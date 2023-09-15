// Inclusão de bibliotecas - Deve ser feita logo no início
#include <stdio.h>
#include "../libs/meu_modulo.h"
#include <string.h>

// Os símbolos de menor ou maior (<>) indicam ao compilador para procurar no diretório "include" do sistema pela biblioteca "stdio.h" 
// Já as aspas duplas ("") dizem ao compilador para procurar no mesmo diretório que o arquivo fonte

/* GLOSSÁRIO DE COMANDOS USADOS NA COMPILAÇÃO (Usando o terminal)
gcc nome_do_arquivo.c -------------------------------> Faz a compilação
gcc -o nome_do_arquivo.out --------------------------> Transfere o conteúdo compilado p/ um arquivo de output
./nome-do-arquivo.out -------------------------------> Roda o programa compilado
// Junção de comandos p/ compilar e rodar o programa em uma linha só:
gcc nome-do-arquivo.c -o nome-do-arquivo.out && ./nome-do-arquivo.out 

---- Como compilar projetos modulares (ou seja, um projeto com múltiplos arquivos) ---- 
1. Crie um arquivo .c externo e coloque algum código lá. Como funções, variáveis globais ou alguma estrutura.

2. Crie um arquivo header (arquivos terminados em .h). De exemplo, nesse projeto tem o meu_modulo.h. 

3. No arquivo o qual você quer importar o módulo, implemente as funções declaradas no arquivo de header. 
Você pode incluir o arquivo de cabeçalho usando #include "meu_modulo.h" (se atente ao caminho do arquivo) para garantir 
que as implementações da função correspondam aos protótipos.
Isso disponibiliza as declarações de meu_modulo.h para serem usadas no código de outros arquivos.

4. Compile os dois arquivos juntos.
Inclua os arquivos de origem (seu arquivo com a função main) e o módulo (meu_modulo.c) no comando de compilação. 
Use esse comando para compilar ambos os arquivos em um executável só:
    gcc seu_main.c libs/meu_modulo.c -o programa
Você pode rodar o programa resultante com o comando: ./programa

Quando você começa a ter vários arquivos fonte externos, uma boa alternativa é transformá-los em objetos ao invés de compilá-los todos juntos.
Arquivos de objeto são mais fáceis de linkar na hora da compilação, pois são montados a partir de código de máquina.
Arquivos executáveis (.out, .exe, etc) são formados a partir da vinculação de arquivos .o, sendo que arquivos .o não podem ser executados diretamente.
gcc -Wall -g -c nome_do_arquivo.c -------------------> Cria um objeto do arquivo nome_do_arquivo.c
gcc -Wall -g -c libs/meu_modulo.c  -----------------------------> Cria um objeto do arquivo meu_modulo.c
Em seguida você precisa vincular os dois arquivos ".o" resultantes em um único programa executável. Você pode fazer isso usando a opção -o do compilador:
gcc -o demo nome_do_arquivo.o meu_modulo.o -lm
Isso resulta em um executável chamado "demo", que você pode rodar com o comando: ./demo
Dica: Crie uma pasta 'objeto' (ou 'obj') para armazenar todos os arquivos .o
*/

/* CÓDIGOS DE FORMATAÇÃO
Na linguagem C, os símbolos de formatação são especificadores de formato usados com as funções printf e scanf para indicar o tipo de dados que você deseja imprimir ou ler. 

╔═══════════════════════════╦══════════════════════════════════════════════════╗
║   Formatação em C         ║              Descrição                           ║
╠═══════════════════════════╬══════════════════════════════════════════════════╣
║ %c                        ║ char                                             ║
║                           ║   Lê um caractere.                               ║
║                           ║   Exemplo:                                       ║
║                           ║       char letra;                                ║
║                           ║       scanf(“%c”, &letra);                       ║
╠═══════════════════════════╬══════════════════════════════════════════════════╣
║ %s                        ║ string                                           ║
║                           ║   Lê uma string.                                 ║
║                           ║   Exemplo:                                       ║
║                           ║       char nome[20];                             ║
║                           ║       scanf(“%s”, nome);                         ║
╠═══════════════════════════╬══════════════════════════════════════════════════╣
║ %hd                       ║ short                                            ║
║                           ║   Lê um short int                                ║
║                           ║   Exemplo:                                       ║
║                           ║       short num;                                 ║
║                           ║       scanf(“%hd”, &num);                        ║
╠═══════════════════════════╬══════════════════════════════════════════════════╣
║ %d                        ║ int                                              ║
║                           ║   Lê um inteiro                                  ║
║                           ║   Exemplo:                                       ║
║                           ║       int num;                                   ║
║                           ║       scanf(“%d”, &num);                         ║
╠═══════════════════════════╬══════════════════════════════════════════════════╣
║ %i                        ║ int                                              ║
║                           ║   Similar ao %d, com uma diferença sutil:        ║
║                           ║   É capaz de reconhecer números em base          ║
║                           ║   decimal (padrão), octal (base 8, prefixados    ║
║                           ║   com 0) e hexadecimal (base 16, prefixados      ║
║                           ║   com 0x ou 0X).                                 ║ 
║                           ║   Exemplo:                                       ║
║                           ║       int num;                                   ║
║                           ║       scanf(“%i”, &num);                         ║
╠═══════════════════════════╬══════════════════════════════════════════════════╣
║ %ld                       ║ long                                             ║
║                           ║   Lê um long int                                 ║
║                           ║   Exemplo:                                       ║
║                           ║       long num;                                  ║
║                           ║       scanf(“%ld”, &num);                        ║
╠═══════════════════════════╬══════════════════════════════════════════════════╣
║ %f                        ║ float                                            ║
║                           ║   Lê um float                                    ║
║                           ║   Exemplo:                                       ║
║                           ║       float num;                                 ║
║                           ║       scanf(“%f”, &num);                         ║
╠═══════════════════════════╬══════════════════════════════════════════════════╣
║ %lf                       ║ double                                           ║
║                           ║   Lê um double                                   ║
║                           ║   Exemplo:                                       ║
║                           ║       double num;                                ║
║                           ║       scanf(“%lf”, &num);                        ║
╠═══════════════════════════╬══════════════════════════════════════════════════╣
║ %p                        ║ pointer                                          ║
║                           ║   Lê um ponteiro e imprime o endereço            ║
║                           ║   de memória.                                    ║
║                           ║   Exemplo:                                       ║
║                           ║       int *ptr;                                  ║
║                           ║       scanf(“%p”, &ptr);                         ║
╚═══════════════════════════╩══════════════════════════════════════════════════╝
*/

/*
    Organização do diretório:

    clang/
    |-- README.md
    |-- src/
    |   |-- main.c
    |   |-- ... (outros arquivos .c)
    |-- .gitignore
    |-- libs/
    |   |-- meu_modulo.h
    |-- obj/
    |   |-- main.o
    |-- output/
    |   |-- main.out
    |   |-- ... (outros arquivos .out)
|   |-- .vscode
*/

// Função main --- Ponto de entrada e codigo que dirige o programa (driver code)
int main() {
    // IMPRIMIR NO CONSOLE
    printf("Hello, World!\n");

    // VARIÁVEIS
    int idade = 25;
    float pi = 3.14159;
    char turma = 'A';

    // ENTRADA NO CONSOLE
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    printf("\n Sua idade é: %d.", idade);

    // CONDITIONAL STATEMENTS
    if (idade >= 18) {
        printf("Você é adulto.\n");
    } else {
        printf("Você é menor de idade.\n");
    }

    // LOOPS (LAÇOS DE REPETIÇÃO)
    for (int i = 0; i < 5; i++) {
        printf("Iteração N°: %d\n", i);
    }

    while (idade < 30) {
        printf("A idade é menor do que 30.\n");
        idade++;
    }

    // ARRAYS
    int numeros[5] = {1, 2, 3, 4, 5};
    printf("Primeiro elemento: %d\n", numeros[0]);

    // FUNÇÕES
    // Funções devem ser definidas fora do escopo do main()
    /*
        int soma(int a, int b) {
            return a + b;
        }

        int main() {
            printf("Soma: %d\n", soma(3, 4));
        }
    */
   
    // STRUCTS (Estruturas)
    // Exemplo 1 - Usando palavra-chave "struct"
    struct Ponto {
        int x;
        int y;
    };

    struct Ponto p1;
    p1.x = 5;
    p1.y = 10;
    
    // Exemplo 2 - Usando 'typedef struct'
    typedef struct {
        char nome[20];
        int idade;
    } Pessoa;

    Pessoa pessoa1;
    strcpy(pessoa1.nome, "Joaquim");
    pessoa1.idade = 30;

    // PONTEIROS
    int valor = 42;
    int *ptr = &valor;
    printf("Valor: %d\n", *ptr);


    //-------------------------

    char nome[10] = "";
    printf("Olá! Qual é o seu nome?\n");
    scanf("%s", nome);
    printf("Olá, %s!\n\n", nome);

    /* Usando as funções de meu_modulo.c */
    int n;
    printf("Digite um inteiro positivo: ");
    scanf("%d", &n);
    printf("A soma dos primeiros inteiros positivos é %d\n", soma(n));
    printf("O produto dos primeiros inteiros positivos é %d\n", fatorial(n));
    

    // EXTRA: Diferença entre %i e %d
    int decimal = 42;               // Valor em base decimal
    int octal = 052;                // Valor em base octal (52 em decimal)
    int hexadecimal = 0x2A;         // Valor em base hexadecimal (42 em decimal)

    printf("%d\n", decimal);        // Imprime como decimal
    printf("%i\n", decimal);        // Imprime como decimal
    printf("%d\n", octal);          // Imprime como decimal (42 em decimal)
    printf("%i\n", octal);          // Imprime como octal (052 em octal)
    printf("%d\n", hexadecimal);    // Imprime como decimal (42 em decimal)
    printf("%i\n", hexadecimal);    // Imprime como hexadecimal (2A em hexadecimal)


    return 0;
}
// Fim do programa