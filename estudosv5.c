#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#include <string.h>// para usar o strlen
#include <ctype.h>
// comando para compilar o codigo criando o a.exe para usar o debug (  gcc -g estudos.c -o a.exe  )


// tipo de retorno - identificador - par�metros // criando um fun��o que retorna o tamnho de uma string
// int minhaStrLen(char str[] ){
//     int tam = 0; 

//     while(str[tam] != '\0' ){
//         tam++;
//     }
//     return tam;
// }
// // procedimento void n�o tem retorno ou retorno vazio
// // criando um procedimento para imprimir uma string
// void imprirString(char palavra[]){
//     int i = 0;
    
//     while(palavra[i]!= '\0'){
//         printf("%c", palavra[i]);
//         i++;
//     }
//     printf("\n");
// } 

// int idade2= 35; //vari�vel global 

// void imprimir(int id){
//     id++;
//     idade2++;
// }

// int mat[5][5];
// int tam = 5;

// void imprimir2(int m[][5]){
//     int i, j ;
//      for (i = 0;i < tam; i++){
//         for(j = 0 ; j < tam ; j++ ){
//             printf("%2d ", mat[i][j]);
//         }
//         printf("\n");
//     }
// }

// // fun��o que retorna a soma de uma linha da matriz
// int somarLinha( int l ){
//     int c, soma = 0; 
//     for (c=0; c< tam; c++)
//         soma  += mat[l][c];
//     return soma;
// }

// // fun��o que retorna a soma de uma coluna da matriz
// int somarColuna (int c ){
//     int l, soma = 0; 
//     for (l= 0; l< tam; l++)
//         soma  += mat[l][c];
//     return soma;
// }
// // procedimento que coverte uma string para mai�sculo
// void maiusculo(char s1[], char s2[]){
//     int i =0;
//     while(s1[i] != '\0'){
//         s2[i] = toupper(s1[i]);
//         i++;
//     }
//     s2[i]='\0';
// }
// // procedimento que coverte uma string para min�sculo 
// void minusculo(char s1[], char s2[]){
//     int i =0;
//     while(s1[i] != '\0'){
//         s2[i] = tolower(s1[i]);
//         i++;
//     }
//     s2[i]='\0';
// }

// fun��es e procedimentos recursivos
    //  exemplo imprimir todos os n�meros de n at� 0

// void imprimir(int x){
//     if (x ==0){
//         printf("%d ", x);
//     }
//     else{
//         printf("%d ", x);
//         imprimir(x-1);// chamada recursiva
//     }
// }

// void imprimir2(int x){
//     if (x ==0){
//         printf("%d ", x);
//     }
//     else{
//         imprimir2(x - 1); // chamada recursiva
//         printf("%d ", x);
        
//     }
// }
// int fatorial(int n ){
//     if(n==0 || n ==1)
//         return 1;
//     else{
//         // 5 * 4!
//         return n * fatorial(n-1);
//     }
// }

// calcular o en�simo termo da sequ�ncia de fibonacci com recurs�o

// int fibonnaci(int n){
//     if (n == 1 )
//      return 0;
//     else{
//         if (n ==2)
//             return 1;
//         else
//             return fibonnaci(n-1) + fibonnaci(n-2) ;
//     }

// }

// fun��o pot�ncia recursiva que rtorne o valor de x elevado n 
// int potencia(int x , int n){
//     if ( n == 0)
//         return 1;
//     else
//         return x * potencia(x, n-1);
// }
// como calcular o somat�rio de 1 ate n com recurs�o 

// int soma( int n ){
//     if (n == 0){
//         return 0;
//     }
//     else{
//         return n + soma(n-1);
//     }
// }

// como somar os elementos de um vetor com recurs�o

// int somavet( int v[], int tam ){
//     if(tam == 0 )
//         return 0;
//     else
//         return v[tam - 1] + somavet(v,tam -1 );
// }

// como descobrir o maior elemento de um vetor com recurs�o 


// int maior(int v[], int tam, int indice){
//     if (tam == 0)
//         return v[indice];
//     else{
//         if(v[tam-1] > v[indice])
//             return maior(v, tam-1, tam-1);
//         else
//             return maior(v, tam -1 ,indice); 
//     }
// }

 // como iverter a posi��o dos elementos de um vetor com recurs�o
// void imprimir(int v[], int tam){
//     if (tam == 1)
//         printf("%d ", v[tam-1]);
//     else{
//         imprimir(v, tam-1);
//         printf("%d, ", v[tam-1]);
//     }
// }

// void imprimirInverso(int v[], int ini, int fim){
//     int aux;
//     if (ini < fim){
//         aux = v[ini];
//         v[ini] = v[fim];
//         v[fim] = aux;
//         imprimirInverso(v,ini+1, fim-1);
//     }
       
// }
// como converter um n�mero decimal em bin�rio
// void binario(int n ){
//     if(n == 0)
//         printf("%d",  n);
//     else{
//         binario(n/2);// como aqui tanto n como o 2 � inteiro o resultado sera inteiro 
//         printf("%d", n%2);
//     }

// }

// tempo de execu��o entre fibonacci recursivo e iterativo
/*
        Aula 165: Calcular o tempo de execu��o do algoritmo de FIBONACCI recursivo e iterativo.

        Escrito por Wagner Gaspar
        Mar�o de 2021
*/
/*
        Fun��o recursiva para calcular um termo n da sequ�ncia de fibonacci
        Como a sequ�ncia cresce muito r�pido, est� sendo usado o operador long para que o tipo int ocupe 8 bytes.
*/
// long long int fiboR(int n){
//     if(n == 1)
//         return 0;
//     else{
//         if(n == 2)
//             return 1;
//         else
//             return fiboR(n - 1) + fiboR(n - 2);
//     }
// }


/*
        Fun��o iterativa para calcular um termo n da sequ�ncia de fibonacci
        Como a sequ�ncia cresce muito r�pido, est� sendo usado o operador long para que o tipo int ocupe 8 bytes.
*/

// long long int fiboI(int n){
//     long long int a = 0, b = 1, c;
//     int i = 2;
//     if(n == 1)
//         return a;
//     else{
//         if(n == 2)
//             return b;
//         else{
//             while(i < n){
//                 c = a + b;
//                 a = b;
//                 b = c;
//                 i++;
//             }
//             return c;
//         }
//     }
// }

/*
        Aula 166: Jogo da velha com fun��es e procedimentos

        Escrito por Wagner Gaspar
        Mar�o de 2021
*/

// vari�veis globais
char jogo[3][3]; // matriz do jogo
int l, c; // �ndices para linha e coluna

// procedimento para inicializar todas as posi��es da matriz com um espa�o
void inicializarMatriz(){
    for(l = 0; l < 3; l++){
        for(c = 0; c < 3; c++)
            jogo[l][c] = ' ';
    }
}

// procedimento para imprimir o jogo na tela
void imprimir(){
    printf("\n\n\t 0   1   2\n\n");
    for(l = 0; l < 3; l++){
        for(c = 0; c < 3; c++){
            if(c == 0)
                printf("\t");
            printf(" %c ", jogo[l][c]);
            if(c < 2)
                printf("|");
            if(c == 2)
                printf("   %d", l);
        }
        printf("\n");
        if(l < 2)
            printf("\t-----------\n");
    }
}

/*
    fun��o para verificar vit�ria do jogador c na linha l
    1 - ganhou
    0 - n�o ganhou ainda
*/
int ganhouPorLinha(int l, char c){
    if(jogo[l][0] == c && jogo[l][1] == c && jogo[l][2] == c)
        return 1;
    else
        return 0;
}

/*
    fun��o para verificar vit�ria do jogador c nas linhas
    1 - ganhou
    0 - n�o ganhou ainda
*/
int ganhouPorLinhas(char c){
    int ganhou = 0;
    for(l = 0; l < 3; l++){
        ganhou += ganhouPorLinha(l, c);
    }
    return ganhou;
}

/*
    fun��o para verificar vit�ria do jogador j na coluna c
    1 - ganhou
    0 - n�o ganhou ainda
*/
int ganhouPorColuna(int c, char j){
    if(jogo[0][c] == j && jogo[1][c] == j && jogo[2][c] == j)
        return 1;
    else
        return 0;
}

/*
    fun��o que verifica vit�ria do jogador j por colunas
    1 - ganhou
    0 - n�o ganhou ainda
*/
int ganhouPorColunas(char j){
    int ganhou = 0;
    for(c = 0; c < 3; c++){
        ganhou += ganhouPorColuna(c, j);
    }
    return ganhou;
}

/*
    fun��o para verificar vit�ria do jogador c na diagonal principal
    1 - vit�ria
    0 - n�o ganhou
*/
int ganhouPorDiagPrin(char c){
    if(jogo[0][0] == c && jogo[1][1] == c && jogo[2][2] == c)
        return 1;
    else
        return 0;
}

/*
    fun��o para verificar vit�ria do jogador c na diagonal secund�ria
    1 - vit�ria
    0 - n�o ganhou
*/
int ganhouPorDiagSec(char c){
    if(jogo[0][2] == c && jogo[1][1] == c && jogo[2][0] == c)
        return 1;
    else
        return 0;
}

/*
    fun��o que diz se uma coordenada � v�lida ou n�o
    1 - � v�lida
    0 - n�o � v�lida
*/
int ehValida(int l, int c){
    if(l >= 0 && l < 3 && c >= 0 && c < 3 && jogo[l][c] == ' ')
        return 1;
    else
        return 0;
}

// procedimento para ler as coordenadas digitadas pelo jogador
void lerCoordenadas(char j){
    int linha, coluna;

    printf("Digite linha e coluna: ");
    scanf("%d%d", &linha, &coluna);

    while(ehValida(linha, coluna) == 0){
        printf("Coordenadas invalidas! Digite outra linha e coluna: ");
        scanf("%d%d", &linha, &coluna);
    }
    jogo[linha][coluna] = j;
}

// fun��o que retorna a quantidade de posi��es ainda vazias (n�o jogadas)
int quantVazias(){
    int quantidade = 0;

    for(l = 0; l < 3; l++){
        for(c = 0; c < 3; c++)
            if(jogo[l][c] == ' ')
                quantidade++;
    }
    return quantidade;
}

// procedimento jogar com o loop (repeti��o) principal do jogo
void jogar(){
    int jogador = 1, vitoriaX = 0, vitoria0 = 0;
    char jogador1 = 'X', jogador2 = '0';

    do{
        imprimir();
        if(jogador == 1){
            lerCoordenadas(jogador1);
            jogador++;
            vitoriaX += ganhouPorLinhas(jogador1);
            vitoriaX += ganhouPorColunas(jogador1);
            vitoriaX += ganhouPorDiagPrin(jogador1);
            vitoriaX += ganhouPorDiagSec(jogador1);
        }
        else{
            lerCoordenadas(jogador2);
            jogador = 1;
            vitoria0 += ganhouPorLinhas(jogador2);
            vitoria0 += ganhouPorColunas(jogador2);
            vitoria0 += ganhouPorDiagPrin(jogador2);
            vitoria0 += ganhouPorDiagSec(jogador2);
        }
    }while(vitoriaX == 0 && vitoria0 == 0 && quantVazias() > 0);

    imprimir();

    if(vitoria0 == 1)
        printf("\nParabens Jogador 2. Voce venceu!!!\n");
    else if(vitoriaX == 1)
        printf("\nParabens Jogador 1. Voce venceu!!!\n");
    else
        printf("\nQue pena. Perderam!!!\n");
}

int main() { setlocale(LC_ALL,"");
    // jogo da velha com fun��es e procedimentos
    int opcao;

    do{
        inicializarMatriz();
        jogar();

        printf("\nDigite 1 para jogar novamente: ");
        scanf("%d", &opcao);
    }while(opcao == 1);

    return 0;




    // tempo de execu��o entre fibonacci recursivo e iterativo
    // int n = 150;
    // time_t tIni, tFim;

    // tIni = time(NULL); // obtem a hora do computador
    // printf("Fibonacci iterativo: %lld\n", fiboI(n));
    // tFim = time(NULL);
    // printf("\tTempo em segundos: %f\n\n", difftime(tFim, tIni)); // diferen�a entre a hora de in�cio e a hora de fim

    // tIni = time(NULL);
    // printf("Fibonacci recursivo: %lld\n", fiboR(n));
    // tFim = time(NULL);
    // printf("\tTempo em segundos: %f\n\n", difftime(tFim, tIni));

    // como converter um n�mero decimal em bin�rio
    /*      Resultado  resto         resultado resto            reultado  resto
        3/2     1       1       4/2     2       0       10/2    5           0
        1/2     0       1       2/2     1       0       5/2     2           1
                                1/2     0       1       2/2     1           0
                                                        1/2     0           1
        3 em bin�rio: 011       4 em binario: 0100      10 em binario : 01010
    lembrando que a divis� o � inteira
    (pega o ultimo resultado da divis�o + ultimo resto e os anteriores tamb�m)
    */
    // int n; 

    // printf("Digite um valor decimal: ");
    // scanf("%d", &n);

    // binario(n);

    // como iverter a posi��o dos elementos de um vetor com recurs�o

    // int vet[10] = {11,342,453,884,45,7896,457,4218,4779,110};

    // imprimir(vet, 10);
    // imprimirInverso(vet, 0, 9); // vetor, �ndice inicial e �ndice final
    // printf("\n\n");
    // imprimir(vet, 10);
    // como descobrir o maior elemento de um vetor com recurs�o 

    // int vet[10] = {11,342,453,884,45,7896,457,4218,4779,110};

    // printf("Maior : %d\n ",maior(vet, 10, 0)); 


    // como calcular o somat�rio de 1 ate n com recurs�o 
    //  int n;

    // printf("Digite N: ");
    // scanf("%d", &n );

    // printf(" A soma de 1 at� %d: %d\n ",n,soma(n));


    // fun��o pot�ncia recursiva que rtorne o valor de x elevado n 
    // int n, x; 

    // printf("Digite um valor para x e para n(x^n): ");
    // scanf("%d%d", &x ,&n );

    // printf("Resultado de %d elevado a %d: %d\n: ",x,n,potencia());

    // calcular o en�simo termo da sequ�ncia de fibonacci com recurs�o

    // int n; 

    // printf("Digite um valor maior que zero: ");
    // scanf("%d", &n);

    // printf("o %d da semquuencia de finonacci � igual a : %d", n , fibonnaci(n));


    // como calcular o fatorial com recurs�o , so lembrando que fatorial !0= 1 e !1 = 1
    // int n; 

    // printf("Digite um valor maior que zero: ");
    // scanf("%d", &n);

    
    // fatorial(n);
    // printf("O fatorial de %d igual: %d ", n, fatorial(n));

    // fun��es e procedimentos recursivos
    //  exemplo imprimir todos os n�meros de n at� 0
    // int n; 

    // printf("Digite um valor maior que zero: ");
    // scanf("%d", &n);

    // printf("Imprimindo de N at� 0:\n");
    // imprimir(n);
    // printf("\nImprimindo de 0 at� N:\n");
    // imprimir2(n); 





    // como converter n�mero para texto em c?

    //codigo feito pelo chat achei melhor que o scanf
    // int tam;
    
    // printf("Digite o tamanho do vetor: ");
    // scanf("%d", &tam);
    // getchar(); // Limpa o buffer ap�s ler o inteiro

    // char palavras[tam + 1];  // Cria um vetor de tamanho din�mico
    // printf("Digite uma frase: ");
    // fgets(palavras, tam + 1, stdin);  // Usa fgets para ler a frase

    // printf("A frase digitada foi: %s\n", palavras);

    // return 0;

    // int tam;
    // char str1[10] = {"%"}, str2[10];

    // printf("Digite o tamanho do vetor:  ");
    // scanf("%d", &tam);
    // scanf("%c");

    // // sprintf(str2, "%d[^\n]",tam);
    // snprintf(str2, 10, "%d[^\n]",tam);
    // strcat(str1, str2);
    
    // printf("%s\n", str2);

    // char palavras[tam];

    // printf("Digite uma frase: ");
    // scanf(str1, palavras);

    // printf("%s\n", palavras);

    // ciar um procedimento para converter uma string para mai�sculo e um para min�scula.
    
    // char str1[] = "Ola Bom Dia";
    // char str2[50];
    // printf("%s\n", str1);

    // maiusculo(str1, str2);
    // printf("%s\n", str2);

    // minusculo(str1, str2);
    // printf("%s\n", str2);
    // fun��o que retorna a soma de uma coluna da matriz
    
    // int i , j;
    
    // srand(time(NULL));

    // for (i = 0;i < tam; i++){
    //     for(j = 0 ; j < tam ; j++ ){
    //         mat[i][j] = rand() % 10;
    //     }
    // }
    // imprimir2(mat);
    // printf("\n");
    // for (i =0; i < tam; i++)
    //     printf("Soma da linha %d: %d\n",i,somarLinha(i));
    // printf("\n");
    // for (i =0; i < tam; i++)
    //     printf("Soma da linha %d: %d\n",i,somarColuna(i));

    // fun��o que retorna a soma deuma linha da matriz

    // int mat[5][5];
    // int i , j;
    
    // srand(time(NULL));

    // for (i = 0;i < tam; i++){
    //     for(j = 0 ; j < tam ; j++ ){
    //         mat[i][j] = rand() % 10;
    //     }
    // }
    // imprimir2(mat);
    // for (i =0; i < tam; i++)
    //     printf("Soma da linha %d: %d\n",i,somarLinha(mat,i));
    
    // Vari�veis locais, globais e escopo de vari�veis 
    // int idade = 25;// vari�vel local dentro do escopo da fun��o main

    // printf("\n Idade: %d\n", idade);
    // printf("\n Idade2: %d\n", idade2);
    // imprir(idade);
    // printf("\n Idade: %d\n", idade);
    // printf("\n Idade2: %d\n", idade2);
    
    
    // criando um procedimento para imprimir uma string
    // char vet[20] = {"ol�. bom dia"};
    // printf("Strlen: %d\n", strlen(vet));

    // printf("minha Strlen: %d\n", minhaStrLen(vet));
    // imprirString(vet);

    // criando um fun��o que retorna o tamnho de uma string
    // char vet[20] = {"ol�. bom dia"};

    // printf("Strlen: %d\n", strlen(vet));

    // printf("minha Strlen: %d\n", minhaStrLen(vet));

    // oque s�o fun��es e procedimentos
    // int tam = 0, num, num2;

    // tam = printf("Hello");

    // tam = scanf("%d%d", &num, &num2);

    // printf("\nTamanho: %d\n", tam);

    return 0;
}
