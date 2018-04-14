#ifndef CONDITION_H
#define CONDITION_H

#include <iostream>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

///Class which is a light informed about condition of connection. When is connected light is green and red otherwise.
/// \brief The Condition class inform about condition of connection.
///
class Condition : public QWidget
{
    Q_OBJECT
public:
    explicit Condition(QWidget *parent = 0);
    ~Condition() = default;

    void paintEvent(QPaintEvent *event);
    bool is_Connected();

public slots:
    void Connected();
    void Disconnected();
private:
    /// \brief _is_connected variable is true when connected and false otherwise.
    bool _is_connected;
};

#endif // CONDITION_H
