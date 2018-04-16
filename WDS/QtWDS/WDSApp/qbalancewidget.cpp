#include "qbalancewidget.h"

QBalanceWidget::QBalanceWidget(QWidget *parent) : QWidget(parent)
{

}

void QBalanceWidget::paintEvent(QPaintEvent *event)
{
    int penWidth=5;
    QPainter painter;
    QPen pen;
    QPainterPath path;
    QBrush brush;
    QPoint center = event->rect().center();
    painter.begin(this);
    pen.setWidth(penWidth);
    painter.setRenderHint(QPainter::Antialiasing);

    pen.setColor(Qt::black);
    brush.setColor(QColor(179, 255, 255,255));

    int myRx = this->width()/2-penWidth;
    int myRy = this->height()/2-penWidth;

    painter.setPen(pen);
    brush.setStyle(Qt::SolidPattern);

    if(myRx<myRy){
        painter.drawEllipse(center,myRx,myRx);


        path.addEllipse(center,myRx,myRx);

        painter.fillPath(path,brush);
        painter.drawLine(QPoint(center.rx()-0.8*myRx,this->height()/2),QPoint(center.rx() - (0.2*myRx),this->height()/2));
        painter.drawLine(QPoint(center.rx()+0.8*myRx,this->height()/2),QPoint(center.rx() + (0.2*myRx),this->height()/2));
        painter.drawLine(QPoint(center.rx() - (0.2*myRx),this->height()/2),QPoint(center.rx(),center.ry()-0.15*myRx));
        painter.drawLine(QPoint(center.rx(),center.ry()-0.15*myRx),QPoint(center.rx()+0.2*myRx,this->height()/2));


    }
    else{
        painter.drawEllipse(center,myRy,myRy);

        path.addEllipse(center,myRy,myRy);

        painter.fillPath(path,brush);
        painter.drawLine(QPoint(center.rx()-0.8*myRy,this->height()/2),QPoint(center.rx() - (0.2*myRy),this->height()/2));
        painter.drawLine(QPoint(center.rx()+0.8*myRy,this->height()/2),QPoint(center.rx() + (0.2*myRy),this->height()/2));
        painter.drawLine(QPoint(center.rx() - (0.2*myRy),this->height()/2),QPoint(center.rx(),center.ry()-0.15*myRy));
        painter.drawLine(QPoint(center.rx(),center.ry()-0.15*myRy),QPoint(center.rx()+0.2*myRy,this->height()/2));

    }




    QWidget::paintEvent(event);
    painter.end();



}

void QBalanceWidget::resizeEvent(QResizeEvent *event)
{
    if(this->width() != this->height()){
        this->resize(this->width(),this->height());
        this->update();
    }
    QWidget::resizeEvent(event);
}

