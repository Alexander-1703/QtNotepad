#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "searchwindow.h"

#include <QTime>
#include <QString>
#include <QDateTime>
#include <QChar>
#include <windows.h>
#include <stdio.h>
#include "searchwindow.h"
#include <QMap>
#include <dialog.h>
#include <stdlib.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
//    ui->setupUi(this);
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setHostName("127.0.0.1");
    database.setDatabaseName("notepadDB");
    database.setUserName("student");
    database.setPassword("student");
    if (database.open()) {
        qDebug () << "db connection succes";
    } else {
        qDebug () << "db connection failed";
    }
    this -> dbInteraction = new DatabaseInteraction(database);
}

MainWindow::~MainWindow()
{
    delete ui;
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

}


void MainWindow::on_pushButton_2_clicked()
{
    SearchWindow* searchWindow = new SearchWindow();
    searchWindow -> setWindowTitle("Search a note");
    searchWindow -> show();
}

