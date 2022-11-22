#ifndef TP02_MATRIX_H
#define TP02_MATRIX_H
#endif

#include <stdlib.h>


/*
 *  Initializes a matrix with a given number of columns and lines.
 *
 *  @param     rows       number of rows in the matrix.
 *  @param     cols       number of columns in the matrix.
 *  @return               pointer to initialized matrix.
 */
int **initializeMatrix(int rows, int cols)
{
    int **matrix = (int **) malloc(rows * sizeof(int *));

    if (!matrix)
    {
        return NULL;
    }

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *) calloc(cols, sizeof(int));
    }

    return matrix;
}