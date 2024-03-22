  #ifndef EstruturaDeDados_Hash_h
    #define EstruturaDeDados_Hash_h

    #include "DoublyLinkedList.h"

    #define MAX 10
    typedef struct HashStruct {
        DoublyLinkedList hashes[MAX];
        int size;
    }HashStruct;
    
    void initHash(HashStruct *hashStruct);
    //verifica se a tabela de hash está vazia
    bool isHashEmpty(HashStruct *hashStruct);
    //calcula o hash para a chave
    int hash(char *key);
    //insere um par (chave,valor)
    int put(HashStruct *hashStruct, char *key, void *data, compare equal);
    //verifica se a chave já existe na tabela de hash
    bool containsKey(HashStruct *hashStruct, char *key, compare equal);
    // retorna o valor buscando pela chave
    void* get(HashStruct *hashStruct, char *key, compare equal);
    // remove um par (chave,valor)
    void* removeKey(HashStruct *hashStruct, char *key, compare equal);
    // exibe os pares armazenados
    void showHashStruct(HashStruct *hashStruct, printNode print);
    
    #endif