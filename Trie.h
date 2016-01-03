#pragma once
#include "stdafx.h"
#include "TrieNode.h"

class Trie
{
	TrieNode* root;

public:
	Trie()
	{
		root = new TrieNode();
	}

	void addWord(const string& str);

	bool hasWord(const string& str);

	bool hasPrefix(const string& str);
};