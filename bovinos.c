#include <stdio.h>

int main(){
    /* Exercício Bovinos
    Temos uma população de n bovinos.
    A cada ano, n/3 novos bovinos nascem, e n/4 bovinos morrem.
    Quantos anos levam para se atingir uma certa população de
    bovinos informada pelo usuário sabendo que começamos com 10 bovinos?
    */
    int bovinos = 10;
    int quantidadeDeBovinos;
    int anos;

    printf("Digite a quantidade de bovinos que você quer no final:\n");
    scanf("%d", &quantidadeDeBovinos);

    for (anos = 0; bovinos <= quantidadeDeBovinos; anos ++) {
        printf("%d\n", bovinos);
        int bovinosNascidos = bovinos / 3;
        int bovinosMortos = bovinos / 4;
    
        bovinos = (bovinos + bovinosNascidos - bovinosMortos);
    }

    printf("Vão levar %d anos para atingir uma população de %d bovinos\n", anos, quantidadeDeBovinos);

    return 0;
}