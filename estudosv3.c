#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// #include <math.h>
#include <time.h>
// comando para compilar o codigo criando o a.exe para usar o debug (  gcc -g estudos.c -o a.exe  )

int main() {
    // setlocale(LC_ALL,"");
    // // 16) Fa�a um programa para jogar o jogo da velha. Ao final imprima o resultado do jogo e pergunte
    // // se deseja jogar novamente.
    // int l, c, linha, coluna, jogador, ganhou, jogadas, opcao;
    // char jogo[3][3];

    // do{ // deseja jogar novamente?
    //     jogador = 1;
    //     ganhou = 0;
    //     jogadas = 0;
    //     // como inicializar nossa estrutura de dados?
    //     for(l = 0; l < 3; l++){
    //         for(c = 0; c < 3; c++){
    //             jogo[l][c] = ' ';
    //         }
    //     }

    //     do{ // repete at� algu�m ganhar ou atingir 9 jogadas
    //         // imprimir jogo
    //         printf("\n\n\t 0   1   2\n\n");
    //         for(l = 0; l < 3; l++){
    //             for(c = 0; c < 3; c++){
    //                 if(c == 0)
    //                     printf("\t");
    //                 printf(" %c ", jogo[l][c]);
    //                 if(c < 2)
    //                     printf("|");
    //                 if(c == 2)
    //                     printf("  %d", l);
    //             }
    //             if(l < 2)
    //                 printf("\n\t-----------");
    //             printf("\n");
    //         }

    //         // ler coordenadas
    //         do{
    //             printf("\n\JOGADOR 1 = 0\nJOGADOR 2 = X\n");
    //             printf("\nJOGADOR %d: Digite a linha e a coluna que deseja jogar: ", jogador);
    //             scanf("%d%d", &linha, &coluna);
    //         }while(linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || jogo[linha][coluna] != ' ');

    //         // salvar coordenadas
    //         if(jogador == 1){
    //             jogo[linha][coluna] = '0';
    //             jogador++;
    //         }
    //         else{
    //             jogo[linha][coluna] = 'X';
    //             jogador = 1;
    //         }
    //         jogadas++;

    //         // algu�m ganhou por linha
    //         if(jogo[0][0] == '0' && jogo[0][1] == '0' && jogo[0][2] == '0' ||
    //            jogo[1][0] == '0' && jogo[1][1] == '0' && jogo[1][2] == '0' ||
    //            jogo[2][0] == '0' && jogo[2][1] == '0' && jogo[2][2] == '0'){
    //             printf("\nParabens! O jogador 1 venceu por linha!\n");
    //             ganhou = 1;
    //         }

    //         if(jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X' ||
    //            jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X' ||
    //            jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X'){
    //             printf("\nParabens! O jogador 2 venceu por linha!\n");
    //             ganhou = 1;
    //         }

    //         // algu�m ganhou por coluna
    //         if(jogo[0][0] == '0' && jogo[1][0] == '0' && jogo[2][0] == '0' ||
    //            jogo[0][1] == '0' && jogo[1][1] == '0' && jogo[2][1] == '0' ||
    //            jogo[0][2] == '0' && jogo[1][2] == '0' && jogo[2][2] == '0'){
    //             printf("\nParabens! O jogador 1 venceu por coluna!\n");
    //             ganhou = 1;
    //         }

    //         if(jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X' ||
    //            jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X' ||
    //            jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X'){
    //             printf("\nParabens! O jogador 2 venceu por coluna!\n");
    //             ganhou = 1;
    //         }

    //         // algu�m ganhou na diagonal principal
    //         if(jogo[0][0] == '0' && jogo[1][1] == '0' && jogo[2][2] == '0'){
    //             printf("\nParabens! O jogador 1 venceu na diag. principal!\n");
    //             ganhou = 1;
    //         }

    //         if(jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X'){
    //             printf("\nParabens! O jogador 2 venceu na diag. principal!\n");
    //             ganhou = 1;
    //         }

    //         // algu�m ganhou na diagonal secund�ria
    //         if(jogo[0][2] == '0' && jogo[1][1] == '0' && jogo[2][0] == '0'){
    //             printf("\nParabens! O jogador 1 venceu na diag. secindaria!\n");
    //             ganhou = 1;
    //         }

    //         if(jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X'){
    //             printf("\nParabens! O jogador 2 venceu na diag. secundaria!\n");
    //             ganhou = 1;
    //         }
    //     }while(ganhou == 0 && jogadas < 9);

    //     // imprimir jogo
    //     printf("\n\n\t 0   1   2\n\n");
    //     for(l = 0; l < 3; l++){
    //         for(c = 0; c < 3; c++){
    //             if(c == 0)
    //                 printf("\t");
    //             printf(" %c ", jogo[l][c]);
    //             if(c < 2)
    //                 printf("|");
    //             if(c == 2)
    //                 printf("  %d", l);
    //         }
    //         if(l < 2)
    //             printf("\n\t-----------");
    //         printf("\n");
    //     }

    //     if(ganhou == 0)
    //         printf("\nO jogo finalizou sem gamhador!\n");

    //     printf("\nDigite 1 para jogar novamente: \n");
    //     scanf("%d", &opcao);
    // }while(opcao == 1);

    // 15) Dada uma matriz 4 x 4 fa�a um programa que diga se ela � um Quadrado M�gico ou n�o.
    // int tam = 4, l, c, soma, total, falha = 0;
    // int mat[4][4] = {16,3,2,13,5,10,11,8,9,6,7,12,4,15,14,1};

    // soma = 0;
    // for(l = 0; l < tam; l++){ // soma da diagonal principal
    //     soma += mat[l][l];
    // }
    // printf("Diag. principal: %d\n", soma);
    // total = soma; // salva a soma da diagonal principal na vari�vel total

    // soma = 0;
    // for(l = 0; l < tam; l++){ // soma da diagonal secund�ria
    //     soma += mat[l][tam - 1 - l];
    // }
    // printf("Diag. secundaria: %d\n", soma);

    // if(total != soma)
    //     printf("Diagonal secundaria eh diferente!\n");

    // for(l = 0; l < tam; l++){ // soma da linhas
    //     soma = 0;
    //     for(c = 0; c < tam; c++)
    //         soma += mat[l][c];
    //     printf("Linha %d: %d\n", l, soma);

    //     if(total != soma){
    //         printf("Linha %d eh diferente\n", l);
    //         falha++;
    //     }
    // }

    // for(c = 0; c < tam; c++){ // soma das colunas s�o iguais
    //     soma = 0;
    //     for(l = 0; l < tam; l++)
    //         soma += mat[l][c];
    //     printf("Coluna %d: %d\n", c, soma);

    //     if(total != soma){
    //         printf("Coluna %d eh diferente\n", c);
    //         falha++;
    //     }
    // }

    // if(falha == 0)
    //     printf("\nHe um quadrado magico!!!!\n");


    // como gerar numeros sem repeti��o com fun��o rand()

    // int i = 0, j, igual, vet[25];

    // srand(time(NULL));

    // do{ // fa�a
    //     vet[i] = rand() % 30; // sorteia um n�mero
    //     igual = 0;
    //     for(j = 0; j < i; j++){ // percorre a parte do vetor j� preenchida
    //         if(vet[j] == vet[i])
    //             igual = 1; // n�mero repetido
    //     }

    //     if(igual == 0) // significa que o elemento n�o se repetiu
    //         i++;
    // }while(i < 25); // enquanto n�o for sorteado 25 n�meros diferentes

    // for(i = 0; i < 25; i++){
    //     printf("%d ", vet[i]);
    // }
    // printf("\n\n"); 


    // 14) Fa�a um programa que imprima na tela apenas os valores abaixo da diagonal principal de uma
    // matriz 4 x 4.

    // tamb�m coloquei os numero da matriz pra cima da principal
    // int tam = 10;
    // int l, c, mat[tam][tam];

    // srand(time(NULL));

    // for(l = 0; l < tam; l++){
    //     for(c = 0; c < tam; c++)
    //         mat[l][c] = rand() % 100;
    // }

    // printf("\n\nMatriz gerada:\n");
    // for(l = 0; l < tam; l++){
    //     for(c = 0; c < tam; c++)
    //         printf("%2d ", mat[l][c]);
    //     printf("\n");
    // }

    // printf("\nacima da diagonal principal:\n");
    // for(l = 0; l < tam; l++){
    //     for(c = 0; c < tam; c++){
    //         if(l < c)
    //             printf("%2d ", mat[l][c]);
    //         else
    //             printf("   ");
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    // printf("\n diagonal principal:\n");
    // for(l = 0; l < tam; l++){
    //     for(c = 0; c < tam; c++){
    //         if(l == c)
    //             printf("%2d ", mat[l][c]);
    //         else
    //             printf("   ");
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    // printf("\n\nAbaixo da diagonal principal:\n");
    // for(l = 0; l < tam; l++){
    //     for(c = 0; c < tam; c++){
    //         if(l > c)
    //             printf("%2d ", mat[l][c]);
    //         else
    //             printf("   ");
    //     }
    //     printf("\n");
    // }
    // printf("\n\n");


    // 13) Fa�a um programa para calcular a transposta de uma matriz 5 x 4. Imprima as duas matrizes na
    // tela.
    // int tamL = 5, tamC = 4;
    // int l, c, mat[tamL][tamC], trans[tamC][tamL];

    // srand(time(NULL));

    // for(l = 0; l < tamL; l++){
    //     for(c = 0; c < tamC; c++){
    //         mat[l][c] = rand() % 500;
    //     }
    // }

    // printf("\nMatriz original:\n");
    // for(l = 0; l < tamL; l++){
    //     for(c = 0; c < tamC; c++){
    //         printf("%3d ", mat[l][c]);
    //     }
    //     printf("\n");
    // }

    // for(l = 0; l < tamL; l++){
    //     for(c = 0; c < tamC; c++){
    //         trans[c][l] = mat[l][c];
    //     }
    // }

    // printf("\nMatriz transposta:\n");
    // for(l = 0; l < tamC; l++){
    //     for(c = 0; c < tamL; c++){
    //         printf("%3d ", trans[l][c]);
    //     }
    //     printf("\n");
    // }




    // 12) Fa�a um programa que imprima na tela a diagonal secund�ria de uma matriz 7 x 7.
    //solu��o do professor
    // int tam = 10;
    // int l, c, mat[tam][tam];

    // srand(time(NULL));

    // // preenche a matriz gerando valores aleat�rios
    // for(l = 0; l < tam; l++){
    //     for(c = 0;  c< tam; c++){
    //         mat[l][c] = rand() % 100;
    //     }
    // }

    // // imprime a matriz na tela
    // for(l = 0; l < tam; l++){
    //     for(c = 0;  c< tam; c++){
    //         printf("%2d ", mat[l][c]);
    //     }
    //     printf("\n");
    // }

    // printf("\n\nDiagonal principal: ");
    // for(l = 0; l < tam; l++){
    //     printf("%d ", mat[l][l]);
    // }

    // printf("\n\nDiagonal secundaria: ");
    // for(l = 0; l < tam; l++){
    //     printf("%d ", mat[l][tam - 1 - l]);
    // }
    // printf("\n\n");

    // solu��o
    // int i, j, tam = 7, matriz[tam][tam];;
    // srand(time(NULL));

    // // Preenchendo a matriz com valores de exemplo
    // printf("Digite os valores da matriz 7x7:\n");
    // for (i = 0; i < tam; i++) {
    //     for (j = 0; j < tam; j++) {
    //         matriz[i][j] = rand()%100;
    //     }
    // }

    // // Imprimindo a matriz completa (opcional, para refer�ncia)
    // printf("\nMatriz completa:\n");
    // for (i = 0; i < tam; i++) {
    //     for (j = 0; j < tam; j++) {
    //         printf("%3d ", matriz[i][j]);
    //     }
    //     printf("\n");
    // }

    // // Imprimindo a diagonal secund�ria
    // printf("\nDiagonal Secund�ria:\n");
    // for (i = 0; i < tam; i++) {
    //     printf("%d ", matriz[i][tam - 1 - i]);
    // }
    // printf("\n");

   



    // 11) Fa�a um programa que imprima na tela a diagonal principal de uma matriz 5 x 5.

    
//    srand(time(NULL));  // Inicializa o gerador de n�meros aleat�rios

//     int l, c, mat[5][5], soma = 0;

//     // Preenchimento da matriz e c�lculo da soma da diagonal principal
//     for (l = 0; l < 5; l++) {
//         for (c = 0; c < 5; c++) {
//             mat[l][c] = rand() % 100;  // Gera n�meros entre 0 e 99
//             if (l == c)
//                 soma += mat[l][c];  // Soma os elementos da diagonal principal
//         }
//     }

//     // Impress�o da matriz 5x5
//     printf("Matriz 5x5:\n");
//     for (l = 0; l < 5; l++) {
//         for (c = 0; c < 5; c++) {
//             printf("%2d ", mat[l][c]);
//         }
//         printf("\n");
//     }

//     // Impress�o da diagonal principal
//     printf("\nDiagonal principal:\n");
//     for (l = 0; l < 5; l++) {
//         for (c = 0; c < 5; c++) {
//             if (l == c) {
//                 printf("%2d ", mat[l][c]);  // Imprime o valor da diagonal
//             } else {
//                 printf("   ");  // Espa�amento para manter a forma da matriz
//             }
//         }
//         printf("\n");
//     }

//     // Exibir a soma da diagonal principal
//     printf("\nA soma da diagonal principal �: %d\n", soma);



    // solu��o do professor

    // int main() {
    // int tam = 5;
    // int l, c, mat[tam][tam];

    // srand(time(NULL));

    // for(l = 0; l < tam; l++){
    //     for(c = 0;  c< tam; c++){
    //         mat[l][c] = rand() % 100;
    //     }
    // }

    // for(l = 0; l < tam; l++){
    //     for(c = 0;  c< tam; c++){
    //         printf("%d ", mat[l][c]);
    //     }
    //     printf("\n");
    // }

    // printf("\n\n");
    // for(l = 0; l < tam; l++){
    //     printf("%d ", mat[l][l]); // diagonal principal onde linha e coluna s�o iguais
    // }
    
    // solu��o minha
    // srand(time(NULL));

    // int l, c, mat[5][5], soma = 0;

    // for(l = 0; l < 5; l++){
    //     for(c = 0; c < 5; c++){
    //         mat[l][c] = rand() % 100;
    //         if (l == c)
    //             soma += mat[l][c];
    //     }
    // }

    // for(l = 0; l < 5; l++){
    //     for(c = 0; c < 5; c++){
    //         printf("%2d ", mat[l][c]);
    //     }
    //     printf("\n");
    // }

    // printf("\n");
    // printf("A soma da diagonal principal � : %d", soma);

    // 10) Dadas duas matrizes A e B 3 x 3, fa�a um programa para calcular a soma das matrizes e salvar
    // em uma matriz C. Imprima as tr�s matrizes
    // solu��o do professor
    // int tam = 3;
    // int l, c, A[tam][tam], B[tam][tam], C[tam][tam];

    // srand(time(NULL));

    // for(l = 0; l < tam; l++){
    //     for(c = 0; c < tam; c++){
    //         A[l][c] = rand() % 100; // sorteia valor para a posi��o l c da matriz A
    //         B[l][c] = rand() % 100; // sorteia valor para a posi��o l c da matriz B
    //         C[l][c] = A[l][c] + B[l][c]; // soma os valores das matrizes A e B e salva na matriz C
    //     }
    // }

    // printf("\nMatriz A\n");
    // for(l = 0; l < tam; l++){
    //     for(c = 0; c < tam; c++)
    //         printf("%3d ", A[l][c]);
    //     printf("\n");
    // }

    // printf("\nMatriz B\n");
    // for(l = 0; l < tam; l++){
    //     for(c = 0; c < tam; c++)
    //         printf("%3d ", B[l][c]);
    //     printf("\n");
    // }

    // printf("\nMatriz C\n");
    // for(l = 0; l < tam; l++){
    //     for(c = 0; c < tam; c++)
    //         printf("%3d ", C[l][c]);
    //     printf("\n");
    // }

    // return 0;


    // minha solu��o 
    // int l, c , matA[3][3], matB[3][3], matC[3][3] = {0};
    
    // srand(time(NULL));

    // for(l = 0; l < 3; l++){
    //     for(c = 0; c < 3; c++){
    //         matA[l][c] = rand() % 100;
    //         matB[l][c] = rand() % 100;
    //         matC[l][c] = matA[l][c] + matB[l][c];
    //     }
       
    // }

    // for(l = 0; l < 3; l++){
    //     for(c = 0; c < 3; c++){
    //         printf("%2d ", matA[l][c]);
    //     }
    //    printf("\n");
    // }
    // printf("\n");
    // for(l = 0; l < 3; l++){
    //     for(c = 0; c < 3; c++){
    //         printf("%2d ", matB[l][c]);
    //     }
    //    printf("\n");
    // }
    // printf("\n");
    // for(l = 0; l < 3; l++){
    //     for(c = 0; c < 3; c++){
    //         printf("%2d ", matC[l][c]);
    //     }
    //    printf("\n");
    // }

    // 9) Crie um programa que preencha uma matriz 5x10 com n�meros inteiros. Em seguida fa�a:
    // a) some cada uma das linhas armazenando o resultado em um vetor;
    // b) some cada uma das colunas armazenando o resultado em um vetor;
    // c) Imprima os dois vetores identificando qual � a soma das linhas e qual � a soma das colunas.

    // int l, c, soma, mat[5][10], somaLinhas[5], somaColunas[10];

    // srand(time(NULL));

    // // preenche a matriz
    // for(l = 0; l < 5; l++){
    //     for(c = 0; c < 10; c++){
    //         mat[l][c] = rand() % 100;
    //     }
    // }

    // // letra a) soma das linhas
    // for(l = 0; l < 5; l++){
    //     soma = 0;
    //     for(c = 0; c < 10; c++){
    //         soma += mat[l][c];
    //     }
    //     somaLinhas[l] = soma;
    // }

    // // letra b) soma das colunas
    // for(c = 0; c < 10; c++){
    //     soma = 0;
    //     for(l = 0; l < 5; l++){
    //         soma += mat[l][c];
    //     }
    //     somaColunas[c] = soma;
    // }

    // // impress�o das estruturas
    // printf("\nMatriz:\n");
    // for(l = 0; l < 5; l++){
    //     for(c = 0; c < 10; c++){
    //         printf("%2d ", mat[l][c]);
    //     }
    //     printf("\n");
    // }

    // printf("\n\nVetor com a soma das linhas:\n");
    // for(l = 0; l < 5; l++){
    //     printf("Linha %d: %d\n", l, somaLinhas[l]);
    // }

    // printf("\n\nVetor com a soma das colunas:\n");
    // for(c = 0; c < 10; c++){
    //     printf("Coluna %d: %d\n", c, somaColunas[c]);
    // }

   
    

    // int i, j, mat[5][10], vetL[5] = {0}, vetC[10] = {0};

    // // Inicializa o gerador de n�meros aleat�rios
    // srand(time(NULL));

    // // Preenche a matriz 5x10 com n�meros aleat�rios e imprime os valores
    // printf("Matriz:\n");
    // for (j = 0; j < 5; j++) {
    //     for (i = 0; i < 10; i++) {
    //         mat[j][i] = rand() % 100;  // Gera n�mero aleat�rio entre 0 e 99
    //         printf("%2d ", mat[j][i]); // Imprime o valor da c�lula
    //     }
    //     printf("\n"); // Nova linha ap�s cada linha da matriz
    // }

    // // Soma das linhas e armazena no vetor vetL
    // for (j = 0; j < 5; j++) {
    //     for (i = 0; i < 10; i++) {
    //         vetL[j] += mat[j][i]; // Soma os elementos da linha
    //     }
    // }

    // // Soma das colunas e armazena no vetor vetC
    // for (i = 0; i < 10; i++) {
    //     for (j = 0; j < 5; j++) {
    //         vetC[i] += mat[j][i]; // Soma os elementos da coluna
    //     }
    // }

    // // Imprime o vetor de somas das linhas
    // printf("\nSoma das linhas:\n");
    // for (j = 0; j < 5; j++) {
    //     printf("Linha %d: %d\n", j + 1, vetL[j]);
    // }

    // // Imprime o vetor de somas das colunas
    // printf("\nSoma das colunas:\n");
    // for (i = 0; i < 10; i++) {
    //     printf("Coluna %d: %d\n", i + 1, vetC[i]);
    // }
    // 8) Fa�a um programa que calcule e imprima a soma de todos os elementos de uma matriz 5 x 7.
    

    // solu��o do professor
    // int i, j, soma = 0, mat[5][7];

    // srand(time(NULL));

    // // preenche a matriz com n�meros entre 0 e 99
    // for(i = 0; i < 5; i++){
    //     for(j = 0; j < 7; j++){
    //         mat[i][j] = rand() % 100;
    //     }
    // }

    // // acumula a soma dos elementos e imprime a matriz
    // for(i = 0; i < 5; i++){
    //     for(j = 0; j < 7; j++){
    //         soma += mat[i][j]; // acumula a soma
    //         printf("%2d ", mat[i][j]); // imprime a matriz
    //     }
    //     printf("\n");
    // }

    // // imprime a soma dos elementos da matriz
    // printf("\n\nSoma total: %d\n\n", soma);

    // return 0;

    // minha solu��o 

    // int i ,j , mat[5][7],soma = 0;
    // srand(time(NULL));
    
    // mat[5][7] = rand() % 100;

    // for (j = 0; j < 5; j++) {
    //     for (i = 0; i < 7; i++) {
    //         mat[j][i] = rand() % 100;
    //         printf("%3d ", mat[j][i]);
            
    //     }
    //     printf("\n");
    // }


    // for (j = 0; j < 5; j++) {
    //     for (i = 0; i < 7; i++) {
    //         soma += mat[j][i]; 
    //     }
    // }
    // printf("\n A soma dos numeros da matriz: %d", soma);

    // 7) Fa�a um programa para ordenar um vetor com 100 n�meros inteiros. Imprima o vetor antes e
    // ap�s a ordena��o.

    // solu��o menos eficiente 
    // int i,j , copia, vetor[100];

    // srand(time(NULL));

    // for(i=0;i < 100; i++){
    //     vetor[i]= rand()% 1000;
    // }
    // printf("antes da ordena��o\n");
    
    // for(i=0; i < 100; i++){
    //     printf("%3d ", vetor[i]);
    // }   
    // for(j = 1 ;j <= 100;j++)
    //     for(i = 0; i< 99;i++){
    //         if(vetor[i]> vetor[i+1]){
    //             copia = vetor[i];
    //             vetor[i] = vetor[i];
    //             vetor[i] = vetor [i+1];
    //             vetor[i+1] = copia;
    //         }
    // }
    // printf("\n\n");
    // printf("depois da ordena��o\n");
    // for(i=0; i < 100; i++){
    //     printf("%3d ", vetor[i]);
    // }   

    // int i, contador = 0, troca, copia, vetor[100];

    // srand(time(NULL));

    // // preenche o vetor com n�meros entre 0 e 999
    // for(i = 0; i < 100; i++){
    //     vetor[i] = rand() % 1000;
    // }

    // // imprime o vetor antes da ordena��o
    // printf("Antes da ordenacao:\n");
    // for(i = 0; i < 100; i++){
    //     printf("%3d ", vetor[i]);
    // }

    // // ordena o vetor
    // do{ // executa enquanto foi feito ao menos uma troca
    //     troca = 0;
    //     contador++; // conta a quantidade de vezes que este trecho foi executado
    //     for(i = 0; i < 99; i++){ // percorre todo o vetor comparando o elemento i com o i+1
    //         if(vetor[i] > vetor[i+1]){ // se o elemento i for maior que o i+1, troca
    //             copia = vetor[i];
    //             vetor[i] = vetor[i+1];
    //             vetor[i+1] = copia;
    //             troca = 1;
    //         }
    //     }
    // }while(troca);

    // // imprime o vetor ap�s a ordena��o
    // printf("\nApos a ordenacao: Contador: %d\n", contador);
    // for(i = 0; i < 100; i++){
    //     printf("%3d ", vetor[i]);
    // }
    
    
    // setlocale(LC_ALL,""); 

    // 6) Fa�a um programa que leia 10 n�meros reais e os armazene em um vetor. Em seguida, leia um
    // c�digo inteiro e fa�a uma das a��es abaixo:
    // 0 � finaliza o programa;
    // 1 � imprime o vetor na ordem do in�cio ao fim;
    // 2 � imprime o vetor na ordem inversa (do fim para o in�cio).
    // O programa deve funcionar at� que o usu�rio digite 0 para finalizar.


    // solu��o do professor 
    //  int i, opcao;
    // float vetor[10];

    // for(i = 0; i < 10; i++){
    //     printf("Digite o valor da posicao %d: ", i);
    //     scanf("%f", &vetor[i]);
    // }

    // do{
    //     printf("\n0 - Fizalizar\n1 - Imprimir vetor\n2 - Imp. vetor invertido\n");
    //     scanf("%d", &opcao);

    //     switch(opcao){
    //     case 0:
    //         printf("Finalizando...\n");
    //         break;
    //     case 1:
    //         for(i = 0; i < 10; i++){
    //             printf("%.2f ", vetor[i]);
    //         }
    //         printf("\n");
    //         break;
    //     case 2:
    //         for(i = 9; i >= 0; i--){
    //             printf("%.2f ", vetor[i]);
    //         }
    //         printf("\n");
    //         break;
    //     default:
    //         printf("Opcao invaalida!\n");
    //     }

    // }while(opcao != 0);

    // com // setlocale(LC_ALL,"");  o programa entrava em loop qunado digitava 10.5 por exemplo , somente digitando conforme no BR 10,7 ele rodava , primeira vez que acontece isso 
    // minha solu��o dois sem mudar o numeros no vetor
    // int i , opcao;
    // float reais[10];

    // for (i = 0; i < 10; i++) {
    //     printf("Digite um numero real: ");
    //     scanf("%f", &reais[i]);
    // }

    // do{
    //     // Apresenta o menu de op��es
    //     printf("\nEscolha uma op��o:\n");
    //     printf("1. Exibir n�meros\n");
    //     printf("2. Inverter n�meros\n");
    //     printf("0. Sair\n");
    //     scanf("%d", &opcao);

    // switch (opcao) {
    // case 1:
    // printf("N�meros: ");
    //     for (i = 0; i < 10; i++) {
    //         printf("%.2f ", reais[i]);
    //         }
    // printf("\n");
    // break;

    // case 2:
    //     // Inverte os n�meros
    //     for (i = 9; i >= 0; i--) { 
    //         printf("%.2f ", reais[i]);
    //     }
    // case 0:
    //     printf("Saindo!!");
    //     break;
    // default:
    //     printf("Op��o inv�lida! Tente novamente.\n");
    //     break;
            
    // } 
    // }while (opcao != 0);


    
 

    // minha solu��o com ajudinha do chat , invertendo os elementos
    // int i, opcao, fim = 9;
    // float reais[10], copia;

    // // Leitura dos n�meros reais uma �nica vez
    // for (i = 0; i < 10; i++) {
    //     printf("Digite um numero real: ");
    //     scanf("%f", &reais[i]);
    // }

    // do {
    //     // Apresenta o menu de op��es
    //     printf("\nEscolha uma op��o:\n");
    //     printf("1. Exibir n�meros\n");
    //     printf("2. Inverter n�meros\n");
    //     printf("0. Sair\n");
    //     scanf("%d", &opcao);

    //     switch (opcao) {
    //         case 1:
    //             // Exibe os n�meros
    //             printf("N�meros: ");
    //             for (i = 0; i < 10; i++) {
    //                 printf("%.2f ", reais[i]);
    //             }
    //             printf("\n");
    //             break;

    //         case 2:
    //             // Inverte os n�meros
    //             for (i = 0; i < 5; i++) { // Troca apenas at� a metade do vetor
    //                 copia = reais[i];
    //                 reais[i] = reais[fim];
    //                 reais[fim] = copia;
    //                 fim--; // Decrementa fim
    //             }
    //             // Exibe os n�meros invertidos
    //             printf("N�meros invertidos: ");
    //             for (i = 0; i < 10; i++) {
    //                 printf("%.2f ", reais[i]);
    //             }
    //             printf("\n");
    //             // Reinicializa fim para 9
    //             fim = 9; 
    //             break;

    //         case 0:
    //             printf("Saindo...\n");
    //             break;

    //         default:
    //             printf("Op��o inv�lida! Tente novamente.\n");
    //             break;
    //     }
    // } while (opcao != 0);
   

    // 5) Fa�a um programa que receba a temperatura m�dia de cada m�s do ano, armazenando-as em um
    // vetor. Ao final, mostre a maior e a menor temperatura do ano e em que m�s ocorreram (mostrar o
    // m�s por extenso: janeiro, fevereiro �). Desconsidere empates.

    // solu��o do professor 
    //  int i, indiceMaior, indiceMenor;
    // float menor = 99, maior = 0, temp[12];

    // for(i = 0; i < 12; i++) {
    //     printf("Digite a temperatura do mes %d: ", i + 1);
    //     scanf("%f", &temp[i]);
    // }

    // for(i = 0; i < 12; i++) {
    //     if(menor > temp[i]) {
    //         menor = temp[i];
    //         indiceMenor = i;
    //     }
    //     if(maior < temp[i]) {
    //         maior = temp[i];
    //         indiceMaior = i;
    //     }
    // }
    // 

    // printf("A menor temperatura foi %.2f e ocorreu no mes ", menor);
    // switch(indiceMenor) {
    // case 0:
    //     printf("Janeiro\n");
    //     break;
    // case 1:
    //     printf("Fevereiro\n");
    //     break;
    // case 2:
    //     printf("Marco\n");
    //     break;
    // case 3:
    //     printf("Abril\n");
    //     break;
    // case 4:
    //     printf("Maio\n");
    //     break;
    // case 5:
    //     printf("Junho\n");
    //     break;
    // case 6:
    //     printf("Julho\n");
    //     break;
    // case 7:
    //     printf("Agosto\n");
    //     break;
    // case 8:
    //     printf("Setembro\n");
    //     break;
    // case 9:
    //     printf("Outubro\n");
    //     break;
    // case 10:
    //     printf("Novembro\n");
    //     break;
    // case 11:
    //     printf("Dezembro\n");
    //     break;
    // }

    // printf("A maior temperatura foi %.2f e ocorreu no mes ", maior);
    // switch(indiceMaior) {
    // case 0:
    //     printf("Janeiro\n");
    //     break;
    // case 1:
    //     printf("Fevereiro\n");
    //     break;
    // case 2:
    //     printf("Marco\n");
    //     break;
    // case 3:
    //     printf("Abril\n");
    //     break;
    // case 4:
    //     printf("Maio\n");
    //     break;
    // case 5:
    //     printf("Junho\n");
    //     break;
    // case 6:
    //     printf("Julho\n");
    //     break;
    // case 7:
    //     printf("Agosto\n");
    //     break;
    // case 8:
    //     printf("Setembro\n");
    //     break;
    // case 9:
    //     printf("Outubro\n");
    //     break;
    // case 10:
    //     printf("Novembro\n");
    //     break;
    // case 11:
    //     printf("Dezembro\n");
    //     break;
    // }


    // solu��o do chat
    //  int i, mesMaior = 0, mesMenor = 0;
    // float temp[12], maior = -99999, menor = 99999;
    
    // // Declara��o correta do vetor de meses com strings
    // char *mes[] = {"janeiro", "fevereiro", "mar�o", "abril", "maio", "junho", 
    //                "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};

    // // Entrada de dados: temperatura de cada m�s
    // for (i = 0; i < 12; i++) {
    //     printf("Digite a temperatura m�dia do m�s de %s: ", mes[i]);
    //     scanf("%f", &temp[i]);
    // }

    // // Encontrando o m�s com a maior e menor temperatura
    // for (i = 0; i < 12; i++) {
    //     if (temp[i] > maior) {
    //         maior = temp[i];
    //         mesMaior = i;  // Armazena o �ndice do m�s com a maior temperatura
    //     }
    //     if (temp[i] < menor) {
    //         menor = temp[i];
    //         mesMenor = i;  // Armazena o �ndice do m�s com a menor temperatura
    //     }
    // }

    // // Exibindo o resultado
    // printf("\nO m�s de %s registrou a maior temperatura: %.2f�C\n", mes[mesMaior], maior);
    // printf("O m�s de %s registrou a menor temperatura: %.2f�C\n", mes[mesMenor], menor);

    // minha solu��o 
    // int i;
    // float temp[12], maior = 0, menor = 99999;
    //  char *mes[] = {"janeiro", "fevereiro", "mar�o", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};

    // for(i =0; i < 12 ; i++){
    //     printf("Digite a temperatura do m�dia do m�s de %s: ", mes[i]);
    //     scanf("%f", &temp[i]);

    // }

    // for(i = 0; i < 12 ; i++){
    //     if(temp[i]>maior){
    //         maior = temp[i];
    //     }
    //     if(temp[i] < menor){
    //         menor = temp[i];
    //     }
    // }
    // for(i = 0; i < 12; i++){
    //     if(temp[i] == maior){
    //         printf("\nM�s de : %s \nRegistrou a maior temperatura %.2f", mes[i], temp[i]);
    //     }
    //     if(temp[i] == menor){
    //         printf("\nM�s de : %s\nRegistrou a menor temperatura %.2f ", mes[i], temp[i]);
    //     }
    // }


    
    

    //4) Uma pequena loja de artesanato possui apenas um vendedor e comercializa 10 tipos de objetos
    // diferentes. O vendedor recebe um sal�rio de R$1100,00 acrescido de 5% do valor total de suas
    // vendas. O valor unit�rio dos objetos deve ser informado e armazenado em um vetor; a quantidade
    // vendida de cada objeto deve ficar em outro vetor, mas na mesma posi��o. Crie um programa que
    // receba os pre�os e as quantidades vendidas, armazenando-os em seus respectivos vetores. Depois,
    // determine e mostre:
    // a) A quantidade vendida, valor unit�rio e valor total de cada objeto. Ao final, dever�o ser mostrados
    // o valor total das vendas e o valor da comiss�o que ser� paga ao vendedor.
    // b) O valor do objeto mais vendido e sua posi��o no vetor (em caso de empates mostre todos
    // empatados). 
    //solu��o do professor
    // int i, maisVedido = 0, quant[10];
    // float valorTotal = 0, valorParcial, valor[10];

    // for(i = 0; i < 10; i++){
    //     printf("Digite valor unitario e quantidade vendida: ");
    //     scanf("%f%d", &valor[i], &quant[i]);
    // }

    // // letra a
    // for(i = 0; i < 10; i++){
    //     valorParcial = quant[i] * valor[i];
    //     printf("Vendido: %d\tValor unitario R$%.2f\tValor total R$%.2f\n", quant[i], valor[i], valorParcial);
    //     valorTotal += valorParcial;
    // }
    // printf("Valor Total das vendas R$%.2f\n", valorTotal);
    // printf("Comissao paga ao vendedor R$%.2f\n", valorTotal * 0.05);

    // // letra b
    // for(i = 0; i < 10; i++){
    //     if(quant[i] > maisVedido)
    //         maisVedido = quant[i];
    // }

    // for(i = 0; i < 10; i++){
    //     if(quant[i] == maisVedido){
    //         printf("Posicao: %d\tValor R$%.2f\n", i, valor[i]);
    //     }
    // }

    



    //  minha solu��o com ajuste
    


    // int i, quantidade[10], maiorQuantidade = 0;
    // float vendas[10], vParcial[10], vTotal = 0;

    // // Leitura dos valores e quantidades dos produtos
    // for (i = 0 ; i < 10; i++) {
    //     printf("Digite o valor do produto %d: R$", i);
    //     scanf("%f", &vendas[i]);
    //     printf("Digite a quantidade vendida do produto %d: ", i);
    //     scanf("%d", &quantidade[i]);

    //     // Calcula o valor parcial de cada produto (quantidade * valor)
    //     vParcial[i] = vendas[i] * quantidade[i];
        
    //     // Acumula o valor total das vendas
    //     vTotal += vParcial[i];

    //     // Verifica se esta � a maior quantidade vendida at� o momento
    //     if (quantidade[i] > maiorQuantidade) {
    //         maiorQuantidade = quantidade[i];
    //     }
    // }

    // // Exibe as informa��es de cada produto
    // for (i = 0 ; i < 10; i++) {
    //     printf("\nProduto %d:", i);
    //     printf("\nQuantidade vendida: %d", quantidade[i]);
    //     printf("\nValor do produto: R$%.2f", vendas[i]);
    //     printf("\nValor total das vendas deste produto: R$%.2f\n", vParcial[i]);
    // }

    // // Exibe o valor total das vendas e a comiss�o do vendedor
    // printf("\nValor total das vendas: R$%.2f\n", vTotal);
    // printf("Comissao paga ao vendedor (5%%): R$%.2f\n", vTotal * 0.05);

    // // b) Encontra e exibe o(s) objeto(s) mais vendido(s)
    // printf("\n--- Produto(s) mais vendido(s) ---\n");
    // for (i = 0; i < 10; i++) {
    //     if (quantidade[i] == maiorQuantidade) {
    //         printf("Produto %d: quantidade vendida %d (posi��o no vetor: %d)\n", i, quantidade[i], i);
    //     }
    // }

    


 
    // 3) Escrever um programa que l� um vetor N de tam 20 e o imprime na tela. Em seguida, troque
    // o 1� elemento com o �ltimo, o 2� com o pen�ltimo, ... at� o 10� com o 11�. Imprima o vetor N
    // modificado.

    // solu��o do professor 
    //  int a, fim = 19, copia, vetor[20];

    // // l� valores do teclado e salva no vetor
    // for(a = 0; a < 20; a++){
    //     printf("digite %d: ", a);
    //     scanf("%d", &vetor[a]);
    // }

    // // imprime o vetor lido
    // printf("\nVetor original: ");
    // for(a = 0; a < 20; a++){
    //     printf("%2d ", vetor[a]);
    // }

    // // faz a troca dos elementos do vetor
    // for(a = 0; a < 10; a++){
    //     copia = vetor[a];
    //     vetor[a] = vetor[fim];
    //     vetor[fim] = copia;
    //     fim--;
    // }

    // // imprime o vetor novamente (agora modificado)
    // printf("\nVetor modificado: ");
    // for(a = 0; a < 20; a++){
    //     printf("%2d ", vetor[a]);
    // }
    // minha solu��o so imprime de vetor de tr�s para frent, o professor solicitou a troca do vetor mesmo, isso so foi percebido vendo o video
    // int i , n[20];

    // srand(time(NULL));

    // for(i = 0; i < 20; i++){
    //     n[i] = rand() % 100;
    // }
    // printf("\nVetor 1: ");
    // for(i = 0; i < 20; i++){
    //     printf("%3d ", n[i]);
    // }
    // printf("\nVetor 1 modificado");
    // printf("\nVetor 1: ");
    // for(i = 19; i >= 0; i--){
    //     printf("%3d ", n[i]);
    // }

    // 2) Fa�a um programa que some o conte�do de dois vetores de tam 25 e armazene o resultado
    // em um terceiro vetor. Imprima os tr�s vetores na tela.
    //solucao do professor 
    //  int i, vet1[25], vet2[25], vet3[25];

    // srand(time(NULL));

    // // gera valores entre 0 e 99 para os vetores 1 e 2
    // for(i = 0; i < 25; i++){
    //     vet1[i] = rand() % 100;
    //     vet2[i] = rand() % 100;
    // }

    // // soma os valores da posi��o i do vetor 1 e 2 e salva no vetor 3
    // for(i = 0; i < 25; i++){
    //     vet3[i] = vet1[i] + vet2[i];
    // }

    // // imprime o vetor 1
    // printf("\nVetor 1: ");
    // for(i = 0; i < 25; i++){
    //     printf("%3d ", vet1[i]);
    // }

    // // imprime o vetor 2
    // printf("\nVetor 2: ");
    // for(i = 0; i < 25; i++){
    //     printf("%3d ", vet2[i]);
    // }

    // // imprime o vetor 3
    // printf("\nVetor 3: ");
    // for(i = 0; i < 25; i++){
    //     printf("%3d ", vet3[i]);
    // }

    // minha resolu��o, copiei parte do codigo anterior do professor para ser mais rapido e fiz so com 10 

    // int i, vet1[10] ={1,2,3,4,5,6,7,8,9,10}, vet2[10] ={11,12,13,14,15,16,17,18,19,110}, vet3[10];

    // // repeti��o para realizar a multiplica��o
    // for(i = 0; i < 10; i++)
    //     vet3[i] = vet1[i] + vet2[i];

    // // impress�o do vetor 1 na tela
    // printf("\nVetor 1: ");
    // for(i = 0; i < 10; i++)
    //     printf("%3d ", vet1[i]);

    // // impress�o do vetor 2 na tela
    // printf("\nVetor 2: ");
    // for(i = 0; i < 10; i++)
    //     printf("%3d ", vet2[i]);

    // printf("\nVetor 3: ");
    // for(i = 0; i < 10; i++)
    //     printf("%3d ", vet3[i]);
      


    // 1) Fa�a um programa que preencha um vetor de inteiros de tam 10 pedindo valores ao usu�rio.
    // Em seguida, calcule e salve num segundo vetor o quadrado de cada elemento do primeiro vetor. Por
    // fim, imprima os dois vetores.
    // cria��o das vari�veis
    
    //solu��o do professor
    // int i, vete1[10], vete2[10];

    // // repeti��o para ler valores do teclado
    // for(i = 0; i < 10; i++){
    //     printf("Digite o valor da posicao %d: ", i);
    //     scanf("%d", &vete1[i]);
    // }

    // // repeti��o para realizar a multiplica��o
    // for(i = 0; i < 10; i++)
    //     vete2[i] = vete1[i] * vete1[i];

    // // impress�o do vetor 1 na tela
    // printf("\nVetor 1: ");
    // for(i = 0; i < 10; i++)
    //     printf("%3d ", vete1[i]);

    // // impress�o do vetor 2 na tela
    // printf("\nVetor 2: ");
    // for(i = 0; i < 10; i++)
    //     printf("%3d ", vete2[i]);

    //minha solu��o
    // int i, vet1[10], vet2[10];

    // for (i = 0; i < 10 ; i++ ){
    //     printf("Digite o  %d valor: ", i);
    //     scanf("%d", &vet1[i]);
    // }
    // for (i = 0; i < 10 ; i++ ){
    //     printf("%d ", vet1[i]);
    // }

    //  for (i = 0; i < 10 ; i++ ){
    //     vet2[i] = vet1[i] * vet1 [i];
    // }
    // printf("\n");
    // printf("O vetor 2 � igual ao quadrado de cada elemento do primeiro vetor");
    // printf("\n");
    // for (i = 0; i < 10 ; i++ ){
    //     printf("%d ", vet2[i]);
    // }

    // int i,j , mat1[3][3] = {11,12,13,14,15,16,17,18,19};
    
    // srand(time(NULL));
    // for (i = 0 ;i < 3; i++){
    //     for (j = 0 ;j < 3; j++){
    //         mat1[i][j] = rand();
    //     }
    // }
    //  for (i = 0 ; i < 3; i++){
    //     for(j = 0; j < 3 ; j++)
    //         printf("%5d ", mat1[i][j]);   
    //     printf("\n");
    // }


    // int i,j , mat1[3][3] = {11,12,13,14,15,16,17,18,19}, mat2[3][3] = {1,2,3,4,5,6,7,8,9}, mat3[3][3] = {1,2,3,4,5,6,7,8,9}; 
    // char mat5[3][4] = {'a','b','c','d','e','f','g','h','i','j','k','l'};
    
    // for (i = 0 ;i < 3; i++){
    //     for (j = 0 ;j < 3; j++){
    //         mat3[i][j] = mat1[i][j] + mat2[i][j];
    //     }
    // }
    //  for (i = 0 ; i < 3; i++){
    //     for(j = 0; j < 3 ; j++)
    //         printf("%2d ", mat3[i][j]);   
    //     printf("\n");
    // }
    // printf("\n");
    // for (i = 0 ;i < 3; i++){
    //     for (j = 0 ;j < 3; j++){
    //         mat3[i][j] = mat3[i][j] * 2;
    //     }
    // }
    //  for (i = 0 ; i < 3; i++){
    //     for(j = 0; j < 3 ; j++)
    //         printf("%2d ", mat3[i][j]);   
    //     printf("\n");
    // }

    // int i,j , mat1[3][3] = {1,2,3,4,5,6,7,8,9}; 
    // char mat5[3][4] = {'a','b','c','d','e','f','g','h','i','j','k','l'};
    
    // for (i = 0 ;i < 3; i++){
    //      for (j = 0 ;j < 3; j++){
    //         printf("Digite o  valor [%d] [%d] : ", i, j);
    //         scanf("%d", &mat1[i][j]);
    //     }
    // }
    // printf("\n\n");
    // for (i = 0 ; i < 3; i++){
    //     for(j = 0; j < 3 ; j++)
    //         printf("%d ", mat1[i][j]);   
    //     printf("\n");
    // }
    // printf("\n\n");
    // for (i = 0 ; i < 3; i++){
    //     for(j = 0; j < 3 ; j++)
    //         printf("%d ", mat1[j][i]);   
    //     printf("\n");
    // }

    
    
    // int i,j , mat1[3][3] = {1,2,3,4,5,6,7,8,9}; 
    // char mat5[3][4] = {'a','b','c','d','e','f','g','h','i','j','k','l'};
    
    // for (i = 0 ; i < 3; i++){
    //     for(j = 0; j < 3 ; j++)
    //         printf("%d ", mat1[i][j]);   
    //     printf("\n");
    // }
    // matrizes , tamb�m so possue dados dos mesmo tipo. para acessar um item na matriz pe necess�rio
    // dois indices , da linha e coluna
    // int vet[10];
    // int mat1[3][3] = {1,2,3,4,5,7,8,9};
    /* como � preenchido 
             c0 c1 c2
    linha 0  1  2   3
    linha 1  4  5   6
    linha 2  7  8   9
    */
    // int mat2[][3] = {1,2,3,4,5,6,7}; // o restante da matriz � preenchida com zeros como acontece no vetor 
    // int mat3 [3][3] = {0};
    // float mat4 [5][5];
    // char mat5 [10][15];

    // gera��o de numeros aleat�rios com rand() e srand(), dentro de um intervalo
    // int i ;
    // int num2 [50];
    // srand(time(NULL));
    // for(i = 0; i < 40;i++)
    //     num2[i] = 1 + rand() % 99; // uso do resto para definir o intervalo
        
    // printf("\n\n");
    // for(i = 0; i< 40 ; i++)
    //     printf("%d ", num2[i]);
    
    // printf("\n\n");
    
    
    
    // gera��o de numeros aleat�rios com rand() e srand()
    // int i ;
    // int num2 [10];
    // srand(time(NULL));
    // for(i = 0; i<10;i++)
    //     num2[i] = rand();
        
    // printf("\n\n");
    // for(i = 0; i<10 ; i++)
    //     printf("%d ", num2[i]);
    
    // printf("\n\n");
    
  
    // como alterar um cote�do de um vetor
    // int i;
    // int num2 [10];

    // for(i = 0; i<10;i++){
    //     printf("Digite o %d numero : ", i);
    //     scanf("%d", &num2[i]);
    // }
    // for(i = 0; i<10;i++)
    //     num2[i] = num2[i] * 3;


    // printf("\n\n");
    // for(i = 0; i<10 ; i++)
    //     printf("%d ", num2[i]);
    
    // printf("\n\n");

    // int i;
    // int num2 [10];

    // for(i = 0; i<10;i++){
    //     printf("Digite o %d numero : ", i);
    //     scanf("%d", &num2[i]);
    // }
    // print("\n\n");

    // for(i = 0; i<10 ; i++)
    //     printf("%d ", num2[i]);
    
    // print("\n\n");

    
    // int i;
    // int num2 [10];

    // for(i = 0; i<10;i++){
    //     printf("Digite o %d numero : ", i+1);
    //     scanf("%d", &num2[i]);
    // }
    // print("\n\n");

    // for(i = 0; i<10 ; i++)
    //     printf("%d ", num2[i]);
    
    // print("\n\n");


    // int i; 
    // int num2 [] = {1,5,9,15,43};
    // char vogais [5] = {'a','e','i','o','u'}; 
    // float notas[3] = {7.5,8.3, 3.9};
    
    // for(i =0; i<5;i++)
    //     printf("\n%d", num2[i]);
    
    // printf("\n\n");
    
    // for(i =0; i<5;i++)
    //     printf("\n%c", vogais[i]);

    // printf("\n\n");

    // for(i =0; i<3;i++)
    //     printf("\n%.2f", notas[i]);
    // estruturas de dados homogeneas, array unidimensional, vetor � um conjunto de de elementos do mesmo tipo, s�o armazenados em sequencia no na mem�ria 
    // como criar um vetor

    // int num1 [10];
    // int num2 [] = {1,5,9,15,43};
    // int num3 [5] = {4,7,5};// quando falta elementos, ser� preenchido autom�ticamente com zeros
    // int num4 [5] = {4,7,5,8,9,9};// quando vc informa o tam do vetor e quando "sobra" numeros, os elementos extras ser�o desconsiderados
    // int num5 [5] = {0};// maneira simples de preencher com zeros e evitar que o vetor fique preenchido com lixo de mem�ria
    
    // char letras[100];
    // char vogais [5] = {'a','e','i','o','u'}; 
    
    // float notas[3] = {7.5,8.3,3.9,8.9};
    return 0;
}