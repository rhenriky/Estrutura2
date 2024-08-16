// ArvoreAVL.h

#ifndef ARVORE_AVL_H
#define ARVORE_AVL_H

typedef struct NoAVL {
    int valor;
    struct NoAVL* esquerdo;
    struct NoAVL* direito;
    int altura;
} NoAVL;

typedef struct {
    NoAVL* raiz;
} ArvoreAVL;

ArvoreAVL* criarArvoreAVL();
void destruirArvoreAVL(ArvoreAVL* arvore);
void inserirAVL(ArvoreAVL* arvore, int valor);
void removerAVL(ArvoreAVL* arvore, int valor);
void emOrdemAVL(NoAVL* no);
void preOrdemAVL(NoAVL* no);
int profundidadeAVL(NoAVL* no);
void imprimirArvore(NoAVL* no, int espaco);  
#endif
