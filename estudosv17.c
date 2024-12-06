#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#include <string.h>// para usar o strlen
#include <ctype.h>
// #include "pilha.h"
#include <windows.h>



/*Como descobrir o menor elemento de um vetor com recurs�o? | Aula 320*/

int menor(int  v[], int tam, int indice){
    if(tam == 0)
        return v[indice];
    else{
        if(v[tam] < v[indice])
            return menor(v, tam -1, tam );
        else
            return menor(v, tam-1, indice);
    }
    
}


int main() {
    int vet[] = {57,13,42,1,21,3,82,59};
    
    printf("O menor valor e : %d\n",menor(vet, 7 , 0));

    return 0 ; 
}




/*Curso de Programa��o C | Desmistificando PONTEIROS em C (se for poss�vel ?? ?? ?? ?? ??) | aula 319

typedef struct no{
    int valor;
    struct no *proximo
}No;

No* inserir(No *inicio, int x){
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = x;
        novo->proximo = inicio;

    }
    return novo; 
}


void inserir2(No **inicio, int x){
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = x;
        novo->proximo = *inicio;
        *inicio = novo;

    }
    
}


void imprimir(No *inicio){
    if(inicio){
        printf("%d ", inicio->valor);
        imprimir(inicio->proximo);
    }
}
int main (){
    No *lista = NULL;
    lista = inserir(lista, 10);
    lista = inserir(lista, 50);
    lista = inserir(lista, 100);

    inserir2(&lista, 88);
    inserir2(&lista, 17);
    inserir2(&lista, 140);
    
    imprimir(lista);
    return 0; 
}


*/

/*

void descobrir_valor(int *v, int *me, int *ma, int tam){
    int i ;
    *me= v[0];
    *ma= v[0];
    for(i= 1 ; i < tam; i++){
        if(v[i]< *me)
            *me= v[i];
        if(v[i]> *ma)
            *ma=v[i];
    }
    printf("Na funcao : menor : %d \t Maior : %d\n", *me,*ma);
    printf(" Na funcao -> End de me: %p\tEnd de ma: %p\n", &me, &ma);
    printf(" Na funcao -> cont de me: %p\tcont de ma: %p\n", me, ma);
}


int main (){

    int valor = 10, menor, maior, vet [] = {50,10,250,500,25};
    int *p;

    p = &valor;

    printf("Valor : %d\tendereco de valor: %p\n", valor, &valor);

    printf("Endereco de p : %p\n", &p);
    printf("Conteudo de p : %p\n", p);
    printf("Conteudo apontado por p : %d\n", *p);
    descobrir_valor(vet, &menor, &maior, 5);
    printf("Em main : menor : %d \t Maior : %d\n", menor , maior);
    printf("End de menor: %p\tEnd de maior: %p\n", &menor, &maior);
    

    return 0; 
}

*/


/* | Estrutura de dados �rvore 2-3-4 (2-3-4 Tree) | aula 318*
n�o foi escrito nenhum codigo at� o momento /




/* Como identificar o Sistema Operacional e limpar o terminal? | aula 317 

int main(){
    #ifdef _WIN32
    printf("abc");
    getchar();
    system("cls");
    getchar();
    printf("windowns");
    #elif __linux
    printf("cde");
    getchar();
    system("clear");
    getchar();
    printf("sistema linux");
    #else
    printf("Sistema n�o reconhecido...\n");
    #endif

    return 0; 
}

*/



/*
 Como criar uma �rvore Bin�ria Balanceada AVL com Struct Pessoa? | aula 316

typedef struct{
    char nome[25];
    int idade;
    int cpf;
}Pessoa;

typedef struct no{
    Pessoa *pessoa;
    struct no *esquerdo, *direito;
    short altura;
}No;


    Fun��o que cria um novo n�
    x -> valor a ser inserido no n�
    Retorna: o endere�o do n� criado

No* novoNo(Pessoa *x){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->pessoa = x;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        novo->altura = 0;
    }
    else
        printf("\nERRO ao alocar n� em novoNo!\n");
    return novo;
}


    Retorna o maior dentre dois valores
    a, b -> altura de dois n�s da �rvore

short maior(short a, short b){
    return (a > b)? a: b;
}

//  Retorna a altura de um n� ou -1 caso ele seja null
short alturaDoNo(No *no){
    if(no == NULL)
        return -1;
    else
        return no->altura;
}

//   Calcula e retorna o fator de balanceamento de um n�
short fatorDeBalanceamento(No *no){
    if(no)
        return (alturaDoNo(no->esquerdo) - alturaDoNo(no->direito));
    else
        return 0;
}

// --------- ROTA��ES ---------------------------

// fun��o para a rota��o � esquerda
No* rotacaoEsquerda(No *r){
    No *y, *f;

    y = r->direito;
    f = y->esquerdo;

    y->esquerdo = r;
    r->direito = f;

    r->altura = maior(alturaDoNo(r->esquerdo), alturaDoNo(r->direito)) + 1;
    y->altura = maior(alturaDoNo(y->esquerdo), alturaDoNo(y->direito)) + 1;

    return y;
}

// fun��o para a rota��o � direita
No* rotacaoDireita(No *r){
    No *y, *f;

    y = r->esquerdo;
    f = y->direito;

    y->direito = r;
    r->esquerdo = f;

    r->altura = maior(alturaDoNo(r->esquerdo), alturaDoNo(r->direito)) + 1;
    y->altura = maior(alturaDoNo(y->esquerdo), alturaDoNo(y->direito)) + 1;

    return y;
}

No* rotacaoEsquerdaDireita(No *r){
    r->esquerdo = rotacaoEsquerda(r->esquerdo);
    return rotacaoDireita(r);
}

No* rotacaoDireitaEsquerda(No *r){
    r->direito = rotacaoDireita(r->direito);
    return rotacaoEsquerda(r);
}


    Fun��o para realizar o balanceamento da �rvore ap�s uma inser��o ou remo��o
    Recebe o n� que est� desbanlanceado e retorna a nova raiz ap�s o balanceamento

No* balancear(No *raiz){
    short fb = fatorDeBalanceamento(raiz);

    // Rota��o � esquerda
    if(fb < -1 && fatorDeBalanceamento(raiz->direito) <= 0)
        raiz = rotacaoEsquerda(raiz);

    // Rota��o � direita
    else if(fb > 1 && fatorDeBalanceamento(raiz->esquerdo) >= 0)
        raiz = rotacaoDireita(raiz);

    // Rota��o dupla � esquerda
    else if(fb > 1 && fatorDeBalanceamento(raiz->esquerdo) < 0)
        raiz = rotacaoEsquerdaDireita(raiz);

    // Rota��o dupla � direita
    else if(fb < -1 && fatorDeBalanceamento(raiz->direito) > 0)
        raiz = rotacaoDireitaEsquerda(raiz);

    return raiz;
}


    Insere um novo n� na �rvore
    raiz -> raiz da �rvore
    x -> valor a ser inserido
    Retorno: endere�o do novo n� ou nova raiz ap�s o balanceamento

No* inserir(No *raiz, Pessoa *x){
    if(raiz == NULL) // �rvore vazia
        return novoNo(x);
    else{ // inser��o ser� � esquerda ou � direita?
        if(x->cpf < raiz->pessoa->cpf)
            raiz->esquerdo = inserir(raiz->esquerdo, x);
        else if(x->cpf > raiz->pessoa->cpf)
            raiz->direito = inserir(raiz->direito, x);
        else
            printf("\nInsercao nao realizada!\nO elemento %d a existe!\n", x->cpf);
    }

    raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;

    raiz = balancear(raiz);

    return raiz;
}


    Fun��o para remover um n� da �rvore bin�ria
    Pode ser necess�rio rebalancear a �rvore e a raiz pode ser alterada
    por isso precisamos retornar a raiz

No* remover(No *raiz, int chave) {
    if(raiz == NULL){
        printf("Valor nao encontrado!\n");
        return NULL;
    } else { // procura o n� a remover
        if(raiz->pessoa->cpf == chave) {
            // remove n�s folhas (n�s sem filhos)
            if(raiz->esquerdo == NULL && raiz->direito == NULL) {
                free(raiz);
                printf("Elemento folha removido: %d !\n", chave);
                return NULL;
            }
            else{
                // remover n�s que possuem 2 filhos
                if(raiz->esquerdo != NULL && raiz->direito != NULL){
                    No *aux = raiz->esquerdo;
                    while(aux->direito != NULL)
                        aux = aux->direito;
                    Pessoa *pessoaAux;
                    pessoaAux = raiz->pessoa;
                    raiz->pessoa = aux->pessoa;
                    aux->pessoa = pessoaAux;
                    printf("Elemento trocado: %d !\n", chave);
                    raiz->esquerdo = remover(raiz->esquerdo, chave);
                    return raiz;
                }
                else{
                    // remover n�s que possuem apenas 1 filho
                    No *aux;
                    if(raiz->esquerdo != NULL)
                        aux = raiz->esquerdo;
                    else
                        aux = raiz->direito;
                    free(raiz);
                    printf("Elemento com 1 filho removido: %d !\n", chave);
                    return aux;
                }
            }
        } else {
            if(chave < raiz->pessoa->cpf)
                raiz->esquerdo = remover(raiz->esquerdo, chave);
            else
                raiz->direito = remover(raiz->direito, chave);
        }

        raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;

        raiz = balancear(raiz);

        return raiz;
    }
}

void imprimirPessoa(Pessoa *pessoa){
    printf("Nome: %s CPF: %d Idade: %d\n", pessoa->nome, pessoa->cpf, pessoa->idade);
}

void imprimir(No *raiz, int nivel){
    int i;
    if(raiz){
        imprimir(raiz->direito, nivel + 1);
        printf("\n\n");

        for(i = 0; i < nivel; i++)
            printf("\t");

        imprimirPessoa(raiz->pessoa);
        imprimir(raiz->esquerdo, nivel + 1);
    }
}

int main(){

    int opcao, valor;
    No *raiz = NULL;
    Pessoa *p;

    do{
        printf("\n\n\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 0:
            printf("Saindo!!!");
            break;
        case 1:
            p = malloc(sizeof(Pessoa));
            printf("\tDigite o nome: ");
            scanf("%s", p->nome);
            printf("Digite o CPF e a Idade: ");
            scanf("%d%d", &p->cpf, &p->idade);
            raiz = inserir(raiz, p);
            break;
        case 2:
            printf("\tDigite o CPF a ser removido: ");
            scanf("%d", &valor);
            raiz = remover(raiz, valor);
            break;
        case 3:
            imprimir(raiz, 1);
            break;
        default:
            printf("\nOcao invalida!!!\n");
        }

    }while(opcao != 0);

    return 0;
}


*/


/*
       Como imprimir uma pir�mide de asteriscos? (tri�ngulo is�sceles) | aula 315


#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, n;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        for(j = n - i; j >= 1; j--) // imprime os espa�os
            printf(" ");
        for(j = 1; j <= i; j++) // imprime os *
            printf("*");
        printf(" ");
        for(j = 1; j <= i; j++) // imprime os *
            printf("*");
        printf("\n");
    }

    return 0;
}

*/


/*
Como converter n�mero decimal em bin�rio e salvar em vari�vel? | aula 314



void binario(int n, int *vet, int id){
    if(n == 0){
        printf("%d", n);
        vet[id] = n;
    }
    else{
        binario(n/2, vet, id - 1);
        printf("%d", n % 2);
        vet[id] = n % 2;
    }
}

int main () {

    int i, n, vet[50];

    for(i = 0; i < 50; i++)
        vet[i] = 0;

    printf("Digite um valor decimal: ");
    scanf("%d",&n);

    binario(n, vet, 49);

    printf("\n");
    for(i = 0; i < 50; i++)
        printf("%d", vet[i]);
    printf("\n\n");

    return 0;
}
*/


/*
             Como descobrir todos os n�meros primos entre 1 e 500? | aula 313


int ehPrimo(int x){
    int i, divisores = 0;

    for(i = 1; i <= x; i++){
        if(x % i == 0)
            divisores++;
    }

    if(divisores == 2)
        return 1;// � primo
    else
        return 0; // n�o � primo
}

int main(){
    int i;

    for(i = 1; i <= 500; i++){
        if(ehPrimo(i) == 1) // se for primo
            printf("%d, ", i); // imprime na tela
    }
    return 0;
}


*/




/*
 Como contar as ocorr�ncias de uma substring em uma string? | aula 312


int existe(char *str1, char *str2, int id){
    int i, j = 0;

    for(i = id; i < strlen(str1); i++){
        if(str1[i] == str2[j])
            j++;
        else
            j = 0;
        if(j == strlen(str2))
            return i;
    }
    return -1;
}

int main(){
    char str1[] = "ama quem ama, ama muito!";
    char str2[] = "ama";
    int indice = 0, quantidade = 0;

    do{
        indice = existe(str1, str2, indice);
        printf("Retorno: %d\n", indice);
        if(indice != -1)
            quantidade++;
    }while(indice != -1);

    printf("\nQuantidade: %d\n", quantidade);

    return 0;
}


*/






/*  
    Como implementar uma �rvore AVL - �rvore balanceada? | aula 302
    Como implementar uma ROTA��O � ESQUERDA em uma �rvore AVL? | aula 303
    Como implementar uma ROTA��O � DIREITA em uma �rvore AVL? | aula 304
    Como implementar as ROTA��ES DUPLAS em uma �rvore AVL? | aula 305
    Como inserir em uma �rvore bin�ria balanceada - �rvore AVL? | aula 306
    Como remover um n� em uma �rvore bin�ria balanceada - �rvore AVL? |aula 307
    Como imprimir uma �rvore Bin�ria Balanceada - �rvore AVL? | aula 308
    Testando nossa �rvore Bin�ria de Busca Balanceada - �rvore AVL | aula 309
*/
/*
       N� para a �rvore AVL

typedef struct no{
    int valor;
    struct no *esquerdo, *direito;
    short altura;
}No;

// 
//     Fun��o que cria um novo n�
//     x -> valor a ser inserido no n�
//     Retorna: o endere�o do n� criado
// 
No* novoNo(int x){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = x;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        novo->altura = 0;
    }
    else
        printf("\nERRO ao alocar n� em novoNo!\n");
    return novo;
}


    Retorna o maior dentre dois valores
    a, b -> altura de dois n�s da �rvore

short maior(short a, short b){
    return (a > b)? a: b;
}


//  Retorna a altura de um n� ou -1 caso ele seja null
short alturaDoNo(No *no){
    if(no == NULL)
        return -1;
    else
        return no->altura;
}

//   Calcula e retorna o fator de balanceamento de um n�
short fatorDeBalanceamento(No *no){
    if(no)
        return (alturaDoNo(no->esquerdo) - alturaDoNo(no->direito));
    else
        return 0;
}

// --------- ROTA��ES ---------------------------

// fun��o para a rota��o � esquerda
No* rotacaoEsquerda(No *r){
    No *y, *f;

    y = r->direito;
    f = y->esquerdo;

    y->esquerdo = r;
    r->direito = f;

    r->altura = maior(alturaDoNo(r->esquerdo), alturaDoNo(r->direito)) + 1;
    y->altura = maior(alturaDoNo(y->esquerdo), alturaDoNo(y->direito)) + 1;

    return y;
}

// fun��o para a rota��o � direita
No* rotacaoDireita(No *r){
    No *y, *f;

    y = r->esquerdo;
    f = y->direito;

    y->direito = r;
    r->esquerdo = f;

    r->altura = maior(alturaDoNo(r->esquerdo), alturaDoNo(r->direito)) + 1;
    y->altura = maior(alturaDoNo(y->esquerdo), alturaDoNo(y->direito)) + 1;

    return y;
}

No* rotacaoEsquerdaDireita(No *r){
    r->esquerdo = rotacaoEsquerda(r->esquerdo);
    return rotacaoDireita(r);
}

No* rotacaoDireitaEsquerda(No *r){
    r->direito = rotacaoDireita(r->direito);
    return rotacaoEsquerda(r);
}

/*
    Fun��o para realizar o balanceamento da �rvore ap�s uma inser��o ou remo��o
    Recebe o n� que est� desbalanceado e retorna a nova raiz ap�s o balanceamento

No* balancear(No *raiz){
    short fb = fatorDeBalanceamento(raiz);

    // Rota��o � esquerda
    if(fb < -1 && fatorDeBalanceamento(raiz->direito) <= 0)
        raiz = rotacaoEsquerda(raiz);

    // Rota��o � direita
    else if(fb > 1 && fatorDeBalanceamento(raiz->esquerdo) >= 0)
        raiz = rotacaoDireita(raiz);

    // Rota��o dupla � esquerda
    else if(fb > 1 && fatorDeBalanceamento(raiz->esquerdo) < 0)
        raiz = rotacaoEsquerdaDireita(raiz);

    // Rota��o dupla � direita
    else if(fb < -1 && fatorDeBalanceamento(raiz->direito) > 0)
        raiz = rotacaoDireitaEsquerda(raiz);

    return raiz;
}

/*
    Insere um novo n� na �rvore
    raiz -> raiz da �rvore
    x -> valor a ser inserido
    Retorno: endere�o do novo n� ou nova raiz ap�s o balanceamento

No* inserir(No *raiz, int x){
    if(raiz == NULL) // �rvore vazia
        return novoNo(x);
    else{ // inser��o ser� � esquerda ou � direita
        if(x < raiz->valor)
            raiz->esquerdo = inserir(raiz->esquerdo, x);
        else if(x > raiz->valor)
            raiz->direito = inserir(raiz->direito, x);
        else
            printf("\nInsercao nao realizada!\nO elemento %d a existe!\n", x);
    }

    // Recalcula a altura de todos os n�s entre a raiz e o novo n� inserido
    raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;

    // verifica a necessidade de rebalancear a �rvore
    raiz = balancear(raiz);

    return raiz;
}

/*
    Fun��o para remover um n� da �rvore bin�ria balanceada
    Pode ser necess�rio rebalancear a �rvore e a raiz pode ser alterada
    por isso precisamos retornar a raiz

No* remover(No *raiz, int chave) {
    if(raiz == NULL){
        printf("Valor nao encontrado!\n");
        return NULL;
    } else { // procura o n� a remover
        if(raiz->valor == chave) {
            // remove n�s folhas (n�s sem filhos)
            if(raiz->esquerdo == NULL && raiz->direito == NULL) {
                free(raiz);
                printf("Elemento folha removido: %d !\n", chave);
                return NULL;
            }
            else{
                // remover n�s que possuem 2 filhos
                if(raiz->esquerdo != NULL && raiz->direito != NULL){
                    No *aux = raiz->esquerdo;
                    while(aux->direito != NULL)
                        aux = aux->direito;
                    raiz->valor = aux->valor;
                    aux->valor = chave;
                    printf("Elemento trocado: %d !\n", chave);
                    raiz->esquerdo = remover(raiz->esquerdo, chave);
                    return raiz;
                }
                else{
                    // remover n�s que possuem apenas 1 filho
                    No *aux;
                    if(raiz->esquerdo != NULL)
                        aux = raiz->esquerdo;
                    else
                        aux = raiz->direito;
                    free(raiz);
                    printf("Elemento com 1 filho removido: %d !\n", chave);
                    return aux;
                }
            }
        } else {
            if(chave < raiz->valor)
                raiz->esquerdo = remover(raiz->esquerdo, chave);
            else
                raiz->direito = remover(raiz->direito, chave);
        }

        // Recalcula a altura de todos os n�s entre a raiz e o novo n� inserido
        raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;

        // verifica a necessidade de rebalancear a �rvore
        raiz = balancear(raiz);

        return raiz;
    }
}

void imprimir(No *raiz, int nivel){
    int i;
    if(raiz){
        imprimir(raiz->direito, nivel + 1);
        printf("\n\n");

        for(i = 0; i < nivel; i++)
            printf("\t");

        printf("%d", raiz->valor);
        imprimir(raiz->esquerdo, nivel + 1);
    }
}

int main(){

    int opcao, valor;
    No *raiz = NULL;

    do{
        printf("\n\n\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 0:
            printf("Saindo!!!");
            break;
        case 1:
            printf("\tDigite o valor a ser inserido: ");
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
            break;
        case 2:
            printf("\tDigite o valor a ser removido: ");
            scanf("%d", &valor);
            raiz = remover(raiz, valor);
            break;
        case 3:
            imprimir(raiz, 1);
            break;
        default:
            printf("\nOpcao invalida!!!\n");
        }

    }while(opcao != 0);

    return 0;
}
*/
/*

Curso de Programa��o C | Como garantir que o usu�rio vai digitar um n�mero? | aula 311
#include <stdio.h>
#include <stdlib.h>

int main(){

    int valor, retorno = -1;
    char letra;

    do{
        printf("Digite um valor: ");
        retorno = scanf("%d", &valor);
        printf("Retorno: %d\n", retorno);

        do{
            letra = getchar();
            printf("%c", letra);
        }while(letra != '\n');
    }while(retorno == 0);

    printf("Valor digitado: %d\n", valor);

    return 0;
}

*/

/*
    O que � uma Arvore AVL - �rvore Bin�ria de Busca Balanceada? | aula 301
    
    balanceada O(log(n)) e n�o balanceada o(n))

    fb = altEsq - altDir

    se o fator de balanceamento de no raiz for -1 significa que ele esta pendendo para direita e 1 esta para esquerda

*/
 


