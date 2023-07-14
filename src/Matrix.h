#pragma once
# include "libraries.h"

typedef vector<vector<long double>> m;
/* Matrix Wrapper Class Interface
*  This class is needed for doing matrix opperations
*/

class Matrix {
	m matrix;
	int row;
	int col;
public:
	Matrix(m matrix);

	void multiply(Matrix v);

	void addition(Matrix v);

	void subtract(Matrix v);

	void print_matrix();

	void transpose();

	Matrix copy();

	void removed_scaled_vector();

	void inverse_matrix();

	int get_rows();

	int get_cols();

	m get_matrix();

	void multiple_by_constant(long double v);

	Matrix get_idenity();
};