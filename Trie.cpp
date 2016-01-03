#pragma once
#include "stdafx.h"
#include "TrieNode.h"
#include "Trie.h"

void Trie::addWord(const string& str)
{
	TrieNode* node = root;
	for (char c : str)
	{
		int p = c - 'a';
		if (node->children[p] == nullptr)
			node->children[p] = new TrieNode();
		node = node->children[p];
	}
	node->isWord = true;
}

bool Trie::hasWord(const string& str)
{
	TrieNode* node = root;
	for (char c : str)
	{
		int p = c - 'a';
		if (node->children[p] == nullptr)
			return false;
		node = node->children[p];
	}
	return node->isWord;
}

bool Trie::hasPrefix(const string& str)
{
	TrieNode* node = root;
	for (char c : str)
	{
		int p = c - 'a';
		if (node->children[p] == nullptr)
			return false;
		node = node->children[p];
	}
	return true;
}