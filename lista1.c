#include <stdio.h>
#include <math.h> 
/* 
Nota: Ao adicionar a lib padrão de matemática (libm/math.h), é necessário usar o comando -lm na hora da compilação 
Dessa forma: gcc lista1.c -o output/lista1.out -lm  && ./output/lista1.out
*/

// Headers
void exercicio1();
void exercicio2();
void exercicio3();
void exercicio4();
void exercicio5();
void exercicio6();
void exercicio7();

int main() {

    // exercicio1();
    // exercicio2();
    // exercicio3();
    // exercicio4();
    exercicio5();
    exercicio6();
    exercicio7();

    return 0;
}

void exercicio1() {
    char nome[50];
    int idade;

    // Solicitar ao usuário que insira o nome
    printf("Digite seu nome: ");
    scanf("%s", nome);

    // Solicitar ao usuário que insira a idade
    printf("Digite sua idade: ");
    scanf("%d", &idade);

    // Imprimir mensagem formatada com nome e idade
    printf("Olá, %s! Você tem %d anos.\n", nome, idade);
}

void exercicio2() {
    float temperaturaCelsius, temperaturaFahrenheit;

    // Solicitar ao usuário que insira a temperatura em Celsius
    printf("Digite a temperatura em Celsius: ");
    scanf("%f", &temperaturaCelsius);

    // Calcular a temperatura equivalente em Fahrenheit
    temperaturaFahrenheit = (temperaturaCelsius * 9 / 5) + 32;

    // Imprimir a temperatura em Fahrenheit
    printf("%.2f graus Celsius são equivalentes a %.2f graus Fahrenheit.\n", temperaturaCelsius, temperaturaFahrenheit);
}

void exercicio3() {
    float base, altura, area;

    // Solicitar ao usuário que insira a base do triângulo
    printf("Digite a base do triângulo: ");
    scanf("%f", &base);

    // Solicitar ao usuário que insira a altura do triângulo
    printf("Digite a altura do triângulo: ");
    scanf("%f", &altura);

    // Calcular a área do triângulo
    area = (base * altura) / 2;

    // Imprimir a área do triângulo
    printf("A área do triângulo é %.2f unidades de área.\n", area);
}

void exercicio4() {
    // Crie um programa que leia um número inteiro e imprima seu quadrado e cubo
    int ex4_num;
    printf("Digite um número inteiro: ");
    scanf("%d", &ex4_num);
    // Forma1
    //quadrado = ex4_num * ex4_num;
    //cubo = ex4_num * ex4_num * ex4_num;

    // Forma2
    double quadrado = pow(ex4_num, 2);
    double cubo = pow(ex4_num, 3);

    // Adicionar .0 faz sumir as casas decimais na hora de imprimir
    printf("\nO quadrado do número %d é %.0lf e seu cubo é %.0lf.\n", ex4_num, quadrado, cubo);
}

void exercicio5() {
    // Escreva um programa que determine se um número digitado pelo usuário é par ou ímpar
    int ex5_num;
    
    printf("Digite um número inteiro: ");
    scanf("%d", &ex5_num);

    if (ex5_num % 2 == 0) {
        printf("%d é um número par.\n", ex5_num);
    } else {
        printf("%d é um número ímpar.\n", ex5_num);
    }
}

void exercicio6() {
    // Crie um programa que determine se um ano fornecido pelo usuário é bissexto ou não
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
}

void exercicio7() {
    // Faça um programa que peça a nota de um aluno em uma prova e verifique se ele foi 
    // aprovado (nota maior ou igual a 6) ou reprovado (nota menor que 6)



}