typedef struct ListaDeAdjacencia listaDeAdjacencia;
typedef struct ListaDeVertices listaDeVertices;
struct ListaDeVertices{
    int indice;
    listaDeVertices *nextVertice;
};
struct ListaDeAdjacencia{
    listaDeAdjacencia *nextLista;
    listaDeVertices *vertices;
};
int degree(int vertice, listaDeAdjacencia *lista);
listaDeAdjacencia *createGraph();