#include "GraphVertex.hpp"
#include <iostream>

using namespace std;

//==================================================
// [Title]
// Author:
// Parameter:
// Return:
// Description:
//==================================================


//==================================================
// Default Constructor
// Author: Tri Dang
// Parameter: none
// Return: none
// Description: creates a graph vertex
//==================================================
template <typename T>
GraphVertex<T>::GraphVertex(){
    value = T();
    status = unseen;
    f = 0;
    d = 0;
    //parent and neighbors are already initialized!
}


//==================================================
// Destructor
// Author: Tri Dang
// Parameter: none
// Return: none
// Description: delete and deallocate vertex
//==================================================
template <typename T>
GraphVertex<T>::~GraphVertex(){
}

//==================================================
// operator = 
// Author: Tri Dang
// Parameter: none
// Return: vertex with copied variables
// Description: Used for copy constructor. Check below.
//==================================================
template <typename T>
GraphVertex<T>& GraphVertex<T>::operator=(const GraphVertex& other){
    if (this != &other){
        value = other.value;
        status = other.status;
        f = other.f;
        d = other.d;
        p = other.p;
        // clears vertex's current parents and neighbors
        parents.clear();
        neighbors.clear();
        // copies parents
        for (int i = 0; i < other.parents.size(); i++){
            parents.push_back(other.parents[i]);
        }
        // copies neighbors
        for (int i = 0; i < other.neighbors.size(); i++){
            neighbors.push_back(other.neighbors[i]);
        }
    }
    return *this;
}

//==================================================
// Copy Constructor
// Author: Tri Dang
// Parameter: none
// Return: none
// Description: creates a vertex copying all member variable (deep copy). Parent pointer, p, will use
// the same pointer as other.
//==================================================
template <typename T>
GraphVertex<T>::GraphVertex(const GraphVertex& other){
    value = other.value;
    status = other.status;
    f = other.f;
    d = other.d;
    p = other.p; // be careful with this, perhaps 2 pointers to the same object may result in double deletion
    // copies parents
    for (int i = 0; i < other.parents.size(); i++){
    parents.push_back(other.parents[i]);
    }
    // copies neighbors
    for (int i = 0; i < other.neighbors.size(); i++){
    neighbors.push_back(other.neighbors[i]);
    }
}
