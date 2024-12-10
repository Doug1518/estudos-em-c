#ifndef ARVORE2_3_4_H_INCLUDED
#define ARVORE2_3_4_H_INCLUDED

// ------------------- estruturas -------------------
struct no {
    int valores[3];
    struct no *filhos[4];
    struct no *pai;
    int quantChaves;
};

typedef struct no No;

struct arv {
    No *raiz;
};

typedef struct arv Arvore2_3_4;

// ------------------- funções e procedimentos -------------------
No* criarNo();
int ehFolha(No *no);
No* escolheFilho(No *no, int valor);
void dividirRaiz(No *raiz);
void dividirFilho(No *raiz);
void dividir(No *raiz);
void ordenar(No *no);
void inserirValor(No *raiz, int valor);
void inserir(Arvore2_3_4 *arv, int valor);
void imprimir(No *raiz, int nivel);
No* buscar(No *no, int valor, int nivel);
int quantidadeChaves(No *raiz);
int getIndice(No *no, int valor);
int getMaiorDosMenores(No *raiz);
int getMenorDosMaiores(No *raiz);
int removerCaso1(No *no, int indice);
int removerCaso3(No *no, int indice);
int indiceNo(No *no);
int temIrmaoRico(No *no);
void deslocarParaEsquerda(No *no, int idChave, int idFilho);
int pegaMaiorValor(No *no);
int pegaMenorValor(No *no);
int removerCaso5(No *no);
No* juntaNosFilhos(No *no1, No *no2);
int insereOrdenado(No *no, int valor);
No* getPai(No *no);
No* removerCaso2(No *no, int valor);
No* irmaoEstaCheio(No *no);
No* removerCaso6(No *no, int valor);
//int irmaosTemApenasUmaChave(No *pai);
int removerCaso7(No *no);
void remover(Arvore2_3_4 *arv, int valor);

#endif

