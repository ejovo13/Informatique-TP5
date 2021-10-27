#ifndef EJOVO_SORT
#define EJOVO_SORT

#include "ejovo_rand.h"
#include "stdbool.h"
// Collection of basic sorting routines

/** @file
 *  @brief A collection of basic sorting routines that operate on integers
 *
 *  @author Evan Voyles
 *  @date 27 October 2021
 *
 *
 */

/**
 * Initialize an array with random elements from 0 to `__max`
 *
 * @param __max Maximum value of a random element
 * @param __tab Pointer to block of memory where we will store the values
 * @param __n   Number of random elements to generate
 *
 */
void init_tab(int __max, int *__tab, int __n);

/**
 *  Exchange two values in an array
 *
 */
void ech(int *__tab, int __i, int __j);

/**
 * Return index of the smallest value in the array
 *
 */
int find_min_index(int *__tab, int __n);

/**
 * Sort an integer array by selection
 *
 */
void tri_selec(int *__tab, int __n);

/**
 * Sort an integer array by bubble sort
 *
 */
void tri_bulle(int *__tab, int __n);

/**
 *  Insert a value into a sorted sub array array of size __n_sorted_array
 */
void insert(int *__full_array, int __n_sorted_array, int __ivalue);

/**
 * Sort an integer array by insertion sort
 *
 */
void tri_insertion(int *__tab, int __n);

/**
 *  Test if an integer array is sorted in increasing order
 *
 *  return true if the array is in increasing order
 */
bool is_sorted(const int *__tab, int __low, int __high);

/**
 *  Partition an array in place about the element __tab[__high]
 *
 *  In this case partition means to move all the elements less than a pivot element to the
 *  left of the pivot's final position in the completely sorted array. Likewise for the elements greater
 *  than the pivot.
 *
 *  @return the index of the pivot value in its final position of the sorted array
 */
int partition(int *__tab, int __low, int __high);

/** @private
 *  Quick sort
 */
void new_tri_rapide(int *__tab, int __low, int __high);

// UNITE THE SORTING FUNCTION API CALL THAT IS void (*func) (int*, int) !!!!!
/**
 * Sort an integer array by quicksort
 *
 *
 */
void tri_rapide(int *__tab, int __n);

/**
 * Copy __n elements of an integer array into a new malloc block
 *
 */
int *copy_int_array(const int *__arr, size_t __n);

#endif