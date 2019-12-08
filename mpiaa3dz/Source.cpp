#define CATCH_CONFIG_RUNNER

#include "Library.h"

int main(int argc, char* argv[])
{
	// Tests
	Catch::Session().run(argc, argv);

	int a, b;
	int swap;

	vector<Wire> wires;

	ifstream in("input.txt");

	while (in && !in.eof()) {
		in >> a >> b;	
		if (a > b)
		{
			swap = a;
			a = b;
			b = swap;
		}
		Wire buffer(a, b);
		if (!isContains(wires,buffer))
			wires.push_back(buffer);
	}
	in.close();

	vector<int> greedy = gates_greedy(wires);
	vector<int> bruted = gates_brute(wires);
	
	result_to_files(greedy, bruted);

	//_getch();
	return 0;
}