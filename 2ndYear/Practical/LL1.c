#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

Node *createNode(int val) {
	Node *temp = (Node *) malloc(sizeof(Node));
	if (temp == NULL) {
		printf("Memory full!\n");
		return NULL;
	}
	temp->data = val;
	temp->next = NULL;
	return temp;
}

void insert(Node **left, Node **right, int val) {
	Node *temp = createNode(val);
	if (temp == NULL)
		return;
	if (*left == NULL)
		*left = *right = temp;
	else {
		(*right)->next = temp;
		(*right) = (*right)->next;
	}
}

void searchDelete(Node **left, Node **right, int val) {
	if (*left == NULL) {
		printf("Unsuccessful Search\n");
		return;
	}
	if ((*left)->data == val) {
		Node *temp = *left;
		*left = (*left)->next;
		if (*right == *left)
			*right = NULL;
		free(temp);
		return;
	}
	Node *trav = *left, *temp = NULL;
	while (trav->next != NULL) {
		if (trav->next->data == val) {
			temp = trav->next;
			break;
		}
		trav = trav->next;
	}
	if (temp == NULL) {
		printf("Unsuccessful Search\n");
		return;
	}
	trav->next = trav->next->next;
	if (temp == *right)
		*right = trav;
	free(temp);
}

void print(Node *left, Node *right) {
	if (left == NULL) {
		printf("Empty list.\n");
		return;
	}
	printf("Left Node: %d\n", left->data);
	printf("List elements: ");
	while (left != NULL) {
		printf("%d ", left->data);
		left = left->next;
	}
	printf("\nRight Node: %d\n", right->data);
}

int main() {
	Node *left = NULL, *right = NULL;
	int n, k;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	printf("Enter the values: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		insert(&left, &right, k);
	}
	print(left, right);
	printf("Enter the element to delete: ");
	scanf("%d", &k);
	searchDelete(&left, &right, k);
	print(left, right);
	return 0;
}