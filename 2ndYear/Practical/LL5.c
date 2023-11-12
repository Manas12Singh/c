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

void delete(Node **head, int val)
{
	if (*head == NULL)
		return;
	Node *temp, *trav = *head;
	if ((*head)->data == val)
	{
		temp = *head;
		if ((*head)->next == *head)
			*head = NULL;
		else
		{
			while (trav->next != *head)
				trav = trav->next;
			trav->next = (*head)->next;
			*head = (*head)->next;
		}
		free(temp);
		return;
	}
	while (trav->next->data != val && trav->next != *head)
		trav = trav->next;
	temp = trav->next;
	trav->next = trav->next->next;
	free(temp);
}

void display(Node *head)
{
	if (head == NULL)
	{
		printf("Empty list.\n");
		return;
	}
	Node *trav = head;
	do
	{
		printf("%d ", trav->data);
		trav = trav->next;
	} while (trav != head);
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
	while (1)
	{
		int opt, n;
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
			delete (&head, n);
			break;
		case 3:
			display(head);
			break;
		case 4:
			freeList(&head);
			return 0;
		default:
			printf("Wrong Choice!\n");
		}
	}
}