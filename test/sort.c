// Test out all of the sorting routines defined in ejovo_sort

#include <assert.h>
#include <stdio.h>
#include "ejovo_sort.h"
#include "ejovo_rand.h"

int main() {

    ejovo_seed();


    // verify that the function is_sorted works as behaved
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8}; // should be sorted
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 0}; // not sorted
    int arr2[] = {9, 1, 2, 3, 4, 5, 6, 7};

    assert(is_sorted(arr, 0, 8));
    assert(!is_sorted(arr1, 0, 8));
    assert(!is_sorted(arr2, 0, 8));

    // verify that my copy matrix behaves as expected
    int arr_copy = copy_int_array(arr, 8);



    // verify that sorting generates sorted arrays.






    return 0;
}