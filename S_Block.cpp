#include "S_Block.h"

S_Block::S_Block()
{
}

int S_Block::Substitution(bitset<4> input)
{
	return this->substitution[input.to_ulong()];
}
