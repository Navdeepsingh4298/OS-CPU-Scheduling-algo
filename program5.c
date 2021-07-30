// Priority Scheduling (Non-Preemptive)
// Completed

#include <stdio.h>

struct Process{
  int arrivalTime, burstTime, priority, waitingTime, turnAroundTime, completionTime, isCompleted;
};
int currentTime = 0;

// Function to get process ID with highPriority
int getHighPriorityPID(struct Process X[], int noOfProcesses){
  int highPriority = -1, highPriorityPID;
  for (int i = 0; i < noOfProcesses; i++){
    if((X[i].arrivalTime <= currentTime) && (X[i].isCompleted == 0) && (X[i].priority > highPriority)){
      highPriority = X[i].priority;
      highPriorityPID = i;
    }
  }
  return highPriorityPID;
}

// Function to check whether all processes completed or not
int isAllProcessesCompleted(struct Process Y[], int noOfProcesses){
  for(int i = 0; i < noOfProcesses; i++){
    if(Y[i].isCompleted != 1)
      return 0;
  }
  return 1;
}

int main()
{
  int i, j, done, noOfProcesses;
  float totalWaitingTime = 0, totalTurnAroundTime = 0;

  printf("\nEnter no. of processes: ");
  scanf("%d", &noOfProcesses);

  struct Process P[noOfProcesses];

  printf("\nEnter Arrival Time for processes: ");
  for (i = 0; i < noOfProcesses; i++)    
    scanf("%d", &P[i].arrivalTime);

  printf("\nEnter Priority for processes: ");
  for (i = 0; i < noOfProcesses; i++)    
    scanf("%d", &P[i].priority);  

  printf("\nEnter Burst Time for processes: ");
  for (i = 0; i < noOfProcesses; i++){
    scanf("%d", &P[i].burstTime);
    P[i].isCompleted = 0;
  }

  while (done != 1){
    for (i = 0; i < noOfProcesses; i++){
      j = getHighPriorityPID(P, noOfProcesses);
      currentTime += P[j].burstTime;
      P[j].completionTime = currentTime;
      P[j].turnAroundTime = P[j].completionTime - P[j].arrivalTime;
      P[j].waitingTime = P[j].turnAroundTime - P[j].burstTime;
      P[j].isCompleted = 1;
      totalWaitingTime += P[j].waitingTime;
      totalTurnAroundTime += P[j].turnAroundTime;
    }
    done = isAllProcessesCompleted(P, noOfProcesses);
  }

  printf("\nProcess \tArrival Time \tBurst Time \t Priority \t Waiting Time\t TurnAround Time");
  for (i = 0; i < noOfProcesses; i++)
    printf("\nP%d \t\t %d \t\t %d \t\t %d \t\t %d \t\t %d", i, P[i].arrivalTime, P[i].burstTime, P[i].priority, P[i].waitingTime, P[i].turnAroundTime);

  printf("\n\nAverage Waiting Time: %.2f", totalWaitingTime / noOfProcesses);
  printf("\nAverage Turnaround Time: %.2f", totalTurnAroundTime / noOfProcesses);
  printf("\nTotal Execution Time: %d", currentTime);

  return 0;
}
