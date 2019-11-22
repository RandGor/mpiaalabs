#include "library.h"
int main()
{
	setlocale(0, "");
	int count = 0;
	ifstream in("input.txt");
	// если файл не открылся
	if (!in)
	{
		printf_s("Не удалось открыть файл input.txt");
		in.close();
		_getch();
		return 0;
	}

	// Рёбра
	int a, b;


	while (!in.eof()) {
		in >> a >> b;
		// Проверка присутствуют ли среди вершин отрицательные, не или равные 0.
		if (a <= 0 || b <= 0) {
			printf_s("Невозможно построить с заданными вершинами компоненты сильной связанности.\nНомера вершин должны быть положительными и не превышать n");
			in.close();
			_getch();
			return 0;
		}
		else 
			g.add_arc(a, b);
		gr.add_arc(b, a);
	}

	for (const auto &p : g.get_graph()) {
		used[p.first] = false;
	}
	for (const auto &p : gr.get_graph()) {
		used[p.first] = false;
	}
	//int n = g.get_size();

	for (const auto &p : g.get_graph()) {
		if (!used[p.first])
			dfs1(p.first);
	}

	//for (int i = 0; i < n; i++)
	//	if (!used[i])
	//		dfs1(i);


	for (const auto &p : g.get_graph()) {
		used[p.first] = false;
	}
	for (const auto &p : gr.get_graph()) {
		used[p.first] = false;
	}
	ofstream fout("output.txt");

	std::reverse(order.begin(), order.end());
	for (int p : order) {
	//	used[p.first] = false;
	//}

	//for (int i = 0; i < n; i++)	{
		//int v = order[n - 1 - i];
		int v = p;
		if (!used[v]) {
			dfs2(v);
			if (component.size() > 1) {
				for (size_t j = 0; j < component.size(); j++)
					fout << component[j] << " ";
				fout << endl;
				count++;
			}
			component.clear();
		}
	}
	in.close();
	fout.close();
	if (count == 0) {
		printf_s("Не удалось построить ни одной КСС");
		_getch();
		return 0;
	}
}