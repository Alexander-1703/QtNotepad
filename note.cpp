#include "note.h"

Note:: Note(QString author, QDateTime creationDate, QDateTime changeDate, QStringList tags, QString text)
{
    this -> author = author;
    this->creationDate = creationDate;
    this -> changeDate = changeDate;
    this -> tags = tags;
    this -> text = text;
    this -> id = creationDate.toMSecsSinceEpoch();
}
