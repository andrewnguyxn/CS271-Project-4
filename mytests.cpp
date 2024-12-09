#include "Graph.hpp"
#include <iostream>

using namespace std;

int main() {
    Graph g;
    // adding vertex enough though the parameter requires 2?
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);

    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(3,1);

    g.removeEdge(3,1);

    auto result = g.depthFirstSearch(true);

    cout << "DFS Results:" << endl;
    for (const auto& [vertex, info] : result) {
        cout << "Vertex: " << vertex
             << ", Discovery: " << get<0>(info)
             << ", Finish: " << get<1>(info)
             << ", Parent: " << get<2>(info) << endl;
    }

    // Print topological order
    cout << "Topological Order:" << endl;
    for (int v : g.getOrdering()) {
        cout << v << " ";
    }
    cout << endl;




    //g.print();

    return 0;
}
