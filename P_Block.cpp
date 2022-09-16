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
