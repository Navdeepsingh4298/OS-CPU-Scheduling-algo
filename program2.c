// Shotest Job First Scheduling (SJF) (Non-Preemptive)
// Completed

#include <stdio.h>

struct Process{
  int arrivalTime, burstTime, waitingTime, allocTime, turnAroundTime, isCompleted;
};
int currentTime = 0;

// Function to get process ID with minBurstTime
int getMinBurstTimePID(struct Process X[], int noOfProcesses){
  int minBurstTime=999, minBurstTimePID;
  for (int i = 1; i < noOfProcesses; i++){
    if((X[i].arrivalTime <= currentTime) && (X[i].isCompleted == 0) && (X[i].burstTime < minBurstTime)){
      minBurstTime = X[i].burstTime;
      minBurstTimePID = i;
    }
  }
  return minBurstTimePID;
}

// Function to check whether all processes completed or not
int isAllProcessesCompleted(struct Process Y[], int noOfProcesses){
  for(int i = 0; i < noOfProcesses; i++){
    if(Y[i].isCompleted != 1)
      return 0;
  }
  return 1;
}


int main(){
  int i, j, done, noOfProcesses;
  float totalWaitingTime, totalTurnAroundTime;

  printf("\nEnter no. of processes: ");
  scanf("%d", &noOfProcesses);

  struct Process P[noOfProcesses];

  printf("\nEnter Arrival Time for processes: ");
  for (i = 0; i < noOfProcesses; i++)    
    scanf("%d", &P[i].arrivalTime);

  printf("\nEnter Burst Time for processes: ");
  for (i = 0; i < noOfProcesses; i++){
    scanf("%d", &P[i].burstTime);
    P[i].isCompleted = 0;
  }
  
  // First process scheduled first because it arrived first in Ready Queue
  currentTime += P[0].burstTime;
  P[0].allocTime = P[0].waitingTime = 0;
  P[0].turnAroundTime = P[0].waitingTime + P[0].burstTime;
  P[0].isCompleted = 1;
  totalWaitingTime = P[0].waitingTime;
  totalTurnAroundTime = P[0].turnAroundTime;

  while(done != 1){
    for (i = 1; i < noOfProcesses; i++){
      j = getMinBurstTimePID(P, noOfProcesses);
      P[j].allocTime = currentTime;
      currentTime += P[j].burstTime;
      P[j].waitingTime = P[j].allocTime - P[j].arrivalTime;
      P[j].turnAroundTime = P[j].waitingTime + P[j].burstTime;
      P[j].isCompleted = 1;
      totalWaitingTime += P[j].waitingTime;
      totalTurnAroundTime += P[j].turnAroundTime;
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
