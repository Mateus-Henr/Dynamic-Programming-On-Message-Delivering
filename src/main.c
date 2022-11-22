#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "travel.h"
#include "file.h"


// Function prototype.

void clearConsole();


int main()
{
    clearConsole();
    printf("Welcome!\n");

    while (true)
    {
        char userFilepath[CHAR_MAX];
        int rows = 0, cols = 0;
        int **matrix = NULL;
        int **p = NULL;
        int **numP = NULL;

        printf("Type the filepath: ");
        scanf("%s", userFilepath);
        flushIn();

        matrix = readFileIntoMatrix(userFilepath, &rows, &cols);

        if (!matrix)
        {
            printf("Press ENTER to continue.\n");
            getchar();
            clearConsole();
            continue;
        }

        p = initializeMatrix(rows, cols);

        printf("\nSoma Mínima: ");
        minSum(rows - 1, cols - 1, rows, cols, matrix, p);
        printf("%d\n", p[0][0]);


        numP = initializeMatrix(rows, cols);

        printf("\nQuantidade de Caminhos: ");
        printf("%d\n", numPaths(rows, cols, p, matrix, numP));


        char *file = generateRandomFile(&rows, &cols);

        printf("File gerado em: %s\n", file);

        return 0;
    }
}


/*
 *  Clears the input buffer.
 */
void flushIn()
{
    int ch;

    do
    {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}


/*
 *  Clears console based on user's OS.
 */
void clearConsole()
{
#ifdef _WIN32
    system("cls");

#else
    system("clear");

#endif
}