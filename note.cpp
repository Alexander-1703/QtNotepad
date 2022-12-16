#include "note.h"

Note::Note()
{
    this -> author = " ";
    this->creationDate = QDateTime::currentDateTime();
    this -> changeDate = this->creationDate;
    this -> tags = QStringList();
    this -> text = "";
    this -> id = creationDate.toMSecsSinceEpoch();
}

Note::Note(QString author, QStringList tags, QString text)
{
    this -> author = author;
    this->creationDate = QDateTime::currentDateTime();
    this -> changeDate = this -> creationDate;
    this -> tags = tags;
    this -> text = text;
    this -> id = creationDate.toMSecsSinceEpoch();
}

Note::Note(QString author, QDateTime changeDate, QStringList tags, QString text)
{
    this -> author = author;
    this->creationDate = QDateTime::currentDateTime();
    this -> changeDate = changeDate;
    this -> tags = tags;
    this -> text = text;
    this -> id = creationDate.toMSecsSinceEpoch();
}

bool Note::serialize(QSqlQuery& query) {
    query.prepare("INSERT INTO notes (author, creationDate, changeDate, tags, text, id) "
                  "VALUES (:author, :creationDate, :changeDate, :tags, :text, :id)");
    query.bindValue(":author", this -> id);
    query.bindValue(":creationDate", this -> creationDate);
    query.bindValue(":changeDate", this -> changeDate);
    query.bindValue(":tags", this -> tags);
    query.bindValue(":text", this -> text);
    query.bindValue(":id", this -> id);
    return query.exec();
}

bool Note::refresh(QSqlQuery& query, int id){
    query.executedQuery();
    id = 0;
    return id;
}
