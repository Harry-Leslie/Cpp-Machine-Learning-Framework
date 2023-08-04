#include "MultipleLinearRegression.h"

MultipleLinearRegression::MultipleLinearRegression(m X, m y) {
    this->X = prepareMatrix(X);
    this->y = y;
}

m MultipleLinearRegression::prepareMatrix(const m& inputMatrix) {
    m newMat(inputMatrix.size(), vector<long double>(inputMatrix[0].size() + 1, 0));
    for (int i = 0; i < newMat.size(); i++) {
        for (int j = 0; j < newMat[0].size(); j++) {
            if (j == 0) {
                newMat[i][j] = 1;
            }
            else {
                newMat[i][j] = inputMatrix[i][j - 1];
            }
        }
    }
    return newMat;
}

void MultipleLinearRegression::train() {
    Matrix Y(this->y);
    Matrix X(this->X);
    Matrix X_T(this->X);
    X_T.transpose();
    X_T.multiply(X);
    X_T.inverse_matrix();

    Matrix X_C(this->X);
    X_C.transpose();
    X_C.multiply(Y);
    X_T.multiply(X_C);
    X_T.print_matrix();
}

void MultipleLinearRegression::ridgeTrain(long double alpha) {
    Matrix Y(this->y);
    Matrix X(this->X);
    Matrix X_T(this->X);
    X_T.transpose();
    X_T.multiply(X);

    Matrix ridgev = X_T.get_idenity();
    ridgev.multiple_by_constant(alpha);
    X_T.addition(ridgev);
    X_T.inverse_matrix();

    Matrix X_C(this->X);
    X_C.transpose();
    X_C.multiply(Y);
    X_T.multiply(X_C);
    X_T.print_matrix();
    coefficients = X_T.get_matrix()[0];
}

vector<long double> MultipleLinearRegression::getCoefficients() {
    return coefficients;
}