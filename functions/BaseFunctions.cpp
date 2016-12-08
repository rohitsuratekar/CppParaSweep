#include <iostream>
#include "..\headers\BaseFunctions.h"


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
std::vector<double> BaseFunctions::getRandNumbers(double total)
{
	double numberList[8];
	double sum = 0;
	double sumTemp = 0;
	std::vector<double> allNumbers;

	for (int i = 0; i < sizeof(numberList) - 1; i++) {
		numberList[i] = getRandom(1, 10);
		sum = sum + numberList[i];
	}

	//2 is needed because last element we will just minus from sum
	for (int i = 0; i < sizeof(numberList) - 2; i++) {
		double tempNum = (1 / sum)*total;
		allNumbers.push_back(tempNum);
		sumTemp = sumTemp + tempNum;
	}
	allNumbers.push_back(total - sumTemp);
	return allNumbers;
}
BaseFunctions::~BaseFunctions()
{
}
