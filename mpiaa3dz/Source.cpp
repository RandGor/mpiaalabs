#define CATCH_CONFIG_RUNNER

#include "Library.h"

int main(int argc, char* argv[])
{
	Catch::Session().run(argc, argv);
	int a, b;
	int swap;

	vector<Wire> wires = read_from_file("input.txt");

	vector<int> greedy = getcover_greedy(wires);
	vector<int> bruted = getcover_brute(wires);
	
	result_to_files(greedy, bruted);

	printf("Nodes\tEdges\tTime\n");
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j < 10; j++)
			measure_greedy(pow(10, i) * j, pow(10, i) * j);
	_getch();
	return 0;
}