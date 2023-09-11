#pragma once
#include "Matrix.h"

class MultipleLinearRegression{
	m X;
	m y;
	vector<long double> coefficients;
public:
	MultipleLinearRegression(m X, m y);

	void train();

	vector<long double> getCoefficients();

	m prepareMatrix(const m& inputMatrix);

	void ridgeTrain(long double alpha);
};