#include "..\headers\Enzyme.h"
#include "..\headers\Lipids.h"
#include <boost/array.hpp>
#include <map>
#include "..\headers\EquationSet.h"





double c(double substrate, Enzyme enzyme) {
	return (substrate*enzyme.getVmax()) / (substrate + enzyme.getKm());
}

EquationSet::EquationSet(std::map<std::string, Enzyme>& enzymeList)
{
	pitp = enzymeList["pitp"];
	pi4k = enzymeList["pi4p"];
	pip5k = enzymeList["pip5k"];
	plc = enzymeList["plc"];
	dagk = enzymeList["dagk"];
	laza = enzymeList["laza"];
	patp = enzymeList["patp"];
	cds = enzymeList["cds"];
	pis = enzymeList["pis"];
}

/*
void getFF(const Lipids &x, Lipids &u, double t)
{
	u.pmpi = c(x.erpi, pitp) - c(x.pmpi, pi4k);
	u.pi4p = c(x.pmpi, pi4k) - c(x.pi4p, pip5k);
	u.pip2= c(x.pi4p, pip5k) - c(x.pip2, plc);
	u.dag = c(x.pip2, plc) - c(x.dag, dagk) + c(x.pmpa, laza);
	u.pmpa = c(x.dag, dagk) - c(x.pmpa, laza) - c(x.pmpa, patp);
	u.erpa = c(x.pmpa, patp) - c(x.erpa, cds);
	u.cdpdag = c(x.erpa, cds) - c(x.cdpdag, pis);
	u.erpi = c(x.cdpdag, pis) - c(x.erpi, pitp);
}
*/

void EquationSet::operator()(const state_type & x, state_type & u, double t)
{
	double pmpi, pi4p, pip2, dag, pmpa, erpa, cdpdag, erpi;
	pmpi = x[0];
	pi4p = x[1];
	pip2 = x[2];
	dag = x[3];
	pmpa = x[4];
	erpa = x[5];
	cdpdag = x[6];
	erpi = x[7];

	u[0] = c(erpi, pitp) - c(pmpi, pi4k);
	u[1] = c(pmpi, pi4k) - c(pi4p, pip5k);
	u[2] = c(pi4p, pip5k) - c(pip2, plc);
	u[3] = c(pip2, plc) - c(dag, dagk) + c(pmpa, laza);
	u[4] = c(dag, dagk) - c(pmpa, laza) - c(pmpa, patp);
	u[5] = c(pmpa, patp) - c(erpa, cds);
	u[6] = c(erpa, cds) - c(cdpdag, pis);
	u[7] = c(cdpdag, pis) - c(erpi, pitp);
}





EquationSet::~EquationSet()
{
}
