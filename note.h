#ifndef NOTE_H
#define NOTE_H

#include "abstractNote.h"

class Note: public AbstractNote
{
public:
        Note(QString author, QDateTime creationDate, QDateTime changeDate, QStringList tags, QString text, long long id);
        Note(QString author, QDateTime changeDate, QStringList tags, QString text);
        Note(QString author, QStringList tags, QString text);
        Note();
        ~Note();
};

#endif // NOTE_H
