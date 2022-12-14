#pragma once
#include <vector>
#include <bitset>

using namespace std;

class P_Block
{
private:
	vector<int> permutation = { 0, 4, 8, 12, 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15 };
public:
	P_Block();

	unsigned long Permutation(bitset<16> input);
	unsigned long RevercePermutation(bitset<16> input);
	vector<int> GetPermutation();
};

