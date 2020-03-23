#include "rectanglecutter.h"

//basic constructor
RectangleCutter::RectangleCutter(Point lbc, Point rtc)
{
    leftBotCut = lbc;
    rightTopCut = rtc;
}

//methods that created new rectangle cut from input rectangle inside the work space
Rectangle RectangleCutter::cut(Rectangle toCut)
{
    Point newLeftBot, newRightTop;

    checkPoint(toCut.leftBot, &newLeftBot);
    checkPoint(toCut.rightTop, &newRightTop);

    return Rectangle(newLeftBot, newRightTop);
}

//method below is for code reuse in cut method
//it check where x and y are, and sets them to according positions
//rules are after the method (check them out!)
void RectangleCutter::checkPoint(Point toCheck, Point* newLeftBot)
{

    if (toCheck.x < leftBotCut.x)
        newLeftBot->x = leftBotCut.x;
    else
        {
            if (toCheck.x >= leftBotCut.x && toCheck.x <= rightTopCut.x)
                newLeftBot->x = toCheck.x;
            else
                if (toCheck.x > rightTopCut.x)
                    newLeftBot->x = rightTopCut.x;
        }

    if (toCheck.y < leftBotCut.y)
        newLeftBot->y = leftBotCut.y;
    else
        {
            if (toCheck.y >= leftBotCut.y && toCheck.y <= rightTopCut.y)
                newLeftBot->y = toCheck.y;
            else
                if (toCheck.y > rightTopCut.y)
                    newLeftBot->y = rightTopCut.y;
        }


}

/*
 * if x < leftbottom.x
 *      then x = leftbottom.x
 * if x >= leftbottom.x && x <= righttop.x
 *      then x = x
 * if x > righttop.x
 *      then x = righttop.x
 *
 * the same goes for y
*/
