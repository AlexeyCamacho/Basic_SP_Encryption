#include "S_Block.h"

S_Block::S_Block()
{
}

unsigned long S_Block::Substitution(bitset<4> input)
{
	return this->substitution[input.to_ulong()];
}

vector<int> S_Block::GetSubstitution()
{
	return this->substitution;
}
