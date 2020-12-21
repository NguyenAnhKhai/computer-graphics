#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BtnDrawSimple_clicked()
{
    ui->GrapicsPresenter->mode = 1; // set mode ve =1
    ui->GrapicsPresenter->repaint(); // ham repaint() se goi den painevent
    ui->GrapicsPresenter->mode = 0; // set mdoe ve ve lai 0
}

void MainWindow::on_BtnDrawwCircle_clicked()
{
    ui->GrapicsPresenter->mode = 1;
    ui->GrapicsPresenter->repaint();
    ui->GrapicsPresenter->mode=0;
}

void MainWindow::on_btnDrawRect_clicked()
{
    ui->GrapicsPresenter->mode=1;
    ui->GrapicsPresenter->repaint();
    ui->GrapicsPresenter->mode=0;
}
