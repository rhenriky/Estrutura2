#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

void init(DoublyLinkedList *list) {
    Node *trashNode = (Node *)malloc(sizeof(Node));
    trashNode->data = NULL;
    trashNode->previous = trashNode;
    trashNode->Next = trashNode;
    list->first = trashNode;
    list->size = 0;
}

int enqueue(DoublyLinkedList *list, void *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        return -1;
    }
    newNode->data = data;
    newNode->Next = list->first;
    newNode->previous = list->first->previous;
    list->first->previous->Next = newNode;
    list->first->previous = newNode;
    list->size++;
    return 1;
}

void* dequeue(DoublyLinkedList *list) {
    if (isEmpty(list)) return NULL;
    Node *trash = list->first;
    Node *first = list->first->Next;
    first->Next->previous = trash;
    trash->Next = first->Next;
    void *data = first->data;
    free(first);
    list->size--;
    return data;
}

void* first(DoublyLinkedList *list) {
    if (isEmpty(list)) return NULL;
    return list->first->Next->data;
}

void* last(DoublyLinkedList *list) {
    if (isEmpty(list)) return NULL;
    return list->first->previous->data;
}

int push(DoublyLinkedList *list, void *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        return -1;
    }
    newNode->data = data;
    newNode->Next = list->first->Next;
    newNode->previous = list->first;
    list->first->Next->previous = newNode;
    list->first->Next = newNode;
    list->size++;
    return 1;
}

void* pop(DoublyLinkedList *list) {
    return dequeue(list);
}

void* top(DoublyLinkedList *list) {
    return first(list);
}

bool isEmpty(DoublyLinkedList *list) {
    return (list->size == 0);
}

int indexOf(DoublyLinkedList *list, void *data, compare equal) {
    if (isEmpty(list)) return -1;
    Node *aux = list->first->Next;
    int i = 0;
    while (aux != list->first && !equal(aux->data, data)) {
        aux = aux->Next;
        i++;
    }
    return (aux != list->first) ? i : -1;
}

Node* getNodeByPos(DoublyLinkedList *list, int pos) {
    if (isEmpty(list) || pos >= list->size) return NULL;
    Node *aux = list->first->Next;
    for (int count=0;(aux != list->first && count < pos); count++, aux = aux->Next);
    return aux;
}

void* getPos(DoublyLinkedList *list, int pos) {
    Node *aux = getNodeByPos(list, pos);
    if (aux == NULL) return NULL;
    else return aux->data;
}

int add(DoublyLinkedList *list, int pos, void *data) {
    if (pos < 0 || pos > list->size) return -1;
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) return -1;
    newNode->data = data;
    if (pos == 0) {
        newNode->Next = list->first->Next;
        newNode->previous = list->first;
        list->first->Next->previous = newNode;
        list->first->Next = newNode;
    } else {
        Node *aux = getNodeByPos(list, pos - 1);
        newNode->Next = aux->Next;
        newNode->previous = aux;
        aux->Next->previous = newNode;
        aux->Next = newNode;
    }
    list->size++;
    return 1;
}

int addAll(DoublyLinkedList *listDest, int pos, DoublyLinkedList *listSource) {
    Node *aux = getNodeByPos(listDest, pos);
    if (aux == NULL) return -2;
    if (isEmpty(listSource)) return -1;
    listSource->first->previous->Next = aux;
    listSource->first->Next->previous = aux->previous;
    aux->previous->Next = listSource->first->Next;
    aux->previous = listSource->first->previous;
    listDest->size += listSource->size;
    return listSource->size;
}

void* removePos(DoublyLinkedList *list, int pos) {
    if (isEmpty(list) || pos >= list->size) return NULL;
    Node *nodeRemove = getNodeByPos(list, pos);
    nodeRemove->previous->Next = nodeRemove->Next;
    nodeRemove->Next->previous = nodeRemove->previous;
    void* dataRemove = nodeRemove->data;
    free(nodeRemove);
    list->size--;
    return dataRemove;
}

bool removeData(DoublyLinkedList *list, void *data, compare equal) {
    if (isEmpty(list)) return -1;
    Node *nodeRemove = list->first->Next;
    while (nodeRemove != list->first && !equal(nodeRemove->data, data))
        nodeRemove = nodeRemove->Next;
    if (nodeRemove != list->first) {
        nodeRemove->previous->Next = nodeRemove->Next;
        nodeRemove->Next->previous = nodeRemove->previous;
        free(nodeRemove->data);
        free(nodeRemove);
        list->size--;
        return 1;
    } else {
        return 0;
    }
}

void show(DoublyLinkedList *list, printNode print) {
    Node *aux = list->first->Next;
    while (aux != list->first) {
        print(aux->data);
        aux = aux->Next;
    }
    printf("\n");
}

void showMem(DoublyLinkedList *list) {
    printf("Trash Node: %p\n\n", list->first);
    Node *aux = list->first->Next;
    printf("Node Addr : Previous - Data - Next\n\n");
    while (aux != list->first) {
        printf("%p: %p - %p - %p\n", aux, aux->previous, aux->data, aux->Next);
        aux = aux->Next;
    }
}
