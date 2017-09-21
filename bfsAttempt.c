
#define LINE_SIZE_MAX 32
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct linkedList {
	int destNode;
	float weight;
	struct linkedList *nextPtr;
};

struct linkedList* buildAdjacencyList(struct linkedList* pointerInput, FILE *sourceFile);
int printList(struct linkedList * pointerInput);

int main(int argc, char *argv[]) {
	FILE *fp;
	fp = fopen(argv[1], "r+");
	int n = atoi(strtok(argv[1],"-"));
	int *nodeList = (int *)malloc(n * sizeof(int));
	struct linkedList *adjacencyList = (struct linkedList *)malloc(n * sizeof(struct linkedList));
	adjacencyList = buildAdjacencyList(adjacencyList, fp);
 	fclose(fp);
}

struct linkedList* buildAdjacencyList(struct linkedList* pointerInput, FILE *sourceFile) {
	char line[LINE_SIZE_MAX];
	while(fgets(line, LINE_SIZE_MAX, sourceFile))
		printf("%s\n", line);
	return pointerInput;
}
