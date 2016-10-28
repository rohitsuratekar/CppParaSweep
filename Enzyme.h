#ifndef ENZYME_H
#define ENZYME_H

class Enzyme
{
private:
	double v;

public:
	char name;
	double v, k, min_v, max_v, min_k, max_k;
	double v_random, k_random, v_original, k_original;
	void next_v() { return v; };
};
#endif