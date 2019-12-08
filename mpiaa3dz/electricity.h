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

bool isContains(vector<int> set, int node);

bool isContains(vector<Wire> set, Wire node);

bool isCovers(vector<Wire> wires, vector<int> generators, vector<int> set);

int vertexAdjCount(vector<Wire> wires, int node);

vector<vector<int>> appendix(vector<vector<int>> previous, vector<int> vertexes);

vector<int> getVertexes(vector<Wire> wires);

/// euristic
vector<int> gates_greedy(vector<Wire> wires);
/// brute
vector<int> gates_brute(vector<Wire> wires);