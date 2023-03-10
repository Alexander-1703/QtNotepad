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

Note::Note(QString author,QDateTime creationDate, QDateTime changeDate, QStringList tags, QString text, long long id)
{
    this -> author = author;
    this->creationDate = creationDate;
    this -> changeDate = changeDate;
    this -> tags = tags;
    this -> text = text;
    this -> id = id;
}
