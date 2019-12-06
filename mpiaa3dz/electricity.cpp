#pragma once
#include "electricity.h"
#include "timer.h"
#include <conio.h>

using namespace std;

std::vector<int> gates_exp(int v, int e, int* stations, int** wires) {
	std::vector<std::vector<int>> stat_arr;
	int i, fl;
	for (const auto &stat : stat_arr) {
		for (auto num : stat) {
			stations[num] = 1;
		}


		for (int iter = 0; iter < e; iter++) {
			for (i = 0; i < e; i++) {
				if (stations[wires[i][0]] == 1 || stations[wires[i][1]] == 1) {
					wires[i][2] = 1;
				}

			}
		}

		fl = 1;
		i = 0;
		while (fl == 1 && i < e) {
			if (wires[i][2] != 1) fl = 0;
			i++;
		}

		if (fl == 1) {

			std::vector<int> unwired;
			for (i = 0; i < v; i++) {
				unwired.push_back(i);
			}

			for (i = 0; i < e; i++) {
				if (find(unwired.begin(), unwired.end(), wires[i][0]) != unwired.end()) {
					unwired.erase(find(unwired.begin(), unwired.end(), wires[i][0]));
				}
				if (find(unwired.begin(), unwired.end(), wires[i][1]) != unwired.end()) {
					unwired.erase(find(unwired.begin(), unwired.end(), wires[i][1]));
				}
			}

			for (int i : unwired) {
				if (stations[i] == 0) {
					fl = 0;
					break;
				}
			}


		}

		if (fl == 1) return stat;

		for (i = 0; i < v; i++) stations[i] = 0;
		for (i = 0; i < e; i++) wires[i][2] = 0;
	}
}

std::vector<int> gates_brute(int v, int e, int* stations, int** wires) {
	int i, j, k, fl;
	std::vector<int> stat_arr;
	for (i = 0; i < v; i++) {
		if (stations[i] == 0) {
			stat_arr.push_back(i);
			stations[i] = 1;
		}
		j = 0; fl = 1;
		while (fl == 1 && j < e) {
			if ((wires[j][0] == i || wires[j][1] == i) && wires[j][2] == 1) {
				stat_arr.pop_back();
				fl = 0;
			}
			j++;
		}
		if (fl == 1) {
			for (j = 0; j < e; j++) {
				for (k = 0; k < e; k++)
					if (stations[wires[k][0]] == 1 || stations[wires[k][1]] == 1) {
						wires[k][2] = 1;
					}
			}
		}

	}
	return stat_arr;


}
