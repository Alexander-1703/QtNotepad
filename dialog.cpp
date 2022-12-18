#include "dialog.h"
#include "ui_dialog.h"
#include <mainwindow.h>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}
Dialog::Dialog(AbstractNote note, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->note = note;
    ui->plainTextEdit->appendPlainText(note.author);
    ui->plainTextEdit_2->appendPlainText(note.text);
    ui->plainTextEdit_3->appendPlainText(note.tags.join(" "));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_2_clicked()
{
    qDebug() << "start button func";
    this -> dbInteraction = new DatabaseInteraction(database);
    note.author =  ui->plainTextEdit->toPlainText();
    note.text =  ui->plainTextEdit_2->toPlainText();
    note.tags = ui->plainTextEdit_3->toPlainText().split(" ");
    note.changeDate = QDateTime::currentDateTime();
    qDebug() << note.text;
    if(!dbInteraction->update(note, note.id)) {
        qDebug() << "Update not succesful";
    } else {
        qDebug() << "Update succesful";
    }
    this->close();
}

