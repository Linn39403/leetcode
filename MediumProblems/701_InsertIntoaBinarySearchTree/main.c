#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
/*
    Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
    Return the root node reference (possibly updated) of the BST.
    Basically, the deletion can be divided into two stages:
    Search for a node to remove.
    If the node is found, delete the node.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
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

struct TreeNode* insertIntoBST(struct TreeNode* root, int val)
{
    if(root == NULL)
    {
        struct TreeNode * ptr = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        ptr->val = val;
        ptr->left = NULL;
        ptr->right = NULL;
        return ptr;
    }
    
    if(val < root->val)
    {
        root->left = insertIntoBST(root->left, val);
    }
    else
    {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

void  BST_vPreorderTranversal(struct TreeNode * tree)
{
    if(tree != NULL)
    {
        printf("%d\t", tree->val);
        BST_vPreorderTranversal(tree->left);
        BST_vPreorderTranversal(tree->right);
    }
}
int main(void)
{
    struct TreeNode * root = BT_pstCreateTree(4);
    root = BT_pstInsertElement(root, 2);
    root = BT_pstInsertElement(root, 7);
    root = BT_pstInsertElement(root, 1);
    root = BT_pstInsertElement(root, 3);

    printf("Original Tree \r\n"); 
    BST_vPreorderTranversal(root);

    printf("The Tree after added 5\r\n");
    root = insertIntoBST(root, 5);
    BST_vPreorderTranversal(root);

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

