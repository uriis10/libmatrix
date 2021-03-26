typedef (double **) MATRIX;

MATRIX create_matrix(int, int);
MATRIX copy_matrix(MATRIX);
MATRIX copy_dimensions(MATRIX);
void destroy_matrix(MATRIX);

int get_cols(MATRIX);
int get_rows(MATRIX);
int is_legal_matrix(MATRIX);

void add_to_matrix(MATRIX, MATRIX);
MATRIX add_matrix(MATRIX, MATRIX);
MATRIX scale_matrix(MATRIX, int);
void scale_to_matrix(MATRIX, int);
