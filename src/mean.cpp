#include "vector_op.h"

double mean(std::vector<double> arr) {
	// divide by 0 is undefined
	if (arr.size() <= 0) { 
		return 0;
	}
	
	double sum = 0;
	for (auto i : arr) {
		sum += i;
	}
	return sum / arr.size();
}