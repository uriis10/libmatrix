/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This file contains functions that create and free matrices.					   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h> 
#include <stdlib.h>
#include "matrix.h"

static MAT_NODE *get_info_list();
static void destroy_matrix_info(MATRIX);

//returns a new matrix with rows*cols dimensions and initializes every element in it to 0
MATRIX create_matrix(int rows, int cols)
{
	MATRIX mat;
	MAT_NODE *matInfo;

	//makes sure dimensions are at least 1*1
	if (rows < 1 || cols < 1)
		return NULL;
	
	//alloctates the memory needed for the matrix
	mat = malloc(rows * sizeof(double *));
	for (int i = 0; i < rows; i++) {
		mat[i] = calloc(cols, sizeof(double));							//uses 'calloc' to automatically initialize elements to 0
	}

	//creates a new information object for the new matrix
	matInfo = _get_matrix_info(mat);
	if (matInfo->mat != NULL) {
		matInfo->next = malloc(sizeof(MAT_NODE));
		matInfo = matInfo->next;
	}

	//stores the information itself
	matInfo->mat = mat;
	matInfo->cols = cols;
	matInfo->rows = rows;

	return mat;
}

//gets the head of the linked list of matrix information
static MAT_NODE *get_info_list()
{
	static MAT_NODE *head;												//declared "static" to allow access to it even after function terminates
	//if the head hasn't been created yet it should be created
	if (head == NULL)
		head = malloc(sizeof(MAT_NODE));

	return head;
}

//gets the object that holds the information about "mat"
MAT_NODE *_get_matrix_info(MATRIX mat)
{
	//can't use "is_legal_matrix" since "is_legal_matrix" calls this function
	if (mat == NULL)
		return NULL;
	
	//check if a list has ever been started
	MAT_NODE *head = get_info_list();
	if (head->mat == NULL)
		return head;

	//searches for the information about "mat"
	MAT_NODE *tmp;
	for (tmp = head; tmp->next != NULL; tmp = tmp->next) {
		if (tmp->mat == mat)
			return tmp;
	}

	return tmp;
}

//creates a copy of a matrix
MATRIX duplicate_matrix(MATRIX mat)
{
	//makes sure the matrix isn't partialy NULL
	if (!is_legal_matrix(mat))
		return NULL;

	MATRIX copy = copy_dimensions(mat);										//creates a matrix with the same dimensions as the one to copy
	copy_matrix(copy, mat);

	return copy;
}

//copys the values of one matrix to another one
void copy_matrix(MATRIX copyTo, MATRIX copyFrom)
{
	//makes sure the matrix isn't partialy NULL
	if (!is_legal_matrix(copyFrom) || !is_legal_matrix(copyFrom))
		return;
	//makes sure "copyTo" and "copyFrom" have the same amount of rows and columns
	if (get_rows(copyTo) != get_rows(copyFrom) || get_cols(copyTo) != get_cols(copyFrom))
		return;

	//copys every element from "mat" to "copy"
	for (int i = 0; i < get_rows(copyTo); i++)
		for (int j = 0; i < get_rows(copyTo); j++)
			copyTo[i][j] = copyFrom[i][j];
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

	destroy_matrix_info(mat);

	//frees each column
	for (int i = 0; i < get_cols(mat); i++) {
		free(mat[i]);
	}
	free(mat);															//frees rows
	mat = NULL;															//for saftey only. used to make sure that checks like (mat == NULL) will work properly
}

//destroys information about a matrix
static void destroy_matrix_info(MATRIX mat)
{
	MAT_NODE *matInfo = get_info_list();								//gets the head of the list
	MAT_NODE *tmp;
	
	/* handels the case where the head stores information about "mat". in this case the information object can't be freed because we don't want a new list to be created the next time "get_info_list"
		is called if there are more information objects */
	if (matInfo->mat == mat) {
		if (matInfo->next == NULL)
			free(matInfo);												//frees the list completely since it doesn't matter if a new list is started when theres no information to store
		else {
			//copys the second information object to the head and free it
			matInfo->rows = matInfo->next->rows;
			matInfo->cols = matInfo->next->cols;
			matInfo->mat = matInfo->next->mat;
			
			tmp = matInfo->next->next;
			free(matInfo->next);
			matInfo->next = tmp;

			return;
		}
	}

	//searches for the information about "mat"
	for (tmp = matInfo->next; tmp != NULL && tmp->mat != mat; matInfo = matInfo->next, tmp = tmp->next)
		;
	//if there is no information object for "mat" theres nothing to free
	if (tmp == NULL)
		return;

	//frees the information object about "mat" and removes it from the list
	tmp = tmp->next;
	free(matInfo->next);
	matInfo->next = tmp;
}

//prints a matrix to the standard input
void print_matrix(MATRIX mat)
{
	//makes sure matrix isn't partially freed already
	if (!is_legal_matrix(mat))
		return;

	//prints the matrix to the standard input
	for (int i = 0; i < get_rows(mat); i++) {
		for (int j = 0; j < get_cols(mat); j++)
			printf("%7.3lf ", mat[i][j]);
		printf("\n");
	}
	printf("\n");
}
