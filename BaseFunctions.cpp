#include "BaseFunctions.h"
#include <iostream>


BaseFunctions::BaseFunctions()
{
}

double BaseFunctions::getRandom(double min, double max)
{
	double f = (double)rand() / RAND_MAX;
	return min + f * (max - min);
}
BaseFunctions::~BaseFunctions()
{
}
