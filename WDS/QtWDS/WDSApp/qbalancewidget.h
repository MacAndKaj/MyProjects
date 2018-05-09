#ifndef QBALANCEWIDGET_H
#define QBALANCEWIDGET_H

#include <QObject>
#include <QPushButton>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QtMath>
#include <iostream>


class QBalanceWidget: public QWidget{
    Q_OBJECT
public:
    explicit QBalanceWidget(QWidget *parent = 0);
	~QBalanceWidget();
	void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
	int get_Roll();
	int get_Pitch();

signals:
	void RollChanged(int& ang);
	void PitchChanged(int& ang);

public slots:
	void ChangeRoll(uint16_t&);
	void ChangePitch(uint16_t&);

private:
	int _Roll;
	int _Pitch;
};

#endif // QBALANCEWIDGET_H
