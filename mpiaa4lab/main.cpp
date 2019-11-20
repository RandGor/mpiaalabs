#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include "path.h"

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

Graph gen_random_graph(int size) {
	Graph g;
	for (int i = 0; i < 10 * size; i++) {
		g.add_arc(rand() % size, rand() % size);
	}
	return g;
}

void measure(int size) {
	const auto g = gen_random_graph(size);

	Timer t;

	t.start();
	double cc_time = t.getTime();

	t.start();
	const int repeats = 10;
	for (int i = 0; i < repeats; i++) {
		path_exists(g, rand() % size, rand() % size);
		/*for (int j = 0; j < size - 1; j++)
		{
			for (int k = 0; k < j; k++)
			{
				path_exists(g, j, k); //только 2 рандомные вершины
			}
		}*/
	}
	double sp_time = t.getTime() / repeats;

	printf("N: %8d,time: %10.5f sec\n",
		size,sp_time);
}

int main() {
	for (int i = 1; i < 6; i++) {
		measure(pow(10, i));
	}
	return 0;


}
