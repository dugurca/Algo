#pragma once
#include "stdafx.h"
#include "Trie.h"
#include "FileUtils.h"

class TrieTest
{
	Trie trie;
	vector<string> lines;
	void init()
	{		
		lines = FileUtils::readLines("google-10000-english.txt");
		for (string line : lines)
			trie.addWord(line);
	}

public:
	bool Test1()
	{
		for (string line : lines)
		{
			if (!trie.hasWord(line) || !trie.hasPrefix(line))
				return false;
		}
		return true;
	}

	bool Test2()
	{
		vector<string> gibberishWords = 
		{   
			"supercalifragilistic",
			"expialidocious",
			"iggily",
			"biggily",
			"gollygoops",
			"ittly",
			"bittly",
			"psghetti",
			"coochie",
			"pigglywiggly",
			"woospiedoo",
			"scribblescrabble",
			"spindingy",
			"capstcha",
			"zowzy",
			"tispytospy",
			"bazinga"
		};

		for (string gib : gibberishWords)
		{
			if (trie.hasWord(gib) || trie.hasPrefix(gib))
				return false;
		}
		return true;		
	}

	bool Test()
	{
		return Test1() && Test2();
	}
};
