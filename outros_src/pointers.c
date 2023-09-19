#include <stdio.h>

// Um ponteiro é um tipo de dado
// Ele ocupa 8 bytes de memória (ou 4bytes, dependendo do SO)

// Cabeçalhos 
int ehIgual(char *s1, char *s2);
void trocar (int a, int b);

int main(void) {
  int n = 50;
  int a = n;
  int *p = &n;

  printf("n : %d\n", n);
  printf("Endereço de n: %p\n", p);
   

  // Strings
  char s[] = "OI!";
  char t[] = "OI!\0";
  //char *t = s; // Mesmo que: &s[0]
  // s também é um ponteiro
  
  printf("s = %s\n", s); // OI!
  printf("t = %s\n", t); // OI!
  printf("Endereço dentro of s : %p\n", s);
  printf("Endereço inside of t : %p\n", t);
  printf("String armazenada em s : %c%c%c%d\n", *t, *(t + 1), *(t + 2), *(t + 3));

  // Comparando strings sem strcmp()
  if (*s == *t) {
    printf("Iguais\n");
  }
  else {
    printf("Diferentes\n");
  }

  int different = ehIgual(s, t);
  printf("As strings são diferentes? -- %d\n", different);


  // Trocar
  int x = 3;
  int y = 4;

  printf("x = %d, y = %d\n", x, y);
  trocar(x, y);
  printf("x = %d, y = %d\n", x, y);

  return 0;
}

// Recriando strcmp()

int ehIgual(char *s1, char *s2) {
  int counter = 0;
  int diferente = 0;


  while (*(s1 + counter) != '\0') {
     if (*(s1 + counter) != *(s2 + counter)) {
       diferente = 1;
  }
     counter++;
  }

  if (*(s2 + counter) != '\0') {
    diferente = 1;
  }

  return diferente;
}

void trocar (int a, int b) {
  int tmp = a;
  a = b;
  b = tmp;
}

// malloc() -> retorna uma quantidade x de bytes do heap
// malloc(sizeof(int)) -> retorna um endereço de 4 bytes 