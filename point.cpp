#include "point.h"

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

bool Point::operator <(const Point &pt)
{
    return (this->x < pt.x && this->y < pt.y);
}

bool Point::operator >(const Point &pt)
{
    return (this->x > pt.x && this->y > pt.y);
}
