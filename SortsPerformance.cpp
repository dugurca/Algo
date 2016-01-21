#include "MergeSort.h"
#include "InsertionSort.h"
#include "HybridSort.h"

double sortTime(int method, int numSize, int repeat)
{
	Rand r;
	Timer t;
	double res = 0.0;
	for (int j = 0; j < repeat; j++)
	{
		auto vec = r.getRandIntVec(numSize);
		t.startTime();
		if (method == 0) MergeSort::sort(vec);
		else if (method == 1) InsertionSort::sort(vec);
		else if (method == 2) HybridSort::sort(vec);
		t.endTime();
		res += t.elapsedSeconds();
	}
	return res / repeat;
}

vector<double> sortingPerf(int method, int n, int m = 1)
{
	assert(n > 0);	
	vector<double> ans(n, 0.0);
	for (int i = 1; i <= n; i++)
		ans[i] = sortTime(method, i, m);
	return ans;
}

void sortsPerformanceInsertionVsMerge()
{
	const int arraySize = 250;
	const int numRepeat = 15;
	
	auto mergeTimes = sortingPerf(0, arraySize, numRepeat);
	auto inserTimes = sortingPerf(1, arraySize, numRepeat);
	
	for (int i = 0; i < mergeTimes.size(); i++)
	{
		double mt = mergeTimes[i];
		double it = inserTimes[i];
		
		cout << "Elements: "  << i + 1 << "  ";
		cout << "Merge: "     << mt << "    |    " 
		     << "Insertion: " << it << " ";
		if (mt > it) cout << " *** ";
		cout << endl;
	}
}

void sortsPerformanceHybridVsMerge()
{
	int startVal = 100;
	int endVal = pow(startVal, 4);
	int numRepeat = 1;
	
	for (int i = startVal; i <= endVal; i *= 10)
	{
		double mergeTime = sortTime(0, i, numRepeat);
		double hybridTime = sortTime(2, i, numRepeat);
		
		cout << "n: " << i << "   ";
		cout << "merge  :   " << mergeTime << "   |   ";
		cout << "hybrid :  " << hybridTime;
		
		if (mergeTime < hybridTime) cout << " *** ";
		cout << endl;
	}
}

int main_()
{
	sortsPerformanceHybridVsMerge();
	return 0;
}