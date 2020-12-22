#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>


class graphics : public QWidget
{
    Q_OBJECT
public:
    explicit graphics(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
  
    QPoint quay(QPoint p, QPoint c, int delta);

    void bonghoa(QPainter& painter);
   
signals:
    
public slots:
    
};

#endif // GRAPHICS_H
