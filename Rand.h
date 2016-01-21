#pragma once
#include "stdafx.h"

class Rand
{
	random_device rd;
	mt19937 gen;
public:
	Rand()
	{
		gen.seed(rd());
	}

	int getInt(int a = 0, int b = INT_MAX)
	{
		uniform_int_distribution<int> unif(a, b);
		return unif(gen);
	}

	vector<int> getRandIntVec(int n, int a = 0, int b = INT_MAX)
	{
		vector<int> v(n);
		uniform_int_distribution<int> unif(a, b);
		for (int i = 0; i < n; i++)
			v[i] = unif(gen);
		return v;
	}
};