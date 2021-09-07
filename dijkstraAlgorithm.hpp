#ifndef __DIJKSTRAALGORITHM_HPP__
#define __DIJKSTRAALGORITHM_HPP__
#include <utility>
#include <iostream>
#include <vector>
#include <queue>

#define INF 10000000

typedef int Weight;
typedef std::pair<Weight, int> Vertice;
typedef std::vector<std::vector<Vertice>> AdjacencyList;
typedef std::priority_queue<Vertice, std::vector<Vertice>, std::greater <Vertice>> Heap;

AdjacencyList createAdjacencyList(int qtt_Vertices);

void DijsktraAlgorithm(AdjacencyList list, int source, std::vector<int> & distance, std::vector <int> & parent);

void printVertice(Vertice vertice);

void printAdjacencyList(AdjacencyList list);

void insertVertice(AdjacencyList & list, int first, int second, int weight);

Vertice createVertice(int weight, int vertice);

#endif // __DIJKSTRAALGORITHM_HPP__