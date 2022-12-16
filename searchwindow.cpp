#include "searchwindow.h"
#include "ui_searchwindow.h"

const int AUTHOR_SEARCH = 0;
const int TAG_SEARCH = 1;
const int CREATE_SEARCH = 2;
const int CHANGE_SEARCH = 3;

SearchWindow::SearchWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchWindow)
{
    ui->setupUi(this);
}

SearchWindow::~SearchWindow()
{
    delete ui;
}

void SearchWindow::on_pushButton_clicked()
{
//    Dialog* dialog = new Dialog();
//    dialog -> setWindowTitle("Note");
//    dialog -> show();
    ui->plainTextEdit->clear();
    QSqlQuery query = QSqlQuery(database);

    switch(getSearchFilter()) {
        case(AUTHOR_SEARCH):
            query.prepare("SELECT * FROM notes WHERE author=?");
            query.addBindValue(ui->plainTextEdit->toPlainText());
            if (!query.exec()) {
               qDebug() << "Failed to connect to database";
            }
            while (query.next()) {
                QString str = query.record().value(0).toString() + " " +
                        query.record().value(3).toString() + " " +
                        query.record().value(4).toString()+ "\n";
                ui->plainTextEdit->appendPlainText(str);
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
                    QString str = query.record().value(0).toString() + " " +
                            query.record().value(3).toString() + " " +
                            query.record().value(4).toString()+ "\n";
                    ui->plainTextEdit->appendPlainText(str);
                }
            }
            break;
        case(CREATE_SEARCH):
            query.prepare("SELECT * FROM notes");
            if (!query.exec()) {
               qDebug() << "Failed to connect to database";
            }
            while (query.next()) {
                QDateTime dateTimeCreation = query.record().value(1).toDateTime();
                if (dateTimeCreation.daysTo(QDateTime::currentDateTime()) < 3) {
                    QString str = query.record().value(0).toString() + " " +
                            query.record().value(3).toString() + " " +
                            query.record().value(4).toString()+ "\n";
                    ui->plainTextEdit->appendPlainText(str);
                }
            }
            break;
        case(CHANGE_SEARCH):
            query.prepare("SELECT * FROM notes");
            if (!query.exec()) {
               qDebug() << "Failed to connect to database";
            }
            while (query.next()) {
                QDateTime dateTimeChange = query.record().value(2).toDateTime();
                if (dateTimeChange.daysTo(QDateTime::currentDateTime()) < 3) {
                    QString str = query.record().value(0).toString() + " " +
                            query.record().value(3).toString() + " " +
                            query.record().value(4).toString()+ "\n";
                    ui->plainTextEdit->appendPlainText(str);
                }
            }
            break;
    }
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

