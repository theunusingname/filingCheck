#include "excelreader.h"


excelReader::excelReader(QObject *parent, QString *path): QObject(parent)

{
    interruptLoad=false;
    this->parent=parent;
    this->filePath=*path;
    excel = new QAxObject("Excel.Application", 0);
    workbooks = excel->querySubObject("Workbooks");
    workbook = workbooks->querySubObject("Open(const QString&)", filePath);
    sheets = workbook->querySubObject("Worksheets");

    sheetsNumb=sheets->property("Count").toInt();
    qDebug()<<"sheets:"<<sheetsNumb;


}

void excelReader::FeelTableWidget(QTableWidget *table, int sheetn)
{

    QSize size=GetTableSize(sheetn);
    qDebug()<<"size"<<size.width()<<" x "<<size.height();

    table->setRowCount(size.height());
    table->setColumnCount(size.width());

	progressWidget progress(size.height());
	connect(&progress, SIGNAL(interrupt()), this, SLOT(interruptLoading()));
	progress.setBaseSize(QSize(100, 200));
	progress.show();

    for ( int row = 0; row < size.height(); row++ ){
        for ( int column = 0; column < size.width(); column++ ){
            QAxObject* cell = sheet->querySubObject("Cells(int,int)",row  + 1,column  + 1);
            QVariant value = cell->property("Value");
            QTableWidgetItem* item = new QTableWidgetItem(value.toString());
            table->setItem(row, column, item);
            qApp->processEvents();
            if(interruptLoad)
                break;
        } 
        if(interruptLoad)
            break;
		progress.progressNow(row);
    }
    interruptLoad=false;
    emit loadEnd();
}

//void excelReader::FeelModel(QStandardItemModel *model, int sheetn)
//{
//    QSize size=GetTableSize(sheetn);

//    model= new QStandardItemModel(size.height(),size.width());
//    for ( int row = 0; row < /*countRows*/70; row++ ){
//        for ( int column = 0; column < /*countCols*/70; column++ ){
//            QAxObject* cell = sheet->querySubObject("Cells(int,int)",row  + 1,column  + 1);
//            QVariant value = cell->property("Value");
//           // QTableWidgetItem* item = new QTableWidgetItem(value.toString());
//            model->set
//          //  table->setItem(row, column, item);
//        }
//    }
//}

QSize excelReader::GetTableSize( int sheetn)
{
    QSize result;
    sheet = sheets->querySubObject("Item(int)", sheetn);
    QAxObject* usedRange = sheet->querySubObject("UsedRange");
    QAxObject* rows = usedRange->querySubObject("Rows");
    int countRows = rows->property("Count").toInt();

    QAxObject* columns = usedRange->querySubObject("Columns");
    int countCols = columns->property("Count").toInt();

    result.setHeight(countRows);
    result.setWidth(countCols);

    return result;
}

excelReader::~excelReader()
{
    workbook->dynamicCall("Close()");
    excel->dynamicCall("Quit()");
	delete sheet;
	delete sheets;
	delete workbook;
	delete workbooks;
	delete excel;
  // workbooks->clear();
    //
   // 
  
}
