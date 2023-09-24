// Inclusão de bibliotecas - Deve ser feita logo no início
#include <stdio.h> // ----> Biblioteca padrão de input/output
#include "../libs/meu_modulo.h"
#include <string.h> // ----> P/ manipulação de strings
#include <locale.h> // ----> Permite utilizar caracteres latinos
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

// Macros
/*
    Macro é uma sequência de código que é definida por um nome e pode ser substituída por essa sequência de código em tempo de compilação. 
    São geralmente criados usando a diretiva #define.
    Devem ser definidos fora da função main, e possuem escopo global neste arquivo.
    A convenção é usar letras maiúsculas.
    Alguns usos comuns de macros:
    - Criar atalhos;
    - Substituir valores constantes;
    -  Gerar código repetitivo de maneira mais conveniente.
*/
#define PI 3.14159265359
#define RAIZ_QUADRADA_DE(x) ((x) * (x))

// Função main --- Ponto de entrada e codigo que dirige o programa (driver code)
/*
    Parâmetros do main() :
    int main(int argc, char *argv[])

    Esses parâmetros não precisam ser fornecidos pelo programador ao chamar a função main(). 
    Em vez disso, esses argumentos são adicionados pelo sistema operacional quando o programa é iniciado.

    int argc: 
    É o número de argumentos da linha de comando fornecidos quando o programa é executado, incluindo o nome do programa. 
    O nome do programa em si é considerado o primeiro argumento. 
    Portanto, argc é sempre pelo menos 1.

    char *argv[]: 
    É um array de strings (um array de ponteiros para caracteres) que contém os argumentos da linha de comando como strings. 
    argv[0] contém o nome do programa, argv[1] contém o primeiro argumento, argv[2] contém o segundo argumento e assim por diante.

    Logo, se você executar um programa chamado "meuprograma" da seguinte maneira:
    ./meuprograma arg1 arg2 arg3
    argc será igual a 4 (o nome do programa mais três argumentos).
    - argv[0] será uma string contendo "meuprograma".
    - argv[1] será uma string contendo "arg1".
    - argv[2] será uma string contendo "arg2".
    - argv[3] será uma string contendo "arg3".

    Esses argumentos da linha de comando podem ser usados para que o programa responda a diferentes entradas ou execute tarefas específicas com base nos argumentos fornecidos. 
    No entanto, eles não são fornecidos explicitamente na chamada da função main(), somente no terminal.
    O sistema operacional automaticamente os preenche uma vez que você roda o programa.
*/
int main() {
    // Chamada de função para permitir utilizar caracteres latinos
    setlocale(LC_ALL, "portuguese");

    // IMPRIMIR NO CONSOLE
    printf("Hello, World!\n");

    // VARIÁVEIS
    int idade = 25;
    float decimal = 5.3283;
    char turma = 'A';

    // ENTRADA NO CONSOLE
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    printf("Sua idade é: %d.\n", idade);

    // PRINTANDO UM MACRO
    double pi = PI;
    printf("O valor de pi é: %.5lf\n", pi);
    int num = 5;
    int resultado = RAIZ_QUADRADA_DE(5); // Isso é substituído por int resultado = ((5) * (5));
    printf("A raiz quadrada de %d é: %d\n", num, resultado);

    // CONDICIONAIS
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

    // ARRAYS (1D) --- VETORES
    // Quando iniciados dessa forma, pode deixar o índice vazio ou atribuir um valor que servirá como seu tamanho, como por exemplo numeros[5] = {1, 2, 3, 4, 5};
    //Se nada for atribuído, o próprio compilador irá determinar o tamanho necessário durante a execução do programa
    int arr1d_numeros[] = {1, 2, 3, 4, 5}; 
    printf("Primeiro elemento: %d\n", arr1d_numeros[0]);

    // ARRAYS (2D) --- MATRIZES
    int arr2d_numeros[4][2] = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8}
    };
    printf("Elemento posicionado na linha 2 e coluna 1: %d\n", arr2d_numeros[2][1]);
    // Na declaração acima, arr2d_numeros é uma matriz bidimensional com 4 linhas e 2 colunas. 
    // Os elementos podem ser acessados usando a notação [linha][coluna], como arr2d_numeros[2][1] para acessar o valor 6.
    /* OBS: 
        Importante lembrar que arrays se iniciam no índice 0, não no índice 1. 
        Portanto, a "linha 2" é na verdade a "linha 3" e a "coluna 1" é a "coluna 2".
    */

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
   
    // STRUCTS (ESTRUTURAS)
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
    /*
        Ponteiros são variáveis que armazenam endereços de memória de outras variáveis. 
        Os ponteiros permitem que você acesse e manipule dados indiretamente, acessando a memória onde os dados estão armazenados.
        Alguns usos comuns de ponteiros incluem:
        - Alocação dinâmica de memória;
        - Passagem de argumentos por referência para funções;
        - Criação de estruturas de dados complexas;
        - Etc.
                                    -- GLOSSÁRIO --
        - Endereço de Memória: 
            Cada variável em um programa C ou C++ é armazenada em uma posição de memória com um endereço único. 
            Os ponteiros armazenam esses endereços de memória.
        - Variáveis de Ponteiro: 
            Uma variável de ponteiro é uma variável que pode armazenar um endereço de memória. 
            Em C, você declara uma variável de ponteiro usando o símbolo '*'.
            Mas cuidado, pois esse símbolo adquire outro significado uma vez que você declara um ponteiro.
            Depois de declarada, você pode usar o símbolo '*' como um operador.

                                -- OPERADORES DE PONTEIRO --
        - Operador de Endereço (&): 
            O operador '&' é usado para obter o endereço de memória de uma variável existente.
        - Operador de Desreferência (*): 
        O operador '*' é usado para acessar o valor armazenado em um endereço de memória apontado por um ponteiro.

        Ponteiros fornecem um alto grau de controle e flexibilidade ao programa, mas também podem ser propensos a erros se não forem usados com cuidado.
    */
    int valor = 50;
    int *ptr = &valor;
    printf("Valor armazenado no ponteiro: %d\n", *ptr);                 // OUTPUT: 50
    printf("Endereço armazenado no ponteiro (%%p & *ptr): %p\n", *ptr); // OUTPUT: 0000000000000032 ----> 50 convertido para hexadecimal (pois a formatação %p espera um endereço de memória)
    printf("Endereço armazenado no ponteiro (%%p & ptr): %p\n", ptr);   // OUTPUT: Um número hexadecimal que é gerado dinamicamente a cada execução
    printf("Endereço de memória da variável 'valor': %p\n", &valor);    // OUTPUT: O mesmo número hexadecimal gerado acima
    printf("Endereço de memória do próprio ponteiro: %p\n", &ptr);      // OUTPUT: Outro número hexadecimal, dessa vez é o endereço do próprio ponteiro, e não o endereço que ele armazena

    //-------------------------//

    /* Usando as funções de meu_modulo.c */
    int n;
    printf("\nDigite um inteiro positivo: ");
    scanf("%d", &n);
    printf("A soma dos primeiros inteiros positivos é %d\n", soma(n));
    printf("O produto dos primeiros inteiros positivos é %d\n", fatorial(n));

    // EXTRA: Diferença entre %i e %d
    printf("\n-- Testando diferentes sistemas de numeração --\n");
    int base10 = 42;               // Valor em base decimal
    int base8 = 052;                // Valor em base octal (52 em decimal)
    int base16 = 0x2A;         // Valor em base hexadecimal (42 em decimal)

    printf("%d\n", base10);        // Imprime como decimal
    printf("%i\n", base10);        // Imprime como decimal
    printf("%d\n", base8);          // Imprime como decimal (42 em decimal)
    printf("%i\n", base8);          // Imprime como octal (052 em octal)
    printf("%d\n", base16);    // Imprime como decimal (42 em decimal)
    printf("%i\n", base16);    // Imprime como hexadecimal (2A em hexadecimal)

    // NOTAÇÃO CIENTÍFICA EM C
    /* 
        Na linguagem C, você pode representar números em notação científica usando a letra 'E' ou 'e' para denotar a parte exponencial. 
        Notação científica é útil para representar números muito grandes ou muito pequenos de forma mais concisa. 

        Observe que o 'E' ou 'e' indica a potência de 10 pela qual o número base deve ser multiplicado (podendo ser potência positiva ou negativa). 
        
        Nesse exemplo, num * 1e6 será o mesmo que 25 * 1e6, que representa 25 multiplicado por 10 elevado à sexta potência (ou seja, 1000).

        Exemplo: Suponha-se que você queira executar uma operação que arredonde um dado número para seis casas decimais.
        num = 5;
        double arrendondaNum = round(num * 1e6) / 1e6;

        Especificamente, 1e6 representa o número 1 multiplicado por 10 elevado à potência de 6, que equivale a 1.000.000. 
        Então, 1e6 é igual a 1.000.000. E num * 1e6 = 15.625.

    */
    printf("\nNotação Científica:\n");
    double exemplo = 1.23e3; // Isso representa 1.23 * 10^3
    printf("%lf\n", exemplo); // OUTPUT: 1230.000000

    exemplo = 4.56E-2; // Isso representa 4.56 * 10^(-2)
    printf("%lf\n", exemplo); // OUTPUT: 0.045600

    return 0;
}
// Fim do programa