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

	Matrix copy() {
		Matrix m1(matrix);
		return m1;
	}

	void removedScaledVector() {
		int j = 0;
		while (j < matrix[0].size()) {
			vector<double> v1 = {};
			for (int i = 0; i < matrix.size(); i++) {
				v1.push_back(matrix[i][j]);
			}
			int a = j + 1;
			while (a < matrix[0].size()) {
				vector<double> v2 = {};
				for (int i = 0; i < matrix.size(); i++) {
					v2.push_back(matrix[i][a]);
				}

				bool parallel = true;
				double scale_factor = v1[0] / v2[0]; // Edge Case 0 if both are 0 then parallel 
				for (int k = 1; k < matrix.size(); k++) {
					if (scale_factor != v1[k] / v2[k]) {
						parallel = false;
						break;
					}
				}

				if (parallel) {
					for (int k = 0; k < matrix.size(); k++) {
						matrix[k].erase(matrix[k].begin() + a);
					}
					a--;
				}
				a++;
			}
			j++;
		}
		col = matrix[0].size();
		row = matrix.size();
	}

	bool gdDecider() { // this method decides whether to use gradient descent or not
		int zero = 0;
		for (int i = 0; i < getRows(); i++) {
			for (int j = 0; j < getCols(); j++) {
				if (matrix[i][j] == 0) {
					zero++;
				}
				else {
					zero--;
				}
			}
		}
		if (zero > 0) {
			return true;
		}

		removedScaledVector();

		Matrix transpose_matrix = copy();
		transpose_matrix.transpose();

		multiply(transpose_matrix);

		inverse();

		//make decision
	}

	void inverse() {
		m init (getCols(), vector<double>(getRows(), 0));
		Matrix identity (init);

		for (int i = 0; i < getRows(); i++) {
			(*identity.getMatrixPtr())[i][i] = (i == i) ? 1 : 0;
		}

		identity.printMatrix();


		//row swap

		//scaling

		//elimination
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

	m* getMatrixPtr() {
		return &matrix;
	}

};