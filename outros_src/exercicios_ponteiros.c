#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cabeçalho
double* lerDouble(char* mensagem);
char* lerString(char* mensagem);

int main() {
  double *entradaNum = lerDouble("Informe um numero: ");
  printf("Numero = %.2lf\n", *entradaNum);

  char *entradaString = lerString("Informe um texto: ");
  printf("Texto = %s\n", entradaString);
  
  return 0;
}

double* lerDouble(char* mensagem) {
    double* numero = malloc(sizeof(double));
  // Imprime a mensagem passada como parâmetro
  printf("%s", mensagem);
  if (numero == NULL) {
    exit(1);
  }
    
    scanf("%lf", numero);
    while (getchar() != '\n');
    return numero;
}

char* lerString(char* mensagem) {
    /* Jeitos seguros de inicializar uma string vazia:
    // FORMA 1 
    // Adicionando o caracter terminador de string no índice 0
    char string[100]; // Tamanho máximo da string
    string[0] = '\0'; // Inicializa a string com um caractere nulo '\0'

    // FORMA 2
    // Usando uma string literal vazia
    char string[100] = "";
    */
    int tamanhoMax = 100;
    int byte = sizeof(char);
    char* string = (char*)malloc(tamanhoMax * byte);
    
    // ----------- DEBUG ----------- //
    int tamanho = strlen(string); 

    printf("String antes: %s\n", string); // Mostra caracteres que são representação de lixo de memória
    printf("[DEBUG1] O tamanho da string: %d.\n", tamanho); // Mostra o tamanho inicial e arbitrário da string

    // Imprime a mensagem passada como parâmetro
    printf("%s", mensagem);
    // Por segurança, para evitar falhas de malloc
    if (string == NULL) {
        exit(1);
    }

    char c;
    int cont = 0;
    // ex string: "ola!"
    // c = o | cont = 0 |
    // c = l | cont = 1 |
    // c = a | cont = 2 |
    // c = ! | cont = 3 |
    while ((c = getchar()) != '\n' && cont < tamanhoMax - 1) {
        // Preenchendo a string com caracteres
        string[cont++] = c;
    }

    string[cont] = '\0'; // Adicionando '\0' no último índice

    // Realocando o tamanho original da string (100) para o novo tamanho de acordo com o número de caracteres inseridos 
    string = realloc(string, cont);

    // Por segurança, para evitar falhas de realloc
    if (string == NULL) {
        exit(1);
    }

    // ----------- DEBUG ----------- //
    int tamanhoTotal = sizeof(string);
    tamanho = strlen(string);
    printf("String depois: %s\n", string);
    printf("\n[DEBUG2] O tamanho da string: %d.\n", tamanho);
    printf("\n[DEBUG2] O tamanho do ponteiro: %d.\n", tamanhoTotal);

    return string;
}
