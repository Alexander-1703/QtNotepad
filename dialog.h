#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <abstractNote.h>
#include <databaseinteraction.h>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    Dialog(AbstractNote *note);
    ~Dialog();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
    DatabaseInteraction* dbInteraction;
    QSqlDatabase database;
    AbstractNote* note;
};

#endif // DIALOG_H
