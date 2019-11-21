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
	const int repeats = 1;
	for (int i = 0; i < repeats; i++) {
		int a1 = rand() % size;
		int a2 = rand() % size;
		printf_s("_%d %d %d\n",size,a1,a2);
		path_exists(g, a1, a2);
	}
	double sp_time = t.getTime() / repeats;

	printf("N: %8d,time: %10.5f sec\n",
		size,sp_time);
}

int main(int argc, char* argv[]) {
	int result = Catch::Session().run(argc, argv);
	for (int i = 1; i < 7; i++) {
		measure(pow(10, i));
	}
	return 0;
}
