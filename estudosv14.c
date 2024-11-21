#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#include <string.h>// para usar o strlen
#include <ctype.h>
// #include "pilha.h"

 

/*

                Aula 280: Dúvida: Como formar um triângulo com uma palavra?

                Palavra: fulano
                     o
                    non
                   anona
                  lanonal
                 ulanonalu
                fulanonaluf


int main(){

    char vet[] = "fulano";
    int i, j, k, m, tamanho = strlen(vet) - 1;

    for(i = tamanho; i >= 0; i--){
        // imprime espaços à esquerda
        for(j = 0; j < i; j++)
            printf(" ");
        // imprime a parte esquerda do triângulo
        for(k = i; k <= tamanho; k++)
            printf("%c", vet[k]);
        // imprime a parte direita do triângulo
        for(m = tamanho - 1; m >= i; m--)
            printf("%c", vet[m]);
        printf("\n");
    }

    return 0;
}

*/


/*
    Como comprimir dados com Código de Huffman - Algoritmo de Huffman |aula 278

    uma das diferenças entre a arvore binaria e 
    a arvore binaria de busca é que os elementos menores 
    que no raiz na  abb ficam a esquerda e os maiores ficam a direita 

    e cada no na arovre binaria so possue dos filhos
*/



/*
            Aula 277: Árvore Binária de Busca de Pessoas

            


typedef struct{
    char nome[50];
    int cpf;
}Pessoa;

typedef struct no{
    Pessoa pessoa;
    struct no *direita, *esquerda;
}NoArv;

Pessoa ler_pessoa(){
    Pessoa p;
    printf("\tDigite o nome da pessoa: ");
    fgets(p.nome, 49, stdin);
    printf("\tDigite o cpf: ");
    scanf("%d", &p.cpf);
    return p;
}

void imprimir_pessoa(Pessoa p){
    printf("\tNome: %s\tCpf: %d\n", p.nome, p.cpf);
}

NoArv* inserir_versao_1(NoArv *raiz, Pessoa p){
    if(raiz == NULL){
        NoArv *aux = malloc(sizeof(NoArv));
        aux->pessoa = p;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else{
        if(p.cpf < raiz->pessoa.cpf)
            raiz->esquerda = inserir_versao_1(raiz->esquerda, p);
        else
            raiz->direita = inserir_versao_1(raiz->direita, p);
        return raiz;
    }
}

void inserir_versao_2(NoArv **raiz, Pessoa p){
    if(*raiz == NULL){
        *raiz = malloc(sizeof(NoArv));
        (*raiz)->pessoa = p;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    }
    else{
        if(p.cpf < (*raiz)->pessoa.cpf)
            inserir_versao_2(&((*raiz)->esquerda), p);
        else
            inserir_versao_2(&((*raiz)->direita), p);
    }
}

void inserir_versao_3(NoArv **raiz, Pessoa p){
    NoArv *aux = *raiz;
    while(aux){
        if(p.cpf < aux->pessoa.cpf)
            raiz = &aux->esquerda;
        else
            raiz = &aux->direita;
        aux = *raiz;
    }
    aux = malloc(sizeof(NoArv));
    aux->pessoa = p;
    aux->esquerda = NULL;
    aux->direita = NULL;
    *raiz = aux;
}

NoArv* buscar_versao_1(NoArv *raiz, int cpf){
    if(raiz){
        if(cpf == raiz->pessoa.cpf)
            return raiz;
        else if(cpf < raiz->pessoa.cpf)
            return buscar_versao_1(raiz->esquerda, cpf);
        else
            return buscar_versao_1(raiz->direita, cpf);
    }
    return NULL;
}

NoArv* buscar_versao_2(NoArv *raiz, int cpf){
    while(raiz){
        if(cpf < raiz->pessoa.cpf)
            raiz = raiz->esquerda;
        else if(cpf > raiz->pessoa.cpf)
            raiz = raiz->direita;
        else
            return raiz;
    }
    return NULL;
}

int altura(NoArv *raiz){
    if(raiz == NULL){
        return -1;
    }
    else{
        int esq = altura(raiz->esquerda);
        int dir = altura(raiz->direita);
        if(esq > dir)
            return esq + 1;
        else
            return dir + 1;
    }
}

int quantidade_nos(NoArv *raiz){
    if(raiz == NULL)
        return 0;
    else
        return 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);

    // operador ternário
    //return (raiz == NULL)? 0: 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);
}

int quantidade_folhas(NoArv *raiz){
    if(raiz == NULL)
        return 0;
    else if(raiz->esquerda == NULL && raiz->direita == NULL)
        return 1;
    else
        return quantidade_folhas(raiz->esquerda) + quantidade_folhas(raiz->direita);
}

// função para remover nós da Árvore binária
NoArv* remover(NoArv *raiz, int chave) {
    if(raiz == NULL){
        printf("Valor nao encontrado!\n");
        return NULL;
    } else { // procura o nó a remover
        if(raiz->pessoa.cpf == chave) {
            // remove nós folhas (nós sem filhos)
            if(raiz->esquerda == NULL && raiz->direita == NULL) {
                free(raiz);
                printf("Elemento folha removido: %d !\n", chave);
                return NULL;
            }
            else{
                // remover nós que possuem 2 filhos
                if(raiz->esquerda != NULL && raiz->direita != NULL){
                    Pessoa p;
                    NoArv *aux = raiz->esquerda;
                    while(aux->direita != NULL)
                        aux = aux->direita;
                    p = raiz->pessoa;
                    raiz->pessoa = aux->pessoa;
                    aux->pessoa = p;
                    printf("Elemento trocado: %d !\n", chave);
                    raiz->esquerda = remover(raiz->esquerda, chave);
                    return raiz;
                }
                else{
                    // remover nós que possuem apenas 1 filho
                    NoArv *aux;
                    if(raiz->esquerda != NULL)
                        aux = raiz->esquerda;
                    else
                        aux = raiz->direita;
                    free(raiz);
                    printf("Elemento com 1 filho removido: %d !\n", chave);
                    return aux;
                }
            }
        } else {
            if(chave < raiz->pessoa.cpf)
                raiz->esquerda = remover(raiz->esquerda, chave);
            else
                raiz->direita = remover(raiz->direita, chave);
            return raiz;
        }
    }
}

void imprimir_versao_1(NoArv *raiz){ // 50 25 30 100
    if(raiz){
        imprimir_pessoa(raiz->pessoa);
        imprimir_versao_1(raiz->esquerda);
        imprimir_versao_1(raiz->direita);
    }
}

void imprimir_versao_2(NoArv *raiz){ // 25 30 50 100
    if(raiz){
        imprimir_versao_2(raiz->esquerda);
        imprimir_pessoa(raiz->pessoa);
        imprimir_versao_2(raiz->direita);
    }
}

int main(){

    NoArv *busca, *raiz = NULL;
    int opcao, valor;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Buscar\n\t4 - Altura\n\t5 - Tamanho\n\t6 - Folhas\n\t7 - Remover\n");
        scanf("%d", &opcao);
        scanf("%c");

        switch(opcao){
        case 1:
            //printf("\n\tDigite um valor: ");
            //scanf("%d", &valor);
            //raiz = inserir_versao_1(raiz, valor);
            //inserir_versao_2(&raiz, valor);
            inserir_versao_3(&raiz, ler_pessoa());
            break;
        case 2:
            printf("\n\tPrimeira impressao:\n\t");
            imprimir_versao_1(raiz);
            printf("\n");
            printf("\n\tSegunda impressao:\n\t");
            imprimir_versao_2(raiz);
            printf("\n");
            break;
        case 3:
            printf("\n\tDigite o cpf a ser procurado: ");
            scanf("%d", &valor);
            //busca = buscar_versao_1(raiz, valor);
            busca = buscar_versao_2(raiz, valor);
            if(busca){
                printf("\n\tValor encontrado:\n");
                imprimir_pessoa(busca->pessoa);
            }
            else
                printf("\n\tValor nao encontrado!\n");
            break;
        case 4:
            printf("\n\tAltura da arvore: %d\n\n", altura(raiz));
            break;
        case 5:
            printf("\n\tQuantidade de nos: %d\n", quantidade_nos(raiz));
            break;
        case 6:
            printf("\n\tQuantidade folhas: %d\n", quantidade_folhas(raiz));
            break;
        case 7:
            printf("\t");
            imprimir_versao_2(raiz);
            printf("\n\tDigite o cpf a ser removido: ");
            scanf("%d", &valor);
            raiz = remover(raiz, valor);
            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}
*/
/*
            Aula 276: Como remover um nó com 2 filhos em uma Árvore Binária?



typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NoArv;

NoArv* inserir_versao_1(NoArv *raiz, int num){
    if(raiz == NULL){
        NoArv *aux = malloc(sizeof(NoArv));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else{
        if(num < raiz->valor)
            raiz->esquerda = inserir_versao_1(raiz->esquerda, num);
        else
            raiz->direita = inserir_versao_1(raiz->direita, num);
        return raiz;
    }
}

void inserir_versao_2(NoArv **raiz, int num){
    if(*raiz == NULL){
        *raiz = malloc(sizeof(NoArv));
        (*raiz)->valor = num;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    }
    else{
        if(num < (*raiz)->valor)
            inserir_versao_2(&((*raiz)->esquerda), num);
        else
            inserir_versao_2(&((*raiz)->direita), num);
    }
}

void inserir_versao_3(NoArv **raiz, int num){
    NoArv *aux = *raiz;
    while(aux){
        if(num < aux->valor)
            raiz = &aux->esquerda;
        else
            raiz = &aux->direita;
        aux = *raiz;
    }
    aux = malloc(sizeof(NoArv));
    aux->valor = num;
    aux->esquerda = NULL;
    aux->direita = NULL;
    *raiz = aux;
}

NoArv* buscar_versao_1(NoArv *raiz, int num){
    if(raiz){
        if(num == raiz->valor)
            return raiz;
        else if(num < raiz->valor)
            return buscar_versao_1(raiz->esquerda, num);
        else
            return buscar_versao_1(raiz->direita, num);
    }
    return NULL;
}

NoArv* buscar_versao_2(NoArv *raiz, int num){
    while(raiz){
        if(num < raiz->valor)
            raiz = raiz->esquerda;
        else if(num > raiz->valor)
            raiz = raiz->direita;
        else
            return raiz;
    }
    return NULL;
}

int altura(NoArv *raiz){
    if(raiz == NULL){
        return -1;
    }
    else{
        int esq = altura(raiz->esquerda);
        int dir = altura(raiz->direita);
        if(esq > dir)
            return esq + 1;
        else
            return dir + 1;
    }
}

int quantidade_nos(NoArv *raiz){
    if(raiz == NULL)
        return 0;
    else
        return 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);

    // operador ternÃ¡rio
    //return (raiz == NULL)? 0: 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);
}

int quantidade_folhas(NoArv *raiz){
    if(raiz == NULL)
        return 0;
    else if(raiz->esquerda == NULL && raiz->direita == NULL)
        return 1;
    else
        return quantidade_folhas(raiz->esquerda) + quantidade_folhas(raiz->direita);
}

// função para remover nós da Árvore binária
NoArv* remover(NoArv *raiz, int chave) {
    if(raiz == NULL){
        printf("Valor nao encontrado!\n");
        return NULL;
    } else { // procura o nó a remover
        if(raiz->valor == chave) {
            // remove nós folhas (nós sem filhos)
            if(raiz->esquerda == NULL && raiz->direita == NULL) {
                free(raiz);
                printf("Elemento folha removido: %d !\n", chave);
                return NULL;
            }
            else{
                // remover nós que possuem 2 filhos
                if(raiz->esquerda != NULL && raiz->direita != NULL){
                    NoArv *aux = raiz->esquerda;
                    while(aux->direita != NULL)
                        aux = aux->direita;
                    raiz->valor = aux->valor;
                    aux->valor = chave;
                    printf("Elemento trocado: %d !\n", chave);
                    raiz->esquerda = remover(raiz->esquerda, chave);
                    return raiz;
                }
                else{
                    // remover nós que possuem apenas 1 filho
                    NoArv *aux;
                    if(raiz->esquerda != NULL)
                        aux = raiz->esquerda;
                    else
                        aux = raiz->direita;
                    free(raiz);
                    printf("Elemento com 1 filho removido: %d !\n", chave);
                    return aux;
                }
            }
        } else {
            if(chave < raiz->valor)
                raiz->esquerda = remover(raiz->esquerda, chave);
            else
                raiz->direita = remover(raiz->direita, chave);
            return raiz;
        }
    }
}

void imprimir_versao_1(NoArv *raiz){
    if(raiz){
        printf("%d ", raiz->valor);
        imprimir_versao_1(raiz->esquerda);
        imprimir_versao_1(raiz->direita);
    }
}

void imprimir_versao_2(NoArv *raiz){
    if(raiz){
        imprimir_versao_2(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir_versao_2(raiz->direita);
    }
}

int main(){

    NoArv *busca, *raiz = NULL;
    int opcao, valor;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Buscar\n\t4 - Altura\n\t5 - Tamanho\n\t6 - Folhas\n\t7 - Remover\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("\n\tDigite um valor: ");
            scanf("%d", &valor);
            //raiz = inserir_versao_1(raiz, valor);
            //inserir_versao_2(&raiz, valor);
            inserir_versao_3(&raiz, valor);
            break;
        case 2:
            printf("\n\tPrimeira impressao:\n\t");
            imprimir_versao_1(raiz);
            printf("\n");
            printf("\n\tSegunda impressao:\n\t");
            imprimir_versao_2(raiz);
            printf("\n");
            break;
        case 3:
            printf("\n\tDigite o valor a ser procurado: ");
            scanf("%d", &valor);
            //busca = buscar_versao_1(raiz, valor);
            busca = buscar_versao_2(raiz, valor);
            if(busca)
                printf("\n\tValor encontrado: %d\n", busca->valor);
            else
                printf("\n\tValor nao encontrado!\n");
            break;
        case 4:
            printf("\n\tAltura da arvore: %d\n\n", altura(raiz));
            break;
        case 5:
            printf("\n\tQuantidade de nos: %d\n", quantidade_nos(raiz));
            break;
        case 6:
            printf("\n\tQuantidade folhas: %d\n", quantidade_folhas(raiz));
            break;
        case 7:
            printf("\t");
            imprimir_versao_2(raiz);
            printf("\n\tDigite o valor a ser removido: ");
            scanf("%d", &valor);
            raiz = remover(raiz, valor);
            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}

*/

/*
            Aula 275: Como remover um nó com 1 filho em uma Árvore Binária?

            


typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NoArv;

NoArv* inserir_versao_1(NoArv *raiz, int num){
    if(raiz == NULL){
        NoArv *aux = malloc(sizeof(NoArv));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else{
        if(num < raiz->valor)
            raiz->esquerda = inserir_versao_1(raiz->esquerda, num);
        else
            raiz->direita = inserir_versao_1(raiz->direita, num);
        return raiz;
    }
}

void inserir_versao_2(NoArv **raiz, int num){
    if(*raiz == NULL){
        *raiz = malloc(sizeof(NoArv));
        (*raiz)->valor = num;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    }
    else{
        if(num < (*raiz)->valor)
            inserir_versao_2(&((*raiz)->esquerda), num);
        else
            inserir_versao_2(&((*raiz)->direita), num);
    }
}

void inserir_versao_3(NoArv **raiz, int num){
    NoArv *aux = *raiz;
    while(aux){
        if(num < aux->valor)
            raiz = &aux->esquerda;
        else
            raiz = &aux->direita;
        aux = *raiz;
    }
    aux = malloc(sizeof(NoArv));
    aux->valor = num;
    aux->esquerda = NULL;
    aux->direita = NULL;
    *raiz = aux;
}

NoArv* buscar_versao_1(NoArv *raiz, int num){
    if(raiz){
        if(num == raiz->valor)
            return raiz;
        else if(num < raiz->valor)
            return buscar_versao_1(raiz->esquerda, num);
        else
            return buscar_versao_1(raiz->direita, num);
    }
    return NULL;
}

NoArv* buscar_versao_2(NoArv *raiz, int num){
    while(raiz){
        if(num < raiz->valor)
            raiz = raiz->esquerda;
        else if(num > raiz->valor)
            raiz = raiz->direita;
        else
            return raiz;
    }
    return NULL;
}

int altura(NoArv *raiz){
    if(raiz == NULL){
        return -1;
    }
    else{
        int esq = altura(raiz->esquerda);
        int dir = altura(raiz->direita);
        if(esq > dir)
            return esq + 1;
        else
            return dir + 1;
    }
}

int quantidade_nos(NoArv *raiz){
    if(raiz == NULL)
        return 0;
    else
        return 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);

    // operador ternÃ¡rio
    //return (raiz == NULL)? 0: 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);
}

int quantidade_folhas(NoArv *raiz){
    if(raiz == NULL)
        return 0;
    else if(raiz->esquerda == NULL && raiz->direita == NULL)
        return 1;
    else
        return quantidade_folhas(raiz->esquerda) + quantidade_folhas(raiz->direita);
}

// função para remover nós da Árvore binária
NoArv* remover(NoArv *raiz, int chave) {
    if(raiz == NULL){
        printf("Valor nao encontrado!\n");
        return NULL;
    } else { // procura o nó a remover
        if(raiz->valor == chave) {
            // remove nós folhas (nós sem filhos)
            if(raiz->esquerda == NULL && raiz->direita == NULL) {
                free(raiz);
                printf("Elemento folha removido: %d !\n", chave);
                return NULL;
            }
            else{
                // remover nós que possuem 2 filhos
                if(raiz->esquerda != NULL && raiz->direita != NULL){

                }
                else{
                    // remover nós que possuem apenas 1 filho
                    NoArv *aux;
                    if(raiz->esquerda != NULL)
                        aux = raiz->esquerda;
                    else
                        aux = raiz->direita;
                    free(raiz);
                    printf("Elemento com 1 filho removido: %d !\n", chave);
                    return aux;
                }
            }
        } else {
            if(chave < raiz->valor)
                raiz->esquerda = remover(raiz->esquerda, chave);
            else
                raiz->direita = remover(raiz->direita, chave);
            return raiz;
        }
    }
}

void imprimir_versao_1(NoArv *raiz){
    if(raiz){
        printf("%d ", raiz->valor);
        imprimir_versao_1(raiz->esquerda);
        imprimir_versao_1(raiz->direita);
    }
}

void imprimir_versao_2(NoArv *raiz){
    if(raiz){
        imprimir_versao_2(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir_versao_2(raiz->direita);
    }
}

int main(){

    NoArv *busca, *raiz = NULL;
    int opcao, valor;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Buscar\n\t4 - Altura\n\t5 - Tamanho\n\t6 - Folhas\n\t7 - Remover\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("\n\tDigite um valor: ");
            scanf("%d", &valor);
            //raiz = inserir_versao_1(raiz, valor);
            //inserir_versao_2(&raiz, valor);
            inserir_versao_3(&raiz, valor);
            break;
        case 2:
            printf("\n\tPrimeira impressao:\n\t");
            imprimir_versao_1(raiz);
            printf("\n");
            printf("\n\tSegunda impressao:\n\t");
            imprimir_versao_2(raiz);
            printf("\n");
            break;
        case 3:
            printf("\n\tDigite o valor a ser procurado: ");
            scanf("%d", &valor);
            //busca = buscar_versao_1(raiz, valor);
            busca = buscar_versao_2(raiz, valor);
            if(busca)
                printf("\n\tValor encontrado: %d\n", busca->valor);
            else
                printf("\n\tValor nao encontrado!\n");
            break;
        case 4:
            printf("\n\tAltura da arvore: %d\n\n", altura(raiz));
            break;
        case 5:
            printf("\n\tQuantidade de nos: %d\n", quantidade_nos(raiz));
            break;
        case 6:
            printf("\n\tQuantidade folhas: %d\n", quantidade_folhas(raiz));
            break;
        case 7:
            printf("\t");
            imprimir_versao_2(raiz);
            printf("\n\tDigite o valor a ser removido: ");
            scanf("%d", &valor);
            raiz = remover(raiz, valor);
            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}

*/

/*
            Aula 274: Como remover um nó FOLHA de uma Árvore Binária?

            


typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NoArv;

NoArv* inserir_versao_1(NoArv *raiz, int num){
    if(raiz == NULL){
        NoArv *aux = malloc(sizeof(NoArv));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else{
        if(num < raiz->valor)
            raiz->esquerda = inserir_versao_1(raiz->esquerda, num);
        else
            raiz->direita = inserir_versao_1(raiz->direita, num);
        return raiz;
    }
}

void inserir_versao_2(NoArv **raiz, int num){
    if(*raiz == NULL){
        *raiz = malloc(sizeof(NoArv));
        (*raiz)->valor = num;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    }
    else{
        if(num < (*raiz)->valor)
            inserir_versao_2(&((*raiz)->esquerda), num);
        else
            inserir_versao_2(&((*raiz)->direita), num);
    }
}

void inserir_versao_3(NoArv **raiz, int num){
    NoArv *aux = *raiz;
    while(aux){
        if(num < aux->valor)
            raiz = &aux->esquerda;
        else
            raiz = &aux->direita;
        aux = *raiz;
    }
    aux = malloc(sizeof(NoArv));
    aux->valor = num;
    aux->esquerda = NULL;
    aux->direita = NULL;
    *raiz = aux;
}

NoArv* buscar_versao_1(NoArv *raiz, int num){
    if(raiz){
        if(num == raiz->valor)
            return raiz;
        else if(num < raiz->valor)
            return buscar_versao_1(raiz->esquerda, num);
        else
            return buscar_versao_1(raiz->direita, num);
    }
    return NULL;
}

NoArv* buscar_versao_2(NoArv *raiz, int num){
    while(raiz){
        if(num < raiz->valor)
            raiz = raiz->esquerda;
        else if(num > raiz->valor)
            raiz = raiz->direita;
        else
            return raiz;
    }
    return NULL;
}

int altura(NoArv *raiz){
    if(raiz == NULL){
        return -1;
    }
    else{
        int esq = altura(raiz->esquerda);
        int dir = altura(raiz->direita);
        if(esq > dir)
            return esq + 1;
        else
            return dir + 1;
    }
}

int quantidade_nos(NoArv *raiz){
    if(raiz == NULL)
        return 0;
    else
        return 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);

    // operador ternÃ¡rio
    //return (raiz == NULL)? 0: 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);
}

int quantidade_folhas(NoArv *raiz){
    if(raiz == NULL)
        return 0;
    else if(raiz->esquerda == NULL && raiz->direita == NULL)
        return 1;
    else
        return quantidade_folhas(raiz->esquerda) + quantidade_folhas(raiz->direita);
}

// função para remover nós da Árvore binária
NoArv* remover(NoArv *raiz, int chave) {
    if(raiz == NULL){
        printf("Valor nao encontrado!\n");
        return NULL;
    } else { // procura o nó a remover
        if(raiz->valor == chave) {
            // remove nós folhas (nós sem filhos)
            if(raiz->esquerda == NULL && raiz->direita == NULL) {
                free(raiz);
                printf("Elemento folha removido: %d !\n", chave);
                return NULL;
            }
            else{
                // remover nós que possuem 1 ou 2 filhos
            }
        } else {
            if(chave < raiz->valor)
                raiz->esquerda = remover(raiz->esquerda, chave);
            else
                raiz->direita = remover(raiz->direita, chave);
            return raiz;
        }
    }
}

void imprimir_versao_1(NoArv *raiz){
    if(raiz){
        printf("%d ", raiz->valor);
        imprimir_versao_1(raiz->esquerda);
        imprimir_versao_1(raiz->direita);
    }
}

void imprimir_versao_2(NoArv *raiz){
    if(raiz){
        imprimir_versao_2(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir_versao_2(raiz->direita);
    }
}

int main(){

    NoArv *busca, *raiz = NULL;
    int opcao, valor;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Buscar\n\t4 - Altura\n\t5 - Tamanho\n\t6 - Folhas\n\t7 - Remover\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("\n\tDigite um valor: ");
            scanf("%d", &valor);
            //raiz = inserir_versao_1(raiz, valor);
            //inserir_versao_2(&raiz, valor);
            inserir_versao_3(&raiz, valor);
            break;
        case 2:
            printf("\n\tPrimeira impressao:\n\t");
            imprimir_versao_1(raiz);
            printf("\n");
            printf("\n\tSegunda impressao:\n\t");
            imprimir_versao_2(raiz);
            printf("\n");
            break;
        case 3:
            printf("\n\tDigite o valor a ser procurado: ");
            scanf("%d", &valor);
            //busca = buscar_versao_1(raiz, valor);
            busca = buscar_versao_2(raiz, valor);
            if(busca)
                printf("\n\tValor encontrado: %d\n", busca->valor);
            else
                printf("\n\tValor nao encontrado!\n");
            break;
        case 4:
            printf("\n\tAltura da arvore: %d\n\n", altura(raiz));
            break;
        case 5:
            printf("\n\tQuantidade de nos: %d\n", quantidade_nos(raiz));
            break;
        case 6:
            printf("\n\tQuantidade folhas: %d\n", quantidade_folhas(raiz));
            break;
        case 7:
            printf("\t");
            imprimir_versao_2(raiz);
            printf("\n\tDigite o valor a ser removido: ");
            scanf("%d", &valor);
            raiz = remover(raiz, valor);
            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}

*/

/*
            Aula 273: Como contar a quantidade de FOLHAS de uma Árvore Binária?

            


typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NoArv;

NoArv* inserir_versao_1(NoArv *raiz, int num){
    if(raiz == NULL){
        NoArv *aux = malloc(sizeof(NoArv));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else{
        if(num < raiz->valor)
            raiz->esquerda = inserir_versao_1(raiz->esquerda, num);
        else
            raiz->direita = inserir_versao_1(raiz->direita, num);
        return raiz;
    }
}

void inserir_versao_2(NoArv **raiz, int num){
    if(*raiz == NULL){
        *raiz = malloc(sizeof(NoArv));
        (*raiz)->valor = num;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    }
    else{
        if(num < (*raiz)->valor)
            inserir_versao_2(&((*raiz)->esquerda), num);
        else
            inserir_versao_2(&((*raiz)->direita), num);
    }
}

void inserir_versao_3(NoArv **raiz, int num){
    NoArv *aux = *raiz;
    while(aux){
        if(num < aux->valor)
            raiz = &aux->esquerda;
        else
            raiz = &aux->direita;
        aux = *raiz;
    }
    aux = malloc(sizeof(NoArv));
    aux->valor = num;
    aux->esquerda = NULL;
    aux->direita = NULL;
    *raiz = aux;
}

NoArv* buscar_versao_1(NoArv *raiz, int num){
    if(raiz){
        if(num == raiz->valor)
            return raiz;
        else if(num < raiz->valor)
            return buscar_versao_1(raiz->esquerda, num);
        else
            return buscar_versao_1(raiz->direita, num);
    }
    return NULL;
}

NoArv* buscar_versao_2(NoArv *raiz, int num){
    while(raiz){
        if(num < raiz->valor)
            raiz = raiz->esquerda;
        else if(num > raiz->valor)
            raiz = raiz->direita;
        else
            return raiz;
    }
    return NULL;
}

int altura(NoArv *raiz){
    if(raiz == NULL){
        return -1;
    }
    else{
        int esq = altura(raiz->esquerda);
        int dir = altura(raiz->direita);
        if(esq > dir)
            return esq + 1;
        else
            return dir + 1;
    }
}

int quantidade_nos(NoArv *raiz){
    if(raiz == NULL)
        return 0;
    else
        return 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);

    // operador ternário
    //return (raiz == NULL)? 0: 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);
}

int quantidade_folhas(NoArv *raiz){
    if(raiz == NULL)
        return 0;
    else if(raiz->esquerda == NULL && raiz->direita == NULL)
        return 1;
    else
        return quantidade_folhas(raiz->esquerda) + quantidade_folhas(raiz->direita);
}

void imprimir_versao_1(NoArv *raiz){
    if(raiz){
        printf("%d ", raiz->valor);
        imprimir_versao_1(raiz->esquerda);
        imprimir_versao_1(raiz->direita);
    }
}

void imprimir_versao_2(NoArv *raiz){
    if(raiz){
        imprimir_versao_2(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir_versao_2(raiz->direita);
    }
}

int main(){

    NoArv *busca, *raiz = NULL;
    int opcao, valor;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Buscar\n\t4 - Altura\n\t5 - Tamanho\n\t6 - Folhas\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("\n\tDigite um valor: ");
            scanf("%d", &valor);
            //raiz = inserir_versao_1(raiz, valor);
            //inserir_versao_2(&raiz, valor);
            inserir_versao_3(&raiz, valor);
            break;
        case 2:
            printf("\n\tPrimeira impressao:\n\t");
            imprimir_versao_1(raiz);
            printf("\n");
            printf("\n\tSegunda impressao:\n\t");
            imprimir_versao_2(raiz);
            printf("\n");
            break;
        case 3:
            printf("\n\tDigite o valor a ser procurado: ");
            scanf("%d", &valor);
            //busca = buscar_versao_1(raiz, valor);
            busca = buscar_versao_2(raiz, valor);
            if(busca)
                printf("\n\tValor encontrado: %d\n", busca->valor);
            else
                printf("\n\tValor nao encontrado!\n");
            break;
        case 4:
            printf("\n\tAltura da arvore: %d\n\n", altura(raiz));
            break;
        case 5:
            printf("\n\tQuantidade de nos: %d\n", quantidade_nos(raiz));
            break;
        case 6:
            printf("\n\tQuantidade folhas: %d\n", quantidade_folhas(raiz));
            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}

*/

/*
            Aula 272: Como contar a quantidade de nós de uma Árvore Binária?

            


typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NoArv;

NoArv* inserir_versao_1(NoArv *raiz, int num){
    if(raiz == NULL){
        NoArv *aux = malloc(sizeof(NoArv));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else{
        if(num < raiz->valor)
            raiz->esquerda = inserir_versao_1(raiz->esquerda, num);
        else
            raiz->direita = inserir_versao_1(raiz->direita, num);
        return raiz;
    }
}

void inserir_versao_2(NoArv **raiz, int num){
    if(*raiz == NULL){
        *raiz = malloc(sizeof(NoArv));
        (*raiz)->valor = num;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    }
    else{
        if(num < (*raiz)->valor)
            inserir_versao_2(&((*raiz)->esquerda), num);
        else
            inserir_versao_2(&((*raiz)->direita), num);
    }
}

void inserir_versao_3(NoArv **raiz, int num){
    NoArv *aux = *raiz;
    while(aux){
        if(num < aux->valor)
            raiz = &aux->esquerda;
        else
            raiz = &aux->direita;
        aux = *raiz;
    }
    aux = malloc(sizeof(NoArv));
    aux->valor = num;
    aux->esquerda = NULL;
    aux->direita = NULL;
    *raiz = aux;
}

NoArv* buscar_versao_1(NoArv *raiz, int num){
    if(raiz){
        if(num == raiz->valor)
            return raiz;
        else if(num < raiz->valor)
            return buscar_versao_1(raiz->esquerda, num);
        else
            return buscar_versao_1(raiz->direita, num);
    }
    return NULL;
}

NoArv* buscar_versao_2(NoArv *raiz, int num){
    while(raiz){
        if(num < raiz->valor)
            raiz = raiz->esquerda;
        else if(num > raiz->valor)
            raiz = raiz->direita;
        else
            return raiz;
    }
    return NULL;
}

int altura(NoArv *raiz){
    if(raiz == NULL){
        return -1;
    }
    else{
        int esq = altura(raiz->esquerda);
        int dir = altura(raiz->direita);
        if(esq > dir)
            return esq + 1;
        else
            return dir + 1;
    }
}

int quantidade_nos(NoArv *raiz){
    if(raiz == NULL)
        return 0;
    else
        return 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);

    // operador ternário
    //return (raiz == NULL)? 0: 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);
}

void imprimir_versao_1(NoArv *raiz){
    if(raiz){
        printf("%d ", raiz->valor);
        imprimir_versao_1(raiz->esquerda);
        imprimir_versao_1(raiz->direita);
    }
}

void imprimir_versao_2(NoArv *raiz){
    if(raiz){
        imprimir_versao_2(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir_versao_2(raiz->direita);
    }
}

int main(){

    NoArv *busca, *raiz = NULL;
    int opcao, valor;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Buscar\n\t4 - Altura\n\t5 - Tamanho\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("\n\tDigite um valor: ");
            scanf("%d", &valor);
            //raiz = inserir_versao_1(raiz, valor);
            //inserir_versao_2(&raiz, valor);
            inserir_versao_3(&raiz, valor);
            break;
        case 2:
            printf("\n\tPrimeira impressao:\n\t");
            imprimir_versao_1(raiz);
            printf("\n");
            printf("\n\tSegunda impressao:\n\t");
            imprimir_versao_2(raiz);
            printf("\n");
            break;
        case 3:
            printf("\n\tDigite o valor a ser procurado: ");
            scanf("%d", &valor);
            //busca = buscar_versao_1(raiz, valor);
            busca = buscar_versao_2(raiz, valor);
            if(busca)
                printf("\n\tValor encontrado: %d\n", busca->valor);
            else
                printf("\n\tValor nao encontrado!\n");
            break;
        case 4:
            printf("\n\tAltura da arvore: %d\n\n", altura(raiz));
            break;
        case 5:
            printf("\nQuantidade de nos: %d\n", quantidade_nos(raiz));
            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}

*/

/*
            Aula 271: Como calcular a ALTURA uma Árvore Binária?

            lembrar das aresta/pontes/ponteiros isso diz a altura da arvore



typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NoArv;

NoArv* inserir_versao_1(NoArv *raiz, int num){
    if(raiz == NULL){
        NoArv *aux = malloc(sizeof(NoArv));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else{
        if(num < raiz->valor)
            raiz->esquerda = inserir_versao_1(raiz->esquerda, num);
        else
            raiz->direita = inserir_versao_1(raiz->direita, num);
        return raiz;
    }
}

void inserir_versao_2(NoArv **raiz, int num){
    if(*raiz == NULL){
        *raiz = malloc(sizeof(NoArv));
        (*raiz)->valor = num;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    }
    else{
        if(num < (*raiz)->valor)
            inserir_versao_2(&((*raiz)->esquerda), num);
        else
            inserir_versao_2(&((*raiz)->direita), num);
    }
}

void inserir_versao_3(NoArv **raiz, int num){ // 500
    NoArv *aux = *raiz;
    while(aux){
        if(num < aux->valor)
            raiz = &aux->esquerda;
        else
            raiz = &aux->direita;
        aux = *raiz;
    }
    aux = malloc(sizeof(NoArv));
    aux->valor = num;
    aux->esquerda = NULL;
    aux->direita = NULL;
    *raiz = aux;
}

NoArv* buscar_versao_1(NoArv *raiz, int num){ // 500 700 850 1000 1500
    if(raiz){
        if(num == raiz->valor)
            return raiz;
        else if(num < raiz->valor)
            return buscar_versao_1(raiz->esquerda, num);
        else
            return buscar_versao_1(raiz->direita, num);
    }
    return NULL;
}

NoArv* buscar_versao_2(NoArv *raiz, int num){
    while(raiz){
        if(num < raiz->valor)
            raiz = raiz->esquerda;
        else if(num > raiz->valor)
            raiz = raiz->direita;
        else
            return raiz;
    }
    return NULL;
}

int altura(NoArv *raiz){
    if(raiz == NULL){
        return -1;// tem que ser -1 porque se a arvore estiver com apenas um no vai somar com 1 e resultar em zero que é altura da arvore quando se somente o no raiz
    }
    else{
        int esq = altura(raiz->esquerda);
        int dir = altura(raiz->direita);
        if(esq > dir)
            return esq + 1;
        else
            return dir + 1;
    }
}

void imprimir_versao_1(NoArv *raiz){
    if(raiz){
        printf("%d ", raiz->valor);
        imprimir_versao_1(raiz->esquerda);
        imprimir_versao_1(raiz->direita);
    }
}

void imprimir_versao_2(NoArv *raiz){
    if(raiz){
        imprimir_versao_2(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir_versao_2(raiz->direita);
    }
}

int main(){

    NoArv *busca, *raiz = NULL;
    int opcao, valor;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Buscar\n\t4 - Altura\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("\n\tDigite um valor: ");
            scanf("%d", &valor);
            //raiz = inserir_versao_1(raiz, valor);
            //inserir_versao_2(&raiz, valor);
            inserir_versao_3(&raiz, valor);
            break;
        case 2:
            printf("\n\tPrimeira impressao:\n\t");
            imprimir_versao_1(raiz);
            printf("\n");
            printf("\n\tSegunda impressao:\n\t");
            imprimir_versao_2(raiz);
            printf("\n");
            break;
        case 3:
            printf("\n\tDigite o valor a ser procurado: ");
            scanf("%d", &valor);
            //busca = buscar_versao_1(raiz, valor);
            busca = buscar_versao_2(raiz, valor);
            if(busca)
                printf("\n\tValor encontrado: %d\n", busca->valor);
            else
                printf("\n\tValor nao encontrado!\n");
            break;
        case 4:
            printf("\n\tAltura da arvore: %d\n\n", altura(raiz));
            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}

*/





/*
            Aula 270: Como BUSCAR em uma Árvore Binária de Busca?
            VERSÃO ITERATIVA

           


typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NoArv;

NoArv* inserir_versao_1(NoArv *raiz, int num){
    if(raiz == NULL){
        NoArv *aux = malloc(sizeof(NoArv));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else{
        if(num < raiz->valor)
            raiz->esquerda = inserir_versao_1(raiz->esquerda, num);
        else
            raiz->direita = inserir_versao_1(raiz->direita, num);
        return raiz;
    }
}

void inserir_versao_2(NoArv **raiz, int num){
    if(*raiz == NULL){
        *raiz = malloc(sizeof(NoArv));
        (*raiz)->valor = num;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    }
    else{
        if(num < (*raiz)->valor)
            inserir_versao_2(&((*raiz)->esquerda), num);
        else
            inserir_versao_2(&((*raiz)->direita), num);
    }
}

void inserir_versao_3(NoArv **raiz, int num){
    NoArv *aux = *raiz;
    while(aux){
        if(num < aux->valor)
            raiz = &aux->esquerda;
        else
            raiz = &aux->direita;
        aux = *raiz;
    }
    aux = malloc(sizeof(NoArv));
    aux->valor = num;
    aux->esquerda = NULL;
    aux->direita = NULL;
    *raiz = aux;
}

NoArv* buscar_versao_1(NoArv *raiz, int num){
    if(raiz){
        if(num == raiz->valor)
            return raiz;
        else if(num < raiz->valor)
            return buscar_versao_1(raiz->esquerda, num);
        else
            return buscar_versao_1(raiz->direita, num);
    }
    return NULL;
}

NoArv* buscar_versao_2(NoArv *raiz, int num){
    while(raiz){
        if(num < raiz->valor)
            raiz = raiz->esquerda;
        else if(num > raiz->valor)
            raiz = raiz->direita;
        else
            return raiz;
    }
    return NULL;
}

void imprimir_versao_1(NoArv *raiz){
    if(raiz){
        printf("%d ", raiz->valor);
        imprimir_versao_1(raiz->esquerda);
        imprimir_versao_1(raiz->direita);
    }
}

void imprimir_versao_2(NoArv *raiz){
    if(raiz){
        imprimir_versao_2(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir_versao_2(raiz->direita);
    }
}

int main(){

    NoArv *busca, *raiz = NULL;
    int opcao, valor;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Buscar\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("\n\tDigite um valor: ");
            scanf("%d", &valor);
            //raiz = inserir_versao_1(raiz, valor);
            //inserir_versao_2(&raiz, valor);
            inserir_versao_3(&raiz, valor);
            break;
        case 2:
            printf("\n\tPrimeira impressao:\n\t");
            imprimir_versao_1(raiz);
            printf("\n");
            printf("\n\tSegunda impressao:\n\t");
            imprimir_versao_2(raiz);
            printf("\n");
            break;
        case 3:
            printf("\n\tDigite o valor a ser procurado: ");
            scanf("%d", &valor);
            //busca = buscar_versao_1(raiz, valor);
            busca = buscar_versao_2(raiz, valor);
            if(busca)
                printf("\n\tValor encontrado: %d\n", busca->valor);
            else
                printf("\n\tValor nao encontrado!\n");
            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}

*/






/*
            Aula 269: Como BUSCAR em uma Árvore Binária de Busca?
            VERSÃO RECURSIVA

           


typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NoArv;

NoArv* inserir_versao_1(NoArv *raiz, int num){
    if(raiz == NULL){
        NoArv *aux = malloc(sizeof(NoArv));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else{
        if(num < raiz->valor)
            raiz->esquerda = inserir_versao_1(raiz->esquerda, num);
        else
            raiz->direita = inserir_versao_1(raiz->direita, num);
        return raiz;
    }
}

void inserir_versao_2(NoArv **raiz, int num){
    if(*raiz == NULL){
        *raiz = malloc(sizeof(NoArv));
        (*raiz)->valor = num;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    }
    else{
        if(num < (*raiz)->valor)
            inserir_versao_2(&((*raiz)->esquerda), num);
        else
            inserir_versao_2(&((*raiz)->direita), num);
    }
}

void inserir_versao_3(NoArv **raiz, int num){
    NoArv *aux = *raiz;
    while(aux){
        if(num < aux->valor)
            raiz = &aux->esquerda;
        else
            raiz = &aux->direita;
        aux = *raiz;
    }
    aux = malloc(sizeof(NoArv));
    aux->valor = num;
    aux->esquerda = NULL;
    aux->direita = NULL;
    *raiz = aux;
}

NoArv* buscar_versao_1(NoArv *raiz, int num){
    if(raiz){
        if(num == raiz->valor)
            return raiz;
        else if(num < raiz->valor)
            return buscar_versao_1(raiz->esquerda, num);
        else
            return buscar_versao_1(raiz->direita, num);
    }
    return NULL;
}

void imprimir_versao_1(NoArv *raiz){ // 50 25 30 100
    if(raiz){
        printf("%d ", raiz->valor);
        imprimir_versao_1(raiz->esquerda);
        imprimir_versao_1(raiz->direita);
    }
}

void imprimir_versao_2(NoArv *raiz){ // 25 30 50 100
    if(raiz){
        imprimir_versao_2(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir_versao_2(raiz->direita);
    }
}

int main(){

    NoArv *busca, *raiz = NULL;
    int opcao, valor;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Buscar\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("\n\tDigite um valor: ");
            scanf("%d", &valor);
            //raiz = inserir_versao_1(raiz, valor);
            //inserir_versao_2(&raiz, valor);
            inserir_versao_3(&raiz, valor);
            break;
        case 2:
            printf("\n\tPrimeira impressao:\n\t");
            imprimir_versao_1(raiz);
            printf("\n");
            printf("\n\tSegunda impressao:\n\t");
            imprimir_versao_2(raiz);
            printf("\n");
            break;
        case 3:
            printf("\n\tDigite o valor a ser procurado: ");
            scanf("%d", &valor);
            busca = buscar_versao_1(raiz, valor);
            if(busca)
                printf("\n\tValor encontrado: %d\n", busca->valor);
            else
                printf("\n\tValor nao encontrado!\n");
            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}
*/



/*
            Aula 269: Como BUSCAR em uma Árvore Binária de Busca?
            VERSÃO RECURSIVA

           


typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NoArv;

NoArv* inserir_versao_1(NoArv *raiz, int num){
    if(raiz == NULL){
        NoArv *aux = malloc(sizeof(NoArv));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else{
        if(num < raiz->valor)
            raiz->esquerda = inserir_versao_1(raiz->esquerda, num);
        else
            raiz->direita = inserir_versao_1(raiz->direita, num);
        return raiz;
    }
}

void inserir_versao_2(NoArv **raiz, int num){
    if(*raiz == NULL){
        *raiz = malloc(sizeof(NoArv));
        (*raiz)->valor = num;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    }
    else{
        if(num < (*raiz)->valor)
            inserir_versao_2(&((*raiz)->esquerda), num);
        else
            inserir_versao_2(&((*raiz)->direita), num);
    }
}

void inserir_versao_3(NoArv **raiz, int num){
    NoArv *aux = *raiz;
    while(aux){
        if(num < aux->valor)
            raiz = &aux->esquerda;
        else
            raiz = &aux->direita;
        aux = *raiz;
    }
    aux = malloc(sizeof(NoArv));
    aux->valor = num;
    aux->esquerda = NULL;
    aux->direita = NULL;
    *raiz = aux;
}

NoArv* buscar_versao_1(NoArv *raiz, int num){
    if(raiz){
        if(num == raiz->valor)
            return raiz;
        else if(num < raiz->valor)
            return buscar_versao_1(raiz->esquerda, num);
        else
            return buscar_versao_1(raiz->direita, num);
    }
    return NULL;
}

void imprimir_versao_1(NoArv *raiz){ // 50 25 30 100
    if(raiz){
        printf("%d ", raiz->valor);
        imprimir_versao_1(raiz->esquerda);
        imprimir_versao_1(raiz->direita);
    }
}

void imprimir_versao_2(NoArv *raiz){ // 25 30 50 100
    if(raiz){
        imprimir_versao_2(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir_versao_2(raiz->direita);
    }
}

int main(){

    NoArv *busca, *raiz = NULL;
    int opcao, valor;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Buscar\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("\n\tDigite um valor: ");
            scanf("%d", &valor);
            //raiz = inserir_versao_1(raiz, valor);
            //inserir_versao_2(&raiz, valor);
            inserir_versao_3(&raiz, valor);
            break;
        case 2:
            printf("\n\tPrimeira impressao:\n\t");
            imprimir_versao_1(raiz);
            printf("\n");
            printf("\n\tSegunda impressao:\n\t");
            imprimir_versao_2(raiz);
            printf("\n");
            break;
        case 3:
            printf("\n\tDigite o valor a ser procurado: ");
            scanf("%d", &valor);
            busca = buscar_versao_1(raiz, valor);
            if(busca)
                printf("\n\tValor encontrado: %d\n", busca->valor);
            else
                printf("\n\tValor nao encontrado!\n");
            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}


*/





/*
            Aula 268: Como inserir em uma Árvore Binária de Busca?
            TERCEIRA VERSÃO

           


typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NoArv;

NoArv* inserir_versao_1(NoArv *raiz, int num){
    if(raiz == NULL){
        NoArv *aux = malloc(sizeof(NoArv));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else{
        if(num < raiz->valor)
            raiz->esquerda = inserir_versao_1(raiz->esquerda, num);
        else
            raiz->direita = inserir_versao_1(raiz->direita, num);
        return raiz;
    }
}

void inserir_versao_2(NoArv **raiz, int num){
    if(*raiz == NULL){
        *raiz = malloc(sizeof(NoArv));
        (*raiz)->valor = num;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    }
    else{
        if(num < (*raiz)->valor)
            inserir_versao_2(&((*raiz)->esquerda), num);
        else
            inserir_versao_2(&((*raiz)->direita), num);
    }
}

void inserir_versao_3(NoArv **raiz, int num){
    NoArv *aux = *raiz;
    while(aux){
        if(num < aux->valor)
            raiz = &aux->esquerda;
        else
            raiz = &aux->direita;
        aux = *raiz;
    }
    aux = malloc(sizeof(NoArv));
    aux->valor = num;
    aux->esquerda = NULL;
    aux->direita = NULL;
    *raiz = aux;
}

void imprimir_versao_1(NoArv *raiz){
    if(raiz){
        printf("%d ", raiz->valor);
        imprimir_versao_1(raiz->esquerda);
        imprimir_versao_1(raiz->direita);
    }
}

void imprimir_versao_2(NoArv *raiz){
    if(raiz){
        imprimir_versao_2(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir_versao_2(raiz->direita);
    }
}

int main(){

    NoArv *raiz = NULL;
    int opcao, valor;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("\n\tDigite um valor: ");
            scanf("%d", &valor);
            //raiz = inserir_versao_1(raiz, valor);
            //inserir_versao_2(&raiz, valor);
            inserir_versao_3(&raiz, valor);
            break;
        case 2:
            printf("\n\tPrimeira impressao:\n\t");
            imprimir_versao_1(raiz);
            printf("\n");
            printf("\n\tSegunda impressao:\n\t");
            imprimir_versao_2(raiz);
            printf("\n");
            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}

*/


/*
            Aula 267: Como inserir em uma Árvore Binária de Busca?
            SEGUNDA VERSÃO

           


typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NoArv;

NoArv* inserir_versao_1(NoArv *raiz, int num){
    if(raiz == NULL){
        NoArv *aux = malloc(sizeof(NoArv));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else{
        if(num < raiz->valor)
            raiz->esquerda = inserir_versao_1(raiz->esquerda, num);
        else
            raiz->direita = inserir_versao_1(raiz->direita, num);
        return raiz;
    }
}

void inserir_versao_2(NoArv **raiz, int num){
    if(*raiz == NULL){
        *raiz = malloc(sizeof(NoArv));
        (*raiz)->valor = num;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    }
    else{
        if(num < (*raiz)->valor)
            inserir_versao_2(&((*raiz)->esquerda), num);
        else
            inserir_versao_2(&((*raiz)->direita), num);
    }
}

void imprimir_versao_1(NoArv *raiz){ // 50 25 30 100
    if(raiz){
        printf("%d ", raiz->valor);
        imprimir_versao_1(raiz->esquerda);
        imprimir_versao_1(raiz->direita);
    }
}

void imprimir_versao_2(NoArv *raiz){ // 25 30 50 100
    if(raiz){
        imprimir_versao_2(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir_versao_2(raiz->direita);
    }
}

int main(){

    NoArv *raiz = NULL;
    int opcao, valor;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("\n\tDigite um valor: ");
            scanf("%d", &valor);
            //raiz = inserir_versao_1(raiz, valor);
            inserir_versao_2(&raiz, valor);
            break;
        case 2:
            printf("\n\tPrimeira impressao:\n\t");
            imprimir_versao_1(raiz);
            printf("\n");
            printf("\n\tSegunda impressao:\n\t");
            imprimir_versao_2(raiz);
            printf("\n");
            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}

*/



/*
            Aula 266: Como imprimir uma Árvore Binária de Busca?

            


typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NoArv;

NoArv* inserir_versao_1(NoArv *raiz, int num){
    if(raiz == NULL){
        NoArv *aux = malloc(sizeof(NoArv));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else{
        if(num < raiz->valor)
            raiz->esquerda = inserir_versao_1(raiz->esquerda, num);
        else
            raiz->direita = inserir_versao_1(raiz->direita, num);
        return raiz;
    }
}

void imprimir_versao_1(NoArv *raiz){
    if(raiz){
        printf("%d ", raiz->valor);
        imprimir_versao_1(raiz->esquerda);
        imprimir_versao_1(raiz->direita);
    }
}

void imprimir_versao_2(NoArv *raiz){
    if(raiz){
        imprimir_versao_2(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir_versao_2(raiz->direita);
    }
}

int main(){

    NoArv *raiz = NULL;
    int opcao, valor;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("\n\tDigite um valor: ");
            scanf("%d", &valor);
            raiz = inserir_versao_1(raiz, valor);
            break;
        case 2:
            printf("\n\tPrimeira impresao:\n");
            imprimir_versao_1(raiz);
            printf("\n");
            printf("\n\tSegunda impresao:\n");
            imprimir_versao_2(raiz);
            printf("\n");
            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}

*/



/*
            Aula 265: Como inserir em uma Árvore Binária de Busca?

            

typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NoArv;

NoArv* inserir_versao_1(NoArv *raiz, int num){
    if(raiz == NULL){
        NoArv *aux = malloc(sizeof(NoArv));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else{
        if(num < raiz->valor)
            raiz->esquerda = inserir_versao_1(raiz->esquerda, num);
        else
            raiz->direita = inserir_versao_1(raiz->direita, num);
        return raiz;
    }
}

int main(){

    NoArv *raiz = NULL;
    
    raiz = inserir_versao_1(raiz, 100);

    return 0;
}

*/


/*  Estrutura de dados dinâmica Árvore Binária de Busca | aula 264
        Estrutura de dados ultilizada para organização e busca de dados

        quando um no tem seus ponteiros apontando para valores nulos , eles são chamdos de folhas

                                583
                               /    \
                              /      731 
                             245    /    \ 
                            /   \  684   893
                           /     \
                        123      389

            os elementos 123,389,684,893 são folhas da arvore , o 583 é no raiz
*/
