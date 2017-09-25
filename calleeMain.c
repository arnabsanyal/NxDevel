
#include <stdio.h>
#include <stdlib.h>
#include "graphKernels.h"

int main(int argc, char const *argv[]) {
	struct graphData busData = buildGraph(argv[1]);
	printf("Generated graph status = %d\n\n", printGraph(busData));
	//printf("Queue status = %d\n", shortestPathUnweightedBFS(busData, 0, 0));
	return 0;
}
