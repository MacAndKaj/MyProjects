#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Text_Condition->setText(QObject::tr("Disconnected"));
    ui->LCD_AGL->display("------");
    ui->LCD_ASL->display("------");
    ui->LCD_Pitch->display("---");
    ui->LCD_Roll_1->display("---");
    ui->LCD_Roll_2->display("---");
    connect(this,SIGNAL(Connect_clicked()),ui->Connection_Cond,SLOT(Connected()));
    connect(this,SIGNAL(Disconnect_clicked()),ui->Connection_Cond,SLOT(Disconnected()));
}

MainWindow::~MainWindow()
{
    delete ui;
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
