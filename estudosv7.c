#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#include <string.h>// para usar o strlen
#include <ctype.h>
// comando para compilar o codigo criando o a.exe para usar o debug (  gcc -g estudos.c -o a.exe  )
// Ponteiro como parâmetro para uma função ou procedimento 
// void imprimir(int *num){
//     printf("%d\n",*num);
//     *num = 80;
// }
//Vetor é sempre um ponteiro?
// void teste(int vet[], int tam){
//     int i; 
//     for(i=0;i< tam;i++){
//         vet[i] = vet[i] *2;
    
//     }
//     printf("\n");
// }

// void imprimir(int vet[], int tam){
//     int i; 
//     for(i=0;i< tam;i++){
//         printf("%d ", vet[i]);
//     }
//     printf("\n");
// }
// Entendendo aritmética de ponteiros com vetor
// void imprimir(int vet[], int tam){
//     int i; 
//     for(i=0;i< tam;i++){
//         printf("%d ", *(vet + i));// aritimetica de ponteiros para "pegar" o endereço dos proximos
//     }
//     printf("\n");
// }
// Como criar um ponteiro para struct?
// typedef struct {
//     int dia, mes, ano;
// }Data;

// void imprimirData(Data *x){
//     printf("%d/%d/%d\n", x->dia, x->mes, x->ano);
// }


/* minha solução do exericio 1
void Ex1(int vet[], int tam, int *maior, int *menor) {
    int i;
    *maior = vet[0];  // Inicializa com o primeiro elemento do vetor
    *menor = vet[0];

    for (i = 0; i < tam; i++) {
        if (vet[i] > *maior)
            *maior = vet[i];
        if (vet[i] < *menor)
            *menor = vet[i];
    }

    // Imprime uma vez após o laço
    printf("O menor elemento do vetor é: %d\n", *menor);
    printf("O maior elemento do vetor é: %d\n", *maior);
}

*/

/* solução do professor do exercicio 1

void maiorMenor(int *vet, int tam, int *menor, int *maior){
    int i;
    *menor = *vet;
    *maior = *vet;
    for(i = 1; i < tam; i++){
        if(*menor > *(vet + i))
            *menor = *(vet + i);
        if(*maior < *(vet + i))
            *maior = *(vet + i);
    }
}

int main(){
    int menor, maior, v[10] = {45,89,69,23,14,75,2,45,100,58};

    printf("Menor: %d\tMaior: %d\n", menor, maior);
    maiorMenor(v, 10, &menor, &maior);
    printf("Menor: %d\tMaior: %d\n", menor, maior);

    return 0;
}

*/

/*2) Escreva um procedimento que troca os valores dos parâmetros recebidos. Sua assinatura deve
    ser: void troca(float *a, float *b);*/

// void troca(float *a, float *b) {
//     float temp;  // variável temporária para armazenar o valor de *a
//     temp = *a;
//     *a = *b;
//     *b = temp;
//     printf("Depois da troca - A: %.2f e B: %.2f\n", *a, *b);
// }


/*res do professor 

   2) Escreva um procedimento que troca os valores dos parâmetros recebidos.
    Sua assinatura deve ser: void troca(float *a, float *b);
*/
/*
void troca(float *a, float *b){
    float c;
    c = *a;
    *a = *b;
    *b = c;
}

int main(){
    float num1 = 50, num2 = 101;

    printf("Num1: %.2f\tNum2: %.2f\n", num1, num2);
    troca(&num1, &num2);
    printf("Num1: %.2f\tNum2: %.2f\n", num1, num2);

    return 0;
}

*/
// 5) Implemente a função strcpy (char *destino, char *origem) usando ponteiros.


// int strcopy (char *destino, char *origem){
//     int i = 0;

//     while(*(origem + i) != '\0'){
//         *(destino + i) = *(origem + i);
//         i++;
//     }
//     *(destino + i) = '\0';
//     return i;
// }


int main() { setlocale(LC_ALL,"");
    char num = 'f';
    char *p; // ponteiro so armazena endereço de memoria

    p = &num;

    printf("Valor de num : %d\n", num);
    printf("endereco  de num : %p\n", &num);// como printrar o endereço de memonria ele printado no formato hexadecimal

    printf("Valor de p : %p\n", p);
    printf("endereco  de p : %p\n", &p);
    printf("valor apontado por  p : %c\n", *p);// como imprir o valor apontado por p (*p)




    // 5) Implemente a função strcpy (char *destino, char *origem) usando ponteiros.


        // char destino[25], origem[25] = {"Bom dia."};

        // printf("Tamanho: %d\n", strcopy(destino, origem));
        // printf("Destino: %s\n", destino);

    

    // 4) Considere a seguinte declaração: int A, *B, **C, ***D
    // Escreva um programa que leia a variável A e calcule e exiba o dobro, o triplo e o quádruplo desse
    // valor utilizando apenas os ponteiros B, C e D. O ponteiro B deve ser usada para calcular o dobro, C
    // o triplo e D o quádruplo.

   
    // int A, *B, **C, ***D;

    // printf("Digite um valor: ");
    // scanf("%d", &A);

    // B = &A;
    // C = &B;
    // D = &C;

    // printf("O dobro de %d e: %d\n", A, 2 * *B);
    // printf("O triplo de %d e: %d\n", A, 3 * **C);
    // printf("O quadruplo de %d e: %d\n", A, 4 * ***D);


    // 3) Crie um programa que contenha um array de inteiros com 10 elementos. Imprima o elemento e o
    // endereço de cada posição do array.

    // resolução do professor

    // int i, vet[10] = {0,1,2,3,4,5,6,7,8,9};

    // for(i = 0; i < 10; i++)
    //     printf("Endereco: %p\tConteudo: %d\n", vet + i, *(vet + i));

    // int vet[10]= {1,15,14,19,22,39,58,2,47,18}, i ,*p;

    // p = vet;

    // for (i = 0; i < 10; i++) {
    //     printf("O endereço de memória do índice %d é: %p\n", i, (p + i));
    // }

    // for (i = 0; i < 10; i++) {
    //     printf("O valor apontado pelo vetor no indice %d é: %d\n", i, *(p + i));
    // }

    // exercicios de ponteiros.
    /*2) Escreva um procedimento que troca os valores dos parâmetros recebidos. Sua assinatura deve
    ser: void troca(float *a, float *b);*/
    

    // float a = 1.0, b = 2.0;
    
    // printf("Antes da troca - A: %.2f e B: %.2f\n", a, b);
    // troca(&a, &b);



    /*1) Escreva um procedimento que receba um vetor inteiro, seu tamanho e os endereços de duas
    variáveis inteiras, menor e maior, salve nestas variáveis o menor e o maior valor do vetor.*/
    
    // minha solução do exericio 1
    // int vet[10] = {35, 2, 119, 92, 47, 101, 67, 87, 99, 44};
    // int maior, menor;
    // int *Ma = &maior, *Me = &menor;

    // Ex1(vet, 10, Ma, Me);

    // Existe ponteiro pra ponteiro?
    // int a =100, *b, **c;// ponteiro de ponteiro, pode ter ***d e assim por diante

    // b = &a;
    // c = &b;

    // printf("Endereço de A: %p\t Conteudo de A: %d\n " , &a,a);
    // printf("Endereço de B: %p\t Conteudo de P: %p\n " , &b,b);
    // printf("Conteudo apontado por B: %d\n", *b);// o uso do * é realizado quando criamos o ponteiro ou qunado desejamos imprimir o conteudo apontado pelo ponteiro
    // printf("Endereço de B: %p\t Conteudo de P: %p\n " , &c,c);
    // printf("Conteudo apontado por C: %d\n", **c); // o uso do *8 é realizado quando criamos o ponteiro de ponteiro ou qunado desejamos imprimir o conteudo apontado pelo ponteiro do ponteiro

    // Como criar um ponteiro para struct?
    // Data data;
    // Data *p;

    // p = &data;
    // printf("data:  %p\tp: %p\n", &data, p);
    // data.dia = 29;
    // data.mes = 2;
    // data.ano = 2021;
    // imprimirData(p);// acessando o ponteiro da struch data
    // printf("%d/%d/%d\n", data.dia, data.mes, data.ano);// acessando os membros das struct diretamente
    // //qunado for manipular a variavel usa o ., a -> e quando é para ponteiro

    // Entendendo aritmética de ponteiros com vetor
    // int vet[10] = {10,11,12,13,14,15,16,17,18,19};
    // imprimir(vet, 10);
    
    //Vetor é sempre um ponteiro?
    // int vet[10] = {10,11,12,13,14,15,16,17,18,19};
    // imprimir(vet, 10);
    // teste(vet, 10);
    // imprimir(vet, 10);
;
    // Ponteiro como parâmetro para uma função ou procedimento 
    // int idade = 35;

    // imprimir(&idade);
    // printf("no main: %d", idade);

    // Por que não usamos & ao ler uma string com a função scanf?
    // char palavra[100];// um vetor(o nome dele) por si so é um ponteiro 

    // // scanf("%100[^\n]", palavra);
    // // printf("%s\n", palavra);
    // printf("%p\n", palavra);
    // printf("%p\n", &palavra);
    // printf("%p\n", &palavra[0]);


    // qual o  tamanho de um ponteiro na linguagem C
    // int *p;
    // char *p2;
    // float *p3;

    // printf("O tamanho : %d\n", sizeof(p));
    // printf("O tamanho : %d\n", sizeof(p2));
    // printf("O tamanho : %d\n", sizeof(p3));
    // o tamanho sempre será o mesmo porque ele so recebe o endereço de memória
    // oque são e como criar um ponteiro
    // char num = 'f';
    // char *p; // ponteiro so armazena endereço de memoria

    // p = &num;

    // printf("Valor de num : %d\n", num);
    // printf("endereco  de num : %p\n", &num);// como printrar o endereço de memonria ele printado no formato hexadecimal

    // printf("Valor de p : %p\n", p);
    // printf("endereco  de p : %p\n", &p);
    // printf("valor apontado por  p : %c\n", *p);// como imprir o valor apontado por p (*p)
// }
return 0;
}