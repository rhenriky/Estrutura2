#include "Blockchain.h"
#include <string.h>
#include "sha-256.h"
#include <time.h>


//Procedimento p/ transformar hash de 32 bytes p/ string 64 caracteres
static void hash_to_string(char string[65], const uint8_t hash[32])
{
    size_t i;
    //monta string com 64 caracteres hexadecimais
    for(i = 0; i < 32; i++){
        //02x hexadecimal em 2 caracteres
        string += sprintf(string, "%02x", hash[i]);
    }
}
void initBlockchain(Blockchain *blockchain){

    Block * genesisBlock = (Block*) malloc(sizeof(Block));  
    genesisBlock->index = 0;
    genesisBlock->previousHash = "0";
    genesisBlock->previousBlock = NULL;
    genesisBlock->data = 800000;
    genesisBlock->timestamp = time(NULL);
    genesisBlock->hash = calculateHash(genesisBlock->index,genesisBlock->previousHash,genesisBlock->timestamp,genesisBlock->data);

    blockchain->genesisBlock = genesisBlock;
    blockchain->latestBlock = genesisBlock;

}
char* calculateHash(int index, char* previousHash, unsigned long timestamp, float data){
    char input[1024];
    sprintf(input, "%i%s%lu%.8f", index, previousHash,timestamp, data);

    uint8_t hash[32];//vetor de 32 bytes de inteiros unsigned [0-255] (256/8 =32)
    //char hash_string[65];
    char * hash_string = (char*) malloc(sizeof(char)*65);
    //realiza a função hash
    calc_sha_256(hash,input,strlen(input));
    //transforma o hash em uma string de 64 caracteres
    hash_to_string(hash_string,hash);

    return hash_string;
}
char * calculateBlockHash(Block* block){
    return calculateHash(block->index,block->previousHash,block->timestamp,block->data);
}
Block* generateNextBlock(Blockchain *blockchain, float data){
    Block * previousBlock = getLatestBlock(blockchain);
    Block * newBlock = (Block*) malloc(sizeof(newBlock));

    newBlock->previousBlock = previousBlock;
    newBlock->previousHash = previousBlock->hash;
    newBlock->data = data;
    newBlock->timestamp = time(NULL);
    newBlock->index = previousBlock->index++;
    newBlock->hash = calculateBlockHash(newBlock);

    return newBlock;
}
Block* getLatestBlock(Blockchain *blockchain){
    return blockchain->latestBlock;
}
bool isValidNewBlock(Block* newBlock, Block* previousBlock){
 

   if(newBlock->index != previousBlock->index+1){
       return false;
   }
   else if(newBlock->previousHash != previousBlock->hash){
       return false;
   }else if(strcmp(calculateBlockHash(newBlock),newBlock->hash) !=0){
       return false;
   } 

}
bool isBlockchainValid(Blockchain *blockchain){

    Block * block = getLatestBlock(blockchain);
    
    

}
int addBlock(Blockchain *blockchain, Block *newBlock){

}