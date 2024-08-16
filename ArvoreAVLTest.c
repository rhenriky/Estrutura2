// ArvoreAVLTest.c

#include <stdio.h>
#include "ArvoreAVL.h"

void mostrarMenu() {
    printf("\nMenu:\n");
    printf("1. Inserir valor\n");
    printf("2. Remover valor\n");
    printf("3. Exibir a árvore (in-order)\n");
    printf("4. Exibir a árvore (pre-order)\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    ArvoreAVL* arvore = criarArvoreAVL();
    int opcao, valor;

    do {
        mostrarMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                inserirAVL(arvore, valor);
                printf("Valor %d inserido na árvore AVL.\n", valor);
                break;

            case 2:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                removerAVL(arvore, valor);
                printf("Valor %d removido da árvore AVL.\n", valor);
                break;

            case 3:
                printf("Exibindo árvore (in-order): ");
                emOrdemAVL(arvore->raiz);
                printf("\n");
                break;

            case 4:
                printf("Exibindo árvore (pre-order): ");
                preOrdemAVL(arvore->raiz);
                printf("\n");
                break;

            case 5:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);

    destruirArvoreAVL(arvore);
    return 0;
}

