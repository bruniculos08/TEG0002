typedef struct ListaDeAdjacencia listaDeAdjacencia;
typedef struct ListaDeVertices listaDeVertices;
struct ListaDeVertices{
    int indice;
    listaDeVertices *next;
};
struct ListaDeAdjacencia{
    listaDeAdjacencia *next;
    listaDeVertices *vertices;
};
int grau(int vertice, listaDeAdjacencia *lista);