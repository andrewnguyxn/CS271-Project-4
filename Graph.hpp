#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <tuple>
#include <iostream>
#include <unordered_map>
#include <vector>
/*
find (begin, end, value)

*/

using namespace std;

class Graph {
private:
    unordered_map<int, vector<int> > adjacencyList; // stores edges
    vector<int> sorted; // for topological order
    unordered_map(int, tuple<int, int, int>) DFSresults; // for DFS
    long finish; // f in textbook
    long discovery; // d in textbook

public:
    Graph(); // Default constructor
    ~Graph(); // Destructor
    Graph(const Graph& other);   // Copy constructor
    Graph& operator=(const Graph& other);


    void addEdge(int u, int v);
    void removeEdge(int u, int v);
    bool edgeIn(int u, int v);
    void deleteVertex(int u);
    void addVertex(int u);
    //unordered_map<int, pair<int, int> > breadthFirstSearch(int s);
    //unordered_map<int, tuple<int, int, int> > depthFirstSearch(bool sort=false);
    //void DFSvisit(bool sort=false);
    //vector<int> getOrdering();
    //static Graph readFromSTDIN();

    // Additional helper methods as needed
    void print() const;
};
// Add other methods similarly


#endif