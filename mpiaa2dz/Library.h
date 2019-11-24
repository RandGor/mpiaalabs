#pragma once
#include <string>
#include <vector>
#include <conio.h>
#include <locale.h>
#include "graph.h"
using namespace std;


// функция поиска КСС - Strongly Connected Component
vector<vector<int>> find_SCC(Graph graph);

// функция обхода в глубину
void dfs1(int v);

// функция обхода в глубину по транспонированному графу и поиск КСС
void dfs2(int v);

// функция для печати результата в файл
void result_to_file(vector<vector<int>> ans, const char* chars);