#define CATCH_CONFIG_RUNNER

#include "Library.h"

int main(int argc, char* argv[])
{
	Graph graph;
	vector<vector<int>> ans;

	// Tests
	Catch::Session().run(argc, argv);

	// Tests in files
	graph.read_from_file("input.txt");
	ans = find_scc(graph);
	result_to_file(ans, "output.txt");

	// Time tests for large graphs
	printf("Nodes\tEdges\tTime\n");
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j < 10; j++)
		{
			measure(pow(10, i)*j, pow(10, i)*j);
		}
	}

	return 1;
}