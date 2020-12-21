#include "graphics.h"
#include <QPainter>
#include <math.h>
#include <QString>


graphics::graphics(QWidget *parent) :
    QWidget(parent)
{
    position = 0;
    timerId = startTimer(50);
    angle = 30;
}

void graphics::timerEvent(QTimerEvent *) {
    position += 1;
    angle += 1;
    repaint();
}

void graphics::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
//    animationCircle(painter);
//    drawStar(painter, QPointF(100, 100), 50);
    solarSystem(painter);
//    thousandStars(painter);
}

QPointF graphics::quay(QPointF p, QPointF c, int delta) {
    QPointF pnew;
    double goc = delta * 3.14/180;
    pnew.setX(c.x() + (p.x() - c.x())*cos(goc) - (p.y() - c.y())*sin(goc));
    pnew.setY(c.y() + (p.x() - c.x())*sin(goc) + (p.y() - c.y())*cos(goc));
    return pnew;
}

void graphics::animationCircle(QPainter &painter) {
    int r = 10;
    int h = height() / 2;
    int w = width() / 2;
    QPointF pcenter, pstart, pnew;
    pcenter.setX(w);
    pcenter.setY(h);
    pstart.setX(pcenter.x());
    pstart.setY(pcenter.y() - 100);

    pnew = quay(pstart, pcenter, angle);
    painter.setPen(Qt::blue);
    painter.drawEllipse(pcenter, r, r);
//    painter.drawLine(pcenter, pnew);
    painter.drawEllipse(pnew, 2*r, 2*r);

    drawStar(painter, pcenter, r);
    drawStar(painter, pnew, 2*r);
}


void graphics::drawStar(QPainter &painter, QPointF pcenter, int r) {
    QPointF p(pcenter.x(), pcenter.y() - r);
    QPolygonF polygon;
    int goc = 72;
    polygon << QPointF(p.x(), p.y());
    for (int i = 0; i < 5; i++) {
        p = quay(p, pcenter, goc);
        polygon << QPointF(p.x(), p.y());
    }

   painter.drawLine(polygon.value(0), polygon.value(2));
   painter.drawLine(polygon.value(0), polygon.value(3));
   painter.drawLine(polygon.value(1), polygon.value(3));
   painter.drawLine(polygon.value(1), polygon.value(4));
   painter.drawLine(polygon.value(2), polygon.value(4));
}

void graphics::solarSystem(QPainter &painter) {
    int r = 10;
    int h = height() / 2;
    int w = width() / 2;
    QPointF pcenter, pstart, earth, moon;
    QString moonFilename = "C:/Users/jeanLannes/workstation/computer_graphic/lab4/moon.png";
    QString earthFilename = "C:/Users/jeanLannes/workstation/computer_graphic/lab4/earth.png";
    QString sunFilename = "C:/Users/jeanLannes/workstation/computer_graphic/lab4/sun.png";

    pcenter.setX(w);
    pcenter.setY(h);
    pstart.setX(pcenter.x());
    pstart.setY(pcenter.y() - 200);

    earth = quay(pstart, pcenter, angle);
    moon = quay(QPointF(earth.x(),  earth.y()-70),  earth, angle*5);

//    painter.drawEllipse(pcenter, r, r);
    painter.drawPixmap(pcenter.x(), pcenter.y(), r*8, r*8, QPixmap(sunFilename));

//    painter.drawEllipse(earth, 2*r, 2*r);
    painter.drawPixmap(earth.x(), earth.y(), r*5, r*5, QPixmap(earthFilename));

//    painter.drawEllipse(moon, r, r);
    painter.drawPixmap(moon.x(), moon.y(), r*3, r*3, QPixmap(moonFilename));
}

int graphics::random(int n) {
    return rand() % n;
}

void graphics::thousandStars(QPainter &painter) {
    for (int i = 1; i <= 1000; i++) {
        painter.setPen(Qt::NoPen);
        painter.setBrush(QColor(random(255), random(255), random(255)));
        painter.drawEllipse(random(1000), random(1000), 3, 3);
    }
}
