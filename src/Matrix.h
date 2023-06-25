#pragma once
# include "libraries.h"

typedef vector<vector<double>> m;


class Matrix {
	m matrix;
	int row;
	int col;
public:
	Matrix(m matrix) {
		this->matrix=matrix;
		this->row = matrix.size();
		this->col = matrix[0].size();
	}

	void multiply(Matrix v) {

		if (this->col != v.getRows()) {
			throw "Matrices have incorrect dimensions";
			return;
		}
		m new_matrix(getRows(), vector<double>(v.getCols(), 0));
		for (int i = 0; i < getRows(); i++) {
			for (int j = 0; j < v.getCols(); j++) {
				double sum = 0;
				for (int k = 0; k < v.getRows(); k++) {
					sum += matrix[i][k] * v.getMatrix()[k][j];
				}
				new_matrix[i][j] = sum;
			}
		}
		matrix = new_matrix;
		col = v.getCols();
	}

	void addition(Matrix v) {
		if ((this->col == v.getCols()) && (this->row == v.getRows())){
			for (int i = 0; i < getRows(); i++) {
				for (int j = 0; j < getCols(); j++)
					matrix[i][j] += v.getMatrix()[i][j];
			}
		}
		throw "Matrices have incorrect dimensions";		
	}

	void subtract(Matrix v) {
		if ((this->col == v.getCols()) && (this->row == v.getRows())) {
			for (int i = 0; i < getRows(); i++) {
				for (int j = 0; j < getCols(); j++)
					matrix[i][j] -= v.getMatrix()[i][j];
			}
		}
		throw "Matrices have incorrect dimensions";
	}


	void printMatrix() {
		for (int i = 0; i < getRows(); i++) {
			for (int j = 0; j < getCols(); j++) {
				cout << matrix[i][j] <<  " ";
			}
			cout << endl;
		}
	}

	void transpose() {
		m transposed(getCols(), vector<double>(getRows()));
		for (int j = 0; j < getCols(); j++) {
			for (int i = 0; i < getRows(); i++) {
				transposed[j][i]=matrix[i][j];
			}
		}
		col = transposed[0].size();
		row = transposed.size();
		matrix = transposed;
	}


	int getRows() {
		return row;
	}

	int getCols() {
		return col;
	}

	m getMatrix() {
		return matrix;
	}

};