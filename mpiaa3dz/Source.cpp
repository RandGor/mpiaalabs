#define CATCH_CONFIG_RUNNER

#include "Library.h"

int main(int argc, char* argv[])
{


	int a, b;
	int i = 0;
	std::vector<int> vertex;

	int v=0, e=0;	//v-vertex; e-edges

	std::ifstream in("input.txt");
	if (!in)
		return 2;
	while (!in.eof()) {
		in >> a >> b;
		for (i = 0; i < vertex.size(); i++)
			if (vertex[i]==a)
				break;
		if (i == vertex.size())
			vertex.push_back(a);

		for (i = 0; i < vertex.size(); i++)
			if (vertex[i] == b)
				break;
		if (i == vertex.size())
			vertex.push_back(b);
		e++;
	}
	v = vertex.size();

	in.close();


	std::map<int, int> stplus;
	int *stations = new int[v];
	std::vector<int *> wirplus;
	int **wires = new int*[e];

	in.open("input.txt");
	if (!in)
		return 2;

	i = 0;
	while (!in.eof()) {
		in >> a >> b;
		int *buff = new int[3]{ a,b,0 };
		wires[i] = buff;
		wirplus.push_back(buff);
		i++;
	}
	in.close();

	for (int p : vertex)
		stplus[p] = 0;

	for (i = 0; i < v; i++) stations[i] = 0;

	std::vector<int> exponed = gates_exp(v, e, stations, wires);

	for (i = 0; i < v; i++) stations[i] = 0;
	for (i = 0; i < e; i++) wires[i][2] = 0;

	std::vector<int> bruted = gates_brute(v, e, stations, wires);
	result_to_file(bruted, "output.txt");

	_getch();
	return 0;
}