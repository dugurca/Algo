#pragma once
#include "stdafx.h"

class MergeSort
{
	MergeSort() {}

public:
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

	static void sort(vector<int>& v, vector<int>& aux, int lo, int hi)
	{
		if (lo >= hi) return;
		int mid = lo + (hi - lo) / 2;
		sort(v, aux, lo, mid);
		sort(v, aux, mid + 1, hi);
		merge(v, aux, lo, mid, hi);
	}

	static void sort(vector<int>& v)
	{
		int n = v.size();
		vector<int> aux(n);
		sort(v, aux, 0, n - 1);
	}
};
