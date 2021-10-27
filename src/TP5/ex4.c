// tri par selection

#include "ejovo_input.h"
#include <stdlib.h>
#include "ejovo_sort.h"
#include "ejovo_print.h"


int main() {

    ejovo_seed();
    ex(4, "Generer un tableau aleatoire de taille 100 et le trier par\n\t\tselection");

    int tab[100] = {0};

    init_tab(100, tab, 100); // random array from 0 to 100.
    print_int_array(tab, 100);

    printf("\nSorting all elements...\n\n");

    tri_selec(tab, 100); // definied in ejovo_sort.c (on vs code you can press F12 to see the definition)
    print_int_array(tab, 100);


    return 0;
}