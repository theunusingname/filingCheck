#ifndef REPORTVALIDATO_H
#define REPORTVALIDATO_H
#include <QFile>
#include <QTextStream>
#include <qfiledialog.h>
#include <QString>


class ReportValidator
{
private:
    QStringList filesList;
    QStringList watingList;
    int schema;


public:
    enum{V2,V3,XML};
    ReportValidator();
    ReportValidator(int schema, QStringList fileList);
};

#endif // REPORTVALIDATO_H

