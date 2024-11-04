#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#include <string.h>// para usar o strlen
#include <ctype.h>
int main() { setlocale(LC_ALL,"");
    /*
            Aula 207: Curiosidade sobre as funções malloc e calloc
            
            A função malloc aloca porém o vetor pode conter lixo de memoria 
            com a função calloc o vetor fica sem lixo de memoria

            OBSERVAÇÃO:
            Este é apenas um código de exemplo e ambos os vetores podem estar com o valor zero em todas as posições de memória se forem vetores pequenos e não possuir lixo de memória.
    
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
            Aula 206: Como liberar a memória de uma matriz dinâmica?

            Código escrito por Wagner Gaspar
            Junho de 2021
    
    int **mat, i, j;

    // alocando um vetor de ponteiros (vetor de vetores)
    mat = malloc(5 * sizeof(int*));

    // alocando um vetor para cada posição do vetor anterior
    for(i = 0; i < 5; i++)
        mat[i] = malloc(5 * sizeof(int));

    srand(time(NULL));

    // gerando números e preenchendo a matriz
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

    // liberando a memória alocada para a matriz
    for(i = 0; i < 5; i++)
        free(mat[i]); // libera cada uma das linhas
    free(mat); // libera o vetor inicial com os ponteiros para as linhas
    */
    


    /*
            Aula 205: Dúvida

            Código escrito por Wagner Gaspar
            Junho de 2021

        Dúvida: Faça uma função que recebe um nome e devolve o nome invertido.


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
            Aula 204: É possível percorrer uma matriz dinâmica sem colchetes?


        vetor de vetores -> int* -> 10 27 32
                            int* -> 11 75 49
                            int* -> 43 82 10
                            int* -> 12 47 62
    
    int **mat, i, j;

    // aloca um vetor de ponteiros para inteiros
    mat = malloc(5 * sizeof(int*));


    // cada posição do vetor aponta para outro vetor
    for(i = 0; i < 5; i++)
        mat[i] = malloc(5 * sizeof(int));

    srand(time(NULL));


    // gera números aleatórios para preencher a matriz
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
            Aula 203: Dúvida

            Código escrito por Wagner Gaspar
            Junho de 2021

        Foram digitadas três linhas, onde cada uma das linhas contém o nome e a nota de
        um aluno. Escreva um programa que leia essas informações e monte uma tabela onde
        a primeira coluna é o nome e a segunda coluna é a nota.
    

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
            Aula 202: Como alocar uma matriz dinâmica?

            

            vetor de vetores -> int* -> 10 27 32
                                int* -> 11 75 49
                                int* -> 43 82 10
                                int* -> 12 47 62
    
    int **mat, i, j;

    // aloca um vetor de ponteiros para inteiros
    mat = malloc(4 * sizeof(int*));


    // cada posição do vetor aponta para outro vetor
    for(i = 0; i < 4; i++)
        mat[i] = malloc(3 * sizeof(int));

    srand(time(NULL));


    // gera números aleatórios para preencher a matriz
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
    /* Aula 201: Como liberar memória alocada dinamicamente com a função free
    
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

        free(vet);// função para liberar memoria

    }
    else{
        printf("Erro ao alocar memoria!\n");
    }
    */


    /*
            Aula 200: Alocação dinâmica de memória com a função realloc(vet, tam);
        
        -> Retorna um ponteiro para a nova região de memória alocada.
        -> Se o ponteiro vet for nulo ela aloca tam bytes de memória.
        -> Se o novo tamanho for zero a memória de vet é liberada.
        -> Se não houver memória suficiente retorna null.
    

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
            Aula 199: Como alocar um vetor dinâmico?
    


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
            Aula 198: Alocação dinâmica de memória com a função calloc.

            
       

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
                Aula 197: Alocação dinâmica de memória com a função malloc.
                Retorna um ponteiro para a região de memória alocada ou NULL.

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
