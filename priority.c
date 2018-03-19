#include <stdio.h>
#include <stdlib.h>

struct Node {
	int remainingServiceTime;
	int priority;
	struct Node *left, *right;
} *root;
