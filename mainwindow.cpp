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


    connect(ui->CheckButton,SIGNAL(clicked(bool)),this,SLOT(checkResults()));
    connect(ui->lineEdit,SIGNAL(textEdited(QString)),this,SLOT(lineListner(QString)));
    connect(ui->ChoseFolderButton,SIGNAL(clicked(bool)),this,SLOT(choseFoler()));
    connect(ui->addWatingButton,SIGNAL(clicked(bool)),this,SLOT(addWating()));
    connect(ui->ChoseTestCaseButton,SIGNAL(clicked(bool)),this,SLOT(choseTestCaseFile()));
    connect(this->caseReader,SIGNAL(loadEnd()),this,SLOT(deleteReader()));
    connect(this,SIGNAL(stopLoadFile()),caseReader,SLOT(interruptLoading()));

}

MainWindow::~MainWindow()
{
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
        findExp=new QRegExp('('+section+')');
        //int n=findExp->indexIn(fileText);
        int n=fileText.indexOf( "<find:fIndicators>");
        if(n<0)                                                          //добавить сюда сравнение с таблицой тест кейсов
            return false;

        delete findExp;
        findExp=0;
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
