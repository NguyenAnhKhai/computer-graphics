#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_BtnDrawSimple_clicked();

    void on_BtnDrawwCircle_clicked();

    void on_btnDrawRect_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
