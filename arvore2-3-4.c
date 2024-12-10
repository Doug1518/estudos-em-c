#include <stdio.h>
#include <stdlib.h>
#include "arvore2-3-4.h"

/*
Cria um novo Nó e inicializa seus campos com zero ou nulo.
*/
No* criarNo() {
    No *novo = malloc(sizeof(No));
    if (novo) {
        novo->quantChaves = 0;
        novo->valores[0] = 0;
        novo->valores[1] = 0;
        novo->valores[2] = 0;
        novo->pai = NULL;
        novo->filhos[0] = NULL;
        novo->filhos[1] = NULL;
        novo->filhos[2] = NULL;
        novo->filhos[3] = NULL;
    }
    return novo;
}

int ehFolha(No *no) {
    return no->filhos[0] == NULL;
}

/*
Escolhe qual ponteiro filho seguir durante a inserção
*/
No* escolheFilho(No *no, int valor) {
    int i = 0;

    if (ehFolha(no)) // se folha, retorna o próprio nó
        return no;
    while (i < no->quantChaves && valor > no->valores[i])
        i++;
    return no->filhos[i]; // caminho para inserir valor
}

void dividirRaiz(No *raiz) {
    No *esquerda = criarNo();
    No *direita = criarNo();

    if (esquerda && direita) {
        esquerda->valores[0] = raiz->valores[0];
        esquerda->quantChaves++;
        esquerda->filhos[0] = raiz->filhos[0];
        esquerda->filhos[1] = raiz->filhos[1];
        esquerda->pai = raiz;

        if (esquerda->filhos[0]) {
            esquerda->filhos[0]->pai = esquerda;
            esquerda->filhos[1]->pai = esquerda;
        }

        direita->valores[0] = raiz->valores[2];
        direita->quantChaves++;
        direita->filhos[0] = raiz->filhos[2];
        direita->filhos[1] = raiz->filhos[3];
        direita->pai = raiz;

        if (direita->filhos[0]) {
            direita->filhos[0]->pai = direita;
            direita->filhos[1]->pai = direita;
        }

        raiz->valores[0] = raiz->valores[1];
        raiz->valores[1] = 0;
        raiz->valores[2] = 0;
        raiz->quantChaves = 1;

        raiz->filhos[0] = esquerda;
        raiz->filhos[1] = direita;
        raiz->filhos[2] = NULL;
        raiz->filhos[3] = NULL;
    } else {
        printf("Erro ao alocar memória em dividirRaiz!\n");
    }
}

void dividirFilho(No *raiz) {
    No *pai = raiz->pai;
    No *direita = criarNo();
    int i, tam;

    if (direita) {
        direita->valores[0] = raiz->valores[2];
        direita->quantChaves++;
        direita->filhos[0] = raiz->filhos[2];
        direita->filhos[1] = raiz->filhos[3];
        direita->pai = pai;

        if (direita->filhos[0]) {
            direita->filhos[0]->pai = direita;
            direita->filhos[1]->pai = direita;
        }

        tam = pai->quantChaves - 1;
        if (raiz->valores[1] > pai->valores[tam]) {
            pai->valores[tam + 1] = raiz->valores[1];
            pai->quantChaves++;
            pai->filhos[tam + 2] = direita;
        } else {
            for (i = tam; i >= 0; i--) {
                if (raiz->valores[1] < pai->valores[i]) {
                    pai->valores[i + 1] = pai->valores[i];
                    pai->filhos[i + 2] = pai->filhos[i + 1];
                } else {
                    break;
                }
            }
            i++;
            pai->valores[i] = raiz->valores[1];
            pai->quantChaves++;
            pai->filhos[i + 1] = direita;
        }

        raiz->quantChaves = 1;
        raiz->valores[1] = 0;
        raiz->valores[2] = 0;
        raiz->filhos[2] = NULL;
        raiz->filhos[3] = NULL;
    } else {
        printf("Erro ao alocar memória em dividirFilho!\n");
    }
}

void dividir(No *raiz) {
    if (raiz->pai)
        dividirFilho(raiz);
    else
        dividirRaiz(raiz);
}

void ordenar(No *no) {
    int i, j, aux;
    for (i = 0; i < no->quantChaves - 1; i++) {
        for (j = i + 1; j < no->quantChaves; j++) {
            if (no->valores[j] < no->valores[i]) {
                aux = no->valores[i];
                no->valores[i] = no->valores[j];
                no->valores[j] = aux;
            }
        }
    }
}

void inserirValor(No *raiz, int valor) {
    No *aux = raiz;

    do {
        if (aux->quantChaves == 3) {
            dividir(aux);
            if (aux->pai)
                aux = aux->pai;
        }
        aux = escolheFilho(aux, valor);
    } while (!ehFolha(aux) || aux->quantChaves == 3);

    aux->valores[aux->quantChaves] = valor;
    aux->quantChaves++;
    ordenar(aux);
}

void inserir(Arvore2_3_4 *arv, int valor) {
    if (arv->raiz) {
        inserirValor(arv->raiz, valor);
    } else {
        arv->raiz = criarNo();
        arv->raiz->valores[0] = valor;
        arv->raiz->quantChaves++;
    }
}

void imprimir(No *raiz, int nivel) {
    int i;
    if (raiz) {
        for (i = 0; i < nivel; i++) {
            printf("\t");
        }
        printf("Nivel: %2d: %3d %3d %3d\n", nivel, raiz->valores[0], raiz->valores[1], raiz->valores[2]);
        i = 0;
        while (i < 4 && raiz->filhos[i]) {
            imprimir(raiz->filhos[i], nivel + 1);
            i++;
        }
    }
}

No* buscar(No *no, int valor, int nivel) {
    int i;

    if (no) {
        for (i = 0; i < no->quantChaves; i++) {
            if (no->valores[i] == valor) {
                printf("O elemento %d esta no nivel %d na posicao %d\n", valor, nivel, i);
                return no;
            } else if (valor < no->valores[i]) {
                break;
            }
        }
        return buscar(no->filhos[i], valor, nivel + 1);
    }
    printf("O elemento %d nao foi encontrado na arvore!\n", valor);
    return NULL;
}

int quantidadeChaves(No *raiz) {
    int chaves = 0;

    if (raiz) {
        chaves = raiz->quantChaves;
        for (int i = 0; i < 4; i++) {
            chaves += quantidadeChaves(raiz->filhos[i]);
        }
    }
    return chaves;
}
