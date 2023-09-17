#include <stdio.h>

void limpaBuffer();

int main() {
/*  Implemente um programa de calculadora que ofereça as seguintes opções:
    a. Soma (+)
    b. Subtração (-)
    c. Multiplicação (*)
    d. Divisão (/)
    e. Média Ponderada (MP)
    Para a média ponderada, o usuário deve informar uma nota seguida do respectivo
    peso enquanto quiser, e o programa deve calcular a média ponderada das “n” notas
    com os “p” pesos.
*/
    char operacao;
    float resultado = 0.0;
    int contador = 0;
    
    printf("###### Calculadora ######\n\n");
    printf("Escolha uma operação:\n");
    printf("a. Soma (+)\n");
    printf("b. Subtração (-)\n");
    printf("c. Multiplicação (*)\n");
    printf("d. Divisão (/)\n");
    printf("e. Média Ponderada (MP)\n");
    printf("f. Sair\n");
    
    while (1) {
        operacao = getchar();
        
        if (operacao == 'f') {
            break;
        }

        limpaBuffer();
        
        if (operacao == 'a' || operacao == 'b' || operacao == 'c' || operacao == 'd') {
            float numero1, numero2;
            printf("Digite o primeiro número: ");
            scanf("%f", &numero1);
            
            printf("Digite o segundo número: ");
            scanf("%f", &numero2);
            
            if (operacao == 'a') {
                resultado = numero1 + numero2;
            } else if (operacao == 'b') {
                resultado = numero1 - numero2;
            } else if (operacao == 'c') {
                resultado = numero1 * numero2;
            } else if (operacao == 'd') {
                if (numero2 != 0) {
                    resultado = numero1 / numero2;
                } else {
                    printf("Erro: Divisão por zero!\n");
                }
            }
            
            printf("Resultado: %.2f\n", resultado);
        } else if (operacao == 'e') {
            float nota1, nota2, peso1, peso2;
            printf("Digite a primeira nota: ");
            scanf("%f", &nota1);
            
            printf("Digite o peso da primeira nota: ");
            scanf("%f", &peso1);
            
            printf("Digite a segunda nota: ");
            scanf("%f", &nota2);
            
            printf("Digite o peso da segunda nota: ");
            scanf("%f", &peso2);
            
            if (peso1 + peso2 > 0) {
                resultado = (nota1 * peso1 + nota2 * peso2) / (peso1 + peso2);
                printf("A média ponderada é: %.2f\n", resultado);
            } else {
                printf("Erro: Os pesos devem ser maiores que zero!\n");
            }
        } else {
            printf("Operação inválida. Tente novamente.\n");
        }

        limpaBuffer();
    }
    
    printf("Programa encerrado.\n");
    
    return 0;
}

void limpaBuffer(){
    int c;
    // Limpa o buffer até que encontre um caracter de quebra de linha ou o final do arquivo (EOF), 
    // garantindo que qualquer entrada pendente seja descartada
    while ((c = getchar()) != '\n' && c != EOF);
}
