#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct {
    size_t row;
    size_t col;
    double* elements;
} matrix_t;

// Matrix creation and initialization
matrix_t matrix_create(size_t row, size_t col);
matrix_t matrix_init(size_t row, size_t col, double* elements);
void matrix_free(matrix_t* matrix);

// Matrix operations
matrix_t matrix_add(const matrix_t A, const matrix_t B);
matrix_t matrix_sub(const matrix_t A, const matrix_t B);
matrix_t matrix_mul(const matrix_t A, const matrix_t B);
matrix_t matrix_transpose(const matrix_t A);

// Utility functions
bool matrix_is_valid(const matrix_t matrix);
void matrix_print(const matrix_t matrix);

#endif // MATRIX_H
