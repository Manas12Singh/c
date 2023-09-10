#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev, *next;
};

// Function to create a doubly linked list
void createList(struct Node **head)
{
    // Check if the list already exists
    if (*head)
    {
        printf("The list already exists!\n");
        return;
    }

    // Get the number of nodes from the user
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Check if the number of nodes is valid
    if (n < 1)
    {
        printf("Invalid number.\n");
        return;
    }

    // Initialize a traversal pointer
    struct Node *trav = NULL;

    // Loop to create the nodes of the linked list
    for (int i = 0; i < n; i++)
    {
        // Create a new node
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

        // Get the data for the node from the user
        scanf("%d", &(temp->data));

        // Set the next pointer of the node to NULL
        temp->next = NULL;

        // Check if the head pointer is NULL
        if (!*head)
        {
            // If the head pointer is NULL, set the head and traversal pointers to the new node
            *head = trav = temp;

            // Set the previous pointer of the new node to NULL
            temp->prev = NULL;
        }
        else
        {
            // If the head pointer is not NULL, set the next and previous pointers of the traversal pointer and move the traversal pointer forward
            trav->next = temp;
            temp->prev = trav;
            trav = trav->next;
        }
    }
}

// Function to print the linked list
void printList(struct Node *head)
{
    // Check if the list is empty
    if (!head)
    {
        printf("List is empty.\n");
        return;
    }

    // Loop through the linked list
    while (head->next)
    {
        // Print the data of the current node
        printf("%d ", head->data);

        // Move to the next node
        head = head->next;
    }
    printf("%d ", head->data);
    // Print a new line after printing all the nodes
    printf("\nReverse: ");
    while (head)
    {
        printf("%d ", head->data);
        head = head->prev;
    }
    printf("\n");
}

void insertAtBegin(struct Node **head, int val)
{
    // Allocate memory for a new node
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    // Check if memory allocation was successful
    if (!temp)
    {
        // Print an error message if memory is full
        printf("Memory full!\n");
        return;
    }

    // Set the data of the new node to the given value
    temp->data = val;

    // Set the previous pointer of the new node to NULL
    temp->prev = NULL;

    // Set the next pointer of the new node to the current head
    temp->next = *head;

    // If the current head exists
    if (*head)
    {
        // Set the previous pointer of the current head to the new node
        (*head)->prev = temp;
    }

    // Set the head pointer to the new node
    *head = temp;
}

// Function to insert a node at the end of a doubly linked list
void insertAtEnd(struct Node **head, int val)
{
    // Allocate memory for the new node
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        // Print an error message if memory allocation fails
        printf("Memory full!\n");
        return;
    }

    // Set the value of the new node
    temp->data = val;
    temp->next = NULL;

    // If the list is empty, make the new node the head of the list
    if (!*head)
    {
        temp->prev = NULL;
        *head = temp;
        return;
    }

    // Traverse to the end of the list
    struct Node *trav = *head;
    while (trav->next)
        trav = trav->next;

    // Insert the new node at the end of the list
    trav->next = temp;
    temp->prev = trav;
}

void insertAfterk(struct Node **head, int val, int k)
{
    // Allocate memory for a new node
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        // If memory allocation fails, print an error message and return
        printf("Memory full!\n");
        return;
    }

    // Set the value of the new node to the given value
    temp->data = val;

    // If the list is empty, make the new node the head of the list
    if (!*head)
    {
        *head = temp;
        temp->next = temp->prev = NULL;
        return;
    }

    // Traverse the list to find the node with the value k
    struct Node *trav = *head;
    while (trav->next && trav->data != k)
        trav = trav->next;

    // Insert the new node after the node with the value k
    temp->prev = trav;
    temp->next = trav->next;
    if (trav->next)
        trav->next->prev = temp;
    trav->next = temp;
}

void insertBeforek(struct Node **head, int val, int k)
{
    // Allocate memory for a new node
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        // Print an error message if memory allocation fails
        printf("Memory full!\n");
        return;
    }

    // Assign the given value to the data field of the new node
    temp->data = val;

    // If the list is empty, make the new node the head of the list
    if (!*head)
    {
        temp->next = temp->prev = NULL;
        *head = temp;
        return;
    }

    // Traverse the list to find the node with data equal to k
    struct Node *trav = *head;
    while (trav->next != NULL)
    {
        if (trav->next->data == k)
        {
            // Insert the new node before the node with data equal to k
            temp->next = trav->next;
            trav->next->prev = temp;
            trav->next = temp;
            temp->prev = trav;
            return;
        }
        trav = trav->next;
    }

    // If the node with data equal to k is not found, insert the new node at the beginning of the list
    temp->next = *head;
    temp->prev = NULL;
    (*head)->prev = temp;
    *head = temp;
}

// Function to delete the first node in a doubly linked list
void deleteBegin(struct Node **head)
{
    // Check if the list is already empty
    if (!*head)
    {
        printf("List already empty!\n");
        return;
    }

    // Store the address of the first node in a temporary variable
    struct Node *temp = *head;

    // Update the head pointer to point to the next node
    *head = (*head)->next;

    // Update the previous pointer of the new head, if it exists
    if (*head)
        (*head)->prev = NULL;

    // Free the memory occupied by the first node
    free(temp);
}

// Function to delete the last node from a doubly linked list
void deleteEnd(struct Node **head)
{
    // Check if the list is empty
    if (!*head)
    {
        printf("List already empty!\n");
        return;
    }

    struct Node *temp;

    // Check if there is only one node in the list
    if ((*head)->next == NULL)
    {
        temp = *head;
        *head = NULL;
        free(temp);
        return;
    }

    struct Node *trav = *head;

    // Traverse to the last node of the list
    while (trav->next)
        trav = trav->next;

    // Store the last node in a temporary variable
    temp = trav;

    // Update the second-to-last node's next pointer to NULL
    trav->prev->next = NULL;

    // Free the memory of the last node
    free(temp);
}

void deletek(struct Node **head, int k)
{
    // Check if the head is NULL, indicating an empty linked list
    if (!*head)
        return;

    struct Node *temp;

    // Check if the data of the head node is equal to k
    if ((*head)->data == k)
    {
        // If so, update the head to the next node
        temp = *head;
        *head = (*head)->next;

        // Update the previous pointer of the new head to NULL
        if (*head)
            (*head)->prev = NULL;

        // Free the memory of the old head node
        free(temp);
        return;
    }

    struct Node *trav = *head;

    // Traverse the linked list until the node with data equal to k is found
    while (trav && trav->data != k)
        trav = trav->next;

    if (trav)
    {
        temp = trav;

        // Update the next pointer of the previous node to skip the current node
        trav->prev->next = trav->next;

        // Update the previous pointer of the next node to skip the current node
        if (trav->next)
            trav->next->prev = trav->prev;

        // Free the memory of the current node
        free(temp);
    }
}

void deleteAllk(struct Node **head, int k)
{
    // Check if head is NULL, i.e., if the list is empty
    if (!*head)
        return;

    struct Node *temp, *trav = *head;

    // Iterate through the list
    while (trav)
    {
        // Check if the data of the current node is equal to k
        if (trav->data == k)
        {
            // If the current node's next pointer is not NULL, update the next node's prev pointer
            if (trav->next)
                trav->next->prev = trav->prev;

            // If the current node's prev pointer is not NULL, update the prev node's next pointer
            if (trav->prev)
                trav->prev->next = trav->next;

            // If the current node is the head, update the head pointer to the next node
            if (trav == *head)
                *head = trav->next;

            temp = trav;
            trav = trav->next;
            free(temp);
        }
        else
            trav = trav->next;
    }
}

void freeList(struct Node **head)
{
    // Recursively free the memory allocated for each node in the list
    if ((*head)->next != NULL)
        freeList(&((*head)->next));

    // Free the memory allocated for the current node
    free(*head);
    *head = NULL;
}