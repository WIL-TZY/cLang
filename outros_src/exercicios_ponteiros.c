#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cabeçalho
double* lerDouble();
char* lerString();

int main() {
  
  printf("Informe um numero: ");
  double *entradaNum = lerDouble();
  printf("Numero = %.2lf\n", *entradaNum);

  printf("Informe um texto: ");
  char *entradaString = lerString();
  printf("Texto = %s\n", entradaString);
  
  return 0;
}

double* lerDouble() {
    double* numero = malloc(sizeof(double));
  if (numero == NULL) {
    exit(1);
  }
    
    scanf("%lf", numero);
    while (getchar() != '\n');
    return numero;
}

char* lerString() {
    int tamanho_max = 100;
    int byte = sizeof(char);
    char* string = (char*)malloc(tamanho_max * byte);
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
    while ((c = getchar()) != '\n' && cont < tamanho_max - 1) {
        string[cont++] = c;
    }

    string[cont] = '\0'; // Adicionando '\0' no último índice

    //fgets(string, 100, stdin);

    return string;
}
