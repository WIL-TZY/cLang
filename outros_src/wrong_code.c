// Check with the debug and compare to right_code.c
#include <stdio.h>

int main() {
    int numero;
    int divisor = 1;
    int divisor_divisivel = 1;

    printf("Digite um numero inteiro: \n");
    scanf("%d", &numero);
    printf("Divisores:\n");

    while(divisor <= numero) {
        if (numero % divisor == 0) {
            divisor++;
            printf("%d", divisor_divisivel);
            divisor_divisivel++;
        }
        else {
            divisor++;
        }
    }
    return 0;
}
