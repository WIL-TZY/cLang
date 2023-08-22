#include <stdio.h>
// "gcc hello.c -o hello.out && ./hello.out" ---> Comando p/ compilar e rodar o programa
int main(void) {
    printf("Hello, World!\n");

    char nome[10] = "";
    printf("Qual é o seu nome?\n");
    scanf("%s", nome);
    printf("Olá, %s!\n", nome);

    return 0;
}
