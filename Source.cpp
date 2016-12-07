#define _CRT_SECURE_NO_WARNINGS //Need for compilation with VS2015
#include <iostream>
#include <fstream>
#include <vector>
#include <boost/numeric/odeint.hpp>
#include "BaseFunctions.h"
#include "Enzyme.h"
using namespace std;
using namespace boost::numeric::odeint;

/* we solve the simple ODE x' = 3/(2t^2) + x/(2t)
* with initial condition x(1) = 0.
* Analytic solution is x(t) = sqrt(t) - 1/t
*/

BaseFunctions baseFun;
vector<vector<double>> vec;

void rhs(const double x, double &dxdt, const double t)
{
	dxdt = 3.0 / (2.0*t*t) + x / (2.0*t);
}



void write_cout(const double &x, const double t)
{
	
//	cout << t << '\t' << x << endl;
	vector<double> k;
	k.push_back(t);
	k.push_back(baseFun.getRandom(10,20));
	vec.push_back(k);

}

// state_type = double
typedef runge_kutta_dopri5< double > stepper_type;




int trySave()
{
	double x = 0.0;
	integrate_adaptive(make_controlled(1E-12, 1E-12, stepper_type()),
		rhs, x, 1.0, 10.0, 0.1, write_cout);
	
	ofstream myfile;
	myfile.open("example.txt");
	vector<vector<double>> ::iterator v = vec.begin();
	while (v != vec.end()) {
		vector<double> m = *v;
		cout << "value of v = " << m[0] << endl;
		myfile << m[0] << "\t" << m[1] << endl;
		v++;
	}
	myfile.close();
	cin.get(); //Need this to stop output window with VS2015
	return 0;
}

int main()
{

	Enzyme pitp = Enzyme("pitp");
	pitp.setVmax(20.00);
	pitp.setKm(23);
	Enzyme dagk = Enzyme("dagk");
	
	return 0;
}