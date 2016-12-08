#include <iostream>
#include "BaseFunctions.h"

BaseFunctions::BaseFunctions()
{
}

double BaseFunctions::getRandom(double min, double max)
{
	double f = (double)rand() / RAND_MAX;
	return min + f * (max - min);
}
double BaseFunctions::randomizeAround(double original, double range)
{
	double min = original - range;
	double max = original + range;
	return getRandom(min, max);
}
double BaseFunctions::calculateError(std::vector<std::vector<double>> originalPara, std::vector<std::vector<double>> newPara)
{
	double error = 0;
	return 0.0;
}
BaseFunctions::~BaseFunctions()
{
}
