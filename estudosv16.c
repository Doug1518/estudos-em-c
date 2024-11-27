#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#include <string.h>// para usar o strlen
#include <ctype.h>
// #include "pilha.h"
#include <windows.h>


/*
       O que faz o modificador STATIC na linguagem C? | aula 300
*/

static int valor = 50;// o modificador static na variavel global faz com a variavel global fique ultilizavel nesse programa diferente de quando esta sem o modificador que permite que a variavel seja usada em outros programas do "sistema" 

float mediaPares(int vet[], int tam){
    static int soma = 0, quant = 0;// static indica que a variável é permanente ou seja ele não altera no loop como no caso da variavel int somente

    if(tam == 0)
        return (soma * 1.0) / quant;
    else{
        if(vet[tam - 1] % 2 == 0){
            soma = soma + vet[tam - 1];
            quant++;
            return mediaPares(vet, tam - 1);
        }
        else
            return mediaPares(vet, tam - 1);
    }
}

int main(){

    int vet[6] = {2,4,38,7,11,9};

    printf("Media dos pares: %f\n", mediaPares(vet, 6));

    return 0;
}





/*
         Como fazer uma função recursiva para calcular a média dos pares de um vetor? | aula 299


float mediaPares(int vet[], int tam, int soma, int quant){
    if(tam == 0)
        return (soma * 1.0) / quant;
    else{
        if(vet[tam - 1] % 2 == 0)
            return mediaPares(vet, tam - 1, soma + vet[tam - 1], quant += 1);
        else
            return mediaPares(vet, tam - 1, soma, quant);
    }
}

int main(){

    int vet[6] = {2,4,38,7,11,9};

    printf("Media dos pares: %f\n", mediaPares(vet, 6, 0, 0));

    return 0;
}
*/ 



/*
         | Algoritmo para resolver uma equação do segundo grau com a fórmula de Bhaskara | aula 298




int main(){
    int a, b, c, delta;

    printf("Informe os valores para A, B e C: ");
    scanf("%d%d%d", &a, &b, &c);

    delta = b * b - 4 * a * c;

    if(b == 0 || c == 0)
        printf("Equacao incompleta.\n");
    else{
        if(delta < 0)
            printf("Delta: %d\nEsta equacao nao possui raizes reais.\n", delta);
        else{
            if(delta == 0)
                printf("Delta: %d\nEsta equacao possui raizes iguais.\n", delta);
            else
                printf("Delta: %d\nEsta equacao possui raizes diferentes.\n", delta);

            printf("(-b + ou - sqrt(delta)) / (2 * a)\n");
            printf("(-%d + ou - %f) / (2 * %d)\n", b, sqrt(delta), a);
            printf("(%d + ou - %f) / %d\n", -1 * b, sqrt(delta), 2 * a);

            printf("\nx1 = %f / %d\n", (-1 * b) + sqrt(delta), 2 * a);
            printf("x1 = %f\n", ((-1 * b) + sqrt(delta)) / (2 * a));

            printf("\nx2 = %f / %d\n", (-1 * b) - sqrt(delta), 2 * a);
            printf("x2 = %f\n", ((-1 * b) - sqrt(delta)) / (2 * a));
        }
    }

    return 0;
}

*/

/*
       Como encontrar o maior quociente de um vetor na divisão de vet[i] por i ? | aula 297

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int i, maiorQ, id, vet[10000];

    srand(time(NULL));

    for(i = 0; i < 10000; i++)
        vet[i] = rand();

    // for(i = 0; i < 10000; i++)
    //     printf("%d:\t%d\t", i, vet[i]);

    maiorQ = vet[0];
    id = 0;

    for(i = 1; i < 10000; i++){
        if(vet[i] / i > maiorQ){
            maiorQ = vet[i] / i;
            id = i;
        }
    }

    printf("id: %d\tValor: %d\tQuociente: %d\n", id, vet[id], maiorQ);

    return 0;
}


*/


/*
         Como LER nosso arquivo COMPACTADO com o Algoritmo de Huffman? | aula 295

          OBS.: Para utilizar este código no sistema operacional Linux
          retire a inclusão do arquivo de cabeçalho windows.h



#define TAM 256

typedef struct no{
    unsigned char caracter;
    int frequencia;
    struct no *esq, *dir, *proximo;
}No;

typedef struct{
    No *inicio;
    int tam;
}Lista;

//----------- parte 1: tabela de frequencia ----------------------
void inicializa_tabela_com_zero(unsigned int tab[]){
    int i;
    for(i = 0; i < TAM; i++)
        tab[i] = 0;
}

void preenche_tab_frequencia(unsigned char texto[], unsigned int tab[]){
    int i = 0;

    while(texto[i] != '\0'){
        tab[texto[i]]++;
        i++;
    }
}

void imprime_tab_frequencia(unsigned int tab[]){
    int i;

    printf("\tTABELA DE FREQUENCIA\n");
    for(i = 0; i < TAM; i++){
        if(tab[i] > 0)
            printf("\t%d = %u = %c\n", i, tab[i], i);
    }
}

//----------- parte 2: Lista Encadeada Ordenada ----------------------

void criar_lista(Lista *lista){
    lista->inicio = NULL;
    lista->tam = 0;
}

void inserir_ordenado(Lista *lista, No *no){
    No *aux;
    // a lista esta vazia?
    if(lista->inicio == NULL){
        lista->inicio = no;
        //lista->tam++;
    }
    // tem frequencia menor que o inicio da lista
    else if(no->frequencia < lista->inicio->frequencia){
        no->proximo = lista->inicio;
        lista->inicio = no;
        //lista->tam++;
    }
    else{
        aux = lista->inicio;
        while(aux->proximo && aux->proximo->frequencia <= no->frequencia)
            aux = aux->proximo;
        no->proximo = aux->proximo;
        aux->proximo = no;
        //lista->tam++;
    }
    lista->tam++;
}

void preencher_lista(unsigned int tab[], Lista *lista){
    int i;
    No *novo;
    for(i = 0; i < TAM; i++){
        if(tab[i] > 0){
            novo = malloc(sizeof(No));
            if(novo){
                novo->caracter = i;
                novo->frequencia = tab[i];
                novo->dir = NULL;
                novo->esq = NULL;
                novo->proximo = NULL;

                inserir_ordenado(lista, novo);
            }
            else{
                printf("\tERRO ao alocar memoria em preencher_lista!\n");
                break;
            }
        }
    }
}

void imprimir_lista(Lista *lista){
    No *aux = lista->inicio;

    printf("\n\tLista ordenada: Tamanho: %d\n", lista->tam);
    while(aux){
        printf("\tCaracter: %c Frequencia: %d\n", aux->caracter, aux->frequencia);
        aux = aux->proximo;
    }
}

//------------- parte 3: Montar a Arvore de Huffman ----------------------

No* remove_no_inicio(Lista *lista){
    No *aux = NULL;

    if(lista->inicio){
        aux = lista->inicio;
        lista->inicio = aux->proximo;
        aux->proximo = NULL;
        lista->tam--;
    }

    return aux;
}

No* montar_arvore(Lista *lista){
    No *primeiro, *segundo, *novo;
    while(lista->tam > 1){
        primeiro = remove_no_inicio(lista);
        segundo = remove_no_inicio(lista);
        novo = malloc(sizeof(No));

        if(novo){
            novo->caracter = '+';
            novo->frequencia = primeiro->frequencia + segundo->frequencia;
            novo->esq = primeiro;
            novo->dir = segundo;
            novo->proximo = NULL;

            inserir_ordenado(lista, novo);
        }
        else{
            printf("\n\tERRO ao alocar memoria em montar_arvore!\n");
            break;
        }
    }
    return lista->inicio;
}

void imprimir_arvore(No *raiz, int tam){
    if(raiz->esq == NULL && raiz->dir == NULL)
        printf("\tFolha: %c\tAltura: %d\n", raiz->caracter, tam);
    else{
        imprimir_arvore(raiz->esq, tam + 1);
        imprimir_arvore(raiz->dir, tam + 1);
    }
}

//-------------- parte 4: Montar o dicionario ---------------------

int altura_arvore(No *raiz){
    int esq, dir;

    if(raiz == NULL)
        return -1;
    else{
        esq = altura_arvore(raiz->esq) + 1;
        dir = altura_arvore(raiz->dir) + 1;

        if(esq > dir)
            return esq;
        else
            return dir;
    }
}

char** aloca_dicionario(int colunas){
    char **dicionario;
    int i;

    dicionario = malloc(sizeof(char*) * TAM);

    for(i = 0; i < TAM; i++)
        dicionario[i] = calloc(colunas, sizeof(char));

    return dicionario;
}

void gerar_dicionario(char **dicionario, No *raiz, char *caminho, int colunas){
    char esquerda[colunas], direita[colunas];

    if(raiz->esq == NULL && raiz->dir == NULL)
        strcpy(dicionario[raiz->caracter], caminho);
    else{
        strcpy(esquerda, caminho);
        strcpy(direita, caminho);

        strcat(esquerda, "0");
        strcat(direita, "1");

        gerar_dicionario(dicionario, raiz->esq, esquerda, colunas);
        gerar_dicionario(dicionario, raiz->dir, direita, colunas);
    }
}

void imprime_dicionario(char **dicionario){
    int i;

    printf("\n\tDicionario:\n");
    for(i = 0; i < TAM; i++){
        if(strlen(dicionario[i]) > 0)
            printf("\t%3d: %s\n", i, dicionario[i]);
    }
}

//-------------- parte 5: Codificar ----------------------------

int calcula_tamanho_string(char **dicionoario, unsigned char *texto){
    int i = 0, tam = 0;
    while(texto[i] != '\0'){
        tam = tam + strlen(dicionoario[texto[i]]);
        i++;
    }
    return tam + 1;
}

char* codificar(char **dicionario, unsigned char *texto){

    int i = 0, tam = calcula_tamanho_string(dicionario, texto);
    char *codigo = calloc(tam, sizeof(char));

    while(texto[i] != '\0'){
        strcat(codigo, dicionario[texto[i]]);
        i++;
    }
    return codigo;
}

//-------------- parte 6: Decodificar --------------------------
char* decodificar(unsigned char texto[], No *raiz){
    int i = 0;
    No *aux = raiz;
    char temp[2];
    char *decodificado = calloc(strlen(texto), sizeof(char));

    while(texto[i] != '\0'){
        if(texto[i] == '0')
            aux = aux->esq;
        else
            aux = aux->dir;

        if(aux->esq == NULL && aux->dir == NULL){
            temp[0] = aux->caracter;
            temp[1] = '\0';
            strcat(decodificado, temp);
            aux = raiz;
        }

        i++;
    }
    return decodificado;
}

//-------------- parte 7: Compactar --------------------------
void compactar(unsigned char str[]){
    FILE *arquivo = fopen("compactado.wg", "wb");
    int i = 0, j = 7;
    unsigned char mascara, byte = 0; // 00000000

    if(arquivo){
        while(str[i] != '\0'){
            mascara = 1;
            if(str[i] == '1'){
                mascara = mascara << j;
                byte = byte | mascara;
            }
            j--;

            if(j < 0){ // tem um byte formado
                fwrite(&byte, sizeof(unsigned char), 1, arquivo);
                byte = 0;
                j = 7;
            }

            i++;
        }
        if(j != 7) //11010000
            fwrite(&byte, sizeof(unsigned char), 1, arquivo);
        fclose(arquivo);
    }
    else
        printf("\nErro ao abrir/criar arquivo em compactar\n");
}

//-------------- parte 8: Descompactar ------------------------
unsigned int eh_bit_um(unsigned char byte, int i){
    unsigned char mascara = (1 << i);
    return byte & mascara;
}

void descompactar(No *raiz){
    FILE *arquivo = fopen("compactado.wg", "rb");
    No *aux = raiz;
    unsigned char byte; // 10111001
    int i;

    if(arquivo){
        while(fread(&byte, sizeof(unsigned char), 1, arquivo)){
            for(i = 7; i >= 0; i--){
                if(eh_bit_um(byte, i))
                    aux = aux->dir;
                else
                    aux = aux->esq;

                if(aux->esq == NULL && aux->dir == NULL){
                    printf("%c", aux->caracter);
                    aux = raiz;
                }
            }
        }
        fclose(arquivo);
    }
    else
        printf("\nErro ao abrir arquivo em descompactar\n");
}

// função para descobrir o tamanho de um texto em arquivo texto (quantidade de caracteres)
int descobrir_tamanho(){
    FILE *arq = fopen("teste.txt", "r");
    int tam = 0;

    if(arq){
        while(fgetc(arq) != -1)
            tam++;
        fclose(arq);
    }
    else
        printf("\nErro ao abri arquivo em descobrir_tamanho\n");
    return tam;
}

// função para ler um texto de um arquivo texto
void ler_texto(unsigned char *texto){
    FILE *arq = fopen("teste.txt", "r");
    unsigned char letra;
    int i = 0;

    if(arq){
        while(!feof(arq)){
            letra = fgetc(arq);
            if(letra != -1){
                //printf("%d: %c\n", letra, letra);
                texto[i] = letra;
                i++;
            }
        }
        fclose(arq);
    }
    else
        printf("\nErro ao abri arquivo em ler_texto\n");
}

int main() {

    //unsigned char texto[] = "Vamos aprender programação";
    unsigned char *texto;
    unsigned int tabela_frequencia[TAM];
    Lista lista;
    No *arvore;
    int colunas, tam;
    char **dicionario;
    char *codificado, *decodificado;

    // retire ou comente a linha a seguir para executar no Linux
    SetConsoleOutputCP(65001);

    tam = descobrir_tamanho();
    printf("\nQuantidade: %d\n", tam);

    texto = calloc(tam + 2, sizeof(unsigned char));
    ler_texto(texto);
    //printf("\nTEXTO:\n%s\n", texto);


    //----------- parte 1: tabela de frequência ---------------
    inicializa_tabela_com_zero(tabela_frequencia);
    preenche_tab_frequencia(texto, tabela_frequencia);
    //imprime_tab_frequencia(tabela_frequencia);

    //----------- parte 2: Lista Encadeada Ordenada -----------
    criar_lista(&lista);
    preencher_lista(tabela_frequencia, &lista);
    //imprimir_lista(&lista);

    //----------- parte 3: Montar a Árvore de Huffman ---------
    arvore = montar_arvore(&lista);
    printf("\n\tArvore de Huffam\n");
    //imprimir_arvore(arvore, 0);

    //----------- parte 4: Montar o dicionário ----------------
    colunas = altura_arvore(arvore) + 1;
    dicionario = aloca_dicionario(colunas);
    gerar_dicionario(dicionario, arvore, "", colunas);
    //imprime_dicionario(dicionario);

    //----------- parte 5: Codificar ---------------------------
    codificado = codificar(dicionario, texto);
    //printf("\n\tTexto codificado: %s\n", codificado);

    //----------- parte 6: Decodificar -------------------------
    decodificado = decodificar(codificado, arvore);
    //printf("\n\tTexto decodificado: %s\n", decodificado);

    //----------- parte 7: Compactar ----------------------------
    compactar(codificado);

    //----------- parte 8: Descompactar ----------------------------
    printf("\nARQUIVO DESCOMPACTADO!\n");
    descompactar(arvore);
    printf("\n\n");

    free(texto);
    free(codificado);
    free(decodificado);

    return 0;
}
*/


/*
             Dúvida | Como imprimir os elementos abaixo da diagonal secundária de uma matriz? | aula 294

             


int main(){
    const TAM = 5;
    int i, j, mat[TAM][TAM];

    srand(time(NULL));

    for(i = 0; i < TAM; i++){
        for(j = 0; j < TAM; j++)
            mat[i][j] = rand() % 100;
    }

    // Imprimir elementos abaixo da diagonal secundária
    for(i = 0; i < TAM; i++){
        for(j = 0; j < TAM; j++){
            if(j >= TAM - i)
                printf(" %2d ", mat[i][j]);
            else
                printf("    ");
        }
        printf("\n");
    }

    return 0;
}
*/
/* explicação do chatgpt como se fosse em debug mode


Entradas:
Suponha que str seja a sequência binária "101001110011".

Passo a passo:
1. Inicialização:
arquivo: Arquivo binário é aberto para escrita.
i: 0 (primeiro índice da string).
j: 7 (representa o bit mais à esquerda do byte).
byte: 00000000 (começa zerado).

2. Iteração sobre str:
Cada caractere da string str será processado um por um:

Iteração 1 (i = 0, str[i] = '1'):
mascara = 1.
Shift: mascara << j ? 00000001 desloca 7 posições ? 10000000.
byte: 00000000 | 10000000 ? 10000000.
Decrementa j: j = 6.

Iteração 2 (i = 1, str[i] = '0'):
mascara = 1, mas como é '0', byte não é alterado.
byte: Continua 10000000.
Decrementa j: j = 5.

Iteração 3 (i = 2, str[i] = '1'):
mascara = 1.
Shift: mascara << j ? 00000100.
byte: 10000000 | 00000100 ? 10000100.
Decrementa j: j = 4.

Iteração 4 (i = 3, str[i] = '0'):
byte: Continua 10000100.
Decrementa j: j = 3.

Iteração 5 (i = 4, str[i] = '0'):
byte: Continua 10000100.
Decrementa j: j = 2.

Iteração 6 (i = 5, str[i] = '1'):
mascara = 1.
Shift: mascara << j ? 00000010.
byte: 10000100 | 00000010 ? 10000110.
Decrementa j: j = 1.

Iteração 7 (i = 6, str[i] = '1'):
mascara = 1.
Shift: mascara << j ? 00000001.
byte: 10000110 | 00000001 ? 10000111.
Decrementa j: j = 0.

Iteração 8 (i = 7, str[i] = '0'):
byte: Continua 10000111.
Decrementa j: j = -1.

3. Escrita no arquivo:
Como j < 0, um byte completo foi formado:
byte (10000111 ou 0x87 em hexadecimal) é escrito no arquivo.
Reinicia byte = 0.
j = 7 para começar um novo byte.

4. Continua até o fim de str:
Seguem as mesmas etapas para o restante da string "0011". Quando str termina:

Um byte parcial (00110000) é escrito no arquivo, caso não esteja completo.
Arquivo final:
Para "101001110011", o arquivo conterá dois bytes:
10000111 (0x87).
00110000 (0x30).
Resumo do Debug:
Cada caractere '1' ou '0' da string determina se um bit será alterado em byte.
Quando o byte está completo (8 bits), é escrito no arquivo e reiniciado.
Um byte parcial ao final da string também é gravado.*/


/*
        | Como criar um arquivo COMPACTADO com o Algoritmo de Huffman? | aula 293


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM 256

typedef struct no{
    unsigned char caracter;
    int frequencia;
    struct no *esq, *dir, *proximo;
}No;

typedef struct{
    No *inicio;
    int tam;
}Lista;

//----------- parte 1: tabela de frequência ----------------------
void inicializa_tabela_com_zero(unsigned int tab[]){
    int i;
    for(i = 0; i < TAM; i++)
        tab[i] = 0;
}

void preenche_tab_frequencia(unsigned char texto[], unsigned int tab[]){
    int i = 0;

    while(texto[i] != '\0'){
        tab[texto[i]]++;
        i++;
    }
}

void imprime_tab_frequencia(unsigned int tab[]){
    int i;

    printf("\tTABELA DE FREQUENCIA\n");
    for(i = 0; i < TAM; i++){
        if(tab[i] > 0)
            printf("\t%d = %u = %c\n", i, tab[i], i);
    }
}

//----------- parte 2: Lista Encadeada Ordenada ----------------------

void criar_lista(Lista *lista){
    lista->inicio = NULL;
    lista->tam = 0;
}

void inserir_ordenado(Lista *lista, No *no){
    No *aux;
    // a lista está vazia?
    if(lista->inicio == NULL){
        lista->inicio = no;
        //lista->tam++;
    }
    // tem frequência menor que o início da lista
    else if(no->frequencia < lista->inicio->frequencia){
        no->proximo = lista->inicio;
        lista->inicio = no;
        //lista->tam++;
    }
    else{
        aux = lista->inicio;
        while(aux->proximo && aux->proximo->frequencia <= no->frequencia)
            aux = aux->proximo;
        no->proximo = aux->proximo;
        aux->proximo = no;
        //lista->tam++;
    }
    lista->tam++;
}

void preencher_lista(unsigned int tab[], Lista *lista){
    int i;
    No *novo;
    for(i = 0; i < TAM; i++){
        if(tab[i] > 0){
            novo = malloc(sizeof(No));
            if(novo){
                novo->caracter = i;
                novo->frequencia = tab[i];
                novo->dir = NULL;
                novo->esq = NULL;
                novo->proximo = NULL;

                inserir_ordenado(lista, novo);
            }
            else{
                printf("\tERRO ao alocar memoria em preencher_lista!\n");
                break;
            }
        }
    }
}

void imprimir_lista(Lista *lista){
    No *aux = lista->inicio;

    printf("\n\tLista ordenada: Tamanho: %d\n", lista->tam);
    while(aux){
        printf("\tCaracter: %c Frequência: %d\n", aux->caracter, aux->frequencia);
        aux = aux->proximo;
    }
}

//------------- parte 3: Montar a Árvore de Huffman ----------------------

No* remove_no_inicio(Lista *lista){
    No *aux = NULL;

    if(lista->inicio){
        aux = lista->inicio;
        lista->inicio = aux->proximo;
        aux->proximo = NULL;
        lista->tam--;
    }

    return aux;
}

No* montar_arvore(Lista *lista){
    No *primeiro, *segundo, *novo;
    while(lista->tam > 1){
        primeiro = remove_no_inicio(lista);
        segundo = remove_no_inicio(lista);
        novo = malloc(sizeof(No));

        if(novo){
            novo->caracter = '+';
            novo->frequencia = primeiro->frequencia + segundo->frequencia;
            novo->esq = primeiro;
            novo->dir = segundo;
            novo->proximo = NULL;

            inserir_ordenado(lista, novo);
        }
        else{
            printf("\n\tERRO ao alocar memoria em montar_arvore!\n");
            break;
        }
    }
    return lista->inicio;
}

void imprimir_arvore(No *raiz, int tam){
    if(raiz->esq == NULL && raiz->dir == NULL)
        printf("\tFolha: %c\tAltura: %d\n", raiz->caracter, tam);
    else{
        imprimir_arvore(raiz->esq, tam + 1);
        imprimir_arvore(raiz->dir, tam + 1);
    }
}

//-------------- parte 4: Montar o dicionário ---------------------

int altura_arvore(No *raiz){
    int esq, dir;

    if(raiz == NULL)
        return -1;
    else{
        esq = altura_arvore(raiz->esq) + 1;
        dir = altura_arvore(raiz->dir) + 1;

        if(esq > dir)
            return esq;
        else
            return dir;
    }
}

char** aloca_dicionario(int colunas){
    char **dicionario;
    int i;

    dicionario = malloc(sizeof(char*) * TAM);

    for(i = 0; i < TAM; i++)
        dicionario[i] = calloc(colunas, sizeof(char));

    return dicionario;
}

void gerar_dicionario(char **dicionario, No *raiz, char *caminho, int colunas){
    char esquerda[colunas], direita[colunas];

    if(raiz->esq == NULL && raiz->dir == NULL)
        strcpy(dicionario[raiz->caracter], caminho);
    else{
        strcpy(esquerda, caminho);
        strcpy(direita, caminho);

        strcat(esquerda, "0");
        strcat(direita, "1");

        gerar_dicionario(dicionario, raiz->esq, esquerda, colunas);
        gerar_dicionario(dicionario, raiz->dir, direita, colunas);
    }
}

void imprime_dicionario(char **dicionario){
    int i;

    printf("\n\tDicionario:\n");
    for(i = 0; i < TAM; i++){
        if(strlen(dicionario[i]) > 0)
            printf("\t%3d: %s\n", i, dicionario[i]);
    }
}

//-------------- parte 5: Codificar ----------------------------

int calcula_tamanho_string(char **dicionario, unsigned char *texto){
    int i = 0, tam = 0;
    while(texto[i] != '\0'){
        tam = tam + strlen(dicionario[texto[i]]);
        i++;
    }
    return tam + 1;
}

char* codificar(char **dicionario, unsigned char *texto){

    int i = 0, tam = calcula_tamanho_string(dicionario, texto);
    char *codigo = calloc(tam, sizeof(char));

    while(texto[i] != '\0'){
        strcat(codigo, dicionario[texto[i]]);
        i++;
    }
    return codigo;
}

//-------------- parte 6: Decodificar --------------------------
char* decodificar(unsigned char texto[], No *raiz){
    int i = 0;
    No *aux = raiz;
    char temp[2];
    char *decodificado = calloc(strlen(texto), sizeof(char));

    while(texto[i] != '\0'){
        if(texto[i] == '0')
            aux = aux->esq;
        else
            aux = aux->dir;

        if(aux->esq == NULL && aux->dir == NULL){
            temp[0] = aux->caracter;
            temp[1] = '\0';
            strcat(decodificado, temp);
            aux = raiz;
        }

        i++;
    }
    return decodificado;
}


      -------------- parte 7: Compactar --------------------------

void compactar(unsigned char str[]){
    FILE *arquivo = fopen("compactado.wg", "wb");
    int i = 0, j = 7;
    unsigned char mascara, byte = 0; // 00000000

    if(arquivo){
        while(str[i] != '\0'){
            mascara = 1;
            if(str[i] == '1'){
                mascara = mascara << j;
                byte = byte | mascara;
            }
            j--;

            if(j < 0){ // tem um byte formado
                fwrite(&byte, sizeof(unsigned char), 1, arquivo);
                byte = 0;
                j = 7;
            }

            i++;
        }
        if(j != 7) // tem um byte em formação
            fwrite(&byte, sizeof(unsigned char), 1, arquivo);
        fclose(arquivo);
    }
    else
        printf("\nErro ao abrir/criar arquivo em compactar\n");
}



int main() {

    //unsigned char texto[] = "Vamos aprender programação";
    unsigned char *texto;
    unsigned int tabela_frequencia[TAM];
    Lista lista;
    No *arvore;
    int colunas, tam;
    char **dicionario;
    char *codificado, *decodificado;

    SetConsoleOutputCP(65001);

    tam = descobrir_tamanho();
    printf("\nQuantidade: %d\n", tam);

    texto = calloc(tam + 2, sizeof(unsigned char));
    ler_texto(texto);
    //printf("\nTEXTO:\n%s\n", texto);


    //----------- parte 1: tabela de frequência ---------------
    inicializa_tabela_com_zero(tabela_frequencia);
    preenche_tab_frequencia(texto, tabela_frequencia);
    //imprime_tab_frequencia(tabela_frequencia);

    //----------- parte 2: Lista Encadeada Ordenada -----------
    criar_lista(&lista);
    preencher_lista(tabela_frequencia, &lista);
    //imprimir_lista(&lista);

    //----------- parte 3: Montar a Árvore de Huffman ---------
    arvore = montar_arvore(&lista);
    printf("\n\tArvore de Huffam\n");
    //imprimir_arvore(arvore, 0);

    //----------- parte 4: Montar o dicionário ----------------
    colunas = altura_arvore(arvore) + 1;
    dicionario = aloca_dicionario(colunas);
    gerar_dicionario(dicionario, arvore, "", colunas);
    //imprime_dicionario(dicionario);

    //----------- parte 5: Codificar ---------------------------
    codificado = codificar(dicionario, texto);
    //printf("\n\tTexto codificado: %s\n", codificado);

    //----------- parte 6: Decodificar -------------------------
    decodificado = decodificar(codificado, arvore);
    //printf("\n\tTexto decodificado: %s\n", decodificado);

    //----------- parte 7: Compactar ----------------------------
    compactar(codificado);
}

*/


/*  OU EXCLUSIVO. Como funciona a operação OU EXCLUSIVO bit a bit? | aula 292

Operador bit a bit ou exclusivo ( ^ )
A  B   A^B
0  0    0
0  1    1
1  0    1
1  1    0


Esta operação é util quando precisamos inverter o estado de um bit
xxxx.xxXx
0000.0010
xxxx.xx0x


int main(){
    int a, b;

        a = 73;           // 01001001 (73 em binário)
        b = a ^ (1 << 3); // 00001000 ( 1 << 3 ), para inverter o bit-3 = 65
        printf("a: %d\tb: %d\n", a, b);

        b = b ^ (1 << 3); // 00010000 ( 1 << 3 ), para inverter o bit-3 = 73
        printf("a: %d\tb: %d\n", a, b);

return 0;
}

*/
/*
    Operador OU | bit a bit. Como funciona a operação OR bit a bit? | aula 291
     
     operador bit a bit ou (|)
     Exemplo com o operador or ( | )

int main(){
    int a, b, c;
    a = 30;    // 0000.0000.0001.1110 
    b = 19;    // 0000.0000.0001.0011
    c = a | b; // 0000.0000.0001.1111 = 31
//  c = a || b;// 0000.0000.0000.0001 = 1 
    printf("%d | %d = %d\n", a ,b ,c);


    // como ativar um bit (colocar um bit em 1)

    a = 1;      // 0000.0001
    c = 1 << 1; // 000.00010 // criando a mascara
    b = a | c ; // 0000.0011 = 3
    //b = a | (1 << 1);// 0000.0011 = 3
    printf("a: %d\tb: %d\n", a, b);

    b = a | (1 << 2);// 0000.0101 = 5
    printf("a: %d\tb: %d\n", a, b);

    b = a | (1 << 3);// 0000.1001 = 9
    printf("a: %d\tb: %d\n", a, b);

    b = a | (1 << 4);// 0001.0001 = 17
    printf("a: %d\tb: %d\n", a, b);

     return 0; 
}
*/
/*
    Operador & bit a bit. Como funciona a operação AND bit a bit? | aula 290

    Opertador bit a bit E (&) abd && if (() && ())

    & compara bit a bit e &&  faz uma comparação logica




int main (){

    int a, b, c;

    a = 30;    // 0000.0000.0001.1110 
    b = 19;    // 0000.0000.0001.0011
    c = a & b; // 0000.0000.0001.0010 = 18
    // c = A && b; // 0000.0000.0000.0001=1

    printf("%d & %d = %d\n", a ,b ,c);

    // testar se um bit esta ligado ou desligado
    a = 73; //           01001001 (73 em binário)
    b = a & (1 << 3); // 00001000 ( 1 << 3 ), para testar o bit-3 (quarto bit)
    printf("a: %d\tb: %d\n", a, b);

    b = a & (1 << 4); // 00010000 ( 1 << 4 ), para testar o bit-4 (quinto bit)
    printf("a: %d\tb: %d\n", a, b);

    // verifica se um bumero é par ou impar
    int n = 97; // 0110.0001   obs: todo numero impar tem 1 no final e par o 0
    if( n & 1 ) // 0000.0001
        printf("Numero impar.\n") ;
    else
        printf("Numero par.\n") ;
    

    

return 0;

}

*/

/*
        Operação NOT negação bit a bit e números em Complemento de Dois | aula 289

operador bit a bit NOT ( ~ )

é a negação bit a bit 

1 = 0001    2 = 0010     3 = 0011  9 = 1001
~1 = 1110(-2)  ~2 = 1101(-3)  ~3 = 1110(-4)  ~9 = 1110(-10)



Como achar um negativo numero em binario

Complemento de dois 

camo representar o - 2 em binario 
2 - em decimal
0010 - dois em binário
      |
inverte os bits
      |
1101
   1  - soma 1 o  resultado é dois e dois em binario é 10 
  10  - dois em binario 
1110  - continua a soma 

3 - em decimal
0011 - 3 em binário
      |
inverte os bits
      |
1100
   1  - soma 1 o  resultado é dois e dois em binario é 10 
1101 -> -3



int main(){

    int a, b;
    a = 1;
    b = ~a;
    printf("\ta: %d\t~a: %d\n", a, b);

    a = 2;
    b = ~a;
    printf("\ta: %d\t~a: %d\n", a, b);

    a = 3;
    b = ~a;
    printf("\ta: %d\t~a: %d\n", a, b);

    a = 4;
    b = ~a;
    printf("\ta: %d\t~a: %d\n", a, b);

    return 0;
}

*/




/*
             Deslocamento bit a bit na linguagem C aula 288

             


int main(){

    // Deslocamento à esquerda
    int a, b;
    a = 1;      // 0001
    b = a << 1; // 0010 = 2

    printf("a: %d\tb: %d\n", a, b);

    b = a << 2; // 0100 = 4
    printf("a: %d\tb: %d\n", a, b);

    b = a << 3; // 1000 = 8
    printf("a: %d\tb: %d\n", a, b);


    // Deslocamento à Direita
    a = 10;     // 1010
    b = a >> 1; // 0101 = 5

    printf("a: %d\tb: %d\n", a, b);

    b = a >> 2; // 0010 = 2
    printf("a: %d\tb: %d\n", a, b);

    b = a >> 3; // 0001 = 1
    printf("a: %d\tb: %d\n", a, b);

    return 0;
}

*/