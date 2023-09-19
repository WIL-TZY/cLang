#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stddef.h> // ---> biblioteca usada p/ gerenciamento de ponteiros (inclui o tipo size_t)

// Cabeçalhos
size_t strcspn_remade(const char *str, const char *reject);

int main() {
    setlocale(LC_ALL, "portuguese");

    char nome[50];

    printf("Digite seu nome: ");
    // scanf() necessariamente só lê até o espaço
    // Portanto, não é possível adicionar nomes compostos
    //scanf("%s", nome);

    // Uma alternativa é usar a função fgets()
    fgets(nome, sizeof(nome), stdin);
    // No entanto, ele irá incluir o caractere '\n' que é inserido quando o usuário clica enter
    // Para lidar com isso, pode-se usar a função strcspn()
    // strcspn() significa "string complementary span" pois ela procura caracteres não encontrados na string inicial, portanto, seu complemento
    // Ela serve para encontrar a primeira ocorrência de qualquer caractere em uma string que corresponda a um conjunto de caracteres especificado
    // Essa linha está substituindo o caractere de nova linha ('\n') pelo terminador de string nulo ('\0')
    // strcspn(nome, "\n") lê a string passada no 1° parâmetro até encontrar o índice que contem o valor "\n", e ao chegar nele, retorna sua posição
    nome[strcspn(nome, "\n")] = '\0';
    /*
        Explicando o passo a passo:
        Supondo que o nome digitado na entrada do terminal foi "Joana"
        Buffer de entrada:
        nome[0] = 'J'
        nome[1] = 'o'
        nome[2] = 'a'
        nome[3] = 'n'
        nome[4] = 'a'
        nome[5] = '\n'
        strcspn(nome, "\n") ---> retornará 5, que é o tamanho da string (size_t) antes do caracter rejeitado (5 primeiro índices, portanto, nome[0] até nome[5])
        Porém, esse retorno veio no formato de size_t, que é um tipo de dado sem sinal usado para representar tamanhos de memória e índices (em bytes)
        Logo, ao retornar 5 bytes, adicionamos esse 5 devolvido como índice da string "nome". Portanto, nome[5]
        
        nome[strcspn(nome, "\n")] = '\0';
    
    */

    printf("Olá, %s!", nome);
    printf("\n\n");

    // Tipo de dado size_t:
    // Em C, %zu é um especificador de formato usado em funções de formatação de strings, como printf(), para imprimir um valor do tipo size_t. 
    // O size_t é um tipo de dados que representa o tamanho em bytes de objetos e alocações de memória. 
    // Ele é frequentemente usado para índices de arrays e para representar tamanhos de objetos em C.

    // Por exemplo, se quiser imprimir o tamanho de um array usando printf(), pode-se utilizar %zu para formatar corretamente o valor de size_t
    int arr[] = {1, 2, 3, 4, 5};
    size_t tamanho = sizeof(arr);

    printf("O tamanho do array é: %zu bytes\n", tamanho);


    // strlen():
    /*
    strlen() é uma função da biblioteca string.h que é usada para calcular o comprimento de uma string.
    Ela conta o número de caracteres na string até o caractere nulo '\0' que marca o fim da string.
    strlen() retorna o comprimento da string em termos de número de caracteres, excluindo o caractere nulo.
    */
    char exString[] = "Hello, World!";
    size_t comprimento = strlen(exString);
    printf("O comprimento da string é: %zu bytes\n", comprimento);

    // sizeof(): 
    /*
    sizeof() é um operador em C que retorna o tamanho, em bytes, de um tipo de dado ou de uma variável.
    Ele não está limitado a strings; pode ser usado com qualquer tipo de dado, incluindo arrays, estruturas e tipos de dados primitivos.
    sizeof() retorna o tamanho em bytes do tipo de dado ou variável especificado, incluindo qualquer espaço alocado para dados e possíveis preenchimentos.
    */
    size_t tamanhoDaStringEmBytes = sizeof(exString);
    printf("O tamanho da string é: %zu bytes\n", tamanhoDaStringEmBytes);


   // Diferença entre strlen() & sizeof() na prática:
    char str[] = "Hello";  // Uma string com 5 caracteres (incluindo '\0')

    printf("\nsizeof vs strlen:\n");
    size_t tamanho1 = sizeof(str);  // Isso retornará o tamanho total da string (um array de chars), não o comprimento real.
    size_t tamanho2 = strlen(str);  // Isso retornará o comprimento real da string.

    printf("Tamanho usando sizeof: %zu\n", tamanho1); // OUTPUT: Tamanho usando sizeof: 6
    printf("Comprimento usando strlen: %zu\n", tamanho2); // OUTPUT: Comprimento usando strlen: 5

    return 0;
}

size_t strcspn_remade(const char *str, const char *reject) {
    const char *s1 = str;
    const char *s2;

    for (; *s1; ++s1) {
        for (s2 = reject; *s2; ++s2) {
            if (*s1 == *s2) {
                return s1 - str;
            }
        }
    }

    return s1 - str;
}