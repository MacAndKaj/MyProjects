#ifndef PORT_H
#define PORT_H

#include <iostream>
#include <QDialog>
#include <QSerialPortInfo>
#include <QDebug>

namespace Ui {
	class Port;
}

class Port : public QDialog
{
	Q_OBJECT

public:
	explicit Port(QWidget *parent = 0);
	~Port();
signals:
	void changed_ip(QString ip);

private slots:
	void on_buttonBox_accepted();

private:
	Ui::Port *ui;
};

#endif // PORT_H
