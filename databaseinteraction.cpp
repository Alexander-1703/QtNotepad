#include "databaseinteraction.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>

DatabaseInteraction::DatabaseInteraction(QSqlDatabase& database)
{
    this->database = database;
}

DatabaseInteraction::~DatabaseInteraction()
{
}

bool DatabaseInteraction::serialize(AbstractNote &note)
{
    QSqlQuery query = QSqlQuery(database);
    query.prepare("INSERT INTO notes (author, creationDate, changeDate, tags, text, id) "
                  "VALUES (:author, :creationDate, :changeDate, :tags, :text, :id)");
    query.bindValue(":author", note.author.toLower());
    query.bindValue(":creationDate", note.creationDate.toString().toLower());
    query.bindValue(":changeDate", note.changeDate.toString().toLower());
    query.bindValue(":tags", note.tags.join(" ").toLower());
    query.bindValue(":text", note.text.toLower());
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
    query.prepare("UPDATE notes SET author=?, changeDate=?, text=?, tags=? WHERE id=?");
    query.addBindValue(note.author.toLower());
    query.addBindValue(note.changeDate.toString().toLower());
    query.addBindValue(note.text.toLower());
    query.addBindValue(note.tags.join(" ").toLower());
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

AbstractNote DatabaseInteraction::get(long long id)
{
    QSqlQuery query = QSqlQuery(database);
    query.prepare("SELECT * FROM notes WHERE id=?");
    query.addBindValue(id);
    if (!query.exec()) {
       qDebug() << "Failed to get";
    }

    if (!query.next()) {
        qDebug() << "No such id";
    }
    auto author = query.record().value(0).toString();
    auto creationDate = query.record().value(1).toDateTime();
    auto tags = query.record().value(3).toStringList();
    auto text = query.record().value(4).toString();
    return *new Note(author, creationDate, QDateTime::currentDateTime(), tags, text, id);
}
