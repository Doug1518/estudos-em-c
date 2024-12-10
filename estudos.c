#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#include <string.h>// para usar o strlen
#include <ctype.h>
// #include "pilha.h"
#include <windows.h>
#include "arvore2-3-4.h"


int main() {
    Arvore2_3_4 arv;
    arv.raiz = NULL;
    int opcao;

    // Inser��o de elementos na �rvore
    do {
        printf("Digite o valor a ser inserido ou 0 para finalizar: ");
        scanf("%d", &opcao);
        if (opcao != 0) {
            inserir(&arv, opcao);
        }
        printf("\n\tARVORE 2 3 4 \n\n");
        imprimir(arv.raiz, 0);
        printf("\n");
    } while (opcao != 0);

    // Impress�o final da �rvore
    imprimir(arv.raiz, 0);
    printf("Quantidade de chaves: %d\n", quantidadeChaves(arv.raiz));

    // Busca de elementos na �rvore
    do {
        printf("Digite o valor a ser buscado ou 0 para finalizar: ");
        scanf("%d", &opcao);
        if (opcao != 0) {
            buscar(arv.raiz, opcao, 0);
        }
    } while (opcao != 0);

    /*
    // Remo��o de elementos da �rvore
    do {
        printf("Quantidade de chaves: %d\n", quantidadeChaves(arv.raiz));
        printf("Digite o valor a ser removido ou 0 para finalizar: ");
        scanf("%d", &opcao);
        if (opcao != 0) {
            remover(&arv, opcao);
            printf("\n\tARVORE 2 3 4 \n\n");
            imprimir(arv.raiz, 0);
            printf("\n");
        }
    } while (opcao != 0);
    */

    return 0;
}



