#include <stdio.h>
#include <stdlib.h> // Lib da função srand() e rand(), mas é necessário a de baixo p/ gerar uma seed diferente com srand() para evitar números falso-aleatórios
#include <time.h> // Função time(). Gera um valor específico com base na hora atual

int main() {
   // Jogo Adivinha
    int tentativas;
    int numero;
    srand(time(NULL)); // Gera uma seed diferente toda vez para escolher números aleatórios
    int sorteio = rand() % 51; // Gera um número de 0 a 50 (se fizesse % 50 só iria gerar de 0 a 49)

    printf("Bem-vindo(a) ao jogo de adivinhação!\n");
    printf("Digite o número de tentativas:\n");
    scanf("%d", &tentativas);
    printf("Tente adivinhar o número sorteado pelo programa.\n");

    while (tentativas > 0) {
 
        printf("\nChute um número (0 a 50):\n");
        scanf("%d", &numero);

        if (numero == sorteio) {
            printf("\nVocê acertou! O número era: %d\n\n", sorteio);
            printf("Tentativas restantes: %d", tentativas);
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
        printf("\nVocê perdeu... O número era: %d\n", sorteio);        
    } 

    return 0;
}