#pragma once
#include "stdafx.h"

inline bool isSorted(vector<int>& v)
{
	int n = v.size();
	for (int i = 0; i < n - 1; i++)
		if (v[i] > v[i + 1]) return false;
	return true;
}