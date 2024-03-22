#include<stdio.h>
#include"Hash.h"
#include<stdlib.h>
#include<string.h>

typedef struct userBanco
{
    char * nome;
    float saldo;
}userBanco;

bool compararChaves(void * data,void *key){

    char * chave = (char*) key;
    userBanco * cliente = (userBanco*) data;

    return (strcmp(chave,cliente->nome) == 0)?true:false;
    //return (*chave == cliente->nome)? true: false;
}

void imprimirUser(void * user){
    userBanco * user1 = (userBanco*) user;
    printf("Nome:%s e Saldo:%.2f\n", user1->nome,user1->saldo);    
}

int main() {
    
    // Inicializa a estrutura de hash
    HashStruct Hash;
    initHash(&Hash);

    // Adiciona alguns usuários ao banco
    userBanco usuario1 = {"Joao", 100.0};
    userBanco usuario2 = {"Maria", 200.0};
    userBanco usuario3 = {"Carlos", 150.0};

    put(&Hash, usuario1.nome, &usuario1, compararChaves);
    put(&Hash, usuario2.nome, &usuario2, compararChaves);
    put(&Hash, usuario3.nome, &usuario3, compararChaves);

    // Busca por um usuário
    char *nomeBuscado = "Maria";
    userBanco *usuarioBuscado = get(&Hash, nomeBuscado, compararChaves);
    if (usuarioBuscado != NULL) {
        printf("Usuário %s encontrado. Saldo: %.2f\n", nomeBuscado, usuarioBuscado->saldo);
    } else {
        printf("Usuário %s não encontrado.\n", nomeBuscado);
    }

    // Remove um usuário
    char *nomeRemovido = "Joao";
    void *usuarioRemovido = removeKey(&Hash, nomeRemovido, compararChaves);
    if (usuarioRemovido != NULL) {
        printf("Usuário %s removido.\n", nomeRemovido);
    } else {
        printf("Usuário %s não encontrado para remoção.\n", nomeRemovido);
    }

    // Exibe todos os usuários restantes
    printf("Usuários no banco após remoção:\n");
    showHashStruct(&Hash, imprimirUser);

    return 0;
}
