#pragma once

#include "catch.hpp"
#include "graph.h"
#include "timer.h"
#include "kosaraju.h"
#include <algorithm>
#include <set>
#include <conio.h>

using namespace std;

Graph gen_random_graph(int nodes, int arcs);

void measure(int nodes, int arcs);

// функция для печати результата в файл
void result_to_file(vector<vector<int>> ans, const char* chars);