#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QDialog>

namespace Ui {
class adminpage;
}

class adminpage : public QDialog
{
    Q_OBJECT

public:
    explicit adminpage(QWidget *parent = nullptr);
    ~adminpage();

private slots:
    void on_btnRefresh_clicked();

    void on_btnClearAll_clicked();

private:
    Ui::adminpage *ui;
    void loadReservations();
};

#endif // ADMINPAGE_H
