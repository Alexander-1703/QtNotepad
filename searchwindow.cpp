#include "searchwindow.h"
#include "ui_searchwindow.h"
#include <QMessageBox>
#include <abstractNote.h>
#include <mainwindow.h>
#include <dialog.h>

const int AUTHOR_SEARCH = 0;
const int TAG_SEARCH = 1;
const int CREATE_SEARCH = 2;
const int CHANGE_SEARCH = 3;

SearchWindow::SearchWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchWindow)
{
    ui->setupUi(this);
    QSqlQuery query = QSqlQuery(database);
    query.prepare("SELECT * FROM notes");
    if (!query.exec()) {
       qDebug() << "Failed to connect to database";
    }
    while (query.next()) {
        QString str = query.record().value(4).toString() + "      " +
                + "[Author: " + query.record().value(0).toString() + ",    " +
                + "Tags: " + query.record().value(3).toString() + ",    " +
                + "Creation date: " + query.record().value(1).toString() + ",     " +
                + "Change date: " + query.record().value(2).toString() + ",     " +
                + "ID: " + query.record().value(5).toString() + "]";
        QListWidgetItem* item = new QListWidgetItem(str);
        ui->listWidget->addItem(item);
    }
}

SearchWindow::~SearchWindow()
{
    delete ui;
}

void SearchWindow::on_pushButton_clicked()
{
    ui->listWidget->clear();
    QSqlQuery query = QSqlQuery(database);
    switch(getSearchFilter()) {
        case(AUTHOR_SEARCH):
            query.prepare("SELECT * FROM notes WHERE author=?");
            query.addBindValue(ui->plainTextEdit->toPlainText());
            if (!query.exec()) {
               qDebug() << "Failed to connect to database";
            }
            while (query.next()) {
                QString str = query.record().value(4).toString() + "      " +
                        + "[Author: " + query.record().value(0).toString() + ",    " +
                        + "Tags: " + query.record().value(3).toString() + ",    " +
                        + "Creation date: " + query.record().value(1).toString() + ",     " +
                        + "Change date: " + query.record().value(2).toString() + ",     " +
                        + "ID: " + query.record().value(5).toString() + "]";
                QListWidgetItem* item = new QListWidgetItem(str);
                ui->listWidget->addItem(item);
            }
            break;
        case(TAG_SEARCH):
            query.prepare("SELECT * FROM notes");
            if (!query.exec()) {
               qDebug() << "Failed to connect to database";
            }
            while (query.next()) {
                if (query.record().value(3).toString().split(" ").contains(ui-> plainTextEdit -> toPlainText())
                        && query.record().value(5).toString().length() > 0) {
                    QString str = query.record().value(4).toString() + "      " +
                            + "[Author: " + query.record().value(0).toString() + ",    " +
                            + "Tags: " + query.record().value(3).toString() + ",    " +
                            + "Creation date: " + query.record().value(1).toString() + ",     " +
                            + "Change date: " + query.record().value(2).toString() + ",     " +
                            + "ID: " + query.record().value(5).toString() + "]";
                    QListWidgetItem* item = new QListWidgetItem(str);
                    ui->listWidget->addItem(item);
                }
            }
            break;
        case(CREATE_SEARCH):
            query.prepare("SELECT * FROM notes");
            if (!query.exec()) {
               qDebug() << "Failed to connect to database";
            }
            while (query.next()) {
                auto noteDate =  query.record().value(1).toString().split(" ")[2].toInt();
                auto currentDate = QDateTime::currentDateTime().toString().split(" ")[2].toInt();
                int lessThanDays = ui -> textEdit ->toPlainText().toInt();
                if (lessThanDays <= 0) {
                    QMessageBox::warning(this, "Warning", "Invalid input.");
                    return;
                }
                if ((currentDate - noteDate) <= lessThanDays) {
                    QString str = query.record().value(4).toString() + "      " +
                            + "[Author: " + query.record().value(0).toString() + ",    " +
                            + "Tags: " + query.record().value(3).toString() + ",    " +
                            + "Creation date: " + query.record().value(1).toString() + ",     " +
                            + "Change date: " + query.record().value(2).toString() + ",     " +
                            + "ID: " + query.record().value(5).toString() + "]";
                    QListWidgetItem* item = new QListWidgetItem(str);
                    ui->listWidget->addItem(item);
                }
            }
            break;
        case(CHANGE_SEARCH):
            query.prepare("SELECT * FROM notes");
            if (!query.exec()) {
               qDebug() << "Failed to connect to database";
            }
            while (query.next()) {
                auto noteDate =  query.record().value(1).toString().split(" ")[2].toInt();
                auto currentDate = QDateTime::currentDateTime().toString().split(" ")[2].toInt();
                int lessThanDays = ui -> textEdit ->toPlainText().toInt();
                if (lessThanDays <= 0) {
                    QMessageBox::warning(this, "Warning", "Invalid input");
                    ui->textEdit->clear();
                    return;
                }
                if (noteDate - currentDate <= lessThanDays) {
                    QString str = query.record().value(4).toString() + "      " +
                            + "[Author: " + query.record().value(0).toString() + ",    " +
                            + "Tags: " + query.record().value(3).toString() + ",    " +
                            + "Creation date: " + query.record().value(1).toString() + ",     " +
                            + "Change date: " + query.record().value(2).toString() + ",     " +
                            + "ID: " + query.record().value(5).toString() + "]";
                    QListWidgetItem* item = new QListWidgetItem(str);
                    ui->listWidget->addItem(item);
                }
            }
            break;
    }
    ui->textEdit->clear();
}

int SearchWindow::getSearchFilter() const {
    return searchFilter;
}

void SearchWindow::setSearchFilter(int filter) {
    SearchWindow::searchFilter = filter;
}

void SearchWindow::on_radioButton_toggled(bool checked)
{
    if (checked) {
        setSearchFilter(AUTHOR_SEARCH);
    }
}


void SearchWindow::on_radioButton_2_toggled(bool checked)
{
    if (checked) {
        setSearchFilter(TAG_SEARCH);
    }
}


void SearchWindow::on_radioButton_3_toggled(bool checked)
{
    if (checked) {
        setSearchFilter(CREATE_SEARCH);
    }
}


void SearchWindow::on_radioButton_4_toggled(bool checked)
{
    if (checked) {
        setSearchFilter(CHANGE_SEARCH);
    }
}


void SearchWindow::on_pushButton_2_clicked()
{
    auto elements = ui -> listWidget ->currentItem()->text().split(" ");
    long long selectedNoteId = elements[elements.length()-1].split("]")[0].toLongLong();
    this -> dbInteraction = new DatabaseInteraction(database);
    AbstractNote note = dbInteraction->get(selectedNoteId);
    qDebug() << note.author << " " << note.text;
    qDebug() << "start";
    Dialog* searchWindow = new Dialog(&note);
    searchWindow -> setWindowTitle("Change a note");
    searchWindow -> show();
    qDebug() << "final";
}

