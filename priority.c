#include <stdio.h>
#include <stdlib.h>
/*
struct Node {
	int arivalTime;
	int bursttime;
	int remainingServiceTime;
	int priority;
	struct Node *left, *right;
} *root, *ptr;

int minheapify(struct Node *inserted) {
	return 0;
}

int maxheapify(struct Node *inserted) {
	return 0;
}

int insertIntoHeap(int process) {
	return 0;
}

int deleteFromHeap() {
	return 0;
}

int findMaxPriority() {
	return 0;
}
*/
int main() {
	int numberOfProcess, timeCounter = 0, sum = 0;
	printf("Enter number of processes : \n");
	scanf("%d", &numberOfProcess);

	int arrivalTime[numberOfProcess], priority[numberOfProcess];
	int serviceTime[numberOfProcess], remainingServiceTime[numberOfProcess];

	int i = 0;

	printf("\n");
	for( ; i < numberOfProcess; i++) {
		printf("\nEnter arrival time of process P%d", i + 1);
		scanf("%d", &arrivalTime[i]);

		printf("\nEnter service time of process P%d", i + 1);
		scanf("d", &serviceTime[i]);

		priority[i] = 0;
		remainingServiceTime[i] = serviceTime[i];

		sum += remainingServiceTime[i];
	}


	while(sum--) {

	}



	return 0;
}