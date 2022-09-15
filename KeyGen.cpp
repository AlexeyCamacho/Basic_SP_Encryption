#include "KeyGen.h"

KeyGen::KeyGen()
{
	
}

void KeyGen::SetKey(string input)
{
	this->key = input;
}

string KeyGen::Generate(int round)
{
	string word;
	for (int i = 0; i < this->key.size(); i++) {
		word += bitset<8>(this->key[i]).to_string();
	}
	
	return word;
}
