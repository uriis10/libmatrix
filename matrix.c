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
