#ifndef CONDITION_H
#define CONDITION_H
/*!
 *
 * \file
 * \brief Definition of Condition widget.
 *
 * A file contains definition of widget which visualises condition
 * of connection with a device.
 * It is a light green or red depending of a condition.
 *
 *
 *
 *
 */




#include <iostream>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

///Class which is a light informed about condition of connection. When is connected light is green and red otherwise.
/// \brief The Condition class inform about condition of connection.
///
class QConditionWidget : public QWidget
{
    Q_OBJECT
public:
	explicit QConditionWidget(QWidget *parent = 0);
	~QConditionWidget() = default;

    void paintEvent(QPaintEvent *event);
    bool is_Connected();

public slots:
    void Connected();
    void Disconnected();
private:
    bool _is_connected;
};

#endif // CONDITION_H
