#include "reportvalidator.h"

ReportValidator::ReportValidator()
{

}


ReportValidator::ReportValidator(int schema, QStringList fileList)
{
    this->schema=schema;
    this->filesList=fileList;
}

