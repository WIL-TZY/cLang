#include <stdio.h>

void exercicio1();
void exercicio2();
void exercicio3();

int main() {

    exercicio1();
    exercicio2();
    exercicio3();

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