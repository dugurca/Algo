#pragma once

#include "stdafx.h"

class InsertionSort
{
	InsertionSort() {}

public:
	static void sort(vector<int>& v)
	{
		int n = v.size();
		for (int i = 1; i < n; i++)
		{
			for (int j = i; j > 0 && v[j] < v[j - 1]; j--)
				swap(v[j], v[j - 1]);
		}
	}
};
