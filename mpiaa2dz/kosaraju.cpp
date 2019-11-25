#pragma once
#include "kosaraju.h"

// граф и транспонированный граф
Graph g, gr;

map<int, bool> used;
// упорядоченный список и список КСС
vector<int> order, component;

// функция поиска КСС
vector<vector<int>> find_scc(Graph graph) {
	vector<vector<int>> ans;

	// Рёбра

	used.clear();
	g.clear();
	gr.clear();
	order.clear();
	component.clear();

	g = graph;
	gr = graph.get_transponated();


	for (const auto& p : g.get_graph())
		used[p.first] = false;

	for (const auto& p : gr.get_graph())
		used[p.first] = false;


	for (const auto& p : g.get_graph())
		if (!used[p.first])
			dfs1(p.first);



	for (const auto& p : g.get_graph())
		used[p.first] = false;

	for (const auto& p : gr.get_graph())
		used[p.first] = false;

	
	std::reverse(order.begin(), order.end());

	for (int v : order) {
		if (!used[v]) {
			dfs2(v);
			if (component.size() > 1 || g.has_arc(v, v) )
				ans.push_back(component);
			component.clear();
		}
	}

	return ans;
}

// функция обхода в глубину
inline void dfs1(int v) {
	used[v] = true;

	std::set<int> gv = (g.get_graph()).at(v);

	for (int x : gv)
		if (!used[x])
			dfs1(x);
	order.push_back(v);
}

// функция обхода в глубину по транспонированному графу и поиск КСС
inline void dfs2(int v) {
	used[v] = true;
	component.push_back(v);

	std::set<int> grv = std::map<int, std::set<int>>(gr.get_graph())[v];

	for (int x : grv)
		if (!used[x])
			dfs2(x);
}