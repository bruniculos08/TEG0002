def createGraph(graph):
    n = input(int("Digite o número de vértices: "))
    graph = [[]*n]
    for i in range(n):
        for j in range(i, n):
            a = 0
            while(a > 2 or a < 0):
                a = input(int("a[{i}][{j}] = "))
            graph[i][j] = a
            graph[j][i] = a
return graph