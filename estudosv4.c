#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// #include <math.h>
#include <time.h>
#include <string.h>// para usar o strlen
// comando para compilar o codigo criando o a.exe para usar o debug (  gcc -g estudos.c -o a.exe  )

int main() { setlocale(LC_ALL,"");
    // leia uma frase e descubra se � palindroma
    
   char palavra[50], copia[50];
    int i, tam, diferentes = 0, j = 0;

    printf("Digite uma frase: ");
    scanf("%50[^\n]", palavra);

    // remover => !? .
    for(i = 0; i < strlen(palavra); i++){
        if(palavra[i] != '!' && palavra[i] != '?' && palavra[i] != ' ' && palavra[i] != '.')
            copia[j++] = palavra[i];
    }

    copia[j] = '\0';

    printf("Original: %s\nCopia:%s\n", palavra, copia);

    tam = strlen(copia);
    tam--;
    for(i = 0; i < strlen(copia); i++){
        if(copia[i] != copia[tam])
            diferentes++;
        tam--;
    }

    if(diferentes == 0)
        printf("\nEh palindroma...\n");
    else
        printf("\nNao eh palindroma...\n");

    // leia uma palvara e diga se ela � palindroma
    // char palavra[30];
    // int i, tam, diferentes = 0;

    // printf("Digite uma palavra: ");
    // scanf("%s", palavra);

   
    // tam = strlen(palavra);
    // tam--;// �ltimo �ndice v�lido da string (vetor)
    // i = 0; // primeiro �ndice v�lido da string (vetor)

    // while(tam >= i){
    //     if(palavra[i] != palavra[tam]) // conta as letras diferentes
    //         diferentes ++;
    //     i++;
    //     tam--;
    // }

    // if(diferentes == 0)
    //     printf("\nEh palindroma...\n");
    // else
    //     printf("\nNao eh palindroma...\n");

    


    
    // char palavra[30], copia[30];
    // int i, tam, iguais = 0;

    // printf("Digite uma palavra: ");
    // scanf("%s", palavra);// com o fgets ficaria assim a contagem de caracter oi\n\o
    
    // tam = strlen(palavra);
    
    // for(i = 0; i <strlen(palavra); i++){
    //     copia[i] = palavra[tam - 1];
    //     tam--;
    // }
    // copia[i] = '\0';

    // tam = strlen(palavra);

    // printf("Original: %s\nCopia : %s", palavra, copia);

    // for(i = 0; i < tam; i++){
    //     if(palavra[i] == copia[i])
    //         iguais++;
        
    // } 
    // if(iguais == tam){
    //     printf("\n� palindroma");
    // }else
    //     printf("\nN�o � palindroma");
    // matriz de strings na linguagem c

    //c�digo do professor com problema do scanf 
    // char nomes[5][25];
    // int l;

    // for(l = 0; l < 5; l++){
    //     printf("\nDigite o nome da posicao %d. ", l);
    //     scanf("%25[^\n]", nomes[l]);
    //     scanf("%c");
    // }

    // for(l = 0; l < 5; l++)
    //     printf("\nNome na posicao %d: %s", l, nomes[l]);


    // meu c�digo da aula
    // char nomes[5][25];
    // int l ;
    // for(l = 0 ; l< 5 ; l++){
    //     printf("Digite o nome da posi��o %d: ", l);
    //     fgets(nomes[l], 25, stdin);// pode ser o scanf("%25[^\n]", nomes[l]), tem que usar um scanf("%c")
    // }
    // for(l = 0 ; l< 5 ; l++){
    //     printf("\nNome na posi��o %d: %s", l, nomes[l]);
    // }

    // como divir um string com a fun��o strtok()
    // char palavra[50] = {"Bom!dia.simpatia Bom dia"};
    // char *pt;

    // pt = strtok(palavra, "!. ");
    // while(pt){
    //     printf("token: %s\n", pt);
    //     pt = strtok(NULL, "!. ");// aqui tem que colocar null para o ponteiro ir para proxima ocorr�ncia 
    // }

    // como imprir a string em mai�sculo ou mini�sculo com fun��es strupr() e strlwr()
    // char palavra[50] = {"Bom dia simpatia!"};
    
    
    // printf("\nAntes: %s\n", palavra);
    // strupr(palavra);
    // printf("\nDepois: %s\n", palavra);
    // strlwr(palavra);
    // printf("\nDepois2: %s\n", palavra);

    //  localizando uma substring com a fun��o strstr
    // char palavra[50] = {"Bom dia simpatia!"};
    // char str[] = {"uia"};
    // char *ponteiro;

    // ponteiro = strstr(palavra, str); // primeiro campo onde vai buscar e o segundo oque se est� buscando 
    
    // if(ponteiro)// so colocando  o ponteiro assim dentro do if a linguagem c ja verifica que o ponteiro � nulo ou n�o, seria equivalente a fazer ponteiro =! null
    //     printf("\n%c%c%c\n", *ponteiro,*(ponteiro+1),*(ponteiro+2));
    // else
    //     printf("\nPonteiro nulo.\n");

    // como achar um caracter dentro de um string com strchr e strrchr
    // strchr -> retorna a primeira ocorr�ncia
    // strrchr -> retorna a ultima ocorr�ncia

    // char palavra[50] = {"abacate"};
    // char *letra; // o * marca que a vari�vel para guardar um  ponteiro do car�cter

    // letra = strchr(palavra, 'a');
    // printf("\n%c\n", *letra);//  como imprimir o cont�udo de um ponteiro  
    // printf("\n%c\n", *(letra + 1 ));// artimetica de ponteiros para apontar para o pr�ximo
    // printf("\n%c\n", *(letra + 3 ));


    // printf("usando o strrchr");
    // letra = strrchr(palavra, 'a');


    // printf("\n%c\n", *letra);
    // printf("\n%c\n", *(letra + 1 ));

    // como fazer uma copia da string com strcpy()

    // char palavras[50] = {"bola"};
    // char palavras2[50] = {"abacate"};
    
    // printf("\nAntes de copiar");
    // printf("\npalavra 1 %s\npalavra 2: %s\n", palavras, palavras2);
    
    // strcpy(palavras2, palavras);// par�metro � o local de destino e o segundo � o que vai ser copiado 
    
    // printf("\ndepois de copiar");
    // printf("\npalavra 1 %s\npalavra 2: %s\n", palavras, palavras2);

    // palavras = palavras2  n�o funciona

    // como comprarar duas strings com a fun��o strcmp()
    // 0 - quando as strings s�o iguais
    // -1 - quando a string1 for menor do que a primeira (na rela��o alfabetica)
    // 1 - quando a string1 for maior do que a primeira (na rela��o alfabetica)

    // char palavras[50] = {"bola"};
    // char palavras2[50] = {"abacate"};

    // printf("\n\n Resultado : %d\n\n", strcmp(palavras, palavras2));


    // strcat para concatenar duas strings
    // char palavras[50] = {"Oi."};
    // char palavras2[50] = {" Bom Dia."};

    // strcat(palavras,palavras2);

    // printf("\n\t%s", palavras);


    // fun��o strlen()
    // int tam;
    // char palavras[55] = {"Oi, Vamos aprender a programar com a linguagem C?"};
    
    // // printf("Digite algo: ");
    // fgets(palavras, 15,stdin);
    


    // tam = strlen(palavras);
    // printf("\nTamnho da string :%d ", tam);

    // // ou 
    // printf("\nTamnho da string :%d ", strlen(palavras));

    // como descobrir o tamanho de uma string sem a fun��o

    // int i, tam = 0 ;
    // char palavras[55] = {"Oi, Vamos aprender a programar com a linguagem C?"};
    // printf("Digite algo: ");
    // fgets(palavras, 15,stdin);

    
    // i = 0;
    // while(palavras[i] != '\0'){
    //     if(palavras[i] == '\n')
    //         palavras[i] = '\0';
    //     i++;
    // }

    // i = 0;
    // while(palavras[i] != '\0'){
    //     tam++;
    //     i++;
    // }


    // printf("\nTamnho da string :%d ", tam);


    // como identificar o fim de uma string
    // int i ;
    // char palavras[55] = {"Oi, Vamos aprender a programar com a linguagem C?"};
    
    // // for (i = 0 ;i < 55;i++){
    // //     printf("%d = %c\n", i, palavras[i]);
    // // }
    // // for (i = 0 ;i < 55;i++){
    // //     printf("%d = %d\n", i, palavras[i]);// imprimindo o codigo decimal da tabela ascii, o codigo para o fim da string � \0
    // // }
    // // fgets(palavras, 15,stdin);

    // // printf("\n");
    // i = 0;
    // while(palavras[i] != '\0'){
    //     printf("%d = %c\n", i, palavras[i]);
    //     i++;
    // }


    // printf("\n");



    // printf("Digite o seu nome: ");
    // fgets(palavras, 10,stdin);

    

    
    
    // fun��o fgets()

    // char palavras[10] = {""};
    // printf("Digite o seu nome: ");
    // fgets(palavras, 10,stdin);// forma segura, se o vetor tem tamanho 10 ele so vai ler 9 , o ultimo caracter fica como fim de string

    // printf("%s\n\n", palavras);


    // fun��o gets()
    // char palavras[10] = {"Oi, Vamos aprender a programar com a linguagem C?"};
    // printf("Digite o seu nome: ");
    // gets(palavras);// fun��o insegura, n�o � reomendado
    // printf("%s", palavras);


    // char palavras[10] = {"Oi, Vamos aprender a programar com a linguagem C?"};
    // // printf("Digite o seu nome: ");
    // // scanf("%s", palavras); // em string n�o precisa do & , somente em string pelo que professor falou
    // // a fun��o scanf so le at� primeiro op��o

    // printf("Digite o seu nome: ");
    // scanf("%10[^\n]", palavras); // como fazer o scanf ler o op��o, com o numero 10 ("%10[^\n]") ele limite q quantidade de caracter

    // printf("%s", palavras);

    //módulo de string , O que � uma string (sequência de caracteres)
    // char palavras[] = {"Oi, Vamos aprender a programar com a linguagem C?"};


    // printf("%c\n", palavras[1]);
    // printf("%s", palavras); // como imprimir uma string



    return 0;
}
