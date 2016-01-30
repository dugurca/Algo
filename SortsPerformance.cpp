#include "MergeSort.h"
#include "InsertionSort.h"
#include "HybridSort.h"
#include "MergeBU.h"

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
		else if (method == 3) MergeBU::sort(vec);
		t.endTime();
		res += t.elapsedSeconds();

		assert(isSorted(vec));
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
	auto merBuTimes = sortingPerf(3, arraySize, numRepeat);
	
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

string getWinner(double merge, double mergeBu, double hybrid)
{
	map<double, int> m;
	m.insert(make_pair(merge, 0));
	m.insert(make_pair(mergeBu, 1));
	m.insert(make_pair(hybrid, 2));

	auto winner = m.begin()->second;
	if (winner == 0) return "merge";
	if (winner == 1) return "merge Bu";
	if (winner == 2) return "hybrid";
	return "???";
}

void sortsPerformanceHybridVsMergeVsMergeBu()
{
	int startVal = 100;
	int endVal = pow(startVal, 4);
	int numRepeat = 1;
	
	for (int i = startVal; i <= endVal; i *= 10)
	{
		double mergeTime = sortTime(0, i, numRepeat);
		double hybridTime = sortTime(2, i, numRepeat);
		double mergeBuTime = sortTime(3, i, numRepeat);
		
		cout << "n: " << i << "   ";
		cout << "merge   : " << mergeTime << " | ";
		cout << "hybrid  : " << hybridTime << " | ";
		cout << "mergeBu : " << mergeBuTime << " ";
		cout << " >>  ";
		
		cout << getWinner(mergeTime, mergeBuTime, hybridTime);
		cout << endl;
	}
}

int main()
{
	sortsPerformanceHybridVsMergeVsMergeBu();
	return 0;
}