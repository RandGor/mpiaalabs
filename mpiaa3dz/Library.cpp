#pragma once

#include "Library.h"

vector<Wire> gen_random_wires(int nodes, int arcs) {
	vector<Wire> ans;
	int a, b, swap;
	for (int i = 0; i < arcs; i++) {
		a = rand() % nodes;
		b = rand() % nodes;
		if (a < b) {
			swap = a;
			a = b;
			b = swap;
		}
		ans.push_back(Wire(a, b));
	}

	return ans;
}

void measure_brute(int nodes, int arcs) {
	Timer t;
	vector<Wire> wires;
	double time = 0;
	for (int i = 0; i < REPEATS; i++) {
		wires = gen_random_wires(nodes, arcs);
		t.start();
		getcover_brute(wires);
		time += t.getTime();
	}

	printf("%d\t%d\t%10f\n", nodes, arcs, time / REPEATS);
}

void measure_greedy(int nodes, int arcs) {
	Timer t; 
	vector<Wire> wires;
	double time = 0;
	for (int i = 0; i < REPEATS; i++) {
		wires = gen_random_wires(nodes, arcs);
		t.start();
		getcover_greedy(wires);
		time += t.getTime();
	}

	printf("%d\t%d\t%10f\n", nodes, arcs, time / REPEATS);
}

vector<Wire> read_from_file(const char* chars) {
	vector<Wire> wires;
	int a, b, swap;
	
	ifstream in(chars);
	if (!in)
		return {};

	while (in && !in.eof()) {
		in >> a >> b;
		if (a > b)
		{
			swap = a;
			a = b;
			b = swap;
		}
		Wire buffer(a, b);
		if (!isContains(wires, buffer))
			wires.push_back(buffer);
		in.close();
		return wires;
	}
}

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