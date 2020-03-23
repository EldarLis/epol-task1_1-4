#include "rectangle.h"

int Rectangle::numberOfRects = 0;
int Rectangle::commonPerimeter = 0;
int Rectangle::commonArea = 0;

Rectangle::Rectangle(Point lb, Point rt)
{
    perimeter = 0;
    area = 0;

    if(!pointPlacement(lb, rt))
    {
        pointPlacementFree(lb, rt);
        std::cout << "Initial rectangle is line or point!" << std::endl;
    }

    numberOfRects++;
    Calculations();
}

Rectangle::Rectangle(Point lb, int width, int height)
{
    perimeter = 0;
    area = 0;

    Point rt = Point(lb.x + width, lb.y + height);
    if(!pointPlacement(lb, rt))
    {
        pointPlacementFree(lb, rt);
        std::cout << "Initial rectangle is line or point!" << std::endl;
    }

    numberOfRects++;
    Calculations();
}

Rectangle::Rectangle()
{
    perimeter = 0;
    area = 0;

    leftBot = Point(0, 0);
    rightTop = Point(1, 1);

    numberOfRects++;
    Calculations();
}

Rectangle::~Rectangle()
{
    commonArea -= area;
    commonPerimeter -= perimeter;
    // deleting rectangle object deletes its area and perimeter from common values
}

bool Rectangle::isInside(int x, int y)
{
    return (x > leftBot.x && y > leftBot.y) && (x < rightTop.x && y < rightTop.y);
}

void Rectangle::changeGeometry()
{

    // a lot of checks for valid input
    char mode, set;
    bool check = true;
    while(check)
    {
        std::cout << "What do you want to change?" << std::endl <<
                     "Sides(input s) or point positions(input p): ";
        std::cin >> mode;

        // switch case asking for what change does user want
        // you can call the task of method by name ;)

        switch (mode)
        {
        // upper and low case could be rewritten as if else, but i like switch case more in this position
        case 's':
            changeSides();
            check = false; // checks not to loop
            break;
        case 'S': //for upper case of s
            changeSides();
            check = false; // checks not to loop
            break;
        case 'p':
            changePoints();
            check = false; // checks not to loop
            break;
        case 'P': //for upper case of p
            changePoints();
            check = false; // checks not to loop
            break;

        default: // wrong mode
            std::cout << "Wrong input" << std::endl
                      << "Wanna do again? ( y / n ):";
            std::cin >> set;
            if ( set == 'y' || set == 'Y')
            {
                std::cout << "Starting again. " << std::endl;
            }
            else
            {
                std::cout << "Finishing with previous input" << std::endl;
                check = false;
            }
            break;
        }
    }

    // calculation for rectangle with changed geometry
    // here comes our commonArea -= area;
    // ;)

    Calculations();
}

void Rectangle::changeSides()
{
    int newWidth, newHeight;

    // a lot of checks for valid input
    bool check = true;
    while(check)
    {
        std::cout << "Input new width( x axis ) and new height ( y axis ): ";
        std::cin >> newWidth >> newHeight;

        // checks if width and height are valid
        if (newWidth > 0 && newHeight > 0)
        {
            width = newWidth;
            height = newHeight;
            rightTop.x = leftBot.x + newWidth;
            rightTop.y = leftBot.y + newHeight;

            std::cout << "Success! New width changed to: " << width << ", new height changed to: " << height << std::endl;

            check = false;
        }
        else
        {
            char set;
            std::cout << "Wrong input. Wanna do again ( y / n ):";
            std::cin >> set;
            if (set != 'y' || set != 'Y')
            {
                std::cout << "Finishing with previous input" << std::endl;
                check = false;
            }
        }
    }

}

void Rectangle::changePoints()
{

    // a lot of checks for valid input
    bool params = true;
    bool check = true;
    while (check)
    {
        int nlbx, nlby, nrtx, nrty;
        std::cout << "Input coordinates for first point (x then y): ";
        std::cin >> nlbx >> nlby;
        std::cout << "First point is set to coordinates (" << nlbx << "," << nlby << ")"
                  << std::endl
                  << "Input coordinates for second point (x then y): ";
        std::cin >> nrtx >> nrty;
        std::cout << "Second point is set to coordinates (" << nrtx << "," << nrty << ")"
                  << std::endl;

        //here can be little optimization deleting two ints and setting new point with each input, i know ;)

        Point newF = Point(nlbx, nlby);
        Point newS = Point(nrtx, nrty);

        // pointPlacement again checking if points are valid
        // and Rectangle doesnt become point or line
        params = pointPlacement(newF, newS);

        if(params)
        {
            check = false;
        }
        else
        {
            char set;
            std::cout << "Wrong input. Wanna do again ( y / n )?";
            std::cin >> set;
            if (set != 'y' || set != 'Y')
                check = true;
        }
    }
}

void Rectangle::Calculations()
{

    // all main calculations are in this method
    // this method is called when any changes are made
    // or with initialization of object of this class

    commonArea -= area;
    commonPerimeter -= perimeter;

    // block up to this comment is crucial for geometry changes in object

    width = rightTop.x - leftBot.x;
    height = rightTop.y - leftBot.y;

    // our points are almost every time are exactly right top and left bottom
    // thanks for pointPlacement method :)

    area = width * height;
    perimeter = 2 * (width + height);

    inscribedCircleRadius = (width <= height) ? width : height;
    // minimal side is this radius
    circumscribedCircleRadius = sqrt(width*width + height*height);
    // diagonal of rectangle is this radius

    isSquare = (width == height) ? true : false; // ;)

    // block under this comment is for common area and perimeter of all objects
    commonArea += area;
    commonPerimeter += perimeter;
}

// it returns true when points given are
bool Rectangle::pointPlacement(Point newF, Point newS)
{
    //this method is for setting left bottom and right top point to correct poitions
    //it helps if in input there are left top and right bottom

    if (newF.x > newS.x)
    {
        rightTop.x = newF.x;
        leftBot.x = newS.x;
        if (newF.y > newS.y)
        {
            rightTop.y = newF.y;
            leftBot.y = newS.y;
            return true;
        }
        else if (newF.y < newS.y)
        {
            rightTop.y = newS.y;
            leftBot.y = newF.y;
            return true;
        }
        else return false;
    }
    else if (newF.x < newS.x)
    {
        rightTop.x = newS.x;
        leftBot.x = newF.x;
        if (newF.y > newS.y)
        {
            rightTop.y = newF.y;
            leftBot.y = newS.y;
            return true;
        }
        else if (newF.y < newS.y)
        {
            rightTop.y = newS.y;
            leftBot.y = newF.y;
            return true;
        }
        else return false;
    }
    else return false;
}

void Rectangle::pointPlacementFree(Point newF, Point newS)
{
    //this method is mainly for RectangleCutter
    //it also check and sets correct positions
    //but points may lay on the boundaries

    if (newF.x >= newS.x)
    {
        rightTop.x = newF.x;
        leftBot.x = newS.x;
        if (newF.y >= newS.y)
        {
            rightTop.y = newF.y;
            leftBot.y = newS.y;
        }
        else
        {
            rightTop.y = newS.y;
            leftBot.y = newF.y;
        }
    }
    else
    {
        rightTop.x = newS.x;
        leftBot.x = newF.x;
        if (newF.y >= newS.y)
        {
            rightTop.y = newF.y;
            leftBot.y = newS.y;
        }
        else if (newF.y < newS.y)
        {
            rightTop.y = newS.y;
            leftBot.y = newF.y;
        }
    }
}
