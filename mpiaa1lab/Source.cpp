#include "merge.h"
#include "catch.hpp"
#include <chrono>

using namespace chrono;

void main()
{
	int rows = 10;
	for (int i = 0; i < 8; i++)
	{
		vector<Info> Mas;
		Input(Mas, pow(rows,i));

		auto t1 = std::chrono::high_resolution_clock::now();
		MergeSort<YEAR>(Mas);

		auto t2 = std::chrono::high_resolution_clock::now();
		double time = std::chrono::duration<double>(t2 - t1).count();
		printf("N: %.0f,\t time: %.5f sec\n", pow(rows, i), time);
	}
}

