#include <stdio.h>
#include "ArvoreVermelhaNegra.h"

int main() {
    ArvoreVermelhaNegra* arvore = criarArvore();

    // Inserindo valores na árvore
    inserir(arvore, 10);
    inserir(arvore, 20);
    inserir(arvore, 30);
    inserir(arvore, 15);
    inserir(arvore, 25);

    printf("Travessia em ordem da árvore:\n");
    emOrdem(arvore);  // Deve exibir os valores em ordem crescente

    destruirArvore(arvore);
    return 0;
}
