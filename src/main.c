#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "travel.h"
#include "file.h"


// Function prototype.

void clearConsole();


long int main()
{
    clearConsole();
    while (true)
    {
        char userFilepath[CHAR_MAX];
        char generatedFilepath[CHAR_MAX];
        long int rows = 0, cols = 0;
        long int **matrix = NULL;
        long int **p = NULL;
        long int **numP = NULL;
        long int option = 0;
        long int range = 0;

        printf("Welcome to minimum cost path finder!\n\n");
        printf("1 - Enter file path\n");
        printf("2 - Generate random matrix\n");
        printf("3 - Define parameters before generating random matrix\n");
        printf("4 - Exit\n");
        printf("\nEnter option: ");
        scanf("%ld", &option);
        flushIn();

        switch (option)
        {
            case 1:
                clearConsole();
                printf("Enter file path: ");
                scanf("%s", userFilepath);
                flushIn();
                matrix = readFileIntoMatrix(userFilepath, &rows, &cols);
                if (!matrix)
                {
                    printf("Press ENTER to continue ");
                    getchar();
                    clearConsole();
                    break;
                }

                

                p = initializeMatrix(rows, cols);

                printf("\nMinimum sum: ");
                minSum(rows, cols, matrix, p);
                printf("%ld\n", p[0][0]);

                printf("\nPossible paths: ");
                numP = initializeMatrix(rows, cols);
                numPaths(rows, cols, p, matrix, numP);
                printf("%ld\n", numP[0][0]);

                printf("\nPress ENTER to continue ");
                getchar();
                clearConsole();
                break;

            case 2:
                clearConsole();
                printf("Generating random matrix, please wait \n");
                char *generatedFilepath = generateRandomFile(&rows, &cols);

                if(!generatedFilepath)
                {
                    printf("Could not generate file.\n");
                    printf("Press ENTER to continue ");
                    getchar();
                    clearConsole();
                    break;
                }
                
                matrix = readFileIntoMatrix(generatedFilepath, &rows, &cols);

                if (!matrix)
                {
                    printf("Press ENTER to continue ");
                    getchar();
                    clearConsole();
                    break;
                }

                p = initializeMatrix(rows, cols);

                printf("\nMinimum sum: ");
                minSum(rows, cols, matrix, p);
                printf("%ld\n", p[0][0]);

                printf("\nPossible paths: ");
                numP = initializeMatrix(rows, cols);
                numPaths(rows, cols, p, matrix, numP);
                printf("%ld\n", numP[0][0]);

                printf("\nPress ENTER to continue ");
                getchar();
                clearConsole();
                break;

            case 3:
                
                clearConsole();
                printf("Enter number of rows: ");
                scanf("%ld", &rows);
                flushIn();
                printf("Enter number of columns: ");
                scanf("%ld", &cols);
                flushIn();
                printf("Enter range of values: ");
                scanf("%ld", &range);
                flushIn();
                printf("Generating random matrix, please wait \n");
                generatedFilepath = generateRandomFileWithInput(&rows, &cols, &range);

                if(!generatedFilepath)
                {
                    printf("Could not generate file.\n");
                    printf("Press ENTER to continue ");
                    getchar();
                    clearConsole();
                    break;
                }

                 matrix = readFileIntoMatrix(generatedFilepath, &rows, &cols);

                if (!matrix)
                {
                    printf("Press ENTER to continue ");
                    getchar();
                    clearConsole();
                    break;
                }

                p = initializeMatrix(rows, cols);

                printf("\nMinimum sum: ");
                minSum(rows, cols, matrix, p);
                printf("%ld\n", p[0][0]);

                printf("\nPossible paths: ");
                numP = initializeMatrix(rows, cols);
                numPaths(rows, cols, p, matrix, numP);
                printf("%ld\n", numP[0][0]);

                printf("\nPress ENTER to continue ");
                getchar();
                clearConsole();
                break;

            case 4:
                
                printf("Goodbye my friend!\n");
                return 0;



            default:
                printf("Invalid option.\n");
                printf("Press ENTER to continue ");
                getchar();
                clearConsole();
                break;
        }
    }
}


/*
 *  Clears the input buffer.
 */
void flushIn()
{
    long int ch;

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