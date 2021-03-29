typedef double ** MATRIX;

//the information object stored for every matrix
typedef struct mat_info {
	MATRIX mat;												//the matrix
	int rows;												//the number of rows the matrix has
	int cols;												//the number of columns the matrix has
	struct mat_info *next;									//the next matrix in the linked list of matrix information objects
} MAT_NODE;

MATRIX create_matrix(int, int);
MATRIX duplicate_matrix(MATRIX mat);
void copy_matrix(MATRIX, MATRIX);
MATRIX copy_dimensions(MATRIX);
void destroy_matrix(MATRIX);

int get_cols(MATRIX);
int get_rows(MATRIX);
int is_legal_matrix(MATRIX);
void print_matrix(MATRIX);

void add_to_matrix(MATRIX, MATRIX);
MATRIX add_matrix(MATRIX, MATRIX);
MATRIX scale_matrix(MATRIX, double);
void scale_to_matrix(MATRIX, double);
MATRIX sub_matrix(MATRIX, MATRIX);
void sub_to_matrix(MATRIX, MATRIX);
MATRIX mul_matrix(MATRIX, MATRIX);
MATRIX transpose_matrix(MATRIX);

MAT_NODE *_get_matrix_info(MATRIX);
