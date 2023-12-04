/* 10. Using circular linked list allocate time slots of 10ms for given processes in time sharing Environment and then print which process will be completed in how much time.

Name: Manas Singh
Section: C1
Roll No: 38
Course: B.Tech CSE
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct Process
{
    int id;
    int runtime;
    int timeRemaining;
    int completeTime;
    struct Process *next;
} Process;
Process *createProcess(int id, int runtime)
{
    Process *temp = (Process *)malloc(sizeof(Process));
    temp->id = id;
    temp->runtime = temp->timeRemaining = runtime;
    temp->completeTime = 0;
    temp->next = NULL;
    return temp;
}
void addProcess(Process **head, Process *temp)
{
    if (*head == NULL)
    {
        *head = temp;
        temp->next = *head;
    }
    else
    {
        Process *trav = *head;
        while (trav->next != *head)
            trav = trav->next;
        trav->next = temp;
        temp->next = *head;
    }
}
void run(Process *head)
{
    if (head == NULL)
        return;
    head->timeRemaining = head->runtime;
    Process *curr = head->next;
    while (curr != head)
    {
        curr->timeRemaining = curr->runtime;
        curr = curr->next;
    }
    if (head->next == head)
    {
        head->completeTime = head->timeRemaining;
        head->timeRemaining = 0;
        return;
    }
    int r = 1, time = 0;
    while (r != 0)
    {
        r = 0;
        if (head->timeRemaining > 10)
        {
            time += 10;
            head->timeRemaining -= 10;
            r++;
        }
        else if (head->timeRemaining > 0)
        {
            time += head->timeRemaining;
            head->timeRemaining = 0;
            head->completeTime = time;
            r++;
        }
        Process *curr = head->next;
        while (curr != head)
        {
            if (curr->timeRemaining > 10)
            {
                time += 10;
                curr->timeRemaining -= 10;
                r++;
            }
            else if (curr->timeRemaining > 0)
            {
                time += curr->timeRemaining;
                curr->timeRemaining = 0;
                curr->completeTime = time;
                r++;
            }
            curr = curr->next;
        }
    }
}
void printRuntime(Process *head)
{
    if (head == NULL)
        return;
    printf("Process %d will be completed in %d ms\n", head->id, head->completeTime);
    Process *curr = head->next;
    while (curr != head)
    {
        printf("Process %d will be completed in %d ms\n", curr->id, curr->completeTime);
        curr = curr->next;
    }
}
int main()
{
    Process *head = NULL;
    int opt, id, timeRemaining;
    do
    {
        printf("1. Add a process\n2. Run\n3. Print complete times.\n4. Exit\nEnter your option: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Enter process ID: ");
            scanf("%d", &id);
            printf("Enter time remaining for the process: ");
            scanf("%d", &timeRemaining);
            addProcess(&head, createProcess(id, timeRemaining));
            break;
        case 2:
            run(head);
            break;
        case 3:
            printRuntime(head);
            break;
        case 4:
            break;
        default:
            printf("Invalid option.\n");
        }
    } while (opt != 4);
    return 0;
}

/*
Output:
1. Add a process
2. Run
3. Print complete times.
4. Exit
Enter your option: 1
Enter process ID: 21
Enter time remaining for the process: 30
1. Add a process
2. Run
3. Print complete times.
4. Exit
Enter your option: 1
Enter process ID: 25
Enter time remaining for the process: 40
1. Add a process
2. Run
3. Print complete times.
4. Exit
Enter your option: 1
Enter process ID: 18
Enter time remaining for the process: 20
1. Add a process
2. Run
3. Print complete times.
4. Exit
Enter your option: 1
Enter process ID: 7
Enter time remaining for the process: 45
1. Add a process
2. Run
3. Print complete times.
4. Exit
Enter your option: 2
1. Add a process
2. Run
3. Print complete times.
4. Exit
Enter your option: 3
Process 21 will be completed in 90 ms
Process 25 will be completed in 120 ms
Process 18 will be completed in 70 ms
Process 7 will be completed in 135 ms
1. Add a process
2. Run
3. Print complete times.
4. Exit
Enter your option: 4
*/