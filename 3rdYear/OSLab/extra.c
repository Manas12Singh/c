#include <stdio.h>

// Structure to represent a process
struct Process {
    int pid;         // Process ID
    int arrivalTime; // Arrival Time
    int burstTime;   // Burst Time
    int completionTime; // Completion Time
    int waitingTime; // Waiting Time
    int turnaroundTime; // Turnaround Time
};

void findCompletionTime(struct Process proc[], int n) {
    proc[0].completionTime = proc[0].arrivalTime + proc[0].burstTime;
    for (int i = 1; i < n; i++) {
        if (proc[i].arrivalTime > proc[i - 1].completionTime) {
            proc[i].completionTime = proc[i].arrivalTime + proc[i].burstTime;
        } else {
            proc[i].completionTime = proc[i - 1].completionTime + proc[i].burstTime;
        }
    }
}

void findTurnaroundAndWaitingTime(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnaroundTime = proc[i].completionTime - proc[i].arrivalTime;
        proc[i].waitingTime = proc[i].turnaroundTime - proc[i].burstTime;
    }
}

void findAverageTime(struct Process proc[], int n) {
    findCompletionTime(proc, n);
    findTurnaroundAndWaitingTime(proc, n);

    printf("PID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    for (int i = 0; i < n; i++) {
        totalWaitingTime += proc[i].waitingTime;
        totalTurnaroundTime += proc[i].turnaroundTime;
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               proc[i].pid, proc[i].arrivalTime, proc[i].burstTime,
               proc[i].completionTime, proc[i].waitingTime, proc[i].turnaroundTime);
    }

    printf("Average Waiting Time: %.2f\n", (float)totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnaroundTime / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d%d", &proc[i].arrivalTime, &proc[i].burstTime);
        proc[i].pid = i + 1;
    }

    // Sort processes by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (proc[j].arrivalTime > proc[j + 1].arrivalTime) {
                struct Process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }

    findAverageTime(proc, n);
    return 0;
}
