#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "matrix.h"

#include "file.h"

#define FILEPATH "tests/random-%d-%d.txt"


/*
 *  Reads file into matrix and returns initialized matrix.
 *
 *  @param     filepath     name of the file.
 *  @param     rows         pointer to an integer that will store the number of rows in the matrix.
 *  @param     cols         pointer to an integer that will store the number of columns in the matrix.
 *  @return                 pointer to initialized matrix.
 */

int **readFileIntoMatrix(char *filepath, int *rows, int *cols)
{
    FILE *file = fopen(filepath, "r");

    if (!file)
    {
        printf("\nERROR: Couldn't open the file.\n");
        return NULL;
    }

    fscanf(file, "%d %d", rows, cols);

    if (*rows == 0 || *cols == 0)
    {
        printf("\nERROR: Invalid value of number of rows or columns.");
        return NULL;
    }

    int **matrix = initializeMatrix(*rows, *cols);

    if (!matrix)
    {
        printf("\nERROR: Couldn't allocate memory for the matrix.");
        return NULL;
    }

    for (int i = 0; i < *rows; i++)
    {
        for (int j = 0; j < *cols; j++)
        {
            fscanf(file, "%d ", &matrix[i][j]);
        }
    }

    fclose(file);
    file = NULL;

    return matrix;
}


/*
 *  Generates a random file for testing.
 *
 *  @param     rows         pointer to an integer that will store the number of rows in the matrix.
 *  @param     cols         pointer to an integer that will store the number of columns in the matrix.
 *  @return                 the path to the file.
 */
char *generateRandomFile(int *rows, int *cols)
{
    srand(time(NULL));

    *rows = rand() % 100 + 1;
    *cols = rand() % 100 + 1;


    printf("\nNumber of rows: %d\n"
           "Number of columns: %d\n", *rows, *cols);

    char *filepath = (char *) malloc(strlen(FILEPATH) + 1);

    sprintf(filepath, FILEPATH, *rows, *cols);
    printf("Filepath: %s\n", filepath);

    FILE *file = fopen(filepath, "w");

    if (!file)
    {
        printf("\nERROR: Couldn't open the file.\n");
        return NULL;
    }

    fprintf(file, "%d %d \n", *rows, *cols);

    for (int i = 0; i < *rows; i++)
    {
        for (int j = 0; j < *cols; j++)
        {
            fprintf(file, "%d ", rand() % 100);
        }

        fprintf(file, "\n");
    }

    fclose(file);
    file = NULL;

    return filepath;
}