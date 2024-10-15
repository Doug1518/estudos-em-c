#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    printf("Digite x e y: ");
    scanf("%d%d", &x, &y);
    if(x != 0 & y != 0)8

    printf("Digite x e y: ");
    scanf("%d%d", &x, &y);
    if(x != 0 && y != 0)

    /*26) Escreva um programa para ler as notas da primeira e da segunda avaliaÁ„o de um aluno. Calcule
    e imprima a mÈdia semestral. O programa dever· aceitar apenas notas v·lidas no intervalo [0,10].
    Cada nota deve ser validada separadamente. Ao final, deve ser impressa a mensagem ìnovo
    calculo? (1-sim 2-nao)î, solicitando ao usu·rio que informe um cÛdigo (1 ou 2), indicando se ele
    deseja ou n„o executar o programa novamente. Se for informado o cÛdigo 1, deve ser repetida a
    execuÁ„o de todo o programa para permitir um novo c·lculo, se for informado o cÛdigo 2 o
    programa deve ser encerrado.
      float n1, n2, media;
    int opcao;

    do{ // d· ao usu·rio a opÁ„o para calcular v·rias mÈdias
        do{ // valida primeira nota
            printf("Digite a primeira nota: ");
            scanf("%f", &n1);
        }while(n1 < 0 || n1 > 10);

        do{ // valida segunda nota
            printf("Digite a segunda nota: ");
            scanf("%f", &n2);
        }while(n2 <0 || n2 > 10);

        media = (n1 + n2) / 2;
        printf("Media: %.2f\n\n", media);

        printf("Novo calculo? (1-Sim 2-Nao)");
        scanf("%d", &opcao);
    }while(opcao != 2);

    return 0;
    /*25) Escreva um programa que leia dois valores X e Y. A seguir, mostre uma sequÍncia de 1 atÈ Y,
    passando para a prÛxima linha a cada X n˙meros.
    Exemplo de entrada:
    3 99
    Exemplo de saÌda:
    1 2 3
    4 5 6
    7 8 9
    10 11 12
    ...
    97 98 99*/
    int x, y, i;

    printf("Digite X e Y: ");
    scanf("%d%d", &x, &y);

    for(i = 1; i <= y; i++){
        printf("%3d ", i);
        if(i % x == 0)
            printf("\n");
    }

    return 0;
    /*24) VocÍ deve fazer um programa que apresente a sequÍncia conforme o exemplo abaixo.
    I=1 J=7
    I=1 J=6
    I=1 J=5
    I=3 J=9
    I=3 J=8
    I=3 J=7
    I=5 J=11
    I=5 J=10
    I=5 J=9
    ...
    I=9 J=15
    I=9 J=14
    I=9 J=13*/
    int i, j;

    for(i = 1; i <= 9; i += 2){
        for(j = 6 + i; j >= 4 + i; j--)
            printf("I = %d J = %d\n", i, j);
        printf("\n");
    }
    /*23) Escreva um programa que gere a saÌda abaixo.
    RestriÁıes:
    ? A instruÁ„o ìprintfî pode ser utilizada no m·ximo 2 vezes;
    ? O \n para saltar linha pode ser utilizado no m·ximo 2 vezes.
    *
    **
    ***
    ****
    *****
    ******
    *******
    *********/
    int i, j;

    for(j = 1; j <= 8; j++){
        for(i = 1; i <= j; i++)
            printf("*");
        printf("\n");
    }
    /*22) Chico tem 1,50 metro e cresce 2 centÌmetros por ano, enquanto ZÈ tem 1,10 metro e cresce 3
    centÌmetros por ano. Construa um programa que calcule e imprima quantos anos ser„o necess·rios
    para que ZÈ seja maior que Chico.*/
    float chico = 1.5, ze = 1.1;
    int ano = 0;

    while(chico >= ze){
        // incrementa a idade do Chico
        chico += 0.02;
        // incrementa a idade do Ze
        ze += 0.03;
        // conta mais um ano
        ano++;
        printf("Chico: %.2f\tZe: %.2f\tAno: %d\n", chico, ze, ano);
    }
    printf("Sao necessarios %d anos!\n\n", ano);
    /*21) Escreva um programa que gere a saÌda abaixo (10 linhas, 20 * por linha).
    RestriÁıes:
    ? A instruÁ„o ìprintfî pode ser utilizada no m·ximo 2 vezes;
    ? O \n para saltar linha pode ser utilizado no m·ximo 1 vez.
    ********************
    ********************
    ********************
    ********************
    ********************
    ********************
    ********************
    ********************
    ********************
    *********************/
     int i, j;

    for(j = 1; j <= 10; j++){ // 10 linhas
        for(i = 1; i <= 20; i++) // 20 colunas
            printf("*");
        printf("\n");
    }
    /*20) Uma rainha requisitou os serviÁos de um monge e disse-lhe que pagaria qualquer preÁo. O
    monge, necessitando de alimentos, indagou ‡ rainha sobre o pagamento, se poderia ser feito com
    gr„os de trigo dispostos em um tabuleiro de xadrez (que possui 64 casas), de tal forma que o
    primeiro quadro deveria conter apenas um gr„o e os quadros subsequentes, o dobro do quadro
    anterior. Crie um programa para calcular o total de gr„os de trigo que o monge recebeu.7*/
    int i;
    long double somatorio = 1, inicio = 1;

    for(i = 2; i <= 64; i++){
        inicio = inicio * 2;
        somatorio += inicio;
        printf("%d Valor: %Lf\n", i, inicio);
        __mingw_printf("%d Valor: %Lf\n", i, inicio);
    }
    printf("->Valor: %Lf\n", somatorio);
    __mingw_printf("->Valor: %Lf\n", somatorio);
    return 0;

    /*19) Escreva um programa para ler as coordenadas (X,Y) de uma quantidade indeterminada de
    pontos no sistema cartesiano. Para cada ponto escrever o quadrante a que ele pertence. O algoritmo
    ser· encerrado quando pelo menos uma de duas coordenadas for NULA (nesta situaÁ„o sem
    escrever mensagem alguma).
    Exemplo de entrada:
    2 2
    3 -2
    -8 -1
    -7 1
    0 2
    Exemplo de saÌda:
    primeiro
    quarto
    terceiro
    segundo*/
    int x, y;

    do{
        printf("Digite x e y: ");
        scanf("%d%d", &x, &y);
        if(x != 0 & y != 0){
            // primeiro quadrante
            if(x > 0 & y > 0)
                printf("Primeiro quadrante\n");
            else if(x < 0 & y > 0)
                printf("Segundo quadrante\n");
            else if(x < 0 & y < 0)
                printf("Terceiro quadrante\n");
            else
                printf("Quarto quadrante\n");
        }
    }while(x != 0 & y != 0);
    /*18) Foi feita uma pesquisa entre os habitantes de uma regi„o e foram coletados os dados de idade,
    sexo (M/F) e sal·rio de X pessoas (x deve ser informado pelo usu·rio). FaÁa um algoritmo que
    informe:
    a) a mÈdia de sal·rio do grupo;
    b) a maior e a menor idade do grupo;
    c) a quantidade de mulheres com sal·rio atÈ R$2000,00.*/
      int i, x, idade, menorIdade = 999, maiorIdade = 0, quantM = 0;
    char sexo;
    float salario, mediaSalario = 0;

    printf("Digite a quantidade de entrevistados: ");
    scanf("%d", &x);

    for(i = 1; i <= x; i++){
        printf("Digite sua idade, seu sexo e seu salario: ");
        scanf("%d %c%f", &idade, &sexo, &salario);

        // letra a
        mediaSalario += salario;

        // letra b
        if(menorIdade > idade)
            menorIdade = idade;
        if(maiorIdade < idade)
            maiorIdade = idade;

        // letra c
        if(sexo == 'F' && salario <= 2000)
            quantM++;
    }

    printf("Media salarial R$%.2f\n", mediaSalario / x);
    printf("Menor idade: %d\nMaior idade: %d\n", menorIdade, maiorIdade);
    printf("Quantidade de mulheres com salario ate R$2000,00: %d\n\n", quantM);

    /*17) FaÁa um programa que peÁa n˙meros ao usu·rio. Quando o usu·rio digitar o n˙mero 0 (zero) o
    programa deve imprimir na tela quantos n˙meros positivos e negativos foram digitados.
    Exemplo:*/
    int num, positivos = 0, negativos = 0;

    do{
        printf("Digite um valor: ");
        scanf("%d", &num);

        if(num > 0)
            positivos++;
        if(num < 0)
            negativos++;

    }while(num != 0);

    printf("Positivos: %d\nNegativos: %d\n\n", positivos, negativos);

    /*16) FaÁa um programa para encontrar o menor n˙mero inteiro que seja divisÌvel por todos os
    n˙meros inteiros entre 1 e 10.*/
    int i, divisores, valor = 8;

    do{
        divisores = 0;
        valor+= 2;
        for(i = 1; i <= 10; i++){
            if(valor % i == 0)
                divisores++;
        }
    }while(divisores != 10);

    printf("Valor: %d\n\n", valor);

    /*int main() {
    / 15) FaÁa um programa que peÁa ao usu·rio dois n˙meros inteiros e apresente o resultado na
    // multiplicaÁ„o entre os dois n˙meros sem utilizar a operaÁ„o de multiplicaÁ„o.
    // int i, a, b, r = 0;

    // printf("Digite dois valores: ");
    // scanf("%d%d", &a, &b);

    // for(i = 1; i <= a; i++)
    //     r += b;

    // printf("%d * %d = %d\n\n", a, b, r);
    
    //minha solucao

    //     setlocale(LC_ALL,"");
    //     int a, b, res = 0;
        
    //     // Recebendo os dois n˙meros
    //     printf("Digite o primeiro numero inteiro para multiplicaÁ„o: ");
    //     scanf("%d", &a);
    //     printf("Digite o segundo numero inteiro para multiplicaÁ„o: ");
    //     scanf("%d", &b);

    //     // MultiplicaÁ„o por somas sucessivas
    //     while (b > 0) {
    //         res += a;
    //         b--;
    //     }
        
    //     printf("O resultado da multiplicaÁ„o È: %d\n", res);
        
    //     return 0;
    // }

    // 15) FaÁa um programa que peÁa ao usu·rio dois n˙meros inteiros e apresente o resultado na
    // multiplicaÁ„o entre os dois n˙meros sem utilizar a operaÁ„o de multiplicaÁ„o.
    int a,b;
    printf("Digite o segundo numero inteiro multiplicaÁ„o:  ");
    scanf("%d", a);
    printf("Digite o segundo numero inteiro multiplicaÁ„o: ");
    scanf("%d", b);

    do{
        a+=a
        b--

    }while(b>1);
    
    printf("O resultado da multiplicaÁ„o entre os numeros ")
    /*
     int valor, i, divisores = 0, opcao;

    do{
        do{
            printf("Digite um valor maior que 1: ");
            scanf("%d", &valor);
        }while(valor < 2);

        printf("Divisores de %d: ", valor);
        for(i = 2; i <= valor/2; i++){
            if(valor % i == 0){
                printf("%d ", i);
                divisores++;
            }
        }
        printf("\n");

        if(divisores != 0)
            printf("%d nao e primo\n", valor);
        else
            printf("%d e primo\n", valor);
        printf("\n1 - Digitar outro valor\n2 - Sair\n");
        scanf("%d", &opcao);
    }while(opcao != 2);

    /*Faùa um programa que calcule a mùdia de salùrios de uma empresa, pedindo ao usuùrio a
    quantidade de funcionùrios e o salùrio de cada funcionùrio. Ao final, o programa deve imprimir a
    mùdia dos salùrios informados, o salùrio mais alto e o salùrio mais baixo
    resoluùùo do professsor
    int quantidade, i;
    float salario, totalSalarios = 0, salarioMaior = 0, salarioMenor = 99999;

    do{
        printf("Quantos funcionais a empresa possui? ");
        scanf("%d", &quantidade);
    }while(quantidade < 0);

    for(i = 1; i <= quantidade; i++){
        printf("%d salario: ", i);
        scanf("%f", &salario);

        totalSalarios += salario;
        if(salarioMenor > salario)
            salarioMenor = salario;
        if(salarioMaior < salario)
            salarioMaior = salario;
    }
    printf("Salario medio R$%.2f\n", totalSalarios/quantidade);
    printf("Maior salario R$%.2f\n", salarioMaior);
    printf("Menor salario R$%.2f\n\n", salarioMenor);

    minha resoluùùo
    setlocale(LC_ALL,"");
    int a,b = 0;
    float salario, totalS = 0 ,mediaS , maior = 0  , menor = 0;
    printf("Quantos funcionùrios tem sua empresa? \n ");
    scanf("%d", &a);
    do{
        printf("Qual o salùrio dos funcionùrios? ");
        scanf("%f", &salario);
        totalS += salario;
        if(b==0){
            menor = salario;
            maior = salario;
        }
        else{
            if(menor > salario){
                menor = salario;
            }
            if (maior < salario){
                maior = salario;
            }
        }
        b++;
    }while(a > b);
    mediaS = totalS/a;


    printf("O maior salùrio e %f\n o menor salùrio ù %f", maior, menor);
    printf("\nO numero de funcionarios em sua empresa e de  %d e a mùdia salùrial ù de: %.2f", a, mediaS);
    //vùrios codigos testados para definir se um numero ù primo ou nùo
    // setlocale(LC_ALL, "");
    // int valor, i, divisores, opcao;

    // do {
    //     do {
    //         printf("Digite um numero maior que 1: ");
    //         scanf("%d", &valor);
    //     } while (valor < 2);

    //     // Resetar a contagem de divisores
    //     divisores = 0;

    //     printf("Divisores de %d: ", valor);
    //     // Inicia a verificaùùo de divisores a partir de 1
    //     for (i = 1; i <= valor / 2; i++) {
    //         if (valor % i == 0) {
    //             printf("%d ", i);
    //             divisores++;
    //         }
    //     }
    //     printf("%d ", valor); // O prùprio nùmero tambùm ù um divisor
    //     divisores++; // Contar o nùmero como divisor

    //     printf("\n");
    //     if (divisores > 2) // Considera 1 e o prùprio nùmero como divisores
    //         printf("%d nùo ù primo\n", valor);
    //     else
    //         printf("%d ù primo\n", valor);

    //     printf("\n1 - Digitar outro valor\n2 - Sair\n");
    //     scanf("%d", &opcao);
    // } while (opcao != 2);
    // setlocale(LC_ALL, "");
    // int valor ,i , divisores = 0, opcao;
    // do{
    //     do{
    //         printf("Digite um numero maior que 1: ");
    //         scanf("%d", &valor);
    //     }while (valor < 2 );

    //     printf("Divisores de %d: ", valor);
    //     for (i= 2; i <=valor/2; i++){
    //         if(valor % i ==0){
    //             printf("%d ", i);
    //             divisores++;
    //         }

    //     }
    //     printf("\n");
    //     if(divisores > 0)
    //         printf("%d nùo e primo\n", valor);
    //     else
    //         printf("%d ù primo\n", valor);
    //     printf("\n1 - Digitar outro valor\n2 - Sair\n");
    //     scanf("%d", &opcao);
    // }while(opcao != 2);
    // int valor, i, divisores = 0, opcao;

    // do{
    //     do{
    //         printf("Digite um valor maior que 1: ");
    //         scanf("%d", &valor);
    //     }while(valor < 2);

    //     printf("Divisores de %d: ", valor);
    //     for(i = 2; i <= valor/2; i++){
    //         if(valor % i == 0){
    //             printf("%d ", i);
    //             divisores++;
    //         }
    //     }
    //     printf("\n");

    //     if(divisores != 0)
    //         printf("%d nao e primo\n", valor);
    //     else
    //         printf("%d e primo\n", valor);
    //     printf("\n1 - Digitar outro valor\n2 - Sair\n");
    //     scanf("%d", &opcao);
    // }while(opcao != 2);


    /*13) Faùa um programa que peùa ao usuùrio um nùmero inteiro maior que 2 e diga se o nùmero
    informado ù primo ou nùo.*/
    // setlocale(LC_ALL,"");
    // int a;
    // int i, primo = 1; // Variùvel para indicar se o nùmero ù primo

    // do {
    //     printf("Digite um numero inteiro maior que 2: ");
    //     scanf("%d", &a);
    // } while (a <= 2);

    // // Verifica se o nùmero ù primo
    // for (i = 2; i * i <= a; i++) { // Verifica atù a raiz quadrada de a
    //     if (a % i == 0) {
    //         primo = 0; // Nùo ù primo se encontrar um divisor
    //         break; // Sai do loop
    //     }
    // }

    // // Exibe o resultado
    // if (primo)
    //     printf("O numero %d ù primo\n", a);
    // else
    //     printf("O numero %d nùo ù primo\n", a);


    /*12) Para uma turma de 45 alunos, construa um algoritmo que determine:
    a) A idade mùdia dos alunos com menos de 1,70m de altura;
    b) A altura mùdia dos alunos com mais de 20 anos.
    res do professor

    int main() {
        int i, idade, idadeBaixinhos = 0, quantIdadeBaix = 0, quantAlturaMaior20 = 0;
        float idadeMedia, alturaMedia, altura, alturaMais20 = 0;

        for(i = 1; i <= 45; i++){
            printf("Digite sua idade e sua altura em metros: ");
            scanf("%d%f", &idade, &altura);

            // soluùùo da letra a
            if(altura < 1.7){
                idadeBaixinhos += idade;
                quantIdadeBaix++;
            }

            // soluùùo da letra b
            if(idade > 20){
                alturaMais20 += altura;
                quantAlturaMaior20++;
            }
        }
        idadeMedia = (float)idadeBaixinhos / quantIdadeBaix;
        alturaMedia = alturaMais20 / quantAlturaMaior20;
        printf("Idade media dos alunos com menos de 1,70m de altura: %.2f\n", idadeMedia);
        printf("Altura media dos alunos com mais de 20 anos: %.2f\n", alturaMedia);
    }


    res do chat com alguns ajustes
    #include <stdio.h>
    #include <locale.h>

    int main() {
        setlocale(LC_ALL,"");

        int idade, i;
        int alunoIdade170 = 0; // contador de alunos com menos de 1,70m de altura
        int alturaMaiores20 = 0; // contador de alunos com mais de 20 anos
        float altura, alturaT = 0, idadeT = 0, alturaM, idadeM;

        for (i = 1; i <= 45; i++) {
            printf("Digite sua idade: ");
            scanf("%d", &idade);
            printf("Digite sua altura (em metros): ");
            scanf("%f", &altura);

            if (altura < 1.70) {
                alunoIdade170++;
                idadeT += idade; // soma a idade dos alunos com menos de 1,70m
            }

            if (idade > 20) {
                alturaMaiores20++;
                alturaT += altura; // soma a altura dos alunos com mais de 20 anos
            }
        }

        // Calculando as mùdias
        idadeM = (alunoIdade170 > 0) ? (idadeT / alunoIdade170) : 0; // mùdia de idade
        alturaM = (alturaMaiores20 > 0) ? (alturaT / alturaMaiores20) : 0; // mùdia de altura

        printf("\nA idade mùdia dos alunos com menos de 1,70m ù: %.2f e totaliza %d alunos", idadeM, alunoIdade170);
        printf("\nA altura mùdia dos alunos com mais de 20 anos ù: %.2f e totaliza %d alunos\n", alturaM, alturaMaiores20);

        return 0;
    }

    minha res
    int idade, i, alunoIdade170 = 0, alturaMaiores20 = 0;// aluno idade sera o contador de alunos com menos de 1,70m de altura e alturamenores sera contador de alunos com mais de 20 anos
    float altura, alturaT = 0, idadeT = 0, alturaM , idadeM;

    for (i = 1; i <= 45; i++){
        printf("Digite sua idade: ");
        scanf("%d", &idade);
        printf("Digite sua altura : ");
        scanf("%f", &altura);
        if (altura <1.70){
            alunoIdade170 ++;
            idadeT +=idade;

        }
        if(idade > 20){
            alturaMaiores20++;
            alturaT += altura;

        }
    }

    idadeM = idadeT/alunoIdade170;
    alturaM = alturaT/ alturaMaiores20;

    printf("\nA Altura idade mùdia de alunos com menos de 1,70 ù : %.2f e totaliza %d alunos", idadeM, alunoIdade170);
    printf("\nA altura mùdia dos alunos com mais de 20 anos : %.2f e totaliza %d", alturaM, alturaMaiores20);

    /*11) Um determinado material radioativo perde metade de sua massa a cada 50 segundos. Dada a
    massa inicial, em gramas, faùa um programa que determine o tempo necessùrio para que essa massa
    se torne menor que 0,05 gramas.*/
    // res do professor

    // float massa;
    // int tempo = 0;

    // printf("Digite a massa do material em gramas: ");
    // scanf("%f", &massa);

    // while(massa >= 0.05){
    //     massa = massa / 2;
    //     tempo += 50;
    // }

    // printf("Massa final: %f\n", massa);
    // printf("O tempo decorrido foi de %d segundos.\n\n", tempo);

    // minha res
    // setlocale(LC_ALL,"");
    // float peso, tempo;
    // printf("Digite o peso do material: ");
    // scanf("%f", &peso);

    // while(peso >= 0.05){
    //     peso /= 2;
    //     tempo += 50;
    // }

    // printf("O tempo para o material ter massa menor que 0,05 gramas ù de %.2f segundos\n", tempo);



    /*10) Vocù decidiu ficar rico guardando dinheiro por 30 dias consecutivos. Para tal, decidiu guardar 1
    centavo no primeiro dia, 2 centavos no segundo dia, 4 centavos no terceiro dia, 8 centavos no quarto
    dia, e assim por diante. Faùa um programa para calcular quanto vocù terù ao final dos 30 dias*/
    // int i, valorInicial = 1, valorFinal = 1;

    // for(i = 1; i <= 29; i++){
    //     valorInicial = valorInicial * 2;
    //     valorFinal += valorInicial;
    // }

    // printf("Valor em centavos: %d\n", valorFinal);
    // printf("R$%.2f\n\n", valorFinal / 100.0);


    // setlocale(LC_ALL,"");
    //  setlocale(LC_ALL,"");
    // int a, n = 30;
    // float deposito = 1, s = 0;
    // for(a = 1; a <= n; a++){
    //     s += deposito;
    //     deposito *= 2;
    // }

    // Exibe o total acumulado em reais
    //printf("O total guardado ao final de %d dias ù: %.2f reais\n", n, s / 100.0);

    /*9) Faùa um programa que calcule o valor de A, dado por:
    A = 1 + 2 + 3 + 4 + ù + n, onde n ù um nùmero inteiro, maior que zero informado pelo usuùrio.*/
    // solucao do professor
    // int i, n, A = 0;

    // do{
    //     printf("Digite o valor de n: ");
    //     scanf("%d", &n);
    // }while(n < 1);

    // for(i = 1; i <= n; i++)
    //     A = A + i;

    // printf("Soma de 1 ate %d: %d\n\n", n, A);
    // minha solucao
    // setlocale(LC_ALL,"");
    // int a, n, soma= 0;
    // printf("digite um numero inteiro: ");
    // scanf("%d", &n);

    // for (a =1;a <=n; a++)
    //     soma +=a;

    // printf("A soma de todos os numero de A = 1 atù N= %d e : %d", n, soma );

    /*8) Escreva um programa em C que funcione como uma calculadora. O programa deve apresentar
    um menu ao usuùrio da seguinte forma:
    1 ù Somar
    2 ù Subtrair
    3 ù Multiplicar
    4 ù Dividir
    0 ù Sair
    Uma estrutura do tipo switch deve ser utilizada para realizar cada operaùùo em um case. Apùs a
    escolha da operaùùo, dois valores devem ser pedidos ao usuùrio para realizar a operaùùo escolhida.
    Se a operaùùo escolhida for a 4 o dividendo nùo pode ser zero, um novo valor deve ser solicitado. O
    programa deve funcionar atù que o usuùrio escolha a opùùo 0 (opùùo de saùda).*/
    //codigo do professor
//     int opcao, num1, num2;

//     do {
//         printf("\n1 - Soma\n2 - Subtracao\n3 - Multiplicacao\n4 - Divisao\n0 - Sair\n\n");
//         scanf("%d", &opcao);

//         if(opcao > 0 && opcao < 5){
//             printf("Digite dois valores: ");
//             scanf("%d%d",&num1, &num2);
//         }

//         switch(opcao) {
//         case 0:
//             printf("Saindo...\n");
//             break;
//         case 1:
//             printf("Soma: %d\n", num1 + num2);
//             break;
//         case 2:
//             printf("Subtracao: %d\n", num1 - num2);
//             break;
//         case 3:
//             printf("Multiplicacao: %d\n", num1 * num2);
//             break;
//         case 4:
//             while(num2 == 0) {
//                 printf("Nao existe divisao por zero!\nDigite outro valor: ");
//                 scanf("%d", &num2);
//             }
//             printf("Divisao: %d\n", num1 / num2);
//             break;
//         default:
//             printf("Opcao invùlida.\nDigite outra opcao: ");
//         }
//     } while(opcao != 0);
// }


    // codigo ajustado com ajuda do chat, ele basicamente colocou o codigo dentro ja do do while e colocou uma condicional para caso a opùùo seja igual a 0
    // setlocale(LC_ALL,"");
    // int opcao;
    // float num1, num2, res;

    // do {
    //     printf("\nBEM VINDO ù CALCULADORA EM C!!!");
    //     printf("\nEscolha uma opùùo: ");
    //     printf("\n1 ù Somar\n2 ù Subtrair\n3 ù Multiplicar\n4 ù Dividir\n0 ù Sair\n");
    //     scanf("%d", &opcao);

    //     if (opcao == 0) {
    //         printf("\nSaindo do programa...");
    //         break;
    //     }

    //     printf("Digite o primeiro nùmero da operaùùo: ");
    //     scanf("%f", &num1);
    //     printf("Digite o segundo nùmero da operaùùo: ");
    //     scanf("%f", &num2);

    //     switch (opcao) {
    //         case 1:
    //             res = num1 + num2;
    //             printf("\nA soma de %.2f + %.2f ù: %.2f", num1, num2, res);
    //             break;
    //         case 2:
    //             res = num1 - num2;
    //             printf("\nA subtraùùo de %.2f - %.2f ù: %.2f", num1, num2, res);
    //             break;
    //         case 3:
    //             res = num1 * num2;
    //             printf("\nA multiplicaùùo de %.2f * %.2f ù: %.2f", num1, num2, res);
    //             break;
    //         case 4:
    //             while (num2 == 0) {
    //                 printf("Divisùo por zero nùo ù permitida. Digite um nùmero diferente de zero: ");
    //                 scanf("%f", &num2);
    //             }
    //             res = num1 / num2;
    //             printf("\nA divisùo de %.2f / %.2f ù: %.2f", num1, num2, res);
    //             break;
    //         default:
    //             printf("\nOpùùo invùlida");
    //             break;
    //     }
    // } while (opcao != 0);




// meu coigo quase pronto porùm quebrado
//     setlocale(LC_ALL,"");
//     int opcao;
//     float num1, num2, res;
//     printf("\nBEM VINDO A CALCULADORORA EM C !!!");
//     printf("\nEscolha uma opùùo : ");
//     printf("\n1 ù Somar\n2 ù Subtrair\n3 ù Multiplicar\n4 ù Dividir\n0 ù Sair\n");
//     scanf("%d", &opcao);
//     printf("Digite o primeiro numero da operaùùo: ");
//     scanf("%f", &num1);
//     printf("Digite o segundo numero da operaùùo: ");
//     scanf("%f", &num2);

//     do {

//     switch (opcao)
//     {
//     case 1:
//         res = num1 + num2;
//         printf("\nA soma  %.2f + %.2f: %.2f", num1, num2, res);
//         break;
//     case 2:
//         res = num1 - num2;
//         printf("\nA Subtraùùo  %.2f - %.2f: %.2f", num1, num2, res);
//         break;
//     case 3:
//         res = num1 * num2;
//         printf("\nA multiplicaùùo  %.2f * %.2f: %.2f", num1, num2, res);
//         break;
//     case 4:
//         do{
//             printf("Digite o segundo numero da operaùùo (ele tem que ser diferente de zero para divisùo funcionar) : ");
//             scanf("%f", &num2);
//         }while(num2 == 0);
//         res = num1 / num2;
//         printf("\nA divisùo  %.2f / %.2f: %.2f", num1, num2, res);
//         break;
//     case 0:
//         printf("\nSaindo do programa...")  ;
//         break;

//     default:
//         printf("\nopùùo invùlida");
//         break;
//    }
//     printf("\nCaso ja tenha acabado digite zero");
//     printf("\n1 ù Somar\n2 ù Subtrair\n3 ù Multiplicar\n4 ù Dividir\n0 ù Sair\n");
//     scanf("%d", &opcao);
//     printf("Digite o primeiro numero da operaùùo: ");
//     scanf("%f", &num1);
//     printf("Digite o segundo numero da operaùùo: ");
//     scanf("%f", &num2);

//     }while(opcao != 0);




    /*7) Leia um valor inteiro N. Apresente o quadrado de cada um dos valores pares, de 1 atù N,
    inclusive N, se for o caso.
    //soluùùo do professor

    int i, n;

    printf("Digite um valor inteiro: ");
    scanf("%d", &n);

    for(i = 2; i <= n; i+= 2)
        printf("%d ", i * i);
    printf("\n\n");


    // minha soluùùo
    int a, n;

    printf("Digite um numero inteiro: ");
    scanf("%d", &n);

    for (a = 1; a <= n ; a++)
        if(a % 2 == 0)
             printf("\n%d ^2 : %d", a, a*a);


    /*6) Faùa um programa que imprima na tela todos os mùltiplos de 7 entre 1 e 9999.*/
    // soluùùo do professor
    // int i;

    // for(i = 7; i <= 9999; i+=7)
    //     printf("%4d ", i);

    // return 0;



    // minha soluùùo
    // int a;
    // for (a = 1 ;a <= 9999; a++){
    //     if (a % 7 == 0)
    //         printf("%d ", a);
    // }


    // 5) Faùa um programa que leia as notas referentes ùs duas avaliaùùes de um aluno. Calcule e
    // imprima a mùdia semestral. Faùa com que o programa sù aceite notas vùlidas (uma nota vùlida deve
    // pertencer entre o intervalo de 0 a 10). Cada nota deve ser validada separadamente.
//     solucao do professor
//     float nota1, nota2, media;

//     do{
//         printf("Digite a primeira nota: ");
//         scanf("%f", &nota1);
//     }while(nota1 < 0 || nota1 > 10);

//     do{
//         printf("Digite a segunda nota: ");
//         scanf("%f", &nota2);
//     }while(nota2 < 0 || nota2 > 10);

//     media = (nota1 + nota2) / 2;

//     printf("Nota final: %.2f\n", media);
// }

//     minha soluùùo
//     setlocale(LC_ALL, "");
//     float nota1 , nota2, media;
//     printf("digite sua primeira nota (1 atù 10): ");
//     scanf("%f", &nota1);
//     while( nota1 <0 || nota1 > 10 ){
//         printf("digite sua primeira nota (1 atù 10): ");
//         scanf("%f", &nota1);
//     }
//     printf("digite sua segunda nota (1 atù 10): ");
//     scanf("%f", &nota2);
//     while( nota2 < 0  || nota2 > 10 ){
//         printf("digite sua segunda nota (1 atù 10): ");
//         scanf("%f", &nota2);
//     }
//     media = (nota1 + nota2) /2;

//     printf("A media semestral ù igual : %.2f" , media);

    /*Faùa um programa que some os nùmeros ùmpares entre 1 e 1000 e imprima a resposta
    soluùùo do professor
    soluùùo um do professor

    int i, soma = 0;

    for(i =1; i <= 1000; i+=2)// 500
        soma += i; // soma = soma + i -> 500

    printf("Soma dos impares de 1 a 1000: %d\n\n", soma);

    soluùùo um  do professor
    // int i, soma = 0;

    // for(i =1; i <= 1000; i++)// 1000
    //     if(i % 2 == 1) // 1000
    //         soma += i; // soma = soma + i -> 500

    // printf("Soma dos impares de 1 a 1000: %d\n\n", soma);


    // minha soluùùo
    // int a, soma = 0;

    // for (a = 1 ; a <=1000 ; a +=2){
    //     soma += a;
    // }
    //  printf("A soma de todos os numeros impares entre 1 e 1000 ù : %d", soma);



    /*2) Escreva um programa que repita a leitura de uma senha atù que ela seja vùlida. Para cada leitura
    de senha incorreta informada, escrever a mensagem ùSenha Invalidaù. Quando a senha for
    informada corretamente deve ser impressa a mensagem ùAcesso Permitidoù e o programa deve ser
    encerrado. Considere que a senha correta ù o valor 123456.
    do professor
    int main() {
    int senha, senhaValida = 123456;

    printf("Digite sua senha: ");
    scanf("%d", &senha);

    while(senha != senhaValida){
        printf("Senha invalida!\n\nDigite sua senha: ");
        scanf("%d", &senha);
    }

    printf("Acesso permitido!\n");
}

    Minha soluùùes
    int senha = 123456, senhaU;

    printf("Digite a senha: ");
    scanf("%d", &senhaU); // Leitura inicial da senha

    while (senhaU != senha) {
        printf("Senha invùlida\n");
        printf("Digite a senha: ");
        scanf("%d", &senhaU);
    }

    printf("Acesso permitido\n");



    // int senha = 123456, senhaU;

    // do{
    //     printf("digite a senha: ");
    //     scanf("%d", &senhaU);
    //     if (senhaU != senha){
    //         printf("Senha invalida\n");
    //     }
    // }while(senhaU!= senha);
    // printf("acesso permitido");

    /*1) Elabore um programa em C para ler do teclado um valor inteiro entre 1 e 10 e apresentar a
    tabuada. Exemplo:
    Entrada 7
    Saùda:
    7 * 1 = 7
    7 * 2 = 14
    7 * 3 = 21
    7 * 4 = 28
    7 * 5 = 35
    7 * 6 = 42
    7 * 7 = 49
    7 * 8 = 56
    7 * 9 = 63
    7 * 10 = 70
    soluùùo do professor

    int i, num;

    do{
        printf("Digite um valor entre 1 e 10: ");
        scanf("%d", &num);
    }while(num < 1 || num > 10);

    for(i = 1; i <= 10; i++)
        printf("%d * %d = %d\n", num, i, num * i);



    // minha soluùùo foi feito diferente , pois nùo cheguei a ler que o numero tinha que ser entre 1 e 10
    // int i , n;
    // printf("Digite um numero interno: ");
    // scanf("%d", &i);

    // for(n = 1; n <=10;n++){
    //     printf("\n %d * %d = %d",i,n,i*n);
    // }
    /* direnùas entre for, while, do{}while
    int i;
    do{
        printf("Digite um valor maior que zero: ");
        scanf("%d", &i);
    }while(i <= 0 );

    printf("Valor lido: %d\n", i);

    // printf("\nGerado com for: ");
    // for(i = 0; i <= 10; i++)
    //     printf("%d ", i);

    // i = 0;

    // printf("\n\nGerado com while: ");
    // while(i <= 10){
    //     printf("%d ", i++); // observe o incremento da variùvel i
    // }


    /*estrutura de reptiùùo do()while
    int valor, valor2;
    printf("Digite um valor maior que zero: ");
    scanf("%d", &valor);

    while(valor <=0){
        printf("Valor invalido digute valor maior que zero: ");
        scanf("%d", &valor);
    }

    printf("Valor lido: %d\n", valor);

    do{
        printf("Digite um valor maior que zero: ");
        scanf("%d", &valor2);
    }while(valor2 <= 0 );
    printf("Valor lido: %d\n", valor2);

    /*estrutura de repetiùùo while
    int valor;
    printf("Digite um valor maior que zero: ");
    scanf("%d", &valor);
    while(valor <=0){
        printf("Valor invalido digute valor maior que zero: ");
        scanf("%d", &valor);
    }
    printf("Valor lido: %d\n", valor);
    /*
    int i;
    for(i = 1; i <=100; i++)
        if(i % 2!= 0)
            printf("%d", i);
    printf("\nSegunda maneira mais eficiente\n");
    for(i = 1; i <=100; i+=2)
        printf("%d", i);
    /*
    int i = 10;
    for(i = 10; i >= 0 ;i--){
        printf("\n%d ",i);

    }

    /* estrutura de repetiùùo for , for (codiùùo de inicio; condiùùo de fara; incremento)
    int i = 0;
    for(i = 0; i <=10 ;i++){
        printf("\n%d ",i);
    }
    */
    return 0;
}
