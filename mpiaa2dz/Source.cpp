#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "library.h"

typedef std::chrono::high_resolution_clock hrc;

namespace {
	class Timer {
	public:
		Timer() {}

		void start() {
			begin = hrc::now();
		}

		double getTime() {
			return std::chrono::duration<double>(hrc::now() - begin).count();
		}

	private:
		hrc::time_point begin;
	};
}

Graph gen_random_graph(int nodes, int arcs) {
	Graph g;
	int i = 0;
	int a, b;
	for (int i = 0; i < nodes; i++)
		g.add_vertex(i);
	
	while (arcs > i)
	{
		a = rand() % nodes;
		b = rand() % nodes;
		if (g.has_arc(a, b))
			continue;
		g.add_arc(a, b);
		i++;
	}
	return g;
}

void measure(int nodes, int arcs) {
	Graph g = gen_random_graph(nodes, arcs);
	
	Timer t;

	t.start();
	double cc_time = t.getTime();

	t.start();
	const int repeats = 1;
	for (int i = 0; i < repeats; i++) {
		find_SCC(g);
	}
	double sp_time = t.getTime() / repeats;

	printf("%d\t%d\t%10.5f\n", nodes, arcs, sp_time);
}

int main(int argc, char* argv[])
{
	Graph graph;
	vector<vector<int>> ans;

	// Tests
	Catch::Session().run(argc, argv);

	// Tests in files
	graph.read_from_file("input.txt");
	ans = find_SCC(graph);
	result_to_file(ans, "output.txt");

	// Time tests for large graphs
	printf("Nodes\tEnges\tTime\n");
	for (int i = 1; i <= 4; i++) {
		measure(pow(10, i), 3*pow(10, i));
	}

	return 1;
}