#include "Lipids.h"
#include <iostream>
#include <vector>
#include "BaseFunctions.h"


Lipids::Lipids()
{
	r_pip2 = 0.05;
	r_pi4p = 0.05;
	r_dag = 0.008;
	r_cdpdag = 0.001;
	r_pa = 0.167;
	wgt_pip2 = 1;
	wgt_cdpdag = 0.5;
	wgt_dag = 1;
	wgt_pi4p = 1;
	wgt_pa = 1;
}

Lipids::Lipids(double total)
{
	initializeWithTotal(total);
}


Lipids::~Lipids()
{
}

void Lipids::initializeWithTotal(double totalLipids)
{
	BaseFunctions baseF;
	double totalDistribtion = r_pip2 + r_pi4p + r_dag + r_cdpdag + r_pa + 1;
	pip2 = (r_pip2 / totalDistribtion)*totalLipids;
	dag = (r_dag / totalDistribtion)*totalLipids;
	pi4p = (r_pi4p / totalDistribtion)*totalLipids;
	cdpdag = (r_cdpdag / totalDistribtion)*totalLipids;
	double totalPA = (r_pa / totalDistribtion)*totalLipids;
	double totalPI = (1 / totalDistribtion)*totalLipids;
	pmpi = baseF.getRandom(0.0, totalPI);
	erpi = totalPI - pmpi;
	pmpa = baseF.getRandom(0.0, totalPA);
	erpa = totalPA - pmpa;

}

//TODO  
void Lipids::initiateRandomly(double totalLipid)
{
	BaseFunctions baseF;
	std::vector<double> allConcentrations = baseF.getRandNumbers(totalLipid);
	pmpi = allConcentrations[0];
	pi4p = allConcentrations[1];
	pip2 = allConcentrations[2];
	dag = allConcentrations[3];
	pmpa = allConcentrations[4];
	erpa = allConcentrations[5];
	cdpdag = allConcentrations[6];
	erpi = allConcentrations[7];
}


double Lipids::getAll()
{
	return pmpi + pi4p + pip2 + dag + pmpa + erpa + cdpdag + erpi;
}

double Lipids::getRatioPA()
{
	return (pmpa + erpa)/(pmpi + erpi);
}

double Lipids::getRatioPIP2()
{
	return pip2/(pmpi+erpi);
}

double Lipids::getRatioPI4P()
{
	return pi4p/(pmpi + erpi);
}

double Lipids::getRatioDAG()
{
	return dag/(pmpi+erpi);
}

double Lipids::getRatioCDPDAG()
{
	return cdpdag/(pmpi + erpi);
}

double Lipids::getErrorPIP2()
{
	return abs((getRatioPIP2() - r_pip2) / r_pip2)*wgt_pip2;
}

double Lipids::getErrorPI4P()
{
	return abs((getRatioPI4P() - r_pi4p) / r_pi4p)*wgt_pi4p;
}

double Lipids::getErrorDAG()
{
	return abs((getRatioDAG() - r_dag) / r_dag)*wgt_dag;
}

double Lipids::getErrorPA()
{
	return abs((getRatioPA() - r_pa) / r_pa)*wgt_pa;
}

double Lipids::getErrorCDPDAG()
{
	return abs((getRatioCDPDAG() - r_cdpdag) / r_cdpdag)*wgt_cdpdag;
}

void Lipids::resetWeights()
{
	wgt_pip2 = 1;
	wgt_cdpdag = 0.5;
	wgt_dag = 1;
	wgt_pi4p = 1;
	wgt_pa = 1;
}

double Lipids::getFractionalError()
{
	return getErrorPIP2() + getErrorPI4P() + getErrorDAG() + getErrorCDPDAG() + getErrorPA();
}