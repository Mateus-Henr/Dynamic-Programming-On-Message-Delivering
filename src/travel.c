#include "travel.h"
#include <stdio.h>

/*
 *  Discovers the minimal sum of the costs of the fields from field(0, 0) to field(n, m).
 *
 *  @param      rows            total number of rows in the matrices.
 *  @param      cols            total number of columns in the matrices.
 *  @param      m               matrix with the cost of travel for each field(field matrix).
 *  @param      p               matrix with the minimal sum of the costs of the fields from each field to field(n, m), used for the dynamic programming.
 */

void minSum(long int rows, long int cols, long int **m, long int **p)
{
    long int xCount = rows - 1;
    long int yCount = cols - 1;
    long int xPos = xCount;
    long int yPos = yCount;
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

long int numPaths(long int rows, long int cols, long int **p, long int **m, long int **numPaths)
{
    // No último campo, o número de caminhos é 1.
    numPaths[rows - 1][cols - 1] = 1;

    // Percorre a matriz de baixo para cima e da direita para a esquerda.
    for (long int i = rows - 1; i >= 0; i--)
    {
        for (long int j = cols - 1; j >= 0; j--)
        {

            if (i == rows - 1 && j == cols - 1)
            {
                // If we are on the last field, we don't need to do anything.
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
