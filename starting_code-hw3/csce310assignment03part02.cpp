#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <cmath>
#include "csce310assignment03part02.h"
using namespace std;

/**
   * Author: Derek Drake
   * Date: 3/31/20
   *
   * allPairsSP is a function that should take an n × n vector (representing the adjacency matrix of a
   * graph) and a value i between 1 and n as input and return the n × n vector representing the matrix
   * computed after the ith stage of Floyd’s algorithm. For the purposes of this program, infinity (∞)
   * will be represented as −1.
   *
   **/

vector< vector<double> > allPairsSP( vector< vector<double> > adjacencyMatrix , int i ){
  //   using the books algorithm we have the following:
  //   Implements Floyd’s algorithm for the all-pairs shortest-paths problem
  //   Input: The weight matrix W of a graph with no negative-length cycle
  //   Output: The distance matrix of the shortest paths’ lengths
  //   D ← W //is not necessary if W can be overwritten
  //   for k ← 1 to n do
  //   for i ← 1 to n do
  //   for j ← 1 to n do
  //   D[i, j ] ← min{D[i, j ], D[i, k] + D[k, j ]}
  //   return D

  int dimensions = adjacencyMatrix.size();

  vector<double> row(dimensions,0);
  vector< vector<double> > d(dimensions,row);

  // copy matrix over to d
  for(int x = 0; x < dimensions; x++){
    for(int y = 0; y < dimensions; y++){
      d[x][y] = adjacencyMatrix[x][y];
    }
  }

  // iterate up to the given ith stage of Floyd’s algorithm
  for(int k = 0; k < i; k++){
    for(int x = 0; x < dimensions; x++){
      for(int y = 0; y < dimensions; y++){
        // check for negative-length cycle
        if(d[x][k] == -1 || d[k][y] == -1){
          // just skip to next iteration if so
          continue;
        }
        // if not negative-length cycle but vertex is inf
        if(d[x][y] == -1){
          d[x][y] = d[x][k] + d[k][y];
        }
        else{
          d[x][y] = min(d[x][y], d[x][k] + d[k][y]);
        }
      }
    }
  }
  return d;
}
