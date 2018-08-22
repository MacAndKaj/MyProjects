#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*!
  * \file
  *	\brief File contains a class MainWindow
  *
  * MainWindow inherits from QMainWindow class
  * and it is main class of application.
  *
  */




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


///
/// \brief The MainWindow class
///
/// MainWindow contains all of widgets.
/// It is modeling a main window of application where
/// are other used elements.
///
class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	void closeEvent(QCloseEvent *event);


public slots:
	void RP_ChangeRoll(int16_t &ang);
	void RP_ChangePitch(int16_t &ang);
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

	void on_actionHelp_triggered();

private:
	int16_t _Roll,_Pitch,_HAGL,_HASL;
	Ui::MainWindow *ui;
	QPortDialog *ip;
	QTimer *timer;
	QString *ip_string;
	QSerialPort *arduino;
	char *data;
};

#endif // MAINWINDOW_H
