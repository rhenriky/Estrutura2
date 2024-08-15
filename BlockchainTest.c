#include"Blockchain.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int main(){


    Blockchain blockchain;
    printf(" ");
    initBlockchain(&blockchain);

    printf("GenesisBlock Hash:%s\n",blockchain.genesisBlock->hash);
    printf("GenesisBlock timestamp:%lu\n",blockchain.genesisBlock->timestamp);
    



    return 0;
}