#ifndef LABELIMAGEN_H
#define LABELIMAGEN_H

#include <QLabel>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <Tracking.h>

class LabelImagen : public QLabel
{

private:
    QPoint mPressPos;
    QPoint mMovePos;

    Q_OBJECT
public:
    explicit LabelImagen(QWidget *parent = 0);

private:
    void mouseMoveEvent(QMouseEvent* /*event*/ );
    void mousePressEvent(QMouseEvent* /*event*/ );
    void mouseReleaseEvent(QMouseEvent* /*event*/ );
    void paintEvent(QPaintEvent* /*event*/);
};

#endif // LABELIMAGEN_H
