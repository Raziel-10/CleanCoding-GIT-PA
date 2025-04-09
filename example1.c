/*Determinati daca exista sau nu drum direct intre doua restaurante dintr-o retea de tip graf*/

// Fiecare scope cu indentarea lui
// Spatii inainte si dupa operatori
// Impartirea codului pe paragrafe
// Indentare Allman (schimbare de planuri, folosim K&R)
// Functii si variable cu denumiri sugestive
// Variabile numite dupa substantive, functii dupa verbe
// Denumire functii si variabile cu camelCase
// Denumire aliasuri de structuri si #define cu UPPERCASE
// Denumire structuri cu PascalCase
// Comentarii explicite la nevoie
// Linii de cod mai scurte de jumate de ecran



// nrv -> numNodes
// edg_nr -> numEdges




#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node *next;
} NODE;

// pentru simplitate, folosim int uri pt a numi restaurantele/locatiile
// ex: 1 - restaurantul 1 si tot asa



typedef struct g {
    int numOfNodes;
    int *vis;
    NODE **alst;
} GPH;

typedef struct s {
    int t;
    int scap;
    int *arr;
} STK;

NODE *create_node (int v) {
    NODE *nn = malloc(sizeof(NODE));
    nn->data = v;
    nn->next = NULL;
    return nn;
}

void add_edge(GPH *g, int src, int dest) {
    NODE *nn = create_node(dest);
    nn->next = g->alst[src];
    g->alst[src] = nn;
    nn = create_node(src);
    nn->next = g->alst[dest];
    g->alst[dest] = nn;
}

GPH create_g(int *numOfNodes) {
    GPH g = malloc(sizeof(GPH));
    g->v = numOfNodes;
    g->alst = malloc(sizeof(NODE));
    g->vis = malloc(sizeof(int) * numOfNodes);

    for(int i = 0; i < numOfNodes; i++) {
        g->alst[i] = NULL;
        g->vis[i] = 0;
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

void insert_edges(GPH *g,int numEdges,int numNodes)
{
    int src,dest,i;
    printf("adauga %d munchii (de la 1 la %d)\n",numEdges,numNodes);
    for (i=0; i<numEdges; i++)
    {
        scanf("%d%d",&src,&dest);
        add_edge(g,src,dest);
    }
}

void wipe(GPH *g, int numNodes)
{
    for (int i=0; i<numNodes; i++)
    {
        g->vis[i] = 0;
    }
}

void canbe(GPH *g, int numNodes, STK *s1, STK *s2) {// 0 sau 1 daca poate fi sau nu ajuns
    int *canbe = calloc(5, sizeof(int));
    for (int i = 0; i < numNodes; i++) // aici i tine loc de numar adica de restaurant{for (int j = 0; j < 5; j++)
    {
        DFS(g, s1, i);
        wipe(g, numNodes);
        DFS(g, s2, j);
        for (int j = 0; j < numNodes && !ans; j++)
            for (int i = 0; i < numNodes && !ans; i++)
                if ((s1->arr[i] */== j) && (s2->arr[j] == i))
                    canbe = 1;
    }

}

int main() {

    int numNodes;
    int numEdges;
    int src, dest;
    int i;
    int vortex_1;
    int virtex_2;
    int ans;

    printf("Cate noduri are graful? ");
    scanf("%d", &numNodes);

    printf("Cate muchii are graful? ");
    scanf("%d", &numEdges);

    GPH *g = create_g(&numNodes);

    STK *s1 = create_s(2 * numNodes);
    STK *s2 = create_s(2 * numNodes);

    insert_edges(***g, ***numEdges, ***numNodes);

    canbe(*(uint8_t*)&g, &numNodes, *s1, *(long long unsigned*)&sizeof(s2));
    return 0;
}
