#include "secpage.h"
#include "ui_secpage.h"
#include "tablepage.h"

#include <QMessageBox>

SecPage::SecPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Table_Reservation)
{
    ui->setupUi(this);
    setWindowTitle("Restaurant Reservation System");
}

SecPage::~SecPage()
{
    delete ui;
}

void SecPage::on_pushButton_clicked()
{
    QString name = ui->lineEditName->text().trimmed();
    QString date = ui->dateEdit->date().toString("dd/MM/yyyy");
    QString time = ui->timeEdit->time().toString("HH:mm");

    if (name.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter customer name.");
        return;
    }

    TablePage *table = new TablePage(name, date, time, this);
    hide();
    table->show();
}
