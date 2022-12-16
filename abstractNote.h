#ifndef ABSTRACTNOTE_H
#define ABSTRACTNOTE_H

#include <QString>
#include <QDateTime>
#include <QSqlQuery>

class AbstractNote
{

protected:
    QString author;
    QDateTime creationDate;
    QDateTime changeDate;
    QStringList tags;
    QString text;

    virtual bool serialize(QSqlQuery& query) = 0;

    virtual bool refresh(QSqlQuery& query, int id) = 0;

};

#endif // ABSTRACTNOTE_H
