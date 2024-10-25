import java.io.*;
import java.util.*;
public class Main {
	
	public static void main(String[] args) {
		int adjMat [] [] = {
		        {0, 2, 0, 4, 0, 0},
		        {0, 0, 3, 2, 0, 0},
		        {2, 0, 0, 0, 0, 4},
		        {0, 0, 0, 0, 2, 0},
		        {0, 0, 0, 0, 0, 1},
		        {0, 0, 0, 0, 0, 0}};
		
		//creating a distance array to keep a note of distance of vertex from source
		int [] distance = new int[adjMat.length];
		
		//taking source vertex to be 0
		int source = 0;
		
		//creating a visited array to keep a count of visited vertices.
		boolean [] visited = new boolean[adjMat.length];
		
		//marking distance of source vertex
		distance[source] = 0;
		
		// filling up other distance in array "distance" as infinity or the max value
		for (int i = 0; i < adjMat.length; i++) {
			if( i == source) continue;
			distance[i] = Integer.MAX_VALUE;
		}
		
		//finding the vertex that is most close to current node or source
		for(int i = 0; i < adjMat.length; i++) {
			int minDistVertex = findMinDistVertex(distance, visited);
			
			//marking the vertex that is most close to source/current vertex as true
			visited[minDistVertex] = true;
			
			//exploring the neighbors of each vertex and updating distance array with new distance
			for(int j = 0; j < adjMat.length; j++) {
				if(adjMat[minDistVertex][j] != 0 && visited[j] == false && distance[minDistVertex] != Integer.MAX_VALUE) {
					int newDist = distance[minDistVertex] + adjMat[minDistVertex][j];
					if(newDist < distance[j]) {
						distance[j] = newDist;
					}
				}
			}
		}
		
		for(int i = 0; i < adjMat.length; i++) {
			System.out.println("Vertex : " + i + " & Distance from Source : " +distance[i]);
		}
	}
	
	public static int findMinDistVertex(int[] distance, boolean [] visited) {
		
		int minVertex = -1;
		
		//traversing through the distance array and finding the least distance vertex whose visited is also false
		for(int i = 0; i < distance.length; i++) {
			if(visited[i] == false && (minVertex == -1 || distance[i] < distance[minVertex])) {
				minVertex = i;
			}
		}
		return minVertex;
	}
}
