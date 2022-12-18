#ifndef DBCONTROLLER_H
#define DBCONTROLLER_H

#include "abstractNote.h"
#include <QSqlDatabase>

class DbController
{
public:
    QSqlDatabase database;
    virtual bool serialize(AbstractNote& note) = 0;
    virtual bool update(AbstractNote &note, long long id) = 0;
    virtual bool remove(long long id) = 0;
    virtual AbstractNote get(long long id) = 0;
};

#endif // DBCONTROLLER_H
