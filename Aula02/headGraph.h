typedef struct Row row;
struct Row{
    int *line;
    row *next;
};
row *createGraph(row *graph, int n);