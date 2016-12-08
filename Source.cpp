#define _CRT_SECURE_NO_WARNINGS //Need for compilation with VS2015
#define _SCL_SECURE_NO_WARNINGS //Need for compilation with VS2015

#include <iostream>
#include <fstream>
#include <map>
#include <boost/array.hpp>
#include "headers\Enzyme.h"
#include "headers\Lipids.h"
#include "headers\EquationSet.h"

#include <boost/numeric/odeint.hpp>



using namespace boost::numeric::odeint;
using namespace std;
Enzyme pitp, pi4k, pip5k, plc, dagk, laza, patp, cds, pis;


void getPrinted(const state_type &x, const double t)
{
	cout << t << '\t' << x[0] << '\t' << x[1] << '\t' << x[0] << endl;
}

std::map<std::string, Enzyme> getEnzymeList() {
	pitp = Enzyme("pitp");
	pi4k = Enzyme("pi4k");
	pip5k = Enzyme("pip5k");
	plc = Enzyme("plc");
	dagk = Enzyme("dagk");
	laza = Enzyme("laza");
	patp = Enzyme("patp");
	cds = Enzyme("cds");
	pis = Enzyme("pis");
	std::map<std::string, Enzyme> enzymeList;
	enzymeList["pitp"] = pitp;
	enzymeList["pi4k"] = pi4k;
	enzymeList["pip5k"] = pip5k;
	enzymeList["plc"] = plc;
	enzymeList["dagk"] = dagk;
	enzymeList["laza"] = laza;
	enzymeList["patp"] = patp;
	enzymeList["cds"] = cds;
	enzymeList["pis"] = pis;
	return enzymeList;
}


void main() {
	Lipids inputLipids = Lipids();
	inputLipids.initializeWithTotal(100);
	state_type x = { 1, 2, 3, 4, 5, 6, 7, 8};
	//integrate(lorenz, x, 0.0, 250.0, 0.1, write_lorenz);
	integrate(EquationSet(getEnzymeList()), x, 0.0, 250.0, 0.1, getPrinted);
	cin.get();
}





