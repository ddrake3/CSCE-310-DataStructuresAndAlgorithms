#ifndef CSCE310HOMEWORK04PART01_H
#define CSCE310HOMEWORK04PART01_H
#include <vector>
#include <cstdint>
using namespace std;

struct blockData
{
    int weight;
    int capacity;
    int remCapacity;
};

int tallestTower( vector<int> , vector<int> );
bool compareCap(const blockData &x, const blockData &y);

#endif

