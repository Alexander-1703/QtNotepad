#ifndef DATABASEINTERACTION_H
#define DATABASEINTERACTION_H

#include "dbcontroller.h"
#include <note.h>

class DatabaseInteraction : public DbController
{
public:
    QSqlDatabase database;
    bool serialize(AbstractNote& note) override;
    bool update(AbstractNote &note, long long id) override;
    bool remove(long long id) override;
    AbstractNote get(long long id) override;
    DatabaseInteraction(QSqlDatabase& database);
    virtual ~DatabaseInteraction();
};

#endif // DATABASEINTERACTION_H
