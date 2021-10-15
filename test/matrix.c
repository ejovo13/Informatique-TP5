#include "ejovo_matrix.h"
#include "ejovo_print.h"
#include "assert.h"

int main(void) {

    // Matrix * A = Matrix_new(5, 5);

    Matrix * m1 = Matrix_ij(10, 10);
    Matrix * m2 = Matrix_ones(13, 3);
    Matrix * m3 = Matrix_new(3, 8);
    Matrix * m4 = Matrix_new(5, 5);

    assert(m1);
    assert(m2);
    assert(m3);
    assert(m4);

    Matrix_print(m1);
    Matrix_print(m2);
    Matrix_print(m3);
    Matrix_print(m4);

    print_line(80, '=');
    printf("Here begins the computational functions\n");
    print_line(80, '=');

    Matrix * m5 = Matrix_value(10, 10, 5);
    Matrix * m6 = Matrix_value(10, 10, 4);
    Matrix * m7 = Matrix_add(m5, m6);

    Matrix_print(m5);
    printf("\n\t+\n");
    Matrix_print(m6);
    printf("\n\t=\n");
    Matrix_print(m7);

    print_line(80, '=');
    ejovo_seed();

    Matrix * m8 = Matrix_random(6, 5, 0, 15);
    Matrix * m9 = Matrix_random(1, 6, 1, 2);
    Matrix * m10 = Matrix_multiply(m9, m8);
    assert(Matrix_comp_mult(m9, m8));
    assert(m10);


    Matrix * m11 = Matrix_random(5, 5, -5, 5);
    Matrix_print(m11);
    printf("\n\t^1 = \n");
    Matrix_print(Matrix_pow(m11, 1));

    Matrix * m11_1 = Matrix_pow(m11, 1);
    Matrix * m11_1_0 = Matrix_pow(m11, 0);
    Matrix * m11_2 = Matrix_pow(m11, 2);
    Matrix * m11_4 = Matrix_pow(m11, 4);

    printf("\n\t^0 = \n");
    Matrix_print(Matrix_pow(m11_1, 0));

    printf("\n\t^2 = \n");
    Matrix_print(m11_2);

    printf("\n\t^4 = \n");
    Matrix_print(m11_4);

    Matrix_print(m9);
    printf("\n\t*\n");
    Matrix_print(m8);
    printf("\n\t=\n");
    Matrix_print(m10);

    print_line(80, '-');

    Matrix * A1 = Matrix_rand(25, 25);
    Matrix_print(A1);
    printf("\n");

    Matrix * A_sub1 = Matrix_submat(A1, 0, 9, 0, 9); // get 10x10 block
    Matrix_print(A_sub1);






    return 0;
}