
#include <stdio.h>
#include <stdlib.h>
#include "graphKernels.h"

int main(int argc, char *argv[]) {
	struct graphData busData = buildGraph(argv[1]);
	printf("Generated graph status = %d\n\n", printGraph(busData));
	short *minDistance = shortestPathUnweightedBFS(busData, 5);
	int i;
	for (i = 0; i < busData.V; i++)
		printf("%hd  ", minDistance[i]);
	printf("\n");
	//printf("Queue status = %d\n", shortestPathUnweightedBFS(busData 0));
	/*
	Infinite Loop ...
	Recheck most recent kernel modifications ...
	Recheck shortestPathUnweightedBFS ...
	*/
	return argc;
}
