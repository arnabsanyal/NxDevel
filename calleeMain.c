
#include <stdio.h>
#include <stdlib.h>
#include "graphKernels.h"

int main(int argc, char *argv[]) {
	struct graphData busData = buildGraph(argv[1]);
	printf("Generated graph status = %d\n\n", printGraph(busData));
	return 0;
}
