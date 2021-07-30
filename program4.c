// Round Robin Scheduling (Non - Preemptive)
// Completed

#include <stdio.h>

struct Process{
  int arrivalTime, burstTime, remainingTime, waitingTime, turnAroundTime, completionTime, isCompleted;
};
int currentTime = 0;

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
  int i, done, noOfProcesses, timeQuantum;
  float totalWaitingTime=0, totalTurnAroundTime=0;

  printf("\nEnter no. of processes: ");
  scanf("%d", &noOfProcesses);

  struct Process P[noOfProcesses];

  printf("\nEnter Arrival Time for processes: ");
  for (i = 0; i < noOfProcesses; i++)    
    scanf("%d", &P[i].arrivalTime);

  printf("\nEnter Burst Time for processes: ");
  for (i = 0; i < noOfProcesses; i++){
    scanf("%d", &P[i].burstTime);
    P[i].remainingTime = P[i].burstTime;
    P[i].isCompleted = 0;
  }
  
  printf("\nEnter time Quantum: ");
  scanf("%d", &timeQuantum);

  while (done != 1)
  {
    for (i = 0; i < noOfProcesses; i++)
    {
      if (P[i].remainingTime > 0)
      {
        if (P[i].remainingTime <= timeQuantum)
        {
          currentTime += P[i].remainingTime;
          P[i].completionTime = currentTime;
          P[i].remainingTime = 0;
          P[i].isCompleted = 1;
          P[i].turnAroundTime = P[i].completionTime - P[i].arrivalTime;
          P[i].waitingTime = P[i].turnAroundTime - P[i].burstTime;
          totalWaitingTime += P[i].waitingTime;
          totalTurnAroundTime += P[i].turnAroundTime;
        }
        else
        {
          currentTime += timeQuantum;
          P[i].remainingTime -= timeQuantum;
        }
      }
    }
    done = isAllProcessesCompleted(P, noOfProcesses);
  }

  printf("\nProcess \tArrival Time \tBurst Time \t Waiting Time\t TurnAround Time");
  for (i = 0; i < noOfProcesses; i++)
    printf("\nP%d \t\t %d \t\t %d \t\t %d \t\t %d", i, P[i].arrivalTime, P[i].burstTime, P[i].waitingTime, P[i].turnAroundTime);

  printf("\n\nAverage Waiting Time: %.2f", totalWaitingTime / noOfProcesses);
  printf("\nAverage Turnaround Time: %.2f", totalTurnAroundTime / noOfProcesses);
  printf("\nTotal Execution Time: %d", currentTime);

  return 0;
}
