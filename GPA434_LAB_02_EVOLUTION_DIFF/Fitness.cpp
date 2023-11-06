#include "Fitness.h"

double Fitness::identity(double value)
{
    return value;
}

double Fitness::inverse(double value)
{
    return value != 0.0 ? 1.0 / value : 0.0;
}

double Fitness::opposite(double value)
{
    return -value;
}

double Fitness::distance(double value)
{
    return  abs(value - 0);
}
