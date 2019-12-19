#pragma once

#define REPEATS 1

#include "catch.hpp"
#include "timer.h"
#include "electricity.h"
#include <fstream>
#include <conio.h>
#include <map>
#include <set>

// Generates random wire vector with n nodes and m wires
vector<Wire> gen_random_wires(int n, int m);

// Measuring brute algorithm test with given counts of nodes and arcs
void measure_brute(int nodes, int arcs);

// Measuring greedy algorithm test with given counts of nodes and arcs
void measure_greedy(int nodes, int arcs);

// Measuring accuracy of algorithms with given counts of nodes and arcs
void measure_accuracy(int nodes, int arcs);

// Reads given file and returns vector of wires
vector<Wire> read_from_file(const char* chars);

// Writes out results of both algorithms into two files
void result_to_files(vector<int> greedy, vector<int> brute);