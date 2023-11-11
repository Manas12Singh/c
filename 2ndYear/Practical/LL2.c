#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *next;
} Node;

Node *createNode(char val)
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

Node* insert(Node *head, char val)
{
	if(head==NULL || head->data>val)
	{
		Node *temp = createNode(val);
		if (temp == NULL)
			return head;
		temp->next=head;
		head=temp;
	} else {
		head->next= insert(head->next,val);
	}
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

int main() {
	char s[100];
	Node *head = NULL;
	printf("Enter the string: ");
	scanf("%s", s);
	int i = 0;
	while (s[i] != '\0')
		head=insert(head, s[i++]);
	print(head);
	return 0;
}