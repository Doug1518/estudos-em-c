#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#include <string.h>// para usar o strlen
#include <ctype.h>
// comando para compilar o codigo criando o a.exe para usar o debug (  gcc -g estudos.c -o a.exe  )



// como cirar novos tipos de dados em C com typedef struct

// typedef struct {
//     int idade;
//     char sexo;
//     char nome[100];
// }Pessoa;

// // segunda forma
// struct Pessoa2{
//     int idade;
//     char sexo;
//     char nome[100];
// };

// como criar uma struct com dados lidos do teclado
// typedef struct {
//     int idade;
//     char sexo;
//     char nome[100];
// }Pessoa;

// posso ter struct de struct
// typedef struct {
//     int dia, mes, ano;

// }DataNas;

// typedef struct {
//     DataNas dataNas;
//     int idade;
//     char sexo;
//     char nome[100];

// }Pessoa;

// como criar um procedimento que recebe uma struct como parametro
// void imprimirPessoa(Pessoa p){
//     printf("\n\tNome: %s", p.nome);
//     printf("\tIdade: %d\n", p.idade);
//     printf("\tSexo: %c\n", p.sexo);
//     printf("\tData de nas.: %d/%d/%d \n\n", p.dataNas.dia, p.dataNas.mes, p.dataNas.ano);

// }
// fun��o que l� os dados de uma pessoa e retorna para quem chamou
// Pessoa lerPessoa(){
//     Pessoa p;
//     printf("\nDigite seu nome: ");
//     fgets(p.nome,100,stdin);
//     printf("Digite sua idade: ");
//     scanf("%d", &p.idade);
//     scanf("%c");
//     printf("Digite sua sexo(f ou m): ");
//     scanf("%c", &p.sexo);
//     printf("Digite sua data de nascimento no formato dd mm aaaa: ");
//     scanf("%d%d%d", &p.dataNas.dia, &p.dataNas.mes, &p.dataNas.ano);
//     scanf("%c");
//     return p;
// }
// como construir o tipo eletronico com typef struct
typedef struct {
    char tipo[100], marca[50], modelo[25], descricao[500], energia;
    int quantidade;
    int codigo;
} Eletronico;

// Função para imprimir as informações de um Eletronico
void imprimirEletronico(Eletronico e) {
    printf("\n\tTipo: %s", e.tipo);
    printf("\tMarca: %s", e.marca);
    printf("\n\tModelo: %s", e.modelo);
    printf("\n\tEnergia: %c\tQuantidade: %d\n", e.energia, e.quantidade);
    printf("\n\tDescricao: %s", e.descricao);
    printf("\tCódigo: %d\n", e.codigo);
}

// Função para ler as informações de um Eletronico
Eletronico lerEletronico() {
    Eletronico e;
    printf("\nDigite o tipo: ");
    fgets(e.tipo, 100, stdin);

    printf("Marca: ");
    fgets(e.marca, 50, stdin);

    printf("Modelo: ");
    fgets(e.modelo, 25, stdin);

    printf("Eficiencia energetica (um caractere): ");
    scanf(" %c", &e.energia); // espaço antes do %c para ignorar o '\n' anterior
    getchar(); // Limpa o buffer após ler o char

    printf("Descricao: ");
    fgets(e.descricao, 500, stdin);

    printf("Quantidade: ");
    scanf("%d", &e.quantidade);

    printf("Codigo: ");
    scanf("%d", &e.codigo);

    return e;
}

int main() {
    setlocale(LC_ALL, "");

    Eletronico ele = lerEletronico();
    imprimirEletronico(ele);

    return 0;


    // Como construir o tipo ELETRÔNICO com TYPEDEF STRUCT? 

    // Como criar uma matriz (array bidimensional) de struct
    // int i, j;
    // Pessoa pessoa1[2][2];
    // for(j = 0 ; j < 2; j++)
    //     for(i = 0 ; i < 2; i++)
    //         pessoa1[j][i] = lerPessoa();

    // for(j = 0 ; j < 2; j++) 
    //     for(i = 0 ; i < 2; i++)
    //         imprimirPessoa(pessoa1[j][i]);
    



    // como criar um vetor (array unidimensional) de struct
    // int i;
    // Pessoa pessoa1[3];
    // for(i = 0 ; i < 3; i++)
    //    pessoa1[i] = lerPessoa();
    // for(i = 0 ; i < 3; i++)
    //    imprimirPessoa(pessoa1[i]);



    // como criar uma fun��o que recebe uma struct
    // Pessoa pessoa1;

    // pessoa1 = lerPessoa();

    // imprimirPessoa(pessoa1);

    // como criar um procedimento que recebe uma struct como parâmetro
    // Pessoa pessoa1;

    // printf("%d\n", sizeof(pessoa1));


    // printf("Digite seu nome: ");
    // fgets(pessoa1.nome,100,stdin);

    // printf("Digite sua idade: ");
    // scanf("%d", &pessoa1.idade);
    // scanf("%c");
    // printf("Digite sua sexo(f ou m): ");
    // scanf("%c", &pessoa1.sexo);

    // printf("Digite sua data de nascimento no formato dd mm aaaa: ");
    // scanf("%d%d%d", &pessoa1.dataNas.dia, &pessoa1.dataNas.mes, &pessoa1.dataNas.ano);



    // imprimirPessoa(pessoa1);

    /* aula 171 como fazer o triangulo triangulo
         *
        **
       ***
      ****
    */
//    int i,j, n;

//    printf("digite o valor de n: ");
//    scanf("%d", &n);

//     for(i = 1; i < n; i++){
//         for(j= n-i;j>=1;j--)
//             printf(" ");
//         for(j =1;j <= i;j++){
//             printf("*");
//         }
//         printf("\n");
//     }


    // de quanta memoria precisa
    // Pessoa pessoa1;
    // DataNas data;
    // printf("%d\n", sizeof(pessoa1));
    // printf("%d\n", sizeof(data));

    // printf("Digite seu nome: ");
    // fgets(pessoa1.nome,100,stdin);

    // printf("Digite sua idade: ");
    // scanf("%d", &pessoa1.idade);
    // scanf("%c");
    // printf("Digite sua sexo(f ou m): ");
    // scanf("%c", &pessoa1.sexo);

    // printf("Digite sua data de nascimento no formato dd mm aaaa: ");
    // scanf("%d%d%d", &pessoa1.dataNas.dia, &pessoa1.dataNas.mes, &pessoa1.dataNas.ano);

    // printf("Nome: %s\nIdade: %d\nSexo: %c", pessoa1.nome, pessoa1.idade, pessoa1.sexo);
    // printf("Data de nascimento: %d/%d/%d\n ", pessoa1.dataNas.dia, pessoa1.dataNas.mes, pessoa1.dataNas.ano);


    // posso ter struct de struct

    // Pessoa pessoa1;
    // printf("Digite seu nome: ");
    // fgets(pessoa1.nome,100,stdin);

    // printf("Digite sua idade: ");
    // scanf("%d", &pessoa1.idade);
    // scanf("%c");
    // printf("Digite sua sexo(f ou m): ");
    // scanf("%c", &pessoa1.sexo);

    // printf("Digite sua data de nascimento no formato dd mm aaaa: ");
    // scanf("%d%d%d", &pessoa1.dataNas.dia, &pessoa1.dataNas.mes, &pessoa1.dataNas.ano);

    // printf("Nome: %s\nIdade: %d\nSexo: %c", pessoa1.nome, pessoa1.idade, pessoa1.sexo);
    // printf("Data de nascimento: %d/%d/%d\n ", pessoa1.dataNas.dia, pessoa1.dataNas.mes, pessoa1.dataNas.ano);

    // como criar uma struct com dados lidos do teclado
    // Pessoa pessoa1;
    // printf("Digite seu nome: ");
    // fgets(pessoa1.nome,100,stdin);

    // printf("Digite sua idade: ");
    // scanf("%d", &pessoa1.idade);
    // scanf("%c");
    // printf("Digite sua sexo(f ou m): ");
    // scanf("%c", &pessoa1.sexo);



    // printf("Nome: %s\nIdade: %d\nSexo: %c", pessoa1.nome, pessoa1.idade, pessoa1.sexo);



    // como cirar novos tipos de dados em C com typedef struct
    // Pessoa pessoa1;
    // struct Pessoa2 pessoa2;


    // pessoa2.idade = 35;
    // pessoa2.sexo = 'f';
    // strcpy(pessoa2.nome,"Maria");

    // printf("Nome: %s\nIdade: %d\nSexo: %c", pessoa2.nome,pessoa2.idade,pessoa2.sexo);

    return 0;
}
