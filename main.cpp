#include <iostream>
#include "dijkstraAlgorithm.hpp"
using namespace std;
int main(){
  int qtt_vertices, qtt_edges;
  int first, second, weight;
  AdjacencyList list;
  vector<int> parent;
  vector<int> distance;
  cin >> qtt_vertices >> qtt_edges;
  list = createAdjacencyList(qtt_vertices);
  while(qtt_edges--){
    cin >> first >> second >> weight;
    cout << first << " " << second << " " << weight << endl;
    insertVertice(list, first, second, weight);
  }
  printAdjacencyList(list);
  DijsktraAlgorithm(list, 3, distance, parent);

  for (int i = 0; i < qtt_vertices; i++)
  {
    cout << distance[i] << ": ";
    int child = parent[i];
    cout << i << " -> ";
    while(child != -1){
      cout << child << " -> ";
      child = parent[child];
    }
    cout << endl;
  }
  
  return 0;
}