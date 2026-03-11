#ifndef SUMMARYPAGE_H
#define SUMMARYPAGE_H

#include <QDialog>

namespace Ui {
class SummaryPage;
}

class SummaryPage : public QDialog
{
    Q_OBJECT

public:
    explicit SummaryPage(QString name, QString date, QString time, QString table, QWidget *parent = nullptr);
    ~SummaryPage();

private slots:
    void on_SummaryPage_accepted();

    void on_pushButton_clicked();

private:
    Ui::SummaryPage *ui;

    QString customerName;
    QString selectedDate;
    QString selectedTime;
    QString selectedTable;

    bool alreadySaved;
};

#endif
