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

	result = copy_dimensions(a);											//creates the result matrix
	add_to_matrix(result, a);												//adds "a" to the result array
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
			a[i][j] += b[i][j];	
}
