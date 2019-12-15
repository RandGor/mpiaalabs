#pragma once
#include "electricity.h"

Wire::Wire(int A, int B) {
	a = A;
	b = B;
};

bool isContains(vector<int> set, int node) {
	for (int w : set)
		if (w == node) 
			return true;
	return false;
}

bool isContains(vector<Wire> set, Wire node) {
	for (Wire w : set)
		if (w.a == node.a && w.b == node.b)
			return true;
	return false;
}

bool isCovers(vector<Wire> wires, vector<int> generators, vector<int> set) {
	vector<int> lighted;
	for (int p : set)
		for (Wire wire : wires)
			if (wire.a == p || wire.b == p)
			{
				if (!isContains(lighted, wire.a))
					lighted.push_back(wire.a);
				if (!isContains(lighted, wire.b))
					lighted.push_back(wire.b);
			}

	sort(lighted.begin(), lighted.end());
	sort(generators.begin(), generators.end());
	return lighted == generators;
}

int vertexAdjCount(vector<Wire> wires, int node) {
	int ans = 0;
	for (Wire wire:wires)
		if (wire.a == node || wire.b == node)
			ans++;
	return ans;
}

vector<vector<int>> appendix(vector<vector<int>> previous, vector<int> vertexes) {
	sort(vertexes.begin(), vertexes.end());
	int hs = previous.size();
	int vs = vertexes.size();

	vector<vector<int>> newious;
	vector<int> buffer;


	for (int i = 0; i < hs; i++)
	{
		for (int j = 0; j < vs; j++)
		{
			buffer = previous[i];
			while (buffer.size() != 0 && buffer.back() > vertexes[j])
				j++;
			if (buffer.size() == 0 || buffer.back() < vertexes[j])
			{
				buffer.push_back(vertexes[j]);
				newious.push_back(buffer);
			}
		}
	}
	return newious;
}

vector<int> getVertexes(vector<Wire> wires) {
	vector<int> vertexes;
	for (Wire wire : wires) {
		if (!isContains(vertexes, wire.a))
			vertexes.push_back(wire.a);

		if (!isContains(vertexes, wire.b))
			vertexes.push_back(wire.b);
	}
	return vertexes;
}

vector<int> getcover_greedy(vector<Wire> wires) {
	vector<int> ans;

	vector<int> vertexes = getVertexes(wires);
	vector<int> workset = vertexes;
	vector<int> weight;

	for (int p : workset)
		weight.push_back(vertexAdjCount(wires, p));

	int vs = workset.size();
	int imax;
	while (vs>0)
	{
		imax = 0;
		for (int i = 1; i < vs; i++)
			if (weight[i] > weight[imax])
				imax = i;
		ans.push_back(workset[imax]);
		weight.erase(weight.begin() + imax);
		workset.erase(workset.begin() + imax);
		vs = workset.size();
		if (isCovers(wires, vertexes, ans))
			break;
	}

	return ans;
}

vector<int> getcover_brute(vector<Wire> wires) {
	vector<int> ans;
	vector<int> vertexes = getVertexes(wires);

	int vs = vertexes.size();
	int ws = wires.size();

	vector<vector<int>> combinations = { {} };

	for (int i = 1; i <= vs; i++)
	{
		combinations = appendix(combinations, vertexes);
		for (vector<int> p : combinations) {
			if (isCovers(wires, vertexes, p))
			{
				ans = p;
				i = vs;
				break;
			}
		}
	}
	return ans;
}