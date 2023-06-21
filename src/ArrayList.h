#pragma once
# include "libraries.h"

class ArrayList {
	vector<double> arr;
public:
	ArrayList() {
		this->arr = vector<double>();
	}

	ArrayList(vector<double> list) {
		this->arr = list;
	}

	vector<double> getList() {
		return arr;
	}

	void printList() {
		for (int i = 0; i < arr.size(); i++) {
			printf("%.2f ", arr[i]);
		}
		printf("\n");
	}

	double mean() {
		if (arr.size() <= 0) {
			return 0;
		}

		double sum = 0;
		for (auto i : arr) {
			sum += i;
		}
		return sum / arr.size();
	}

	double sum() {
		double total = 0;
		for (auto i : arr) {
			total += i;
		}
		return total;
	}

	void subtract(double value) {
		for (int i = 0; i < arr.size(); i++) {
			arr[i] -= value;
		}
	}

	//squaring
	void square() {
		for (int i = 0; i < arr.size(); i++) {
			arr[i] *= arr[i];
		}
	}

	//adding
	void add(ArrayList v) {

		for (int i = 0; i < arr.size(); i++) {
			arr[i] += v.getList()[i];
		}
	}

	//taking away
	void subtract(ArrayList v) {
		for (int i = 0; i < arr.size(); i++) {
			arr[i] -= v.getList()[i];
		}
	}

	void multiply(ArrayList v) {
		for (int i = 0; i < arr.size(); i++) {
			arr[i] *= v.getList()[i];
		}
	}
};