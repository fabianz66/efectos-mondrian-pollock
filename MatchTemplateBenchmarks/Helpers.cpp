#include "Helpers.h"
#include <QString>
#include <QMessageBox>
#include <QFont>

Helpers::Helpers()
{

}

Point Helpers::getMinPointFromList(QList<double>& pointValues, QList<Point> &points)
{
    double minValue = pointValues.at(0);
    int minValuePos = 0;
    for(int pos=0; pos < pointValues.size(); pos++)
    {
        if(pointValues.at(pos) < minValue)
        {
            minValue = pointValues.at(pos);
            minValuePos = pos;
        }
    }
    return points.at(minValuePos);
}

Point Helpers::getMaxPointFromList(QList<double>& pointValues, QList<Point> &points)
{
    double maxValue = pointValues.at(0);
    int maxValuePos = 0;
    for(int pos=0; pos < pointValues.size(); pos++)
    {
        if(pointValues.at(pos) > maxValue)
        {
            maxValue = pointValues.at(pos);
            maxValuePos = pos;
        }
    }
    return points.at(maxValuePos);
}

void Helpers::showAlertMessage(QString pTitle, QString pMessage)
{
    QMessageBox ventana;
    ventana.setText(pMessage);
    ventana.setFont(QFont("Calibri",12));
    ventana.setWindowTitle(pTitle);
    ventana.exec();
}
