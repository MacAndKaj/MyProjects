#include "port.h"
#include "ui_port.h"

Port::Port(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Port)
{
	this->ui->setupUi(this);
	Q_FOREACH(QSerialPortInfo port,QSerialPortInfo::availablePorts()){
		this->ui->comboBox->addItem(port.portName());
	}

}

Port::~Port()
{
	delete ui;
}

void Port::on_buttonBox_accepted()
{
	qDebug() << this->ui->comboBox->currentText() << endl;

	//else emit ip_changed(this->ui->input_ip->text());
	emit changed_ip(this->ui->comboBox->currentText());
}
