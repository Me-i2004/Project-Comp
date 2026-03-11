#ifndef SECPAGE_H
#define SECPAGE_H

#include <QDialog>
#include <QDate>
#include <QTime>

namespace Ui {
class Table_Reservation;
}

class SecPage : public QDialog
{
    Q_OBJECT;

public:
    explicit SecPage(QWidget *parent = nullptr);
    ~SecPage();

private slots:

    void on_pushButton_clicked();

private:
    Ui::Table_Reservation *ui;

    QString customerName;
    QString selectedDate;
    QString selectedTime;
};

#endif // SECPAGE_H
