#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>

class graphics : public QWidget
{
    Q_OBJECT
public:
    explicit graphics(QWidget *parent = 0);
    void timerEvent(QTimerEvent *);
    double position;
    double timerId;
    double angle;

    void paintEvent(QPaintEvent *);
    void drawExample(QPainter& painter);
    QPointF quay(QPointF p, QPointF c, int delta);
    void animationCircle(QPainter& painter);
    void drawStar(QPainter & painter, QPointF pcenter, int r);
    void solarSystem(QPainter& painter);
    void thousandStars(QPainter& painter);
    int random(int n);
signals:

public slots:

};

#endif // GRAPHICS_H
