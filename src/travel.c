#include "travel.h"

/*
 *  Discovers the minimal sum of the costs of the fields from field(0, 0) to field(n, m).
 *
 *  @param      xPos            current line on the field matrix.
 *  @param      yPos            current column on the field matrix.
 *  @param      rows            total number of rows in the matrices.
 *  @param      cols            total number of columns in the matrices.
 *  @param      m               matrix with the cost of travel for each field(field matrix).
 *  @param      p               matrix with the minimal sum of the costs of the fields from each field to field(n, m), used for the dynamic programming.
 */
void minSum(int xPos, int yPos, int rows, int cols, int **m, int **p)
{
    if(xPos == rows - 1 && yPos == cols - 1)
    {
        p[rows - 1][cols - 1] = m[rows - 1][cols - 1];
    }
    else
    {
        if(xPos == rows - 1)
        {
            p[xPos][yPos] = m[xPos][yPos] + p[xPos][yPos + 1];
        }
        else if(yPos == cols - 1)
        {
            p[xPos][yPos] = m[xPos][yPos] + p[xPos + 1][yPos];
        }
        else
        {
            if(p[xPos][yPos + 1] <= p[xPos + 1][yPos])
            {
                p[xPos][yPos] = m[xPos][yPos] + p[xPos][yPos + 1];
            }
            else
            {
                p[xPos][yPos] = m[xPos][yPos] + p[xPos + 1][yPos];
            }
        }
    }
    if(xPos != 0 && yPos != 0)
    {
        minSum(xPos - 1, yPos, rows, cols, m, p);
        minSum(xPos, yPos - 1, rows, cols, m, p);
    }
    else if(xPos == 0 && yPos != 0)
    {
        minSum(xPos, yPos - 1, rows, cols, m, p);
    }
    else if(yPos == 0 && xPos != 0)
    {
        minSum(xPos - 1, yPos, rows, cols, m, p);
    }
}

/*
 *  Discovers the number of minimal paths.
 *
 *  @param      xPos            current line on the field matrix.
 *  @param      yPos            current column on the field matrix.
 *  @param      rows            total number of rows in the matrix.
 *  @param      cols            total number of columns in the matrix.
 *  @param      p               matrix with the minimal sum of the costs of the fields from each field to field(n, m), used for the dynamic programming.
 *  @return                     the number of minimal paths.
 */
int numPaths(int xPos, int yPos, int rows, int cols, int **p)
{
    if (xPos == rows - 1 && yPos == cols - 1) return 1;
    else
    {
        int num = 0;
        if(xPos != rows - 1 && p[xPos + 1][yPos] < p[xPos][yPos])
        {
            num += numPaths(xPos + 1, yPos, rows, cols, p);
        }
        if(yPos != cols - 1 && p[xPos][yPos + 1] < p[xPos][yPos])
        {
            num += numPaths(xPos, yPos + 1, rows, cols, p);
        }
        return num;
    }
}