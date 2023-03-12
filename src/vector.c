#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "vector.h"

vec_t* vec_init(vec_t* vector, int size) {
	vector->size = size;
	vector->elements = malloc(size*sizeof(double));

	double *elements = vector->elements;
	for (int e = 0; e < size; e++) {
		elements[e] = 0;
	}

	return vector;
}

vec_t* vec_set(vec_t* vector, int num, ...) {
	int size;
	va_list valist;

	size = vector->size;
	if (num > size) {
		return NULL;
	}

	va_start(valist, num);

	for (int e = 0; e < num; e++) {
		vector->elements[e] = va_arg(valist, int);;
	}

	return vector;
}

vec_t* vec_add(vec_t* vector, const vec_t* o_vec) {
	return vector;
}

vec_t* vec_scal_mul(vec_t* vector, double scale) {
	return vector;
}

void vec_print(vec_t* vector) {
	int size;
	double* elements;

	size = vector->size;
	elements = vector->elements;

	for (int e = 0; e < size; e++) {
		if (e == 0)
			printf("[");
		printf("%f", elements[e]);
		if (e == size-1)
			printf("]\n");
		else
			printf(" ");
	}
}