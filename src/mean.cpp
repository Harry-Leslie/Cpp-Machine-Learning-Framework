#include "vector_op.h"

float mean(float arr[]) {
	float length = sizeof(arr) / sizeof(arr[0]); // tried both sizeof(float) and this
	// return sum(arr) / length
	return length;
}