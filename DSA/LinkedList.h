#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void createList(struct Node **head)
{
    // Check if the list already exists
    if (*head)
    {
        printf("The list already exists!\n");
        return;
    }

    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Check if the number of nodes is valid
    if (n < 1)
    {
        printf("Invalid number.\n");
        return;
    }

    struct Node *trav = NULL;
    printf("Enter the elements:\n");

    // Iterate over the number of nodes provided
    for (int i = 0; i < n; i++)
    {
        // Allocate memory for a new node
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

        // Read the data for the node
        scanf("%d", &(temp->data));

        // Set the next pointer of the node to NULL
        temp->next = NULL;

        // Add the node to the list
        if (*head == NULL)
            *head = trav = temp;
        else
        {
            trav->next = temp;
            trav = trav->next;
        }
    }
}

// Function to print the elements of a linked list
void printList(struct Node *head)
{
    // Check if the linked list is empty
    if (head == NULL)
        printf("List is empty.\n");

    // Traverse the linked list and print each element
    while (head != NULL)
    {
        // Print the data of the current node
        printf("%d ", head->data);

        // Move to the next node in the linked list
        head = head->next;
    }

    // Print a new line after printing all the elements
    printf("\n");
}

void insertInBegin(struct Node **head, int value)
{
    // Allocate memory for a new node
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    // Check if memory allocation was successful
    if (!temp)
    {
        printf("Memory full!\n");
        return;
    }

    // Set the data of the new node to the given value
    temp->data = value;

    // Set the next pointer of the new node to the current head of the linked list
    temp->next = *head;

    // Update the head pointer to point to the new node
    *head = temp;
}

void insertAtEnd(struct Node **head, int value)
{
    // Create a new node
    struct Node *trav = *head, *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        // Check if memory allocation failed
        printf("Memory full!\n");
        return;
    }
    // Assign the value to the new node
    temp->data = value;
    temp->next = NULL;
    if (!*head)
    {
        // If the list is empty, make the new node the head
        *head = temp;
        return;
    }
    // Traverse to the end of the list
    while (trav->next != NULL)
        trav = trav->next;
    // Append the new node to the end of the list
    trav->next = temp;
}

// This function inserts a new node with the given value after the first occurrence of the key value 'k' in the linked list
void insertAfterk(struct Node **head, int value, int k)
{
    // Create a new node and allocate memory for it
    struct Node *trav = *head, *temp = (struct Node *)malloc(sizeof(struct Node));
    // Check if memory allocation was successful
    if (!temp)
    {
        // Print an error message if memory allocation failed
        printf("Memory full!\n");
        return;
    }
    // Set the data value of the new node to the given value
    temp->data = value;
    // Set the next pointer of the new node to NULL
    temp->next = NULL;
    // If the linked list is empty, make the new node the head of the list and return
    if (!*head)
    {
        *head = temp;
        return;
    }
    // Traverse the linked list until the end or until the key value 'k' is found
    while (trav->next != NULL && trav->data != k)
        trav = trav->next;
    // Set the next pointer of the new node to the next node of the current node
    temp->next = trav->next;
    // Set the next pointer of the current node to the new node
    trav->next = temp;
}

// Function to insert a node with a given value before the first occurrence of a given key (k) in a linked list
void insertBeforek(struct Node **head, int value, int k)
{
    // Create a new node
    struct Node *trav = *head, *temp = (struct Node *)malloc(sizeof(struct Node));

    // Check if memory allocation was successful
    if (!temp)
    {
        printf("Memory full!\n");
        return;
    }

    // Set the value of the new node
    temp->data = value;
    temp->next = NULL;

    // If the linked list is empty or the first node has the key value, make the new node the new head
    if (!*head || (*head)->data == k)
    {
        temp->next = *head;
        *head = temp;
        return;
    }

    // Traverse the linked list until the end or until the node with the key value is found
    while (trav->next != NULL)
    {
        // If the next node has the key value, insert the new node before it
        if (trav->next->data == k)
        {
            temp->next = trav->next;
            trav->next = temp;
            return;
        }
        trav = trav->next;
    }

    // If the node with the key value is not found, insert the new node at the beginning of the linked list
    temp->next = *head;
    *head = temp;
}

// Function to delete the first node in a linked list
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

    // Move the head pointer to the next node
    *head = (*head)->next;

    // Free the memory occupied by the first node
    free(temp);
}

void deleteEnd(struct Node **head)
{
    // Check if the list is already empty
    if (!*head)
    {
        printf("List already empty!\n");
        return;
    }

    // Variables to keep track of the current and previous nodes
    struct Node *temp = *head, *trav = *head;

    // Check if there is only one node in the list
    if ((*head)->next == NULL)
    {
        *head = (*head)->next; // Update the head pointer to NULL
        free(temp);            // Free the memory occupied by the node
        return;
    }

    // Traverse the list to find the second-to-last node
    while (trav->next->next != NULL)
        trav = trav->next;

    // Set temp to point to the last node
    temp = trav->next;

    // Set the next pointer of the second-to-last node to NULL
    trav->next = NULL;

    // Free the memory occupied by the last node
    free(temp);
}

// Function to delete a node with value k from a linked list
void deletek(struct Node **head, int k)
{
    // Check if the list is empty
    if (!*head)
    {
        printf("List already empty!\n");
        return;
    }

    // Create temporary nodes
    struct Node *temp, *trav = *head;

    // Check if the first node contains the value k
    if ((*head)->data == k)
    {
        // Assign the head to temp and move the head to the next node
        temp = *head;
        *head = (*head)->next;

        // Free the memory of the deleted node
        free(temp);
    }

    // Traverse the linked list until the next node contains the value k or the end of the list is reached
    while (trav->next != NULL && trav->next->data != k)
        trav = trav->next;

    // Check if a node with value k is found
    if (trav->next != NULL)
    {
        // Assign the next node to temp and update the next pointer of the current node to skip the node with value k
        temp = trav->next;
        trav->next = trav->next->next;

        // Free the memory of the deleted node
        free(temp);
    }
    else
    {
        // Node with value k does not exist in the list
        printf("%d does not exist in the list.\n", k);
    }
}

void deleteAllk(struct Node **head, int k)
{
    // Check if the list is already empty
    if (!*head)
    {
        printf("List already empty!\n");
        return;
    }

    // Initialize a temporary node pointer
    struct Node *temp;

    // Remove all occurrences of 'k' at the beginning of the list
    while (*head != NULL && (*head)->data == k)
    {
        // Store the current head node in 'temp'
        temp = *head;

        // Move the head pointer to the next node
        *head = (*head)->next;

        // Free the memory occupied by the previous head node
        free(temp);
    }

    // Initialize a traversal pointer to the current head node
    struct Node *trav = *head;

    // Remove all occurrences of 'k' in the middle or end of the list
    while (trav && trav->next)
    {
        // Check if the next node contains 'k'
        if (trav->next->data == k)
        {
            // Store the next node in 'temp'
            temp = trav->next;

            // Skip the next node by updating the 'next' pointer
            trav->next = trav->next->next;

            // Free the memory occupied by the node containing 'k'
            free(temp);
        }
        else
        {
            // Move the traversal pointer to the next node
            trav = trav->next;
        }
    }
}

// This function frees the memory allocated for a linked list
void freeList(struct Node **head)
{
    // Check if the current node has a next node
    if ((*head)->next != NULL)
    {
        // If it does, recursively call the function for the next node
        freeList(&((*head)->next));
    }

    // Free the memory allocated for the current node
    free(*head);

    // Set the head pointer to NULL to indicate that the list is now empty
    *head = NULL;
}
