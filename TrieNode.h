#pragma once
#include "stdafx.h"

const int numTrieChildren = 26;

class TrieNode
{
public:
	TrieNode* children[numTrieChildren];
	bool isWord = false;
	TrieNode()
	{
		for (int i = 0; i < numTrieChildren; i++)
			children[i] = nullptr;
	}
};
