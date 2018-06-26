#ifndef QBALANCEWIDGET_H
#define QBALANCEWIDGET_H
/*!
  * \file
  *	\brief File contains a class QBalanceWidget
  *
  *
  *
  */

#include <QObject>
#include <QPushButton>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QtMath>
#include <iostream>



///
/// \brief The QBalanceWidget class visualises angles Roll & Pitch of device.
///
/// QBalanceWidget is used to visualise Roll & Pitch angles in main window.
/// It inherits from QWidget and defines own methods paintEvent and resizeEvent
///
class QBalanceWidget: public QWidget{
    Q_OBJECT
public:
    explicit QBalanceWidget(QWidget *parent = 0);
	~QBalanceWidget();
	void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
	int16_t get_Roll();
	int16_t get_Pitch();

signals:
	void RollChanged(int16_t& ang);
	void PitchChanged(int16_t& ang);

public slots:
	void ChangeRoll(int16_t&);
	void ChangePitch(int16_t&);

private:
	int16_t _Roll;
	int16_t _Pitch;
};

#endif // QBALANCEWIDGET_H
