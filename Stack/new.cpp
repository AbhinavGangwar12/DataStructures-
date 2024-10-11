#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a structure to represent a process
typedef struct Process {
    char name;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int response_time;
    int turnaround_time;
} Process;

// Function to simulate Round Robin Scheduling
void roundRobin(Process processes[], int num_processes, int time_quantum) {
    int time = 0; // Current time
    int completed = 0; // Number of completed processes

    // Run the scheduling algorithm until all processes are completed
    while (completed < num_processes) {
        for (int i = 0; i < num_processes; i++) {
            Process *current_process = &processes[i];

            // If the process has arrived and is not completed
            if (current_process->arrival_time <= time && current_process->remaining_time > 0) {
                // Execute the process for the time quantum or until it completes
                int execution_time = (current_process->remaining_time < time_quantum) ? current_process->remaining_time : time_quantum;
                current_process->remaining_time -= execution_time;

                // Update waiting and turnaround times
                current_process->waiting_time += time - current_process->arrival_time;
                time += execution_time;
                current_process->arrival_time = time;
                
                if (current_process->remaining_time == 0) {
                    completed++;
                    current_process->turnaround_time = time;
                }
            }
        }
    }
}

// Function to calculate and print average waiting time and response time
void calculateAndPrintStats(Process processes[], int num_processes) {
    float total_waiting_time = 0;
    float total_turnaround_time = 0;

    printf("Process\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%c\t%d\t%d\n", processes[i].name, processes[i].waiting_time, processes[i].turnaround_time);
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("\nAverage Waiting Time: %.2f\n", total_waiting_time / num_processes);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / num_processes);
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    int num_processes = 4;
    int time_quantum = 2;

    // Create an array of processes
    Process processes[num_processes];

    // Initialize processes with random arrival times and burst times
    for (int i = 0; i < num_processes; i++) {
        processes[i].name = 'P' + i;
        processes[i].arrival_time = rand() % 10; // Adjust the range as needed
        processes[i].burst_time = 1 + rand() % 10; // Adjust the range as needed
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0;
        processes[i].response_time = -1;
    }

    // Call the Round Robin Scheduling function
    roundRobin(processes, num_processes, time_quantum);

    // Calculate and print statistics
    calculateAndPrintStats(processes, num_processes);

    return 0;
}
/*
Now, let's discuss the code and its significance:

Struct Process: In this code, we define a structure Process to represent each process in the scheduling algorithm. This structure contains essential attributes such as the process name, burst time, remaining time, arrival time, waiting time, and turnaround time. These attributes are crucial for tracking the progress of each process and calculating performance metrics.

Round Robin Scheduling Function: The heart of this code is the roundRobin function. It is responsible for implementing the Round Robin scheduling algorithm. Round Robin scheduling assigns a fixed time quantum to each process, ensuring fair allocation of CPU time. The function iterates through the processes, executing them in a round-robin fashion, tracking their remaining time, and updating waiting and turnaround times as needed.

Calculate and Print Statistics: After the scheduling is complete, the calculateAndPrintStats function is called. This function calculates and prints the waiting time and turnaround time for each process. It also computes the average waiting time and turnaround time for all processes. These statistics are essential for evaluating the performance of the scheduling algorithm.

Main Function: The main function serves as the entry point of the program. It sets the number of processes and time quantum, creates an array of processes with their initial attributes, runs the Round Robin scheduling function, and then calculates and prints the statistics. This structure allows you to observe how the scheduling algorithm performs with the given parameters and process data.

Comments and Clarity: To make the code more understandable and maintainable, it's essential to include clear comments. Comments help document the purpose and functionality of each function and segment of the code. This promotes code readability and assists both developers and reviewers in understanding the code's logic.

In this code, we've successfully implemented the Round Robin scheduling algorithm and provided a way to calculate and display important performance metrics. These metrics, such as waiting time and turnaround time, are essential for evaluating the effectiveness of the scheduling algorithm in distributing CPU time fairly among processes. Additionally, comments have been included to improve the code's clarity and maintainability, which is crucial in real-world software development.
*/