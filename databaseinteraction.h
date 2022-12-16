#ifndef DATABASEINTERACTION_H
#define DATABASEINTERACTION_H

#include <note.h>

class DatabaseInteraction
{
public:
    QSqlDatabase database;
    bool serialize(AbstractNote& note);
    bool update(AbstractNote &note, long long id);
    bool remove(long long id);
    DatabaseInteraction(QSqlDatabase& database);
};

#endif // DATABASEINTERACTION_H
