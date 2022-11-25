#include <stdio.h>
#include <stdlib.h>
#include "travel.h"

/*
    *  Discovers the minimal sum of the costs of the fields from field(0, 0) to field(n, m).
    *
    *  @param      rows            total number of rows in the matrices.
    *  @param      cols            total number of columns in the matrices.
    *  @param      m               matrix with the cost of travel for each field(field matrix).
    *  @param      p               matrix with the minimal sum of the costs of the fields from each field to field(n, m), used for the dynamic programming.
 */

void minSum(long long int rows, long long int cols, long long int **m, long long int **p)
{
    long long int xCount = rows - 1;
    long long int yCount = cols - 1;
    long long int xPos = xCount;
    long long int yPos = yCount;
    while (yCount != -1)
    {
        if (xPos == rows - 1 && yPos == cols - 1)
        {
            p[rows - 1][cols - 1] = m[rows - 1][cols - 1];
        }
        else
        {
            if (xPos == rows - 1)
            {
                p[xPos][yPos] = m[xPos][yPos] + p[xPos][yPos + 1];
            }
            
            else if (yPos == cols - 1)
            {
                p[xPos][yPos] = m[xPos][yPos] + p[xPos + 1][yPos];
            }
            
            else
            {
                if (p[xPos][yPos + 1] <= p[xPos + 1][yPos])
                {
                    p[xPos][yPos] = m[xPos][yPos] + p[xPos][yPos + 1];
                }
                
                else
                {
                    p[xPos][yPos] = m[xPos][yPos] + p[xPos + 1][yPos];
                }
            }
        }
        if (xPos == rows - 1 || yPos == 0)
        {
            if (xCount != 0)
            {
                xCount--;
                xPos = xCount;
                yPos = yCount;
            }
            else
            {
                yCount--;
                xPos = xCount;
                yPos = yCount;
            }
        }
        else
        {
            xPos++;
            yPos--;
        }
    }
}
/*
    *  Discovers the number of minimal paths.
    *
    *  
    *  @param      rows            total number of rows in the matrix.
    *  @param      cols            total number of columns in the matrix.
    *  @param      m               matrix with the cost of travel for each field(field matrix).
    *  @param      p               matrix with the minimal sum of the costs of the fields from each field to field(n, m), used for the dynamic programming.
    *  @param      numPaths        matrix with the number of minimal paths from each field to field(n, m).
    *  @return                     the number of minimal paths.
*/

long long int numPaths(long long int rows, long long int cols, long long int **p, long long int **m,  long long int **numPaths)
{
    // No último campo, o número de caminhos é 1.
    numPaths[rows - 1][cols - 1] = 1;

    // Percorre a matriz de baixo para cima e da direita para a esquerda.
    for (long long int i = rows - 1; i >= 0; i--)
    {
        for (long long int j = cols - 1; j >= 0; j--)
        {

            if (i == rows - 1 && j == cols - 1)
            {
                // Se o campo for o último, o número de caminhos é 1.
                continue;
            }

            else if (i == rows - 1)
            {

                /*
                    Se estiver na última linha da matriz p, pega o valor da direita e soma com o valor da matriz m.
                    Se a soma for igual ao elemento p[i][j], soma 1 ao número de caminhos naquela posição.
                */
                if (p[i][j] == p[i][j + 1] + m[i][j])
                {
                    numPaths[i][j] = numPaths[i][j + 1];
                }
            }


            else if (j == cols - 1)
            {
                /*
                    Se estiver na última coluna da matriz p, pega o valor de baixo e soma com o valor da matriz m.
                    Se a soma for igual ao elemento p[i][j], soma 1 ao número de caminhos naquela posição.
                */
                if (p[i][j] == p[i + 1][j] + m[i][j])
                {
                    numPaths[i][j] = numPaths[i + 1][j];
                }
            }

            else
            {
                /*
                    Se estiver em qualquer outra posição da matriz p, pega o valor da direita e soma com o valor da matriz m.
                    Se a soma for igual ao elemento p[i][j], soma 1 ao número de caminhos naquela posição.
                */
                if (p[i][j] == p[i + 1][j] + m[i][j])
                {
                    numPaths[i][j] += numPaths[i + 1][j];
                }

                /*
                    Se estiver em qualquer outra posição da matriz p, pega o valor de baixo e soma com o valor da matriz m.
                    Se a soma for igual ao elemento p[i][j], soma 1 ao número de caminhos naquela posição.
                */
                if (p[i][j] == p[i][j + 1] + m[i][j])
                {

                    numPaths[i][j] += numPaths[i][j + 1];
                }
            }
        }
    }
    

    // Retorna o número de caminhos na posição [0][0].
    return numPaths[0][0];
}


/*
    *  Discovers the maximum sum of the costs of the fields from each field to field(n, m).
    *  
    * @param      rows            total number of rows in the matrix.
    * @param      cols            total number of columns in the matrix.
    * @param      m               matrix with the cost of travel for each field(field matrix).
    * @param      p               matrix with the minimal sum of the costs of the fields from each field to field(n, m), used for the dynamic programming.
    * @return                     the maximum sum of the costs of the fields from each field to field(n, m).
*/


long long int maxSum( long long int rows, long long int cols, long long int **m, long long int **p)
{
    long long int xCount = rows - 1;
    long long int yCount = cols - 1;
    long long int xPos = xCount;
    long long int yPos = yCount;
    while (yCount != -1)
    {
        if (xPos == rows - 1 && yPos == cols - 1)
        {
            p[rows - 1][cols - 1] = m[rows - 1][cols - 1];
        }
        else
        {
            if (xPos == rows - 1)
            {
                p[xPos][yPos] = m[xPos][yPos] + p[xPos][yPos + 1];
            }
            
            else if (yPos == cols - 1)
            {
                p[xPos][yPos] = m[xPos][yPos] + p[xPos + 1][yPos];
            }
            
            else
            {
                if (p[xPos][yPos + 1] >= p[xPos + 1][yPos])
                {
                    p[xPos][yPos] = m[xPos][yPos] + p[xPos][yPos + 1];
                }
                
                else
                {
                    p[xPos][yPos] = m[xPos][yPos] + p[xPos + 1][yPos];
                }
            }
        }
        if (xPos == rows - 1 || yPos == 0)
        {
            if (xCount != 0)
            {
                xCount--;
                xPos = xCount;
                yPos = yCount;
            }
            else
            {
                yCount--;
                xPos = xCount;
                yPos = yCount;
            }
        }
        else
        {
            xPos++;
            yPos--;
        }
    }
    return p[0][0];
}

/*
    *  Discovers the minimum sum of the costs of the fields from each field to field(n, m), with diagonal movement.
    *
    * @param      rows            total number of rows in the matrix.
    * @param      cols            total number of columns in the matrix.
    * @param      m               matrix with the cost of travel for each field(field matrix).
    * @param      minPD           matrix with the minimal sum of the costs of the fields from each field to field(n, m), used for the dynamic programming.
    * @return                     the minimum sum of the costs of the fields from each field to field(n, m).
*/

long long int minSumDiagonal ( long long int rows, long long int cols, long long int **m, long long int **minPD)
{

    long long int xCount = rows - 1;
    long long int yCount = cols - 1;
    long long int xPos = xCount;
    long long int yPos = yCount;
    while (yCount != -1)
    {
        if (xPos == rows - 1 && yPos == cols - 1)
        {
            minPD[rows - 1][cols - 1] = m[rows - 1][cols - 1];
        }
        else
        {
            if (xPos == rows - 1)
            {
                minPD[xPos][yPos] = m[xPos][yPos] + minPD[xPos][yPos + 1];
            }
            
            else if (yPos == cols - 1)
            {
                minPD[xPos][yPos] = m[xPos][yPos] + minPD[xPos + 1][yPos];
            }
            
            else
            {
                if (minPD[xPos][yPos + 1]  <= minPD[xPos + 1][yPos] && minPD[xPos][yPos + 1] <= minPD[xPos + 1][yPos + 1])
                {
                    minPD[xPos][yPos] = m[xPos][yPos] + minPD[xPos][yPos + 1];
                }
                
                else if (minPD[xPos + 1][yPos] <= minPD[xPos][yPos + 1] && minPD[xPos + 1][yPos] <= minPD[xPos + 1][yPos + 1])
                {
                    minPD[xPos][yPos] = m[xPos][yPos] + minPD[xPos + 1][yPos];
                }
                
                else
                {
                    minPD[xPos][yPos] = m[xPos][yPos] + minPD[xPos + 1][yPos + 1];
                }
            }
        }
        if (xPos == rows - 1 || yPos == 0)
        {
            if (xCount != 0)
            {
                xCount--;
                xPos = xCount;
                yPos = yCount;
            }
            else
            {
                yCount--;
                xPos = xCount;
                yPos = yCount;
            }
        }
        else
        {
            xPos++;
            yPos--;
        }
    }
    return minPD[0][0];
}

/*
    * Discovers the number of paths with the minimum sum of the costs of the fields from each field to field(n, m), with diagonal movement.
    *
    * @param      rows            total number of rows in the matrix.
    * @param      cols            total number of columns in the matrix.
    * @param      m               matrix with the cost of travel for each field(field matrix).
    * @param      minPD           matrix with the minimal sum of the costs of the fields from each field to field(n, m), used for the dynamic programming.
    * @param      numPD           matrix with the number of paths with the minimal sum of the costs of the fields from each field to field(n, m), used for the dynamic programming.
    * @return                     the number of paths with the minimum sum of the costs of the fields from each field to field(n, m).
*/

long long int numPathsSumWithDiagonal( long long int rows, long long int cols, long long int **m, long long int **minPD, long long int **numPD)
{
    // No último campo, o número de caminhos é 1.
    numPD[rows - 1][cols - 1] = 1;

    for (long long int i = rows - 1; i >= 0; i--)
    {
        for (long long int j = cols - 1; j >= 0; j--)
        {
            if (i == rows - 1 && j == cols - 1)
            {
                continue;
            }
            else
            {
                // Se o campo atual for o último da linha, o número de caminhos é igual ao número de caminhos do campo abaixo.
                if (i == rows - 1)
                {
                    numPD[i][j] = numPD[i][j + 1];
                }
                // Se o campo atual for o último da coluna, o número de caminhos é igual ao número de caminhos do campo à direita.
                else if (j == cols - 1)
                {   
                    numPD[i][j] = numPD[i + 1][j];
                }

                // Se o campo atual não for o último da linha nem da coluna, o número de caminhos é igual à soma do número de caminhos do campo à direita e do campo abaixo.
                else
                {
                    
                    if (minPD[i][j] == minPD[i + 1][j] + m[i][j])
                {
                    numPD[i][j] += numPD[i + 1][j];
                }

                /*
                    Se estiver em qualquer outra posição da matriz p, pega o valor de baixo e soma com o valor da matriz m.
                    Se a soma for igual ao elemento p[i][j], soma 1 ao número de caminhos naquela posição.
                */
                if (minPD[i][j] == minPD[i][j + 1] + m[i][j])
                {

                    numPD[i][j] += numPD[i][j + 1];
                }

                /*
                    Se estiver em qualquer outra posição da matriz p, pega o valor da diagonal e soma com o valor da matriz m.
                    Se a soma for igual ao elemento p[i][j], soma 1 ao número de caminhos naquela posição.
                */

                if (minPD[i][j] == minPD[i + 1][j + 1] + m[i][j])
                {
                    numPD[i][j] += numPD[i + 1][j + 1];
                }
                }
            }
        }
    }
    return numPD[0][0];          
}

/*
    *  Prints the coordinates of one of the shortest paths
    *
    *  @param      rows            total number of rows in the matrix.
    *  @param      cols            total number of columns in the matrix.
    *  @param      p              matrix with the minimal sum of the costs of the fields from each field to field(n, m), used for the dynamic programming. 
*/

void printCoordinates(long long int rows, long long int cols, long long int **p)

{
    long long int xPos = 0;
    long long int yPos = 0;
    long long int xCount = 0;
    long long int yCount = 0;
    while (xPos != rows - 1 || yPos != cols - 1)
    {
        if (xPos == rows - 1)
        {
            printf("(%lld, %lld) -> ", xPos, yPos);
            yPos++;
        }
        else if (yPos == cols - 1)
        {
            printf("(%lld, %lld) -> ", xPos, yPos);
            xPos++;
        }
        else
        {
            if (p[xPos][yPos + 1] <= p[xPos + 1][yPos])
            {
                printf("(%lld, %lld) -> ", xPos, yPos);
                yPos++;
            }
            else
            {
                printf("(%lld, %lld) -> ", xPos, yPos);
                xPos++;
            }
        }
    }
    printf("(%lld, %lld) -> ", xPos, yPos);
    printf("END \n");
}

/*
    *  Prints the color matrix, with the colors of the shortest paths.
    *
    *  @param      rows            total number of rows in the matrix.
    *  @param      cols            total number of columns in the matrix.
    *  @param      m               matrix with the cost of travel for each field(field matrix).
    *  @param      p               matrix with the minimal sum of the costs of the fields from each field to field(n, m), used for the dynamic programming.
    *  @param      colorMatrix     matrix with the colors of the shortest paths.
*/

void colorPath(long long int rows, long long int cols, long long int **p, long long int **m, long long int **colorMatrix)
{
    long long int xPos = 0;
    long long int yPos = 0;
    long long int xCount = 0;
    long long int yCount = 0;

    for (long long int i = 0; i < rows; i++)
    {
        for (long long int j = 0; j < cols; j++)
        {
            colorMatrix[i][j] = 0;
        }
    }

    while (xPos != rows - 1 || yPos != cols - 1)
    {
        if (xPos == rows - 1)
        {
            colorMatrix[xPos][yPos] = 1;
            yPos++;
        }
        else if (yPos == cols - 1)
        {
            colorMatrix[xPos][yPos] = 1;
            xPos++;
        }
        else
        {
            if (p[xPos][yPos + 1] <= p[xPos + 1][yPos])
            {
                colorMatrix[xPos][yPos] = 1;
                yPos++;
            }
            else
            {
                colorMatrix[xPos][yPos] = 1;
                xPos++;
            }
        }
    }

    colorMatrix[xPos][yPos] = 1;
     
    for (long long int i = 0; i < rows; i++)
    {
        for (long long int j = 0; j < cols; j++)
        {
            if (colorMatrix[i][j] == 1)
            {
                printf("\033[1;31m");
                printf("%lld ", m[i][j]);
                printf("\033[0m");
            }
            else
            {
                printf("%lld ", m[i][j]);
            }
        }
        printf("\n");
    }
}








