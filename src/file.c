#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "matrix.h"
#include "file.h"

#define FILEPATH "tests/random-%lld-%lld.txt"


/*
 *  Reads file into matrix and returns initialized matrix.
 *
 *  @param     filepath     name of the file.
 *  @param     rows         pointer to an integer that will store the number of rows in the matrix.
 *  @param     cols         pointer to an integer that will store the number of columns in the matrix.
 *  @return                 pointer to initialized matrix.
 */

long long int **readFileIntoMatrix(char *filepath, long long int *rows, long long int *cols)
{
    FILE *file = fopen(filepath, "r");

    if (!file)
    {
        printf("\nERROR: Couldn't open the file.\n");
        return NULL;
    }

    fscanf(file, "%lld %lld", rows, cols);

    if (*rows == 0 || *cols == 0)
    {
        printf("\nERROR: Invalid value of number of rows or columns.");
        return NULL;
    }

    long long int **matrix = initializeMatrix(*rows, *cols);

    if (!matrix)
    {
        printf("\nERROR: Couldn't allocate memory for the matrix.");
        return NULL;
    }

    for (long long int i = 0; i < *rows; i++)
    {
        for (long long int j = 0; j < *cols; j++)
        {
            fscanf(file, "%lld ", &matrix[i][j]);
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

char *generateRandomFile(long long int *rows, long long int *cols)
{
    srand(time(NULL));

    *rows = rand() % 100 + 1;
    *cols = rand() % 100 + 1;

    if (*rows < 0 || *cols < 0 || *rows > 6000 || *cols > 6000)
    {
        printf("\nDo you bug my program? \n");
        return NULL;
    }


    
    printf("\n\nNumber of rows: %lld\n"
        "Number of columns: %lld\n", *rows, *cols);

    printf("Range of numbers: 0 - 100\n");

    char *filepath = (char *) malloc(100 + 1);

    sprintf(filepath, FILEPATH, *rows, *cols);
    printf("Filepath: %s\n\n", filepath);          
    
    FILE *file = fopen(filepath, "w");

    if (!file)
    {
        printf("\nERROR: Couldn't open the file.\n");
        return NULL;
    }

    fprintf(file, "%lld %lld \n", *rows, *cols);
    

    for (long long int i = 0; i < *rows; i++)
    {
        for (long long int j = 0; j < *cols; j++)
        {
            fprintf(file, "%d ", rand() % 100);
        }

        fprintf(file, "\n");
    }

    fclose(file);
    file = NULL;

    return filepath;
}

/*
*  Generates a random file for testing, but the user can modify the number of rows and columns and the range of the numbers.
*  
*  @param     rows         pointer to an integer that will store the number of rows in the matrix.
*  @param     cols         pointer to an integer that will store the number of columns in the matrix.
*  @param     range        pointer to an integer that will store the range of the numbers.
*  @return                 the path to the file.
*/


char *generateRandomFileWithInput(long long int *rows, long long int *cols, long long int *range)
{
    srand(time(NULL));
    if (*rows < 0 || *cols < 0 || *rows > 100000 || *cols > 6000 || *range < 0 || *range > 6000)
    
    {
        printf("\nDo you bug my program?\n");
        return NULL;
    }
    
    printf("\n\nNumber of rows: %lld\n"
        "Number of columns: %lld\n", *rows, *cols);

    printf("Range of numbers: 0 - %lld\n", *range);

    char *filepath = (char *) malloc(100 + 1);

    sprintf(filepath, FILEPATH, *rows, *cols);
    printf("Filepath: %s\n\n", filepath);
    

    FILE *file = fopen(filepath, "w");

    if (!file)
    {
        printf("\nERROR: Couldn't open the file.\n");
        return NULL;
    }

    fprintf(file, "%lld %lld \n", *rows, *cols);

    for (long long int i = 0; i < *rows; i++)
    {
        for (long long int j = 0; j < *cols; j++)
        {
            fprintf(file, "%lld ", rand() % (*range+1));
        }

        fprintf(file, "\n");
    }

    fclose(file);
    file = NULL;

    return filepath;
}





