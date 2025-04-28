#include <iostream>
#include <vector>
using namespace std;

//Given a (directed/undirected) graph, design an algorithm and implement it using a program to find if a path exists between two given vertices or not.

//If adjency matrix is given
bool pathExists1 (const vector<vector<bool>>& adj, vector <bool>& visited, int source, int destination){
     if (source == destination) return true;
     visited[source] = true;
     if (adj[source][destination]) return true;
     int noOfVertices = adj.size();
     for (int i = 0; i < noOfVertices; ++i)
          if (!visited[i] && adj[source][i]) 
               if (pathExists1(adj, visited, i, destination)) return true;
     return false; 
}
bool pathExists1 (const vector<vector<bool>>& adj, int source, int destination){
     vector <bool> visited (adj.size(), false);
     return pathExists1(adj, visited, source, destination);
}

//If adjency list is given
bool pathExists2 (const vector<vector<int>>& adj, vector <bool>& visited, int source, int destination){
     if (source == destination) return true;
     visited[source] = true;
     int noOfVertices = adj[source].size();
     for (int i = 0; i < noOfVertices; ++i){
          int newSource = adj[source][i];
          if (!visited[newSource]) 
               if (pathExists2(adj, visited, newSource, destination)) return true;
     }
     return false; 
}
bool pathExists2 (const vector<vector<int>>& adj, int source, int destination){
     vector <bool> visited (adj.size(), false);
     return pathExists2(adj, visited, source, destination);
}

//If edges vector is given
vector<vector<int>> convertAdjencyList(int n, vector<vector<int>>& edges, bool directed){
     vector<vector<int>> adj (n, vector <int> {});
     for (const vector <int> & edge : edges){
          adj[edge[0]].push_back(edge[1]);
          if (!directed) adj[edge[1]].push_back(edge[0]);
     }
     return adj;
}
bool pathExists3(int n, vector<vector<int>>& edges, int source, int destination) {
     vector<vector<int>> adj = convertAdjencyList(n, edges, false);
     vector <bool> visited (adj.size(), false);
     return pathExists2(adj, visited, source, destination);
}

int main(){
     vector<vector<int>> adj = {{1}, {2}, {}};
     cout<<pathExists2(adj, 0, 2);
}
