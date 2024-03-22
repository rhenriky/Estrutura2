#include <stdlib.h>
#include <stdio.h>
#include "GeneralizedLinkedList.h"

int main()
{   
    Node *listaGeneralizada = NULL;
    printf("Lista: ");
    show(listaGeneralizada);

    addAtom(&listaGeneralizada, 5);
    Node *lista2 = NULL;
    addAtom(&lista2, 7);
    addAtom(&lista2, 9);
    Node *lista3 = NULL;
    addAtom(&lista3, 11);
    addAtom(&lista3, 13);

    addList(&listaGeneralizada, &lista2);
    addList(&listaGeneralizada, &lista3);

    printf("\nLista: ");
    show(listaGeneralizada);
    printf("\nProfundidade: %d\n",depth(listaGeneralizada));
    
    printf("\nTail: ");
    show(tail(listaGeneralizada));

    printf("\n\nhead(tail()): %d\n",head(tail(listaGeneralizada))->atomList.atom);
    printf("\n\nhead(tail(tail(head(tail(tail()))))):\n");
    
    return 0;
}