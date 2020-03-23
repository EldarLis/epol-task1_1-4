#include "circumscribedcircle.h"


CircumscribedCircle::CircumscribedCircle(Rectangle *rect)
{
    this->circumscribedCircleRadius = rect->circumscribedCircleRadius;
}

double CircumscribedCircle::getRadius()
{
    return circumscribedCircleRadius;
}


