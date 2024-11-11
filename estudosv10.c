#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#include <string.h>// para usar o strlen
#include <ctype.h>
// #include "pilha.h"

typedef struct no{
    float valor;
    struct no *proximo;
}No;

No* empilhar(No *pilha, float num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = pilha;
        return novo;
    }
    else
        printf("\tErro ao alocar memoria!\n");
    return NULL;
}

No* desempilhar(No **pilha){
    No *remover = NULL;

    if(*pilha){
        remover = *pilha;
        *pilha = remover->proximo;
    }
    else
        printf("\tPilha vazia\n");
    return remover;
}

float operacao(float a, float b, char x){
    switch(x){
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '/':
        return a / b;
        break;
    case '*':
        return a * b;
        break;
    default:
        return 0.0;
    }
}

float resolver_expressao(char x[]){
    char *pt;
    float num;
    No *n1, *n2, *pilha = NULL;

    pt = strtok(x, " ");
    while(pt){
        if(pt[0] == '+' || pt[0] == '-' || pt[0] == '/' || pt[0] == '*'){
            n1 = desempilhar(&pilha);
            n2 = desempilhar(&pilha);
            num = operacao(n2->valor, n1->valor, pt[0]);
            pilha = empilhar(pilha, num);
            free(n1);
            free(n2);
        }
        else{
            num = strtol(pt, NULL, 10);
            pilha = empilhar(pilha, num);
        }
        pt = strtok(NULL, " ");
    }
    n1 = desempilhar(&pilha);
    num = n1->valor; 
    free(n1);
    return num;
}

int main(){
    char exp[50] = {"5 3 2 4 6 7 1 + * + * + *"};

    printf("Resultado de %s:\t", exp);
    printf("%f\n", resolver_expressao(exp));
}


/*      Aula 233

        4) Nota��o p�s-fixa (polonesa reversa) (calculadoras HP)
        Infixa                      P�s-fixa
        (51+13*12)                  51 13 12 * +                R = 207
        (5*(3+2)/4-6)               5 3 2 + * 4 / 6 -           R = 0,25
        (5+3+2*4-6*7*1)             5 3 + 2 4 * + 6 7 * 1 * -   R = -26
        (5*(3+(2*(4+(6*(7+1))))))   5 3 2 4 6 7 1 + * + * + *   R = 535

        


typedef struct no{
    float valor;
    struct no *proximo;
}No;

No* empilhar(No *pilha, float num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = pilha;
        return novo;
    }
    else
        printf("\tErro ao alocar memoria!\n");
    return NULL;
}

No* desempilhar(No **pilha){
    No *remover = NULL;

    if(*pilha){
        remover = *pilha;
        *pilha = remover->proximo;
    }
    else
        printf("\tPilha vazia\n");
    return remover;
}

float operacao(float a, float b, char x){
    switch(x){
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '/':
        return a / b;
        break;
    case '*':
        return a * b;
        break;
    default:
        return 0.0;
    }
}

float resolver_expressao(char x[]){
    char *pt;
    float num;
    No *n1, *n2, *pilha = NULL;

    pt = strtok(x, " ");
    while(pt){
        if(pt[0] == '+' || pt[0] == '-' || pt[0] == '/' || pt[0] == '*'){
            n1 = desempilhar(&pilha);
            n2 = desempilhar(&pilha);
            num = operacao(n2->valor, n1->valor, pt[0]);
            pilha = empilhar(pilha, num);
            free(n1);
            free(n2);
        }
        else{
            num = strtol(pt, NULL, 10);
            pilha = empilhar(pilha, num);
        }
        pt = strtok(NULL, " ");
    }
    n1 = desempilhar(&pilha);
    num = n1->valor;
    free(n1);
    return num;
}

int main(){
    char exp[50] = {"5 3 2 4 6 7 1 + * + * + *"};

    printf("Resultado de %s:\t", exp);
    printf("%f\n", resolver_expressao(exp));
}
*/



/*
    =

    3) Escreva um algoritmo para inverter a ordem das letras de cada palavra de uma string, preservando a ordem das palavras.
       Por exemplo, dado o texto: ABRA A PORTA MARIQUINHA
       A sa�da deve ser: ARBA A ATROP AHNIUQIRAM


typedef struct no{
    char caracter;
    struct no *proximo;
}No;

No* empilhar(No *pilha, char valor){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->caracter = valor;
        novo->proximo = pilha;
        return novo;
    }
    else
        printf("\tErro ao alocar memoria!\n");
    return NULL;
}

No* desempilhar(No **pilha){
    No *remover = NULL;

    if(*pilha){
        remover = *pilha;
        *pilha = remover->proximo;
    }
    else
        printf("\tPilha vazia\n");
    return remover;
}

void inverter_palavras(char x[]){
    int i = 0;
    No *remover, *pilha = NULL;

    while(x[i] != '\0'){
        if(x[i] != ' ')
            pilha = empilhar(pilha, x[i]);
        else {
            while(pilha){
                remover = desempilhar(&pilha);
                printf("%c", remover->caracter);
                free(remover);
            }
            printf(" ");
        }
        i++;
    }
    while(pilha){
        remover = desempilhar(&pilha);
        printf("%c", remover->caracter);
        free(remover);
    }
    printf("\n");
}

int main(){
    char texto[50] = {"EU NAO ABRO NAO!"};

    inverter_palavras(texto);
}
*/

/*
            Aula 231: Como descobrir se uma express�o matem�tica est� mal formada?

            C�digo escrito por Wagner Gaspar
            Julho de 2021


typedef struct no{
    char caracter;
    struct no *proximo;
}No;

No* empilhar(No *pilha, char valor){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->caracter = valor;
        novo->proximo = pilha;
        return novo;
    }
    else
        printf("\tErro ao alocar memoria!\n");
    return NULL;
}

No* desempilhar(No **pilha){
    No *remover = NULL;

    if(*pilha){
        remover = *pilha;
        *pilha = remover->proximo;
    }
    else
        printf("\tPilha vazia\n");
    return remover;
}

void imprimir(No *pilha){
    printf("\n\tPILHA\n");
    while(pilha){
        printf("\t%c\n", pilha->caracter);
        pilha = pilha->proximo;
    }
    printf("\tFIM PILHA\n\n");
}

int forma_par(char f, char d){
    switch(f){
    case ')':
        if(d == '(')
            return 1; // bem formada
        else
            return 0; // mal formada
        break;
    case ']':
        if(d == '[')
            return 1; // bem formada
        else
            return 0; // mal formada
        break;
    case '}':
        if(d == '{')
            return 1; // bem formada
        else
            return 0; // mal formada
        break;
    }
}

int identifica_formacao(char x[]){
    int i = 0;
    No *remover, *pilha = NULL;

    while(x[i] != '\0'){
        if(x[i] == '[' || x[i] == '(' || x[i] == '{'){
            pilha = empilhar(pilha, x[i]);
            imprimir(pilha);
        }
        else if(x[i] == ']' || x[i] == ')' || x[i] == '}'){
            remover = desempilhar(&pilha);
            if(forma_par(x[i], remover->caracter) == 0){
                printf("\tEXPRESSAO MAL FORMADA!\n");
                return 1; // expressao est� mal formada
            }
            free(remover);
        }
        i++;
    }
    imprimir(pilha);
    if(pilha){
        printf("\tExpressao mal formada!\n");
        return 1;
    }
    else{
        printf("\tEXPRESSAO BEM FORMADA!\n");
        return 0;
    }
}

int main(){
    char exp[50];

    printf("\tDigite um expressao: ");
    scanf("%49[^\n]", exp);
    printf("\nExpressao: %s\nRetorno: %d\n", exp, identifica_formacao(exp));
}


*/


/* Aula 230: como criar arquivos de cabe�alho .h foi criado o arquivo pilha.c e piha. h


// função para calcular o fatorial por meio de uma pilha
int fatorial(int num){
    No *remover, *pilha = NULL;

    while(num > 1){
        pilha = empilhar(pilha, num);
        num--;
    }

    imprimir(pilha);

    while(pilha){
        remover = desempilhar(&pilha);
        num = num * remover->valor;
        free(remover);
    }
    return num;
}



int main(){
    int valor;

    printf("Digite um valor maior que zero para o fatorial: ");
    scanf("%d", &valor);
    printf("\tFatorial de %d: %d\n", valor, fatorial(valor));


}

*/ 


/* Duvidas tiradas do chat gpt(desconsiderar erros de português) por conta da aula 229

so para ver se entendi o desempilhar ele recebe um ponteiro de ponteiro como argumento pois ele vai ter que "guardar o endereço do topo" para quando o elemento do topo foi removido o valor que aponta o ponteiro proximo sera passado para o topo

Isso mesmo! Vou detalhar a lógica para deixar ainda mais claro:

Por que usar um ponteiro de ponteiro (No **pilha):

A função desempilhar recebe um ponteiro de ponteiro porque precisamos atualizar diretamente o ponteiro do topo da pilha dentro da função. Quando a função atualiza o topo para o próximo elemento, essa mudança precisa ser refletida fora do escopo da função.
O ponteiro de ponteiro permite que a função desempilhar acesse e modifique o endereço de memória onde o ponteiro original do topo (no main ou outra função) está guardado.
Como desempilhar funciona passo a passo:

Linha 1: Declara o ponteiro remover para guardar temporariamente o nó que será removido (o topo atual da pilha).
Linha 2-3: Verifica se a pilha não está vazia (if (*pilha)).
Se não está vazia:
Linha 3: A variável remover é configurada para apontar para o nó do topo atual (armazenado em *pilha).
Linha 4: Atualiza *pilha para o próximo nó, ou seja, *pilha = remover->proximo;. Isso significa que agora o topo aponta para o segundo elemento da pilha (ou NULL se não houver outros nós).
Linha 6: Se a pilha estiver vazia, imprime "Pilha vazia!".
Linha 7: Retorna o ponteiro remover, para que possamos liberar a memória do nó removido ou usar o valor armazenado, se necessário.
Em resumo:

A função desempilhar pega o nó do topo, faz o ponteiro *pilha (o novo topo) apontar para o próximo nó e retorna o nó antigo. Isso permite acessar o valor e liberar a memória ocupada pelo nó antigo, mantendo a pilha consistente.



Codigo com alterações do chat gpt para ficar mais intuitivo

Aqui está uma versão mais intuitiva e bem comentada do seu código para cálculo de fatorial usando pilha, com nomes de variáveis e funções que deixam o código mais claro:


#include <stdio.h>
#include <stdlib.h>

// Define uma estrutura para representar um nó da pilha
typedef struct Nodo {
    int valor; // Armazena o valor inteiro
    struct Nodo *proximo; // Aponta para o próximo nó na pilha
} Nodo;

// Função para adicionar (empilhar) um novo valor no topo da pilha
Nodo* adicionar_no_topo(Nodo *topo, int numero) {
    Nodo *novo_nodo = malloc(sizeof(Nodo)); // Aloca espaço para um novo nó

    if (novo_nodo) { // Verifica se a alocação de memória foi bem-sucedida
        novo_nodo->valor = numero; // Define o valor do novo nó
        novo_nodo->proximo = topo; // Faz o novo nó apontar para o antigo topo
        return novo_nodo; // Retorna o novo nó como o topo da pilha
    } else {
        printf("Erro ao alocar memória!\n");
        return NULL;
    }
}

// Função para remover (desempilhar) o valor do topo da pilha
Nodo* remover_do_topo(Nodo **topo) {
    Nodo *nodo_a_remover = NULL;

    if (*topo) { // Verifica se a pilha não está vazia
        nodo_a_remover = *topo; // Armazena o nó que será removido
        *topo = nodo_a_remover->proximo; // Atualiza o topo para o próximo nó
    } else {
        printf("Pilha vazia!\n");
    }
    return nodo_a_remover; // Retorna o nó removido (para liberar a memória)
}

// Função para imprimir todos os valores na pilha
void mostrar_pilha(Nodo *topo) {
    printf("\n\tPILHA ATUAL:\n");
    while (topo) {
        printf("\t%d\n", topo->valor);
        topo = topo->proximo; // Move para o próximo nó
    }
    printf("\n");
}

// Função para calcular o fatorial de um número usando pilha
int calcular_fatorial(int numero) {
    Nodo *topo = NULL;
    Nodo *nodo_a_remover;

    // Empilha cada número até 1
    while (numero > 1) {
        topo = adicionar_no_topo(topo, numero);
        numero--;
    }

    mostrar_pilha(topo); // Mostra a pilha preenchida

    // Desempilha e calcula o fatorial
    while (topo) {
        nodo_a_remover = remover_do_topo(&topo);
        numero = numero * nodo_a_remover->valor;
        free(nodo_a_remover); // Libera a memória do nó removido
    }
    return numero;
}

int main() {
    int valor;

    printf("Digite um número maior que zero para o fatorial: ");
    scanf("%d", &valor);
    printf("\tFatorial de %d: %d\n", valor, calcular_fatorial(valor));

    return 0;
}

Explicação das Alterações:
Renomeação das Variáveis e Funções:

No foi renomeado para Nodo e empilhar para adicionar_no_topo, deixando claro que estamos adicionando ao topo da pilha.
desempilhar virou remover_do_topo, facilitando o entendimento de que estamos retirando o valor do topo.
Comentários Descritivos:

Explicações linha a linha ajudam a entender o que cada parte do código está fazendo e por que certas decisões foram tomadas.
Clareza nos Nomes das Funções e Parâmetros:

mostrar_pilha indica claramente a intenção da função, que é exibir o conteúdo da pilha.
Essas mudanças melhoram a legibilidade do código e tornam mais intuitivo o processo de empilhar, desempilhar e calcular o fatorial usando a pilha dinâmica.



no caso da função empilhar quando na primeira etapa qunado é insetido o primeiro valor  o topo fica apontando para esse valor e o ponteiro proximo fica nulo

O ChatGPT disse:
ChatGPT
Memória atualizada
Sim, seu entendimento está correto. Quando a função empilhar é chamada pela primeira vez e um valor é inserido, o topo (representado pela variável pilha ao chamar empilhar) aponta para o novo nó criado. Esse novo nó, por sua vez, terá seu ponteiro proximo apontando para NULL, indicando que ele é o último elemento da pilha (ou o único, no caso da primeira inserção).

Quando mais elementos são adicionados, o novo nó inserido sempre se torna o novo topo da pilha. O campo proximo desse novo nó aponta para o antigo topo, formando uma cadeia onde cada nó aponta para o próximo na pilha, e o último sempre aponta para NULL.

Essa estrutura permite que a pilha seja acessada de forma LIFO (Last In, First Out), ou seja, o último elemento inserido é o primeiro a ser removido.

Aqui está uma representação do que acontece:

Primeiro elemento inserido:

topo → [valor=1, proximo=NULL]
Segundo elemento inserido:

topo → [valor=2, proximo] → [valor=1, proximo=NULL]
E assim sucessivamente, com o topo sempre apontando para o elemento mais recente, e cada nó apontando para o próximo até o final da pilha, onde o último proximo aponta para NULL.




*/

/*
            Aula 229: Como simular a recursão do fatorial com uma pilha?

            Código escrito por Wagner Gaspar
            Julho de 2021


typedef struct no{
    int valor;
    struct no *proximo;
}No;

No* empilhar(No *pilha, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = pilha;
        return novo;
    }
    else
        printf("Erro ao alocar memoria!\n");
    return NULL;
}

No* desempilhar(No **pilha){
    No *remover = NULL;

    if(*pilha){
        remover = *pilha;
        *pilha = remover->proximo;
    }
    else
        printf("Pilha vazia!\n");
    return remover;
}

void imprimir(No *pilha){
    printf("\n\tPILHA\n");
    while(pilha){
        printf("\t%d\n", pilha->valor);
        pilha = pilha->proximo;
    }
    printf("\n");
}

// função para calcular o fatorial por meio de uma pilha
int fatorial(int num){
    No *remover, *pilha = NULL;

    while(num > 1){
        pilha = empilhar(pilha, num);
        num--;
    }

    imprimir(pilha);

    while(pilha){
        remover = desempilhar(&pilha);
        num = num * remover->valor;
        free(remover);
    }
    return num;
}

int main(){
    int valor;

    printf("Digite um valor maior que zero para o fatorial: ");
    scanf("%d", &valor);
    printf("\tFatorial de %d: %d\n", valor, fatorial(valor));

}
*/


/*  Tipo abstrato de dados - TAD aula 228

    Um conjunto de dados e também de operaçãoes para manupular esses dados

    exemplo de conjunto de dado

    typedef struct{
        No *topo;
        int tam;
    }Pilha;

    exemplo de operação

    voi criar_pilha(Pilha *p)


*/

/*
            Aula 227: Estrutura de dados PILHA: Segunda versão




typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    char nome[50];
    Data data;
}Pessoa;

typedef struct no{
    Pessoa p;
    struct no *proximo;
}No;

typedef struct{
    No *topo;
    int tam;
}Pilha;

Pessoa ler_pessoa(){
    Pessoa p;
    printf("\nDigite nome e data de nascimento dd mm aaaa:\n");
    scanf("%49[^\n]%d%d%d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);
    return p;
}

void imprimir_pessoa(Pessoa p){
    printf("\nNome: %s\nData: %2d/%2d/%4d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}

void criar_pilha(Pilha *p){
    p->topo = NULL;
    p->tam = 0;
}

void empilhar(Pilha *p){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->p = ler_pessoa();
        novo->proximo = p->topo;
        p->topo = novo;
        p->tam++;
    }
    else
        printf("\nErro ao alocar memoria...\n");
}

No* desempilhar(Pilha *p){
    if(p->topo){
        No *remover = p->topo;
        p->topo = remover->proximo;
        p->tam--;
        return remover;
    }
    else
        printf("\nPilha vazia!\n");
    return NULL;
}

void imprimir_pilha(Pilha *p){
    No *aux = p->topo;
    printf("\n----------- PILHA Tam: %d --------------\n", p->tam);
    while(aux){
        imprimir_pessoa(aux->p);
        aux = aux->proximo;
    }
    printf("\n--------- FIM PILHA ------------\n");
}

int main(){

    No *remover;
    Pilha p;
    int opcao;

    criar_pilha(&p);

    do{
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
        case 1:
            empilhar(&p);
            break;
        case 2:
            remover = desempilhar(&p);
            if(remover){
                printf("\nElemento removido com sucesso!\n");
                imprimir_pessoa(remover->p);

                free(remover);
            }
            else
                printf("\nSem no a remover.\n");
            break;
        case 3:
            imprimir_pilha(&p);
            break;
        default:
            if(opcao != 0)
                printf("\nOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}

*/

/*
            Aula 224 até 226: Estruturas de dados dinâmicas





typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    char nome[50];
    Data data;
}Pessoa;

typedef struct no{
    Pessoa p;
    struct no *proximo;
}No;

Pessoa ler_pessoa(){
    Pessoa p;

    printf("\nDigite nome e data de nascimento dd mm aaaa:\n");
    scanf("%49[^\n]%d%d%d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);
    return p;
}

void imprimir_pessoa(Pessoa p){
    printf("\nNome: %s\nData: %2d/%2d/%4d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}

// função para a operação push (empilhar)
No* empilhar(No *topo){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->p = ler_pessoa();
        novo->proximo = topo;
        return novo;
    }
    else
        printf("\nErro ao alocar memoria...\n");
    return NULL;
}

// função para a operação pop (desempilhar)
No* desempilhar(No **topo){
    if(*topo != NULL){
        No *remover = *topo;
        *topo = remover->proximo;
        return remover;
    }
    else
        printf("\nPilha vazia!\n");
    return NULL;
}

void imprimir_pilha(No *topo){
    printf("\n----------- PILHA --------------\n");
    while(topo){
        imprimir_pessoa(topo->p);
        topo = topo->proximo;
    }
    printf("\n--------- FIM PILHA ------------\n");
}

int main(){

    No *remover, *topo = NULL;
    int opcao;

    do{
        printf("\n0 - Sair\n1 - Empilar\n2 - Desempilhar\n3 - Imprimir\n");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
        case 1:
            topo = empilhar(topo);
            break;
        case 2:
            remover = desempilhar(&topo);
            if(remover){
                printf("\nElemento removido com sucesso!\n");
                imprimir_pessoa(remover->p);

                free(remover);
            }
            else
                printf("\nSem no a remover.\n");
            break;
        case 3:
            imprimir_pilha(topo);
            break;
        default:
            if(opcao != 0)
                printf("\nOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}

*/


/*
explicação o do porque do apelido na struct no e porque do tydef


É simples. A compilação do nosso código C é feita de cima para baixo da esquerda para a direita, igual à leitura de um livro. Assim, no exemplo que você deu:
1 -  typedef struct {
2 -     Pessoa p;
3 -     No *proximo;
4 - } No;
Quando o compilador chegar na linha 3 ele ainda não sabe quem é No para criar o ponteiro, ao passo que ao fazer:
1 -  typedef struct no {
2 -     Pessoa p;
3 -     struct no *proximo;
4 - } No;
Quando chegar na linha 3 ele já sabe quem é struct no' então ele consegue criar o ponteiro corretamente.
Um ponto interessante que não sei se você percebeu é que esta forma de criar uma estrutura é a junção de duas ações:
1º - a criação da estrutura;
2º - dar um nome à estrutura.

A criação da estrutura é assim:
1 -  struct no{
2 -     Pessoa p;
3 -     struct no *proximo;
4 - };
Apenas isso é suficiente para criar uma estrutura que representa um nó. Porém, toda vez que formos criar um nó precisamos digitar o nome completo, ou seja, 'struct no'. Acho isso muito longo rsrsrs. Então podemos renomear nossa estrutura. É aqui que entra o typedef. A única função do typedef é para renomear estruturas, assim:
typedef struct no No;
Na linha anterior eu estou dizendo que a partir de agora a minha estrutura 'struct no' se chama 'No'.
Não precisamos fazer isso em dois passos como mostrei, podemos fazer tudo de uma vez, criando a estrutura e já dando a ela um nome, como eu fiz na aula, assim:
1 -  typedef struct no {
2 -     Pessoa p;
3 -     struct no *proximo;
4 - } No;







*/

