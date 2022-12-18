#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "searchwindow.h"

#include <QTime>
#include <QString>
#include <QDateTime>
#include <QChar>
#include <windows.h>
#include <QMap>
#include <QDebug>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setHostName("127.0.0.1");
    database.setDatabaseName("../qtNotepad/sqlite/notepadDB");
    qDebug() << database.databaseName();
    qDebug()<<QDir::currentPath();
    if (database.open()) {
        qDebug () << "database connection succes";
    } else {
        qDebug () << "database connection failed";
        qDebug() << database.lastError().text();
    }
    this -> dbInteraction = new DatabaseInteraction(database);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dbInteraction;
}


void MainWindow::on_actionNew_triggered()
{
    ui ->textEdit -> clear();
    ui ->textEdit_2 -> clear();
    ui ->textEdit_3 -> clear();
}


void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui-> textEdit_2->setText(text);
    file.close();
}

void MainWindow::on_actionExit_triggered()
{
     QApplication::quit();
}


void MainWindow::on_actionUndo_triggered()
{
        ui->textEdit_2->undo();
}


void MainWindow::on_actionRedo_triggered()
{
        ui->textEdit_2->redo();
}

void MainWindow::on_pushButton_clicked()
{
    auto author = ui->textEdit->toPlainText();
    auto tags = ui->textEdit_3->toPlainText().split(" ");
    auto text = ui->textEdit_2->toPlainText();
    if (text.length() == 0) {
        QMessageBox::warning(this, "Warning", "Note text is empty!");
        return;
    }
    AbstractNote* note = new Note((author.length() == 0) ? "student" : author, tags, text);
    if(!dbInteraction->serialize(*note)) {
                qDebug() << "Serialize not succesful";
    }
    delete note;
    ui ->textEdit -> clear();
    ui ->textEdit_2 -> clear();
    ui ->textEdit_3 -> clear();
}


void MainWindow::on_pushButton_2_clicked()
{
    SearchWindow* searchWindow = new SearchWindow();
    searchWindow -> setWindowTitle("Search a note");
    searchWindow -> show();
}

