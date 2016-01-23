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

enum{V2,V3,XML};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void checkResults();
    void lineListner(QString lineText);
    void choseFoler();
    void addWating();
    void openTestCases();
    void choseTestCaseFile();
    void deleteReader();


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

    QStringList getListFilesInDir(QString path);
    bool validateReport(QString filep);

signals:
    void stopLoadFile();


};

#endif // MAINWINDOW_H
