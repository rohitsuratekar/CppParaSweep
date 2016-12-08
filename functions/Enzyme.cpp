#include <string> //Load before Enzyme.h

#include "..\headers\BaseFunctions.h"
#include "..\headers\Enzyme.h"


Enzyme::Enzyme(const std::string name)
{
	this->name = name;
	v0 = baseF.getRandom(0.01, 10);
	k0 = baseF.getRandom(1, 100);
	v = this->v0;
	k = this->k0;
	randK = 100;
	randV = 5;
}

Enzyme::Enzyme(const std::string name, double Vmax, double Km)
{
	this->name = name;
	v0 = Vmax;
	k0 = Km;
	v = this->v0;
	k = this->k0;
	randK = 100;
	randV = 5;
}

std::string Enzyme::getName()
{
	return this->name;
}

void Enzyme::setVmax(double value)
{
	v0 = value;
	v = value;
}

double Enzyme::getOriginalVmax()
{
	return v0;
}

void Enzyme::setKm(double value)
{
	k0 = value;
	k = value;
}

double Enzyme::getOriginalKm()
{
	return k0;
}

double Enzyme::getVmax()
{
	return v;
}

double Enzyme::getKm()
{
	return k;
}

void Enzyme::randomizeVmax()
{
	v = baseF.randomizeAround(v, randV);
}

void Enzyme::randomizeKm()
{
	k = baseF.randomizeAround(k, randK);
}

void Enzyme::setVmaxRandomRange(double range)
{
	randV = range;
}

void Enzyme::setKmRandomRange(double range)
{
	randK = range;
}

void Enzyme::reset()
{
	v = v0;
	k = k0;
	randK = 100;
	randV = 5;
}





Enzyme::~Enzyme()
{
}
