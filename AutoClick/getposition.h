#ifndef GETPOSITION_H
#define GETPOSITION_H

#include "standard.h"

#include <QDialog>
#include <QApplication>
#include <QDesktopWidget>
#include <QMouseEvent>


class GetPosition : public QDialog
{
    Q_OBJECT
public:
    GetPosition();
    int getX() const;
    int getY() const;
    void setX(int value);
    void setY(int value);

private:
    int x;
    int y;

    void mousePressEvent(QMouseEvent *event) override;
Q_SIGNALS:
    void MousePressed(bool isPressed);
};

#endif // GETPOSITION_H
