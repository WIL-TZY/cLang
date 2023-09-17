#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Cabeçalhos
void exercicio1();
void exercicio2();
void limpaBuffer();

int main() {
    //exercicio1();
    exercicio2();
    
    return 0;
}

void exercicio1() {
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
    printf("Operações disponíveis:\n");
    printf("  Soma (+)\n");
    printf("  Subtração (-)\n");
    printf("  Multiplicação (*)\n");
    printf("  Divisão (/)\n");
    printf("  Média Ponderada (%%)\n");
    printf("  Sair (s)\n");
    
    while (1) {
        printf("\nDigite qual operação deseja fazer: ");
        operacao = getchar();
        
        if (operacao == 's') {
            break;
        }

        limpaBuffer();
        
        if (operacao == '+' || operacao == '-' || operacao == '*' || operacao == '/') {
            float numero1, numero2;
            printf("Digite o primeiro número: ");
            scanf("%f", &numero1);
            
            printf("Digite o segundo número: ");
            scanf("%f", &numero2);
            
            if (operacao == '+') {
                resultado = numero1 + numero2;
            } else if (operacao == '-') {
                resultado = numero1 - numero2;
            } else if (operacao == '*') {
                resultado = numero1 * numero2;
            } else if (operacao == '/') {
                if (numero2 != 0) {
                    resultado = numero1 / numero2;
                } else {
                    printf("Erro: Não se pode fazer divisão por zero!\n");
                }
            }
            
            // Todas as operações acima irão imprimir esta linha
            printf("Resultado: %.2f\n", resultado);

        } else if (operacao == '%') {
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
}

void exercicio2() {
/*
    Implemente uma função que verifica se uma senha fornecida pelo usuário é válida. 
    A senha deve ter pelo menos 8 caracteres e conter pelo menos uma letra maiúscula,
    uma letra minúscula e um número. 
    A função deve retornar 1 se a senha for válida e 0 caso contrário. 
    (Estudar a biblioteca ctype.h que contém funções para ajudar nesse exercício)
*/
    char senha[20];
    // Inicializando todos os índices da string com '\0' (caractere nulo)
    memset(senha, '\0', sizeof(senha));

    printf("** SENHA **\n");
    printf("Crie sua senha.\n");
    printf("Ela deve conter pelo menos: \n");
    printf("- 8 caractereres.\n");
    printf("- Letra maiúscula.\n");
    printf("- Letra minúscula.\n");
    printf("- Um número.\n");

    // while(1) {

    // }

    printf("Senha: ");
    scanf("%s", senha);

    printf("[DEBUG] senha: %s\n", senha); // DEBUG
    
    for (int i = 0; i < sizeof(senha); i++) {
        printf("a"); // DEBUG
    }

}

void limpaBuffer() {
    int c;
    // Limpa o buffer até que encontre um caracter de quebra de linha ou o final do arquivo (EOF), 
    // garantindo que qualquer entrada pendente seja descartada
    while ((c = getchar()) != '\n' && c != EOF);
}
