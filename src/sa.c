#include "matrix.h"
#include "sa.h"
#include<stdio.h>
#include<math.h>
double calculate_hamiltonain(matrix_t Q, matrix_t x){
    matrix_t x_t = matrix_transpose(x);
    matrix_t m = matrix_mul(x_t, Q);
    matrix_t result = matrix_mul(m, x);
    return result.elements[0];
}
matrix_t neighbour(matrix_t x) {
    int len = x.row;
    int pos = rand() % len;
    x = matrix_set(x, 0, pos, -1 * (matrix_at(x, 0, pos) - 1));
    return x;
}
double temperature(int k, int k_max){
     
    return 1-((k+1)/k_max);
}
double P(double e, double en, double T) {
    if(en > e) return 1;
    return exp((e - en)/T);
}

matrix_t sa_sample(matrix_t Q) {
    matrix_t s = matrix_create(Q.row, 1);
    int k_max = 100;

    for(int k=0;k<k_max;k++) {
        double T = temperature(k, k_max);
        matrix_t sn = neighbour(s);
        double e = calculate_hamiltonain(Q, s);
        double en = calculate_hamiltonain(Q, sn);

        if(rand() % 100 < P(e, en, T) * 100){
            s = sn;
            e = en;
        }
    }

    printf("Hamiltonain: %lf \n", calculate_hamiltonain(Q, s));
    return s;
}

