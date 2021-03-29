/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This file contains functions that give information about matrices.			   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

//gets the number of columns in a matrix
int get_cols(MATRIX mat)
{
	//makes sure the matrix isn't partialy or fully NULL
	if (!is_legal_matrix(mat))
		return EOF;

	//gets and return the wanted information from the information object about "mat"
	MAT_NODE *matInfo = _get_matrix_info(mat);
	return matInfo->cols;
}

//gets the number of rows in a matrix
int get_rows(MATRIX mat)
{
	//makes sure the matrix isn't partialy or fully NULL
	if (!is_legal_matrix(mat))
		return EOF;

	//gets and return the wanted information from the information object about "mat"
	MAT_NODE *matInfo = _get_matrix_info(mat);
	return matInfo->rows;
}

//checks if a matrix is partialy or fully NULL
int is_legal_matrix(MATRIX mat)
{
	int status = (mat != NULL && mat[0] != NULL);								//if the matrix is partialy NULL returns 0 and non-zero
	//a legal  matrix has an information object about it
	if (mat != (_get_matrix_info(mat))->mat)
		status = 0;

	return status;
}
