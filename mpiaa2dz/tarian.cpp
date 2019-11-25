#pragma once

#include "tarian.h"

Graph graph;

map<int, bool> visited_tarian;

stack<int> stack1;
int times_visited;

map<int, int> lowlink;

vector<vector<int>> components_tarian;
vector<int> component_tarian;

vector<vector<int>> scc_tarian(Graph g) {

	graph = g;
	visited_tarian.clear();

	for (const auto& p : g.get_graph())
		visited_tarian[p.first] = false;


	stack1 = stack<int>();
	times_visited = 0;
	lowlink.clear();			

	components_tarian.clear();



	for (auto u : visited_tarian)
		if (!visited_tarian[u.first])
			dfs_tarian(u.first);


	return components_tarian;
}

void dfs_tarian(int u) {
	lowlink[u] = times_visited++;
	visited_tarian[u] = true;
	stack1.push(u);
	bool isComponentRoot = true;
	component_tarian.clear();


	std::set<int> gu = (graph.get_graph()).at(u);

	for (int v : gu) {
		if (!visited_tarian[v])
			dfs_tarian(v);
		if (lowlink[u] > lowlink[v]) {
			lowlink[u] = lowlink[v];
			isComponentRoot = false;
		}
	}

	if (isComponentRoot) {
		while (true) {
			int x = stack1.top();
			stack1.pop();
			component_tarian.push_back(x);
			lowlink[x] = 0x7FFFFFFF;
			if (x == u)
				break;
		}
		if (component_tarian.size() > 1 || graph.has_arc(u, u))
			components_tarian.push_back(component_tarian);
	}
}