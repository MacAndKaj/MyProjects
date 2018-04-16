#ifndef QBALANCEWIDGET_H
#define QBALANCEWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QResizeEvent>

class QBalanceWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QBalanceWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

signals:

public slots:


};

#endif // QBALANCEWIDGET_H
