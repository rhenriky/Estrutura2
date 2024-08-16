#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"

void initHash(HashStruct *hashStruct) {
    for (int i = 0; i < MAX; i++) {
        init(&(hashStruct->hashes[i]));
    }
    hashStruct->size = 0;
}

bool isHashEmpty(HashStruct *hashStruct) {
    return hashStruct->size == 0;
}

int hash(char *key) {
    int sum = 0;
    for (int i = 0; key[i] != 0; i++) {
        sum += key[i];  // Somar diretamente o valor ASCII do caractere
    }
    return sum % MAX;  // Aplicar módulo para manter dentro do tamanho da tabela hash
}

int put(HashStruct *hashStruct, char *key, void *data, compare equal) {
    if (!containsKey(hashStruct, key, equal)) {
        int res = enqueue(&hashStruct->hashes[hash(key)], data);
        hashStruct->size += res;
        return res;
    }
    return 0;
}

bool containsKey(HashStruct *hashStruct, char *key, compare equal) {
    int hashValue = hash(key);
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal);
    return (pos != -1) ? true : false;
}

void* get(HashStruct *hashStruct, char *key, compare equal) {
    int hashValue = hash(key);
    Node *aux = hashStruct->hashes[hashValue].first->Next;
    while (aux != hashStruct->hashes[hashValue].first && !equal(aux->data, key))
        aux = aux->Next;
    return aux->data;
}

void* removeKey(HashStruct *hashStruct, char *key, compare equal) {
    int hashValue = hash(key);
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal);
    void* result = removePos(&hashStruct->hashes[hashValue], pos);
    if (result != NULL) hashStruct->size--;
    return result;
}

void showHashStruct(HashStruct *hashStruct, printNode print) {
    printf("There are %d elements in the Hash\n\n", hashStruct->size);
    for (int i = 0; i < MAX; i++) {
        printf("Hash %d has %d elements: ", i, hashStruct->hashes[i].size);
        show(&hashStruct->hashes[i], print);
        printf("\n");
    }
}
