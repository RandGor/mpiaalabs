#pragma once

#include "Library.h"

template <typename Container>
bool is_equal(const Container& c1, const Container& c2) {
	const auto s1 = std::set<typename Container::value_type>(c1.begin(), c1.end());
	const auto s2 = std::set<typename Container::value_type>(c2.begin(), c2.end());
	return s1 == s2;
}

TEST_CASE("[Electricity] Empty set", "[isContains]") {
	vector<int> set;
	CHECK_FALSE(isContains(set,0));
}

TEST_CASE("[Electricity] Filled set", "[isContains]") {
	vector<int> set{ 1,2,3,5,6,7 };
	CHECK(isContains(set, 3));
	CHECK_FALSE(isContains(set, 4));
}

TEST_CASE("[Electricity] Filled set2", "[isCovers]") {
	map<int, int> stplus;
	vector<int*> wirplus;/*
	vector<int> set{ 1,2,3,5,6,7 };
	CHECK(isCovers(set, 3));
	CHECK_FALSE(isCovers(set, 4));*/
}