#include <stdio.h>
/*
--------+--------+--------+--------+--------+
        |  Col1  |  Col2  |  Col3  |  Col4  |
--------+--------+--------+--------+--------+
  Lin1  |   1    |    2   |    3   |    4   |
  Lin2  |   5    |    6   |    7   |    8   |
  Lin3  |   9    |   10   |   11   |   12   |
--------+--------+--------+--------+--------+
*/

int main() {
    // Matriz (vetor 2D) de 3 linhas e 4 colunas
    int matriz[3][4] = {
        {  1,  2,  3,  4  },
        {  5,  6,  7,  8  },
        {  9, 10, 11, 12  }
    };

    // Acessando e printando elementos de uma matriz
    printf("Matriz:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Modificando todos os valores da matriz para 1 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            matriz[i][j] = 1;
        }
    }

    // Acessando e printando elementos da matriz após modificações
    printf("Matriz modificada:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    int tamanho = sizeof(matriz) / sizeof(matriz[0]);
    printf("Tamanho da matriz: %d\n", tamanho);
    printf("\n");
}