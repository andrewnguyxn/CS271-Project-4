//==================================================
// Author: Tri Dang
// This is the declaration of a Graph's vertex. It will hold important member variables like:
// f (finish time), d (discovery time), status/color (for DFS and BFS), ordered (Topicologial), etc 
//==================================================
#ifndef GRAPHVERTEX_HPP
#define GRAPHVERTEX_HPP

#include <tuple>
#include <iostream>
#include <unordered_map>
#include <vector>
/* List of vector functionality
-push_back(): think insert in stacks
-pop_back(): pop in stacks
-erase(): remove(index)
-clear(): self explanatory
-vector v(x, y): creates x amount of y 
- size: return # of element in vector
- TEMPLATED, USE <int> and what else.
-no size assignment array

*/
#pragma once

using namespace std;

template <typename T>
class GraphVertex {
private:
public:

    T value; // value...what else do you want?
    enum status{ // will try out enum to see their functionality. WORKS LIKE COLOR. For DFS (and BFS)
        unseen = 0,
        seen = 1,
        done = 2
    };
    long f; // primarily for DFS
    long d; // for DFS (and BFS)
    long dt; // is this necessary or are we testing EITHER DFS OR BFS on ONE graph? 
    // the 2 below will act as an array of multiple parents and neighbors. They're all POINTERS.
    vector<GraphVertex*> neighbors; // multiple neighbors;
    vector<GraphVertex*> parents; // multiple parents; polygamy is legal


    // the 4 default member methods
    GraphVertex(); // constructor
    ~GraphVertex(); // destructor
    GraphVertex(const GraphVertex& other); //copy constructor (deep)
    GraphVertex& operator=(const GraphVertex& other); // operator=
};


#endif