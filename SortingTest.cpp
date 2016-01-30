#include "InsertionSort.h"
#pragma once
#include "MergeSort.h"
#include "HybridSort.h"

int main_SortingTest()
{
	Rand r;

	for (int i = 0; i < 10; i++)
	{
		auto k = r.getRandIntVec(1000);
		auto k1 = k;
		auto k2 = k;

		InsertionSort::sort(k);
		assert(isSorted(k));
		
		MergeSort::sort(k1);
		assert(isSorted(k1));
		
		HybridSort::sort(k2);
		assert(isSorted(k2));
				
	}

	cout << "Sorting tests passed" << endl;

	return 0;
}
