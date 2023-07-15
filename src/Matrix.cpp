#include "Matrix.h"

Matrix::Matrix(m matrix) {
	this->matrix = matrix;
	this->row = matrix.size();
	this->col = matrix[0].size();
}

void Matrix::multiply(Matrix v) {
	if (this->col != v.get_rows()) {
		throw "Matrices have incorrect dimensions";
		return;
	}
	m new_matrix(get_rows(), vector<long double>(v.get_cols(), 0));
	for (int i = 0; i < get_rows(); i++) {
		for (int j = 0; j < v.get_cols(); j++) {
			double sum = 0;
			for (int k = 0; k < v.get_rows(); k++) {
				sum += matrix[i][k] * v.get_matrix()[k][j];
			}
			new_matrix[i][j] = sum;
		}
	}
	matrix = new_matrix;
	col = v.get_cols();
}

void Matrix::addition(Matrix v) {
	if ((this->col == v.get_cols()) && (this->row == v.get_rows())) {
		for (int i = 0; i < get_rows(); i++) {
			for (int j = 0; j < get_cols(); j++)
				matrix[i][j] += v.get_matrix()[i][j];
		}
	}
	else {
		throw "Matrices have incorrect dimensions";
	}
}

void Matrix::subtract(Matrix v) {
	if ((this->col == v.get_cols()) && (this->row == v.get_rows())) {
		for (int i = 0; i < get_rows(); i++) {
			for (int j = 0; j < get_cols(); j++)
				matrix[i][j] -= v.get_matrix()[i][j];
		}
	}
	else {
		throw "Matrices have incorrect dimensions";
	}
}


void Matrix::print_matrix() {
	for (int i = 0; i < get_rows(); i++) {
		for (int j = 0; j < get_cols(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void Matrix::transpose() {
	m transposed(get_cols(), vector<long double>(get_rows()));
	for (int j = 0; j < get_cols(); j++) {
		for (int i = 0; i < get_rows(); i++) {
			transposed[j][i] = matrix[i][j];
		}
	}
	col = transposed[0].size();
	row = transposed.size();
	matrix = transposed;
}

Matrix Matrix::copy() {
	Matrix m1(matrix);
	return m1;

}

void Matrix::removed_scaled_vector() {
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

void rowOperations(m& mat, int i, int j, int n) {
	double pivot = mat[i][j];
	for (int k = 0; k < 2 * n; ++k)
		mat[i][k] /= pivot;

	for (int row = 0; row < n; ++row) {
		if (row != i) {
			double factor = mat[row][j];
			for (int col = 0; col < 2 * n; ++col)
				mat[row][col] -= factor * mat[i][col];
		}
	}
}

void Matrix::inverse_matrix() {
	int n = this->matrix.size();
	m aug_matrix (n, std::vector<long double>(2 * n, 0));

	// Augment the original matrix with an identity matrix
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			aug_matrix[i][j] = matrix[i][j];
		aug_matrix[i][i + n] = 1;
	}


	// Augment the original matrix with an identity matrix
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			aug_matrix[i][j] = matrix[i][j];
		aug_matrix[i][i + n] = 1;
	}
	for (int i = 0; i < n; ++i) {
		if (aug_matrix[i][i] == 0) {
			// If the pivot is zero, swap rows to get a non-zero pivot
			bool found = false;
			for (int j = i + 1; j < n; ++j) {
				if (aug_matrix[j][i] != 0) {
					std::swap(aug_matrix[i], aug_matrix[j]);
					found = true;
					break;
				}
			}
			if (!found) {
				throw "Inverible";
			}
		}

		rowOperations(aug_matrix, i, i, n);
	}

	m inverse(n, std::vector<long double>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			inverse[i][j] = aug_matrix[i][j + n];
	}
	matrix = inverse;
	return;
}

int Matrix::get_rows() {
	return row;
}

int Matrix::get_cols() {
	return col;
}

m Matrix::get_matrix() {
	return matrix;
}

Matrix Matrix::get_idenity() {
	if (Matrix::get_rows() == Matrix::get_cols()) {
		m id(Matrix::get_rows(), vector<long double>(Matrix::get_cols(), 0));
		for (int i = 0; i < Matrix::get_rows(); i++) {
			id[i][i] = 1;
 		}
		return Matrix(id);
	}
	throw "Not Square Matrix";
}

void Matrix::multiple_by_constant(long double v) {
	for (int i = 0; i < Matrix::get_rows(); i++) {
		for (int j = 0; j < Matrix::get_cols(); j++) {
			matrix[i][j] *= v;
		}
	}
}


