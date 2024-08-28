#include "BinaryTree.h"

void preorder(TreeNode *root)
{
	if (root == NULL)
		return;
	printf("%d", root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(TreeNode *root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	printf("%d", root->data);
	inorder(root->right);
}

void postorder(TreeNode *root)
{
	if (root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d", root->data);
}

void breadthFirstSearch(TreeNode *root)
{
	if (root == NULL)
		return;
	Stack *s1 = createStack(sizeof(TreeNode *));
	Stack *s2 = createStack(sizeof(TreeNode *));
	push(s1, root);
	while (!isEmpty(s1) || !isEmpty(s2))
	{
		while (!isEmpty(s1))
		{
			TreeNode *n = (TreeNode *)top(s1);
			if (n->left != NULL)
				push(s2, n->left);
			if (n->right != NULL)
				push(s2, n->right);
			printf("%d ", n->data);
			pop(s1);
		}
		while (!isEmpty(s2))
		{
			TreeNode *n = (TreeNode *)top(s2);
			if (n->right != NULL)
				push(s1, n->right);
			if (n->left != NULL)
				push(s1, n->left);
			printf("%d ", n->data);
			pop(s2);
		}
	}
}