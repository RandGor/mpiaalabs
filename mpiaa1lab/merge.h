#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <time.h>
#include <algorithm>
using namespace std;

struct Info
{
	int Birth;
	char Name[15];
	char SurName[20];
};

enum keys
{
	NAME, SURNAME, YEAR
};

void AddPerson(vector<Info>& Mas, Info temp)
{
	Mas.push_back(temp);
}

template <keys T>
struct Comparer {
	bool operator ()(const Info &m1, const Info &m2) const {
		return (T == YEAR ? m1.Birth > m2.Birth : strcmp(m1.Name, m2.Name) > 0);
	}
};

void Input(vector<Info>& Mas, int count)
{
	ifstream In("input.txt");
	Info temp;
	int i = 0;
	while (!In.eof() && i<count)
	{
		In >> temp.Name;
		In >> temp.SurName;
		In >> temp.Birth;
		AddPerson(Mas, temp);
		i++;
	}
	In.close();
}



template <keys T>
void merge(vector<Info>& vArray, vector<Info>& vTemp, int head, int middle, int tail)
{
	int tmp = 0, lower = head, upper = middle + 1;

	while (lower <= middle && upper <= tail)
	{
		if (/*Comparer<T>(vArray[upper], vArray[lower])) {*/(T == YEAR ? vArray[upper].Birth > vArray[lower].Birth : strcmp(vArray[upper].Name, vArray[lower].Name) > 0))
		{
			vTemp[tmp++] = vArray[lower++];
		}
		else
		{
			vTemp[tmp++] = vArray[upper++];
		}
	}

	if (lower <= middle)
	{
		for (; lower <= middle; vTemp[tmp++] = vArray[lower++]);
	}
	else
	{
		for (; upper <= tail; vTemp[tmp++] = vArray[upper++]);
	}

	int arrayPointer = head;
	for (tmp = 0; arrayPointer <= tail; vArray[arrayPointer++] = vTemp[tmp++]);
}

template <keys T>
inline void merge_sort_helper(vector<Info>& vArray, vector<Info>& vTemp, int head, int tail)
{
	if (head == tail)
	{
		return;
	}

	int middle = (head + tail) / 2;

	merge_sort_helper<T>(vArray, vTemp, head, middle);
	merge_sort_helper<T>(vArray, vTemp, middle + 1, tail);

	merge<T>(vArray, vTemp, head, middle, tail);
}

template <keys T>
void MergeSort(vector<Info>& vArray)
{
	vector<Info> v(vArray.size(), vArray[0]);
	merge_sort_helper<T>(vArray, v, 0, vArray.size() - 1);
}


void Print(const vector<Info> Mas)
{
	ofstream Out("Sort.txt");
	for (int i = 0; i < (int)Mas.size(); i++)
		Out << Mas[i].Name << " " << Mas[i].SurName << " " << Mas[i].Birth << "\n";
	Out.close();
}

template<keys T>
bool isSorted(vector<Info> Mas)
{
	for (int i = 0; i < Mas.size() - 1; i++)
	{
		if (T == YEAR)
			if (Mas[i].Birth < Mas[i + 1].Birth)
				return false;
			else if (strcmp(Mas[i].Name, Mas[i + 1].Name) < 0)
				return false;

	}
	return true;
}