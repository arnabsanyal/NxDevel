
#define LINE_SIZE_MAX 32
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct graphData buildGraph(char *sourceFile);
int printList(struct graphData inputGraph);

int main(int argc, char *argv[]) {
	struct graphData busData = buildGraph(argv[1]);
	return 0;
}

struct graphData buildGraph(char *sourceFile) {
	struct graphData populateBus;
	FILE *fp0 = fopen(sourceFile, "r+");
	FILE *fp1 = fopen(sourceFile, "r+");
	populateBus.V = atoi(strtok(sourceFile, "-"));;
	char ch, *parsed, line[LINE_SIZE_MAX];
	populateBus.E = 0;
	while(!feof(fp1)) {
		ch = fgetc(fp1);
		if(ch == '\n')
			populateBus.E++;
	}
	fclose(fp1);
	/*
	Considering initially equal weight graph ... 
	Needs to be modified later ...
	weights field need to be set and the name needs to be checked for w ...
	*/
	populateBus.neighbours = (int *)malloc(populateBus.E * sizeof(int));
	populateBus.offsets = (int *)malloc(populateBus.V * sizeof(int));
	struct pair *rawData = (struct pair *)malloc(populateBus.E * sizeof(struct pair));
	/*
	Let me store the offsets as left indented ...
	Nodes are numbered from 0 ...
	More specifically ith node neighbours are at a offset given at ith position in the array ...
	Store sorted in terms of source vectors in the datatype pair ...
	*/
	populateBus.offsets[0] = 0;

	fclose(fp0);
	return populateBus;
}
