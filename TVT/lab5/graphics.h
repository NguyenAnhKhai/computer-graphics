#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>

class graphics : public QWidget
{
    Q_OBJECT
public:
    explicit graphics(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);

    double timerid;
    double position;
    double hinh;
    QPixmap spritesheet;

    QPointF quay(QPointF p, QPointF c, int delta);
    void drawMegaman(QPainter& painter);
    void drawWatch(QPainter& painter);
    void drawNightSky(QPainter& painter);
    QPointF dichuyen(QPointF p, double kc, int huong);
signals:

public slots:

};

#endif // GRAPHICS_H
