#include "Hash.h"
#include <stdio.h>
#include <stdlib.h>



void initHash(HashStruct *hashStruct){

    for(int i = 0; i<MAX;i++)init(&(hashStruct->hashes[i]));
    
    hashStruct->size = 0;
}

bool isHashEmpty(HashStruct *hashStruct){
    return (hashStruct->size == 0);     
}

int hash(char *key){
    int charSum = 0;
    for(int i = 0;*key != '\0';i++){
        charSum += (*key) * (i+1);
        key++;
    }
    return charSum % MAX;
}

int put(HashStruct *hashStruct, char *key, void *data, compare equal){
    
    if(!containsKey(hashStruct,key,equal)){
        DoublyLinkedList * matchedList;

        matchedList = &hashStruct->hashes[hash(key)];
        int item = enqueue(matchedList,data);
        hashStruct->size+=item;
        return item;
    }
        
        return -2;
}

bool containsKey(HashStruct *hashStruct, char *key, compare equal){
    
    DoublyLinkedList * matchedList;
    int containsKey;

    matchedList = &hashStruct->hashes[hash(key)];
    containsKey = indexOf(matchedList,key,equal); 
    return (containsKey>=0)?true:false;    
}

void* get(HashStruct *hashStruct, char *key, compare equal){
    //quase igual à containsKey
    Node * aux;
    Node *trashNode;


    trashNode = hashStruct->hashes[hash(key)].tail->next;
    aux = trashNode->next;
   
    for(;aux != trashNode && !equal(aux->data,key);aux = aux->next);

    return aux->data;
    //return (aux != trashNode)?aux->data: NULL;

}

void* removeKey(HashStruct *hashStruct, char *key, compare equal){  

    int hashValue = hash(key);
    int pos = indexOf(&hashStruct->hashes[hashValue],key,equal);

    printf("Pos:%d\n",pos);
    void * removedNode = removePos(&hashStruct->hashes[hashValue],pos);
    if(removedNode != NULL)hashStruct->size--;
    return removedNode;
}

void showHashStruct(HashStruct *hashStruct,printNode print){
   
  //  printf("HashTable com %d elementos\n",hashStruct->size);
    for(int i = 0; i<MAX;i++){
        if(hashStruct->hashes[i].size > 0){
            //printf("&hashStruct->hashes[i]:%s e %f",hashStruct->hashes[i].tail->next->next->data);
            //aux = hashStruct->hashes[i].tail->next->next->data
            printf("Hashes[%d] tem %d elementos:\n",i,hashStruct->hashes[i].size);
            show(&hashStruct->hashes[i],print);
        }
    }
        
}