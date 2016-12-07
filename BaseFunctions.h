#pragma once
class BaseFunctions
{
public:
	BaseFunctions();
	double getRandom(double min, double max);
	double randomizeAround(double original, double range);
	double calculateError(vector<vector<double>> originalPara, vector<vector<double>> newPara);
	~BaseFunctions();
};

