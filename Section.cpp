#include "Section.h"

Section::Section()
{
	this->roundCount = 4;
	this->round = 0;
}

Section::~Section()
{
}

void Section::SetInput(string input)
{
	string word;
	for (int i = 0; i < input.size(); i++) {
		word += bitset<8>(input[i]).to_string();
	}
	this->word = new bitset<16> (word);
}

bitset<16> Section::GetOutput()
{
	return bitset<16>();
}

void Section::Encrypt(KeyGen* keyGen)
{
	for (int i = 0; i < this->roundCount; i++) {
		string keyStr = keyGen->Generate(this->round);
		bitset<16> key(keyStr);

		this->XOR(key);


	}

}

void Section::Decrypt(KeyGen* keyGen)
{
}

void Section::XOR(bitset<16> key)
{
	this->word->operator^=(key);
}
