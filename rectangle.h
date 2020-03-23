#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include "cmath"
#include "point.h"


class Rectangle
{
public:
    // i hope you will value my point class :D
    Rectangle(Point lb, Point rt);
    Rectangle(Point lb, int width, int height);
    Rectangle();
    ~Rectangle();
    bool isInside(int x, int y);
    void changeGeometry();

    // static values for number, perimeter and area;
    static int numberOfRects;
    static int commonPerimeter, commonArea;

    // left bottom and right top points
    Point leftBot, rightTop;

    // different simple values
    // arent private or protected because i didnt want to fight with a lot of setters or/and getters
    // i actually should make them private, because any change in them wont count as change and calculations will fail
    // excuse me this time
    // but if youd say me so, ill do them private next weekends ;)
    int width, height;
    int perimeter, area;
    double inscribedCircleRadius, circumscribedCircleRadius;
    bool isSquare;

private:
    //these are private because they are not needed outside the class ;)
    void changeSides();
    void changePoints();
    void Calculations();
    bool pointPlacement(Point newF, Point newS);
    void pointPlacementFree(Point newF, Point newS);
};


#endif // RECTANGLE_H
