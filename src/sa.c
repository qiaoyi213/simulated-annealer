#include "matrix.h"
double calculate_hamiltonain(matrix_t Q, matrix_t x){
    matrix_t x_t = matrix_transpose(x);
    matrix_t m = matrix_mul(x_t, Q);
    matrix_t result = matrix_mul(m, x);
    return result.elements[0];
}


