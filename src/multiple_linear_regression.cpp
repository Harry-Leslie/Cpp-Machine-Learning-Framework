#include "multiple_linear_regression.h"
multiple_linear_regressor::multiple_linear_regressor(m X, m y) {
	this->X = X;
	this->y = y;
}
void multiple_linear_regressor::train() {
	Matrix Y(this->y);
	m newMat(X.size(), vector<long double>(X[0].size()+1, 0));
	for (int i = 0; i < newMat.size(); i++) {
		for (int j = 0; j < newMat[0].size(); j++) {
			if (j == 0) {
				newMat[i][j] = 1;
			}
			else {
				newMat[i][j] = X[i][j - 1];
			}
		}
	}
	this->X = newMat;
	Matrix X(this->X);
	Matrix X_C(this->X);

	Matrix X_T(this->X);
	// (X'X)-1X'y
	X_T.transpose();
	X_T.multiply(X);
	X_T.inverse_matrix();


	X_C.transpose();
	X_C.multiply(Y);
	X_T.multiply(X_C);
	X_T.print_matrix();
	
}

void multiple_linear_regressor::ridge_train(long double alpha) {
	Matrix Y(this->y);
	m newMat(X.size(), vector<long double>(X[0].size() + 1, 0));
	for (int i = 0; i < newMat.size(); i++) {
		for (int j = 0; j < newMat[0].size(); j++) {
			if (j == 0) {
				newMat[i][j] = 1;
			}
			else {
				newMat[i][j] = X[i][j - 1];
			}
		}
	}
	this->X = newMat;
	Matrix X(this->X);
	Matrix X_C(this->X);

	Matrix X_T(this->X);
	// (X'X)-1X'y
	X_T.transpose();
	X_T.multiply(X);

	Matrix ridgev = X_T.get_idenity();
	ridgev.multiple_by_constant(alpha);
	X_T.addition(ridgev);

	X_T.inverse_matrix();

	X_C.transpose();
	X_C.multiply(Y);
	X_T.multiply(X_C);
	X_T.print_matrix();
}
vector<int> multiple_linear_regressor::getCoefficients() {
	return vector<int>();
}