#include "tablepage.h"
#include "ui_tablepage.h"
#include "summarypage.h"
#include "reservationstorage.h"

#include <QHash>
#include <QSet>
#include <QPushButton>
#include <QMessageBox>

static QHash<QString, QSet<QString>> bookedBySlot;

static QPushButton* btnFor(Ui::TablePage* ui, const QString& t)
{
    if (t == "A") return ui->btnA;
    if (t == "B") return ui->btnB;
    if (t == "C") return ui->btnC;
    if (t == "D") return ui->btnD;
    if (t == "E") return ui->btnE;
    if (t == "F") return ui->btnF;
    return nullptr;
}

TablePage::TablePage(QString name, QString date, QString time, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TablePage)
{
    ui->setupUi(this);

    customerName = name;
    selectedDate = date;
    selectedTime = time;

    setWindowTitle("Select Table");

    bookedBySlot = loadReservationsFromCsv();
    refreshTables();
}

TablePage::~TablePage()
{
    delete ui;
}

QString TablePage::bookingKey() const
{
    return selectedDate + "|" + selectedTime;
}

void TablePage::refreshTables()
{
    bookedBySlot = loadReservationsFromCsv();

    const QString key = bookingKey();
    const QSet<QString> bookedTables = bookedBySlot.value(key);
    const QStringList all = {"A", "B", "C", "D", "E", "F"};

    for (const auto& t : all) {
        auto* b = btnFor(ui, t);
        if (!b) continue;

        if (bookedTables.contains(t)) {
            b->setEnabled(false);
            b->setStyleSheet("background-color: #de0a26; color: white; font-weight: bold;");
            b->setText(t + " (Booked)");
        } else {
            b->setEnabled(true);
            b->setStyleSheet("background-color: #2e7d32; color: white; font-weight: bold;");
            b->setText(t);
        }
    }
}

bool TablePage::bookTable(const QString& t)
{
    bookedBySlot = loadReservationsFromCsv();

    const QString key = bookingKey();

    if (bookedBySlot[key].contains(t)) {
        QMessageBox::warning(this, "Booked", "This table is already booked.");
        refreshTables();
        return false;
    }

    return true;
}

void TablePage::on_btnA_clicked()
{
    if (!bookTable("A")) return;
    SummaryPage *summary = new SummaryPage(customerName, selectedDate, selectedTime, "A", this);
    hide();
    summary->show();
}

void TablePage::on_btnB_clicked()
{
    if (!bookTable("B")) return;
    SummaryPage *summary = new SummaryPage(customerName, selectedDate, selectedTime, "B", this);
    hide();
    summary->show();
}

void TablePage::on_btnC_clicked()
{
    if (!bookTable("C")) return;
    SummaryPage *summary = new SummaryPage(customerName, selectedDate, selectedTime, "C", this);
    hide();
    summary->show();
}

void TablePage::on_btnD_clicked()
{
    if (!bookTable("D")) return;
    SummaryPage *summary = new SummaryPage(customerName, selectedDate, selectedTime, "D", this);
    hide();
    summary->show();
}

void TablePage::on_btnE_clicked()
{
    if (!bookTable("E")) return;
    SummaryPage *summary = new SummaryPage(customerName, selectedDate, selectedTime, "E", this);
    hide();
    summary->show();
}

void TablePage::on_btnF_clicked()
{
    if (!bookTable("F")) return;
    SummaryPage *summary = new SummaryPage(customerName, selectedDate, selectedTime, "F", this);
    hide();
    summary->show();
}
