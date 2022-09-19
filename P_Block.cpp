#include "P_Block.h"

P_Block::P_Block()
{
}

unsigned long P_Block::Permutation(bitset<16> input)
{
	bitset<16> res;
	for (int i = 0; i < 16; i++) {
		res[this->permutation[i]] = input[i];
	}

	return res.to_ulong();
}

unsigned long P_Block::RevercePermutation(bitset<16> input)
{
	bitset<16> res;
	for (int i = 0; i < 16; i++) {
		vector<int>::iterator itr = find(this->permutation.begin(), this->permutation.end(), i);
		res[distance(this->permutation.begin(), itr)] = input[i];
	}

	return res.to_ulong();
}

vector<int> P_Block::GetPermutation()
{
	return this->permutation;
}
