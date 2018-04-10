#include "condition.h"

Condition::Condition(QWidget *parent) : QWidget(parent)
{
    this->_is_connected = false;

}

/// paint Event is used to draw a circle with color dependable of condition of connection.
/// /brief paintEvent overriden QWidget method
/// /param event QPaintEvent
///
void Condition::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    QPen pen;
    if(this->_is_connected){
        pen.setColor(Qt::green);
        painter.drawEllipse(event->rect());
    }
    else{
        pen.setColor(Qt::red);
        painter.drawEllipse(event->rect());
    }
    QWidget::paintEvent(event);
    painter.end();
}

///
/// \brief Connected slot used when connection event occurs.
///
void Condition::Connected()
{
    this->_is_connected=true;
    this->update();
}

///
/// \brief Disconnected slot used when disconnection event occurs.
///
void Condition::Disconnected()
{
    this->_is_connected=false;
    this->update();
}


