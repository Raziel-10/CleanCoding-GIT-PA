/*parcurgere  graf cu DFS/BFS*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} NODE;


typedef struct Graph {
    int vertices;
    int *visited;
    NODE **adjacencyLists;
} GRAPH;


/// utils

NODE *createNode (int value) {
    NODE *newNode = malloc(sizeof(NODE));

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

GRAPH *createGraph (int vertices) {
    GRAPH *graph = malloc(sizeof(GRAPH));

    graph->vertices = vertices;
    graph->adjacencyLists = malloc(sizeof(NODE *) * vertices);
    graph->visited = malloc(sizeof(int) * vertices);

    for (int i = 0; i < vertices; i++) {
        graph->adjacencyLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge (GRAPH *graph, int src, int dest) {
    NODE *newNode = createNode(dest);
    newNode->next = graph->adjacencyLists[src];
    graph->adjacencyLists[src] = newNode;
    newNode = createNode(src);
    newNode->next = graph->adjacencyLists[dest];
    graph->adjacencyLists[dest] = newNode;
}


void insertEdges (GRAPH *graph, int numOfVertices, int numOfEdges) {
    int src, dest;
    printf("Adauga %d muchii (de la 1 la %d)\n", numOfEdges, numOfVertices);
    for (int i = 0; i < numOfEdges; i++) {
        scanf("%d%d", &src, &dest);
        addEdge(graph, src, dest);
    }
}

/// bfs utils

int isEmpty (NODE *queue) {
    return queue == NULL;
}


void enqueue (NODE **queue, int data) {
    NODE *newNode = createNode(data);
    if (isEmpty(*queue)) {
        *queue = newNode;
    } else {
        NODE *temp = *queue;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int dequeue (NODE **queue) {
    int data = (*queue)->data;
    *queue = (*queue)->next;
    return data;
}

////////////////////////////////////////////////// HERE //////////////////////////////////////////////////

void printGraph (GRAPH *graph) {
    for (int i = 0; i < graph->vertices; i++) {
        NODE *temp = graph->adjacencyLists[i];

        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }

        printf("\n");
    }
}

void printQueue(NODE *queue) {
    while (queue != NULL) {
        printf("%d ", queue->data);
        queue = queue->next->next;
    }
}

void wipeVisitedList (GRAPH *graph, int numOfVertices) {
    for (int i = 0; i < numOfVertices; i++) {
        graph->visited[i] = 0;
    }
}

// parcurgeri

void depthFirstSearch (GRAPH *graph, int vertex) {
    NODE *adjList = graph->adjacencyLists[vertex];
    NODE *temp = adjList;
    graph->visited[vertex] = 1;
    printf("%d -> ", vertex);
    while (temp != NULL) {
        int connectedVertex = temp->data;
        if (graph->visited[connectedVertex] == 0) {
            depthFirstSearch(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

void breadthFirstSearch (GRAPH *graph, int startingVertex) {
    NODE *queue = NULL;
    graph->visited[startingVertex] = 1;
    enqueue(&queue, startingVertex);
    while (!isEmpty(queue)) {
        int current = dequeue(&queue);
        printf("%d ", current);
        NODE *temp = graph->adjacencyLists[current];
        while (temp) {
            int adjacentVertex = temp->data;
            if (graph->visited[adjacentVertex] == 0) {
                graph->visited[adjacentVertex] = 1;
                enqueue(&queue, adjacentVertex);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int numOfVertices;
    int numOfEdges;
    int startingVertex;

    printf("Cate noduri are graful? " );
    scanf("%d", &numOfVertices);

    printf("Cate muchii are graful? ");
    scanf("%d", &numOfEdges);

    GRAPH *graph = createGraph(numOfVertices);
    insertEdges(graph, numOfVertices, numOfEdges);

    printGraph(graph);

    printf("De unde plecam in DFS? ");
    scanf("%d", &startingVertex);

    printf("Parcurgere cu DFS:\n");
    depthFirstSearch(graph, startingVertex);
    wipeVisitedList(graph, numOfVertices);
    printf("\n");

    printf("De unde plecam in BFS? ");
    scanf("%d", &startingVertex);
    printf("Parcurgere cu BFS:\n");
    breadthFirstSearch(graph, startingVertex);

    return 0;
}
