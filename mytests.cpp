#include "Graph.hpp"

using namespace std;

int main() {
    Graph g;

    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);

    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(3,1);

    g.removeEdge(3,1);



    g.print();

    return 0;
}
