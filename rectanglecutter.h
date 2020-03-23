#ifndef RECTANGLECUTTER_H
#define RECTANGLECUTTER_H
#include "point.h"
#include "rectangle.h"


class RectangleCutter
{
public:
    RectangleCutter(Point lbc, Point rtc);
    Rectangle cut(Rectangle toCut);


private:
    Point leftBotCut, rightTopCut;
    void checkPoint(Point toCheck, Point* newLeftBot);

};

#endif // RECTANGLECUTTER_H
