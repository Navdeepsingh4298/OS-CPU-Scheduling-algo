// First Come First Serve Scheduling (Non-Preemptive)
//Completed

#include <stdio.h>

struct Process{
  int burstTime, waitingTime, turnAroundTime;
};

int main()
{
  int noOfProcesses,i;
  float totalWaitingTime, totalTurnAroundTime;

  printf("\nEnter no. of processes: ");
  scanf("%d", &noOfProcesses);

  struct Process P[noOfProcesses];
  
  printf("\nEnter Burst Time for processes: ");
  for (i = 0; i < noOfProcesses; i++)
    scanf("%d", &P[i].burstTime);

  P[0].waitingTime = totalWaitingTime = 0;
  P[0].turnAroundTime = totalTurnAroundTime = P[0].burstTime;
  for (i = 1; i < noOfProcesses; i++)
  {
    P[i].waitingTime = P[i - 1].turnAroundTime - i;
    P[i].turnAroundTime = P[i].waitingTime + P[i].burstTime;
    totalWaitingTime += P[i].waitingTime;
    totalTurnAroundTime += P[i].turnAroundTime;
  }

  printf("\nProcess \tBurst Time \t Waiting Time\t TurnAround Time");
  for (i = 0; i < noOfProcesses; i++)
    printf("\nP%d \t\t %d \t\t %d \t\t %d", i, P[i].burstTime, P[i].waitingTime, P[i].turnAroundTime);
  printf("\n\nAverage Waiting Time: %.2f", totalWaitingTime / noOfProcesses);
  printf("\nAverage Turnaround Time: %.2f", totalTurnAroundTime / noOfProcesses);

  return 0;
}
