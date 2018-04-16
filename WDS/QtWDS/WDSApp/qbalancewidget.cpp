#include "qbalancewidget.h"

QBalanceWidget::QBalanceWidget(QWidget *parent) : QWidget(parent)
{

}

void QBalanceWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    QPen pen;
    pen.setWidth(10);
    QBrush brush;
    painter.setRenderHint(QPainter::Antialiasing);

    pen.setColor(Qt::black);
    painter.drawEllipse(event->rect());


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

