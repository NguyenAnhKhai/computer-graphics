#include "graphics.h"
#include "math.h"
#include <QPainter>

graphics::graphics(QWidget *parent) :
    QWidget(parent)
{
}

void graphics::paintEvent(QPaintEvent *){
    QPainter painter(this);
//    painter.setPen(Qt::red); // set color
//    painter.drawLine(1,1,50,50);

//    if(mode==1){
//        DrawLines(painter); // goi ham DrawLines neu mode ve = 1
//        DrawCircle(painter);
//        DrawRect(painter);
//    }

//    DrawColorExample(painter); //Fill color
//    drawCircleInsideSquare(painter);
//    drawExtremes(painter); // ve thai cuc
//    drawHouse(painter);
    drawChessBoard(painter);
}

void graphics::DrawLines(QPainter &painter){
    painter.setPen(Qt::red);
    painter.drawLine(10,10,50,50);
}

void graphics::DrawCircle(QPainter &painter){
    painter.setPen(Qt::black);
    painter.drawEllipse(70,70,50,50);
}

void graphics::DrawRect(QPainter &painter){
    painter.setPen(Qt::blue);
    painter.drawRect(40, 100, 50, 100);
}


 void graphics::DrawColorExample(QPainter &painter){
    painter.setPen(QColor('#d4d4d4'));
    int x1 = 10, x2 = 130, x3 = 250;
    int y1 = 15, y2 = 105, y3 = 195;
    painter.setBrush(QBrush('#c56c00'));
    painter.drawRect(x1,y1,90,60);
    painter.setBrush(QBrush('#c56c00'));
    painter.drawRect(x2,y1,90,60);
    painter.setBrush(QBrush('#c56c00'));
    painter.drawRect(x3,y1,90,60);
    painter.setBrush(QBrush('#c56c00'));
    painter.drawRect(x1,y2,90,60);
    painter.setBrush(QBrush('#c56c00'));
    painter.drawRect(x2,y2,90,60);
    painter.setBrush(QBrush('#c56c00'));
    painter.drawRect(x3,y2,90,60);
}


// Viet thu tuc ve mot hinh vuong noi tiep hinh tron
void graphics::drawCircleInsideSquare(QPainter &painter){
    double radius = 200; // Ban kinh duong tron
    double delta, len; //delta la khoang cach tu canh hinh vuong den canh hinh tron, len la do dai canh hinh vuong
    double x = 70, y = 70;
    delta = radius*(1-(sqrt(2)/2));
    len =  radius*sqrt(2);
    // set color PEN
    painter.setPen(QColor('#222222'));
    painter.setBrush(QBrush("#f00000"));
    painter.drawEllipse(x, y, 2*radius, 2*radius); // painter.drawEllipse(x,y, diameter, diameter)
    painter.setBrush(QBrush("#11f014"));
    painter.drawRect(x+delta, x+delta, len, len );

}

// Viet thu tuc ve thai cuc
void graphics::drawExtremes(QPainter &painter){
    double diameter = 500; // diameter: duong kinh hinh tron
    double x, y;
    x = 100;
    y = 100;
    painter.setPen(QColor("black"));
    painter.drawEllipse(x, y, diameter, diameter);
//    painter.drawEllipse(x, y+(diameter/4), (diameter/2), (diameter/2));
//    painter.drawEllipse(x+(diameter/2), y+(diameter/4), (diameter/2), (diameter/2));
//    void QPainter::drawArc(int x, int y, int width, int height, int startAngle, int spanAngle)

    painter.drawArc(x, y+(diameter/4), (diameter/2), (diameter/2), 180*16, 180*16 );
    painter.drawArc(x+(diameter/2), y+(diameter/4), (diameter/2), (diameter/2), 180*-16, 180* -16);
}

void graphics::drawHouse(QPainter &painter){
    painter.setPen(QColor('red'));
//    static const QPointF points[4] = {
//        QPointF(10.0, 80.0),
//        QPointF(20.0, 10.0),
//        QPointF(80.0, 30.0),
//        QPointF(90.0, 70.0)
//    };


//    painter.drawPolygon(points, 4);

    static const QPointF point[5] = {
        QPointF(200,100),
        QPointF(160,200),
        QPointF(240,200),
        QPointF(160,360),
        QPointF(240,360)
    };

    painter.drawPolyline(point, 5);
//    painter.drawPolygon(point, 5);
}

void graphics::drawChessBoard(QPainter &painter){
    painter.setPen(QColor('black'));

    for(int i = 100; i <= 400; i+=100){
         painter.setBrush(QBrush("#222222"));
        for(int j = 100; j <= 400; j+=100){

            painter.drawRect(i, j, 50, 50);
        }
    }
    painter.setBrush(QBrush("#ffffff"));
    for(int i = 150; i <= 450; i+=100){
        for(int j = 150; j <= 450; j+=100){

            painter.drawRect(i, j, 50, 50);
        }
    }

}
