#include <stdio.h>
#include <stdlib.h>
#include "travel.h"

int main ()
{
    // ESSA MAIN EH COMPLETAMENTE E SOMENTE PARA UM TESTE, PODE APAGAR TUDO SEM MEDO
    int **matrix;
    int **p;
    matrix = (int**) malloc(sizeof(int*) * 9);
    for (int i = 0; i < 9; i++) matrix[i] = (int*) calloc(9, sizeof(int));
    p = (int**) malloc(sizeof(int*) * 9);
    for (int i = 0; i < 9; i++) p[i] = (int*) calloc(9, sizeof(int));
    int matrix1[9][9] = {
        {1, 1, 1, 9, 9, 9, 9, 9, 9},
        {1, 9, 1, 1, 1, 9, 2, 1, 9},
        {1, 9, 1, 9, 1, 9, 9, 1, 9},
        {9, 9, 1, 1, 1, 1, 1, 1, 9},
        {9, 9, 9, 9, 1, 9, 9, 1, 9},
        {9, 1, 9, 9, 1, 9, 9, 1, 9},
        {9, 9, 1, 1, 1, 9, 9, 1, 9},
        {9, 9, 9, 1, 1, 1, 1, 1, 9},
        {9, 9, 9, 9, 9, 9, 9, 1, 1},
        };
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            matrix[i][j] = matrix1[i][j];
        }
    }

    minSum(8, 8, 9, 9, matrix, p);
    printf("%d\n", p[0][0]);
    printf("%d\n", numPaths(0, 0, 9, 9, p));

    return 0;
}