typedef (double **) MATRIX;

MATRIX create_matrix(int, int);
void destroy_matrix(MATRIX);
int get_cols(MATRIX);
int get_rows(MATRIX);
int is_legal_matrix(MATRIX);
