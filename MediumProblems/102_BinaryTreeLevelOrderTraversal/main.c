#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
struct TreeNode
{
    int val;
    struct TreeNode * left;
    struct TreeNode * right;
}TreeNode;

struct TreeNode* BT_pstCreateTree(int data)
{
    struct TreeNode * ptr = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    assert(ptr != NULL);
    
    ptr->val = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

struct TreeNode* BT_pstInsertElement(struct TreeNode * tree, int data)
{
    if(tree == NULL){
        tree = BT_pstCreateTree(data);
        return tree;
    }   
    if(data < tree->val){
        tree->left = BT_pstInsertElement(tree->left, data);
    }
    else{
        tree->right = BT_pstInsertElement(tree->right, data);
    }
    return tree;
}

int BT_i32GetHeight(struct TreeNode * tree)
{
    if(tree == NULL){
        return 0;
    }
    int leftHeight = BT_i32GetHeight(tree->left);
    int rightHeight = BT_i32GetHeight(tree->right);
    if(leftHeight > rightHeight){
        return (leftHeight+1);
    }
    return (rightHeight+1);
}

void BST_vTravereseByLevel(struct TreeNode* tree,int ** result, int * col, int level)
{
    if(tree == NULL)
    {
        return;
    }
    result[level][col[level]++] = tree->val;
    BST_vTravereseByLevel(tree->left, result, col, level+1);
    BST_vTravereseByLevel(tree->right, result, col, level+1);
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    int row = BT_i32GetHeight(root); //this will be rows
    * returnSize = row; 

    // result is the array of array
    int ** result = (int **) malloc((row) * sizeof(int*));

    for(int i=0; i<row;i++){
        result[i] = (int *) calloc(1024, sizeof(int));
    }

    //size in each level
    *returnColumnSizes = (int*) calloc(row,sizeof(int*));    

    BST_vTravereseByLevel(root, result, *returnColumnSizes, 0);
    return result;
}


int main(void)
{
    struct TreeNode * root = BT_pstCreateTree(3);
    root = BT_pstInsertElement(root, 9);
    root = BT_pstInsertElement(root, 20);
    root = BT_pstInsertElement(root, 15);
    root = BT_pstInsertElement(root, 7);
    int retRowSize;
    int * retColSize;
    int ** ans = levelOrder(root, &retRowSize, &retColSize);
    for(int i=0; i< retRowSize; i++){
        for(int j=0; j < retColSize[i]; j++){
            printf("%d\t",ans[i][j]);
        }
        printf("\r\n");
    }
    free(retColSize);
    free(ans);
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

