#include <stdio.h>

int main() {
    int numero;

    // Solicita um número ao usuário
    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    printf("Divisores de %d: ", numero);

    // Verifica os divisores do número
    for (int i = 1; i <= numero; i++) {
        if (numero % i == 0) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}
