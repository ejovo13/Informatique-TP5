#include "ejovo_sort.h"



void init_tab(int __max, int *__tab, int __n) {

    for (int i = 0; i < __n; i++) {

        __tab[i] = unif(0, __max);

    }
}

void ech(int *__tab, int __i, int __j) {

    int temp = __tab[__i];
    __tab[__i] = __tab[__j];
    __tab[__j] = temp;

}

// return index of the smallest value in the array
int find_min_index(int *__tab, int __n) {

    int min = __tab[0];
    int min_index = 0;

    for (int i = 1; i < __n; i++) {

        if (__tab[i] < min) {
            min = __tab[i];
            min_index = i;
        }
    }

    return min_index;

}

void tri_selec(int *__tab, int __n) {

    int min_index = -1;

    for (int i = 0; i < __n; i++) {

        // find min index from __tab + i to the end of the array
        min_index = find_min_index(__tab + i, __n - i);
        // printf("min_index %d = %d\n", i, min_index);
        // exchange current index with the min index adjusted for the large array
        ech(__tab, i, min_index + i);

    }
}

void tri_bulle(int *__tab, int __n) {

    bool is_sorted = false; // true if every element i + 1 is greater than i

    while (!is_sorted) {

        // sort the elements
        is_sorted = true; // if we can make it through the entire array with __tab[i] < __tab[i + 1], this doesnt change!

        for (int i = 0; i < __n - 1; i++) { // go to the second to last element

            if (__tab[i] > __tab[i + 1] ) { // if two adjacent elements are not in the right order, sort them
                ech(__tab, i, i + 1);
                is_sorted = false;
            } else {
                continue;
            }
        }
    }
}

// insert a value into a sorted sub array array of size __n_sorted_array
void insert(int *__full_array, int __n_sorted_array, int __ivalue) {

    // find out where the element belongs
    for (int i = 0; i < __n_sorted_array; i++) {

        if (__full_array[__ivalue] < __full_array[i]) { // then place our value at the position i and SHIFT the rest of the table over

            for(int j = i; j < __ivalue; j++) {

                ech(__full_array, __ivalue, j); // im pretty sure this should work

            }
        }
    }
}

void tri_insertion(int *__tab, int __n) {
    for (int i = 1; i < __n; i++) {
        insert(__tab, i, i);
    }
}

// return true if the array is in increasing order
bool is_sorted(const int *__tab, int __low, int __high) {

    if (__high < __low) return false;
    if (__high == __low) return true;

    for (int i = __low + 1; i < __high; i++) {
        if (__tab[i] < __tab[i - 1]) return false;
    }

    return true;

}

// Return the index of the partitioned value
int partition(int *__tab, int __low, int __high) {

    int i = __low;
    int j = __high + 1;
    const int pivot = __tab[__low];

    while (true) {

        while (__tab[--j] >= pivot) {
            if (j == __low) break;
        }

        while (__tab[++i] <= pivot) {
            if (i == j) break;
        }


        if (i >= j) break;
        ech(__tab, i, j);
    }

    // put partitioning item at __tab[j]
    ech(__tab, __low, j);

    return j;

}

void new_tri_rapide(int *__tab, int __low, int __high) {

    if (__high <= __low) return;
    int j = partition(__tab, __low, __high);
    new_tri_rapide(__tab, __low, j - 1);
    new_tri_rapide(__tab, j + 1, __high);

}


void tri_rapide(int *__tab, int __n) {

    // I want to sort the array from 0 to __n - 1
    new_tri_rapide(__tab, 0, __n - 1);

}

int *copy_int_array(const int *__arr, size_t __n) {

    int *new_arr = (int *) malloc(__n * sizeof(int));

    for (size_t i = 0; i < __n; i++) {
        new_arr[i] = __arr[i];
    }

    return new_arr;

}