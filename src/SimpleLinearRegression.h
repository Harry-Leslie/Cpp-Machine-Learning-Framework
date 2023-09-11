#pragma once
#include "Libraries.h"
#include "ArrayList.h"

class SimpleLinearRegression {
	ArrayList x;
	ArrayList y;
	double b0;
	double b1;
public:
	SimpleLinearRegression(ArrayList x, ArrayList y);

	void train();

	void b1_calc();

	void b0_calc();

	double getb1();

	double getb0();

};