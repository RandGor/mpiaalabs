#pragma once

#include "Library.h"

vector<Wire> gen_random_wires(int n, int m) {
	return {};
}

void measure(int nodes, int arcs) {
	//Graph g = gen_random_graph(nodes, arcs);

	//Timer t;

	//t.start();
	//const int repeats = 1;
	//for (int i = 0; i < repeats; i++) {
	//	//gates_brute(g);
	//}
	//double sp_time = t.getTime() / repeats;

	//printf("%d\t%d\t%10.5f\n", nodes, arcs, sp_time);
}

// функция для печати результата в файл
void result_to_files(vector<int> greedy, vector<int> brute) {
	ofstream fout;
	fout.open("greedy.txt");
	for (int p : greedy)
		fout << p << " ";
	fout.close();
	fout.open("brute.txt");
	for (int p : brute)
		fout << p << " ";
	fout.close();
}