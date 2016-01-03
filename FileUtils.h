#pragma once
#include "stdafx.h"

class FileUtils
{
public:
	static vector<string> readLines(const string& fileName)
	{
		vector<string> lines;
		ifstream file(fileName);
		string str;
		while (getline(file, str))
		{
			lines.push_back(str);
		}
		return lines;
	}
};
