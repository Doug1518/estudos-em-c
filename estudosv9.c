#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#include <string.h>// para usar o strlen
#include <ctype.h>




int main(){
    /*
            Aula 222  Como remover / apagar um arquivo com a função remove?

              
    */

    char nome[] = {"Conto.txt"};
    FILE *file = fopen(nome, "r");

    if(file){
        printf("\nArquivo aberto com sucesso\n");
        fclose(file);

        printf("Retorno : %d\n", remove(nome));
    }
    else{
        printf("\nErro ao abrir arquvio\n");
        printf("Retorno : %d\n", remove(nome));
    }
    /*
            AGENDA DE ANIVERSÁRIOS com funções de arquivo binário (salvar, alterar e ler)

            Código escrito por Wagner Gaspar
            Junho de 2021


#include <stdio.h>
#include <stdlib.h>

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
        scanf("%49[^\n]", novo->nome);
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
        scanf("%49[^\n]", novo->nome);
        printf("\nDigite a data de aniversario dd mm aaaa: ");
        scanf("%d%d%d", &novo->dia, &novo->mes, &novo->ano);
        getchar();
        c[id] = novo;
    }
    else
        printf("\n\tCodigo invalido!\n");
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

void salvarB(char arq[], Contato **c, int quant){
    FILE *file = fopen(arq, "wb");
    int i;

    if(file){
        for(i = 0; i < quant; i++)
            fwrite(c[i], sizeof(Contato), 1, file);
        fclose(file);
    }
    else
        printf("\nErro ao abrir arquivo!\n");
}

int lerB(char arq[], Contato **c){
    int quant = 0;
    Contato *novo = malloc(sizeof(Contato));
    FILE *file = fopen(arq, "rb");

    if(file){
        while(fread(novo, sizeof(Contato), 1, file)){
            c[quant] = novo;
            quant++;
            novo = malloc(sizeof(Contato));
        }
        fclose(file);
    }
    else
        printf("\nErro ao abrir arquivo!\n");
    return quant;
}

void alterarB(char arq[]){
    FILE *file = fopen(arq, "rb+");
    Contato c;
    int id, i = 1;

    if(file){
        printf("\tLista de contatos:\n");
        printf("\t----------------------------\n");
        while(fread(&c, sizeof(Contato), 1, file)){
            printf("\t%d = %2d/%2d/%4d\t%s\n", i, c.dia, c.mes, c.ano, c.nome);
            i++;
        }
        printf("\t----------------------------\n");

        printf("\n\tDigite o indice do contato que deseja alterar:\n\n");
        scanf("%d", &id);
        getchar();
        id--;

        if(id >= 0 && id < i - 1){
            printf("\tDigite nome e data de nascimento dd mm aaaa: ");
            scanf("%49[^\n]%d%d%d", c.nome, &c.dia, &c.mes, &c.ano);
            fseek(file, id * sizeof(Contato), SEEK_SET);
            fwrite(&c, sizeof(Contato), 1, file);
        }
        fclose(file);
    }
    else
        printf("\nErro ao abrir arquivo!\n");
}

int main(){

    Contato *agenda[50];
    char arquivo[] = {"agenda.txt"};
    char arquivo2[] = {"agenda.dat"};
    int opcao, tam = 50, quant = 0;

    do{
        printf("\n\t0 - Sair\n\t1 - Cadastrar\n\t2 - Alterar\n\t3 - Imprimir\n");
        printf("\t4 - Salvar\n\t5 - Ler arquivo\n\t6 - SalvarB\n\t7 - LerB\n\t8 - AltererB\n");
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
            salvarB(arquivo2, agenda, quant);
            break;
        case 7:
            quant = lerB(arquivo2, agenda);
            break;
        case 8:
            alterarB(arquivo2);
            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}
*/

    /*
        Aula 218 e 219: Lendo em arquivo binário com a função fread()

        Código escrito por Wagner Gaspar
        Junho de 2021

        Modos de abertura de arquivos:
        wb -> Escrita
        rb -> leitura
        ab -> anexar
        rb+ -> leitura e escrita
        wb+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
        ab+ -> leitura e escrita (adiciona ao final do arquivo)


    typedef struct{
        char nome[50];
        int dia, mes, ano;
    }Contato;

    void escrever(char arq[]){
        Contato c;
        FILE *file = fopen(arq, "ab");

        if(file){
            printf("Digite o nome e a data de nascimento dd mm aaaa: ");
            scanf("%49[^\n]%d%d%d", c.nome, &c.dia, &c.mes, &c.ano);
            fwrite(&c, sizeof(Contato), 1, file);
            fclose(file);
        }
        else
            printf("\nErro ao abrir arquivo!\n");
    }

    void ler(char arq[]){
        Contato c;
        FILE *file = fopen(arq, "rb");

        if(file){
            while(!feof(file)){
                if(fread(&c, sizeof(Contato), 1, file))
                    printf("\nNome: %s\nData: %d/%d/%d\n", c.nome, c.dia, c.mes, c.ano);
            }
            fclose(file);
        }
        else
            printf("\nErro ao abrir arquivo!\n");
    }

    int main(){
        char arquivo[] = {"agenda.dat"};

        escrever(arquivo);
        ler(arquivo);

        return 0;
    }

    */

    /*
        Aula 218: Escrevendo em arquivo binário com a função fwrite()

        Modos de abertura de arquivos:
        wb -> Escrita
        rb -> leitura
        ab -> anexar
        rb+ -> leitura e escrita
        wb+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
        ab+ -> leitura e escrita (adiciona ao final do arquivo)
    */
 
    /*
        Aula 218: Escrevendo em arquivo binário com a função fwrite()

        Código escrito por Wagner Gaspar
        Junho de 2021

        Modos de abertura de arquivos:
        wb -> Escrita
        rb -> leitura
        ab -> anexar
        rb+ -> leitura e escrita
        wb+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
        ab+ -> leitura e escrita (adiciona ao final do arquivo)


    typedef struct{
        char nome[50];
        int dia, mes, ano;
    }Contato;

    void escrever(char arq[]){
        Contato c;
        FILE *file = fopen(arq, "ab");

        if(file){
            printf("Digite o nome e a data de nascimento dd mm aaaa: ");
            scanf("%49[^\n]%d%d%d", c.nome, &c.dia, &c.mes, &c.ano);
            fwrite(&c, sizeof(Contato), 1, file);
            fclose(file);
        }
        else
            printf("\nErro ao abrir arquivo!\n");
    }

    int main(){
        char arquivo[] = {"agenda.dat"};

        escrever(arquivo);

        return 0;
    }
    */

    /* Codigo das aulas 215 até 2017

    

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
        printf("\n\t0 - Sair\n\t1 - Cadastrar\n\t2 - Alterar\n\t3 - Imprimir\n\t4 - Salvar\n\t5 - Ler arquivo\n");
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
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);
*/



 /*
        Aula 214: Como ler um arquivo de texto com a função fscanf?

        Código escrito por Wagner Gaspar
        Junho de 2021

        Modos de abertura de arquivos:
        w -> Escrita
        r -> leitura
        a -> anexar
        r+ -> leitura e escrita
        w+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
        a+ -> leitura e escrita (adiciona ao final do arquivo)


    void escrever(char f[]) {
        FILE *file = fopen(f, "w");
        char nome[100];
        int opcao, idade;
        float altura;

        if(file) {
            do{
                printf("Digite nome, idade e altura: ");
                scanf("%100[^\n]%d%f", nome, &idade, &altura);
                fprintf(file, "%s %d %.2f\n", nome, idade, altura);
                printf("\nDigite 1 para inserir outro registro. ");
                scanf("%d", &opcao);
                scanf("%c");
            }while(opcao == 1);
            fclose(file);
        } else
            printf("\nERRO ao abrir arquivo!\n");
    }

    void ler(char f[]) {
        FILE *file = fopen(f, "r");
        char nome[100];
        int idade;
        float altura;

        if(file){
            printf("\tDados lidos do arquivo:\n");
            while(fscanf(file, "%s%d%f", nome, &idade, &altura) != -1)
                printf("\n\tNome: %s\n\tIdade: %d\n\tAltura: %.2f\n", nome, idade, altura);
            fclose(file);
        }
        else
            printf("\nERRO ao abrir arquivo!\n");
    }

    int main() {

        char nome[] = {"conto.txt"};

        escrever(nome);
        ler(nome);

        return 0;
    }

    */



    /*
        Aula 213: Como escrever em um arquivo texto com a função fprintf?

        Modos de abertura de arquivos:
        w -> Escrita
        r -> leitura
        a -> anexar
        r+ -> leitura e escrita
        w+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
        a+ -> leitura e escrita (adiciona ao final do arquivo)


    void escrever(char f[]) {
        FILE *file = fopen(f, "w");
        char nome[100];
        int opcao, idade;
        float altura;

        if(file) {
            do{
                printf("Digite nome, idade e altura: ");
                scanf("%99[^\n]%d%f", nome, &idade, &altura);
                fprintf(file, "%s %d %.2f\n", nome, idade, altura);
                printf("\nDigite 1 para inserir outro registro. ");
                scanf("%d", &opcao);
                scanf("%c");
            }while(opcao == 1);
            fclose(file);
        } else
            printf("\nERRO ao abrir arquivo!\n");
    }

    int main() {

        char nome[] = {"conto.txt"};

        escrever(nome);

        return 0;
    }
*/

    /*
        Aula 212: Como ler linhas de texto com a função fgets?

        

        Modos de abertura de arquivos:
        w -> Escrita
        r -> leitura
        a -> anexar
        r+ -> leitura e escrita
        w+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
        a+ -> leitura e escrita (adiciona ao final do arquivo)
    */
        // char nome[] = {"conto.txt"};

        // escrever(nome);
        // ler(nome);

    /*
        Aula 211: Como escrever linhas de texto com a função fputs?

        

        Modos de abertura de arquivos:
        w -> Escrita
        r -> leitura
        a -> anexar
        r+ -> leitura e escrita
        w+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
        a+ -> leitura e escrita (adiciona ao final do arquivo)
    
    
    void escrever(char f[]) {

    o problema do scanf ler o enter restante do buffer do teclado 
    pode ser resolvido facilmente só adicionando um espaço antes do %. 
    Assim: "scanf(" %500[^\n]",texto);"
    

   FILE *file = fopen(f, "w");
    char texto[500];

    if(file) {
        printf("Digite uma frase ou 1 caracter para finalizar:\n");
        while (1) {
            // Consumindo o ENTER do buffer e capturando a linha completa
            scanf(" %499[^\n]", texto); 

            if (strlen(texto) == 1) // Encerra quando uma letra for digitada
                break;

            fputs(texto, file);
            fputc('\n', file);
        }
        fclose(file);
    } else {
        printf("\nERRO ao abrir arquivo!\n");
    }
        }
    
    int main() { setlocale(LC_ALL,"");
    char nome[] = {"conto.txt"};

    escrever(nome);
        

    
    */


    /*
        Aula 210: Organizando nosso código em procedimentos

        Código escrito por Wagner Gaspar
        Junho de 2021

        Modos de abertura de arquivos:
        w -> Escrita
        r -> leitura
        a -> anexar
        r+ -> leitura e escrita
        w+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
        a+ -> leitura e escrita (adiciona ao final do arquivo)


    void escrever(char f[]) {
        FILE *file = fopen(f, "w");
        char letra;

        if(file) {
            printf("\nDigite um texto e pressione ENTER ao finalizar!");
            scanf("%c", &letra);
            while(letra != '\n') {
                fputc(letra, file);
                scanf("%c", &letra);
            }
            fclose(file);
        } else
            printf("\nERRO ao abrir arquivo!\n");
    }

    void ler(char f[]) {
        FILE *file = fopen(f, "r");
        char letra;

        if(file){
            printf("\n\tTexto lido do arquivo:\n");
            while(!feof(file)) {
                letra = fgetc(file);
                printf("%c", letra);
            }

            fclose(file);
        }
        else
            printf("\nERRO ao abrir arquivo!\n");
    }

    int main() {

        char nome[] = {"conto.txt"};

        escrever(nome);
        ler(nome);

        return 0;
    }

*/


    /*
        Aula 209: Como ler em arquivo texto com a função fgetc?

        

        Modos de abertura de arquivos:
        w -> Escrita
        r -> leitura
        a -> anexar
        r+ -> leitura e escrita
        w+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
        a+ -> leitura e escrita (adiciona ao final do arquivo)
    


    
    FILE *file; 
    char letra;

    file = fopen("conto.txt","w+"); // tem como vc informa o diretorio que deseja abrir no primeiro argumento da função fopen

    if(file){
        printf("\nDigite um texto e pressione ENTER ao finalizar!");
        scanf("%c", &letra);
        while(letra != '\n'){
            fputc(letra, file);
            scanf("%c", &letra);
        }
        rewind(file);
        printf("\n\tTexto lido do arquivo : \n");
        while(!feof(file)){
            letra = fgetc(file);
            printf("%c", letra);
        }

        fclose(file);
    }
    else{
        printf("\n\t --> Erro ao abrir arquivo !\n");
    }
    
    */

    /*
        Aula 208: Como escrever em arquivo texto com a funç?o fputc?

        Modos de abertura de arquivos:
        w -> Escrita
        r -> leitura
        a -> anexar
        r+ -> leitura e escrita
        w+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
        a+ -> leitura e escrita (adiciona ao final do arquivo)

    FILE *file; 
    char letra;

    file = fopen("conto.txt","w"); // tem como vc informa o diretorio que deseja abrir no primeiro argumento da função fopen

    if(file){
        printf("\nDigite um texto e pressione ENTER ao finalizar!");
        scanf("%c", &letra);
        while(letra != '\n'){
            fputc(letra, file);
            scanf("%c", &letra);
        }
        fclose(file);
    }
    else{
        printf("\n\t --> Erro ao abrir arquivo !\n");
    }

*/
return 0;
}
