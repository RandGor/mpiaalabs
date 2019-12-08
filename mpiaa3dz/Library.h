#pragma once

#include "catch.hpp"
#include "timer.h"
#include "electricity.h"
#include <fstream>
#include <conio.h>
#include <map>
#include <set>

vector<Wire> gen_random_wires(int n, int m);

void measure(int nodes, int arcs);

// функция для печати результата в файл
void result_to_files(vector<int> greedy, vector<int> brute);