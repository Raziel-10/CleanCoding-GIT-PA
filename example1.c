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


// fixed
typedef struct Node {
    int data;
    struct Node *next;
} NODE;

// pentru simplitate, folosim int uri pt a numi restaurantele/locatiile
// ex: 1 - restaurantul 1 si tot asa



typedef struct Graph {
    int numOfNodes;
    int *visits;
    NODE **nodes;
} GRAPH;

typedef struct s {
    int t;
    int scap;
    int *arr;
} STK;

// fixed
NODE *createNode (int value) {
    NODE *node = malloc(sizeof(NODE));
    node->data = value;
    node->next = NULL;
    return node;
}

void addEdge(GPH *g, int src, int dest) {
    NODE *nn = createNode(dest);
    nn->next = g->alst[src];
    g->alst[src] = nn;
    nn = createNode(src);
    nn->next = g->alst[dest];
    g->alst[dest] = nn;
}

// fixed
GRAPH *createGraph (int value) {
    GRAPH *g = malloc(sizeof(GRAPH));
    g->numOfNodes = value;
    g->nodes = malloc(sizeof(NODE) * value);
    g->visits = malloc(sizeof(int) * value);

    for (int i = 0; i < value; i++) {
        g->nodes[i] = NULL;
        g->visits[i] = 0;
    }
    return g;
}

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

void insert_edges(GPH *g,int edg_nr,int nrNoduri)
{
    int src,dest,i;
    printf("adauga %d munchii (de la 1 la %d)\n",edg_nr,nrNoduri);
    for (i=0; i<edg_nr; i++)
    {
        scanf("%d%d",&src,&dest);
        addEdge(g,src,dest);
    }
}

void wipe(GPH *g, int nrNoduri)
{
    for (int i=0; i<nrNoduri; i++)
    {
        g->vis[i] = 0;
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
