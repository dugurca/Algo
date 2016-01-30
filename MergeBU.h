#pragma once
#include "stdafx.h"

class MergeBU
{
	MergeBU() {}

	static void merge(vector<int>& v, vector<int>& aux, int lo, int mid, int hi)
	{
		for (int k = lo; k <= hi; k++) 
			aux[k] = v[k];

		int i = lo, j = mid + 1;
		for (int k = lo; k <= hi; k++)
		{
			if (i > mid) v[k] = aux[j++];
			else if (j > hi) v[k] = aux[i++];
			else if (aux[i] > aux[j]) v[k] = aux[j++];
			else v[k] = aux[i++];
		}
	}

	static void sortBu(vector<int>& v, vector<int>& aux)
	{
		int n = v.size();
		for (int s = 1; s < n; s *= 2)
		{
			for (int lo = 0; lo < n - s; lo += 2 * s)
				merge(v, aux, lo, lo + s - 1, min(lo + 2 * s - 1, n - 1));
		}
	}

public:
	static void sort(vector<int>& v)
	{
		vector<int> aux(v.size());
		sortBu(v, aux);
	}
};
