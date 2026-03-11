#include "adminpage.h"
#include "ui_adminpage.h"

#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QStringList>
#include <QTableWidgetItem>
#include <QMessageBox>

adminpage::adminpage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adminpage)
{
    ui->setupUi(this);
    setWindowTitle("Admin - Reservation Records");
    loadReservations();
}

adminpage::~adminpage()
{
    delete ui;
}

void adminpage::loadReservations()
{
    QString filePath = QDir::currentPath() + "/reservations.csv";
    QFile file(filePath);

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels({"Name", "Date", "Time", "Table"});

    if (!file.exists()) {
        return;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in(&file);
    bool firstLine = true;
    int row = 0;

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();

        if (line.isEmpty()) continue;

        if (firstLine) {
            firstLine = false;
            continue;
        }

        QStringList parts = line.split(",");
        if (parts.size() < 4) continue;

        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(parts[0].trimmed()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(parts[1].trimmed()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(parts[2].trimmed()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(parts[3].trimmed()));
        row++;
    }

    file.close();
}

void adminpage::on_btnRefresh_clicked()
{
    loadReservations();
}

void adminpage::on_btnClearAll_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,
                                  "Confirm Clear",
                                  "Do you want to delete all reservation records?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::No) {
        return;
    }

    QString filePath = QDir::currentPath() + "/reservations.csv";
    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Unable to clear reservation records.");
        return;
    }

    QTextStream out(&file);
    out << "Name,Date,Time,Table\n";
    file.close();

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels({"Name", "Date", "Time", "Table"});

    QMessageBox::information(this, "Success", "All reservation records have been cleared.");
}
