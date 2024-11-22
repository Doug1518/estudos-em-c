#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#include <string.h>// para usar o strlen
#include <ctype.h>
// #include "pilha.h"

/*
Conteudo construido em aulas do wagner gaspar , curso em c aulas  278 ate 287
*/


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

int main() {

    unsigned char texto[] = "algoritmo de huffman em c";
    unsigned int tabela_frequencia[TAM];
    Lista lista;
    No *arvore;
    int colunas;
    char **dicionario;
    char *codificado, *decodificado;

    setlocale(LC_ALL, "Portuguese");

    //----------- parte 1: tabela de frequência ---------------
    inicializa_tabela_com_zero(tabela_frequencia);
    preenche_tab_frequencia(texto, tabela_frequencia);
    imprime_tab_frequencia(tabela_frequencia);

    //----------- parte 2: Lista Encadeada Ordenada -----------
    criar_lista(&lista);
    preencher_lista(tabela_frequencia, &lista);
    imprimir_lista(&lista);

    //----------- parte 3: Montar a Árvore de Huffman ---------
    arvore = montar_arvore(&lista);
    printf("\n\tÁrvore de Huffman\n");
    imprimir_arvore(arvore, 0);

    //----------- parte 4: Montar o dicionário ----------------
    colunas = altura_arvore(arvore) + 1;
    dicionario = aloca_dicionario(colunas);
    gerar_dicionario(dicionario, arvore, "", colunas);
    imprime_dicionario(dicionario);

    //----------- parte 5: Codificar ---------------------------
    codificado = codificar(dicionario, texto);
    printf("\n\tTexto codificado: %s\n", codificado);

    //----------- parte 6: Decodificar -------------------------
    decodificado = decodificar(codificado, arvore);
    printf("\n\tTexto decodificado: %s\n", decodificado);

    return 0;
}




/*
          AGENDA DE ANIVERSÁRIOS - Como excluir um contato



typedef struct{
    char nome[50];
    int dia, mes, ano;
}Contato;

void imprimir(Contato **c, int quant){
    int i;

    printf("\n\t\tLista de Contatos:\n");
    printf("\t--------------------------------\n");
    for(i = 0; i < quant; i++){
        printf("\t%d = %2d/%2d/%4d\t%s\n", i+1, c[i]->dia, c[i]->mes, c[i]->ano, c[i]->nome);
    }
    printf("\t--------------------------------\n");
}

int cadastrar_contato(Contato **c, int quant, int tam){

    if(quant < tam){
        Contato *novo = malloc(sizeof(Contato));

        printf("\nDigite o nome do contato: ");
        scanf("%50[^\n]", novo->nome);
        printf("\nDigite a data de aniversario dd mm aaaa: ");
        scanf("%d%d%d", &novo->dia, &novo->mes, &novo->ano);
        getchar();
        c[quant] = novo;
        return 1;
    }
    else{
        printf("\n\tImpossivel novo cadastro. Vetor cheio!\n");
        return 0;
    }
}

void alterar_contato(Contato **c, int quant){
    int id;

    imprimir(c, quant);

    printf("\n\tDigite o codigo do contato que deseja alterar: \n");
    scanf("%d", &id);
    getchar();
    id--;

    if(id >= 0 && id < quant){
        Contato *novo = malloc(sizeof(Contato));
        printf("\nDigite o nome do contato: ");
        scanf("%50[^\n]", novo->nome);
        printf("\nDigite a data de aniversario dd mm aaaa: ");
        scanf("%d%d%d", &novo->dia, &novo->mes, &novo->ano);
        getchar();
        c[id] = novo;
    }
    else
        printf("\n\tCodigo invalido!\n");
}

// -------- excluir contato ------------------------------
int excluir_contato(Contato **c, int quant){
    int id;

    imprimir(c, quant);

    printf("\n\tDigite o codigo do contato que deseja excluir: \n");
    scanf("%d", &id);
    getchar();
    id--;

    if(id >= 0 && id < quant){
        // apagar contato
        free(c[id]);
        if(id < quant - 1)
            c[id] = c[quant - 1];
        return -1; // excluido com sucesso
    }
    else{
        printf("\n\tCodigo invalido!\n");
        return 0; // nenhum contato excluido
    }
}

void salvar(Contato **c, int quant, char arq[]){
    FILE *file = fopen(arq, "w");
    int i;

    if(file){
        fprintf(file, "%d\n", quant);
        for(i = 0; i < quant; i++){
            fputs(c[i]->nome, file);
            fputc('\n', file);
            fprintf(file, "%d %d %d\n", c[i]->dia, c[i]->mes, c[i]->ano);
        }
        fclose(file);
    }
    else
        printf("\n\tNAO FOI POSSIVEL ABRIR/CRIAR O ARQUIVO!\n");
}

int ler_arquivo(Contato **c, char arq[]){
    FILE *file = fopen(arq, "r");
    int quant = 0, i;
    Contato *novo = malloc(sizeof(Contato));

    if(file){
        fscanf(file, "%d\n", &quant);
        for(i = 0; i < quant; i++){
            //fgets(novo->nome, 50, file);
            fscanf(file, "%50[^\n]", novo->nome);
            fscanf(file, "%d %d %d\n", &novo->dia, &novo->mes, &novo->ano);
            c[i] = novo;
            novo = malloc(sizeof(Contato));
        }
        fclose(file);
    }
    else
        printf("\n\tNAO FOI POSSIVEL ABRIR/CRIAR O ARQUIVO!\n");
    return quant;
}

int main(){

    Contato *agenda[50];
    char arquivo[] = {"agenda.txt"};
    int opcao, tam = 50, quant = 0;

    do{
        printf("\n\t0 - Sair\n\t1 - Cadastrar\n\t2 - Alterar\n\t3 - Imprimir\n\t4 - Salvar\n\t5 - Ler arquivo\n\t6 - Excluir Contato\n");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
        case 1:
            quant += cadastrar_contato(agenda, quant, tam);
            break;
        case 2:
            alterar_contato(agenda, quant);
            break;
        case 3:
            imprimir(agenda, quant);
            break;
        case 4:
            salvar(agenda, quant, arquivo);
            break;
        case 5:
            quant = ler_arquivo(agenda, arquivo);
            break;
        case 6:
            quant += excluir_contato(agenda, quant);
            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}

*/