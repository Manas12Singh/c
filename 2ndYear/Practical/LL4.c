#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next, *prev;
} Node;
Node *createNode(Node *prev, Node *next, int val)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	if (temp == NULL)
	{
		printf("Memory full.\n");
		return NULL;
	}
	temp->data = val;
	temp->prev = prev;
	temp->next = next;
	return temp;
}
Node *insert(Node *head, int val)
{
	if (head == NULL)
	{
		Node *temp = createNode(NULL, NULL, val);
		return temp;
	}
	else if (head->next == NULL)
	{
		Node *temp = createNode(head, NULL, val);
		head->next = temp;
	}
	else
		head->next = insert(head->next, val);
	return head;
}
Node *delete(Node *head, int val)
{
	if (head == NULL)
		return NULL;
	if (head->data == val)
	{
		if (head->next != NULL)
			head->next->prev = head->prev;
		Node *temp = head;
		head = head->next;
		free(temp);
	}
	else
		head->next = delete (head->next, val);
	return head;
}
void display(Node *head)
{
	if (head == NULL)
	{
		printf("Empty list.\n");
		return;
	}
	while (head->next != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("%d ", head->data);
	printf("\n");
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
	Node *head = NULL;
	int opt, n;
	do
	{
		printf("Options: \n1. Insert. \n2. Delete. \n3. Display. \n4. Exit.\n");
		printf("Enter your choice (1 to 4): ");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			printf("Enter the value: ");
			scanf("%d", &n);
			head = insert(head, n);
			break;
		case 2:
			printf("Enter value to delete: ");
			scanf("%d", &n);
			head = delete (head, n);
			break;
		case 3:
			display(head);
			break;
		case 4:
			break;
		default:
			printf("Wrong Choice!\n");
		}
	} while (opt != 4);
	freeList(&head);
	return 0;
}