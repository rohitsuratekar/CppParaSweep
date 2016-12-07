#include <vector>
#include <iostream>
#include "BaseFunctions.h"

using namespace std;

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
double BaseFunctions::calculateError(vector<vector<double>> originalPara, vector<vector<double>> newPara)
{
	double error = 0;
	return 0.0;
}
BaseFunctions::~BaseFunctions()
{
}
