// Implementing First come Fisrt serve algorithm. 
// suppose we're given 4 process with their burst time and are required to find the waiting time and the turnaround time for each process, and display it on the terminal. 

// process 1 burst time: 10
// process 1 burst time: 4
// process 1 burst time: 12
// process 1 burst time: 6

#include<stdio.h>

int main(){
int num_of_processes = 4;
int wait_time[4]; // an array that stores the wait time for each process. 
int turnaround_time[4];
int burst_time[4]; // an array that stores the burst time for each process. 

// assigning burst time to each process
burst_time[0] = 10;
burst_time[1] = 4;
burst_time[2] = 12;
burst_time[3] = 6;

wait_time[0] = 0;

// a loop will calculate the waiting time 
for(int i = 0; i<num_of_processes; i++){
wait_time[i] = wait_time[i-1]+burst_time[i-1];
}

// a loop will calculate the turnaround time 
for(int i = 0; i<num_of_processes; i++){
turnaround_time[i] = wait_time[i] + burst_time[i];
}

// to display each process with wait time and turnaround time
for(int i = 0; i<num_of_processes; i++){
printf("\nProcess %i: ",i);
printf("Wait Time: %i || ",wait_time[i]);
printf("Turnaround Time: %i\n ",turnaround_time[i]);
}

}
