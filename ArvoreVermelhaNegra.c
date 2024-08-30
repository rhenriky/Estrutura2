#include <stdio.h>
#include <stdlib.h>
#include "ArvoreVermelhaNegra.h"

// Função auxiliar para criar um novo nó
No* criarNo(ArvoreVermelhaNegra* arvore, int valor) {
    No* no = (No*)malloc(sizeof(No));
    no->valor = valor;
    no->cor = VERMELHO; // Todo novo nó é inicialmente vermelho
    no->esquerdo = arvore->nulo;
    no->direito = arvore->nulo;
    no->pai = NULL;
    return no;
}

// Rotação à esquerda
void rotacaoEsquerda(ArvoreVermelhaNegra* arvore, No* x) {
    No* y = x->direito;
    x->direito = y->esquerdo;

    if (y->esquerdo != arvore->nulo) {
        y->esquerdo->pai = x;
    }
    y->pai = x->pai;

    if (x->pai == NULL) {
        arvore->raiz = y;
    } else if (x == x->pai->esquerdo) {
        x->pai->esquerdo = y;
    } else {
        x->pai->direito = y;
    }

    y->esquerdo = x;
    x->pai = y;
}

// Rotação à direita
void rotacaoDireita(ArvoreVermelhaNegra* arvore, No* y) {
    No* x = y->esquerdo;
    y->esquerdo = x->direito;

    if (x->direito != arvore->nulo) {
        x->direito->pai = y;
    }
    x->pai = y->pai;

    if (y->pai == NULL) {
        arvore->raiz = x;
    } else if (y == y->pai->esquerdo) {
        y->pai->esquerdo = x;
    } else {
        y->pai->direito = x;
    }

    x->direito = y;
    y->pai = x;
}

// Função auxiliar para corrigir o balanceamento após a inserção
void corrigirInsercao(ArvoreVermelhaNegra* arvore, No* no) {
    while (no->pai->cor == VERMELHO) {
        if (no->pai == no->pai->pai->esquerdo) {
            No* tio = no->pai->pai->direito;
            if (tio->cor == VERMELHO) {
                no->pai->cor = PRETO;
                tio->cor = PRETO;
                no->pai->pai->cor = VERMELHO;
                no = no->pai->pai;
            } else {
                if (no == no->pai->direito) {
                    no = no->pai;
                    rotacaoEsquerda(arvore, no);
                }
                no->pai->cor = PRETO;
                no->pai->pai->cor = VERMELHO;
                rotacaoDireita(arvore, no->pai->pai);
            }
        } else {
            No* tio = no->pai->pai->esquerdo;
            if (tio->cor == VERMELHO) {
                no->pai->cor = PRETO;
                tio->cor = PRETO;
                no->pai->pai->cor = VERMELHO;
                no = no->pai->pai;
            } else {
                if (no == no->pai->esquerdo) {
                    no = no->pai;
                    rotacaoDireita(arvore, no);
                }
                no->pai->cor = PRETO;
                no->pai->pai->cor = VERMELHO;
                rotacaoEsquerda(arvore, no->pai->pai);
            }
        }
    }
    arvore->raiz->cor = PRETO;
}

// Função para inserir um valor na árvore
void inserir(ArvoreVermelhaNegra* arvore, int valor) {
    No* novo = criarNo(arvore, valor);
    No* y = NULL;
    No* x = arvore->raiz;

    while (x != arvore->nulo) {
        y = x;
        if (novo->valor < x->valor) {
            x = x->esquerdo;
        } else {
            x = x->direito;
        }
    }

    novo->pai = y;
    if (y == NULL) {
        arvore->raiz = novo;
    } else if (novo->valor < y->valor) {
        y->esquerdo = novo;
    } else {
        y->direito = novo;
    }

    if (novo->pai == NULL) {
        novo->cor = PRETO;
        return;
    }

    if (novo->pai->pai == NULL) {
        return;
    }

    corrigirInsercao(arvore, novo);
}

// Função para fazer uma travessia em ordem (in-order traversal)
void emOrdemAux(No* no, No* nulo) {
    if (no != nulo) {
        emOrdemAux(no->esquerdo, nulo);
        printf("%d ", no->valor);
        emOrdemAux(no->direito, nulo);
    }
}

void emOrdem(ArvoreVermelhaNegra* arvore) {
    emOrdemAux(arvore->raiz, arvore->nulo);
    printf("\n");
}

// Função para criar a árvore
ArvoreVermelhaNegra* criarArvore() {
    ArvoreVermelhaNegra* arvore = (ArvoreVermelhaNegra*)malloc(sizeof(ArvoreVermelhaNegra));
    arvore->nulo = (No*)malloc(sizeof(No));
    arvore->nulo->cor = PRETO;
    arvore->raiz = arvore->nulo;
    return arvore;
}

// Função para destruir a árvore
void destruirNo(No* no, No* nulo) {
    if (no != nulo) {
        destruirNo(no->esquerdo, nulo);
        destruirNo(no->direito, nulo);
        free(no);
    }
}

void destruirArvore(ArvoreVermelhaNegra* arvore) {
    destruirNo(arvore->raiz, arvore->nulo);
    free(arvore->nulo);
    free(arvore);
}
