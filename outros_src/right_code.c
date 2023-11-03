#include <stdio.h>

int main() {
    int numero;
    int divisor = 1;

    printf("Digite um numero inteiro: \n");
    scanf("%d", &numero);
    printf("Divisores: \n");
    
    while(divisor <= numero) {
        if (numero % divisor == 0) {
            printf("%d ", divisor);
        }
        divisor++;
    }
    return 0;
}
