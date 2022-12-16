#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QWidget>
#include <QDialog>
#include <QDebug>
#include "note.h"

namespace Ui {
class SearchWindow;
}

class SearchWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SearchWindow(QWidget *parent = nullptr);
    int getSearchFilter() const;
    void setSearchFilter(int filter);
    QSqlDatabase database;
    ~SearchWindow();

private slots:
    void on_pushButton_clicked();

    void on_radioButton_toggled(bool checked);

    void on_radioButton_2_toggled(bool checked);

    void on_radioButton_3_toggled(bool checked);

    void on_radioButton_4_toggled(bool checked);

private:
    Ui::SearchWindow *ui;
    int searchFilter;
};

#endif // SEARCHWINDOW_H
