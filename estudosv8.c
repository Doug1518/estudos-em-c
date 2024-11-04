#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#include <string.h>// para usar o strlen
#include <ctype.h>
int main() { setlocale(LC_ALL,"");
    /*
            Aula 207: Curiosidade sobre as fun��es malloc e calloc
            
            A fun��o malloc aloca por�m o vetor pode conter lixo de memoria 
            com a fun��o calloc o vetor fica sem lixo de memoria

            OBSERVA��O:
            Este � apenas um c�digo de exemplo e ambos os vetores podem estar com o valor zero em todas as posi��es de mem�ria se forem vetores pequenos e n�o possuir lixo de mem�ria.
    
    int i, *vet1, *vet2;

    vet1 = malloc(10 * sizeof(int));
    vet2 = calloc(10, sizeof(int));
 
    printf("\nCom malloc: ");
    for(i = 0; i < 10; i++)
        printf("%d ", vet1[i]);

    printf("\nCom calloc: ");
    for(i = 0; i < 10; i++)
        printf("%d ", vet2[i]);

    */
    /*
            Aula 206: Como liberar a mem�ria de uma matriz din�mica?

            C�digo escrito por Wagner Gaspar
            Junho de 2021
    
    int **mat, i, j;

    // alocando um vetor de ponteiros (vetor de vetores)
    mat = malloc(5 * sizeof(int*));

    // alocando um vetor para cada posi��o do vetor anterior
    for(i = 0; i < 5; i++)
        mat[i] = malloc(5 * sizeof(int));

    srand(time(NULL));

    // gerando n�meros e preenchendo a matriz
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++)
            *(*(mat + i) + j) = rand() % 100;
    }

    // imprimindo a matriz no terminal
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++)
            printf("%2d ", *(*(mat + i) + j));
        printf("\n");
    }

    // liberando a mem�ria alocada para a matriz
    for(i = 0; i < 5; i++)
        free(mat[i]); // libera cada uma das linhas
    free(mat); // libera o vetor inicial com os ponteiros para as linhas
    */
    


    /*
            Aula 205: D�vida

            C�digo escrito por Wagner Gaspar
            Junho de 2021

        D�vida: Fa�a uma fun��o que recebe um nome e devolve o nome invertido.


    void inverter(char vet[]){
        int i, aux, fim, tam = strlen(vet);

        fim = tam - 1;
        for(i = 0; i < tam/2; i++){
            aux = vet[i];
            vet[i] = vet[fim];
            vet[fim] = aux;
            fim--;
        }
    }

    char* inverter2(char vet[]){
        int i, aux, fim, tam = strlen(vet);
        char *novo = malloc((tam + 1) * sizeof(char));

        fim = tam - 1;
        for(i = 0; i < tam; i++){
            novo[fim] = vet[i];
            fim--; 
        }
        novo[i] = '\0';
        return novo;
    }

    int main(){

        char palavra[25] = {"Muito bem feito!"};
        char *p;

        printf("%s\n", palavra);
        //inverter(palavra);
        printf("%s\n", palavra);

        p = inverter2(palavra);
        printf("%s\n", p);
    
 */   
    
    
    /*
            Aula 204: � poss�vel percorrer uma matriz din�mica sem colchetes?


        vetor de vetores -> int* -> 10 27 32
                            int* -> 11 75 49
                            int* -> 43 82 10
                            int* -> 12 47 62
    
    int **mat, i, j;

    // aloca um vetor de ponteiros para inteiros
    mat = malloc(5 * sizeof(int*));


    // cada posi��o do vetor aponta para outro vetor
    for(i = 0; i < 5; i++)
        mat[i] = malloc(5 * sizeof(int));

    srand(time(NULL));


    // gera n�meros aleat�rios para preencher a matriz
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++)
            *(*(mat +i) +j) = rand()% 100;
            //mat[i][j] = rand() % 100;
    }


    // imprime a matriz
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5 ; j++)
            printf("%2d ",  *(*(mat +i) +j)); 
        printf("\n");
    }
    */
    /*
            Aula 203: D�vida

            C�digo escrito por Wagner Gaspar
            Junho de 2021

        Foram digitadas tr�s linhas, onde cada uma das linhas cont�m o nome e a nota de
        um aluno. Escreva um programa que leia essas informa��es e monte uma tabela onde
        a primeira coluna � o nome e a segunda coluna � a nota.
    

    char nomes[3][30];
    float notas[3];
    int i;

    for(i = 0; i < 3; i++){
        printf("Digite nome e nota do estudante: ");
        scanf("%s%f", &nomes[i], &notas[i]);
    }

    printf("\n\tNome\tNota\n");
    for(i = 0; i < 3; i++)
        printf("\t%s\t%.2f\n", nomes[i], notas[i]);
      
    */
    /*
            Aula 202: Como alocar uma matriz din�mica?

            

            vetor de vetores -> int* -> 10 27 32
                                int* -> 11 75 49
                                int* -> 43 82 10
                                int* -> 12 47 62
    
    int **mat, i, j;

    // aloca um vetor de ponteiros para inteiros
    mat = malloc(4 * sizeof(int*));


    // cada posi��o do vetor aponta para outro vetor
    for(i = 0; i < 4; i++)
        mat[i] = malloc(3 * sizeof(int));

    srand(time(NULL));


    // gera n�meros aleat�rios para preencher a matriz
    for(i = 0; i < 4; i++){
        for(j = 0; j < 3; j++)
            mat[i][j] = rand() % 100;
    }


    // imprime a matriz
    for(i = 0; i < 4; i++){
        for(j = 0; j < 3; j++)
            printf("%2d ", mat[i][j]);
        printf("\n");
    }
    */
    /* Aula 201: Como liberar mem�ria alocada dinamicamente com a fun��o free
    
    int i, tam,  *vet;


    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);
    srand(time(NULL));

    vet = malloc(tam * sizeof(int));

    if(vet){
        printf("Memoria alocada !\n");
        for (i=0; i<tam ; i++)
            *(vet + i) = rand() % 100;
        for (i=0; i<tam ; i++)
            printf("%d ", *(vet+i));
        printf("\n");
        printf("Digite o novo tamanho do vetor: ");
        scanf("%d", &tam);

        vet = realloc(vet, tam * (sizeof(int)));
        printf("\nVetor realocado: \n");
        for (i=0; i<tam ; i++)
            printf("%d ", *(vet+i));
        printf("\n");

        free(vet);// fun��o para liberar memoria

    }
    else{
        printf("Erro ao alocar memoria!\n");
    }
    */


    /*
            Aula 200: Aloca��o din�mica de mem�ria com a fun��o realloc(vet, tam);
        
        -> Retorna um ponteiro para a nova regi�o de mem�ria alocada.
        -> Se o ponteiro vet for nulo ela aloca tam bytes de mem�ria.
        -> Se o novo tamanho for zero a mem�ria de vet � liberada.
        -> Se n�o houver mem�ria suficiente retorna null.
    

    int i, tam,  *vet;


    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);
    srand(time(NULL));

    vet = malloc(tam * sizeof(int));

    if(vet){
        printf("Memoria alocada !\n");
        for (i=0; i<tam ; i++)
            *(vet + i) = rand() % 100;
        for (i=0; i<tam ; i++)
            printf("%d ", *(vet+i));
        printf("\n");
        printf("Digite o novo tamanho do vetor: ");
        scanf("%d", &tam);

        vet = realloc(vet, tam * (sizeof(int)));
        printf("\nVetor realocado: \n");
        for (i=0; i<tam ; i++)
            printf("%d ", *(vet+i));
        printf("\n");

    }
    else{
        printf("Erro ao alocar memoria!\n");
    }

    */

    /*
            Aula 199: Como alocar um vetor din�mico?
    


    int i, tam,  *vet;


    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);
    srand(time(NULL));

    vet = malloc(tam * sizeof(int));

    if(vet){
        printf("Memoria alocada !\n");
        for (i=0; i<tam ; i++)
            *(vet + i) = rand() % 100;
        for (i=0; i<tam ; i++)
            printf("%d ", *(vet+i));
        printf("\n");
    }
    else{
        printf("Erro ao alocar memoria!\n");
    }

    */
    /*
            Aula 198: Aloca��o din�mica de mem�ria com a fun��o calloc.

            
       

    char *x;

    x = calloc(1, sizeof(char));// recebe mais parametros do que a malloc, quantidade de elementos 

    // if (x) ja faz o teste de x != null
    if(x){
        printf("memoria alocada com sucesso!\n");
        printf("x: %d\n", *x);
        *x = 50;
        printf("x: %d\n", *x);
    }
    else{
        printf("Erro ao alocar memoria!\n");
    }

    */

    /*
                Aula 197: Aloca��o din�mica de mem�ria com a fun��o malloc.
                Retorna um ponteiro para a regi�o de mem�ria alocada ou NULL.

    int *x;

    x = malloc(sizeof(int));

    // if (x) ja faz o teste de x != null
    if(x){
        printf("memoria alocada com sucesso!\n");
        printf("x: %d\n", *x);
        *x = 50;
        printf("x: %d\n", *x);
    }
    else{
        printf("Erro ao alocar memoria!\n");
    }


    */    
return 0;
}
