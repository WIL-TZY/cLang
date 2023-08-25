// Inclusão de bibliotecas - Deve ser feita logo no início
#include <stdio.h>
#include "help.h" 
// Os símbolos de menor ou maior (<>) indicam ao compilador para procurar no diretório "include" do sistema pela biblioteca "stdio.h" 
// Já as aspas duplas ("") dizem ao compilador para procurar no mesmo diretório que o arquivo fonte

/* GLOSSÁRIO DE COMANDOS
gcc hello.c -------------------------------> Faz a compilação
gcc -o hello.out --------------------------> Transfere o conteúdo compilado p/ um arquivo de output
./hello.out ------------------------------> Roda o programa compilado
gcc hello.c -o hello.out && ./hello.out ---> Junção de comandos p/ compilar e rodar o programa

---- Como compilar projetos modulares (ou seja, um projeto com múltiplos arquivos) ---- 
Cada arquivo separado deve ser convertido em um objeto (.o) antes da compilação acontecer
gcc -Wall -g -c hello.c -------------------> Cria um objeto do arquivo hello.c
gcc -Wall -g -c help.c  -------------------> Cria um objeto do arquivo help.c
Em seguida você precisa vincular os dois arquivos ".o" resultantes em um único programa executável. Você pode fazer isso usando a opção -o do compilador:
gcc -o demo hello.o help.o -lm
Isso resulta em um executável chamado "demo", que você pode rodar com o comando: ./demo
*/

// Função main --- Ponto de entrada do programa
int main() {
    printf("Hello, World!\n\n");

    
    char nome[10] = "";
    printf("Olá! Qual é o seu nome?\n");
    scanf("%s", nome);
    printf("Olá, %s!\n\n", nome);

    /* Usando as funções de help.c
    int n;
    printf("Digite um inteiro positivo: ");
    scanf("%d", &n);
    printf("A soma dos primeiros inteiros positivos é %d\n", soma(n));
    printf("O produto dos primeiros inteiros positivos é %d\n", fatorial(n));
    */

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
// Fim do programa