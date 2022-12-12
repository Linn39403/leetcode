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

struct TreeNode * BST_pstFindSmallestElement(struct TreeNode * tree)
{
    struct TreeNode * current = tree;
    while((current != NULL) && (current->left)!=NULL)
    {
        current = current->left;
    }
    return current;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key)
{
    if(root == NULL) 
        return root;
    /* if the node to be deleted is smaller than root?, then it's on the left side. */
    if(key < root->val )
    {
        root->left = deleteNode(root->left, key);
    }
    /* if the node to be deleted is larger than root?, then it's on the right side. */
    else if(key > root->val)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        /* node with only one child or no child? */
        if(root->left == NULL)
        {
            struct TreeNode * temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct TreeNode * temp = root->left;
            free(root);
            return temp;
        }
        /* node with no children */
        /* Get the inorder successor ( samllest in the right subtree )*/
        struct TreeNode * temp = BST_pstFindSmallestElement(root->right);
        root->val = temp->val;
        /* Delete the inorder successor node */
        root->right = deleteNode(root->right, temp->val);
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
    struct TreeNode * root = BT_pstCreateTree(3);
    root = BT_pstInsertElement(root, 9);
    root = BT_pstInsertElement(root, 20);
    root = BT_pstInsertElement(root, 15);
    root = BT_pstInsertElement(root, 7);

    printf("Original Tree \r\n"); 
    BST_vPreorderTranversal(root);

    printf("The Tree after deleted 7\r\n");
    root = deleteNode(root,7);
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

