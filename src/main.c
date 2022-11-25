#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>
#include "travel.h"
#include "file.h"
#include "matrix.h"


// Function prototype.

void clearConsole();

void flushIn();


long long int main()
{
    clearConsole();
    while (true)
    {

        char userFilepath[CHAR_MAX];
        char generatedFilepath[CHAR_MAX];
        long long int rows = 0, cols = 0;
        long long int **matrix = NULL;
        long long int **p = NULL;
        long long int **numP = NULL;
        long long int **numM = NULL;
        long long int option = 0;
        long long int range = 0;
        clock_t start, end;
        double time = 0.0;
        

        printf("Welcome to minimum cost path finder!\n\n");
        printf("1 - Enter file path\n");
        printf("2 - Generate random matrix\n");
        printf("3 - Define parameters before generating random matrix\n");
        printf("4 - Exit\n");
        printf("\nEnter option: ");
        scanf("%lld", &option);
        flushIn();

        switch (option)
        {
            case 1:
                clearConsole();
                printf("Enter file path: ");
                scanf("%s", userFilepath);
                flushIn();

                start = clock();

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
                printf("%lld\n", p[0][0]);

                printf("\nPossible paths: ");
                numP = initializeMatrix(rows, cols);
                numPaths(rows, cols, p, matrix, numP);
                if (numP[0][0] == 0)
                {
                    printf("Close to infinity!");
                }
                else
                {
                    printf("%lld\n", numP[0][0]);
                }

                end = clock();

                
                 
                printf("\nTime spent: %fs\n", (double)(end - start) / CLOCKS_PER_SEC);

               




            


                


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
                
                start = clock();
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
                printf("%lld\n", p[0][0]);

                printf("\nPossible paths: ");
                numP = initializeMatrix(rows, cols);
                numPaths(rows, cols, p, matrix, numP);
                if (numP[0][0] <= 0)
                {
                    printf("\nClose to infinity!");
                }
                else
                {
                    printf("%lld\n", numP[0][0]);
                }

                end = clock();
                printf("\nTime spent: %fs\n", (double)(end - start) / CLOCKS_PER_SEC);

                printf("\nPress ENTER to continue ");
                getchar();
                clearConsole();
                break;

            case 3:
                
                clearConsole();
                printf("Enter number of rows: ");
                scanf("%lld", &rows);
                flushIn();
                printf("Enter number of columns: ");
                scanf("%lld", &cols);
                flushIn();
                printf("Enter range of values: ");
                scanf("%lld", &range);
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

                printf("File generated. \n\n");

               
                start = clock();
                 
                 matrix = readFileIntoMatrix(generatedFilepath, &rows, &cols);

                if (!matrix)
                {
                    printf("Press ENTER to continue ");
                    getchar();
                    clearConsole();
                    break;
                }
                
                p = initializeMatrix(rows, cols);

                printf("Minimum sum: ");
                minSum(rows, cols, matrix, p);
                printf("%lld\n", p[0][0]);

                printf("\nPossible paths: ");
                numP = initializeMatrix(rows, cols);
                numPaths(rows, cols, p, matrix, numP);
                if (numP[0][0] <= 0)
                {
                    printf("Close to infinity!\n");
                }
                else
                {
                    printf("%lld\n", numP[0][0]);
                }

                end = clock();
            
                printf("\nTime spent: %fs\n", (double)(end - start) / CLOCKS_PER_SEC);

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
    long long int ch;

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