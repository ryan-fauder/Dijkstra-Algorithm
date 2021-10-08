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

  std::vector<bool> wasVisited;
  Heap min_heap;

  // Creating distance and parent;
  /*
  
  distance.resize(size, INF);
  parent.resize(size, -1);

  */
  fill(distance.begin(), distance.end(), INF);
  fill(parent.begin(), parent.end(), -1);
  wasVisited.resize(size, 0);

  min_heap.push(createVertice(0, source));

  distance[source] = 0;

  while (!min_heap.empty()){
    weight = min_heap.top().first;
    vertice = min_heap.top().second;

    min_heap.pop();
    
    if(wasVisited[vertice] == 1) continue;
    else wasVisited[vertice] = 1;
    
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
  list.resize(qtt_vertices);
  return list;
}

void printVertice(Vertice vertice){
  std::cout << "(W:" << vertice.first << ", V:" << vertice.second << ")";
}

void printAdjacencyList(AdjacencyList list){
  int size = list.size();

  std::cout << size << std::endl;
  for (int row = 0; row < size; row++)
  {
    std::cout << row << ": ";
    for (int column = 0; column < list[row].size(); column++)
    {
      printVertice(list[row][column]);
      std::cout << " ; ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void insertVertice(AdjacencyList & list, int first, int second, int weight){
  list[first].push_back(createVertice(weight, second));
  list[second].push_back(createVertice(weight, first));
}

Vertice createVertice(int weight, int vertice){
  Vertice v;
  v = std::make_pair(weight, vertice);
  return v;
}

/*

void DijsktraAlgorithm(AdjacencyList list, int source, std::vector<int> & distance, std::vector <int> & parent){
  int size = list.size();
  // distance from source
  // A List with all the path
  int current_weight, weight;
  int current_vertice, vertice;

  Heap min_heap;

  // Creating distance and parent;
  //distance.resize(size, INF);
  //parent.resize(size, -1);

  fill(distance.begin(), distance.end(), INF);
  fill(parent.begin(), parent.end(), -1);

  min_heap.push(createVertice(0, source));

  distance[source] = 0;

  while (!min_heap.empty()){
    weight = min_heap.top().first;
    vertice = min_heap.top().second;

    min_heap.pop();
    
    if(weight > distance[vertice]) continue;
    
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

*/

/*
void DijsktraAlgorithm(AdjacencyList list, int source, int destination, std::vector<int> & distance, std::vector <int> & parent){
  int size = list.size();
  // distance from source
  // A List with all the path
  int current_weight, weight;
  int current_vertice, vertice;

  std::vector<bool> wasVisited;
  Heap min_heap;

  // Creating distance and parent;
  fill(distance.begin(), distance.end(), INF);
  fill(parent.begin(), parent.end(), -1);
  wasVisited.resize(size, 0);

  min_heap.push(createVertice(0, source));

  distance[source] = 0;

  while (!min_heap.empty()){
    weight = min_heap.top().first;
    vertice = min_heap.top().second;

    min_heap.pop();
    
    if(vertice == destination) return;

    if(wasVisited[vertice] == 1) continue;
    else wasVisited[vertice] = 1;
    
    for(auto current : list[vertice])
    {
      current_weight = current.first;
      current_vertice = current.second;
      // It's current vertice that "vertice" is connected.
      if(current_weight + weight < distance[current_vertice] && wasVisited[current_vertice] == 0){
        distance[current_vertice] = current_weight + weight;
        min_heap.push(createVertice(distance[current_vertice], current_vertice));
        parent[current_vertice] = vertice;
      }
    }
  }
}
*/