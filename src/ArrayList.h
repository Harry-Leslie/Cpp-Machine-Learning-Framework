#pragma once
# include "Libraries.h"

class ArrayList {
	vector<double> arr;
public:
	ArrayList();

	ArrayList(vector<double> list);

	vector<double> getList();

	void printList();

	double mean();

	double sum();

	void subtract(double value);

	void square();

	void add(ArrayList v);

	void subtract(ArrayList v);

	void multiply(ArrayList v);
};