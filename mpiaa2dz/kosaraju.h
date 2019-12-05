#pragma once

#include <vector>
#include "graph.h"
using namespace std;


// функция поиска КСС - Strongly Connected Component
vector<vector<int>> find_scc(Graph graph);

// функция обхода в глубину
void dfs1(int v);

// функция обхода в глубину по транспонированному графу и поиск КСС
void dfs2(int v);