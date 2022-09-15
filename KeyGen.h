#pragma once
#include <string>
#include <bitset>

using namespace std;

class KeyGen
{
private:
	string key;

public:
	KeyGen();

	void SetKey(string input);
	string Generate(int round);
};

