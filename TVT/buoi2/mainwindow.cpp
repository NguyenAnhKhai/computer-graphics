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

void MainWindow::on_pushButton_clicked()
{
    ui->graphicsPresenter->mode = 1;
    ui->graphicsPresenter->repaint();
    ui->graphicsPresenter->mode = 0;
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->graphicsPresenter->mode = 3;
    ui->graphicsPresenter->repaint();
    ui->graphicsPresenter->mode = 0;
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->graphicsPresenter->mode = 2;
    ui->graphicsPresenter->repaint();
    ui->graphicsPresenter->mode = 0;
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->graphicsPresenter->mode = 4;
    ui->graphicsPresenter->repaint();
    ui->graphicsPresenter->mode = 0;
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->graphicsPresenter->mode = 5;
    ui->graphicsPresenter->repaint();
    ui->graphicsPresenter->mode = 0;
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->graphicsPresenter->mode = 6;
    ui->graphicsPresenter->repaint();
    ui->graphicsPresenter->mode = 0;
}
