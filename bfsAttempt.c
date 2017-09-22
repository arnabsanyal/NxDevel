
#define LINE_SIZE_MAX 32
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/*================================================================================================================
Function Definition(ks)
================================================================================================================*/

int main(int argc, char *argv[]) {
	struct graphData busData = buildGraph(argv[1]);
	printf("Generated graph status = %d\n\n", printGraph(busData));
	return 0;
}

struct graphData buildGraph(char *sourceFile) {
	struct graphData populateBus;
	FILE *fp0 = fopen(sourceFile, "r+");
	FILE *fp1 = fopen(sourceFile, "r+");
	populateBus.V = atoi(strtok(sourceFile, "-"));;
	char ch, *parsed, line[LINE_SIZE_MAX];
	int counter;
	populateBus.E = 1;
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
	populateBus.offsets = (int *)calloc(populateBus.V, sizeof(int));
	struct pair *rawData = (struct pair *)malloc(populateBus.E * sizeof(struct pair));

	/*
	Let me store the offsets as left indented ...
	Nodes are numbered from 0 ...
	More specifically ith node neighbours are at a offset given at ith position in the array ...
	Store sorted in terms of source vectors in the datatype pair ...
	*/

	populateBus.offsets[0] = 0;
	counter = 0;
	while(!feof(fp0)) {
		fgets(line, LINE_SIZE_MAX, fp0);
		parsed = strtok(line, ",");
		rawData[counter].source = atoi(parsed);
		while(parsed != NULL) {
			parsed = strtok(NULL, ",");
			rawData[counter].destination = (parsed != NULL) ? atoi(parsed) : rawData[counter].destination;
		}
		counter++;
	}

	/*
	Input file cannot have trailing newLine as of now ...
	Hence populateBus.E start as 1 ...
	Address these issues ... 
	*/

	printPairs(rawData, populateBus.E);
	fclose(fp0);
	counter = 0;
	while(counter < populateBus.E) {
		populateBus.neighbours[counter] = rawData[counter].destination;
		if(rawData[counter].source < populateBus.V)
			populateBus.offsets[rawData[counter++].source]++;
	}
	/*
	Compounding offsets ...
	Checking for Absent nodes ...
	Checking last node separately ... 
	*/
	counter = 1;
	while(counter < populateBus.V) {
		populateBus.offsets[counter] += populateBus.offsets[counter - 1];
		counter++;
	}
	counter = 0;
	while(counter < (populateBus.V - 1)) {
		populateBus.offsets[counter] =\
		 (populateBus.offsets[counter] == populateBus.offsets[counter + 1]) ? -1 : populateBus.offsets[counter];
		 counter++;
	}
	if(populateBus.offsets[populateBus.V - 1] >= populateBus.E)
		populateBus.offsets[populateBus.V - 1] = -1;
	return populateBus;
}

int printPairs(struct pair *array, int n) {
	int i;
	printf("Source File assimilated\n\n");
	for (i = 0; i < n; i++)
		printf("%d, %d\n", array[i].source, array[i].destination);
	printf("\n");
	return 0;
}

int printGraph(struct graphData inputGraph) {
	int i;
	printf("Number of Nodes %d\n", inputGraph.V);
	printf("Number of Edges %d\n", inputGraph.E);
	printf("Printing Graph in CSR format\n\nNeighbours:\n");
	for (i = 0; i < inputGraph.E; i++)
		printf("%d  ", inputGraph.neighbours[i]);
	printf("\nOffsets:\n");
	for (i = 0; i < inputGraph.V; i++)
		printf("%d  ", inputGraph.offsets[i]);
	printf("\n");
	return 1;
}
