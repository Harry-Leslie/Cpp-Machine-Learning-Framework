#include "ArrayList.h"

ArrayList::ArrayList() {
	this->arr = vector<double>();
}

ArrayList::ArrayList(vector<double> list) {
	this->arr = list;
}

vector<double> ArrayList::getList() {
	return arr;
}

void ArrayList::printList() {
	for (int i = 0; i < arr.size(); i++) {
		printf("%.2f ", arr[i]);
	}
	printf("\n");
}

double ArrayList::mean() {
	if (arr.size() <= 0) {
		return 0;
	}

	double sum = 0;
	for (auto i : arr) {
		sum += i;
	}
	return sum / arr.size();
}

double ArrayList::sum() {
	double total = 0;
	for (auto i : arr) {
		total += i;
	}
	return total;
}

void ArrayList::subtract(double value) {
	for (int i = 0; i < arr.size(); i++) {
		arr[i] -= value;
	}
}

void ArrayList::square() {
	for (int i = 0; i < arr.size(); i++) {
		arr[i] *= arr[i];
	}
}

void ArrayList::add(ArrayList v) {

	for (int i = 0; i < arr.size(); i++) {
		arr[i] += v.getList()[i];
	}
}

void ArrayList::subtract(ArrayList v) {
	for (int i = 0; i < arr.size(); i++) {
		arr[i] -= v.getList()[i];
	}
}

void ArrayList::multiply(ArrayList v) {
	for (int i = 0; i < arr.size(); i++) {
		arr[i] *= v.getList()[i];
	}
}