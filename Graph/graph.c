/*
 * graph.c
 *
 *  Created on: Dec 5, 2022
 *      Author: featomato
 */
#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

#define V 4

typedef struct NODE {
	int vertex;
	struct NODE *next;
}NODE;

typedef struct GRAPH {
	int vertices;
	int *visited;
	struct NODE **adjacencyList;
}GRAPH;

NODE *node  = NULL;

void initMatrix( int arr[][V] ) {
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			arr[i][j] = 0;
		}
	}
}

void addEdgeInMatrix( int arr[][V], int i, int j ) {
	arr[i][j] = 1;
	arr[j][i] = 1;
}

void printAdjacencyMatrix( int arr[][V] ) {

	for (int i = 0; i < V; i++) {
		printf("%d: ", i);
		for (int j = 0; j < V; j++) {
			printf("%d ", arr[i][i]);
		}
		printf("\n");
	}
}

static NODE *createNode( int v ) {
	NODE *node = malloc(v*sizeof(NODE));
	node->vertex = v;
	node->next = NULL;
	return node;
}

GRAPH *createGraph( int vertices ) {
	GRAPH *graph = malloc(sizeof(GRAPH));
	graph->vertices = vertices;
	graph->adjacencyList = malloc(vertices * sizeof(NODE*));
	graph->visited = malloc(vertices * sizeof(int));

	for (int i = 0; i < vertices; i++) {
		graph->adjacencyList[i] = NULL;
	}

	return graph;
}

void addEdge( GRAPH *graph, int source, int destiny ) {
	// Add edge from source to destiny
	NODE *node = createNode(destiny);
	node->next = graph->adjacencyList[source];
	graph->adjacencyList[source] = node;

	// Add edge from destiny to source
	node = createNode(source);
	node->next = graph->adjacencyList[destiny];
	graph->adjacencyList[destiny] = node;

}

void depthFirstSearch( GRAPH *graph, int vertex ) {
	NODE *adjList = graph->adjacencyList[vertex];
	NODE *temp = adjList;

	graph->visited[vertex] = 1;
	printf("Visited %d\n", vertex);

	while (temp != NULL) {
		int connectedVertex = temp->vertex;

		if (graph->visited[connectedVertex] == 0) {
			depthFirstSearch(graph, vertex);
		}
		temp = temp->next;
	}
}


//void createQueue(QUEUE *queue);
//void enqueue(QUEUE *queue, int value);

void breathFirstSearch( GRAPH *graph, int startVertex ) {

	QUEUE q;
	QUEUE *qp = &q;
	createQueue(qp);

	graph->visited[startVertex] = 1;
	enqueue(qp, startVertex);

	while (!isEmpty(qp)) {
		printQueue(qp);
		int currentVertex = dequeue(qp);
		printf("Visited: %d\n", currentVertex);

		NODE *temp = graph->adjacencyList[currentVertex];

		while (temp) {
			int adjVertex = temp->vertex;
			if (graph->visited[adjVertex] == 0) {
				graph->visited[adjVertex] = 1;
				enqueue(qp, adjVertex);
			}
			temp = temp->next;
		}
	}
}


void printGraph(GRAPH *graph ) {
	for (int v = 0; v < graph->vertices; v++) {
		NODE *temp = graph->adjacencyList[v];
		printf("\nVertex :%d\n", v);
		while (temp) {
			printf("%d -> ", temp->vertex);
			temp = temp->next;
		}
	}
}


void graphTask() {

	GRAPH *graph = createGraph(4);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 0, 3);
	addEdge(graph, 1, 2);

	printGraph(graph);

	depthFirstSearch(graph, 1);

	breathFirstSearch(graph, 3);

    /*
	int adjacencyMatrix[V][V];

	initMatrix(adjacencyMatrix);
	addEdgeInMatrix(adjacencyMatrix, 0, 1);
	addEdgeInMatrix(adjacencyMatrix, 0, 2);
	addEdgeInMatrix(adjacencyMatrix, 1, 2);
	addEdgeInMatrix(adjacencyMatrix, 2, 0);
	addEdgeInMatrix(adjacencyMatrix, 2, 3);

	printAdjacencyMatrix(adjacencyMatrix);
	*/
}
