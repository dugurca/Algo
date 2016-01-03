#pragma once
#include "stdafx.h"
#include "TrieTest.h"

void TrieTester()
{
	TrieTest tt;

	cout << "Testing: Trie" << endl;
	if (tt.Test())
		cout << "All tests passed" << endl;
	else
		cout << "Tests failed" << endl;
}

int main()
{
	TrieTester();
}