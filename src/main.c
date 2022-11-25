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
        long long int **pDiag = NULL;
        long long int **numP = NULL;
        long long int **numPD = NULL;
        long long int **numM = NULL;
        long long int **maxP = NULL;
        long long int **minPD = NULL;
        long long int **colorMatrix = NULL;
        long long int option = 0;
        long long int option2 = 0;
        long long int range = 0;
        clock_t start, end;
        double time = 0.0;
        

        printf("Welcome!\n\n");
        printf("1 - Enter file path\n");
        printf("2 - Generate random matrix\n");
        printf("3 - Define parameters before generating random matrix\n");
        printf("4 - Extra options\n");
        printf("5 - Exit\n");
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

                printf("\nTime spent: %fs\n\n", (double)(end - start) / CLOCKS_PER_SEC);

                printf("Want to show coordinates of one of the shortest paths? ");
                printf("\n1 - Yes\nOTHER - No\n");
                printf("\nEnter option: ");
                scanf("%lld", &option2);
                flushIn();

                switch(option2)
                {
                    case 1:
                        clearConsole();
                        printf("Coordinates:\n");
                        printCoordinates(rows, cols, p);

                        if (rows <= 30 && cols <= 30)
                        {

                            printf("\n\nColor matrix:\n");
                            colorMatrix = initializeMatrix(rows, cols);
                            colorPath(rows, cols, p, matrix, colorMatrix);
                        }             
                        break;
                    default:
                        break;
                }
                
                printf("\nPress ENTER to continue ");
                getchar();
                clearConsole();
                break;

            case 2:

                clearConsole();
                printf("Generating random matrix, please wait");
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

                printf("Minimum sum: ");
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

                printf("\nWant to show coordinates of one of the shortest paths? ");
                printf("\n1 - Yes\nOTHER - No\n");
                printf("\nEnter option: ");
                scanf("%lld", &option2);
                flushIn();

                switch(option2)
                {
                    case 1:
                        clearConsole();
                        printf("Coordinates:\n");
                        printCoordinates(rows, cols, p);

                        if (rows <= 30 && cols <= 30)
                        {

                            printf("\n\nColor matrix:\n");
                            colorMatrix = initializeMatrix(rows, cols);
                            colorPath(rows, cols, p, matrix, colorMatrix);
                        }             
                        break;
                    default:
                        break;
                }
                
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

                printf("Want to show coordinates of one of the shortest paths? ");
                printf("\n1 - Yes\nOTHER - No\n");
                printf("\nEnter option: ");
                scanf("%lld", &option2);
                flushIn();

                switch(option2)
                {
                    case 1:
                        clearConsole();
                        printf("Coordinates:\n");
                        printCoordinates(rows, cols, p);

                        if (rows <= 30 && cols <= 30)
                        {

                            printf("\n\nColor matrix:\n");
                            colorMatrix = initializeMatrix(rows, cols);
                            colorPath(rows, cols, p, matrix, colorMatrix);
                        }             
                        break;
                    default:
                        break;
                }
                
                printf("\nPress ENTER to continue ");
                getchar();
                clearConsole();
                break;

            case 4:

                clearConsole();
                printf("Enter filepath: ");
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

                maxP = initializeMatrix(rows, cols);

                printf("\nMaximum sum: ");
                maxSum(rows, cols, matrix, maxP);
                printf("%lld\n", maxP[0][0]);

                numP = initializeMatrix(rows, cols);
                printf("\nPossible paths: ");
                numPaths(rows, cols, maxP, matrix, numP);
                if (numP[0][0] <= 0)
                {
                    printf("Close to infinity!\n");
                }
                else
                {
                    printf("%lld\n", numP[0][0]);
                }




                minPD = initializeMatrix(rows, cols);

                printf("\nMinimum sum with diagonal: ");
                minSumDiagonal(rows, cols, matrix, minPD);
                printf("%lld\n", minPD[0][0]);

                numPD = initializeMatrix(rows, cols);
                printf("\nPossible paths: ");
                numPathsSumWithDiagonal(rows, cols, matrix, minPD, numPD);
                if (numPD[0][0] <= 0)
                {
                    printf("Close to infinity!\n");
                }
                else
                {
                    printf("%lld\n", numPD[0][0]);
                }
                
                


                printf("\nPress ENTER to continue ");
                getchar();
                clearConsole();
                break;

            case 5:
                
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