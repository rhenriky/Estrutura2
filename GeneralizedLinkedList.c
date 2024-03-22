#include <stdlib.h>
#include <stdio.h>
#include "GeneralizedLinkedList.h"

int addAtom(Node **list, int atom)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode==NULL) return -1;
    newNode->type = 0;
    newNode->atomList.atom = atom;
    newNode->next = NULL;
    if (*list==NULL)
    {
        *list=newNode;
    }
    else
    {
        Node *aux=NULL;
        for (aux= *list; aux->next!=NULL; aux=aux->next);
        aux->next=newNode;
    }
    return 1;
}

int addList(Node **list, Node **subList)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode==NULL) return -1;
    newNode->type = 1;
    newNode->atomList.list = *subList;
    newNode->next = NULL;
    if (*list==NULL)
    {
        *list=newNode;
    }
    else
    {
        Node *aux=NULL;
        for (aux= *list; aux->next!=NULL; aux=aux->next);
        aux->next=newNode;
    }
    return 1;
}

Node* head(Node *list)
{
    Node *headaux=NULL;
    if ((list)->type==0)
    {
        headaux=(Node*)malloc(sizeof(Node));
        headaux->type=0;
        headaux->atomList.atom=(list)->atomList.atom;
        headaux->next=NULL;
    }
    else
    {
        headaux=list->atomList.list;
    }
    return headaux;
}

Node* tail(Node *list)
{
    return (list)->next;
}

void show(Node *list)
{
    printf("( ");
    Node *aux = NULL;
    for (aux = list; aux!=NULL; aux=aux->next)
    {
        if (aux->type==0)
        {
            printf("%d ",aux->atomList.atom);
        }
        else
        {
            show(aux->atomList.list);
        }
    }
    printf(")");
}

int depth(Node *list)
{
    int deep=0;
    if (list==NULL)
        return 0;

    Node *aux=NULL;
    for (aux=list; aux!=NULL; aux=aux->next)
    {
        if (aux->type==1)
        {
            int prof = depth(aux->atomList.list);
            if (prof>deep)
                deep=prof;
        }
    }
    return deep+1;
}