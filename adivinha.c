#include <stdio.h>

int main() {
   // Jogo Adivinha
    int tentativas;
    int numero;
    int sorteio = 42;

    printf("Bem-vindo(a) ao jogo de adivinhação!\n");
    printf("Digite o número de tentativas:\n");
    scanf("%d", &tentativas);
    printf("Tente adivinhar o número sorteado pelo programa.\n");

    while (tentativas > 0) {
 
        printf("\nDigite um número de 0-100:\n");
        scanf("%d", &numero);

        if (numero == sorteio) {
            printf("\nVocê acertou!\n\n");
            tentativas = -1;
        }
        else {
            if (numero > sorteio) {
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
        printf("\nVocê perdeu...\n");        
    } 

    return 0;
}