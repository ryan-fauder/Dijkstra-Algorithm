#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include "dijkstraAlgorithm.hpp"

void DijsktraAlgorithm(AdjacencyList list, int source, std::vector<int> & distance, std::vector <int> & parent){
  int size = list.size();
  // distance from source
  // A List with all the path
  int current_weight, weight;
  int current_vertice, vertice;
  Heap min_heap;

  // Creating distance and parent;
  distance.resize(size, INF);
  parent.resize(size);
  for (int i = 0; i < size; i++) parent[i] = i;
  

  min_heap.push(createVertice(0, source));

  distance[source] = 0;

  while (!min_heap.empty()){
    weight = min_heap.top().first;
    vertice = min_heap.top().second;

    min_heap.pop();
    
    if(parent[vertice] != vertice && vertice != source) continue;

    for(auto current : list[vertice])
    {
      current_weight = current.first;
      current_vertice = current.second;
      // It's current vertice that "vertice" is connected.
      if(current_weight + weight < distance[current_vertice] && current_vertice != source){
        distance[current_vertice] = current_weight + weight;
        min_heap.push(createVertice(distance[current_vertice], current_vertice));
        parent[current_vertice] = vertice;
      }
    }
  }
}

AdjacencyList createAdjacencyList(int qtt_vertices){
  AdjacencyList list;
  list.reserve(qtt_vertices);
  for (int i = 0; i < qtt_vertices; i++)
  {
    list[i].reserve(qtt_vertices);
  }
  return list;
}

void printVertice(Vertice vertice){
  std::cout << "( W:" << vertice.first << ", V:" << vertice.second << " )" << std::endl;
}

void printAdjacencyList(AdjacencyList list){
  int size = list.size();
  for (int row = 0; row < size; row++)
  {
    std::cout << row << ": " << std::endl;
    for (int column = 0; column < list[row].size(); row++)
      printVertice(list[row][column]);
  }
  
}

void insertVertice(AdjacencyList & list, int first, int second, int weight){
  list[first].push_back(createVertice(weight, first));
  list[second].push_back(createVertice(weight, second));
}

Vertice createVertice(int weight, int vertice){
  Vertice v;
  v = std::make_pair(weight, vertice);
  return v;
}
