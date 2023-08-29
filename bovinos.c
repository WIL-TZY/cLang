#include <stdio.h>

int main(){
   // Exercício dos bovinos
    int bovinos = 10;
    int quantidadeDeBovinos;
    int anos;

    printf("Digite a quantidade de bovinos que você quer no final:\n");
    scanf("%d", &quantidadeDeBovinos);

    for (anos = 0; bovinos <= quantidadeDeBovinos; anos ++) {
        printf("%d\n", bovinos);
        int bovinosNascidos = quantidadeDeBovinos / 3;
        int bovinosMortos = quantidadeDeBovinos / 4;
    
        bovinos = (bovinos + bovinosNascidos - bovinosMortos);
    }

    printf("Bovinos %d, Anos %d \n", quantidadeDeBovinos, anos);

    //printf("Vão levar %d anos para atingir uma população de %d bovinos\n", anos, previsao);

    return 0;
}