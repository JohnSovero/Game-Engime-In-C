#pragma once
#include <string>
#include <vector>

using namespace std;
class IDManager
{
public:
	static bool readFiletoBuffer(string filePath, vector<unsigned char>& buffer);
};