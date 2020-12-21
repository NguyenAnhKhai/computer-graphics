#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>


class graphics : public QWidget
{
    Q_OBJECT
public:
    explicit graphics(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    int mode = 0;
    int h = height();
    int w = width();
    int random(int n);


    QPointF tinhtien(QPoint p, int tx, int ty);
    QPoint quay(QPoint p, QPoint c, int delta);
    QPoint doixungx(QPoint p);
    QPoint doixungy(QPoint p);
    QPoint tile(QPoint P, QPoint c, int sx, int sy);
    QPoint giaoDiem(QPoint A, QPoint B, QPoint C, QPoint D);
    QPointF giaoDiemF(QPointF A, QPointF C, QPointF B, QPointF D);

    void ngansao(QPainter& painter);
    void ngugiac(QPainter& painter);
    void bonghoa(QPainter& painter);
    void thaicuc(QPainter& painter);
    void thaicuc_mau(QPainter& painter);
    void quocky(QPainter& painter);
    void ngoilang(QPainter& painter);
    void gingerbreadMan(QPainter& painter);
    void sierpinski(QPainter& painter);
    void drawHouse(QPainter& painter, QPoint f, int height, int width);
    void test(QPainter& painter);
    void rosette(QPainter& painter, int n);
signals:
    
public slots:
    
};

#endif // GRAPHICS_H
