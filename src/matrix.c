
#include <stdlib.h>

/*
 *  Initializes a matrix with a given number of columns and lines.
 *
 *  @param     rows       number of rows in the matrix.
 *  @param     cols       number of columns in the matrix.
 *  @return               polong inter to initialized matrix.
 */
long int **initializeMatrix(long int rows, long int cols)
{
    long int **matrix = (long int **) malloc(rows * sizeof(long int *));

    if (!matrix)
    {
        
        return NULL;
    }

    for (long int i = 0; i < rows; i++)
    {
        matrix[i] = (long int *) calloc(cols, sizeof(long int));
    }

    return matrix;
}