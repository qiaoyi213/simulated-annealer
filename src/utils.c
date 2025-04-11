#include<stdio.h>
#include "matrix.h"
#include "utils.h"
const size_t MAX_COLS = 2000;

matrix_t load_qubo_txt(char* path) {
    
    FILE *fp = NULL;
    fp = fopen(path, "r");
    if(!fp) {
        printf("Load QUBO Error");
        exit(1);
    }
    int size = 0;
    fscanf(fp, "%d", &size);
    double* data = (double*)malloc((size*size)*sizeof(double));

    for(int i=0;i<size*size;i++){
        double num = 0.0;
        fscanf(fp, "%lf", &num);
        data[i] = num;
    } 
    fclose(fp);
    return matrix_init(size, size, data);
}


