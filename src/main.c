#include<stdlib.h>
#include<stdio.h>
#include "matrix.h"
#include "utils.h"
#include "sa.h"

int main(int argc, char* argv[]) { 
    matrix_t Q = load_qubo_txt("qubo.txt");
    matrix_print(Q);
    for(int i=0;i<100;i++){
        matrix_t x = sa_sample(Q);

    }
    return 0;
}
