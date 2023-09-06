#include <stdio.h>

int main() {
    /* FORMA 1 - Typecasting */
    // Declarando o caracter a ser convertido
    char ch = 'G';
    // Typecast do caracter para convertê-lo em int usando (int)
    printf("%d", (int)(ch)); // OUTPUT: 71
    printf("\n\n");

    /* FORMA 2 - Typecasting */
    // Declarando o caracter a ser convertido
    char ch = 'g';
    // Declarando outra variável como int N e atribuindo o caracter 'ch' ao N
    int N = (int)(ch);
    // Imprimindo o número inteiro na tela
    printf("%d", N); // OUTPUT: 103
    printf("\n\n");

    /* Usando sscanf() */
    // Lê dados de s e os armazena nos locais especificados pelos argumentos adicionais no formato do parâmetro
    const char* s = "136";
    int x;
    sscanf(s, "%d", &x);
    printf("\nO valor inteiro de x é: %d ", x); // OUTPUT: O valor inteiro de x é: 136 
    printf("\n\n");

    /* Usando atoi() */
    // Se a execução for bem-sucedida, o método atoi() retorna o valor inteiro convertido. 
    // Se a string fornecida não puder ser convertida em um número inteiro, ela retornará 0
    const char* str = "136";
    int y = atoi(str);
    printf("\nO valor inteiro de y é: %d", y);
    printf("\n\n");

    /* EXTRA: Convertendo char em int adicionando 0 */
    char ch = 'g';
    int N = (int)(ch)+0;
    printf("%d", N); // OUTPUT: 103

    /* EXTRA: Subtração do valor ASCII */
    // 1. Declarar caracter de entrada do usuário
    char input[100] = "12345";
    int i, result = 0;
 
    for (i = 0; input[i] != '\0'; i++) {
        // 2. Subtraindo o valor ASCII de ‘0’ do caractere de entrada para obter o valor inteiro equivalente
        // 3. E depois somar todos os valores inteiros individuais para obter o valor inteiro final
        result = result * 10 + (input[i] - '0');
        // Repetir a etapa 2 para todos os caracteres da string de entrada
    }
    
    // 4. Imprimindo o resultado no console
    printf("O valor inteiro é: %d\n", result); // OUTPUT: O valor inteiro é: 12345


    return 0;
}