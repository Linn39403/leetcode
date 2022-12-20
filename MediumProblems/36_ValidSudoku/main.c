#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
void myassert(bool bResult, bool bExpected, char * cPtrTestName);
/*
    Determine if a 9 x 9 Sudoku board is valid. 
    Only the filled cells need to be validated according to the following rules:

    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
    
    Note:
    A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    Only the filled cells need to be validated according to the mentioned rules.
*/

// return -> false if there is any duplication found
bool checkRow(char **board, int cellRow)
{
    char cellArr[10] = {0};
    for(int c=0; c < 9; c++){
        char cell = board[cellRow][c];
        if(cell != '.'){
            char idx = cell-'0';
            if(cellArr[idx] == 0){
                cellArr[idx] = cell;
            }else{ 
                return false;
            }
        }
    }
    return true;
}

bool checkCol(char **board, int cellCol)
{
    char cellArr[10] = {0};
    for(int r=0; r < 9; r++){
        char cell = board[r][cellCol];
        if(cell != '.'){
            char idx = cell-'0';
            if(cellArr[idx] == 0){
                cellArr[idx] = cell;
            }else{
                return false;
            }
        }
    }
    return true;
}

/*
gridNo will be like ( 1 grid will contains 9 cells )
    0 | 1 | 2
    3 | 4 | 5
    6 | 7 | 8
*/
bool checkGrid(char **board, int gridNo)
{
    /* always point to the top left corner */
    int row = ( gridNo / 3 ) * 3;
    int col = ( gridNo % 3 ) * 3;
    char cellArr[10] = {0};
    for(int r = row; r < row+3; r ++){
        for(int c = col; c < col + 3; c++){
            char cell = board[r][c];
            if(cell != '.'){
                char idx = cell-'0';
                if(cellArr[idx] == 0){
                    cellArr[idx] = cell;
                }else{
                    return false;
                }
            }
        }
    }
    return true;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
    for(int n = 0; n < boardSize; n++){
        if( checkRow(board, n) == false ) return false;
        if( checkCol(board, n) == false ) return false;
        if ( checkGrid(board, n) == false ) return false;
    }
    return true;
}

char sudokuArr1[9][9] = 
{{'5','3','.','.','7','.','.','.','.'}
,{'6','.','.','1','9','5','.','.','.'}
,{'.','9','8','.','.','.','.','6','.'}
,{'8','.','.','.','6','.','.','.','3'}
,{'4','.','.','8','.','3','.','.','1'}
,{'7','.','.','.','2','.','.','.','6'}
,{'.','6','.','.','.','.','2','8','.'}
,{'.','.','.','4','1','9','.','.','5'}
,{'.','.','.','.','8','.','.','7','9'}};

char sudokuArr2[9][9] = 
{{'8','3','.','.','7','.','.','.','.'}
,{'6','.','.','1','9','5','.','.','.'}
,{'.','9','8','.','.','.','.','6','.'}
,{'8','.','.','.','6','.','.','.','3'}
,{'4','.','.','8','.','3','.','.','1'}
,{'7','.','.','.','2','.','.','.','6'}
,{'.','6','.','.','.','.','2','8','.'}
,{'.','.','.','4','1','9','.','.','5'}
,{'.','.','.','.','8','.','.','7','9'}};

int main(void)
{
    int boardSize = 9;
    char * cptr[9];
    for(int i=0; i<9;i++)
        cptr[i] = sudokuArr1[i]; 
    myassert(isValidSudoku(cptr, boardSize, &boardSize),true, "Test casea 1");

    for(int i=0; i<9;i++)
        cptr[i] = sudokuArr2[i]; 
    myassert(isValidSudoku(cptr, boardSize, &boardSize),false, "Test casea 2");
    return 0;
}

void myassert(bool bResult, bool bExpected, char * cPtrTestName)
{
    if(bResult != bExpected)
    {
        printf("%s. ERROR\r\n",cPtrTestName);
    }
    else
    {
        printf("%s. OK\r\n",cPtrTestName);
    }
}

