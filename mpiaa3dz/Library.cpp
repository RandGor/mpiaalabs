#pragma once

#include "Library.h"


Graph gen_random_graph(int nodes, int arcs) {
	Graph g;
	int i = 0;
	int a, b;
	for (int i = 0; i < nodes; i++)
		g.add_vertex(i);

	while (arcs > i)
	{
		a = rand() % nodes + 1;
		b = rand() % nodes + 1;
		g.add_arc(a, b);
		i++;
	}
	return g;
}

void measure(int nodes, int arcs) {
	Graph g = gen_random_graph(nodes, arcs);

	Timer t;

	t.start();
	const int repeats = 1;
	for (int i = 0; i < repeats; i++) {
		//gates_brute(g);
	}
	double sp_time = t.getTime() / repeats;

	printf("%d\t%d\t%10.5f\n", nodes, arcs, sp_time);
}

// функция для печати результата в файл
void result_to_file(vector<int> ans, const char* chars) {
	ofstream fout(chars);

	for (int p : ans)
		fout << p << " ";

	fout << endl;
	fout.close();
}