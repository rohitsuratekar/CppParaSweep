#pragma once
#include <string> //Load before Enzyme.h

class Enzyme
{
private:
	std::string name;
	double v0, k0, v, k;
	double randV, randK;

public:
	Enzyme();
	Enzyme(const  std::string name);
	Enzyme(const std::string name, double Vmax, double Km);
	std::string getName();
	void setVmax(double value);
	double getOriginalVmax();
	void setKm(double value);
	double getOriginalKm();
	double getVmax();
	double getKm();
	void randomizeVmax();
	void randomizeKm();
	void setVmaxRandomRange(double range);
	void setKmRandomRange(double range);
	void reset();
	~Enzyme();
};

