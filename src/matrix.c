
#include <stdlib.h>

/*
 *  Initializes a matrix with a given number of columns and lines.
 *
 *  @param     rows       number of rows in the matrix.
 *  @param     cols       number of columns in the matrix.
 *  @return               polong long inter to initialized matrix.
 */
long long int **initializeMatrix(long long int rows, long long int cols)
{
    long long int **matrix = (long long int **) malloc(rows * sizeof(long long int *));

    if (!matrix)
    {
        
        return NULL;
    }

    for (long long int i = 0; i < rows; i++)
    {
        matrix[i] = (long long int *) calloc(cols, sizeof(long long int));
    }

    return matrix;
}