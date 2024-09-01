#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
/*
    Given a positive integer n, 
    generate an n x n matrix filled with elements from 1 to n2 in spiral order.
*/
//int ansMatrix[12] = {0};

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

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) 
{
    //allocate memory for the matrix
    int ** ansMatrix = (int**)malloc(sizeof(int*) * (n));
    for(int i = 0 ; i < n; i ++){
        ansMatrix[i] = (int*)malloc(sizeof(int) * (n));
    }
    //allocate memory for returnColumSizes
    *returnColumnSizes = (int*)malloc(sizeof(int)*n);
    *returnSize = n;
    //init the col sizes
    for(int i = 0; i < n; i++){
        (*returnColumnSizes)[i] = n;
    }

    int cnt = 0;
    int top_r = 0, first_c = 0;
    int bot_r = n - 1, last_c = n - 1;  
    do
    {
        //scan top row
        for(int c = top_r; c <= last_c; c++)
        {
            ansMatrix[top_r][c] = ++cnt;
        }
        //inc top_row 
        top_r++;
        if(cnt==n*n) break;

        //scan last col
        for(int r=top_r; r <= bot_r;r++)
        {
            ansMatrix[r][last_c] = ++cnt;
        }
        //dec last col
        last_c--;
        if(cnt==n*n) break;

        //scan last row
        for(int c=last_c; c >= first_c; c--)
        {
            ansMatrix[bot_r][c] = ++cnt;
        }
        //dec last row
        bot_r--;

        //scan first col
        for(int r=bot_r; r >= top_r; r--)
        {
            ansMatrix[r][first_c] = ++cnt;
        }
        //inc first col
        first_c++;

    }while(cnt<n*n);
    return ansMatrix;
}
void myassert(int * iResult, int* iExpected,int size, char * cPtrTestName);
int n = 3;
int returnSize;
int * returnColSizes;
int ** matrix;
int main(void)
{
    matrix = generateMatrix(n, &returnSize, &returnColSizes);

    //print matrix
    for(int r=0; r<returnSize; r++)
    {
        for(int c=0; c<returnColSizes[r]; c++)
        {
            printf("%d ", matrix[r][c]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < n; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    free(returnColSizes);
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

