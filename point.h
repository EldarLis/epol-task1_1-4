#ifndef POINT_H
#define POINT_H


class Point
{
    // nothing special
public:
    Point();
    Point(int x, int y);

    bool operator <(const Point &ptf);
    bool operator >(const Point &ptf);

    int x, y;
};

#endif // POINT_H
