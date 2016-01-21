#pragma once

#include "stdafx.h"
#include "Rand.h"

#include "InsertionSort.h"
#include "MergeSort.h"

inline bool isSorted(vector<int>& v)
{
	int n = v.size();
	for (int i = 0; i < n - 1; i++)
		if (v[i] > v[i + 1]) return false;
	return true;
}

int main_SortingTests()
{
	Rand r;

	for (int i = 0; i < 10; i++)
	{
		auto k = r.getRandIntVec(100);
		auto k1 = k;

		InsertionSort::sort(k);
		assert(isSorted(k));
		MergeSort::sort(k1);
		assert(isSorted(k1));
	}

	cout << "Sorting tests passed" << endl;

	return 0;
}
