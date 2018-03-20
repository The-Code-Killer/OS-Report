#include <stdio.h>
#include <stdlib.h>

//Node containing cylinder number and pointer to next node
struct Node
{
	int cylinder;
	struct Node *next;
} *front, *rear, *ptr; //*front pointing to 1st node in the queue and rear pointing to last node in the queue

//function to add node in the queue i.e., cylinders in the ready queue
int queueIt(int cylinderArray[], int size) {
	for(int i = 0; i < size; i++) {
		ptr = (struct Node*) malloc(sizeof(struct Node));
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
	return 0;
}

//function to remove cylinders from the ready queue i.e., deleting nodes from the queue
int dequeueIt() {
	ptr = front;
	front = front -> next;
	free(ptr);
	return 0;
}

//function to count number of disk-arm moves
int fcfs(int head) {
	int sumOfArmMoves = 0;

	while(front != NULL) {
		sumOfArmMoves += abs(head - front -> cylinder);
		head = front -> cylinder;
		dequeueIt();
	}
	return sumOfArmMoves;
}

int main() {
	front = NULL; rear = NULL;
	int numberOfProcess = 9, head = 143, totalDistance = 0;
	int cylinderArray[] = {86, 1470, 913, 1774, 948, 1509, 1022, 1750, 130};

	printf("Position of head : %d\n", head );
	printf("Queue containing cylinder: ");
	for(int i = 0; i < numberOfProcess; i++)
		printf("%d ", cylinderArray[i]);

	queueIt(cylinderArray, numberOfProcess);

	totalDistance = fcfs(head);

	printf("\nThe total distance that the disk arm moves is : %d\n", totalDistance);

	return 0;
}
