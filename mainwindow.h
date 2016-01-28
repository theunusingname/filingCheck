#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <qfiledialog.h>
#include <QString>
#include <QFileSystemModel>
#include "excelreader.h"
#include "reportvalidator.h"
#include <QRegExp>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void checkResults();
    void lineListner(QString lineText);
    void choseFoler();
    void addWating();
    void openTestCases();
    void choseTestCaseFile();
    void deleteReader();
	void selectCases();
	void deleteWaitingElement();
	void batchCheck();


private:
    Ui::MainWindow *ui;
    QStringList *outputOptions;
    QString folderPath;
    QFileSystemModel fm;
    excelReader *caseReader;
    QString testCaseFile;
    QStringList filesToCheck;
    ReportValidator *validator;
    QStringList expectedSections;
	QStringList expectedSectionsForBatch;
	QTableWidgetSelectionRange expectedSectionsRangeToBatch;
	QList<QTableWidgetSelectionRange> expectedResults;
    QStringList getListFilesInDir(QString path);

    bool validateReport(QString filep);
	
	//QVariant getCurrentTableItem(int row, int column);

signals:
    void stopLoadFile();


};


#endif // MAINWINDOW_H
