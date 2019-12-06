#pragma once

#include <vector>
#include <algorithm>
#include "graph.h"
using namespace std;

/// euristic
vector<int> gates_exp(int v, int e, int* stations, int** wires);

/// brute
vector<int> gates_brute(int v, int e, int* stations, int** wires);
