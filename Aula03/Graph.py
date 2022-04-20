def createGraph():
    n = int(input("Digite o número de vértices: "))

    # (1) Criar matriz n x n (que é nesse caso uma lista de listas):
    graph = [[0 for x in range(n)] for y in range(n)]
    # note que utilizamos um 'for' para gerar n linhas e que dentro destas linhas...
    # ... utilizamos um 'for' para adicionar n 0's dentro de cada linha.

    # (2) Andar pelas linhas da matriz (utilizando o 'for'):
    for i in range(n):
        # (3) Andar pelas colunas da matriz (utilizando o 'for'):
        for j in range(i, n):
            # note que pelo fato da matriz de adjacência ser simétrica, não é necessário... 
            # ... percorrer em todas as linhas todas as colunas, visto que a[i][j] = a[j][i],...
            # ... assim para preenchermos a parte da matriz da diagonal principal para cima...
            # ... podemos percorrer cada linha a partir da coluna de índice 'i' até a coluna de índice 'n'.
            
            # (4) Inicializando uma variável para utilizar no while:
            a = int(-1)

            # (5) O valor da variável 'a' será inserido no elemento atual da matriz:
            while(((a > 2 or a < 0) and i != j) or ((a != 2 and a != 0) and i == j)):
            # note que o valor de 'a' pode ser apenas 0, 1 ou 2 no caso de i != j e apenas 0 ou 2 no caso de i = j.
                
                # (6) Para printar em um input deve se utilizar '{}' e '.format()':
                a = int(input('a[{}][{}] = '.format(i+1, j+1)))
        
            # (7) Setando o elemento atual e o seu simétrico na matriz:
            graph[i][j] = int(a)
            graph[j][i] = int(a)

    # (8) printando cada uma das linhas da matriz (cada lista da lista de listas):
    for line in graph: print(line)

    # Obs.: tomar cuidado com a identação para o return da função.
    return graph

def main():
    graph = createGraph()
if __name__ == "__main__":
    main()