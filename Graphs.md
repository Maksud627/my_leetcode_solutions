rules to create adjacancy matrix of a graph

- Create an n x n 2d vector named matrix, where n is the number of vertices, with all entries initialized to 0.
- For an undirected graph, set both matrix[i][j] and matrix[j][i] to 1 if there is an edge between vertices i and j.
- For a directed graph, set matrix[i][j] to 1 if there is an edge from vertex i to vertex j.
- For a weighted graph, set matrix[i][j] to the weight of the edge between vertices i and j.
- If there is a self-loop on vertex i, set matrix[i][i] to 1 (or the weight if weighted).