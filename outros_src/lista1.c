#include <stdio.h>
#include <string.h>
#include <math.h> 
#include <locale.h>
/* 
Nota: Ao adicionar a lib padrão de matemática (libm/math.h), é necessário usar o comando -lm na hora da compilação 
Dessa forma: gcc lista1.c -o output/lista1.out -lm  && ./output/lista1.out
*/
#include <stdlib.h> // Lib da função srand() e rand(), mas é necessário a de baixo p/ gerar uma seed diferente com srand() para evitar números falso-aleatórios
#include <time.h> // Função time(). Gera um valor específico com base na hora atual

// P/ COMPILAR: gcc lista1.c -o output/lista1.out -lm  
// P/ EXECUTAR: ./output/lista1.out

// Headers
void exercicio1();
void exercicio2();
void exercicio3();
void exercicio4();
void exercicio5();
void exercicio6();
void exercicio7();
void exercicio8();
void exercicio9();
void exercicio10();
void exercicio11();
void exercicio12();

int main() {
    setlocale(LC_ALL, "portuguese");
    exercicio1();
    exercicio2();
    exercicio3();
    exercicio4();
    exercicio5();
    exercicio6();
    exercicio7();
    exercicio8();
    exercicio9();
    exercicio10();
    exercicio11();
    exercicio12();

    return 0;
}

void exercicio1() {
/*
    Peça ao usuário para digitar seu nome e idade e, em seguida, imprima uma
    mensagem formatada com esses dados.
*/
    char nome[50];
    int idade;

    printf("Digite seu nome: ");

    // Usando fgets(...) ao invés de scanf("%s", nome) para conseguir pegar nomes compostos
    fgets(nome, sizeof(nome), stdin);
    // Trocando caracter de quebra de linha pelo terminador de string 
    nome[strcspn(nome, "\n")] = '\0';

    /* Uma outra forma de fazer poderia ser com getchar():
        int c;
        int i = 0;
        while ((c = getchar()) != '\n' && c != EOF) {
        if (i < sizeof(nome) - 1) {
            nome[i++] = c;
        }
    }

    nome[i] = '\0'; // Adicione o terminador de string
    */

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Olá, %s! Você tem %d anos.\n", nome, idade);
    printf("\n\n");
}

void exercicio2() {
/*
    Crie um programa que converta uma temperatura em graus Celsius para Fahrenheit.
    Peça ao usuário para inserir a temperatura em Celsius e imprima a temperatura
    equivalente em Fahrenheit.
*/
    float temperaturaCelsius, temperaturaFahrenheit;

    printf("Digite a temperatura em Celsius: ");
    scanf("%f", &temperaturaCelsius);

    temperaturaFahrenheit = (temperaturaCelsius * 9 / 5) + 32;

    printf("%.2f graus Celsius são equivalentes a %.2f graus Fahrenheit.\n", temperaturaCelsius, temperaturaFahrenheit);
    printf("\n\n");
}

void exercicio3() {
/*
    Escreva um programa que calcule e imprima a área de um triângulo. 
    Peça ao usuário para inserir a base e a altura do triângulo.
*/
    float base, altura, area;

    printf("Digite a base do triângulo: ");
    scanf("%f", &base);

    printf("Digite a altura do triângulo: ");
    scanf("%f", &altura);

    area = (base * altura) / 2;

    printf("A área do triângulo é %.2f unidades de área.\n", area);
    printf("\n\n");
}

void exercicio4() {
    // Crie um programa que leia um número inteiro e imprima seu quadrado e cubo.
    int ex4_num;

    printf("Digite um número inteiro: ");
    scanf("%d", &ex4_num);

    // Forma1
    //quadrado = ex4_num * ex4_num;
    //cubo = ex4_num * ex4_num * ex4_num;

    // Forma2 - Usando libm
    double quadrado = pow(ex4_num, 2);
    double cubo = pow(ex4_num, 3);

    // Adicionar .0 faz sumir as casas decimais na hora de imprimir
    printf("\nO quadrado do número %d é %.0lf e seu cubo é %.0lf.\n", ex4_num, quadrado, cubo);
    printf("\n\n");
}

void exercicio5() {
    // Escreva um programa que determine se um número digitado pelo usuário é par ou ímpar.
    int ex5_num;
    
    printf("Digite um número inteiro: ");
    scanf("%d", &ex5_num);

    if (ex5_num % 2 == 0) {
        printf("%d é um número par.\n", ex5_num);
    } else {
        printf("%d é um número ímpar.\n", ex5_num);
    }
    printf("\n\n");
}

void exercicio6() {
    // Crie um programa que determine se um ano fornecido pelo usuário é bissexto ou não.
    int ano;
    
    printf("Digite um ano: ");
    scanf("%d", &ano);

    /* 
    De acordo com o calendário gregoriano, um ano bissexto é aquele que é divisível por 4, 
    mas não é divisível por 100, a menos que também seja divisível por 400. 
    */
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        printf("%d é um ano bissexto.\n", ano);
    } else {
        printf("%d não é um ano bissexto.\n", ano);
    }
    printf("\n\n");
}

void exercicio7() {
/*  Faça um programa que peça a nota de um aluno em uma prova e verifique se ele foi 
    aprovado (nota maior ou igual a 6) ou reprovado (nota menor que 6) */
    short nota;

    printf("Digite a nota do aluno (0-10): \n");
    scanf("%hd", &nota);

    /*  Provando que a condicional if (!(nota < 0 || nota > 10)) funciona:
        SE nota = 6
        nota < 0 ? false
        nota > 10 ? false
        false || false = false
        !false = true

        SE nota = -1
        nota < 0 ? true
        nota > 10 ? false
        true || false = true
        !true = false

        SE nota = 11
        nota < 0 ? false
        nota > 10 ? true
        false || true = true
        !true = false
    */

    // Outra forma de fazer sem a negação:  if (nota >= 0 && nota <= 10)

    if (!(nota < 0 || nota > 10)) {
        if (nota >= 6) {
            printf("O aluno está aprovado.\n");
        }
        else {
            printf("O aluno está reprovado.\n");
        }
    }
    else {
        printf("A nota é inválida.\n");
    }
    printf("\n\n");
}

void exercicio8() {
/*  Escreva um programa que classifique um dado número inteiro como positivo,
    negativo ou zero. */
    int ex8_num;

    printf("Digite um número inteiro qualquer: \n");
    scanf("%d", &ex8_num);

    if (ex8_num > 0) {
        printf("O número digitado é positivo.\n");
    } 
    else if (ex8_num < 0) {
        printf("O número digitado é negativo.\n");
    }
    else {
        printf("O número digitado é zero.\n");
    }
    printf("\n\n");
}

void exercicio9() {
/*  Crie um programa que imprima a tabuada de multiplicação de um número fornecido pelo usuário. */
    int ex9_num, resultado;
    int flag = 1;

    while (flag == 1) {
        printf("Digite um número qualquer para ver a tabuada (ou -1 para cancelar): ");
        scanf("%d", &ex9_num);
        if (ex9_num == -1) {
            printf("Programa encerrado!\n");
            flag = 0;
        }
        else {
            printf("\nTabuada do número %d:\n", ex9_num);
            for (int i = 0; i < 11; i++) {
                resultado = ex9_num * i;
                printf("%d x %d = %d\n", ex9_num, i, resultado);
            }
        }
    }
    printf("\n\n");
}

void exercicio10() {
/*  Escreva um programa que calcule e imprima o fatorial de um número inteiro positivo
    dado pelo usuário. */
    int ex10_num;
    int fatorial = 1;
    int limite = 12; // Limite definido para inteiros de 32 bits

    printf("Digite um número inteiro positivo (limite %d): ", limite);
    scanf("%d", &ex10_num);

    if (ex10_num < 0) {
        printf("O fatorial não está definido para números negativos.\n");
    } else if (ex10_num > limite) {
        printf("Número muito grande para calcular o fatorial com inteiros de 32 bits.\n");
    } else {
        for (int i = 1; i <= ex10_num; i++) {
            fatorial *= i;
        }

        printf("O fatorial de %d é %d.\n", ex10_num, fatorial);
    }
    printf("\n\n");
    /*
        Devido a natureza dos fatoriais, é possível que o tipo int não seja capaz de abarcar valores maiores.
        Portanto, talvez o melhor seria ter usado um unsigned long long para o tipo do fatorial.
    */
}

void exercicio11() {
/*  Implemente um programa que peça ao usuário para adivinhar um número inteiro
    secreto entre 1 e 100. Forneça dicas de "maior" ou "menor" até que o usuário acerte. */
    int tentativas;
    int ex11_num;
    srand(time(NULL)); // Gera uma seed diferente toda vez para escolher números aleatórios
    int sorteio = rand() % 51; // Gera um número de 0 a 50 (se fizesse % 50 só iria gerar de 0 a 49)

    printf("Bem-vindo(a) ao jogo de adivinhação!\n");
    printf("Digite o número de tentativas:\n");
    scanf("%d", &tentativas);
    printf("Tente adivinhar o número sorteado pelo programa.\n");

    while (tentativas > 0) {

        printf("\nChute um número (0 a 50):\n");
        scanf("%d", &ex11_num);

        if (ex11_num == sorteio) {
            printf("\nVocê acertou! O número era: %d\n\n", sorteio);
            printf("Tentativas restantes: %d", tentativas);
            tentativas = -1;
        }
        else {
            if (ex11_num > sorteio) {
                printf("O número sorteado é menor.\n");
                tentativas--;
            }
            else {
                printf("O número sorteado é maior.\n");
                tentativas--;
            }
        }
    }

    if (tentativas == 0) {
        printf("\nVocê perdeu... O número era: %d\n", sorteio);        
    } 

    printf("\n\n");
}

void exercicio12() {
/*  Faça um programa que exiba a sequência de Fibonacci até um número específico
    fornecido pelo usuário. A sequência começa com 0 e 1, e cada termo subsequente é
    a soma dos dois anteriores. */
    int ex12_num, primeiro = 0, segundo = 1, proximo;

    printf("Digite um número para limitar a sequência de Fibonacci: ");
    scanf("%d", &ex12_num);

    printf("Sequência de Fibonacci até %d:\n", ex12_num);

    // Primeiro e segundo termos já conhecidos
    printf("%d, %d, ", primeiro, segundo);

    proximo = primeiro + segundo;

    while (proximo <= ex12_num) {
        printf("%d, ", proximo);
        primeiro = segundo;
        segundo = proximo;
        proximo = primeiro + segundo;
    }

    printf("\n\n");
}