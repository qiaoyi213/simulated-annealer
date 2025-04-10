#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "matrix.h"

matrix_t matrix_create(size_t row, size_t col) {
    matrix_t matrix = {0};
    matrix.row = row;
    matrix.col = col;
    matrix.elements = malloc(row * col * sizeof(double));
    
    if (matrix.elements == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    // Initialize all elements to 0
    memset(matrix.elements, 0, row * col * sizeof(double));
    return matrix;
}

matrix_t matrix_init(size_t row, size_t col, double* elements) {
    matrix_t matrix = matrix_create(row, col);
    
    if (elements != NULL) {
        memcpy(matrix.elements, elements, row * col * sizeof(double));
    }
    
    return matrix;
}

void matrix_free(matrix_t* matrix) {
    if (matrix != NULL && matrix->elements != NULL) {
        free(matrix->elements);
        matrix->elements = NULL;
        matrix->row = 0;
        matrix->col = 0;
    }
}

bool matrix_is_valid(const matrix_t matrix) {
    return matrix.elements != NULL && matrix.row > 0 && matrix.col > 0;
}

void matrix_print(const matrix_t matrix) {
    if (!matrix_is_valid(matrix)) {
        printf("Invalid matrix\n");
        return;
    }

    for (size_t i = 0; i < matrix.row; i++) {
        for (size_t j = 0; j < matrix.col; j++) {
            printf("%8.2f ", matrix.elements[i * matrix.col + j]);
        }
        printf("\n");
    }
}

matrix_t matrix_add(const matrix_t A, const matrix_t B) {
    assert(A.row == B.row && A.col == B.col);
    
    matrix_t result = matrix_create(A.row, A.col);
    
    for (size_t i = 0; i < A.row * A.col; i++) {
        result.elements[i] = A.elements[i] + B.elements[i];
    }
    
    return result;
}

matrix_t matrix_sub(const matrix_t A, const matrix_t B) {
    assert(A.row == B.row && A.col == B.col);
    
    matrix_t result = matrix_create(A.row, A.col);
    
    for (size_t i = 0; i < A.row * A.col; i++) {
        result.elements[i] = A.elements[i] - B.elements[i];
    }
    
    return result;
}

matrix_t matrix_mul(const matrix_t A, const matrix_t B) {
    assert(A.col == B.row);
    
    matrix_t result = matrix_create(A.row, B.col);
    
    for (size_t i = 0; i < A.row; i++) {
        for (size_t j = 0; j < B.col; j++) {
            double sum = 0.0;
            for (size_t k = 0; k < A.col; k++) {
                sum += A.elements[i * A.col + k] * B.elements[k * B.col + j];
            }
            result.elements[i * B.col + j] = sum;
        }
    }
    
    return result;
}

matrix_t matrix_transpose(const matrix_t A) {
    matrix_t result = matrix_create(A.col, A.row);
    
    for (size_t i = 0; i < A.row; i++) {
        for (size_t j = 0; j < A.col; j++) {
            result.elements[j * A.row + i] = A.elements[i * A.col + j];
        }
    }
    
    return result;
}

double matrix_at(const matrix_t matrix, size_t i, size_t j) {
    return matrix.elements[i*matrix.col + j];
}
