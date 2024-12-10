//=========================================
// mytests.cpp
// Author: Tri Dang, Andrew Nguyen, Aisha Barry
// Description: This file runs all tests for troubleshooting and debugging.
//=========================================
#include "Graph.hpp"
#include <iostream>

using namespace std;

int testPassed;
int testFailed;

//=========================================
// test_addVertex
//=========================================
void test_addVertex() {
    Graph g;

    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);
    g.addVertex(6);
    g.addVertex(7);

    testPassed++;

}

//=========================================
// test_addEdge
//=========================================
void test_addEdge() {

    Graph g;

    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);
    g.addVertex(6);
    g.addVertex(7);

    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(7,1);

    testPassed++;
}
//=========================================
// test_deleteVertex
//=========================================
void test_deleteVertex() {
    Graph g;

    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);
    g.addVertex(6);
    g.addVertex(7);

    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(7,1);

    g.deleteVertex(5);
    g.deleteVertex(4);

    testPassed++;
}
//=========================================
// test_removeVertex
//=========================================
void test_removeEdge() {
    Graph g;

    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);
    g.addVertex(6);
    g.addVertex(7);

    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(7,1);

    g.removeEdge(7,1);
    g.removeEdge(4,5);

    testPassed++;
}
//=========================================
// test_edgeIn
//=========================================
void test_edgeIn() {
    Graph g;

    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);
    g.addVertex(6);
    g.addVertex(7);

    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(7,1);

    g.edgeIn(7,1);
    g.edgeIn(4,5);

    testPassed++;
}
//=========================================
// test_DFS
//=========================================
void test_DFS() {
    Graph g;

    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);
    g.addVertex(6);
    g.addVertex(7);

    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(7,1);

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

    
    testPassed++;
}

void test_BFS() {
    Graph g;

    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);
    g.addVertex(6);
    g.addVertex(7);

    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(7,1);

    auto result = g.breadthFirstSearch(true);

    cout << "BFS Results:" << endl;
    for (const auto& [vertex, info] : result) {
        cout << "Vertex: " << vertex
             << ", Distance: " << get<0>(info)
             << ", Parent: " << get<1>(info) << endl;
    }


    
    testPassed++;
}


int main() {

    test_addEdge();
    test_addVertex();
    test_deleteVertex();
    test_edgeIn();
    test_removeEdge();
    test_DFS();
    test_BFS();

    cout << "Total tests passed:" << testPassed << endl;
    cout << "Total tests failed:" << testFailed << endl;
    return 0;
}

