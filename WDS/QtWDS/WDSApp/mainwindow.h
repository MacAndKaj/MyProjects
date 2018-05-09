#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QPainter>
#include <QMainWindow>
#include <QMessageBox>
#include <QtSerialPort>
#include <QDebug>
#include "condition.h"
#include "port.h"

namespace Ui {
	class MainWindow;
}



class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	void closeEvent(QCloseEvent *event);


public slots:
	void RP_ChangeRoll(int &ang);
	void RP_ChangePitch(int &ang);
	void on_actionDisconnect_triggered();
	void on_actionConnect_triggered();
	void realtimeDataSlot();
	void ip_changed(QString ip);
	void newData();

signals:
	void Connect_clicked();
	void Disconnect_clicked();


private slots:
	void on_actionAbout_triggered();
	void on_actionConfig_triggered();

private:
	uint16_t Roll,Pitch,Pressure1,Pressure2;
	Ui::MainWindow *ui;
	Port *ip;
	QTimer *timer;
	QString *ip_string;
	QSerialPort *arduino;
	QByteArray *data;
};

#endif // MAINWINDOW_H
