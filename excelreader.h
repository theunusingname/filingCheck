#ifndef EXCELREADER_H
#define EXCELREADER_H

#include <QObject>
#include <QAxObject>
#include <QtGui>
#include <QTableWidget>
#include <iostream>
#include <QDebug>
#include <vector>
#include "progressWidget.h"

class excelReader: public QObject
{
    Q_OBJECT
public:
    excelReader(QObject *parent=0,QString *path=0);
    ~excelReader();
    void FeelTableWidget(QTableWidget *table, int sheetn);
    void FeelTable(QTableModel *table, int sheetn);
    void FeelModel(QStandardItemModel *model, int sheetn);


private:
    QObject *parent;
    QAxObject* excel;
    QAxObject* workbooks;
    QAxObject* workbook;
    QAxObject* sheets;
    QAxObject* sheet;
    QString filePath;
    bool interruptLoad;
    int sheetsNumb;
    //QTableWidgetItem *itemsArr[][];


    void PopulateTableItemArr(int sheet);
    QSize GetTableSize(int sheetn);

public slots:
    void interruptLoading(){interruptLoad=true;}

signals:
    void loadEnd();
};

#endif // EXCELREADER_H
