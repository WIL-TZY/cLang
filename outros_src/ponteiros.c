#include <stdio.h>
#include <locale.h>

// Um ponteiro é um tipo de dado.
// Em um sistema de 32 bits: Os ponteiros normalmente têm 4 bytes de tamanho.
// Em um sistema de 64 bits: Os ponteiros normalmente têm 8 bytes de tamanho.
// Ponteiros são o único tipo de dado em C que podem ser inicializados como 'NULL' (nulo). OBS: Não confundir com o caractere 'NUL' ('\0')
// Um ponteiro que é NULL representa um ponteiro não inicializado ou inválido.

// Cabeçalhos
int ehIgual(char *s1, char *s2);
void trocar1(int a, int b);
void trocar2(int *a, int *b);

int main()
{
	setlocale(LC_ALL, "portuguese");

	int n = 50;
	int a = n;
	int *p = &n;

	printf("n : %d\n", n);
	printf("Endereço de n: %p\n", p);

	// Strings
	char s[] = "OI!";
	char t[] = "OI!\0";
	// char *t = s; // Mesmo que: &s[0]
	//  s também é um ponteiro

	printf("s = %s\n", s); // OI!
	printf("t = %s\n", t); // OI!
	printf("Endereço contido em s : %p\n", s);
	printf("Endereço contido em t : %p\n", t);
	printf("String armazenada em s : %c%c%c%d\n", *t, *(t + 1), *(t + 2), *(t + 3));

	// Comparando strings sem strcmp()
	if (*s == *t)
	{
		printf("Iguais\n");
	}
	else
	{
		printf("Diferentes\n");
	}

	// Se s = "OI!" e t = "OI!\0"
	int different = ehIgual(s, t);
	printf("As strings são diferentes? -- %d\n", different);

	// Passando por valor VS passando por referência
	/*
	  Essa operação não funciona da forma esperada porque em C os argumentos de uma função são passados por valor.
	  Isso significa que quando a função trocar(x, y) é chamada, ela recebe cópias dos valores de x e y, não as próprias variáveis x e y.
	  Portanto, as operações dentro da função trocar afetam apenas as cópias locais desses valores, não as variáveis originais x e y na função main.
	*/
	int x = 3;
	int y = 4;

	printf("FORMA 1\n");
	printf("x = %d, y = %d\n", x, y); // OUTPUT: x = 3, y = 4
	trocar1(x, y);
	printf("x = %d, y = %d\n", x, y); // OUTPUT: x = 3, y = 4

	/*
	Para realizar a troca de valores das variáveis x e y dentro da função trocar,
	é necessário passar os endereços de memória das variáveis x e y para a função.
	Isso é possível usando ponteiros.
	*/
	printf("FORMA 2\n");
	printf("x = %d, y = %d\n", x, y); // OUTPUT: x = 3, y = 4
	// Passando os endereços de x e y
	trocar2(&x, &y);
	printf("x = %d, y = %d\n", x, y); // OUTPUT: x = 4, y = 3

	// ---------------------- DESREFERENCIAMENTO DE PONTEIROS  ---------------------- //
	/*
		Desreferenciar é o processo de acessar o valor para o qual um ponteiro aponta.
		Como os ponteiros são variáveis que armazenam endereços de memória, quando você desreferencia um ponteiro,
		você está essencialmente usando esse endereço de memória para acessar os dados armazenados naquele local da memória.

		A desreferenciação de um ponteiro é feita usando o operador '*' em C.
		A desreferenciação é um conceito fundamental ao trabalhar com ponteiros.
		Ele permite que você leia ou modifique os dados para os quais o ponteiro aponta.
	*/
	// Exemplo
	// 'ptr' é um ponteiro que aponta para um número inteiro
	// Você pode desreferencia-lo para acessar o valor inteiro assim:
	int x = 42;
	int *ptr = &x; // ptr armazena o endereço de memória de x
	int y = *ptr;  // Desreferenciando ptr para acessar o valor no endereço de memória para o qual ele aponta

	return 0;
}

// Recriando strcmp()

int ehIgual(char *s1, char *s2)
{
	int contador = 0;
	int diferente = 0;

	while (*(s1 + contador) != '\0')
	{
		if (*(s1 + contador) != *(s2 + contador))
		{
			diferente = 1;
		}
		contador++;
	}

	if (*(s2 + contador) != '\0')
	{
		diferente = 1;
	}

	return diferente;
}

// Essa não funciona :(
void trocar1(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

// Essa funciona :)
void trocar2(int *a, int *b)
{
	int tmp = *a; // Usando *a para acessar o valor apontado por a (o valor de x)
	*a = *b;	  // Copiando o valor de *b (o valor de y) para *a (o valor de x)
	*b = tmp;	  // Copiando o valor original de *a (o valor de x) para *b (o valor de y)
}

// malloc() -> retorna uma quantidade x de bytes do heap
// malloc(sizeof(int)) -> retorna um endereço de 4 bytes
