#include <iostream>
#include <limits.h>
#define INFINITY INT_MAX
#define max 6
using namespace std;

// Function to print the path from startNode to v
void printPath(int prev[], int v) {
    if (prev[v] == -1) {
        cout << v;
        return;
    }
	cout << v << " <- " ;
    printPath(prev, prev[v]);
    
}


// Function to find the vertex with the minimum distance value
int minDist(int distances[], bool visited[], int n) {
    int min = INFINITY;
    int min_index;
    for (int i = 0; i < n; i++) {
        if (distances[i] < min && !visited[i]) {
            min = distances[i];
            min_index = i;
        }
    }
    return min_index;
}

// Dijkstra's algorithm to find the shortest path from startNode to all other nodes
void dijkstra(int G[][max], int n, int startNode)
{
	int distances[n]; //array that stores shortest distances
	bool visited[n] = {false}; //array that tracks the visited nodes
	int prev[n] = {-1};  //array that stores prev node of each vertex
	for (int i = 0; i < n; i++) {
        distances[i] = INFINITY;
    }

	distances[startNode] = 0;

	for ( int i = 0 ; i<n-1 ; i++){
		int u = minDist(distances, visited, n);// Pick the minimum distance vertex from the set of unvisited vertices
		visited[u] = true;

		/*condions to update v's distance:
		if v is not visted,
		and there's edge from u to v,
		and v's distance is greater than u's distance + weight of the edge
		*/
        for (int v = 0; v < n; v++) {
            if (!visited[v] && G[u][v] != 0 && distances[u] != INFINITY && distances[u] + G[u][v] < distances[v]) {
                distances[v] = distances[u] + G[u][v];
                prev[v] = u;
            }
        }
	}

	// Print shortest distance and path from startNode to every other node
	for (int v = 0; v < n; v++) {
		if(v!=startNode){
        cout << "Distance of node " << v << " = " << distances[v] <<endl;
        cout << "Path: ";
        printPath(prev, v);
        cout <<endl;
		}
    }

}

int main(int argc, char *argv[])
{
	int G[max][max] = {
		{0,10,0,0,15,5},
		{10,0,10,30,0,0},
		{0,10,0,12,5,0},
		{0,30,12,0,0,20},
		{15,0,5,0,0,0},
		{5,0,0,20,0,0}
	};

	int n = 6;
	int u = 0;
	dijkstra(G,n,u);

}