#include "summarypage.h"
#include "ui_summarypage.h"
#include "reservationstorage.h"

#include <QApplication>
#include <QMessageBox>

SummaryPage::SummaryPage(QString name, QString date, QString time, QString table, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SummaryPage)
    , customerName(name)
    , selectedDate(date)
    , selectedTime(time)
    , selectedTable(table)
    , alreadySaved(false)
{
    ui->setupUi(this);

    setWindowTitle("Reservation Summary");

    ui->labelName->setText("Name : " + name);
    ui->labelDate->setText("Date : " + date);
    ui->labelTime->setText("Time : " + time);
    ui->labelTable->setText("Table : " + table);
}

SummaryPage::~SummaryPage()
{
    delete ui;
}

void SummaryPage::on_SummaryPage_accepted()
{
}

void SummaryPage::on_pushButton_clicked()
{
    if (!alreadySaved) {
        if (isTableBooked(selectedDate, selectedTime, selectedTable)) {
            QMessageBox::warning(this, "Booked", "This table has already been reserved.");
            return;
        }

        bool ok = saveReservationToCsv(customerName, selectedDate, selectedTime, selectedTable);

        if (!ok) {
            QMessageBox::warning(this, "Error", "Failed to save reservation.");
            return;
        }

        alreadySaved = true;
        QMessageBox::information(this, "Success", "Reservation saved successfully.");
    }

    QApplication::quit();
}
