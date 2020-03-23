#ifndef CIRCUMSCRIBEDCIRCLE_H
#define CIRCUMSCRIBEDCIRCLE_H
#include "rectangle.h"


//inscribed - вписанный
//circumscribed - описанный
//поэтому да, класс называется так
class CircumscribedCircle
{
public:
    CircumscribedCircle(Rectangle *rect);
    double getRadius();

private:
    double circumscribedCircleRadius;
};

#endif // CIRCUMSCRIBEDCIRCLE_H
