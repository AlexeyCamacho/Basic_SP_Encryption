#pragma once
#include <vector>
#include <bitset>

using namespace std;

class S_Block
{
private:
	vector<int> substitution {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7};
public:
	S_Block();

	unsigned long Substitution(bitset<4> input);
};

