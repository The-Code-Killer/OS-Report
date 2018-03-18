#include <stdio.h>
#include <malloc.h>
struct Node
{
	int cylinder;
	struct Node *next;
} *front, *rear, *ptr;

int queueIt(int cylinderArray[], int size) {
	for(int i = 0; i < size; i++) {
		ptr = (struct Node*) malloc(sizeof(sturct Node));
		ptr -> cylinder = cylinderArray[i];
		ptr -> next = NULL;

		if(rear==NULL) {
			front = rear = ptr;
		}
		else {
			rear -> next = ptr;
			rear = ptr;
		}
	}
	retun 0;
}

int dequeueIt() {
	ptr = front 
	front = front -> next;
	free(ptr);
	return 0;
}

int fcfs(int cylinderArray[], int size) {

}

int main() {
	front = NULL; rear = NULL;
	int numberOfProcess = 9, head = 143, totalDistance = 0;
	int cylinderArray[] = {86, 1470, 913, 1774, 948, 1509, 1022, 1750, 130};

	queueIt(cylinderArray, numberOfProcess);

	totalDistance = fcfs(cylinderArray, numberOfProcess);

	printf("The total distance that the disk arm moves is : %d\n", totalDistance);

	return 0;
}