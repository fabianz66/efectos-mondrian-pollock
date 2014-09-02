#include "LabelImagen.h"
#include <QDebug>

LabelImagen::LabelImagen(QWidget *parent) :
    QLabel(parent)
{
}

void LabelImagen::mouseMoveEvent(QMouseEvent* event)
{
    mMovePos = event->pos();
}

void LabelImagen::mousePressEvent(QMouseEvent* event)
{
    mPressPos = event->pos();
    mMovePos = event->pos();
}

void LabelImagen::mouseReleaseEvent(QMouseEvent* event)
{
    /** Si se comenzo de abajo para arriba */
    if(mPressPos.y() > mMovePos.y())
    {
        int temp = mPressPos.y();
        mPressPos.setY(mMovePos.y());
        mMovePos.setY(temp);
    }

    /** Si se comenzo de iz a der */
    if(mPressPos.x() > mMovePos.x())
    {
        int temp = mPressPos.x();
        mPressPos.setX(mMovePos.x());
        mMovePos.setX(temp);
    }

    Tracking::getInstance().comenzarRastreo(QRect(mPressPos,mMovePos));

    /** Borro el cuadro q dibuje */
    mPressPos = QPoint(0,0);
    mMovePos = QPoint(0,0);
    repaint();
}

void LabelImagen::paintEvent(QPaintEvent* event)
{
    QLabel::paintEvent(event);
    QPainter painter(this);
    painter.drawRect(QRect(mPressPos,mMovePos));
}
