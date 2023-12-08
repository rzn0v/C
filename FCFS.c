#include <stdio.h>

struct Process {
    int id;             // Process ID
    int arrival_time;   // Arrival time of the process
    int burst_time;     // Burst time (execution time) of the process
    int completion_time; // Completion time of the process
};

// Function to calculate completion times for processes using FCFS
void calculateCompletionTimes(struct Process processes[], int n) {
    int completion_time = 0;

    for (int i = 0; i < n; ++i) {
        // If the process has arrived, update completion time
        if (processes[i].arrival_time <= completion_time) {
            processes[i].completion_time = completion_time + processes[i].burst_time;
            completion_time = processes[i].completion_time;
        } else {
            // If the process hasn't arrived, wait for it to arrive
            completion_time = processes[i].arrival_time + processes[i].burst_time;
            processes[i].completion_time = completion_time;
        }
    }
}

// Function to calculate turnaround time and waiting time for each process
void calculateTurnaroundTimes(struct Process processes[], int n, int turnaround_times[], int waiting_times[]) {
    for (int i = 0; i < n; ++i) {
        turnaround_times[i] = processes[i].completion_time - processes[i].arrival_time;
        waiting_times[i] = turnaround_times[i] - processes[i].burst_time;
    }
}

// Function to display the result
void displayResult(struct Process processes[], int n, int turnaround_times[], int waiting_times[]) {
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < n; ++i) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].id, processes[i].arrival_time, processes[i].burst_time,
               processes[i].completion_time, turnaround_times[i], waiting_times[i]);
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input the arrival time and burst time for each process
    for (int i = 0; i < n; ++i) {
        processes[i].id = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }

    // Sort the processes based on arrival time (assuming processes can arrive in any order)
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Calculate completion times for processes
    calculateCompletionTimes(processes, n);

    // Calculate turnaround time and waiting time for each process
    int turnaround_times[n];
    int waiting_times[n];
    calculateTurnaroundTimes(processes, n, turnaround_times, waiting_times);

    // Display the result
    displayResult(processes, n, turnaround_times, waiting_times);

    return 0;
}
