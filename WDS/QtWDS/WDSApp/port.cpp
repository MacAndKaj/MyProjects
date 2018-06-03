#include "port.h"
#include "ui_port.h"

///Constructor
/// \brief Port::Port Constructor
/// \param parent Parent QWidget
///
QPortDialog::QPortDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Port)
{
	this->ui->setupUi(this);
	Q_FOREACH(QSerialPortInfo port,QSerialPortInfo::availablePorts()){
		this->ui->comboBox->addItem(port.portName());
	}

}

///Destructor.
/// \brief Port::~Port Constructor
///
QPortDialog::~QPortDialog()
{
	delete ui;
}

///When Port window is opened the list of available ports is updated using this function.
/// \brief Port::refresh Updates a list of available ports.
///
void QPortDialog::refresh()
{
	Q_FOREACH(QSerialPortInfo port,QSerialPortInfo::availablePorts()){
		this->ui->comboBox->addItem(port.portName());
	}
}

///Slot used when OK button is clicked, it means new port have been chosen.
/// \brief Port::on_buttonBox_accepted Slot used to confirm changes.
///
void QPortDialog::on_buttonBox_accepted()
{
	//else emit ip_changed(this->ui->input_ip->text());
	emit changed_ip(this->ui->comboBox->currentText());
}
