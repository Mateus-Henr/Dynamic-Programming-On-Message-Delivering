#ifndef TP_02_F_H
#define TP_02_F_H
#endif

long int **readFileIntoMatrix(char *filepath, long int *rows, long int *cols);

char *generateRandomFile(long int *rows, long int *cols);

long int **initializeMatrix(long int rows, long int cols);

char *generateRandomFileWithInput(long int *rows, long int *cols, long int *range);

void flushIn();