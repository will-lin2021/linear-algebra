#ifndef VECTOR_H
#define VECTOR_H

typedef struct vector {
	int size;
	double *elements;
} vec_t;

/*
Initialize vector
*/
vec_t* vec_init(vec_t*, int);

/*
Set elements of vector to inputted array
*/
vec_t* vec_set(vec_t*, int, ...);

/*
Add two vectors together and returns the sum
*/
vec_t* vec_add(vec_t*, const vec_t*);

/*
Scale vector
*/
vec_t* vec_scal_mul(vec_t*, double);

/*
Print vector
*/
void vec_print(vec_t*);

/*
Cleans up vector object
*/
vec_t* vec_clear(vec_t*);

#endif
