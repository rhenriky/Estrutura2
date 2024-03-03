#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "GeneralizedLinkedList.h"
#include "log.h"

int addAtom(Node **list, int atom){
    Node *no = (Node*)malloc(sizeof(Node));
    if(no == NULL) return -1;
    no->type = 0;
    no->atomList.atom = atom;
    no ->next = NULL;
    return 1;
}
int addList (Node **list, Node **subList){
    Node *aux = (Node*)malloc(sizeof(Node));
    if(aux == NULL) return -1;
    aux->type = 1;
    aux->atomList.list = subList;
    aux->next = NULL;
    return 1;

}

Node* head (Node *list){
    Node *aux = (Node*)malloc(sizeof(Node));
    aux->list-next;
    return aux;
}

Node* tail(Node *list){
    Node *aux = (Node*)malloc(sizeof(Node));
    aux->list->next;
    return aux;
}

void show(Node *list){
    Node *aux = (Node*)malloc(sizeof(Node));
    aux = list;
    while(aux!= NULL){
        printf("%p",&aux);
        aux->next;

    }
    printf("/n");
}
/*boole search (Node *list, int atom);
int depth(Node *list);
*/