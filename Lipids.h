#pragma once
class Lipids
{
private:
	double r_pip2, r_pi4p, r_dag, r_pa, r_cdpdag;
	BaseFunctions baseF;
public:
	double pmpi, pi4p, pip2, dag, pmpa, erpa, cdpdag, erpi;
	double wgt_pip2, wgt_pi4p, wgt_pa, wgt_dag, wgt_cdpdag;
	Lipids();
	Lipids(double total);
	~Lipids();
	void initializeWithTotal(double totalLipids);
	void initiateRandomly(double totalLipid);
	double getAll();
	double getRatioPA();
	double getRatioPIP2();
	double getRatioPI4P();
	double getRatioDAG();
	double getRatioCDPDAG();
	double getFractionalError();
	double getErrorPIP2();
	double getErrorPI4P();
	double getErrorDAG();
	double getErrorPA();
	double getErrorCDPDAG();
	void resetWeights();
};

