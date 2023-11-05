#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Um array é o exemplo mais simples de uma estrutura de dados.
// Estruturas de dados são usadas para organizar e armazenar dados em programas de computador.
// Arrays armazenam um conjunto de valores do mesmo tipo em uma sequência contígua de memória.

int main() {
    int array[] = {25, 50, 75, 100};
    printf("Terceiro indice: %d\n", array[3]);
    /* OBS:
    
    Não é ideal usar a função sizeof() para descobrir o tamanho de arrays ou strings (que são arrays de chars).
    Isso porque a função retornaria apenas o tamanho do ponteiro, que é 8 bytes considerando um PC de 64 bits ou 4 bytes considerando um PC de 32 bits.
    Portanto, qual seria uma forma de descobrir o tamanho real de um array?

    Para isso, existe a função strlen() que pode ser usada com strings.
    Porém, ao usar strlen(), o tamanho do array de strings é determinado pelo caractere '\0' (terminador de string).
    Se uma string foi declarada inicialmente com 100 bytes (ex: string[100]), não há uma forma simples de se obter esse tamanho inicial dinamicamente.

    Para exemplificar isso, tomamos alguns arrays:
    */
    int array1[] = {1,2,3,4,5};
    int array2[100] = {1,2,3,4,5};
    int *ptr = array1;
    int tamanhoMax = 100;
    int tamanhoInt = sizeof(int); // Tamanho de um elemento do array (um int)
    int* arrayPtr = (int*)malloc(tamanhoMax * tamanhoInt);

    // Isso retorna o tamanho em bytes do array dias. 
    // O array dias tem 5 elementos do tipo int, que ocupa 4 bytes.
    // Portanto, o tamanho total do array é 5 (elementos) * 4 (bytes por int) = 20 bytes.
    printf("%d\n", sizeof(array1));
    printf("%d\n", sizeof(array2));
    printf("%d\n", sizeof(ptr)); // Imprime o tamanho do ponteiro (8 bytes) ao invés do tamanho do array para o qual ptr está apontando 
    printf("%d\n", sizeof(arrayPtr)); // Imprime o tamanho do ponteiro (8 bytes)  
    printf("%d\n", sizeof(*arrayPtr)); // Imprime o tamanho de um elemento do array (um inteiro, portanto 4bytes)

    // Sabendo disso, qual seria uma maneira de descobrir o tamanho do array para o qual ptr está apontando?

    /* Não existe uma resposta diretiva para essa questão.
    O tamanho de um dado é nada mais nada menos do que um buffer de memória contendo aquele dado, seja uma variável ou um array/string.
    Se for uma string dinâmica criada com malloc, é impossível obter seu tamanho real diretamente usando sizeof(). 
    Isso porque sizeof() fornece o tamanho do ponteiro, não o tamanho da memória alocada dinamicamente. 
    Para controlar o tamanho da memória alocada dinamicamente, normalmente é necessário armazená-la separadamente, talvez em uma variável (tamanhoMax, por exemplo).

    O mais próximo de uma "solução" seria usando um array estático (não alocado dinamicamente), dessa forma é possível usar sizeof para obter seu tamanho. 
    Isso ocorre porque, no caso de um array estático, o compilador conhece o tamanho em tempo de compilação e sizeof() fornece o tamanho em bytes.
    Mas usar um array estático significa não poder modificá-lo, o que não é desejado para essa situação.
    */

    /*
    // Para determinar o tamanho de um array de outros tipos de dados (como inteiros), deve usar outra abordagem. 
    // Em C, é possível fazer isso calculando o tamanho do array em bytes dividido pelo tamanho do tipo de dado.
    int array[] = {1, 2, 3, 4, 5};
    size_t tamanho = sizeof(array) / sizeof(array[0]);
    // Aqui, sizeof(array) dará o tamanho total em bytes do array, e sizeof(array[0]) dará o tamanho de um elemento do array em bytes. 
    // Dividir esses valores lhe dará o número de elementos no array.
    */

    // ARRAY QUE ARMAZENA STRINGS (MATRIZ DE STRINGS)
    /*
        São arrays bidimensionais usados frequentemente para armazenar strings em C. 
        Ele pode armazenar até 10 strings, cada uma com até 50 caracteres de comprimento. 
        É uma maneira eficaz de lidar com um conjunto de strings em um único bloco de memória contígua. 
        Cada elemento nomes[i] representa uma string, e você pode acessar e manipular essas strings como desejar. 
        É uma estrutura de dados comum para lidar com uma lista de nomes, palavras, ou qualquer outra coisa que seja representada como texto.
    */
    // Cada elemento nomes[i] representa uma string, e você pode acessar e manipular essas strings como desejar
    char nomes[10][50]; // Declara um array de 10 strings, cada uma com espaço para 49 caracteres e um caractere nulo de terminação.
    /* IMPORTANTE!
    Por que preciso usar strcpy? Não posso só fazer:
    nomes[0] = "Alice";
    nomes[1] = "Joaquim";
    nomes[2] = "Matheus";

    Não é possível atribuir diretamente uma string literal (como "Alice", "Joaquim" ou "Matheus") a um array de caracteres usando a sintaxe de atribuição simples. 
    Isso ocorre porque uma string literal é, na verdade, um ponteiro constante para uma sequência de caracteres e não pode ser tratada como um array de caracteres que pode ser modificado.
        
    Por conta disso, é necessário usar a função strcpy() da biblioteca string.h para adicionar valores (nesse caso, string literals) em cada índice do array.
    */
    // Preenchendo alguns elementos do array com nomes usando a função strcpy()
    strcpy(nomes[0], "Alice");
    strcpy(nomes[1], "Joaquim");
    strcpy(nomes[2], "Matheus");

    // Para acessar e imprimir os nomes:
    for (int i = 0; i < 10; i++) {
        printf("Nome %d: %s\n", i, nomes[i]);
    }


    return 0;
}
