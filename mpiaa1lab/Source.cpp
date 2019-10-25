#include "merge.h"
#include "catch.hpp"
#include <chrono>
#include <conio.h>

using namespace chrono;
using namespace std;

void main()
{
	int rows = 10;
	for (int i = 0; i < 8; i++)
	{
		vector<Info> Mas;
		Input(Mas, pow(rows,i));

		auto mas_copy = Mas;

		auto t1 = high_resolution_clock::now();
		MergeSort<YEAR>(Mas);
		auto t2 = high_resolution_clock::now();
		double time = duration<double>(t2 - t1).count();
		printf("1)N: %.0f,\t time: %.5f sec\n", pow(rows, i), time);

		auto t3 = high_resolution_clock::now();
		sort(mas_copy.begin(), mas_copy.end(), Comparer<YEAR>());
		auto t4 = chrono::high_resolution_clock::now();
		double time1 = duration<double>(t4 - t3).count();
		printf("2)N: %.0f,\t time: %.5f sec\n\n", pow(rows, i), time1);

	}

	_getch();
}
