//
// Created by Deepanshu Dhami on 16-11-2023.
//

#ifndef STDIO_H
#include <stdio.h>
#endif

#ifndef STDLIB_H
#include <stdlib.h>
#endif

#ifndef STACK_H
#include "mystack.h"
#endif

#ifndef C_BINARYTREE_H
#define C_BINARYTREE_H

//structure definition
typedef struct treeNode
{
	int data;
	struct treeNode *left,*right;
} TreeNode;

//depth first search traversal
void preorder(TreeNode* root);
void inorder(TreeNode* root);
void postorder(TreeNode* root);

//breadth first search traversal
void breadthFirstSearch(TreeNode *root);

#endif //C_BINARYTREE_H
