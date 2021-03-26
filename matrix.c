/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This file contains functions that create and free matrices.					   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "matrix.h"

//returns a new matrix with rows*cols dimensions and initializes every element in it to 0
MATRIX create_matrix(int rows, int cols)
{
	MATRIX mat;

	//makes sure dimensions are at least 1*1
	if (rows < 1 || cols < 1)
		return NULL;
	
	//alloctates the memory needed for the matrix
	mat = malloc(rows * sizeof(double *));
	for (int i = 0; i < rows; i++) {
		mat[i] = calloc(cols * sizeof(double));							//uses 'calloc' to automatically initialize elements to 0
	}

	return mat;
}

//creates a copy of a matrix
MATRIX copy_matrix(MATRIX mat)
{
	MATRIX copy = copy_dimensions(mat);										//creates a matrix with the same dimensions as the one to copy

	//copys every element from "mat" to "copy"
	for (int i = 0; i < get_rows(mat); i++)
		for (int j = 0; j < get_cols(mat); j++)
			copy[i][j] = mat[i][j];

	return copy;
}

//creates a matrix with the same dimensions as "copyFrom"
MATRIX copy_dimensions(MATRIX copyFrom)
{
	//makes sure the matrix isn't partialy NULL
	if (!is_legal_matrix(copyFrom))
		return NULL;

	return create_matrix(get_rows(copyFrom), get_cols(copyFrom));		//creates and returns a matrix with the same dimensions as "copyFrom"
}

//free a matrix
void destroy_matrix(MATRIX mat)
{
	//makes sure matrix isn't partially freed already
	if (!is_legal_matrix(mat))
		return;

	//frees each column
	for (int i = 0; i < get_cols(mat); i++) {
		free(mat[i]);
	}
	free(mat);															//frees rows
	mat = NULL;															//for saftey only. used to make sure that checks like (mat == NULL) will work properly
}
