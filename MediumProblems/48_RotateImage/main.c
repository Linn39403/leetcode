#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
void printMatrix(int ** matrix, int matrixSize)
{
    printf("\r\n");    
    for(int r=0; r<matrixSize; r++)
    {
        for(int c=0; c<matrixSize;c++)
        {
            printf("%2d ", matrix[r][c]);
        }
        printf("\r\n");
    }
}
void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    int msize = matrixSize-1;
    for(int r=0; r<(matrixSize/2); r++)
    {
        for(int c=r; c<*matrixColSize-1-r;c++)
        {
            int x = matrix[c][r];
            matrix[c][r] = matrix[msize-r][c]; 
            matrix[msize-r][c] = matrix[msize-c][msize-r]; 
            matrix[msize-c][msize-r] = matrix[r][msize-c];   
            matrix[r][msize-c] = x;      
        }
    } 
}
//printMatrix(matrix,matrixSize);
int matrixSize = 3;
int doubleArr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

int matrixSize2 = 4;
int doubleArr2[4][4] = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
int main(void)
{
    int *ptr [3];
    ptr[0] = doubleArr[0];
    ptr[1] = doubleArr[1];
    ptr[2] = doubleArr[2];
    rotate(ptr, matrixSize,&matrixSize);

    int *ptr2 [4];
    ptr2[0] = doubleArr2[0];
    ptr2[1] = doubleArr2[1];
    ptr2[2] = doubleArr2[2];
    ptr2[3] = doubleArr2[3];
    rotate(ptr2, matrixSize2,&matrixSize2);
    return 0;
}

void myassert(int iResult, int iExpected, char * cPtrTestName)
{
    if(iResult != iExpected)
    {
        printf("%s. ERROR: Expected %d, result =  %d\r\n",cPtrTestName, iExpected, iResult);
    }
    else
    {
        printf("%s. OK: Expected %d, result =  %d\r\n",cPtrTestName, iExpected, iResult);
    }
}

