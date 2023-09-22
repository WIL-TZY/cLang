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
  char* string = NULL;
  char c;
  int cont = 0;
  // ola!
  // c = o | cont = 0 |
  // c = l | cont = 1 |
  // c = a | cont = 2 |
  // c = ! | cont = 3 |
  while ((c = getchar()) != '\n') {
    /* NÃO FUNFA
    *string = c;
    string = string + cont; // string[0] = c
    cont++;
    */
  }

  string = malloc(cont);

  if (string == NULL) {
     exit(1);
  }

  fgets(string, 100, stdin);

  return string;
}


