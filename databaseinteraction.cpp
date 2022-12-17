#include "databaseinteraction.h"
#include <QDebug>
#include <QSqlError>

DatabaseInteraction::DatabaseInteraction(QSqlDatabase& database)
{
    this->database = database;
}

bool DatabaseInteraction::serialize(AbstractNote &note)
{
    QSqlQuery query = QSqlQuery(database);
    query.prepare("INSERT INTO notes (author, creationDate, changeDate, tags, text, id) "
                  "VALUES (:author, :creationDate, :changeDate, :tags, :text, :id)");
    query.bindValue(":author", note.author);
    query.bindValue(":creationDate", note.creationDate.toString());
    query.bindValue(":changeDate", note.changeDate.toString());
    query.bindValue(":tags", note.tags.join(" "));
    query.bindValue(":text", note.text);
    query.bindValue(":id", note.id);
    if (query.exec()) {
        qDebug() << "succesful serialization";
        return true;
     }
    qDebug() << "serialization failed";
    return true;
}

bool DatabaseInteraction::update(AbstractNote &note, long long id){
    QSqlQuery query = QSqlQuery(database);
    query.prepare("UPDATE notes SET creationDate=?, text=?, tags=? WHERE id=?");
    query.addBindValue(note.changeDate.toString());
    query.addBindValue(note.text);
    query.addBindValue(note.tags);
    query.addBindValue(id);
    return query.exec();
}

bool DatabaseInteraction::remove(long long id)
{
    QSqlQuery query = QSqlQuery(database);
    query.prepare("DELETE FROM notes WHERE id=?");
    query.addBindValue(id);
    return query.exec();
}
