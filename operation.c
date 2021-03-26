/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This file contains mathamatical matrix operations.							   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdlib.h>
#include "matrix.h"

//adds two matrices and returns the resulting matrix
MATRIX add_matrix(MATRIX a, MATRIX b)
{
	MATRIX result;

	//makes sure the matrices aren't partialy NULL
	if (!is_legal_matrix(a) || !is_legal_matrix(b))
		return NULL;
	//makes sure the matrices have the same dimensions
	if (get_rows(a) != get_rows(b) || get_cols(a) != get_cols(b))
		return NULL;

	result = duplicate_matrix(a);												//creates the result matrix
	add_to_matrix(result, b);												//adds "b" to the result array

	return result;
}

//adds two matrices and stores the resulting matrix in the first one
void add_to_matrix(MATRIX addTo, MATRIX addFrom)
{
	//makes sure the matrices aren't partialy NULL
	if (!is_legal_matrix(addTo) || !is_legal_matrix(addFrom))
		return;
	//makes sure the matrices have the same dimensions
	if (get_rows(addTo) != get_rows(addFrom) || get_cols(addTo) != get_cols(addFrom))
		return;

	//loops over the rows and colums of the matrices and adds "b" to "a"
	for (int i = 0; i < get_rows(addTo); i++)
		for (int j = 0; j < get_cols(addTo); j++)
			addTo[i][j] += addFrom[i][j];	
}

//multiplies a matrix by a scalar and returns the resulting matrix
MATRIX scale_matrix(MATRIX mat, double scalar)
{
	MATRIX result;

	//makes sure the matrices aren't partialy NULL
	if (!is_legal_matrix(mat))
		return NULL;

	result = duplicate_matrix(mat);												//creates the result matrix
	scale_to_matrix(result, scalar);										//multiplies the matrix by a scalar

	return result;
}

//multiplies a matrix by a scalar and stores the result in the original matrix
void scale_to_matrix(MATRIX mat, double scalar)
{
	//makes sure the matrices aren't partialy NULL
	if (!is_legal_matrix(mat))
		return;

	//loops over the rows and colums of the matrix and multiplys every element by the scalar
	for (int i = 0; i < get_rows(mat); i++)
		for (int j = 0; j < get_cols(mat); j++)
			mat[i][j] *= scalar;
}

//subtracts two matrices and returns the resulting matrix
MATRIX sub_matrix(MATRIX a, MATRIX b)
{
	MATRIX result;

	//makes sure the matrices aren't partialy NULL
	if (!is_legal_matrix(a) || !is_legal_matrix(b))
		return NULL;
	//makes sure the matrices have the same dimensions
	if (get_rows(a) != get_rows(b) || get_cols(a) != get_cols(b))
		return NULL;

	//subtracts the matrices by using [-b + a] which is the same as [a - b]
	result = duplicate_matrix(b);												//creates the result matrix
	scale_to_matrix(result, -1);											//subtracts "b"
	add_to_matrix(result, a);												//adds "a" to the result array

	return result;
}

//subtracts two matrices and stores the resulting matrix in the first one
void sub_to_matrix(MATRIX a, MATRIX b)
{
	//makes sure the matrices aren't partialy NULL
	if (!is_legal_matrix(a) || !is_legal_matrix(b))
		return;
	//makes sure the matrices have the same dimensions
	if (get_rows(a) != get_rows(b) || get_cols(a) != get_cols(b))
		return;

	//loops over the rows and colums of the matrices and subtracts "b" from "a"
	for (int i = 0; i < get_rows(a); i++)
		for (int j = 0; j < get_cols(a); j++)
			a[i][j] -= b[i][j];	
}

//multiplies two matrices and returns the resulting matrix
MATRIX mul_matrix(MATRIX a, MATRIX b)
{
	MATRIX result;

	//makes sure the matrices aren't partialy NULL
	if (!is_legal_matrix(a) || !is_legal_matrix(b))
		return NULL;
	//makes sure the matrices have dimensions that the matrix product is defined for
	if (get_cols(a) != get_rows(b))
		return NULL;

	result = create_matrix(get_rows(a), get_cols(b));
	//loops over the rows of the "a" and multiplies them with the columns of "b"
	for (int i = 0; i < get_rows(a); i++)
		for (int j = 0; j < get_cols(b); j++)
			for (int w = 0; w < get_cols(a); w++)
				result[i][j] += a[i][w] * b[w][j];
			
	return result;
}

//creates a new matrix which is a transposition of the matrix passed as a parameter
MATRIX transpose_matrix(MATRIX mat)
{
	//makes sure the matrix isn't partialy NULL
	if (!is_legal_matrix(mat))
		return NULL;

	MATRIX result = create_matrix(get_cols(mat), get_rows(mat));			//creates the result matrix

	//copys the values of "mat" to "result" but switches the rows and columns
	for (int i = 0; i < get_cols(mat); i++)
		for (int j = 0; j < get_rows(mat); j++)
			result[j][i] = mat[i][j];

	return result;
}
