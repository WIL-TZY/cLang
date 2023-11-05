#include <stdio.h>
#include <stdlib.h>

struct abc {
    int x;
    int y;
};

typedef struct {
    int x;
    int y;
} Exemplo;

int main() {
    /* -------------- STRUCT INDIVIDUAL VS ARRAY DE STRUCT -------------- */
    // Struct individual
    struct abc a;

    // Inicializar um array de instâncias abc com tamanho 2
    struct abc b[2];

    // Popular cada membro da struct individual
    a.x = 0;
    a.y = 1;

    // Popular cada instância do array de struct
    // 0
    b[0].x = 5;
    b[0].y = 3;
    // 1
    b[1].x = 8;
    b[1].y = 2;
    // 2
    b[2].x = 9;
    b[2].y = 3;

    // Imprimir as informações da struct individual
    printf("Struct a - x: %d\nStruct a - y: %d\n", a.x, a.y);
    printf("\n");

    // Imprimir as informações do array de structs
    for (int i = 0; i <= 2; i++) {
        printf("Struct b[%d] - x: %d\nStruct b[%d] - y: %d\n", i, b[i].x, i, b[i].y);
        printf("\n");
    }

    /* -------------- Desreferenciamento - Notação: (->) -------------- */

    // A sintaxe {} só pode ser usada durante a declaração de uma variável para fornecer valores iniciais
    Exemplo ex1 = {0, 1}; // x será 0, y será 1
    // Uma vez que uma variável struct é inicializada, é necessário acessar seus membros individualmente para alterar seus valores
    /*
    ex1.x = 2;
    ex1.y = 3;
    */

    // Ponteiro para uma variável do tipo "Exemplo", no caso, a variável é "ex1"
    // Ou seja, ptr contém o endereço de memória da variável ex1 (que é uma struct)
    Exemplo *ptr = &ex1;

    // ptr -> x é equivalente a: 
    // (*ptr).x que é equivalente a:        // Aqui o ponteiro está sendo desreferenciado, e depois o membro .x é acessado
    // (*&a).x que é equivalente a:         // Como ptr é um ponteiro, é equivalente a &a
    // a.x que nesse caso, é equivalente a:
    // 0 
    printf("%d %d\n", ptr -> x, ptr -> y); // OUTPUT: 0 1
    printf("\n");

    //-------------- OPERADORES C: (&) Versus (*) -------------- //
    /*
    Em C, se você usar os dois operadores (*) e (&) um seguido do outro (*&) junto a uma variável, 
    eles efetivamente se cancelam e você acaba com o valor original. 

    - (*): É o operador de desreferência, usado para acessar o valor apontado por um ponteiro.
    - (&): É o operador "endereço de", que é usado para obter o endereço de memória de uma variável.
    Se você fizer (*&variable), primeiro usará & para obter o endereço da variável e depois * para desreferencia-la, para obter o valor original da variável. 
    
    Em outras palavras, *&variable é equivalente a própria variável em termos do valor resultante.
    */
    // Aqui está o que acontece na prática:
    int resultado = *&ex1.x;

    printf("Valor da variavel: %d\n", ex1.x);               // OUTPUT: x: 42
    printf("Resultado após (*&ex1.x): %d\n", resultado);    // OUTPUT: resultado: 42

    return 0;
}
