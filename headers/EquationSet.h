#pragma once
#include <boost/array.hpp>
typedef boost::array< double, 8 > state_type;

class EquationSet
{
	private:
	Enzyme pitp, pi4k, pip5k, plc, dagk, laza, patp, cds, pis;
	public:
	EquationSet(std::map<std::string, Enzyme> & enzymeList);
	void operator()(const state_type & x, state_type & u, double t);
	~EquationSet();
};

