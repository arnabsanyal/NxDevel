
#ifndef graphKernels_h
#define graphKernels_h

#include <stdio.h>

/*================================================================================================================
Structure Definition(s)
================================================================================================================*/

struct graphData {
	int V;
	int E;
	int* offsets;
	float* weight;
	int* neighbours;
};

struct pair {
	int source;
	int destination;
};

/*================================================================================================================
Function Prototype(s)
================================================================================================================*/

struct graphData buildGraph(char *sourceFile);
int printGraph(struct graphData inputGraph);
int printPairs(struct pair *array, int n);
int shortestPathUnweightedBFS(struct graphData busData, int destination, int source);

#endif
