/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This file contains functions that give information about matrices.			   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "matrix.h"

//gets the number of columns in a matrix
int get_cols(MATRIX mat)
{
	//makes sure the matrix isn't partialy or fully NULL
	if (!is_legal_matrix(mat))
		return EOF;

	return (double)sizeof(mat[0]) / sizeof(mat[0][0]);					/* returns the number of columns by deviding the size of the columns (in bytes) by the size (in bytes) of each element (every
																			element has the same size) */
}

//gets the number of rows in a matrix
int get_rows(MATRIX *mat)
{
	//makes sure the matrix isn't partialy or fully NULL
	if (!is_legal_matrix(mat))
		return EOF;

	return (double)sizeof(mat) / sizeof(mat[0]);						/* returns the number of rows by deviding the size of the row (in bytes) by the size (in bytes) of each element (every
																			element has the same size) */
}

//checks if a matrix is partialy or fully NULL
int is_legal_matrix(MATRIX mat)
{
	return (mat != NULL && mat[0] != NULL)								//if the matrix is partialy NULL returns 0 and non-zero
}
