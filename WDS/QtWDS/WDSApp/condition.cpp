#include "condition.h"

///Condition widget constructor.
/// \brief Condition::Condition Condition widget constructor
/// \param[in] parent Parent QWidget.
///
QConditionWidget::QConditionWidget(QWidget *parent) : QWidget(parent)
{
    this->_is_connected = false;

}

/// Paint Event is used to draw a circle with color dependable of condition of connection.
/// \brief Condition::paintEvent
/// \param[in] event - a request to repaint all or part of a widget.
///
void QConditionWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    QPen pen;
    pen.setWidth(3);
    QBrush brush;
    painter.setBrush(brush);
    painter.setPen(pen);

    if(this->_is_connected){
        brush.setColor(Qt::green);
        pen.setColor(Qt::black);
        painter.drawEllipse(event->rect().center(),10,10);
    }
    else{
        brush.setColor(Qt::red);
        pen.setColor(Qt::black);
        painter.drawEllipse(event->rect().center(),10,10);
    }
    brush.setStyle(Qt::SolidPattern);
    QPainterPath path;
    path.addEllipse(event->rect().center(),10,10);

    painter.fillPath(path,brush);
    QWidget::paintEvent(event);
    painter.end();
}

///
/// \brief Condition::is_Connected method used when you want to know if device is connected
/// \return True when is connected, False otherwise
///
bool QConditionWidget::is_Connected()
{
    return this->_is_connected;
}

///
/// \brief Connected slot used when connection event occurs.
///
void QConditionWidget::Connected()
{
    this->_is_connected=true;
    this->update();
}

///
/// \brief Disconnected slot used when disconnection event occurs.
///
void QConditionWidget::Disconnected()
{
    this->_is_connected=false;
    this->update();
}


