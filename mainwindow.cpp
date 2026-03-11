#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Restaurant Reservation System");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    hide();
    secPage = new SecPage(this);
    secPage->show();

}


void MainWindow::on_btnAdmin_clicked()
{
    adminDialog = new adminpage(this);
    adminDialog->show();
}

