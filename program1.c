// First Come First Serve Scheduling (Non-Preemptive)
//Completed

#include <stdio.h>

struct Process{
  int arrivalTime, burstTime, waitingTime, completionTime, turnAroundTime;
};
int currentTime = 0;

int main()
{
  int noOfProcesses,i;
  float totalWaitingTime=0, totalTurnAroundTime=0;

  printf("\nEnter no. of processes: ");
  scanf("%d", &noOfProcesses);

  struct Process P[noOfProcesses];

  printf("\nEnter Arrival Time for processes: ");
  for (i = 0; i < noOfProcesses; i++)    
    scanf("%d", &P[i].arrivalTime);
  
  printf("\nEnter Burst Time for processes: ");
  for (i = 0; i < noOfProcesses; i++)
    scanf("%d", &P[i].burstTime);

  for (i = 0; i < noOfProcesses; i++)
  {
    currentTime += P[i].burstTime;
    P[i].completionTime = currentTime;
    P[i].turnAroundTime = P[i].completionTime - P[i].arrivalTime;
    P[i].waitingTime = P[i].turnAroundTime - P[i].burstTime;
    totalWaitingTime += P[i].waitingTime;
    totalTurnAroundTime += P[i].turnAroundTime;
  }

  printf("\nProcess \tArrival Time \tBurst Time \t Waiting Time\t TurnAround Time");
  for (i = 0; i < noOfProcesses; i++)
    printf("\nP%d \t\t %d \t\t %d \t\t %d \t\t %d", i, P[i].arrivalTime, P[i].burstTime, P[i].waitingTime, P[i].turnAroundTime);
  printf("\n\nAverage Waiting Time: %.2f", totalWaitingTime / noOfProcesses);
  printf("\nAverage Turnaround Time: %.2f", totalTurnAroundTime / noOfProcesses);
  printf("\nTotal Execution Time: %d", currentTime);

  return 0;
}
