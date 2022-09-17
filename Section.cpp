#include "Section.h"

void Section::Substitution()
{
	string s_block;
	string res;

	for (int i = 0; i < 4; i++) {

		s_block = this->word->to_string().substr(4 * i, 4);
		
		unsigned long swapRes = this->S_Block->Substitution(bitset<4>(s_block));

		res += bitset<4>(swapRes).to_string();

	}

	this->word = new bitset<16>(res);
}

void Section::Permutation()
{
	unsigned long res = this->P_Block->Permutation(bitset<16> (this->word->to_ulong()));

	this->word = new bitset<16>(res);
}

Section::Section()
{
	this->roundCount = 4;
	this->round = 0;
	this->S_Block = new class S_Block();
	this->P_Block = new class P_Block();
	this->Drawer = new class Drawer();
	this->y = 0;
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

void Section::SetInput(unsigned short int input)
{
	this->word = new bitset<16>(input);
}

bitset<16> Section::GetOutput()
{
	return bitset<16> (this->word->to_ulong());
}

void Section::Encrypt(KeyGen* keyGen, Graphics^ g)
{
	this->Drawer->DrowReg16(g, 30, this->y, 30, 35);
	this->Drawer->DrowBits16(g, this->word->to_string(), 30, this->y);
	this->YStep();

	for (int i = 0; i < this->roundCount; i++) {
		string keyStr = keyGen->Generate(this->round);
		bitset<16> key(keyStr);

		this->XOR(key);

		this->Drawer->DrowReg16(g, 30, this->y, 30, 35);
		this->Drawer->DrowBits16(g, this->word->to_string(), 30, this->y);
		this->YStep();

		this->Substitution();

		this->Drawer->DrowReg16(g, 30, this->y, 30, 35);
		this->Drawer->DrowBits16(g, this->word->to_string(), 30, this->y);
		this->YStep();

		if (i != 3) {
			this->Permutation();

			this->Drawer->DrowReg16(g, 30, this->y, 30, 35);
			this->Drawer->DrowBits16(g, this->word->to_string(), 30, this->y);
			this->YStep();
		}
		Pen^ p = gcnew Pen(Color::Blue, 1.0f);
	}

	string keyStr = keyGen->Generate(this->round);
	bitset<16> key(keyStr);
	this->XOR(key);

	this->Drawer->DrowReg16(g, 30, this->y, 30, 35);
	this->Drawer->DrowBits16(g, this->word->to_string(), 30, this->y);
	this->YStep();

}

void Section::Decrypt(KeyGen* keyGen)
{
}

void Section::XOR(bitset<16> key)
{
	this->word->operator^=(key);
}

void Section::YStep()
{
	this->y += 55;
}
