#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findMinDistance(vector<int>& distances, vector<bool>& inMST) {
  int minDistance = INT_MAX, minIndex = -1;
  for (int v = 0; v < distances.size(); ++v) {
    if (!inMST[v] && distances[v] < minDistance) {
      minDistance = distances[v];
      minIndex = v;
    }
  }
  return minIndex;
}

void printMST(vector<int>& parents, vector<vector<int>>& graph) {
  cout << "Minimum Spanning Tree:" << endl;
  for (int i = 0; i < parents.size(); ++i) {
    if (parents[i] != -1) {
      cout << parents[i] << " - " << i << "  (Cost: " << graph[i][parents[i]] << ")" << endl;
    }
  }
}

int primMST(vector<vector<int>>& graph, int startNode) {
  int numVertices = graph.size();
  vector<int> parents(numVertices, -1);
  vector<int> distances(numVertices, INT_MAX);
  vector<bool> inMST(numVertices, false);

  distances[startNode] = 0;

  for (int count = 0; count < numVertices - 1; ++count) {
    int minIndex = findMinDistance(distances, inMST);
    inMST[minIndex] = true;

    for (int v = 0; v < numVertices; ++v) {
      if (graph[minIndex][v] && !inMST[v] && graph[minIndex][v] < distances[v]) {
        parents[v] = minIndex;
        distances[v] = graph[minIndex][v];
      }
    }
  }

  int minCost = 0;
  for (int i = 0; i < numVertices; ++i) {
    if (parents[i] != -1) {
      minCost += graph[i][parents[i]];
    }
  }

  printMST(parents, graph);

  return minCost;
}

int main() {
  vector<vector<int>> graph = {
    {0, 3, 0, 0, 0, 1},
    {3, 0, 2, 1, 10, 0},
    {0, 2, 0, 3, 0, 5},
    {0, 1, 3, 0, 5, 0},
    {0, 10, 0, 5, 0, 4},
    {1, 0, 5, 0, 4, 0}
  };

  int startNode = 0;
  int minCost = primMST(graph, startNode);

  cout << "Minimum spanning tree cost: " << minCost << endl;

  return 0;
}
