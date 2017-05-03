#include "getposition.h"

GetPosition::GetPosition()
{
    QRect winRect = QApplication::desktop()->geometry();
    setGeometry(winRect);
    setWindowOpacity(0.2);
}

int GetPosition::getX() const
{
    return x;
}

int GetPosition::getY() const
{
    return y;
}

void GetPosition::setX(int value)
{
    x = value;
}

void GetPosition::setY(int value)
{
    y = value;
}

void GetPosition::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        QPoint qPoint = event->globalPos();
        x = qPoint.x();
        y = qPoint.y();
        this->hide();
        emit MousePressed(true);
    }
}
