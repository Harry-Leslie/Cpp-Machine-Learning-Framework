#pragma once
# include "libraries.h"
# include "ArrayList.h"

class SimpleLinearRegression {
	ArrayList x;
	ArrayList y;
	double b0;
	double b1;

	public:
		SimpleLinearRegression(ArrayList x, ArrayList y) {
			this->x = x;
			this->y = y;
		}

		void train() {
			b1_calc();
			b0_calc();
			printf("Gradient : %f\n", getb1());
			printf("y-intercept : %f\n", getb0());
		}

		void b1_calc(){
			ArrayList dummy_x = x;
			ArrayList dummy_y = y;

			dummy_x.subtract(dummy_x.mean());
			dummy_y.subtract(dummy_y.mean());
			dummy_x.multiply(dummy_y);
			double top = dummy_x.sum();

			dummy_x = x;

			dummy_x.subtract(dummy_x.mean());
			dummy_x.square();
			double bottom = dummy_x.sum();

			
			this->b1= top/bottom;
		}

		void b0_calc(){
			this->b0 = y.mean() - (b1*x.mean());
		}

		double getb1() {
			return b1;
		}

		double getb0() {
			return b0;
		}

		

};