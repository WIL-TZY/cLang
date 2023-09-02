#include <stdio.h>

float kmParaMs(float km) {
    return (km / 3.6);
}

float msParaKm(float ms) {
    return (ms * 3.6);
}

void main() {
    // Programa que converte Km/h para M/s ou vice-versa de acordo com a escolha do usuário
    // e fecha o programa quando o usuário quiser
    int x = 0;
    float km, ms;

    for (  ; x != -1; x++) { // Primeira parte do loop pode ser omitida pois o contador x já foi determinado
        //printf("O valor da entrada é: %d (início do loop)\n", x);
        printf("\n");
        printf("- Se você quiser converter Km/h para M/s digite 1:\n");
        printf("\n");
        printf("- Se você quiser converter M/s para K/h digite 2:\n");
        printf("\n");
        printf("- Se você quer encerrar o programa, digite -1.\n");

        scanf("%d", &x);
        if (x == 1) {
            printf("Qual o valor em km/h?\n");
            scanf("%f", &km);
            printf("Esse valor em m/s é: %.2f\n", kmParaMs(km));
        }
        else if (x == 2) {
            printf("Qual o valor em m/s:\n");
            scanf("%f", &ms);
            printf("Esse valor em km/h é: %.2f\n", msParaKm(ms));
        }        
        else if (x == -1) {
            break;
        } else {
            printf("Opção inválida! Por favor, escolha uma opção válida.\n");
        }

        //printf("O valor da entrada é: %d (final do loop)\n", x);
    }

    printf("Programa finalizado! :)\n");
}