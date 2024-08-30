#ifndef ARVORE_VERMELHA_NEGRA_H
#define ARVORE_VERMELHA_NEGRA_H

// Definição das cores
typedef enum { VERMELHO, PRETO } Cor;

// Estrutura do nó da árvore
typedef struct No {
    int valor;
    Cor cor;
    struct No* esquerdo;
    struct No* direito;
    struct No* pai;
} No;

// Definição da árvore
typedef struct {
    No* raiz;
    No* nulo;  // Nó sentinela para representar os nós nulos
} ArvoreVermelhaNegra;

// Funções
ArvoreVermelhaNegra* criarArvore();
void destruirArvore(ArvoreVermelhaNegra* arvore);
void inserir(ArvoreVermelhaNegra* arvore, int valor);
void remover(ArvoreVermelhaNegra* arvore, int valor);
void emOrdem(ArvoreVermelhaNegra* arvore);

#endif // ARVORE_VERMELHA_NEGRA_H
