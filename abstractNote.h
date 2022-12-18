#ifndef ABSTRACTNOTE_H
#define ABSTRACTNOTE_H

#include <QString>
#include <QDateTime>
#include <QSqlQuery>

class AbstractNote
{
public:
    QString author;
    QDateTime creationDate;
    QDateTime changeDate;
    QStringList tags;
    QString text;
    long long id;
};

#endif // ABSTRACTNOTE_H
