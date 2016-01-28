#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    outputOptions=new QStringList();
    outputOptions->push_back("V2");
    outputOptions->push_back("V3");
    outputOptions->push_back("XML");
    ui->comboBox->addItems(*outputOptions);

	caseReader = 0;

    connect(ui->CheckButton,SIGNAL(clicked(bool)),this,SLOT(checkResults()));
    connect(ui->lineEdit,SIGNAL(textEdited(QString)),this,SLOT(lineListner(QString)));
    connect(ui->ChoseFolderButton,SIGNAL(clicked(bool)),this,SLOT(choseFoler()));
    connect(ui->addWatingButton,SIGNAL(clicked(bool)),this,SLOT(addWating()));
    connect(ui->ChoseTestCaseButton,SIGNAL(clicked(bool)),this,SLOT(choseTestCaseFile()));
	connect(ui->selectCasesButton, SIGNAL(clicked(bool)), this, SLOT(selectCases()));
	connect(ui->deleteButton, SIGNAL(clicked(bool)), this, SLOT(deleteWaitingElement()));
	connect(ui->BatchCheckButton, SIGNAL(clicked(bool)), this, SLOT(batchCheck()));

}

MainWindow::~MainWindow()
{
	delete caseReader;
    delete ui;
}

void MainWindow::addWating()
{
    if(ui->addWatingLine->text()!="")
        ui->watingListWidget->addItem(ui->addWatingLine->text());
    this->expectedSections.push_back(ui->addWatingLine->text());
    ui->addWatingLine->clear();
}

void MainWindow::checkResults()
{
    if(this->filesToCheck.size()>0)
    {
        int i=0;
        foreach(QString file,filesToCheck)
        {
            QVariant valuetocell = validateReport(file);
            ui->testCaseTable->setItem(i,1,new QTableWidgetItem(valuetocell.toString()));
            i++;
        }
    }
}

void MainWindow::choseFoler()
{
    if(ui->testCaseTable->size()!=QSize(0,0))
    {
        //clear results;
    }

    QString directory= QFileDialog::getExistingDirectory(0,"Open folder","");

    if( directory.size()>0)
    {
        ui->lineEdit->setText(directory);
    }

    this->filesToCheck=this->getListFilesInDir(directory);
    ui->testCaseTable->setRowCount(filesToCheck.size());
    ui->testCaseTable->setColumnCount(2);
    int i=0;
    foreach(QString file, filesToCheck)
    {
        ui->testCaseTable->setItem(i,0,new QTableWidgetItem(file.remove(0,directory.size()+1)));
        i++;
    }
}

void MainWindow::openTestCases()
{
    this->caseReader=new excelReader(this,&testCaseFile);
	
	connect(this->caseReader, SIGNAL(loadEnd()), this, SLOT(deleteReader()));
	connect(this, SIGNAL(stopLoadFile()), caseReader, SLOT(interruptLoading()));

    caseReader->FeelTableWidget(ui->tableWidget,1);
}

void MainWindow::lineListner(QString lineText)
{
    this->folderPath=lineText;
}

void MainWindow::choseTestCaseFile()
{
    this->testCaseFile= QFileDialog::getOpenFileName(this,"Open file","");
    ui->openTestcaseLineEdit->setText(this->testCaseFile);
    this->openTestCases();
}

bool MainWindow::validateReport(QString filep)
{

    if(expectedSections.size()==0)
    {
        qDebug()<<"need expexted sections";
        return false;
    }

    QRegExp *findExp;

    QFile file(filep);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream stream(&file);

    QString fileText=stream.readAll();
	

		foreach(QString section, expectedSections)
		{
			findExp = new QRegExp('(' + section + ')');
			//int n=findExp->indexIn(fileText);
			int n = fileText.indexOf(section);
			if (n < 0)                                                          //добавить сюда сравнение с таблицой тест кейсов
				return false;

			delete findExp;
			findExp = 0;
		}
	
    return true;

}

QStringList MainWindow:: getListFilesInDir(QString path)
{

    QStringList filelist;
    QDir dir(path);
    bool ok = dir.exists();
    if (ok)
    {
        dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
        dir.setSorting(QDir::Name);
        QFileInfoList list = dir.entryInfoList();

        for (int i = 0; i < list.size(); ++i)
        {
            QFileInfo fileInfo = list.at(i);
            filelist.push_back(path+'/'+fileInfo.fileName());
        }
    }
    return filelist;
}

void MainWindow::deleteReader()
{

    delete caseReader;
    caseReader=0;
}

void MainWindow::selectCases()
{
 QList< QTableWidgetItem *> itemlist= ui->tableWidget->selectedItems();
 QList<QTableWidgetSelectionRange> selectedRanges;
 

 foreach (QTableWidgetItem *var , itemlist)
 {
	 this->expectedSections.push_back(var->text());
	 ui->watingListWidget->addItem(var->text());
 }

 selectedRanges=ui->tableWidget->selectedRanges();
 
 foreach(QTableWidgetSelectionRange range, selectedRanges)
 {
	 int row = range.topRow();
	 int column = range.leftColumn();
	 while (QString::compare(ui->tableWidget->item(row,column)->text(),""))
	 {
		 column++;
		 qDebug() << ui->tableWidget->columnCount();
		 if (column == ui->tableWidget->columnCount())
			 break;
	 }
	 this->expectedResults.push_back(QTableWidgetSelectionRange(range.topRow(), range.leftColumn()+1, range.bottomRow(), column));
 }

 foreach(QTableWidgetSelectionRange range, expectedResults)
 {
	 int row = range.topRow();
	 int column = range.leftColumn();
	 for (size_t y = row; y <= range.bottomRow(); y++)
	 {
		 for (size_t x = column; x < range.rightColumn(); x++)
		 {
			 ui->tableWidget->item(y, x)->setTextColor(Qt::blue);
		 }
	 }
 }

}

void MainWindow::deleteWaitingElement()
{
	QList< QListWidgetItem *> itemlist = ui->watingListWidget->selectedItems();
	expectedSections.removeAt(ui->watingListWidget->currentRow());
	ui->watingListWidget->clear();
		foreach (QString expectedElement , expectedSections)
		{
			ui->watingListWidget->addItem(expectedElement);
		}


}

void MainWindow::batchCheck()
{
	if (this->filesToCheck.size() == 0 || this->expectedResults.size()==0)
		return;
	
		foreach(QTableWidgetSelectionRange range, expectedResults)
		{
			int testCaseNum;
			int section;
			for (size_t x = range.leftColumn(), testCaseNum = 1; x <= range.rightColumn(); x++, testCaseNum++)
			{

				for (size_t y = range.topRow(), section = 0; y <= range.bottomRow(); y++, section++)
				{
					char tcm[6] = "";
					QStringList filesToCheckNow = this->filesToCheck.filter("case_" + QString(itoa(testCaseNum,tcm,10))+"_"+ui->comboBox->currentText(),Qt::CaseInsensitive);
					qDebug() << "i check" << ("case_" + QString(itoa(testCaseNum, tcm, 10)) + ui->comboBox->currentText());
					foreach(QString filep, filesToCheckNow)
					{
						QFile file(filep);

						if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
						{
							qDebug() << "can't open file";
							break;
						}
						QTextStream stream(&file);
						QString fileText = stream.readAll();

						if (fileText.indexOf(ui->tableWidget->item(range.topRow()+section,range.leftColumn()-1) < 0 && ui->tableWidget->item(y, x)->text().toLower() == "true"))
						{
							ui->tableWidget->item(y, x)->setTextColor(Qt::red);
						}
						else
						{
							ui->tableWidget->item(y, x)->setTextColor(Qt::green);
						}
					}
					
				}

			}

		}



	
}

