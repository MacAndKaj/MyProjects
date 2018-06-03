#ifndef PORT_H
#define PORT_H
/*!
  * \file
  *	\brief File contains a class Port
  *
  *
  */

#include <iostream>
#include <QDialog>
#include <QSerialPortInfo>
#include <QDebug>

namespace Ui {
	class Port;
}


///
/// \brief The Port class is modeling a window to choose a port.
///
/// Class Port is used when user wants to change a port
/// which device is connected to. It inherits from QDialog.
///
class QPortDialog : public QDialog
{
	Q_OBJECT

public:
	explicit QPortDialog(QWidget *parent = 0);
	~QPortDialog();
	void refresh();
signals:
	void changed_ip(QString ip);

private slots:
	void on_buttonBox_accepted();

private:
	Ui::Port *ui;
};

#endif // PORT_H
