# Bellman-Ford algorithm

class Graph:
    def __init__(self, num_vertices):
        self.V = num_vertices
        self.adjacency_matrix = [[float('inf')] * num_vertices for _ in range(num_vertices)]
        for i in range(num_vertices):
            self.adjacency_matrix[i][i] = 0
        
    def add_edge(self, u, v, weight):
        if 0 <= u < self.V and 0 <= v < self.V:
            self.adjacency_matrix[u][v] = weight
            # self.adjacency_matrix[v][u] = weight # Uncomment for undirected graph
        else:
            raise ValueError("Vertex index out of bounds")

        def add_vertex(self):
            self.V += 1
            for row in self.adjacency_matrix:
                row.append(float('inf'))
            self.adjacency_matrix.append([float('inf')] * self.V)
            self.adjacency_matrix[-1][-1] = 0

    def bellman_ford(self, start):
        if start < 0 or start >= self.V:
            raise ValueError("Start vertex index out of bounds")

        distances = [float('inf')] * self.V 
        distances[start] = 0

        for _ in range(self.V - 1):
            for u in range(self.V):
                for v in range(self.V):
                    if self.adjacency_matrix[u][v] != float('inf'):
                        if distances[u] + self.adjacency_matrix[u][v] < distances[v]:
                            distances[v] = distances[u] + self.adjacency_matrix[u][v]

        # Check for negative weight cycles
        for u in range(self.V):
            for v in range(self.V):
                if self.adjacency_matrix[u][v] != float('inf'):
                    if distances[u] + self.adjacency_matrix[u][v] < distances[v]:
                        raise ValueError("Graph contains a negative weight cycle")
                    
        return distances
    
    # String representation of the graph
    def __str__(self):
        result = []
        for i in range(self.V):
            result.append(f"Vertex {i}: " + ", ".join(f"{j}({self.adjacency_matrix[i][j]})" for j in range(self.V) if self.adjacency_matrix[i][j] != float('inf')))
        return "\n".join(result)
    

def main():
    g = Graph(5)
    g.add_edge(0, 1, -1)
    g.add_edge(0, 2, 4)
    g.add_edge(1, 2, 3)
    g.add_edge(1, 3, 2)
    g.add_edge(1, 4, 2)
    g.add_edge(3, 2, 5)
    g.add_edge(3, 1, 1)
    g.add_edge(4, 3, -3)

    print("Graph:")
    print(g)

    try:
        distances = g.bellman_ford(0)
        print("\nShortest distances from vertex 0:")
        for i in range(len(distances)):
            print(f"Vertex {i}: {distances[i]}")
    except ValueError as e:
        print(e)

if __name__ == "__main__":
    main()
