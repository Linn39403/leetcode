#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void myassert(int result, int expected, char * printStr);

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize)
{
    int iWealthArr[50] = {0};
    int iMaxValue = 0;
    for(int i = 0; i < accountsSize; i++)
    {
        for(int j=0; j < *accountsColSize; j++)
        {
            iWealthArr[i] += accounts[i][j];
        }
    }
    iMaxValue = iWealthArr[0];
    for(int i = 1; i < accountsSize; i++)
    {
        iMaxValue = iWealthArr[i] > iMaxValue ? iWealthArr[i] : iMaxValue;
    }
    return iMaxValue;
}

int iAccount1[2][3]={{1,2,3},{3,2,1}};
int iAccount2[3][2]={{1,5},{7,3},{3,5}};
int iAccount3[3][3]={{2,8,7},{7,1,3},{1,9,5}};

int main(void)
{
    int iAccCol = 3;
    int * iPtr1[3];
    iPtr1[0] = iAccount1[0];
    iPtr1[1] = iAccount1[1];
    iPtr1[2] = iAccount1[2];
    myassert(maximumWealth(iPtr1,2,&iAccCol),6,"iAccount1");
    
    iAccCol = 2;
    int * iPtr2[3] = {iAccount2[0],iAccount2[1],iAccount2[2]};
    myassert(maximumWealth(iPtr2,2,&iAccCol),10,"iAccount2");    

    iAccCol = 3;
    int * iPtr3[3] = {iAccount3[0],iAccount3[1],iAccount3[2]};
    myassert(maximumWealth(iPtr3,3,&iAccCol),17,"iAccount3");    
    return 0;
}


void myassert(int result, int expected, char * printStr)
{
    if(expected != result)
    {
        printf("%s ERROR: Expected %d, result =  %d\r\n",printStr,expected, result);
    }
    else
    {
        printf("%s OK: Expected %d, result =  %d\r\n",printStr, expected, result);
    }
}