#include "matrix.h"
#include<math.h>
double calculate_hamiltonain(matrix_t Q, matrix_t x){
    matrix_t x_t = matrix_transpose(x);
    matrix_t m = matrix_mul(x_t, Q);
    matrix_t result = matrix_mul(m, x);
    return result.elements[0];
}

double sa_sample(matrix_t Q) {
    matrix_t s = matrix_create(Q.row);
    int k_max = 100;

    for(int k=0;k<k_max;k++) {
        T = temperature(k, k_max);
        matrix_t sn = neighbour(s);
        double e = calculate_hamiltonain(Q, s);
        double en = calculate_hamiltonain(Q, sn);

        if(rand% 100 < int(P(e, en, T))){
            s = sn;
            e = en;
        }
    }
    return s;
}
double temperature(int k, int k_max){
     
    return 1-((k+1)/k_max);
}
double P(double e, double en, double T) {
    if(en > e) return 1;
    return exp((e - en)/T);
}
matrix_t neighbour(matrix_t x) {
    int len = x.rows;
    int pos = rand() % len;
    x.elements[0][pos] = -1 * (x.elements[0][pos] -1);
    return x;
}
