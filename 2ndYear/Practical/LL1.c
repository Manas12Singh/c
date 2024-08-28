#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
} Node;
Node *createNode(int val)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	if (temp == NULL)
	{
		printf("Memory full!\n");
		return NULL;
	}
	temp->data = val;
	temp->next = NULL;
	return temp;
}
void insert(Node **left, Node **right, int val)
{
	Node *temp = createNode(val);
	if (temp == NULL)
		return;
	if (*left == NULL)
		*left = *right = temp;
	else
		(*right)->next = temp,
		(*right) = (*right)->next;
}
void searchDelete(Node **left, Node **right, int val)
{
	if (*left == NULL)
	{
		printf("Unsuccessful Search\n");
		return;
	}
	if ((*left)->data == val)
	{
		Node *temp = *left;
		if (*right == *left)
			*right = NULL;
		*left = (*left)->next;
		free(temp);
		return;
	}
	Node *trav = *left, *temp = NULL;
	while (trav->next != NULL && trav->next->data != val)
		trav = trav->next;
	if (trav->next == NULL)
	{
		printf("Unsuccessful Search\n");
		return;
	}
	temp = trav->next;
	trav->next = trav->next->next;
	if (temp == *right)
		*right = trav;
	free(temp);
}
void printList(Node *left)
{
	if (left == NULL)
	{
		printf("Empty list.\n");
		return;
	}
	printf("List elements: ");
	while (left != NULL)
	{
		printf("%d ", left->data);
		left = left->next;
	}
	printf("\n");
}
void freeList(Node **head)
{
	while (*head != NULL)
	{
		Node *temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}
int main()
{
	Node *left = NULL, *right = NULL;
	int n, k;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	printf("Enter the values: ");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		insert(&left, &right, k);
	}
	printList(left);
	printf("Enter the element to delete: ");
	scanf("%d", &k);
	searchDelete(&left, &right, k);
	printList(left);
	freeList(&left);
	right = NULL;
	return 0;
}