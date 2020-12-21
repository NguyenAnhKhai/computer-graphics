#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>

class graphics : public QWidget
{
    Q_OBJECT
public:
    explicit graphics(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void DrawLines(QPainter& painter);
    void DrawCircle(QPainter& painter);
    void DrawRect(QPainter& painter);
    void DrawColorExample(QPainter& painter);

    void drawCircleInsideSquare(QPainter& painter);
    void drawExtremes(QPainter& painter);
    void drawChessBoard(QPainter& painter);
    void drawHouse(QPainter& painter);

    int mode = 0;

signals:

public slots:

};

#endif // GRAPHICS_H
