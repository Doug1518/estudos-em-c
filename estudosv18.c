#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#include <string.h>// para usar o strlen
#include <ctype.h>
// #include "pilha.h"
#include <windows.h>


/*Algoritmo de ordenação Insertion Sort Iterativo e Recursivo | aula 333*/

#include <stdio.h>

void insertionSort(int *v, int tam) {
    int i, j;
    for (i = 1; i < tam; i++) {
        int aux = v[i];
        j = i;
        while (j > 0 && aux < v[j - 1]) {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = aux;
    }
}

void insertionSortRecursivo(int *v, int fim, int tam) {
    if (fim >= tam) return;

    int aux = v[fim];
    int j = fim;
    while (j > 0 && aux < v[j - 1]) {
        v[j] = v[j - 1];
        j--;
    }
    v[j] = aux;
    insertionSortRecursivo(v, fim + 1, tam);
}

void imprimir(int *v, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d, ", v[i]);
    }
    printf("\n");
}

int main() {
    int vet[] = {4, 6, 9, 1, 5, 2, 8, 0};
    int tam = 8;

    imprimir(vet, tam);
    insertionSort(vet, tam);  // Descomente se quiser usar o Insertion Sort Iterativo
    // insertionSortRecursivo(vet, 1, tam);  // Descomente se quiser usar o Insertion Sort Recursivo
    imprimir(vet, tam);

    return 0;
}


/*Curso de Programação C | Algoritmo de ordenação Selection Sort (Ordenação por Seleção) | aula 332

void selectionSort(int *v, int tam) {
    int i, j, menor;
    for (i = 0; i < tam - 1; i++) {
        menor = i;
        for (j = i + 1; j < tam; j++) {
            if (v[j] < v[menor]) {
                menor = j;
            }
        }
        int aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }
}

void selectionSortRecursivo(int *v, int inicio, int tam) {
    if (inicio >= tam) return;
    int j, menor = inicio;
    for (j = inicio + 1; j < tam; j++) {
        if (v[j] < v[menor]) {
            menor = j;
        }
    }
    int aux = v[inicio];
    v[inicio] = v[menor];
    v[menor] = aux;
    selectionSortRecursivo(v, inicio + 1, tam);
}

void imprimir(int *v, int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        printf("%d, ", v[i]);
    }
    printf("\n");
}

int main() {
    int vet[] = {4, 6, 9, 1, 5, 2, 8, 0};
    int tam = 8;

    imprimir(vet, tam);
    selectionSort(vet, tam);  // Descomente se quiser usar o Selection Sort Iterativo
    // selectionSortRecursivo(vet, 0, tam);  // Descomente se quiser usar o Selection Sort Recursivo
    imprimir(vet, tam);

    return 0;
}
*/

/* Algoritmo de Ordenação BUBBLE SORT iterativo e recursivo | aula 331


void bubbleSort(int *v, int tam) {
    int i, aux, troca = 1;
    while (troca == 1) {
        troca = 0;
        for (i = 0; i < tam - 1; i++) {
            if (v[i] > v[i + 1]) {
                troca = 1;
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
            }
        }
        tam--; // melhoria
    }
}

void bubbleSortRecursivo(int *v, int n) {
    if (n < 2) return;
    
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            int aux = v[i];
            v[i] = v[i + 1];
            v[i + 1] = aux;
        }
    }
    bubbleSortRecursivo(v, n - 1);
}

void imprimir(int *v, int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        printf("%d, ", v[i]);
    }
    printf("\n");
}

int main() {
    int vet[] = {47, 35, 12, 49, 56, 25, 71, 83, 5, 3, 1, 70, 99, 10, 61}; // tamanho = 15
    int tam = sizeof(vet) / sizeof(vet[0]);
    
    printf("Antes de ordenar:\n");
    imprimir(vet, tam);
    
    bubbleSort(vet, tam); // Usando bubble sort iterativo
    printf("Depois de ordenar (Bubble Sort Iterativo):\n");
    imprimir(vet, tam);
    
    int vet2[] = {47, 35, 12, 49, 56, 25, 71, 83, 5, 3, 1, 70, 99, 10, 61};
    
    bubbleSortRecursivo(vet2, tam); // Usando bubble sort recursivo
    printf("Depois de ordenar (Bubble Sort Recursivo):\n");
    imprimir(vet2, tam);
    
    return 0;
}

*/

/* Algoritmo de ordenação Quick Sort em C | aula 330


int particiona(int *v, int inicio, int fim) { 
    int pivo = (v[inicio] + v[fim] + v[(inicio + fim) / 2]) / 3;
    
    while (inicio < fim) {
        while (inicio < fim && v[inicio] <= pivo) 
            inicio++;
        
        while (inicio < fim && v[fim] > pivo) 
            fim--;
        
        int aux = v[inicio];
        v[inicio] = v[fim];
        v[fim] = aux;
    }
    
    return inicio;
}

void quickSort(int ** v, int inicio, int fim){
    if(inicio < fim){
        int pos = particiona(v,inicio, fim);
        quickSort(v, inicio, pos-1);
        quickSort(v, pos, fim);
    }
}
void imprimir(int *v, int tam){
    int i ;
    for(i = 0; i <= tam; i++)
        printf("%d ,", v[i]);
    printf("\n");
}

int main() {
    int vet[] = {47, 35, 12, 49, 56, 25, 71, 83, 5, 3, 1, 70, 99, 10, 61}; // tamanho = 15
    imprimir(vet,14);
    quickSort(vet,0,14);
    imprimir(vet,14);
    return 0;
}

*/

/*Como gerar todas as substrings possíveis de uma string? | aula 329

void imprimir(char vet[], int inicio, int fim, int tam) {
    int i;

    if (fim < tam) {
        for (i = inicio; i <= fim; i++) {
            printf("%c", vet[i]);
        }
        printf(", ");
        imprimir(vet, inicio, fim + 1, tam);
    } else if (inicio < fim) {
        imprimir(vet, inicio + 1, inicio + 1, tam);
    }
}

int main() {
    char palavra[] = "abacate";
    int tam = strlen(palavra);

    imprimir(palavra, 0, 0, tam);
    printf("\n");

    return 0;
}

*/
/*Como gerar números aleatórios fracionários? | aula 327
int main() {
    int valor, n, i;
    float valor2;

    srand(time(NULL));

    for (i = 0; i < 10; i++) {
        valor = rand() % 10000;
        n = rand() % 100;

        valor2 = valor / 10000.0;
        printf("%.4f\n", valor2);
    }

    return 0;
}
*/
/*Como imprimir meio triângulo de asteriscos? | aula 328
int main(){
    int i,j;
    for(i=0;j<10;j++){
        for (i=j;i<10;i++){
            printf("*");
        }
        printf("\n");
    }
    return 0; 
}

*/
/*Como passar uma matriz dinâmica como parâmetro? | aula 326
void imprimir(int ** m, int l , int c){
    int i , j;
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            printf("%3d ", *(*(m + i)+j));
        }
        printf("\n");
    }

}

int soma(int **m, int l , int c){
    int i , j, soma = 0;
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) 
            soma += m[i][j];
    }
    return soma;

}


int main() {
    int **mat, i, j;

    // Aloca um vetor de ponteiros para inteiros
    mat = malloc(4 * sizeof(int*));

    // Cada posição do vetor aponta para outro vetor
    for (i = 0; i < 4; i++) {
        mat[i] = malloc(3 * sizeof(int));
    }

    srand(time(NULL)); // Gera números aleatórios para preencher a matriz

    // Preenche a matriz com números aleatórios
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            mat[i][j] = rand() % 100;
        }
    }

    // Imprime a matriz
    imprimir(mat, 4 , 3);

    printf("Soma: %d\n", soma(mat,4,3));

    // Libera a memória alocada
    for (i = 0; i < 4; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}

*/
/*| Como dividir um printf longo em várias linhas em C? | aula 325

int main(){
    setlocale(LC_ALL, "portuguese");
    printf(" Você já escreveu um printf que sumia no lado direito da sua tela "
    "e era necessário rolar a barra de rolagem para visualizar seu fim?"
    "Pois bem. Hoje vamos aprender como dividir um printf longo em várias linhas," 
    "facilitando sua visualização sem a necessidade de barras de rolagem.");

    return 0; 

}

*/
/*Como passar parâmetros para função main Code Blocks e terminal? | aula 324

int main(int argc, char *argv[]){
    int i ;
    printf("Quantidade: %d\n", argc);
    
    for(i=0; i< argc;i++){
        printf("%d = %s\n", i, argv[i]);
    }
    return 0; 
}
*/


/*Como descobrir quantas e quais letras duas strings têm em comum? | aula 323


 void eliminarRepetidos (char s1[], char s2[2]){
    int i,tam = strlen(s1);
    int tams2 = 0 ;
    for (i = 0 ; i < tam; i++){
        if(strchr(s2, s1[i]) == NULL){
            s2[tams2] = s1[i];
            tams2++;
            s2[tams2] = '\0';
        }
    }
 }

int ocorrencias(char str[], char letra){
    int i,quant = 0, tam = strlen(str);
    
    for (i = 0 ; i < tam; i++){
        if(letra == str[i]){
            quant ++;
        }
    }
    return quant;
}

int main(){
    char str1[50] = {"Vamos aprender"};
    char str2[50] = {"\0"};
    char str3[50] = {"Vamos aprender a programar?"};
    int tam, i , total= 0, resultado;
    
    eliminarRepetidos(str1, str2);
    printf("str2: %s\n", str2);
    tam = strlen(str2);
    for (i = 0 ; i < tam; i++){
        resultado = ocorrencias(str3, str2[i]);
        printf("%c\t%d\n", str2[i], resultado);
        if(resultado !=0)
            total++;
    }
    printf("\nTotal : %d\n" , total);
    return 0; 
}

*/



/*O que é e como criar um ENUM na linguagem C? | aula 322 



// enum mes {janeiro = 1, fevereiro, marco, abril};



// enum mes nome_da_funcao(enum mes m){
//     printf("--> %d\n", m );
//     return abril;
// }

typedef enum  {janeiro = 1, fevereiro, marco, abril} mes;

mes nome_da_funcao(enum mes m){
    printf("--> %d\n", m );
    return abril;
}


int main (){
   int opcao;

    printf("Digite o numero de um mes: \n");
    scanf("%d", &opcao);

    switch(opcao){
        case janeiro:
            printf("--> Janeiro\n");
            break;
        case fevereiro:
            printf("--> fevereiro\n");
            break;
        case marco:
            printf("--> Marco\n");
            break;
        case abril:
            printf("--> Abril\n");
            break;
        default:
            printf("opção invalida");
            
    }
    printf("Em main %d \n", nome_da_funcao(janeiro));
    
    return 0;
}
*/




