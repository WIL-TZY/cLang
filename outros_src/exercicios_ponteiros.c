#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cabeçalho
double* lerDouble(char* mensagem);
char* lerString(char* mensagem);
char* lerString2(char* mensagem);

int main() {
  //double *entradaNum = lerDouble("Informe um numero: ");
  //printf("Numero = %.2lf\n", *entradaNum);

  char *entradaString1 = lerString("Informe um texto: ");
  printf("Texto = %s\n", entradaString1);
  
  char *entradaString2 = lerString2("Informe um texto: ");
  printf("Texto = %s\n", entradaString2);

  // Liberando o espaço na memória
  //free(entradaString1);
  //free(entradaString2);
  
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

// Realocando memória após o while loop
char* lerString(char* mensagem) {
  /* Jeitos seguros de inicializar uma string vazia:
  // FORMA 1 
  // Adicionando o caracter terminador de string no índice 0
  char string[100]; // Tamanho máximo da string
  string[0] = '\0'; // Inicializa a string com um caractere nulo '\0'
  *string = '\0'; // Mesma coisa da de cima

  // FORMA 2
  // Usando uma string literal vazia
  char string[100] = "";
  */
  int tamanhoMax = 100;
  int byte = sizeof(char);
  char* string = (char*)malloc(tamanhoMax * byte);
  
  // ----------- DEBUG ----------- //
  int tamanho = strlen(string); 

  //printf("String antes: %s\n", string); // Mostra caracteres que são representação de lixo de memória
  //printf("[DEBUG] O tamanho da string: %d.\n", tamanho); // Mostra o tamanho inicial e arbitrário da string

  // Imprime a mensagem passada como parâmetro
  printf("%s", mensagem);
  // Por segurança, para evitar falhas de malloc
  if (string == NULL) {
      exit(1);
  }
   // Inicializando a string com um caractere nulo para evitar comportamento inesperado
  string[0] = '\0';

  char c;
  int cont = 0;
  // ex string: "ola!"
  // c : o | cont : 0 | string : ""
  // c : l | cont : 1 | string : "o"
  // c : a | cont : 2 | string : "ol"
  // c : ! | cont : 3 | string : "ola"
  // c: \n | cont : 4 | string : "ola!" ----> quebra do loop
  while ((c = getchar()) != '\n' && cont < tamanhoMax - 1) {
      // Preenchendo a string com caracteres
      string[cont++] = c;
  }
  // string[0] = 'o'  (1 byte)
  // string[1] = 'l'  (1 byte)
  // string[2] = 'a'  (1 byte)
  // string[3] = '!'  (1 byte)
  // string[4] = '\0' (1 byte)
  string[cont] = '\0'; // Adicionando '\0' no último índice

  // Realocando o tamanho original da string (100) para o novo tamanho de acordo com o número de caracteres inseridos 
  string = realloc(string, cont + 1); // Tem que adicionar +1 pois arrays iniciam-se no índice 0, então se a string contém índices de 0-4, ela precisa de 5 bytes

  // Por segurança, para evitar falhas de realloc
  if (string == NULL) {
      exit(1);
  }

  // ----------- DEBUG ----------- //
  //int tamanhoTotal = sizeof(string); // Sempre devolve 8 que é o tamanho de um ponteiro
  tamanho = strlen(string);
  printf("String depois: %s\n", string);
  printf("\n[DEBUG] O tamanho da string: %d.\n", tamanho); // string = "ola!" ---> OUTPUT: 4
  printf("[DEBUG] O tamanho real da string (incluindo '\\0'): %d.\n", tamanho + 1); // string = "ola!" ---> OUTPUT: 5
  //printf("\n[DEBUG] O tamanho do ponteiro: %d.\n", tamanhoTotal);

  return string;
}

// Realocando memória durante o while loop
char* lerString2(char* mensagem) {
  char *str = '\0';
  int tam = 0;
  int capacidade = 0;

  char c;
  printf("%s", mensagem);

  while ((c = getchar()) != '\n') {
    if (tam == capacidade) {
      // Se o tamanho for igual a capacidade máxima, ai sim realoca mais memória
      capacidade += 1;
      str = (char*)realloc(str, capacidade * sizeof(char));
      if (str == NULL) {
        exit(1);
      }
    }
    /*
      string de entrada: 'ola!'

      -- Não inicializado
      tam : 0 | capacidade : 0 | c : 0 ('\0') | str : 0x0

      -- Inicialização do loop
      (Início Loop1)
      tam : 0 | capacidade : 1 | c : 'o' | str : 0x1f7c3771650 "p", (lixo), ... , (lixo), str[0] : 'p'
      (Final Loop1)
      tam : 1 | capacidade : 1 | c : 'o' | str : 0x1f7c3771650 "o", (lixo), ... , (lixo), str[0] : 'o'
      (Final Loop2)
      tam : 2 | capacidade : 2 | c : 'l' | str : 0x1f7c3771650 "ol", (lixo), ... , (lixo), str[0] : 'o'
      (Final Loop3)
      tam : 3 | capacidade : 3 | c : 'a' | str : 0x1f7c3771650 "ola", (lixo), ... , (lixo), str[0] : 'o'
      (Final Loop4)
      tam : 4 | capacidade : 4 | c : '!' | str : 0x1f7c3771650 "ola!", (lixo), ... , (lixo), str[0] : 'o'
      (Início Loop5) ------> c = '\n' (saída do loop)
      Por fim, o '\0' é adicionado após a saída do loop, a string final aparecerá como: str : 0x1f7c3771650 "ola!"
    */

    str[tam] = c; // Adicionar o caracter na string
    tam++;

    // DEBUG
    printf("Final do loop\n");
  }

  // Adicionando o terminador de string no último índice
  str[tam] = '\0';

  return str;
}