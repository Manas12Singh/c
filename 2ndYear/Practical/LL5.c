#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
} Node;
Node *createNode(Node *next, int val)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	if (temp == NULL)
	{
		printf("Memory full.\n");
		return NULL;
	}
	temp->data = val;
	temp->next = next;
	return temp;
}
void insert(Node **head, int val)
{
	Node *temp = createNode(*head, val);
	if (*head == NULL)
	{
		*head = temp;
		temp->next = temp;
		return;
	}
	Node *trav = *head;
	while (trav->next != *head)
		trav = trav->next;
	trav->next = temp;
}
void deleteNode(Node **head, int val)
{
	if (*head == NULL)
		printf("Empty list.\n");
	Node *curr = *head;
	Node *prev = NULL;
	while (curr->data != val)
	{
		if (curr->next == *head)
		{
			printf("Node not found.\n");
			return;
		}
		prev = curr;
		curr = curr->next;
	}
	if (curr == *head)
	{
		if (curr->next == *head)
		{
			free(curr);
			*head = NULL;
			return;
		}
		Node *last = *head;
		while (last->next != *head)
			last = last->next;
		last->next = curr->next;
		*head = curr->next;
	}
	else
	{
		prev->next = curr->next;
		free(curr);
	}
}
void display(Node *head)
{
	if (head == NULL)
	{
		printf("Empty list.\n");
		return;
	}
	printf("List: %d ", head->data);
	Node *trav = head->next;
	while (trav != head)
	{
		printf("%d ", trav->data);
		trav = trav->next;
	}
	printf("\n");
}
void freeList(Node **head)
{
	if (*head == NULL)
		return;
	if ((*head)->next == *head)
	{
		free(*head);
		*head = NULL;
		return;
	}
	Node *temp, *trav = (*head)->next;
	while (trav != *head)
	{
		temp = trav;
		trav = trav->next;
		free(temp);
	};
	free(trav);
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
			insert(&head, n);
			break;
		case 2:
			printf("Enter value to delete: ");
			scanf("%d", &n);
			deleteNode(&head, n);
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