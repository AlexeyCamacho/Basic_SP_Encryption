#include "S_Block.h"

S_Block::S_Block()
{
}

unsigned long S_Block::Substitution(bitset<4> input)
{
	return this->substitution[input.to_ulong()];
}

unsigned long S_Block::ReverceSubstitution(bitset<4> input)
{
	vector<int>::iterator itr = find(this->substitution.begin(), this->substitution.end(), input.to_ulong());
	return distance(this->substitution.begin(), itr);
}

vector<int> S_Block::GetSubstitution()
{
	return this->substitution;
}
