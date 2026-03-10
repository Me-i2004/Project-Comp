#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "secpage.h"
#include "adminpage.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_btnAdmin_clicked();

private:
    Ui::MainWindow *ui;
    SecPage *secPage;
    adminpage *adminDialog;
};
#endif // MAINWINDOW_H
