#ifndef TABLEPAGE_H
#define TABLEPAGE_H

#include <QDialog>

namespace Ui {
class TablePage;
}

class TablePage : public QDialog
{
    Q_OBJECT

public:
    explicit TablePage(QString name, QString date, QString time, QWidget *parent = nullptr);
    ~TablePage();

private slots:
    void on_btnA_clicked();
    void on_btnB_clicked();
    void on_btnC_clicked();
    void on_btnD_clicked();
    void on_btnE_clicked();
    void on_btnF_clicked();


private:
    Ui::TablePage *ui;

    QString customerName;
    QString selectedDate;
    QString selectedTime;

    bool bookTable(const QString& t);
    void refreshTables();
    QString bookingKey() const;

};

#endif // TABLEPAGE_H
