#ifndef Blockchain_h
#define Blockchain_h

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

enum boolean {
    true = 1, false = 0
};

typedef enum boolean bool;

typedef struct Block {
    //index:Código único sequencial de indentificação do bloco
    unsigned int index;
    //hash do bloco anterior
    char* previousHash;
    struct Block* previousBlock;
    //Registro da data e hora em que o bloco foi criado
    unsigned long timestamp;
    //Conteúdo armazenado no bloco.
    float data;
    //Identificação de comprimento fixo que 
    //garante a integridade dos dados do bloco
    char* hash;
}Block;

typedef struct Blockchain {
    Block *genesisBlock; //Ponteiro para o primeiro bloco
    Block *latestBlock; //Ponteiro para o último bloco
}Blockchain;


//Gera o genesisBlock
void initBlockchain(Blockchain *blockchain);
char* calculateHash(int index, char* previousHash, unsigned long timestamp, float data);
//Gera próximo bloco
Block* generateNextBlock(Blockchain *blockchain, float data);
//Retorna último bloco
Block* getLatestBlock(Blockchain *blockchain);
//Verificar o novo bloco é valido
bool isValidNewBlock(Block* newBlock, Block* previousBlock);
//Verificar a cadeia de blocos é válida
bool isBlockchainValid(Blockchain *blockchain);
//insere um bloco
int addBlock(Blockchain *blockchain, Block *newBlock);

#endif