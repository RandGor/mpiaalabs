#pragma once

#include "Library.h"

template <typename Container>
bool is_equal(const Container& c1, const Container& c2) {
	const auto s1 = set<typename Container::value_type>(c1.begin(), c1.end());
	const auto s2 = set<typename Container::value_type>(c2.begin(), c2.end());
	return s1 == s2;
}

TEST_CASE("[Electricity] Test empty set", "[isContains<int>]") {
	vector<int> set;
	CHECK_FALSE(isContains(set,0));
}

TEST_CASE("[Electricity] Test filled set", "[isContains<int>]") {
	vector<int> set{ 1,2,3,5,6,7 };
	CHECK(isContains(set, 3));
	CHECK_FALSE(isContains(set, 4));
}

TEST_CASE("[Electricity] Test filled wireset", "[isContains<Wire>]") {
	vector<Wire> set{ {1,2},{2,3},{4,6} };
	CHECK(isContains(set, { 1,2 }));
	CHECK_FALSE(isContains(set, {1,3}));
}

TEST_CASE("[Electricity] Test if set isCovers", "[isCovers]") {
	vector<Wire> wires{ {1,2},{2,3},{4,6} };
	vector<int> generators{ 1,2,3,4,6 };
	CHECK(isCovers(wires, generators, { 2,4 }));
	CHECK_FALSE(isCovers(wires, generators, { 4 }));
}

TEST_CASE("[Electricity] Test adjacent vertex count", "[vertexAdjCount]") {
	vector<Wire> wires{ {1,2},{2,3},{4,6} };
	vector<int> generators{ 1,2,3,4,6 };
	CHECK(vertexAdjCount(wires, 4) == 1);
	CHECK(vertexAdjCount(wires, 2) == 2);
}

TEST_CASE("[Electricity] Test appendix", "[appendix]") {
	vector<vector<int>> prev{ {1},{2},{3} };
	vector<int> nodes{ 1,2,3 };
	vector<vector<int>> wanted{ {1,2},{1,3},{2,3} };
	CHECK(is_equal(appendix(prev, nodes), wanted));
}

TEST_CASE("[Electricity] Test get vertexes", "[getVertexes]") {
	vector<Wire> wires{ {1,2},{2,3},{4,6} };
	CHECK(is_equal(getVertexes(wires), { 1,2,3,4,6 }));
	CHECK_FALSE(is_equal(getVertexes(wires), { 1,2,3,4 }));
}

TEST_CASE("[Electricity] Test one station no wires (greedy)", "[getcover_greedy]") {
	vector<Wire> wires{ {1,1} };
	CHECK(is_equal(getcover_greedy(wires), {1}));
}

TEST_CASE("[Electricity] Test one station no wires (brute)", "[getcover_brute]") {
	vector<Wire> wires{ {1,1} };
	CHECK(is_equal(getcover_brute(wires), { 1 }));
}

TEST_CASE("[Electricity] Test three negative stations no wires (greedy)", "[getcover_greedy]") {
	vector<Wire> wires{ {-1,-1},{1,1},{-7,-7} };
	CHECK(is_equal(getcover_brute(wires), { -1,1,-7 }));
}

TEST_CASE("[Electricity] Test three negative stations no wires (brute)", "[getcover_brute]") {
	vector<Wire> wires{ {-1,-1},{1,1},{-7,-7} };
	CHECK(is_equal(getcover_brute(wires), { -1,1,-7 }));
}

TEST_CASE("[Electricity] Test three stations one wire (greedy) fail", "[getcover_greedy]") {
	vector<Wire> wires{ {-1,1},{-7,-7} };
	vector<int> result = getcover_greedy(wires);
	bool br = is_equal(result, { -1,-7 }) || is_equal(result, { 1,-7 });
	CHECK_FALSE(br);
}

TEST_CASE("[Electricity] Test three stations one wire (brute)", "[getcover_brute]") {
	vector<Wire> wires{ {-1,1},{-7,-7} };
	vector<int> result = getcover_brute(wires);
	bool br = is_equal(result, { -1,-7 }) || is_equal(result, { 1,-7 });
	CHECK(br);
}

TEST_CASE("[Electricity] Test three stations two wires (greedy)", "[getcover_greedy]") {
	vector<Wire> wires{ {-1,1},{1,-7} };
	vector<int> result = getcover_greedy(wires);
	bool br = is_equal(result, { 1 });
	CHECK(br);
}

TEST_CASE("[Electricity] Test three stations two wires (brute)", "[getcover_brute]") {
	vector<Wire> wires{ {-1,1},{1,-7} };		//-1 - 1
	vector<int> result = getcover_brute(wires);//   -7
	bool br = is_equal(result, { 1 });
	CHECK(br);
}

TEST_CASE("[Electricity] Test three stations three wires, triangle (greedy)", "[getcover_greedy]") {
	vector<Wire> wires{ {-1,1},{1,-7},{-7,-1} };//-7 - -1
	vector<int> result = getcover_greedy(wires);// \ 1 /
	bool br = is_equal(result, { -1 }) || is_equal(result, { 1 }) || is_equal(result, { -7 });
	CHECK(br);
}

TEST_CASE("[Electricity] Test three stations three wires, triangle (brute)", "[getcover_brute]") {
	vector<Wire> wires{ {-1,1},{1,-7},{-7,-1} };//-7 - -1
	vector<int> result = getcover_brute(wires);//  \ 1 /
	bool br = is_equal(result, { -1 }) || is_equal(result, { 1 }) || is_equal(result, { -7 });
	CHECK(br);
}

TEST_CASE("[Electricity] Test five stations four wires, flat (greedy) fail", "[getcover_greedy]") {
	vector<Wire> wires{ {1,2},{2,3},{3,4},{4,5} };//1 - 2 - 3 - 4 - 5
	vector<int> result = getcover_greedy(wires);
	bool br = is_equal(result, { 1,4 }) || is_equal(result, { 2,4 }) || is_equal(result, { 2,5 });
	CHECK_FALSE(br);
}

TEST_CASE("[Electricity] Test five stations four wires, flat (brute)", "[getcover_brute]") {
	vector<Wire> wires{ {1,2},{2,3},{3,4},{4,5} };//1 - 2 - 3 - 4 - 5
	vector<int> result = getcover_brute(wires);
	bool br = is_equal(result, { 1,4 }) || is_equal(result, { 2,4 }) || is_equal(result, { 2,5 });
	CHECK(br);
}