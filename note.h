#ifndef NOTE_H
#define NOTE_H

#include <QString>
#include <QDateTime>
#include <QSqlQuery>

class Note
{
public:
    QString author;
    QDateTime creationDate;
    QDateTime changeDate;
    QStringList tags;
    QString text;
    int id;

    Note(QString author, QDateTime creationDate, QDateTime changeDate, QStringList tags, QString text);

    bool serialize(QSqlQuery& query);

    bool refresh(QSqlQuery& query, int id);

};

#endif // NOTE_H
