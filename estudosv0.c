#include <stdio.h>
#include <stdlib.h>

int main() {
    

    /* funciona conforme o incremento 
    int  contador = 10;
    
    
    printf("valor: %d\n", --contador);


    /*
    como funciona a atruibuição em variáveis com contador
    no caso da variável resutaldo primeiro é Atribuído o valor 10 
    e depois o valor é incrementado.

    int resultado, contador = 10;
    //contador ++;
    //contador += 1;
    //contador  = contador +1;
    resultado = contador++;
    printf("valor: %d\n", resultado);
    

    printf("valor: %d\n", contador++);
    printf("valor: %d\n", contador);
    


    /*
    int a= 7 , b = 20 ;
    printf("resto da divisao inteira %d\n ", a % b);
    printf("resto da divisao inteira %d\n ", b % a);
    

    /*
    int a= 10 , b = 20 ; 
    float pi = 3.1415;

    a= (int)pi;
    printf("Valor de a: %d\n ", a);
    printf("\n Soma: %d \n", a + b);
    printf("\n Subtracao : %d \n", a - b);
    printf("\n Multiplicacao: %d \n", a * b);
    printf("\n Divisao: %f \n", (float)a / b); 


    /*
    printf("\n Soma: %d \n", 10 +20);
    printf("\n Subtracao : %d \n", 10 - 20);
    printf("\n Multiplicacao: %d \n", 10 * 20);
    printf("\n Divisao de um inteiro por um inteiro em c resulta em inteiro: %f \n", 10 / 20);
    printf("\n Divisao: %f \n", 10.0 / 20);


    /*caracter de escape

    printf("\n\nisto e uma mesnagem \"a\" ser impressa na tela \n\n");
    printf("\n\nisto e uma mesnagem \"a\" \\ser impressa na tela \n\n");

    /* long double e outras coisas
    long double y = 3.1415896598877898988455547;
    
    printf("valor de y: %Lf\n", y );
    __mingw_printf("valor de y: %.15Lf\n", y ); 
    printf("um float precisa de %d bytes de momeria.\n", sizeof y);
    


    /* double
    float  x = 3.1415;
    double y = 3.1415896598877898988455547;
    
    printf("um float precisa de %d bytes de momeria.\n", sizeof x );
    printf("um float precisa de %d bytes de momeria.\n", sizeof y);
    
    
    /*float  x =  3.1415;
    printf("um float precisa de %d bytes de momeria.\n", sizeof x );
    printf("um float precisa de %d bytes de momeria.\n", sizeof (float));

    /* em arquitentura modernas long int e int tem o mesmo tamanho 4 bytes, 
    então é necessario colocar long long int ,
    so lembrando que tem que colocar %lld ou %lli 

    long long int x = 2147483647;

    printf("Tamanho de x em bytes : %d \n", sizeof x );

    printf("valor de x %lld\n", x );
    x++;
    printf("valor de x %lli\n", x );



    /* limite para variável int 
    int x = 2147483647;

    printf("valor dex %d\n", x );
    x++;
    printf("valor dex %d\n", x );
    
    
    /*int y =0;
    short int x = 32767;

    printf("valor dex %d\n", x );
    x++;
    printf("valor dex %hi\n", x );


    /*int y =0;
    short int x = 32767;

    printf("Tamanho em memoria de um int: %d \n bytes", sizeof y );
    printf("Tamanho em memoria de um int: %d\n bytes", sizeof x);

   // short reduz  o espaço ocupado em memoria , serve para inteiros dentro do intervalo -23768 até 32,767
   /* 
    float x = 1.0;

    printf("Tamanho em memoria de um float: %d \n bytes", sizeof x );
    printf("Tamanho em memoria de um int: %d\n bytes", sizeof(int));

    // um inteiro ocupa 4 * 8 = 32 bits
    /*  1 Byte = 8 bits.
        1 Kilobyte = 1024 bytes
        1 Megabyte = 1024 Kilobytes ou KB
        1 Gigabyte = 1024 Megabytes ou MB
        1 Terabyte = 1024 Gigabytes ou GB
        1 Petabyte = 1024 Terabytes ou TB
        1 Exabyte = 1024 Petabytes ou PB
        1 Zettabyte = 1024 Exabytes ou EB
        1 Yottabyte = 1024 Zettabytes ou ZB

    /*char a, b;

    printf("Digite uma letra  ");
    scanf("%c",  &a);

    printf("Digite a Segunda letra   ");
    scanf(" %c",  &b);




    printf("Primeira letra : %c \nSegunda letra: %c \n ", a , b);

    segunda maneira em que o codigo gera problema por conta do buffer de tecledo

    /*char a, b ;

    printf("Digite duas letras:  ");
    scanf("%c %c",  &a,  &b);


    printf("Primeira letra : %c \nSegunda letra: %c \n ", a , b);


    /*char sexo;
    int idade ;
    float peso, altura;

    printf("digite idade ,peso, altura e o sexo (f,F,m oiu M): \n ");
    scanf("%d%f%f %c",  &idade, &peso, & altura, &sexo);

    printf("sexo: %c \n idade : %d \n peso : %.1f \n Altura: %2f\n", sexo, idade, peso, altura);
    return 0;

    solucionado  o problema relacionado ao buffer de teclado , no na ultima "vari�vel do scanf foi necess�rio colocar um espa�o"

/*

    /* exercicio testando os conhecimentos
    char sexo;
    int idade;
    float peso, altura;

    printf("Digite seu sexo (M/F): \n");
    scanf(" %c", &sexo);  // Adicionei um espa�o antes de %c para consumir o caractere de nova linha
    printf("Digite sua idade: \n");
    scanf("%d", &idade);
    printf("Digite seu peso (com ponto): \n");
    scanf("%f", &peso);
    printf("Digite sua altura (com ponto): \n");
    scanf("%f", &altura);

    printf("Seu sexo: %c\nSua idade: %d\nSeu peso: %.2f\nSua altura: %.2f\n", sexo, idade, peso, altura);
*/


 /*

    int num1, num2, num3;

    printf("Digite tres valores inteiros : ");
    scanf("%d%d%d", &num1, &num2, &num3 );

    printf("Valores digitados: %d, %d e  %d \n ", num1, num2, num3);

*/
/*
    char letra;
    printf("Digite um caracter: ");
    letra = fgetc(stdin);

    printf("Caracter lido : %c \n ", letra);

*/

    /*
    char letra;
    printf("Digite um caracter: ");
    letra = getc(stdin);

    printf("Caracter lido : %c \n ", letra);


*/

/* alternativa ao scanf
    char letra ;

    printf("Digite uma letra : ");
    letra = getchar();


    printf("Caracter lido: %c \n", letra);

*/


/*
    char sexo = 'k';
    printf("Valor da variavel  sexo: %c\n  ", sexo);


    printf("Digite o seu sexo: (f, F, m ou M): ");
    scanf("%c", &sexo);

    printf("Valor da variavel  sexo: %c\n  ", sexo);

*/

/*
    float numero = 3.1415;

    printf("Valor da minha vairavel : %.4f \n", numero);

    printf("Digite um numero real: ");
    scanf("%f", &numero);

    printf("Valor digitado pelo usuario : %.4f \n", numero);

*/


    /*
    int valor,valor2;

    valor = 50;
    printf("Digite um valor inteiro ");
    scanf("%d", &valor);

    printf("Digite o segundo valor inteiro ");
    scanf("%d", &valor2);

    printf("\n\n primeiro valor digitado :  %d \n Segundo valor  digitado: %d \n\n", valor, valor2);
    */


    return 0 ;
}
