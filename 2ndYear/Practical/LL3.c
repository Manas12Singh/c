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
Node *insert(Node *head, int val)
{
	if (head == NULL)
		return createNode(val);
	head->next = insert(head->next, val);
	return head;
}
Node *search(Node *head, int val)
{
	while (head != NULL)
	{
		if (head->data == val)
			return head;
		head = head->next;
	}
	return NULL;
}
void freeList(Node **head)
{
	if (*head == NULL)
		return;
	freeList(&((*head)->next));
	free(*head);
	*head = NULL;
}
int main()
{
	int n, k;
	Node *head = NULL;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	printf("Enter the values: ");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		head = insert(head, k);
	}
	printf("Enter the value to search: ");
	scanf("%d", &k);
	Node *node = search(head, k);
	if (node == NULL)
		printf("Value not found.\n");
	else
		printf("Value found.\n");
	freeList(&head);
	return 0;
}