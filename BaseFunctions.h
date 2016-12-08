#pragma once
#include <vector>

class BaseFunctions
{
public:
	BaseFunctions();
	double getRandom(double min, double max);
	double randomizeAround(double original, double range);
	double calculateError(std::vector<std::vector<double>> originalPara, std::vector<std::vector<double>> newPara);
	~BaseFunctions();
};

