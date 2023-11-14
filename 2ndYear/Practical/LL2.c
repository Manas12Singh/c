#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	char data;
	struct node *next;
} Node;
Node *createNode(Node *next, char val)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	if (temp == NULL)
	{
		printf("Memory full!\n");
		return NULL;
	}
	temp->data = val;
	temp->next = next;
	return temp;
}
Node *insert(Node *head, char val)
{
	if (head == NULL || head->data > val)
	{
		Node *temp = createNode(head, val);
		if (temp == NULL)
			return head;
		head = temp;
	}
	else
		head->next = insert(head->next, val);
	return head;
}
void print(Node *head)
{
	if (head == NULL)
	{
		printf("Empty list.\n");
		return;
	}
	printf("List elements: ");
	while (head != NULL)
	{
		printf("%c ", head->data);
		head = head->next;
	}
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
	char s[100];
	Node *head = NULL;
	printf("Enter the string: ");
	scanf("%s", s);
	int i = 0;
	while (s[i] != '\0')
		head = insert(head, s[i++]);
	print(head);
	freeList(&head);
	return 0;
}