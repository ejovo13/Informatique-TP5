// tri a bulle
#include "ejovo_print.h"
#include "ejovo_sort.h"


int main(void) {

    ex(5, "Generer un tableau aleatoire de taille 100 et le trier par bulle");

    ejovo_seed();

    int tab[100] = {0};

    init_tab(100, tab, 100);
    print_int_array(tab, 100);

    printf("\nSorting by tri_bull...\n\n");
    tri_bulle(tab, 100); // defined in ejovo_sort.c

    print_int_array(tab, 100);



    return 0;
}