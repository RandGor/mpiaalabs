#define CATCH_CONFIG_RUNNER
#include "library.h"
#include "catch.hpp"

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

vector<int> findKSS(Graph g) {
	vector<int> ans;

	// Рёбра
	int a, b;


	while (!in.eof()) {
		in >> a >> b;
		g.add_arc(a, b);
		gr.add_arc(b, a);
	}

	for (const auto& p : g.get_graph()) {
		used[p.first] = false;
	}
	for (const auto& p : gr.get_graph()) {
		used[p.first] = false;
	}

	for (const auto& p : g.get_graph()) {
		if (!used[p.first])
			dfs1(p.first);
	}


	for (const auto& p : g.get_graph()) {
		used[p.first] = false;
	}
	for (const auto& p : gr.get_graph()) {
		used[p.first] = false;
	}


	std::reverse(order.begin(), order.end());
	for (int p : order) {
		int v = p;
		if (!used[v]) {
			dfs2(v);
			if (component.size() > 1) {
				ans = component;
			}
			component.clear();
		}
	}

	return ans;
}

int main()
{
	ifstream in("input.txt");
	// если файл не открылся
	if (!in)
	{
		return 0;
	}

	// Рёбра
	int a, b;


	while (!in.eof()) {
		in >> a >> b;
		g.add_arc(a, b);
		gr.add_arc(b, a);
	}

	for (const auto &p : g.get_graph()) {
		used[p.first] = false;
	}
	for (const auto &p : gr.get_graph()) {
		used[p.first] = false;
	}

	for (const auto &p : g.get_graph()) {
		if (!used[p.first])
			dfs1(p.first);
	}


	for (const auto &p : g.get_graph()) {
		used[p.first] = false;
	}
	for (const auto &p : gr.get_graph()) {
		used[p.first] = false;
	}
	ofstream fout("output.txt");

	std::reverse(order.begin(), order.end());
	for (int p : order) {
		int v = p;
		if (!used[v]) {
			dfs2(v);
			if (component.size() > 1) {
				for (size_t j = 0; j < component.size(); j++)
					fout << component[j] << " ";
				fout << endl;
			}
			component.clear();
		}
	}
	in.close();
	fout.close();

	return 1;
}