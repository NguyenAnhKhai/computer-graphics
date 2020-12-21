#include "graphics.h"
#include <QPainter>
#include <math.h>

graphics::graphics(QWidget *parent) :
    QWidget(parent)
{
}

void graphics::paintEvent(QPaintEvent *) {
    QPainter painter(this);
//    luoiCau(painter);
//    tamGiac(painter);
//    polyspirals(painter, 4, 89);
//    daGiac(painter, 12);
    _21Star(painter);
//    star(painter, 200, 200, 200);
//    snowFlower(painter, 200);
}

QPointF graphics::dichuyen(QPointF p, double kc, int huong) {
    QPointF pnew;
    pnew.setX(p.x() + kc*cos(M_PI*huong/180));
    pnew.setY(p.y() + kc*sin(M_PI*huong/180));
    return pnew;
}

QPointF graphics::quay(QPointF p, QPointF c, int delta) {
    QPointF pnew;
    double goc = delta * 3.14 / 180;
    pnew.setX(c.x() + (p.x() - c.x()) * cos(goc) - (p.y() - c.y()) * sin(goc));
    pnew.setY(c.y() + (p.x() - c.x()) * sin(goc) + (p.y() - c.y()) * cos(goc));
    return pnew;
}


void graphics::snowFlower(QPainter &painter, int L) {
    QPointF start (width()/2 - 200, height()/2);
    int huong = 0;
    QPointF p;

    p = dichuyen(start, L*4/10, 0);
    painter.drawLine(start, p);
    start = p;

    p = dichuyen(start, L*3/10, -60);
    painter.drawLine(start, p);
    start = p;

    p = dichuyen(start, L/40, 0);
    painter.drawLine(start, p);
    start = p;

    p = dichuyen(start, L*3/10, 120);
    painter.drawLine(start, p);
    start = p;

    p = dichuyen(start, L*0.2, 0);
    painter.drawLine(start, p);
    start = p;

    p = dichuyen(start, L*0.2, -60);
    painter.drawLine(start, p);
    start = p;

    p = dichuyen(start, L/40, 0);
    painter.drawLine(start, p);
    start = p;

    p = dichuyen(start, L*0.2, 120);
    painter.drawLine(start, p);
    start = p;

    p = dichuyen(start, L*0.2, 0);
    painter.drawLine(start, p);
    start = p;

    p = dichuyen(start, L/40, 45);
    painter.drawLine(start, p);
    start = p;
    // done one side

    p = dichuyen(start, L/40, 90+45);
    painter.drawLine(start, p);
    start = p;

    p = dichuyen(start, L*0.2, 0 + 180);
    painter.drawLine(start, p);
    start = p;

    p = dichuyen(start, L*0.2, 120 - 60);
    painter.drawLine(start, p);
    start = p;

    p = dichuyen(start, L/40, 0 + 180);
    painter.drawLine(start, p);
    start = p;
}

void graphics::_21Star(QPainter &painter) {
    QPointF center(width()/2 - 100, height()/2 - 100);
    star(painter, center.x(), center.y(), 100 + 100);
    painter.drawPoint(center);

    QPointF secondLayer(center.x(), center.y() - 130);
    int angle = 36;
    for(int i = 0; i < 10; i++) {
        star(painter, secondLayer.x(), secondLayer.y() + 100, 10);
        secondLayer = quay(secondLayer, center, angle);
    }

    QPointF thirdLayer(center.x(), center.y() - 200);
    for (int i = 0; i < 10; i++) {
        star(painter, thirdLayer.x(), thirdLayer.y() + 100, 20);
        thirdLayer = quay(thirdLayer, center, angle);
    }
}

void graphics::star(QPainter &painter, int x, int y, int size) {
    QPointF p(x, y-100);
    QPointF bd;
    int huong = 72, angle = 144;
    for (int i = 0; i < 5; i++) {
        bd = p;
        p = dichuyen(p, size, huong);
        painter.drawLine(bd, p);
        huong += angle;
    }
}

void graphics::daGiac(QPainter &painter, int n) {
    QPointF p(width()/2 - 100, height()/2 - 100);
    QPointF bd;
    int huong = 0;
    int angle = 360 / n;
    int dist = 100;
    for (int i = 0; i < n; i++) {
        bd = p;
        p = dichuyen(p, dist, huong);
        huong += angle;
        painter.drawLine(bd, p);
    }
}

void graphics::polyspirals(QPainter &painter, int incr, int angle) {
    QPointF p(width()/2, height()/2);
    QPointF bd;
    double dist = 10;
    int huong = 0;
    for (int i = 0; i < 100; i++) {
        bd = p;
        p = dichuyen(p, dist, huong);
        painter.drawLine(bd, p);
        huong += angle;
        dist += incr;
    }
}



void graphics::luoiCau(QPainter &painter) {
    QPointF P(100, 300);
    int huong = 0;
    double kc = 50;
    QPointF Q = dichuyen(P, 3*kc, huong);
    painter.drawLine(P, Q);

    P = Q;
    huong += -90;
    Q = dichuyen(P, kc, huong);
    painter.drawLine(P, Q);

    P = Q;
    huong += -90;
    Q = dichuyen(P, kc, huong);
    painter.drawLine(P, Q);
}

void graphics::chuNhat(QPainter &painter) {
    painter.setPen(Qt::red);
    QPointF P(100, 400);
    int huong = 0;
    double kc = 50;
    QPointF BD;
    for (int i = 0; i < 4; i++) {
        BD = P;
        P = dichuyen(P, 3*kc, huong);
        painter.drawLine(BD, P);
        huong += -90;


        BD = P;
        P = dichuyen(P, kc, huong);
        painter.drawLine(BD, P);
        huong += -90;

        BD = P;
        P = dichuyen(P, kc, huong);
        painter.drawLine(BD, P);
        huong += -90;
    }
}

void graphics::chuNhat45Do(QPainter &painter) {
    QPointF P(500, 400);
    int huong = 45;
    double kc = 50;
    QPointF BD;
    for (int i = 0; i < 4; i++) {
        BD = P;
        P = dichuyen(P, 3*kc, huong);
        painter.drawLine(BD, P);
        huong += -90;


        BD = P;
        P = dichuyen(P, kc, huong);
        painter.drawLine(BD, P);
        huong += -90;

        BD = P;
        P = dichuyen(P, kc, huong);
        painter.drawLine(BD, P);
        huong += -90;
    }
}

void graphics::chuNhat0Do(QPainter &painter) {
    QPointF p(300, 300);
    int huong = 0;
    double kc = 0;
    QPointF bd;

    for (int i = 1; i < 5; i++) {
        huong = 0;
        kc += 50;
        bd = p;
        p = dichuyen(p, kc, huong);
        painter.drawLine(bd, p);

        bd = p;
        huong += -90;
        p = dichuyen(p, kc, huong);
        painter.drawLine(bd, p);

        bd = p;
        huong += -90;
        p = dichuyen(p, kc, huong);
        painter.drawLine(bd, p);

        bd = p;
        huong += -90;
        p = dichuyen(p, kc, huong);
        painter.drawLine(bd, p);
    }
}

void graphics::tamGiac(QPainter &painter) {
    QPointF p(700, 300);
    int huong = 0;
    double kc = 100;
    QPointF bd;
    for (int i = 0; i < 4; i++) {
        bd = p;
        p = dichuyen(p, 2*kc, huong);
        painter.drawLine(bd, p);
        huong += -120;
    }

    bd = p;
    p = dichuyen(p, kc, huong);
    painter.drawLine(bd, p);
    huong += -120;

    for (int i = 0; i < 4; i++) {
        bd = p;
        p = dichuyen(p, kc, huong);
        painter.drawLine(bd, p);
        huong += 120;
    }
}



//painter.setRenderHint(QPainter::Antialiasing);
//painter.drawLine(0,0,200,0);
//QPointF a (100, 100), b, c, d, e, f;
//    b.setX(dichuyen(a, 100, 0).x());
//    b.setY(dichuyen(a, 100, 0).y());
//    painter.setPen(Qt::blue);
//    painter.drawLine(a.x(), a.y(), b.x(), b.y());

//    c.setX(dichuyen(a, 100, 45).x());
//    c.setY(dichuyen(a, 100, 45).y());
//    painter.setPen(Qt::red);
//    painter.drawLine(a.x(), a.y(), c.x(), c.y());

//    d.setX(dichuyen(a, 100, 90).x());
//    d.setY(dichuyen(a, 100, 90).y());
//    painter.setPen(Qt::yellow);
//    painter.drawLine(a.x(), a.y(), d.x(), d.y());

//    e.setX(dichuyen(a, 100, -45).x());
//    e.setY(dichuyen(a, 100, -45).y());
//    painter.setPen(Qt::cyan);
//    painter.drawLine(a.x(), a.y(), e.x(), e.y());

//    f.setX(dichuyen(a, 100, -90).x());
//    f.setY(dichuyen(a, 100, -90).y());
//    painter.setPen(Qt::green);
//    painter.drawLine(a.x(), a.y(), f.x(), f.y());

//    painter.setPen(QPen(Qt::blue, 5, Qt::SolidLine));
//    QPointF P(100, 200);
//    QPointF Q = dichuyen(P, 100, 0);
//    painter.drawPoint(P);
//    painter.drawPoint(Q);

