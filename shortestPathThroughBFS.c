
#include <stdio.h>
#include <stdlib.h>
#include "graphKernels.h"

/*================================================================================================================
Structure Definition(s)
================================================================================================================*/

struct queue {
	int nodeNumber;
	struct queue *link;
};

/*================================================================================================================
Variable Definition(s)
================================================================================================================*/

int *nodeList;

/*================================================================================================================
Function Prototype(s)
================================================================================================================*/

int checkEmptyQueue(struct queue *ref);
struct queue* initializeQueue();
int enqueue(struct queue *tail, int newNode);
struct queue* dequeue(struct queue *head);

/*================================================================================================================
Overriding Function Definition(s)
================================================================================================================*/

int checkEmptyQueue(struct queue *ref) {
	if(ref == NULL)
		return 1;
	else
		return 0;
}

struct queue* initializeQueue() {
	struct queue *ptr = (struct queue*)malloc(sizeof(struct queue));
	ptr = NULL;
	return ptr;
}

int enqueue(struct queue *tail, int newNode) {
	struct queue *newEntry = (struct queue*)malloc(sizeof(struct queue));
	newEntry->nodeNumber = newNode;
	newEntry->link = NULL;
	(tail->link).link = newEntry;
	tail->link = newEntry;
	return 1;
}
struct queue* dequeue(struct queue *head) {

}

int shortestPathUnweightedBFS(struct graphData busData, int destination, int source) {
	int shortestDistance = 0;
	return shortestDistance;
}

/*
Incomplete ... 
Enqueue needs attention ...
Dequeue needs attention ...
Test Queue structure ...
Implement BFS ...
Find unweighted graph distance ...
*/