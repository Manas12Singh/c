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
        printf("List is empty.\n");

    // Loop through the linked list
    while (head)
    {
        // Print the data of the current node
        printf("%d ", head->data);

        // Move to the next node
        head = head->next;
    }

    // Print a new line after printing all the nodes
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

void freeList(struct Node **head)
{
    // Recursively free the memory allocated for each node in the list
    if ((*head)->next != NULL)
        freeList(&((*head)->next));
    
    // Free the memory allocated for the current node
    free(*head);
    *head = NULL;
}