typedef struct Row row;
struct Row{
    int *line;
    row *next;
};
row *createGraph(row *graph, int n);
int degree(row *graph, int n);