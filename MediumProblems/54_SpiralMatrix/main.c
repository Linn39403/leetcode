#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
/*
    Given an m x n matrix, return all elements of the matrix in spiral order.
*/
//int ansMatrix[12] = {0};
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    int ansIndx = 0;
    int top_r = 0, first_c = 0;
    int bot_r = matrixSize - 1, last_c = *matrixColSize - 1;    
    int matrixAlloSize = (matrixSize) * (*matrixColSize);
    int *ansMatrix = malloc(sizeof(int) * matrixAlloSize);
    * returnSize = matrixAlloSize;
    do
    {
        //scan top row
        for(int c = top_r; c <= last_c; c++)
        {
            ansMatrix[ansIndx++] = matrix[top_r][c];
        }
        //inc top_row 
        top_r++;
        if(ansIndx==matrixAlloSize) break;

        //scan last col
        for(int r=top_r; r <= bot_r;r++)
        {
            ansMatrix[ansIndx++] = matrix[r][last_c];
        }
        //dec last col
        last_c--;
        if(ansIndx==matrixAlloSize) break;

        //scan last row
        for(int c=last_c; c >= first_c; c--)
        {
            ansMatrix[ansIndx++] = matrix[bot_r][c];
        }
        //dec last row
        bot_r--;

        //scan first col
        for(int r=bot_r; r >= top_r; r--)
        {
            ansMatrix[ansIndx++] = matrix[r][first_c];
        }
        //inc first col
        first_c++;

    }while(ansIndx<matrixAlloSize);
    return ansMatrix;
}
void myassert(int * iResult, int* iExpected,int size, char * cPtrTestName);
int matrix1ColSize = 3;
int matrix1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
int matrix1RetSize = 0;
int expectedAns[9] = {1,2,3,6,9,8,7,4,5};

int matrix2ColSize = 4;
int doubleArr2[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
int matrix2RetSize = 0;
int expectedAns2[12] = {1,2,3,4,8,12,11,10,9,5,6,7};
int main(void)
{
    int *ptr [matrix1ColSize];
    ptr[0] = matrix1[0];
    ptr[1] = matrix1[1];
    ptr[2] = matrix1[2];

    int * ans = spiralOrder(ptr, 3, &matrix1ColSize, &matrix1RetSize);
    myassert(ans,expectedAns, 9, "Testing 3x3 matrix");
    free(ans);

    int *ptr2 [matrix2ColSize];
    ptr2[0] = doubleArr2[0];
    ptr2[1] = doubleArr2[1];
    ptr2[2] = doubleArr2[2];
    int * ans2 = spiralOrder(ptr2, 3, &matrix2ColSize, &matrix2RetSize);
    myassert(ans2,expectedAns2, 12, "Testing 4x3 matrix");
    free(ans2);
    return 0;
}

void printarr(int * arr, int size)
{
    printf("{");
    for(int i=0; i<size-1;i++)
    {
        printf("%d,", arr[i]);
    }
    printf("%d",arr[size-1]);
    printf("}");
}
#if 0 
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
#endif
void myassert(int * iResult, int* iExpected,int size, char * cPtrTestName)
{
    if(memcmp(iResult,iExpected,size) != 0)
    {
        printf("%s. ERROR: Expected = ");
        printarr(iResult,size);
        printf(", Result = ");
        printarr(iExpected, size);
        printf("\n");
    }
    else
    {
        printf("%s. OK : ",cPtrTestName);
        printarr(iResult,size);
        printf("\n");
    }
}

