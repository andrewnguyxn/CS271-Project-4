#include <tuple>
#include "Graph.hpp"
#include "customexceptions.hpp" 
#include <unordered_map>
#include <vector>
#include <queue>
#include <iostream>
#include <stdexcept>
#include <climits>
#include <set>
#include <algorithm>

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
        throw vertex_exception();
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

// print graph for testing
// void Graph::print() const {
//     cout << "Graph adjacency list:" << endl;
//     for (const auto& [vertex, neighbors] : adjacencyList) {
//         cout << vertex << ": ";
//         for (const int& neighbor : neighbors) {
//             cout << neighbor << " ";
//         }
//         cout << endl;
//     }
// }


//=========================================
// DFS (Depth First Search)
// Author: Tri Dang
// Parameter: bool sort
// Return: the graph
// Description: Peforms DFS on the specified map, returning the same map with the distance assigned
// Based off book's algorithm. If sort = true, then check if the graph is DAG.
// If Sort == true: For every finished node, add it into a linked list (ordered). The Member "ordered" does
// NOT need to be a DAG ordered; just returns an order.
//=========================================
unordered_map<int, tuple<int, int, int>> Graph::depthFirstSearch(bool sort) {
    //initialize DFS by setting time to zero
    long time = 0;
    discovery = time;
    finish = time;

    for (auto& node : adjacencyList) {
        DFSresults[node.first] = make_tuple(-1, -1, -1);  // discovery, finish, parent
    }

    unordered_map<int, tuple<int, int, int>> results; // stores results to return
    set<int> visited; // keeps track of visited UNIQUE nodes

    // Iterate through all nodes in the adjacency list
    for (const auto& node : adjacencyList) {
        if (visited.find(node.first) == visited.end() && get<1>(DFSresults[node.first]) == -1) {
            visited.insert(node.first);
            cout << "Node visiting: " << node.first << endl;
            DFSvisit(node.first, -1, visited, sort); // Start DFSvisit if not visited, -1 is no parent YET
        }
    }

    // Fill DFSresults with discovery time, finish time, and parent
    for (const auto& node : adjacencyList) {
        int u = node.first;
        results[u] = DFSresults[u];
    }

    if (sort) {
        reverse(sorted.begin(), sorted.end()); // push back makes nodes in sorted as "ascending order in terms of f time"
        // reversing will show us the start to last (descending order in terms of f time)
        ordered = sorted;
    }
    return results;
}

//=========================================
// DFS-visit
// Author: Tri Dang
// Parameter: node u, parent, and bool sort
// Return: None
// Description: Part of the DFS algorithm in the textbook
// fully visit a neighboring node's path to fill in discovery and finish time.
// Sort == true: store finished node into sorted for topological sort.
//=========================================
void Graph::DFSvisit(int u, int parent, set<int> visited, bool sort) {
    time++;
    discovery = time;
    cout << "Time and discovery: " << time << " " << discovery << endl;
    DFSresults[u] = make_tuple(discovery, -1, parent); // Store discovery time, parent, and "un-finished" time -1
    
    // Visit all unvisited neighbors of u
    for (int v : adjacencyList[u]) {  // Iterate over neighbors of the current node u
    if (visited.find(v) == visited.end() && get<0>(DFSresults[v]) == -1) { // If neighbor is unvisited
            cout << "DFSresults[v]: " << get<0>(DFSresults[v]) << endl;
            cout << "v: " << v << endl;
            cout << "u: " << u << endl;
        DFSvisit(v, u, visited, sort);  // Recursively visit the neighbor
        }
    }

    time++;
    finish = time;
    cout << "Finish time: " << finish << " for node: " << u << endl;
    DFSresults[u] = make_tuple(get<0>(DFSresults[u]), finish, get<2>(DFSresults[u]));
    // topological sort
    if (sort) {
        sorted.push_back(u); // add node u into sorted for later uses...
    }
}


//==============================================================
// breadthFirstSearch
// Aisha Barry
// This function performs Breadth-First Search (BFS) on the graph
// starting from a specified vertex.
// PARAMETERS: int s - The starting vertex for BFS.
// Return value: A map where the key is the vertex ID, and the 
// value is a pair representing the distance from the source and
// the parent vertex.
//==============================================================
unordered_map<int, pair<int, int>> Graph::breadthFirstSearch(int s) {
    unordered_map<int, pair<int, int>> bfsResult; // Stores distances and parents
    unordered_map<int, bool> visited;            // Tracks visited vertices
    queue<int> q;                                // Queue for BFS

    // Initialize all vertices as unvisited
    for (auto &node : adjacencyList) {
        bfsResult[node.first] = {INT_MAX, -1}; // Distance is "infinity," no parent
        visited[node.first] = false;
    }

    // Start BFS from the source vertex
    bfsResult[s].first = 0; // Distance to itself is 0
    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // Explore all neighbors of the current vertex
        for (int neighbor : adjacencyList[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                bfsResult[neighbor].first = bfsResult[current].first + 1; // Distance
                bfsResult[neighbor].second = current;                    // Parent
                q.push(neighbor);
            }
        }
    }

    return bfsResult;
}

//==============================================================
// getOrdering
// Aisha Barry
// This function retrieves the ordering of vertices stored in 
// the 'ordered' member of the graph class. It returns a copy 
// of this ordering.
// PARAMETERS: None
// Return value: A vector containing the ordering of vertices.
//==============================================================
vector<int> Graph::getOrdering() {
    return ordered; // Return a copy of the ordered vertices
}

//=========================================
// read from STDIN
// Author: Tri Dang
// Parameter: None. Is an assignment for any graph
// Return: None. Reassign the graph into an STDIN with n nodes, m edges, and all node-to-node edges
// Description: Bruh how tf do I  implement this shit lmao.
//=========================================
Graph Graph::readFromSTDIN() {
    int n, m;
    cin >> n >> m; // Read the number of vertices (n) and edges (m)

    Graph g;

    // adding all the vertices
    for (int i = 0; i <= n; ++i) {
        g.addVertex(i);
    }

    // adding all the edges
    for (int i = 0; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    return (g);
}
