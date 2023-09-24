#include <stdio.h>

// Uma matriz é uma forma específica de array bidimensional, organizada em linhas e colunas.
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

    /*
        ERRATA: Seria melhor usar size_t pro tamanho ao invés de int
        size_t é um tipo definido como grande o suficiente para representar o tamanho de qualquer objeto escrito em C. 
        Os outros tipos, não. Nada impede de usar int se quiser, mas é uma opção que pode levar a bugs.
        Portanto, para armazenar o tamanho de um objeto, o ideal é usar size_t.
    */
    int tamanho = sizeof(matriz) / sizeof(matriz[0]);
    printf("Tamanho da matriz: %d\n", tamanho);
    printf("\n");
}