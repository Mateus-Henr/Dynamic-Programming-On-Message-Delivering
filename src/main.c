#include <stdio.h>
#include <graphics.h>
#include <math.h>

#include <stdlib.h>
#include "travel.h"


int main ()
{
    // ESSA MAIN EH COMPLETAMENTE E SOMENTE PARA UM TESTE, PODE APAGAR TUDO SEM MEDO
    int **matrix;
    int **p;
    matrix = (int**) malloc(sizeof(int*) * 3);
    for (int i = 0; i < 3; i++) matrix[i] = (int*) calloc(3, sizeof(int));
    p = (int**) malloc(sizeof(int*) * 3);
    for (int i = 0; i < 3; i++) p[i] = (int*) calloc(3, sizeof(int));
    int matrix1[3][3] = {
        {1, 3,1},
        {1, 5,1},
        {4, 2,1}
    };
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            matrix[i][j] = matrix1[i][j];
        }
    }

    minSum(2, 2, 3, 3, matrix, p);
    printf("%d", p[0][0]);
    
    printf("%d\n", numPaths(0, 0, 3, 3, p));
    char *filename [100];
    filename = generateRandomFile(
    return 0;
}