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

    //seters
    void set_LCD_AGL(const int &num);
    void set_LCD_ASL(const int &num);
    void set_LCD_Roll_1(const int &num);
    void set_LCD_Roll_2(const int &num);
    void set_LCD_Pitch(const int &num);

    void closeEvent(QCloseEvent *event);

private slots:
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
