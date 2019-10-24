#include "merge.h"
#include "catch.hpp"
#include <chrono>
#include <conio.h>

using namespace chrono;

void main()
{
	int rows = 10;
	for (int i = 0; i < 8; i++)
	{
		vector<Info> Mas;
		Input(Mas, pow(rows,i));

		auto mas_copy = Mas;

		auto t1 = std::chrono::high_resolution_clock::now();
		MergeSort<YEAR>(Mas);

		auto t2 = std::chrono::high_resolution_clock::now();
		double time = std::chrono::duration<double>(t2 - t1).count();
		printf("1)N: %.0f,\t time: %.5f sec\n", pow(rows, i), time);

		auto t3 = std::chrono::high_resolution_clock::now();
		std::sort(mas_copy.begin(), mas_copy.end(), Comparer<YEAR>());
		auto t4 = std::chrono::high_resolution_clock::now();
		double time1 = std::chrono::duration<double>(t4 - t3).count();
		printf("2)N: %.0f,\t time: %.5f sec\n\n", pow(rows, i), time1);
	}
	_getch();
}
