#pragma once
#include "Matrix.h"

class multiple_linear_regressor{
private:
	m X;
	m y;
public:
	multiple_linear_regressor(m X, m y);
	void train();
	vector<int> getCoefficients();
	void ridge_train(long double alpha);
};
