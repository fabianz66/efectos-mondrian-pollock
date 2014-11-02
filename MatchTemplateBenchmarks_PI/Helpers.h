#ifndef HELPERS_H
#define HELPERS_H

#include <opencv2/opencv.hpp>
#include <QList>

using namespace cv;

class Helpers
{
public:
    Helpers();

    static Point getMinPointFromList(QList<double>& pointValues, QList<Point>& points);
    static Point getMaxPointFromList(QList<double>& pointValues, QList<Point>& points);
    static void showAlertMessage(QString pTitle, QString pMessage);
};

#endif // HELPERS_H
