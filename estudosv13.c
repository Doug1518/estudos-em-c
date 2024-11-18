#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#include <string.h>// para usar o strlen
#include <ctype.h>
// #include "pilha.h"
/*
            Aula 261: Tabela Hash com lista encadeada

            C�digo escrito por Wagner Gaspar
            Setembro de 2021
*/

// 2 * 15 = 31
#define TAM 31

typedef struct no{
    int chave;
    struct no *proximo;
}No;

typedef struct{
    No *inicio;
    int tam;
}Lista;

void inicializarLista(Lista *l){
    l->inicio = NULL;
    l->tam = 0;
}

void inserir_na_lista(Lista *l, int valor){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->chave = valor;
        novo->proximo = l->inicio;
        l->inicio = novo;
        l->tam++;
    }
    else
        printf("\n\tErro ao alocar memoria!\n");
}

int buscar_na_lista(Lista *l, int valor){
    No *aux = l->inicio;
    while(aux && aux->chave != valor)
        aux = aux->proximo;
    if(aux)
        return aux->chave;
    return 0;
}

void imprimir_lista(Lista *l){
    No *aux = l->inicio;
    printf(" Tam: %d: ", l->tam);
    while(aux){
        printf("%d ", aux->chave);
        aux = aux->proximo;
    }
}

void inicializarTabela(Lista t[]){
    int i;

    for(i = 0; i < TAM; i++)
        inicializarLista(&t[i]);
}

int funcaoHash(int chave){
    return chave % TAM;
}

void inserir(Lista t[], int valor){
    int id = funcaoHash(valor);
    inserir_na_lista(&t[id], valor);
}

int busca(Lista t[], int chave){
    int id = funcaoHash(chave);
    return buscar_na_lista(&t[id], chave);
}

void imprimir(Lista t[]){
    int i;
    for(i = 0; i < TAM; i++){
        printf("%2d = ", i);
        imprimir_lista(&t[i]);
        printf("\n");
    }
}

int main(){

    int opcao, valor, retorno;
    Lista tabela[TAM];

    inicializarTabela(tabela);

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 -Imprimir\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("\tQual valor desseja inserir? ");
            scanf("%d", &valor);
            inserir(tabela, valor);
            break;
        case 2:
            printf("\tQual valor desseja buscar? ");
            scanf("%d", &valor);
            retorno = busca(tabela, valor);
            if(retorno != 0)
                printf("\tValor encontrado: %d\n", retorno);
            else
                printf("\tValor nao encontrado!\n");
            break;
        case 3:
            imprimir(tabela);
            break;
        default:
            printf("Opcao invalida!\n");
        }
    }while(opcao != 0);

    return 0;
}



   
    /*
            Aula 260: Tabela Hash linear com vetor

            C�digo escrito por Wagner Gaspar
            Setembro de 2021


// 2 * 15 = 31
#define TAM 31

void inicializarTabela(int t[]){
    int i;

    for(i = 0; i < TAM; i++)
        t[i] = 0;
}

int funcaoHash(int chave){
    return chave % TAM;
}

void inserir(int t[], int valor){
    int id = funcaoHash(valor);
    while(t[id] != 0){
        id = funcaoHash(id + 1);
    }
    t[id] = valor;
}

int busca(int t[], int chave){
    int id = funcaoHash(chave);
    printf("\nIndice gerada: %d\n", id);
    while(t[id] != 0){
        if(t[id] == chave)
            return t[id];
        else
            id = funcaoHash(id + 1);
    }
    return 0;
}

void imprimir(int t[]){
    int i;
    for(i = 0; i < TAM; i++){
        printf("%d = %d\n", i, t[i]);
    }
}

int main(){

    int opcao, valor, retorno, tabela[TAM];

    inicializarTabela(tabela);

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 -Imprimir\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("\tQual valor desseja inserir? ");
            scanf("%d", &valor);
            inserir(tabela, valor);
            break;
        case 2:
            printf("\tQual valor desseja buscar? ");
            scanf("%d", &valor);
            retorno = busca(tabela, valor);
            if(retorno != 0)
                printf("\tValor encontrado: %d\n", retorno);
            else
                printf("\tValor nao encontrado!\n");
            break;
        case 3:
            imprimir(tabela);
            break;
        default:
            printf("Opcao invalida!\n");
        }
    }while(opcao != 0);

    return 0;
}
    
*/  
    
    
    
    
    
    /*  O que � e como funciona a estrutura de dados Tabela Hash? aula 259
        Estrutura de dados com foco em busca, tem resposta rapida

    Tamanho - quantida m�xima de elementos na tabela
    
    fun��o de espalhamento - fun��o que gera um codigo a ser ultilizado como indiace de acesso na tabela
    
    colis�es - ocorre uma colis�o quando a fun��o de espalhamento gera o mesmo codigo para chaves diferentes 
    
    fator de carga, quantidade de elementos divido pelo tamanho da tabela



    */


