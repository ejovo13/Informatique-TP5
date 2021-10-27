// tri par insertion
#include "ejovo_sort.h"
#include "ejovo_print.h"



int main() {

    ejovo_seed();
    ex(6, "Generer un tableau aleatoire de taille 100 et le trier par insertion");

    int tab[100] = {0};

    init_tab(100, tab, 100);
    print_int_array(tab, 100);

    printf("\nSorting by insertion...\n\n");
    tri_insertion(tab, 100); // defined in ejovo_sort.c

    print_int_array(tab, 100);

    return 0;
}