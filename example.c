/*
 * an example file to show how the library can be used
 */

#include "matrix.h"
#include <stdio.h>

int main()
{
	MATRIX a = create_matrix(3, 2);
	MATRIX b = create_matrix(2, 2);
	MATRIX c;
	MATRIX d = create_matrix(3, 2);
	MATRIX tmp;

	for (int i = 0; i < get_rows(b); i++)
		for (int j = 0; j < get_cols(b); j++)
			b[i][j] = i + j;
	printf("matrix b:\n");
	print_matrix(b);

	scale_to_matrix(b, 10);
	printf("b * 10:\n");
	print_matrix(b);

	for (int i = 0; i < get_rows(a); i++)
		for (int j = 0; j < get_cols(a); j++)
			a[i][j] = 1;
	printf("matrix a:\n");
	print_matrix(a);

	for (int i = 0; i < get_rows(d); i++)
		for (int j = 0; j < get_cols(d); j++)
			d[i][j] = (i + j) * i + j;
	printf("matrix d:\n");
	print_matrix(d);
	
	sub_to_matrix(d, a);
	printf("d - a:\n");
	print_matrix(d);

	add_to_matrix(d, a);
	printf("d + a:\n");
	print_matrix(d);
	
	c = mul_matrix(a, b);
	printf("a * b:\n");
	print_matrix(c);

	tmp = transpose_matrix(c);
	destroy_matrix(c);
	c = tmp;
	printf("c transposed:\n");
	print_matrix(c);

	destroy_matrix(a);
	destroy_matrix(b);
	destroy_matrix(c);
	destroy_matrix(d);
	
	return 0;
}
