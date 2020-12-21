#include "graphics.h"
#include "math.h"
#include <QPainter>

graphics::graphics(QWidget *parent) :
    QWidget(parent)
{
}

void graphics::paintEvent(QPaintEvent *) {
    QPainter painter(this);

    if (mode == 1)gingerbreadMan(painter);
    if (mode == 2)sierpinski(painter);
    if (mode == 3)ngansao(painter);
    if (mode == 4)drawHouse(painter, QPoint(300, 50), 300, 400);
    if (mode == 5) ngugiac(painter);
    if (mode == 6) rosette(painter, 10);
    quocky(painter);
}


// ------------- auxilary function ----------------
QPointF graphics::tinhtien(QPoint p, int tx, int ty) {
    QPointF pnew;
    pnew.setX(p.x() + tx);
    pnew.setY(p.y() + ty);
    return pnew; // pnew = (p.x() + tx, p.y() + ty)
}

QPoint graphics::quay(QPoint p, QPoint c, int delta) {
    QPoint pnew;
    double goc = delta * 3.14 / 180;
    pnew.setX(c.x() + (p.x() - c.x())*cos(goc) - (p.y() - c.y())*sin(goc));
    pnew.setY(c.y() + (p.x() - c.x())*sin(goc) + (p.y() - c.y())*cos(goc));
    return pnew;
}

QPoint graphics::doixungx(QPoint p) {
    QPoint pnew;
    pnew.setX(p.x());
    pnew.setY(-p.y());
    return pnew;
}

QPoint graphics::doixungy(QPoint p) {
    QPoint pnew;
    pnew.setX(-p.x());
    pnew.setY(p.y());
    return pnew;
}

// giao diem cua AC va BD
QPoint graphics::giaoDiem(QPoint A, QPoint B, QPoint C, QPoint D) {
    int a1 = (A.y() - C.y())/(A.x() - C.x());
    int b1 = A.y() - (A.x()*a1);

    int a2 = (B.y() - D.y())/(B.x() - D.x());
    int b2 = B.y() - (B.x()*a2);

    int x = (b1 - b2) / (a2 - a1);
    int y = a1*x + b1;
    return QPoint(x, y);
}

QPointF graphics::giaoDiemF(QPointF A, QPointF C, QPointF B, QPointF D) {
    float a1 = (A.y() - C.y())/(A.x() - C.x());
    float b1 = A.y() - (A.x()*a1);
    float a2 = (D.y() - B.y())/(D.x() - B.x());
    float b2 = B.y() - (B.x()*a2);

    float x = (b1 - b2) / (a2 - a1);
    float y = a1*x + b1;
    return QPointF(x, y);
}

// --------------------------------------------------

// ---------------- MAIN ----------------------------

int graphics::random(int n) {
    return rand() % n;
}

void graphics::ngansao(QPainter &painter) {
    for (int i = 0; i < 100; ++i) {
        painter.setPen(Qt::NoPen);
        painter.setBrush(QColor(random(255), random(255), random(255)));
        painter.drawEllipse(random(1000), random(1000), 3, 3);
    }
}

void graphics::gingerbreadMan(QPainter &painter) {
    QPoint p = QPoint(115, 121);
    for (int i = 0; i < 10000; i++) {
        QPoint q;
        q.setX(40*7 - p.y() + abs(p.x() - 40*3));
        q.setY(p.x());
        painter.drawPoint(q);
        p.setX(q.x());
        p.setY(q.y());
    }
}

void graphics::sierpinski(QPainter &painter) {
    const QPointF p[3] = {
        QPoint(500, 100),
        QPoint(200, 600),
        QPoint(800, 600)
    };
    int i = random(3);
    QPoint g_prev = QPoint(p[i].x(), p[i].y());
    painter.drawPoint(g_prev);
    for (int j = 0; j < 10000; j++) {
        int i = random(3);
        QPoint P = QPoint(p[i].x(), p[i].y());;
        QPoint gn = QPoint((g_prev.x() + P.x())/2, (g_prev.y() + P.y())/2);
        painter.drawPoint(gn);
        g_prev.setX(gn.x());
        g_prev.setY(gn.y());
    }
}

void graphics::drawHouse(QPainter &painter, QPoint p, int height, int width) {
    int x_top = p.x();
    int y_top = p.y();
    float half_width = width/2;

    static const QPointF housePoints[5] = {
        QPointF(x_top, y_top),
        tinhtien(p, -half_width, half_width),
        tinhtien(p, -half_width, (half_width + height)),
        tinhtien(p, half_width, (half_width + height)),
        tinhtien(p, half_width, half_width)
    };
    painter.drawPolygon(housePoints, 5);


    const QPointF doorPoint[4] = {
        tinhtien(p, -half_width * 1/3, half_width + height),
        tinhtien(p, -half_width * 1/3, half_width + height * 1/3),
        tinhtien(p, 0, half_width + height * 1/3),
        tinhtien(p, 0, half_width + height )
    };
    painter.drawPolygon(doorPoint, 4);

    const QPointF windowPoint[4] = {
        tinhtien(p, half_width * 1/2, half_width + height * 1/5),
        tinhtien(p, half_width * 1/3, half_width + height * 1/5),
        tinhtien(p, half_width * 1/3, half_width + height * 1/3),
        tinhtien(p, half_width * 1/2, half_width + height * 1/3)
    };
    painter.drawPolygon(windowPoint, 4);

//    const QPointF chimneyPoint[2] = {
//        QPointF(x_top - half_width*3/4, x_top - half_width*3/4),
//        QPointF(x_top - half_width*3/4, x_top - half_width*3/4 - 100),
////        QPointF(x_top - 1/2 * half_width, x_top + y_top - x_top - 1/2 * half_width),
////        QPointF(x_top - 1/4 * half_width, x_top + y_top - x_top - half_width * 1/4),
////        QPointF(x_top - 1/2 * half_width, 80),
////        QPointF(x_top - 1/4 * half_width, 40),

////        QPointF(x_top - 1/2 * half_width, y_top),
////        QPointF(x_top - 1/4 * half_width, y_top),
//    };

//    painter.drawPolygon(chimneyPoint, 2);

}

void graphics::bonghoa(QPainter &painter) {
    painter.setBrush(QColor(random(255), random(255), random(255)));
    int x = random(width());
    int y = random(height());

    int d = 100;
    int r = d/3;
    QPoint c(x,y);
    QPoint p(x, y-r);

    for( int i = 1; i <= 5; i++) {
        QPoint pnew = quay(p, c, i*72);
        painter.drawEllipse(pnew, r, r);
    }
}

void graphics::ngugiac(QPainter &painter) {
    painter.setPen(Qt::red);
    QPolygon polygon;
    int x = width()/2;
    int y = width()/2;
    QPoint p(x, y-100);
    QPoint c(x, y);
    polygon <<QPoint(p.x(), p.y());
    for (int i = 1; i < 5; i++) {
        QPoint pnew = quay(p, c, i*72);
        polygon <<QPoint(pnew.x(), pnew.y());
    }
//    painter.drawPolygon(polygon);

    painter.setPen(Qt::blue);
    for (int i = 0; i < 5; i++) {
        for (int j = i+1; j < 5; j++) {
            painter.drawLine(polygon.value(i), polygon.value(j));
        }
    }
}

void graphics::rosette(QPainter &painter, int n) {
    painter.setPen(Qt::red);
    QPolygon polygon;
    int x = height()/2;
    int y = width()/2;
    QPoint p(x, y-200);
    QPoint c(x, y);
    polygon <<QPoint(p.x(), p.y());
    for (int i = 1; i < n; i++) {
        QPoint pnew = quay(p, c, i* (360/n));
        polygon <<pnew;//QPoint(pnew.x(), pnew.y());
    }

    painter.setPen(Qt::blue);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            painter.drawLine(polygon.value(i), polygon.value(j));
        }
    }
}

void graphics::quocky(QPainter &painter) {
    QPolygon main_points, sub_points, main_;
    int x = height()/2, y = width()/2;
    QPoint p(x, y-200);
    QPoint c(x, y);
    main_points << p;
    for (int i = 1; i < 5; i++) {
        QPoint pnew = quay(p, c, i* (360/5));
        main_points <<QPoint(pnew.x(), pnew.y());
    }

    QPoint A(main_points.value(0));
    QPoint B(main_points.value(1));
    QPoint C(main_points.value(2));
    QPoint D(main_points.value(4));
    QPoint new_point = giaoDiem(A, B, C, D);

    sub_points <<QPoint(new_point.x(), new_point.y());
    for (int i = 1; i < 5; i++) {
        QPoint pnew = quay(new_point, c, i* (360/5));
        sub_points <<QPoint(pnew.x(), pnew.y());
    }

    for (int i = 0; i < 5; i++) {
        main_<<QPoint(main_points[i].x(), main_points[i].y());
        main_<<QPoint(sub_points[i].x(), sub_points[i].y());
    }

    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::red);
    painter.drawRect(int (c.x() - 250), int (c.y() - 250), 500, 450);

    painter.setBrush(Qt::yellow);
    painter.drawPolygon(main_);
}
