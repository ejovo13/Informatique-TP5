// comparison of different sorting routines

#include "ejovo_sort.h"
#include "ejovo_rand.h"
#include "time.h"
#include "stdio.h"

#define N_SORT_FNS 4 // number of sorting functions that we're testing
#define N_SORTS 20 // number of arrays to generate and sort.
#define N_ELEMENTS 10000 // number of elements per array
#define MAX_VALUE 5000
// #define N_TRIALS 10 // average the number of trials

// use a copy array routine to use the same generated random array



int clear_screen(void) {
    return system("clear");
}


int main() {

    // create a random array that will be used over and over
    ejovo_seed();

    double p = 0;
    clock_t start = clock();
    clock_t end = start; // initialize the start and end times


    typedef void (*fn_sort) (int*, int);
    fn_sort fn_array[N_SORT_FNS] = {tri_bulle, tri_insertion, tri_selec, tri_rapide};
    char* fn_name[N_SORT_FNS] = {"Tri a bulle", "Tri par insertion", "Tri par selection", "Tri rapide"};
    clock_t total_time[N_SORT_FNS] = {0}; // The total time that each sorting routine takes,  in clock cycles

    int arr[N_ELEMENTS] = {0}; // Create array where all the sorts will be generated
    int *dummy = NULL;

    for (size_t i = 0; i < N_SORTS; i++) {

        init_tab(MAX_VALUE, arr, N_ELEMENTS); // fill arr with random elements from 1 to MAX

        for (size_t f = 0; f < N_SORT_FNS; f++) {

            dummy = copy_int_array(arr, N_ELEMENTS); // array that contains a copy of arr, copy_int_array declared in ejovo_sort
            fn_sort sort_method = fn_array[f];
            printf("is arr sorted? %d\n", is_sorted(arr, 0, N_ELEMENTS-1));
            printf("Calling function '%s' at address %p\n", fn_name[f], sort_method);
            start = clock();
            sort_method(dummy, N_ELEMENTS);
            end = clock();
            total_time[f] += (end - start);
            free(dummy);
            // for each election type, I should call the selection.
            // to improve my C skills, let's use a function pointer.

            // generate a random integer array
        }
    }

    // clear_screen();

    for (size_t i = 0; i < N_SORT_FNS; i++) {

        printf("Total time (s) for %20s: %lf\t average time: %lf\n", fn_name[i], (double) total_time[i] / CLOCKS_PER_SEC,
                                                                                 ((double) total_time[i] / CLOCKS_PER_SEC) / N_SORTS);


    }


    return 0;
}