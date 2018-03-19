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
int mergesortUser(int arrivalTime[], int serviceTime[], int remainingServiceTime[], int beg, int end) {
	if(beg == end)
		return 0;
	int mid = (beg + end) / 2;
	mergesortUser(arrivalTime, serviceTime, remainingServiceTime, beg, mid);
	mergesortUser(arrivalTime, serviceTime, remainingServiceTime, mid + 1, end);
	mergeUser(arrivalTime, serviceTime, remainingServiceTime, beg, mid, end);

	return 0;
}

int mergeUser(int arrivalTime[], int serviceTime[], int remainingServiceTime[], int beg, int mid, int end) {
	int i = beg, j = mid + 1, k = 0;
	int tempArrival[end - beg + 1], tempService[end - beg + 1], tempRemaining[end - beg + 1];	

	while(i <= mid && j <= end) {
		if(arrivalTime[i] < arrivalTime[j]) {
			tempArrival[k] = arrivalTime[i];
			tempService[k] = serviceTime[i];
			tempRemaining[k] = remainingServiceTime[i];
			i++;
		}
		else {
			tempArrival[k] = arrivalTime[j];
			tempService[k] = serviceTime[j];
			tempRemaining[k] = remainingServiceTime[j];
			j++;
		}
		k++;
	}

	if(i > mid) {
		while(j <= end){
			tempArrival[k] = arrivalTime[j];
			tempService[k] = serviceTime[j];
			tempRemaining[k] = remainingServiceTime[j];
			j++; k++;
		}
	}
	else {
			tempArrival[k] = arrivalTime[i];
			tempService[k] = serviceTime[i];
			tempRemaining[k] = remainingServiceTime[i];
			i++; k++;
	}

	for(i = beg, k = 0; i <= end; i++, k++) {
		arrivalTime[i] = tempArrival[k];
		serviceTime[i] = tempService[k];
		remainingServiceTime[i] = tempRemaining[k];
	}

	return 0;
}

int main() {
	int numberOfProcess, timeCounter = 0, sum = 0;
	printf("Enter number of processes : \n");
	scanf("%d", &numberOfProcess);

	int arrivalTime[numberOfProcess], priority[numberOfProcess];
	int serviceTime[numberOfProcess], remainingServiceTime[numberOfProcess];

	int i = 0;

	printf("\n");
	for( ; i < numberOfProcess; i++) {
		printf("\nEnter arrival time of process P%d ", i + 1);
		scanf("%d", &arrivalTime[i]);

		printf("\nEnter service time of process P%d ", i + 1);
		scanf("%d", &serviceTime[i]);

		priority[i] = 0;
		remainingServiceTime[i] = serviceTime[i];

		sum += remainingServiceTime[i];
	}

	mergesortUser(arrivalTime, serviceTime, remainingServiceTime, 0, numberOfProcess - 1);

	/*for(i = 0; i < numberOfProcess; i++) {
		printf("%d ", arrivalTime[i] );
	}
	printf("\n");
	for(i = 0; i < numberOfProcess; i++) {
		printf("%d ", serviceTime[i] );
	}
	printf("\n");
	for(i = 0; i < numberOfProcess; i++) {
		printf("%d ", remainingServiceTime[i] );
	}*/

	/*while(sum--) {

	}*/



	return 0;
}