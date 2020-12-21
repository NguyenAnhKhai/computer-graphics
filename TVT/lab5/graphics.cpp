#include "graphics.h"
#include <QPainter>
#include <QRect>
#include <math.h>

graphics::graphics(QWidget *parent) :
    QWidget(parent)
{
    position = 0;
    hinh = 0;
    timerid = startTimer(10);
}

void graphics::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setPen(QPen(Qt::red, 5, Qt::SolidLine));
//    drawMegaman(painter);
    drawWatch(painter);
//    drawNightSky(painter);
}

void graphics::timerEvent(QTimerEvent *) {
    position += 1;
    hinh += 1;
    if (hinh == 10) hinh = 0;
    repaint();
}

void graphics::drawMegaman(QPainter &painter) {
    QPixmap spritesheet("D://Megaman.png");
    double hHinh = spritesheet.height();
    double wHinh = spritesheet.width() / 10;
    int r = 5; // toc do khung hinh

    QRect displayWindow(wHinh * hinh, 0, wHinh, hHinh);

    QRect pos(position * r, height() / 2, wHinh, hHinh);

    painter.drawPixmap(pos, spritesheet, displayWindow);
}

QPointF graphics::quay(QPointF p, QPointF c, int delta) {
    QPointF pnew;
    double goc = delta * 3.14/180;
    pnew.setX(c.x() + (p.x() - c.x())*cos(goc) - (p.y() - c.y())*sin(goc));
    pnew.setY(c.y() + (p.x() - c.x())*sin(goc) + (p.y() - c.y())*cos(goc));
    return pnew;
}

void graphics::drawWatch(QPainter &painter){
    painter.setPen(Qt::black);
    QFont font("Georgia", 20);

    QPointF centre(width()/2, height()/2);
    QPointF first(centre.x(), centre.y()-200);
    QPainterPath path;
    QString str = QString::number(12);
    path.addText(first, font, str);
    painter.drawPath(path);
    for (int i = 1; i <= 11; i++) {
        QPointF pnew = quay(first, centre, 30*i);
        QPainterPath path;
        QString str = QString::number(i);
        path.addText(pnew, font, str);
        painter.drawPath(path);
    }


    QPointF secondNew, second(first.x(), first.y() + 20);
    secondNew = quay(second, centre, 360 * position/60);
    painter.setPen(Qt::red);
    painter.drawLine(centre, secondNew);

    painter.setPen(Qt::black);
    QPointF minuteNew, minute(first.x(), first.y() + 30);
    minuteNew = quay(minute, centre, (360 * position)/60*60);
    painter.drawLine(centre, minuteNew);

    QPointF hourNew, hour(first.x(), first.y() + 60);
    hourNew = quay(hour, centre, (360 * position) / (60*60*60));
    painter.drawLine(centre, hourNew);
}

//void graphics::drawNightSky(QPainter &painter) {
//    QPointF centre(200, 200);
//    QPointF x[];
//    QPointF first(centre.x(), centre.y()-50);
//}


QPointF graphics::dichuyen(QPointF p, double kc, int huong) {
    QPointF pnew;
    pnew.setX(p.x() + kc*cos(M_PI*huong/180));
    pnew.setY(p.y() + kc*sin(M_PI*huong/180));
    return pnew;
}

