#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include "timer.h"

using namespace std;

class Wire {
public:
	int a;
	int b;
	Wire(int A, int B);
};

// If int node in vector
bool isContains(vector<int> set, int node);

// If wire node in vector
bool isContains(vector<Wire> set, Wire node);

// If set covers generators with wires
bool isCovers(vector<Wire> wires, vector<int> generators, vector<int> set);

// Returns count of adjacent nodes in node
int vertexAdjCount(vector<Wire> wires, int node);

// Creates new vector of vectors that contains new unique elements from vertexes, little first
vector<vector<int>> appendix(vector<vector<int>> previous, vector<int> vertexes);

// Returns unique vertexes in wire vector
vector<int> getVertexes(vector<Wire> wires);

// Returns minimum cover set using greedy algorithm
vector<int> getcover_greedy(vector<Wire> wires);

// Returns minimum cover set using brute algorithm
vector<int> getcover_brute(vector<Wire> wires);