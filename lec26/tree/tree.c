#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/* Counte the number of negative values stored in a tree */
int countNegatives(struct node* root)
{
    int count = 0;


    if(root->left != NULL)
        count += countNegatives(root->left);
    if(root->right!= NULL)
        count += countNegatives(root->right);
    
    if(root->data <0)
        count++;


    return count;
}

int isSameTree(struct node *root1, struct node *root2)
{
    if(root1 == NULL && root2 == NULL)
        return 1;
    else if(root1 != NULL && root2!= NULL)
        return (root1->data == root2->data) && isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right); 
    else
        return 0;
}

void mirror(struct node* root)
{
    if(root == NULL) return;
    else{
        mirror(root->left);
        mirror(root->right);

        struct node *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}


void padding(char ch, int n)
{
    int i;
    for(i=0;i<n;i++)
        putchar(ch);
}
void printTree(struct node *root, int level)
{
    if(root == NULL){
        padding('\t',level);
        printf("*\n");

    }
    else{
        printTree(root->right,level+1);
        padding('\t', level);
        printf("%d\n", root->data);
        printTree(root->left, level+1);
    }
}
