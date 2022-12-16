#ifndef NOTE_H
#define NOTE_H

#include "abstractNote.h"

class Note: public AbstractNote
{
public:
        Note(QString author, QDateTime changeDate, QStringList tags, QString text);
        Note(QString author, QStringList tags, QString text);
        Note();
        ~Note();
private:
        long long id;

        bool serialize(QSqlQuery& query) override;

        bool refresh(QSqlQuery& query, int id) override;
};

#endif // NOTE_H
