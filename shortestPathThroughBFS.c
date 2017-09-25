
#include <stdio.h>
#include <stdlib.h>
#include "graphKernels.h"

/*===============================================================================================================
Structure Definition(s)
===============================================================================================================*/

struct node {
	int vertex;
	struct node *link;
};

/*===============================================================================================================
Variable Definition(s)
===============================================================================================================*/

short *nodeList;
struct node *head;
struct node *tail;

/*===============================================================================================================
Function Prototype(s)
===============================================================================================================*/

int checkEmptyQueue();
int initializeQueue();
int enqueue(int vertex);
int dequeue();

/*===============================================================================================================
Function Definition(s)
===============================================================================================================*/

int checkEmptyQueue() {
	if((head == NULL) && (tail == NULL))
		return 1;
	else
		return 0;
}

int initializeQueue() {
	head = NULL;
	tail = NULL;
	return 1;
}

int enqueue(int vertex) {
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->vertex = vertex;
	newNode->link = NULL;
	if((head == NULL) && (tail == NULL)) {
		head = tail = newNode;
		return 0;
	}
	tail->link = newNode;
	tail = newNode;
	return 1;
}
int dequeue() {
	struct node *nodeTobeRemoved = head;
	if((head == NULL) && (tail == NULL))
		return -1;
	else
		head = head->link;
	int vertex = nodeTobeRemoved->vertex;
	free(nodeTobeRemoved);
	if(head == NULL)
		tail = NULL;
	return vertex;
}

/*===============================================================================================================
Overriding Function Definition(s)
===============================================================================================================*/

short* shortestPathUnweightedBFS(struct graphData busData, int root) {
	nodeList = (short *)calloc(busData.V, sizeof(short));

	/*
	Root distance inside the return array is -1 ...
	Distance 0 signifies that the point is unreachable ...
	Must think about this further ...
	*/

	initializeQueue();
	enqueue(source);
	nodeList[source - 1] = 1;
	int shortestDistance = 0;
	while(!checkEmptyQueue()) {

	}
	return shortestDistance;
}

/*===============================================================================================================
Temporary Code To Test Linked List
===============================================================================================================

int main()
{
	initializeQueue();
	printf("Status of Queue %d\n", checkEmptyQueue());
	enqueue(2);
	enqueue(5);
	enqueue(3);
	printf("FIFO element %d\n", dequeue());
	printf("Status of Queue %d\n", checkEmptyQueue());
	enqueue(1);
	enqueue(7);
	printf("FIFO element %d\n", dequeue());
	enqueue(8);
	enqueue(6);
	printf("FIFO element %d\n", dequeue());
	enqueue(9);
	printf("FIFO element %d\n", dequeue());
	printf("FIFO element %d\n", dequeue());
	printf("FIFO element %d\n", dequeue());
	printf("Status of Queue %d\n", checkEmptyQueue());
	printf("FIFO element %d\n", dequeue());
	printf("FIFO element %d\n", dequeue());
	printf("Status of Queue %d\n", checkEmptyQueue());
	printf("FIFO element %d\n", dequeue());
	return 0;
}

===============================================================================================================*/

/*
Incomplete ... 
Implement BFS ...
Find unweighted graph distance ...
*/