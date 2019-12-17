#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <locale.h>
using namespace std;
// граф и транспонированный граф
vector < vector<int> > g, gr;
vector<bool> used;
// упорядоченный список и список КСС
vector<int> order, component;
// Функция обхода в глубину
void dfs1(int v) {
	used[v] = true;
	for (size_t i = 0; i < g[v].size(); i++)
		if (!used[g[v][i]])
			dfs1(g[v][i]);
	order.push_back(v);
}
// функция обхода в глубину по транспонированному графу и поиск КСС
void dfs2(int v) {
	used[v] = true;
	component.push_back(v);
	for (size_t i = 0; i < gr[v].size(); i++)
		if (!used[gr[v][i]])
			dfs2(gr[v][i]);
}