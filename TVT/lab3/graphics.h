#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>

class graphics : public QWidget
{
    Q_OBJECT
public:
    explicit graphics(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    QPointF dichuyen(QPointF p, double kc, int huong);
    QPointF quay(QPointF p, QPointF c, int delta);
//    QPointF BD;
//    double huong = 0;

    void luoiCau(QPainter &painter);
    void chuNhat(QPainter &painter);
    void chuNhat45Do(QPainter &painter);
    void chuNhat0Do(QPainter &painter);
    void tamGiac(QPainter &painter);

    void polyspirals(QPainter &painter, int incr, int angle);
    void daGiac(QPainter &painter, int n);
    void star(QPainter &painter, int x, int y, int size);
    void _21Star(QPainter &painter);
    void snowFlower(QPainter &painter, int L);
signals:

public slots:

};

#endif // GRAPHICS_H
