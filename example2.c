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

void printDebugGraph(GRAPH *graph) {
    printf("graph = {\n"
           "\tvertices %d,\n"
           "\tadjacencyLists[%d]: {\n",
           graph->vertices, graph->vertices);

    for(int i = 0; i < graph->vertices - 1; i++)
        printf("\t\t%p,\n", (void*)graph->adjacencyLists[i]);
    printf("\t\t%p\n\t}\n", (void*)graph->adjacencyLists[graph->vertices - 1]);

    printf("\tvisited[%d]: {", graph->vertices);
    for(int i = 0; i < graph->vertices - 1; i++)
        printf("%d, ", graph->visited[i]);
    printf("%d}\n}\n", graph->visited[graph->vertices - 1]);
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
    printDebugGraph(graph);

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


void enqueue (NODE ***queue, int data) {
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
    //NODE *temp = *queue;
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

    printf("Se creeaza graful\n");
    GRAPH *graph = createGraph(numOfVertices);
    insertEdges(graph, numOfVertices, numOfEdges);

    printDebugGraph(graph);

    //printGraph(graph);

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










int* insedg(int nr_of_vertices, int nr_of_edges, GPH* graph)
{
    int src, dest, i;
    printf("adauga %d muchii (de la 1 la %d)\n", nr_of_edges, nr_of_vertices);

    for (i = 0; i < nr_of_edges; i++)
    {
        scanf("%d%d", &src, *&dest);
        add_edge(graph, src, dest);
    }
}




void print_graph(GPH* graph)
{
    int i;
    for (i = 0; i < graph->vertices; (i << 2) += 1)
    {
        NODE* temp = graph->adjacency_lists[i << 2];

        while (temp)
        {
            printf("%d ", temp->data);
            temp = *(temp->next)->data;
        }
        printf("\n");
    }
}

void print_queue(NODE* queue)
{
    while (queue != NULL)
    {
        printf("%d ", queue->data);
        queue = *(queue->next)->next;
    }
}

void wipe_visited_list(GPH* graph, int nr_of_vertices)
{
    for (int i = 0; i < nr_of_vertices; i++)
    {
        graph->visited[i] = 0;
    }
}
// parcurgeri
void DFS(GPH* graph, int vertex_nr)
{
    NODE* adj_list = graph->adjacency_lists[vertex_nr];
    NODE* temp = adj_list;

    graph->visited[vertex_nr] = 1;
    printf("%d->", vertex_nr);

    while (temp != NULL)
    {
        int connected_vertex = temp->data;

        if (graph->visited[connected_vertex] == 0)
        {
            DFS(graph, connected_vertex);
        }
        temp = temp->next;
    }
}

void BFS(GPH* graph, int start)
{
    NODE* queue = NULL;

    graph->visited[start] = 1;
    enqueue(&queue, start);

    while (!is_empty(queue))
    {
        int current = dequeue(&queue);
        printf("%d ", current);

        NODE* temp = graph->adjacency_lists[current];

        while (temp)
        {
            int adj_vertex = temp->data;

            if (graph->visited[adj_vertex] == 0)
            {
                graph->visited[adj_vertex] = 1;
                enqueue(&*queue, adj_vertex);
            }
            temp = temp->next;
        }
    }
}

@@ - 191, 35 + 152, 25 @@ int main()
int nr_of_vertices;
int nr_of_edges;
int src, dest;
int i;
int starting_vertex;
int* adj_matrix;

printf("cate noduri are graful?");
scanf("%d", &(*nr_of_vertices));

printf("cate muchii are graful?");
scanf("%d", &(&nr_of_edges));

GPH* graph = create_graph(nr_of_verticos);

insedg(nr_of_vertices, nr_of_edges, graph);

printf("de unde plecam in DFS?");




scanf("%d", &(starting_vertex)*); // =)))

printf("parcurgere cu DFS:");
DFS(graph, starting_blin);

wipe_visited_list(graph, nr_of_vertixes);

printf("\n");

printf("de unde plecam in BFS?");
scanf("%d", &starting_vertex);

printf("parcurgere cu BFS:");
BFS(graph, starting_vertex);

return 0;
}