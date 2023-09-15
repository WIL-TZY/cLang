// Módulos devem ser compilados em arquivos de objetos (.o) para depois serem transformados em programas
// Comando para transformar em objetos:
// gcc -c arquivo.c -o objetos/arquivo.o



int soma(int n) {
  int i;
  int total = 0;
  for (i = 1; i <= n; i++) {
    total += i;
  }
    /* EXEMPLO
    n = 4; total = 1
    i = 1; total = 1 + 1 = 1
    i = 2; total = 2 + 2 = 4
    i = 3; total = 4 + 3 = 6
    i = 4; total = 6 + 4 = 10
    i = 5; ... Fim do loop - condição de quebra: i <= 4
  */
  return (total);
}

int fatorial(int n) {
  int i;
  int total = 1;
  for (i = 1; i <= n; i++) {
    total *= i;
  }
  /* EXEMPLO
    n = 4; total = 1
    i = 1; total = 1 * 1 = 1
    i = 2; total = 1 * 2 = 2
    i = 3; total = 2 * 3 = 6
    i = 4; total = 6 * 4 = 24
    i = 5; ... Fim do loop - condição de quebra: i <= 4
  */
  return (total);
}
