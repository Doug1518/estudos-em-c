#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
     /*Fa�a um programa que, dado tr�s valores a, b e c, verifique se eles podem ser os comprimentos
    dos lados de um tri�ngulo. Caso positivo, seu programa deve informar tamb�m se o tri�ngulo �
    equil�tero, is�sceles ou escaleno. Caso contr�rio, seu programa deve escrever a mensagem �N�o
    formam um tri�ngulo�.
    solu��o do professor 
    int main() {
    int a, b, c;

    printf("Digite tres valores: ");
    scanf("%d%d%d", &a, &b, &c);

    if(a + b > c && a + c > b && b + c > a){
        printf("Os 3 lados formam um triangulo!\n");
        if(a == b && a == c)
            printf("Equilatero\n");
        else
            if(a == b || a == c || b == c)
                printf("Isosceles\n");
            else
                printf("Escaleno\n");
    }
    else
        printf("Os 3 lados NAO formam um trinagulo!\n");
}
    
    minha solu��o
    setlocale(LC_ALL,"");
    int lado1, lado2, lado3;
    printf("Digite o primeiro lado do tri�ngulo: "); 
    scanf("%d", &lado1);
    printf("Digite o segundo lado do tri�ngulo: "); 
    scanf("%d", &lado2);
    printf("Digite o terceiro lado do tri�ngulo: "); 
    scanf("%d", &lado3);
    if(lado1 + lado2 > lado3 && lado1 + lado3 > lado2  && lado2 + lado3 > lado1){
        if(lado1 == lado2 && lado2 == lado3)
            printf("O tri�ngulo � equil�tero");
        else if  ((lado1 == lado2 && lado1 != lado3) || (lado1 == lado3 && lado1 != lado2) || (lado2 == lado3 && lado2 != lado1))
            printf("O tri�ngulo � is�sceles");
        else if  (lado1 != lado2 && lado2!=lado3 && lado1 != lado3)
            printf("O tri�ngulo � escaleno");
    }else
        printf("O 3 lados n�o formam um tri�ngulo");
    /*Um usu�rio deseja um programa onde possa escolher que tipo de m�dia deseja calcular a partir
    de tr�s notas. Fa�a um programa que leia as notas e o tipo da m�dia escolhida pelo usu�rio e calcule
    a apresente a m�dia:
    Op��es:
    � �a� - Aritm�tica.
    � �p� - Ponderada (pesos: 3,3,4).
    solu��o do professor
    int main() {
    float nota1, nota2, nota3;
    char escolha;

    printf("Qual a media deseja?\na - aritmetica\np - ponderada\n");
    scanf("%c", &escolha);

    printf("Digite as tres notas: ");
    scanf("%f%f%f", &nota1, &nota2, &nota3);

    if(escolha == 'a')
        printf("Media aritmetica: %.2f\n", (nota1 + nota2 + nota3) / 3);
    else
        if(escolha == 'p')
            printf("Media ponderada: %.2f\n", (nota1 * 3 + nota2 * 3 + nota3 * 4) / 10);
        else
            printf("\nOpcao invalida!!!\n");
}

    minha solu��o
    setlocale(LC_ALL,"");
    float nota1, nota2, nota3, media;
    char opcao;

    printf("Digite a primera nota: ");
    scanf("%f", &nota1);
    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);
    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    printf("\nOp��es\n'a' - Aritm�tica.\n'p' - Ponderada (pesos: 3,3,4).\n");
    scanf(" %c", &opcao);// colocado espa�o para o sistema n�o ler o \n, O scanf(" %c", &opcao); agora consome qualquer espa�o em branco, evitando problemas ao ler a op��o.

    switch(opcao){
        case 'a':
        media = (nota1+nota2+nota3)/3;
        printf("A sua m�dia aritm�tica: %f", media);
        break;
        case 'p':
        media = (nota1*3+nota2*3+nota3*4)/10;
        printf("A sua m�dia Ponderada: %f", media);
        break;
        default:
            printf("Op��o inv�lida.\n"); 10
            break;
    }


    /*Elabore um programa que, dado o n�mero do m�s, indica quantos dias t�m esse m�s. Utilize para
    isso a estrutura de sele��o switch.
    Obs.: Considere fevereiro como tendo 28 dias.*
    solu��o do professor 2
    int main() {
    int mes;

    printf("Digite um numero: ");
    scanf("%d", &mes);

    switch(mes) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        printf("\nO mes possui 31 dias\n");
        break;
    case 2:
        printf("\nO mes possui 28 dias\n");
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        printf("\nO mes possui 30 dias\n");
        break;
    default:
        printf("\nValor nao corresponde a nenhum mes!\n");
    }
}
    solu��o do professor
    int mes;

    printf("Digite um numero: ");
    scanf("%d", &mes);

    switch(mes) {
    case 1:
        printf("\nJaneiro com 31 dias\n");
        break;
    case 2:
        printf("\nFevereiro com 28 dias\n");
        break;
    case 3:
        printf("\nMarco com 31 dias\n");
        break;
    case 4:
        printf("\nAbril com 30 dias\n");
        break;
    case 5:
        printf("\nMaio com 31 dias\n");
        break;
    case 6:
        printf("\nJunho com 30 dias\n");
        break;
    case 7:
        printf("\nJulho com 31 dias\n");
        break;
    case 8:
        printf("\nAgosto com 31 dias\n");
        break;
    case 9:
        printf("\nSetembro com 30 dias\n");
        break;
    case 10:
        printf("\nOutubro com 31 dias\n");
        break;
    case 11:
        printf("\nNovembro com 30 dias\n");
        break;
    case 12:
        printf("\nDezembro com 31 dias\n");
        break;
    default:
        printf("\nValor nao corresponde a nenhum mes!\n");
    }

    minha res
    #include <stdio.h>
    setlocale(LC_ALL,"");
    int mes;

    // Leitura do n�mero do m�s
    printf("Digite o n�mero do m�s (1 a 12): ");
    scanf("%d", &mes);

    // Verifica quantos dias tem o m�s usando switch
    switch(mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            printf("Esse m�s tem 31 dias.\n");
            break;
        case 4: case 6: case 9: case 11:
            printf("Esse m�s tem 30 dias.\n");
            break;
        case 2:
            printf("Fevereiro tem 28 dias.\n");
            break;
        default:
            printf("M�s inv�lido.\n");
            break;
    }

    


    

    /*Fa�a um programa que pe�a ao usu�rio um caracter e diga se � uma vogal ou n�o.
    solu��o do professor
    int main() {
    char letra;

    printf("Digite um caracter: ");
    scanf("%c", &letra);
    // a, e, i, o, u, A, E, I, O, U
    if(letra == 'a' || letra == 'A' || letra == 'e' || letra == 'E' || letra == 'i'
       || letra == 'I' || letra == '0' || letra == 'O' || letra == 'u' || letra == 'U')
        printf("\tVogal...\n");
    else
        printf("\tConsoante\n");
}
    
    minha resolu��o
    setlocale(LC_ALL,"");
    char letra;
    printf("digite um carcater para ver ser ele � uma vogal: ");
    scanf("%c", &letra);
    if (letra  == 'a' || letra =='e' || letra =='i' || letra =='o' || letra =='u')
        printf("A letra que voc� digitou (%c) � uma vogal",letra);
    else
        printf(" A letra que voc� digitou (%c) n�o � vogal", letra);

    /*6) Fa�a um programa para ler um n�mero inteiro e verificar se corresponde a um m�s v�lido no
    calend�rio. Caso corresponda, escrever o nome do m�s, caso contr�rio, escrever a mensagem �M�s
    Inv�lido�.
    #include <stdio.h>

    
    int mes;

    // Leitura do n�mero inteiro
    printf("Digite um n�mero correspondente a um m�s (1 a 12): ");
    scanf("%d", &mes);

    // Verifica se o n�mero corresponde a um m�s v�lido
    switch(mes) {
        case 1:
            printf("Janeiro\n");
            break;
        case 2:
            printf("Fevereiro\n");
            break;
        case 3:
            printf("Mar�o\n");
            break;
        case 4:
            printf("Abril\n");
            break;
        case 5:
            printf("Maio\n");
            break;
        case 6:
            printf("Junho\n");
            break;
        case 7:
            printf("Julho\n");
            break;
        case 8:
            printf("Agosto\n");
            break;
        case 9:
            printf("Setembro\n");
            break;
        case 10:
            printf("Outubro\n");
            break;
        case 11:
            printf("Novembro\n");
            break;
        case 12:
            printf("Dezembro\n");
            break;
        default:
            printf("M�s Inv�lido\n");
            break;
    }

    return 0;
}


    int a ; 
    printf("Digite um numero: \n");
    scanf("%d", &a);

    if (a == 1):

    /*5) O IMC (�ndice de Massa Corporal), pode ser calculado dividindo-se o peso da pessoa (em kg)
    pela altura (h em metros) elevada ao quadrado (IMC= m/h�). Escreva um programa que leia o peso
    e a altura de uma pessoa, calcule e mostre o IMC e a faixa em que o indiv�duo se enquadra de cordo
    com a tabela abaixo:
    IMC Interpreta��o
    Menor que 18,5 Abaixo do peso
    Entre 18,5 e menor que 25 Peso normal
    Entre 25 e menor que 30 Sobrepeso
    Entre 30 e menor que 35 Obesidade grau 1
    Entre 35 e menor que 40 Obesidade grau 2
    Maior ou igual a 40 Obesidade grau 3
    solu��o do professor
    int main() {
    float massa, altura, imc;

    printf("Digite seu peso (em kg) e sua altura (em metros): ");
    scanf("%f%f", &massa, &altura);

    imc = massa / (altura * altura);

    if(imc < 18.5)
        printf("IMC: %f\tAbaixo do peso\n", imc);
    else if(imc >= 18.5 && imc < 25)
        printf("IMC: %f\tPeso normal\n", imc);
    else if(imc >= 25 && imc < 30)
        printf("IMC: %f\tSobrepeso\n", imc);
    else if(imc >= 30 && imc < 35)
        printf("IMC: %f\tObesidade grau 1\n", imc);
    else if(imc >= 35 && imc < 40)
        printf("IMC: %f\tObesidade grau 2\n", imc);
    else
        printf("IMC: %f\tObesidade grau 3\n", imc);
}
    
    
    minha soluc��o 

    float peso, altura, imc;
    printf("Digite seu peso em kg: \n");
    scanf("%f", &peso);
    printf("Digite sua altura em metros: \n");
    scanf("%f", &altura);

    imc = peso / (altura*altura);

    if(imc < 18.5)
        printf("Abaixo do peso");
    else if (imc >=18.5 && imc < 25 )
        printf("Peso normal");
    else if (imc >= 25 && imc < 30 )
        printf("sobrepeso");
    else if (imc >=30 && imc < 35 )
        printf("Obesidade grau 1");
    else if (imc >= 35 && imc < 40 )
        printf("Obesidade grau 2");
    else if (imc < 40 )
        printf("Obesidade grau 3");


    /*Crie um programa que permita ao usu�rio escolher entre fazer a convers�o de Real para D�lar ou
    de D�lar para Real. Utilize como taxa de c�mbio $1 igual a R$5.30.
    solucao do professor 
    int main() {
    float valor, valorConvertido;
    int opcao;

    printf("Digite o valor a ser convertido: ");
    scanf("%f", &valor);

    printf("\n1 - Converter de real para dolar\n2 - Converter de dolar para real\n");
    scanf("%d", &opcao);

    switch(opcao){
    case 1:// Converter de real para dolar
        valorConvertido = valor / 5.3;
        printf("Valor convertido: $%.2f\n", valorConvertido);
        break;
    case 2:// Converter de dolar para real
        valorConvertido = valor * 5.3;
        printf("Valor convertido: R$%.2f\n", valorConvertido);
        break;
    default:
        printf("\nOpcao invalida!!!\n");
    }
    printf("Valor convertido: %.2f\n", valorConvertido);
}

    minha solu��o
    setlocale(LC_ALL,"");
    int  opcao;
    float valor, valorF;

    printf("Digite a quantia monet�ria que voce far� a convers�o(Real ou dolar): ");
    scanf("%f", &valor);
    printf("\nDigite a op��o para convers�o (1 ou 2)");
    printf("\n1- Convers�o para dolar\n2- Convers�o para real\n");
    scanf("%d", &opcao);
    switch (opcao){
    case 1:
        valorF=  valor/5.30;
        printf("\nA convers�o de R$ %.2f para dolar retorna um valor de : $ %.2f", valor, valorF);
        break;
    case 2: 
        valorF=  valor*5.30;
        printf("\nA convers�o de $ %.2f para real retorna um valor de R$: %.2f", valor, valorF);
        break;
    default:
        printf ("\nOp��o invalida!\n");
    }

   
    /*3) Escreva um programa em C que leia um n�mero e informe se ele � divis�vel por 2, por 3 ou por
    5, ou se n�o � divis�vel por nenhum deles.
     solu��o do professor
    int main() {
    int num;

    printf("Digite um valor qualquer: ");
    scanf("%d", &num);

    // se resto de num por 2 for igual a 0 ou ...
    if(num % 2 == 0 || num % 3 == 0 || num % 5 == 0)
        printf("Divisivel por 2, 3 ou 5.\n");
    else
        printf("Nao divisivel por 2, 3 e 5.\n");
}

    minha solu��o
    setlocale(LC_ALL, "");
    int a;
    printf("digite um numero: ");
    scanf("%d", &a);

    if(a % 2 == 0)
        printf("o numero %d � divis�vel por 2", a);
    else if (a % 3 == 0)
        printf("o numero %d � div�sivel por 3 ", a);
    else if (a % 5 == 0)
        printf("o numero %d � div�sivel por 3 ", a);
    else
        printf("o numero %d N�o � div�sivel por 2,3 ou 5 ", a);
    /*
    int main() {
    int valor, positovos = 0, negativos = 0;

    printf("Digite o primeiro valor: ");
    scanf("%d", &valor);

    if(valor < 0)
        negativos++;// sin�nimo de -> negativos += 1; negativos = negativos + 1;
    else
        positovos++;

    printf("Digite o segundo valor: ");
    scanf("%d", &valor);

    if(valor < 0)
        negativos++;
    else
        positovos++;

    printf("Digite o terceiro valor: ");
    scanf("%d", &valor);

    if(valor < 0)
        negativos++;
    else
        positovos++;

    printf("Digite o quarto valor: ");
    scanf("%d", &valor);

    if(valor < 0)
        negativos++;
    else
        positovos++;

    printf("Digite o quinto valor: ");
    scanf("%d", &valor);

    if(valor < 0)
        negativos++;
    else
        positovos++;

    printf("\nPositivos: %d\nNegativos: %d\n", positovos, negativos);
}
    /*2) Escreva um programa em C que l� 5 n�meros inteiros, um por vez. Conte quantos destes valores
    s�o negativos e quantos s�o positivos. Ao final, imprima na tela a quantidade de n�meros negativos
    e positivos.
    O codigo so poderia usar if e else , pode estar meio longo e n�o conciso, por�m era oque dava para fazer 
   setlocale(LC_ALL,  "");
    int a,b,c,d,e, contadorP = 0, contadorN = 0;
    
    printf("Digite um numero: ");
    scanf("%d", &a);
    printf("Digite o segundo numero: ");
    scanf("%d", &b);
    printf("Digite o terceiro numero: ");
    scanf("%d", &c);
    printf("Digite o quarto numero: ");
    scanf("%d", &d);
    printf("Digite o quinto numero: ");
    scanf("%d", &e);
    
    if(a < 0)
        contadorN +=1;
    if(b < 0)
        contadorN +=1;
    if(c < 0)
        contadorN +=1;
    if(d < 0)
        contadorN +=1;
    if(e < 0)
        contadorN +=1;
    
    if(a > 0)
        contadorP +=1;
    if(b > 0)
        contadorP +=1;
    if(c > 0)
        contadorP +=1;
    if(d > 0)
        contadorP +=1;
    if(e > 0)
        contadorP +=1;

    printf("o numero de numeros positivos foi de: %d \n � de numeros negativos foi de: %d ", contadorP, contadorN);

    /* solu��o � sugest�o do professor em um coment�rio
    int main(){
	int a, b, c;
	printf("Digite tres numeros inteiros:\n");
	scanf("%d%d%d",&a, &b, &c);

	if((a<=b&&a<=c)&&(b>=a&&b>=c)){
		printf("Menor numero:%d\nMarior numero :%d\n",a,b);	
	}
	else if((a<=b&&a<=c)&&(c>=a&&c>=b)){
		printf("Menor numero:%d\nMaior numero :%d\n",a,c);
	}
	else if((b<=a&&b<=c)&&(c>=a&&c>=b)){
		printf("Menor numero:%d\nMaior numero :%d\n",b,c);
	}
	else if((b<=a&&b<=c)&&(a>=b&&a>=c)){
		printf("Menor numero:%d\nMaior numero :%d\n",b,a);
	}
	else if((c<=a&&c<=b)&&(a>=b&&a>=c)){
		printf("Menor numero:%d\nMaior numero :%d\n",c,a);
    }
	else if((c<=a&&c<=b)&&(b>=a&&b>=c)){
		printf("Menor numero:%d\nMaior numero :%d\n",c,b);
	}

 return 0;   
}*/

    /* segunda solu��o do professor
    int main() {
    int a, b, c, menor, maior;

    printf("Digite tres valores: ");
    scanf("%d%d%d", &a, &b, &c);

    /* segunda vers�o
        vari�veis menor e maior s�o inicializadas com o primeiro valor
    
    menor = a;
    maior = a;

    if(menor > b)
        menor = b;
    if(menor > c)
        menor = c;

    if(maior < b)
        maior = b;
    if(maior < c)
        maior = c;

    printf("Segunda versao\tMenor: %d\tMaior: %d\n", menor, maior);
}
    /* solu��o do professor
    int main() {
    int a, b, c, menor, maior;

    printf("Digite tres valores: ");
    scanf("%d%d%d", &a, &b, &c);

    // encontrando o menor
    if(a < b){
        if(a < c)
            menor = a;
        else
            menor = c;
    }
    else{
        if(b < c)
            menor = b;
        else
            menor = c;
    }

    // encontrando o maior
    if(a > b){
        if(a > c)
            maior = a;
        else
            maior = c;
    }
    else{
        if(b > c)
            maior = b;
        else
            maior = c;
    }

    printf("Primeira versao\tMenor: %d\tMaior: %d\n", menor, maior);
}
    /*Escreva um programa em C que leia tr�s valores e apresente qual � o maior e qual � o menor.
    minha solu��o
    setlocale(LC_ALL,"");
    int a,b,c, maior, menor;
    
    printf("Digite um numero: ");
    scanf("%d", &a);
    printf("Digite o segundo numero: ");
    scanf("%d", &b);
    printf("Digite o terceiro numero: ");
    scanf("%d", &c);

    if (a > b && b > c){
        maior = a;
        menor = c;
        printf("O maior numero � %d" , a);
        printf("\nO menor numero � %d" , c);
    }else if (a > c && c > b){
        maior = a;
        menor = b;
        printf("O maior numero � %d" , a);
        printf("\nO menor numero � %d" , b);
    }
    else if (b > a && a > c){
        maior = b;
        menor = c; 
        printf("O maior numero � %d" , b);
        printf("\nO menor numero � %d" , c);
    } else if (b > c && c > a){
        maior = b;
        menor = a; 
        printf("O maior numero � %d" , b);
        printf("\nO menor numero � %d" , a);
    }
    else if (c > a && a > b){
        maior = c;
        menor = b; 
        printf("O maior numero � %d" , c);
        printf("\nO menor numero � %d" , b);
    }else if (c > b && b > a){
        maior = c;
        menor = a; 
        printf("O maior numero � %d" , c);
        printf("\nO menor numero � %d" , a);
    }


    // if (a > b && a > c){
    //     maior = a;
    //     printf("O maior numero � %d" , a);
    // }else if (b > a && a > c){
    //     maior = b;
    //     printf("O maior numero � %d" , b);
    // }else if (c > a && c > a){
    //     maior = c;
    //     printf("O maior numero � %d" , c);
    // }

    /* colando as op��o no switch case com caracteres
    setlocale(LC_ALL,"");
    char opcao;

    printf("a - Cadastar produto\nb - Vender produto \nc - Buscar produto\nd - imprimir\ne - Sair\n");
    scanf("%c",&opcao);

    switch (opcao){
    case 'a':
        printf("\nCadastrando novo produto.\n");
        break;
    case 'b' :
        printf("\nVendendo um novo produto");
        break;
    case 'c' :
        printf("\nBuscando novo produto");
        break;
    case 'd' :
        printf("\nImprimindo relatorio.\n");
        break;  
    case 'e':
        printf("\nSaindo..\n") ;
        break;
    default:
        printf ("\nOp��o invalida!\n");
    }
    
    /*
    //Estrura de seleca��o de switch case
    setlocale(LC_ALL,"");
    int opcao;

    printf("1 - Cadastar produto\n2 - Vender produto \n3 - Buscar produto\n4 - imprimir\n5 - Sair\n");
    scanf("%d",&opcao);

    switch (opcao){
    case 1:
        printf("\nCadastrando novo produto.\n");
        break;
    case 2 :
        printf("\nVendendo um novo produto");
        break;
    case 3 :
        printf("\nBuscando novo produto");
        break;
    case 4 :
        printf("\nImprimindo relatorio.\n");
        break;  
    case 5:
        printf("\nSaindo..\n") ;
        break;
    default:
        printf ("\nOp��o invalida!\n");
    }
    
    /*
    int a ;
    printf("\n Digite um valor qualquer: ");
    scanf("%d", &a);

    //primeira vers�o
    printf("Operador tern�rio:\n");
    a < 0 ? printf("\n\tValor negativo !\n") : printf("\n\tValor positivo ou igual a zero!");
    
    printf("\n\nif/else\n\n");
    if(a < 0)
        printf("\n\tValor negativo !\n");
    else{
        if(a > 0 )
            printf("\n\t Valor positivo!\n");
        else
            printf("\n\tValor igual a zero!\n");
        
    // segunda vers�o com else if 
    if(a < 0)
        printf("\n\tValor negativo !\n");
    else if (a > 0)
        printf("\n\t Valor positivo!\n");
    else
            printf("\n\tValor igual a zero!\n");
    /*
    // operador l�gico de ou (||)
    // tabela verdade x     b   a || b
    //                v     v     v
    //                v     f     v
    //                f     v     v
    //                f     f     f
    setlocale(LC_ALL, "");
    int idade; 
    printf("Digite sua idade: ");
    scanf ("%d", &idade);

    if (idade <=5 || idade >=65)
        printf("Tem direito a gratuidade!\n");
    else
        printf("N�o tem direito a gratuidade\n");


    /*
    // operador l�gico de e (&)
    // tabela verdade x     b   a & b
    //                v     v     v
    //                v     f     f
    //                f     v     f
    //                f     f     f
    
    int idade; 
    char sexo;

    printf("Digite seu sexo f ou m : ");
    scanf("%c", &sexo );
    printf("Digite sua idade  : ");
    scanf("%d", &idade );
    if (sexo == 'm' && idade == 18) 
        printf("Alistamaento obrigatorio! \n");
    else
        printf("Dispensado!\n");

    // printf("Digite seu sexo f ou m : ");
    // scanf("%c", &sexo );
    // printf("Digite sua idade  : ");
    // scanf("%d", &idade );
    // if (sexo == 'm'){
    //     if (idade == 18 )
    //         printf("Alistamaento obrigatorio! \n");
    //     else 
    //         printf("Dispensado!\n");
    // }
    // else
    //     printf("Dispensado!\n");

    /*
    // operador l�gico de nega��o !
    // tabela verdade x     !x
    //                v     f
    //                f     v   
    // lembrar do if(0) e if (1) para verdadeiro e falso
    setlocale(LC_ALL,"");
    int a ;
    printf("\n Digite um valor qualquer: ");
    scanf("%d", &a);

    printf("Operador tern�rio:\n");
    !(a < 0 )? printf("\n\tValor negativo !\n") : 
        a > 0 ? printf("\n\t Valor posutivo!\n") : printf("\n\tValor igual a zero!\n");
    printf("\n\nif/else\n\n");
    if(!(a < 0))
        printf("\n\tValor negativo !\n");
    else{
        if(a > 0 )
            printf("\n\t Valor positivo!\n");
        else
            printf("\n\tValor igual a zero!\n");
    }

    /* operador tern�rio aninhado
    setlocale(LC_ALL,"");
    int a ;
    printf("\n Digite um valor qualquer: ");
    scanf("%d", &a);

    printf("Operador tern�rio:\n");
    a < 0 ? printf("\n\tValor negativo !\n") : 
        a > 0 ? printf("\n\t Valor posutivo!\n") : printf("\n\tValor igual a zero!\n");
    
    // printf("\n\nif/else\n\n");
    // if(a < 0)
    //     printf("\n\tValor negativo !\n");
    // else{
    //     if(a > 0 )
    //         printf("\n\t Valor positivo!\n");
    //     else
    //         printf("\n\tValor igual a zero!\n");
    // }


    /* decis�es aninhadas
    setlocale(LC_ALL,"");
    int a ;
    printf("\n Digite um valor qualquer: ");
    scanf("%d", &a);

    printf("Operador tern�rio:\n");
    a < 0 ? printf("\n\tValor negativo !\n") : printf("\n\tValor positivo ou igual a zero!");
    
    printf("\n\nif/else\n\n");
    if(a < 0)
        printf("\n\tValor negativo !\n");
    else{
        if(a > 0 )
            printf("\n\t Valor positivo!\n");
        else
            printf("\n\tValor igual a zero!\n");
    }
        
    printf("\n continua��o do programa ");

    
    
    
    /* operador tern�rio Condi��o ? verdadeiro : falso
    setlocale(LC_ALL, "");
    int a ;
    printf("\n Digite um valor qualquer: ");
    scanf("%d", &a);

    printf("Operador tern�rio:\n");
    a < 0 ? printf("\n\tValor negativo !\n") : printf("\n\tValor positivo ou igual a zero!");
    
    printf("\n\nif/else\n\n");
    if(a < 0)
        printf("\n\tValor negativo !\n");
    else
        printf("\n\tValor positivo ou igual a zero!");
    printf("\n continua��o do programa ");
    

    
    /*uso de chaves nas condcionais � necess�rio quando o 
    condicional executa mais de uma linha de codigo
    int a ;
    printf("\n Digite um valor qualquer: ");
    scanf("%d", &a);
    if(a < 0){
        printf("\n\tValor negativo !\n");
        printf("\n\tValor negativo !\n");
    }
    else{
        printf("\n\tValor positivo ou igual a zero!");
        printf("\n\t**Valor positivo ou igual a zero!");
    }
    printf("\n continua��o do programa ");

    /*
    setlocale(LC_ALL, "");
    int a ;
    printf("\n Digite um valor qualquer: ");
    scanf("%d", &a);

    printf("\nResultado logico: %d\n", a < 0);

    if(a < 0)
        printf("\n\tValor negativo !\n");
    else
        printf("\n\tValor positivo ou igual a zero!");
    printf("\n continua��o do programa ");
    aqui como o valor dentro do if � zero ele entende como reposta logica (0) como falso . 
    sendo asism ele pula direto para o bloco else
    no caso abaixo o valor if (0.1) por ser qualquer valor diferente de zero 
    o teste logico � positivo ele "roda" o if 
    if(0) 
        printf("\n\tValor negativo !\n");
    else
        printf("\n\tValor positivo ou igual a zero!");
    printf("\n continua��o do programa ");

    if(0.1)
        printf("\n\tValor negativo !\n");
    else
        printf("\n\tValor positivo ou igual a zero!");
    printf("\n continua��o do programa ");
    
    
    /*
    setlocale(LC_ALL, "");
    int a ;
    printf("\n Digite um valor qualquer: ");
    scanf("%d", &a);
    if(a < 0)
        printf("\n\tValor negativo !\n");
    else
        printf("\n\tValor positivo ou igual a zero!");
    printf("\n continua��o do programa ");
    
    
    
    setlocale(LC_ALL, "");
    int a ;
    printf("\n Digite um valor qualquer: ");
    scanf("%d", &a);
    if(a < 0)
        printf("\n\t Valor negativo !\n");
    printf("\n continua��o do programa ");


    
    // operadores relacionais menor que (a< b) = > 1
    //relacionais menor que (a > b)  = > 0
    // menor ou igual (a <= b)  = > 1
    // maior ou igual (a >= b) = > 0
    //igual (a == b) = > 0
    // diferente (a != b) = > 1
    int a=10 , b= 20;
    printf("z\n\t Resultado: %d\n\n", a < b);
    printf("z\n\t Resultado: %d\n\n", a > b);
    printf("z\n\t Resultado: %d\n\n", a <= b);
    printf("z\n\t Resultado: %d\n\n", a >= b);
    printf("z\n\t Resultado: %d\n\n", a == b);
    printf("z\n\t Resultado: %d\n\n", a != b);
    
     
   
    //7)Fa�a um programa para ler do teclado uma quantidade de segundos e imprimir na tela a
    //convers�o para horas, minutos e segundos.
    //Exemplo:
    //Entrada: 3672
    //Sa�da: 1:1:12
    // solu��o do professor 
    int segundos, h, m, s, resto;

    printf("Digite uma quantidade de segundos: ");
    scanf("%d", &segundos);
    
    h = segundos / 3600;
    resto = segundos % 3600;
    m = resto / 60;
    s = resto % 60;
    printf("%d:%d:%d\n", h, m, s);

    



     solu��o errda, meu codigo funciona o para exemplo de entrada o problema � na parte de segundos quanto foi inserido o numero exemplo 3762 ele ficou 1:2:102
    int segundos, horas, minutos, segundosf; 
    printf("Digite uma quantidade de segundo para o tempo ser convertido em horas , minutos e segundos: ");
    scanf("%d", &segundos);
    horas = (int)(segundos / 3600);
    minutos = (int)(segundos - 3600)/ 60 ; 
    segundosf  = ((segundos % 3600) - 60) -60);
    printf("%d:%d:%d",horas, minutos, segundosf);
    
    //6) Crie um programa em C que permita fazer a convers�o cambial entre Reais e D�lares. Considere
    //como taxa de c�mbio US$1,0 = R$5,30. Leia um valor em Reais e mostre o correspondente em
    //D�lares.
    setlocale(LC_ALL,"");

    float valor, valorD , taxaC = 5.30;
    printf("Qual o valor em Reais para convers�o cambial  : \n");
    scanf("%f", &valor);
    valorD = valor / taxaC;
    printf("\n O valor da convers�o de em reais: R$  %.2f \n taxa cambial: %f \n Valor em dolares: $ %.2f", valor, taxaC, valorD);

    
    //5) Uma empresa contrata um encanador a R$ 45,00 por dia. Fa�a um programa que solicite o
    //n�mero de dias trabalhados pelo encanador e imprima a quantia l�quida que dever� ser paga,
    //sabendo que s�o descontados 8% para imposto de renda.
    setlocale(LC_ALL, "");
    int dias;
    float bruto ,liquido, imposto;
    printf("Qual o valor total de dias trabalhados pelo encanador : \n");
    scanf("%d", &dias);
    bruto = dias * 45;
    imposto = bruto * 0.08;
    liquido = bruto - imposto;
    printf("O valor bruto do sal�rio do encanador � de R$ %.2f pelo %d dias trabalhados o liquido a receber ja com a dedu��o do imposto de  R$ %2.f e de R$ %.2f", bruto , dias, imposto, liquido);
    

    
    //4) Escreva um programa que leia um valor de despesa de restaurante, o valor da gorjeta (em
    //porcentagem) e o n�mero de pessoas para dividir a conta. Imprima o valor que cada um deve pagar.
    //Assuma que a conta ser� dividida igualmente.
    float conta, gorjeta, total, contafinal;
    int pessoas;
    printf("Qual o valor total da conta: \n");
    scanf("%f", &conta);
    printf("Qual o percentual da gorjeta(em %): \n");
    scanf("%f", &gorjeta);
    printf("Qual o numero de pessoas na mesa para dividir a conta:  \n");
    scanf("%d", &pessoas);
    total = conta + conta * (gorjeta/100);
    contafinal = total/pessoas;
    printf("o valor total da conta foi de R$ %f, divido o valor fica em R$ %.2f", total, contafinal); 


    
    //3) Fa�a um programa em C para trocar o valor de duas vari�veis inteiras sem utilizar nenhuma
    //vari�vel auxiliar.
    int a, b ;
    printf("Digite um numero inteiro: \n");
    scanf("%d", &a);
    
    printf("Digite outro numero inteiro: \n");
    scanf("%d", &b);
    
    printf("o valor de A: %d\n", a );
    printf("o valor de B: %d\n", b );
    
    
    a = a + b; 
    b = a - b; 
    a = a -b;
    printf("o valor de A: %d\n", a );
    printf("o valor de B: %d\n", b );
    

    2 - Elabore um algoritmo que receba, por meio do teclado, dois valores, um para a vari�vel �a� e um
    para a vari�vel �b�. Em seguida, fa�a os passos que julgar necess�rio para que ao final, a vari�vel
    �a� possua o valor que inicialmente estava em �b� e a vari�vel �b� possua o valor que inicialmente
    estava em �a�. Traduza seu algoritmo para a linguagem C e exiba os valores na tela.
    int a, b ,c;
    printf("Digite um numero inteiro: \n");
    scanf("%d", &a);
    
    printf("Digite outro numero inteiro: \n");
    scanf("%d", &b);
    
    printf("o valor de A: %d\n", a );
    printf("o valor de B: %d\n", b );
    c = a;
    a = b;
    b = c;  


    printf("o valor de A: %d\n", a );
    printf("o valor de B: %d\n", b );

    
    //1 - setlocale(LC_ALL,NULL ); padr�o da linguagem C
    //2 - setlocale(LC_ALL,""); padr�o do sistema operacional
    //3 - setlocale(LC_ALL, "Portuguese"); portugu�s brasileiro
    // para dar certo o codigo tive que mudar como � slavo o encoding de utf - 8 para windows 1252

    setlocale(LC_ALL, "");
    printf("cora��o\n");

     operador usigned ele so permite valores positivos
    possibilitando  que o numero chegue a 4.294.967.295
    no padr�o int o valor so vai de -2147483647 at� 2147483647
    para usar o short com unsigned tem que colocar %hu ou %d
    unsigned long int %lu

    unsigned short int y = 55000;
    unsigned int x = 2147483647;

    printf("\n\t %u \n\n", ++x);

    printf("\n\t %d \n\n", y);

*/
    return 0 ;
}
