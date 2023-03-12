#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

int main(int argc, char const *argv[]) {
	vec_t vector;
	// double test[] = {4.0, 3.0, 2.0};

	vec_init(&vector, 3);

	vec_print(&vector);

	return 0;
}
