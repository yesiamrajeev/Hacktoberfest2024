import java.util.*;

// Class representing a graph
class Graph {
    private int vertices; // Number of vertices in the graph
    private LinkedList<Integer>[] adjacencyList; // Adjacency list to represent the graph

    // Constructor
    public Graph(int vertices) {
        this.vertices = vertices;
        adjacencyList = new LinkedList[vertices];
        for (int i = 0; i < vertices; i++) {
            adjacencyList[i] = new LinkedList<>();
        }
    }

    // Add an edge to the graph
    public void addEdge(int from, int to) {
        adjacencyList[from].add(to);
    }

    // DFS-based function for Topological Sorting
    private void topologicalSortUtil(int currentVertex, boolean[] visited, Stack<Integer> stack) {
        // Mark the current node as visited
        visited[currentVertex] = true;

        // Recur for all vertices adjacent to this vertex
        for (Integer neighbor : adjacencyList[currentVertex]) {
            if (!visited[neighbor]) {
                topologicalSortUtil(neighbor, visited, stack);
            }
        }

        // Push the current vertex to the stack which stores the result
        stack.push(currentVertex);
    }

    // The function to perform Topological Sort using DFS
    public void topologicalSort() {
        Stack<Integer> stack = new Stack<>(); // Stack to store the topological order
        boolean[] visited = new boolean[vertices]; // Mark all the vertices as not visited

        // Call the recursive helper function for all vertices
        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, stack);
            }
        }

        // Print contents of the stack, which contains the topologically sorted order
        System.out.println("Topological Sort:");
        while (!stack.isEmpty()) {
            System.out.print(stack.pop() + " ");
        }
    }
}

// Driver class to test the code
public class TopoSortUsingDFS {
    public static void main(String[] args) {
        // Create a graph with 6 vertices
        Graph graph = new Graph(6);

        // Add edges to the graph
        graph.addEdge(5, 2);
        graph.addEdge(5, 0);
        graph.addEdge(4, 0);
        graph.addEdge(4, 1);
        graph.addEdge(2, 3);
        graph.addEdge(3, 1);

        // Perform Topological Sort
        graph.topologicalSort();
    }
}
