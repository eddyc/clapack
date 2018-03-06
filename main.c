//
//  main.cpp
//  TestClapack
//
//  Created by Edward Costello on 06/03/2018.
//  Copyright © 2018 Edward Costello. All rights reserved.
//

#include <f2c.h>
#include <clapack.h>
#include <stdio.h>

typedef struct Matrix {

    int rows;
    int cols;
    double *data;
} Matrix;


void multiply(Matrix *a, Matrix *b, Matrix *c) {

    integer m = a->rows;
    integer n = b->cols;
    integer k = a->cols;
    double alph = 1;
    double bet = 0;

    dgemm_("N", "N", &n, &m, &k, &alph, b->data, &n, a->data, &k, &bet, c->data, &n);
}

void print(Matrix *input) {

    for (size_t i = 0; i < input->rows; i++) {

        for (size_t j = 0; j < input->cols; ++j) {

            printf("[%f]", input->data[i * input->cols + j]);
        }

        printf("\n");
    }
}


int main(int argc, const char * argv[]) {

    Matrix A;
    double a[6] = {
        1, 2, 3,
        4, 5, 6
    };
    A.data = a;
    A.cols = 3;
    A.rows = 2;

    Matrix B;
    double b[6] = {
        2, 3,
        4, 5,
        6, 7
    };
    B.data = b;
    B.cols = 2;
    B.rows = 3;

    double c[4] = {0};
    Matrix C = {
        .rows = 2,
        .cols = 2,
        .data = c
    };

    multiply(&A, &B, &C);
    printf("Product is:\n");
    print(&C);

    return 0;
}
