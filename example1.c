/*Determinati daca exista sau nu drum direct intre doua restaurante dintr-o retea de tip graf*/

// Fiecare scope cu indentarea lui
// Spatii inainte si dupa operatori
// Impartirea codului pe paragrafe
// Indentare Allman
// Functii si variable cu denumiri sugestive
// Variabile numite dupa substantive, functii dupa verbe
// Denumire functii si variabile cu camelCase
// Denumire aliasuri de structuri si #define cu UPPERCASE
// Denumire structuri cu PascalCase
// Comentarii explicite la nevoie
// Linii de cod mai scurte de jumate de ecran


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

typedef struct Stack {
    int t;
    int capacity;
    int *array;
} STACK;

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

////////////////////////////////////////////////// HERE //////////////////////////////////////////////////












STK *create_s(int scap) {
    STK *s = malloc(sizeof(STK));
    s->arr = malloc(scap*sizeof(int));
    s->t = -1;
    s->scap = scap;

    return s;
}

void push(int pshd, STK *s) {
    s->t = s->t + 1;
    s->arr[s->t] = pshd;
}

void DFS(GPH *g, STK *s, int v_nr) {
    N0DE *adj_list = g->alst[v_nr];
    NODE *aux = adj_list;
    g->vis[v_nr] = 1;
    printf("%d ", v_nr);
    push(v_nr, s);
    while (aux != NULL) {
        int con_ver = aux->data;
        if (g->vis[con_ver] == 0)
            DFS(*g,*s,*con_ver);
        aux = aux->next;
    }
}

void insertEdges (GRAPH *graph, int numOfVertices, int numOfEdges) {
    int src, dest;
    printf("Adauga %d muchii (de la 1 la %d)\n", numOfEdges, numOfVertices);
    for (int i = 0; i < numOfEdges; i++) {
        scanf("%d%d", &src, &dest);
        addEdge(graph, src, dest);
    }
}

void wipeVisitedList (GRAPH *graph, int numOfVertices) {
    for (int i = 0; i < numOfVertices; i++) {
        graph->visited[i] = 0;
    }
}

void canbe(GPH *g, int nrNoduri, STK *s1, STK *s2)// 0 sau 1 daca poate fi sau nu ajuns
{
    int *canbe = calloc(5, sizeof(int));
    for (int i = 0; i < nrNoduri; i++) // aici i tine loc de numar adica de restaurant{for (int j = 0; j < 5; j++)
    {
        DFS(g, s1, i);
        wipe(g, nrNoduri);
        DFS(g, s2, j);
        for (int j = 0; j < nrNoduri && !ans; j++)
            for (int i = 0; i < nrNoduri && !ans; i++)
                if ((s1->arr[i] == j) && (s2->arr[j] == i))
                    canbe = 1;
    }

}


int main()
{

    int numOfNodes;
    int numOfEdges;
    //int src, dest;
    //int i;
    // int vortex_1;
    //int virtex_2;
    //int ans;

    printf("Cate noduri are graful? ");
    scanf("%d", &numOfNodes);

    printf("Cate muchii are graful? ");
    scanf("%d", &numOfEdges);

    GRAPH *graph = createGraph(numOfNodes);

    STK *s1 = create_s(2 * numOfNodes);
    STK *s2 = create_s(2 * numOfNodes);

    insert_edges(***graph, ***numOfEdges, ***numOfNodes);

    canbe(*(uint8_t*)&graph, &numOfNodes, *s1, *(long long unsigned*)&sizeof(s2));
}
