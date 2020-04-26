#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>
#include "csce310assignment03part01.h"

using namespace std;

/**
   * Author: Derek Drake
   * Date: 3/15/20
   *
   * maximumST is an adaptation of Exercise 9.3.5 on page 332. maximumST is a function that should
   * take an n × n vector (representing the adjacency matrix of a graph) as input and return the value
   * of the maximum spanning tree of the graph defined by the n × n vector.
   *
   **/

double maximumST( vector< vector<double> > adjacencyMatrix ){
  // strategy: use the inverse of Kruskal's algorithm, that is instead of
  // choosing the min edge at every step, choose the max edge

  // copy the vector over to 2d array
  double **array;
  int rows = adjacencyMatrix.size();
  array = new double*[rows];
  for(int i = 0; i < rows; i++){
    array[i] = new double[rows];
    for(int j = 0; j < rows; j++){
      array[i][j] = adjacencyMatrix[i][j];
    }
  }

  // creating disjoint set
  int disjoint[rows];
  for(int i = 0; i < rows; i++){
    disjoint[i] = i;
  }

  int n = 0;
  int a = 0;
  int b = 0;
  int maxCost = 0;
  // start with an empty subgraph, then pick the largest edge then add it
  // to the current subgraph if such an inclusion(using the find parent and union functions) does not create a cycle
  // and skipping the edge other wise - quoting the book
  while(n < rows - 1){
    int max = 0;
    for(int i = 0; i < rows; i++){
      for(int j = 0; j < rows; j++){
        if(array[i][j] > max){
          max = array[i][j];
          a = i;
          b = j;
        }
      }
    }

    // creat two subsets
    int x = findDisjoint(a, disjoint);
    int y = findDisjoint(b, disjoint);

    // find the disjoint set of those two ^^
    if(unions(x, y, disjoint)){
      maxCost += max;
      n++;
    }

    // inverse the edge
    array[a][b] = array[b][a] = 0;
  }

  return maxCost;
}

bool unions(int x, int y, int disjoint[]){
  int a = findDisjoint(x, disjoint);
  int b = findDisjoint(y, disjoint);
  if(a != b){
    disjoint[x] = y;
    return true;
  }
  return false;
}

int findDisjoint(int x, int disjoint[]){
  while(disjoint[x] != x){
    x = disjoint[x];
  }

  return x;
}
