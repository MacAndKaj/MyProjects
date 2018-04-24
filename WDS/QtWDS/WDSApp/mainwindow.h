#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPainter>
#include <QMainWindow>
#include <QMessageBox>
#include "condition.h"

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

signals:
	void Connect_clicked();
	void Disconnect_clicked();


private:
	Ui::MainWindow *ui;
	QTimer *timer;

};

#endif // MAINWINDOW_H
