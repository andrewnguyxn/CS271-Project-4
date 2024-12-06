#include <tuple>
#include "Graph.hpp"
#include "customexceptions.hpp" 
#include <unordered_map>
#include <vector>
#include <queue>
#include <stdexcept>

using namespace std;

// Default constructor
Graph::Graph() {
    adjacencyList.clear();
    sorted.clear();
}

// Destructor
Graph::~Graph() {
    adjacencyList.clear();
    sorted.clear();
}

// deep copy
Graph::Graph(const Graph& other) {
    adjacencyList = other.adjacencyList; 
    sorted = other.sorted;              
}

// assignment operator
Graph& Graph::operator=(const Graph& other) {
    if (this != &other) { 
        adjacencyList = other.adjacencyList; 
        sorted = other.sorted;              
    }
    return *this; 
}

// addEdge
void Graph::addEdge(int u, int v) {
    if (find(adjacencyList[u].begin(), adjacencyList[u].end(), v) == adjacencyList[u].end()) { // check if the edge already exist
        adjacencyList[u].push_back(v); // put vertex to the back of adj list
    }
}

// removeEdge - remove an edge
void Graph::removeEdge(int u, int v) {
    if (adjacencyList.find(u) == adjacencyList.end()) { // check if the vertex exist
        throw edge_exception();
    }
    
    vector<int>& neighbors = adjacencyList[u]; 
    vector<int>::iterator edge = find(neighbors.begin(), neighbors.end(), v);  // iterate through u's neighbors, if found assign to edge

    // if the edge exists, remove it. otherwise, throw an exception
    if (edge != neighbors.end()) {
        neighbors.erase(edge);
    } else {
        throw edge_exception();
    }
}

// edgeIn - return whether an edge is in the graph or not
bool Graph::edgeIn(int u, int v) {
    return find(adjacencyList[u].begin(), adjacencyList[u].end(), v) != adjacencyList[u].end();
}

// addVertex - add new vertex 
void Graph::addVertex(int u) {
    if (adjacencyList.find(u) != adjacencyList.end()) { // check if vertex already exists
        throw vertex_exception();
    }
    adjacencyList[u] = vector<int>();
}

// deleteVertex - delete a vertex and all its edges
void Graph::deleteVertex(int u) {
    if (adjacencyList.find(u) == adjacencyList.end()) { // check to see if vertex already exists
        throw vertex_exception();
    }

    // delete all outgoing edges
    adjacencyList.erase(u);

    // delete all ingoing edges to that vertex
    for (unordered_map<int, vector<int> >::iterator it = adjacencyList.begin(); it != adjacencyList.end(); ++it) {
        vector<int>& neighbors = it->second; 
        vector<int>::iterator vertex = remove(neighbors.begin(), neighbors.end(), u); 

        if (vertex != neighbors.end()) {
            neighbors.erase(vertex, neighbors.end());
        }
    }
}