#include "mainwindow.h"
#include "ui_mainwindow.h"


///MainWindow constructor.
/// \brief MainWindow::MainWindow MainWindow constructor.
/// \param parent Parent QWidget.
///
MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow){
	this->ui->setupUi(this);
	this->timer = new QTimer(this);
	//---------------------------------- start values -------------------
	this->ui->Text_Condition->setText(QObject::tr("Disconnected"));
	this->ui->LCD_AGL->display("------");
	this->ui->LCD_ASL->display("------");
	this->ui->LCD_Pitch->display("---");
	this->ui->LCD_Roll_1->display("---");
	this->ui->LCD_Roll_2->display("---");

	//---------------setup plotting--------------------------------------
	this->ui->Widget_AXL->addGraph();
	this->ui->Widget_AXL->addGraph();
	this->ui->Widget_AXL->graph(0)->setPen(QColor(Qt::blue));
	this->ui->Widget_AXL->graph(1)->setPen(QColor(Qt::green));
	QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
	timeTicker->setTimeFormat("%h:%m:%s");

	this->ui->Widget_AXL->xAxis->setTicker(timeTicker);
	this->ui->Widget_AXL->axisRect()->setupFullAxesBox();
	this->ui->Widget_AXL->yAxis->setRange(0,300);
	this->ui->Widget_AXL->adjustSize();


	connect(this,SIGNAL(Connect_clicked()),this->ui->Connection_Cond,SLOT(Connected()));          //click connect -> light green
	connect(this,SIGNAL(Disconnect_clicked()),this->ui->Connection_Cond,SLOT(Disconnected()));    //click disconnect -> light red
	connect(this->ui->actionExit,SIGNAL(triggered(bool)),this,SLOT(close()));                     //exit -> asking for sure
	connect(this->ui->Widget_AXL->xAxis, SIGNAL(rangeChanged(QCPRange)), this->ui->Widget_AXL->xAxis2, SLOT(setRange(QCPRange)));
	connect(this->ui->Widget_AXL->yAxis, SIGNAL(rangeChanged(QCPRange)), this->ui->Widget_AXL->yAxis2, SLOT(setRange(QCPRange)));

	connect(this->ui->Widget_RP,SIGNAL(RollChanged(int&)),this,SLOT(RP_ChangeRoll(int&)));
	connect(this->ui->Widget_RP,SIGNAL(PitchChanged(int&)),this,SLOT(RP_ChangePitch(int&)));

	connect(this->timer,SIGNAL(timeout()),this,SLOT(realtimeDataSlot()));
	this->timer->start(0);

}

///MainWindow destructor.
/// \brief MainWindow::~MainWindow MainWindow destructor.
///
MainWindow::~MainWindow(){
	delete this->ui;
	delete this->timer;
}


///This overriden method asks user if he is sure he wants to exit applications. Method catches QCloseEvent end writes decision into it.
/// \brief MainWindow::closeEvent Overriden method to show a window asking for confirmation.
/// \param event QCloseEvent
///
void MainWindow::closeEvent(QCloseEvent *event){
	QMessageBox::StandardButton resBtn = QMessageBox::question( this, QObject::tr("Exiting"),
																QObject::tr("Are you sure?\n"),
																QMessageBox::No | QMessageBox::Yes,
																QMessageBox::Yes);
	if (resBtn != QMessageBox::Yes) {
		event->ignore();
	} else {
		event->accept();
	}
}


///Slot sets a value of Roll angle in LCDs, connected with a signal emited by qbalancewidget.
/// \brief MainWindow::_RP_ChangeRoll Sets a value of Roll angle
///	\param ang New Roll angle.
///
void MainWindow::RP_ChangeRoll(int& ang){
	this->ui->LCD_Roll_1->display(-ang);
	this->ui->LCD_Roll_2->display(ang);
}

///Slot sets a value of Pitch angle in LCD, connected with a signal emited by qbalancewidget.
/// \brief MainWindow::RP_ChangePitch Sets a value of Pitch angle.
/// \param ang New Pitch angle.
///
void MainWindow::RP_ChangePitch(int &ang){
	this->ui->LCD_Pitch->display(ang);
}

///Slot used when device option Disconnect from menu File is clicked.
/// \brief MainWindow::on_actionDisconnect_triggered
///
void MainWindow::on_actionDisconnect_triggered(){
	emit this->Disconnect_clicked();
	this->ui->Text_Condition->setText(QObject::tr("Disconnected"));
	this->ui->LCD_AGL->display("------");
	this->ui->LCD_ASL->display("------");
	this->ui->LCD_Pitch->display("---");
	this->ui->LCD_Roll_1->display("---");
	this->ui->LCD_Roll_2->display("---");
	QMessageBox::warning(nullptr,QObject::tr("Error!"),QObject::tr("No connection!"));
}

///Slot used when option Connect from menu File is clicked.
/// \brief MainWindow::on_actionConnect_triggered Slot connected with option Connect from menu File.
///
void MainWindow::on_actionConnect_triggered()
{
	emit this->Connect_clicked();
	this->ui->Text_Condition->setText(QObject::tr("Connected"));
	QMessageBox::information(nullptr,QObject::tr("Succes!"),QObject::tr("Succesfully connected to device"));

}


///Used to test with QTimer to generate random data and wisualising it on plot and balancewidget.
/// \brief MainWindow::realtimeDataSlot Test method.
///
void MainWindow::realtimeDataSlot()
{

	if(this->ui->Connection_Cond->is_Connected()){
		static QTime time(QTime::currentTime());
		// calculate two new data points:
		double key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds
		double d1 = 300*qSin(key)+qrand()/(double)RAND_MAX*1*qSin(key/0.3843);
		double d2 = 300*qCos(key)+qrand()/(double)RAND_MAX*0.5*qSin(key/0.4364);

		int a1 = qSin(key)*90;
		int a2 = qSin(key)*90;
		static double lastPointKey = 0;
		if (key-lastPointKey > 0.2)
		{

			this->ui->LCD_AGL->display(d1);
			this->ui->LCD_ASL->display(d2);

			// add data to lines:
			this->ui->Widget_AXL->graph(0)->addData(key, d1);
			this->ui->Widget_AXL->graph(1)->addData(key, d2);
			// rescale value (vertical) axis to fit the current data:
			this->ui->Widget_AXL->graph(0)->rescaleValueAxis();
			this->ui->Widget_AXL->graph(1)->rescaleValueAxis(true);
			this->ui->Widget_RP->ChangeRoll(a1);
			this->ui->Widget_RP->ChangePitch(a2);
			lastPointKey = key;
		}
		// make key axis range scroll with the data (at a constant range size of 8):
		this->ui->Widget_AXL->xAxis->setRange(key, 8, Qt::AlignRight);
		this->ui->Widget_AXL->replot();



		this->ui->Widget_RP->update();

	}
}

