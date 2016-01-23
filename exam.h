#ifndef EXAM_H
#define EXAM_H

#include <QObject>

class exam : public QObject
{
    Q_OBJECT
public:
    explicit exam(QObject *parent = 0);

signals:

public slots:
};

#endif // EXAM_H
