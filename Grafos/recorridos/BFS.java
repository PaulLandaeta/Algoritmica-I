import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class BFS {
	
	
	public static Scanner scanner = new Scanner(System.in);
		
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		// Read number of edges
		int edges = scanner.nextInt();
		
		// Create a list with 'edges' edges. 
		
		LinkedList<Integer>[]  graph = new LinkedList[edges];
		for(int i = 0; i < edges; i++) {
			graph[i] = new LinkedList<Integer>();
		}
		// Read number of vertices
		int vertices = scanner.nextInt();
	
		
		// Read pair of edges. 
		
		for(int i = 0; i < vertices; i++ ) {
			int edgeOne,edgeTwo;
			edgeOne = scanner.nextInt();
			edgeTwo = scanner.nextInt();
			graph[edgeOne].add(edgeTwo);
			//graph[edgeTwo].add(edgeOne);
		}
		
		//Print Graph 
		for(int i = 0; i< edges; i++) {
			System.out.print("Edge {"+i+"} => ");
			for(int j = 0; j < graph[i].size(); j++ ) {
				System.out.print("["+graph[i].get(j)+"]");  // grafo[i][j]
			}	
			System.out.println();
		}
		
		//BFS 
		//Create the queue to save the next edges. 
		Queue<Integer> edgeQueue = new LinkedList<Integer>();
 		boolean[]	edgeVisited = new boolean[edges];
 		int[] level = new int[edges];
 		
 		//insert the first edge. 
 		edgeVisited[0] = true;
 		
 		int initialEdge = 0;
 		level[initialEdge] = 1;
 		edgeQueue.add(initialEdge);
 		
 		while(!edgeQueue.isEmpty()) {
 			int currentEdge = edgeQueue.remove();
 			for(int i=0;i<graph[currentEdge].size();i++) {
 				if(!edgeVisited[graph[currentEdge].get(i)]) {
 					edgeVisited[graph[currentEdge].get(i)] = true;
 					level[graph[currentEdge].get(i)] = level[currentEdge] + 1;
 					edgeQueue.add(graph[currentEdge].get(i));
 				}
 			}
 		}
 		if(edgeVisited[2]) {
 			System.out.println("The edge 2 was visited");
 		}else {
 			System.out.println("The edge 2 was not visited");
 		}
	}

}

/* 
4 3
0 1
1 2
3 1
*/
/* 
4 2
0 1
1 3
*/
