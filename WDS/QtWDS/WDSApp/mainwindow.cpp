#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->timer = new QTimer(this);
    //---------------------------------- start values -------------------
    ui->Text_Condition->setText(QObject::tr("Disconnected"));
    ui->LCD_AGL->display("------");
    ui->LCD_ASL->display("------");
    ui->LCD_Pitch->display("---");
    ui->LCD_Roll_1->display("---");
    ui->LCD_Roll_2->display("---");

    //---------------setup plotting--------------------------------------
    ui->Widget_AXL->addGraph();
    ui->Widget_AXL->addGraph();
    ui->Widget_AXL->graph(0)->setPen(QColor(Qt::blue));
    ui->Widget_AXL->graph(1)->setPen(QColor(Qt::green));
    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");

    ui->Widget_AXL->xAxis->setTicker(timeTicker);
    ui->Widget_AXL->axisRect()->setupFullAxesBox();
    ui->Widget_AXL->yAxis->setRange(0,300);
    ui->Widget_AXL->adjustSize();


    connect(this,SIGNAL(Connect_clicked()),ui->Connection_Cond,SLOT(Connected()));          //click connect -> light green
    connect(this,SIGNAL(Disconnect_clicked()),ui->Connection_Cond,SLOT(Disconnected()));    //click disconnect -> light red
    connect(ui->actionExit,SIGNAL(triggered(bool)),this,SLOT(close()));                     //exit -> asking for sure
    connect(ui->Widget_AXL->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->Widget_AXL->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->Widget_AXL->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->Widget_AXL->yAxis2, SLOT(setRange(QCPRange)));

    connect(this->timer,SIGNAL(timeout()),this,SLOT(realtimeDataSlot()));
    this->timer->start(0);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->timer;
}


///Function sets a value displayed as a height above ground-level.
/// \brief MainWindow::set_LCD_Height sets height AGL.
/// \param num Numeric value if height as integer.
///
void MainWindow::set_LCD_AGL(const int &num){
  ui->LCD_AGL->display(num);
}

///Function sets a value displayed as a height above sea-level.
/// \brief MainWindow::set_LCD_ASL sets height ASL.
/// \param num Numeric value if height as integer.
///
void MainWindow::set_LCD_ASL(const int &num){
  ui->LCD_ASL->display(num);
}

///Function sets a value displayed as a pitch angle.
/// \brief MainWindow::set_LCD_Pitch
/// \param num Numeric value of pitch angle as integer.
///
void MainWindow::set_LCD_Pitch(const int &num){
    ui->LCD_Pitch->display(num);
}

///This overriden method asks user if he is sure he wants to exit applications. Method catches QCloseEvent end writes decision into it.
/// \brief MainWindow::closeEvent Overriden method to show a window asking for confirmation.
/// \param event QCloseEvent
///
void MainWindow::closeEvent(QCloseEvent *event)
{
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

///Function sets a value displayed as a roll angle.
/// \brief MainWindow::set_LCD_Roll_1
/// \param num Numeric value of roll angle as integer.
///
void MainWindow::set_LCD_Roll_1(const int &num){
    ui->LCD_Roll_1->display(num);
}

///Function sets a value displayed as a roll angle.
/// \brief MainWindow::set_LCD_Roll_2
/// \param num Numeric value of roll angle as integer.
///
void MainWindow::set_LCD_Roll_2(const int &num){
    ui->LCD_Roll_2->display(num);
}

///
/// \brief MainWindow::on_actionDisconnect_triggered
///
void MainWindow::on_actionDisconnect_triggered()
{
    emit this->Disconnect_clicked();
    ui->Text_Condition->setText(QObject::tr("Disconnected"));
    ui->LCD_AGL->display("------");
    ui->LCD_ASL->display("------");
    ui->LCD_Pitch->display("---");
    ui->LCD_Roll_1->display("---");
    ui->LCD_Roll_2->display("---");
    QMessageBox::warning(nullptr,QObject::tr("Error!"),QObject::tr("No connection!"));
}

///
/// \brief MainWindow::on_actionConnect_triggered
///
void MainWindow::on_actionConnect_triggered()
{
    emit this->Connect_clicked();
    ui->Text_Condition->setText(QObject::tr("Connected"));
    QMessageBox::information(nullptr,QObject::tr("Succes!"),QObject::tr("Succesfully connected to device"));

}

void MainWindow::realtimeDataSlot()
{
    if(ui->Connection_Cond->is_Connected()){
        static QTime time(QTime::currentTime());
        // calculate two new data points:
        double key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds
        static double lastPointKey = 0;
        if (key-lastPointKey > 0.1)
        {
            // add data to lines:
            ui->Widget_AXL->graph(0)->addData(key, 300*qSin(key)+qrand()/(double)RAND_MAX*1*qSin(key/0.3843));
            ui->Widget_AXL->graph(1)->addData(key, 300*qCos(key)+qrand()/(double)RAND_MAX*0.5*qSin(key/0.4364));
            // rescale value (vertical) axis to fit the current data:
            ui->Widget_AXL->graph(0)->rescaleValueAxis();
            ui->Widget_AXL->graph(1)->rescaleValueAxis(true);
            lastPointKey = key;
        }
        // make key axis range scroll with the data (at a constant range size of 8):
        ui->Widget_AXL->xAxis->setRange(key, 8, Qt::AlignRight);
        ui->Widget_AXL->replot();

        ui->Widget_RP->update();

    }
}

