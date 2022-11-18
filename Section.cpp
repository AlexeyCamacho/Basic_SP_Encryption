#include "Section.h"

void Section::Substitution(bool reverce)
{
	string s_block;
	string res;

	for (int i = 0; i < 4; i++) {

		s_block = this->word->to_string().substr(4 * i, 4);
		unsigned long swapRes;

		if (reverce) {
			swapRes = this->S_Block->ReverceSubstitution(bitset<4>(s_block));
		}
		else {
			swapRes = this->S_Block->Substitution(bitset<4>(s_block));
		}

		res += bitset<4>(swapRes).to_string();

	}

	this->word = new bitset<16>(res);
}

void Section::Permutation(bool reverce)
{
	unsigned long res;
	if (reverce) {
		res = this->P_Block->RevercePermutation(bitset<16>(this->word->to_ulong()));
	}
	else {
		 res = this->P_Block->Permutation(bitset<16>(this->word->to_ulong()));
	}

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

void Section::Encrypt(KeyGen* keyGen, Graphics^ g) // ����������
{
	vector <int> NoColor;
	vector <int> orderColor {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

	this->Drawer->DrowReg16(g, 550, this->y, 30, 35); // ����
	this->Drawer->DrowBits16(g, keyGen->Generate(0), 550, this->y); // ����

	this->DrowBitReg(g, NoColor);


	for (int i = 0; i < this->roundCount; i++) {
		string keyStr = keyGen->Generate(this->round);
		bitset<16> key(keyStr);

		this->Drawer->DrowXOR(g, 240, this->y);
		this->XOR(key);
		this->DrowBitReg(g, NoColor);

		this->Drawer->DrowS_Block(g, 62, this->y);
		this->Drawer->DrowSubstitution(g, 550, this->y - 50, this->word->to_string());
		this->Substitution(false);
		this->DrowBitReg(g, orderColor);
		this->Drawer->DrowSubstitution(g, 550, this->y - 50, this->word->to_string());

		if (i != 3) {
			this->Permutation(false);
			this->DrowBitReg(g, this->P_Block->GetPermutation());
		}
		Pen^ p = gcnew Pen(Color::Blue, 1.0f);
	}

	string keyStr = keyGen->Generate(this->round);
	bitset<16> key(keyStr);

	this->Drawer->DrowXOR(g, 240, this->y);
	this->XOR(key);
	this->DrowBitReg(g, NoColor);

}

void Section::EncryptNoDisplay(KeyGen* keyGen)
{
	for (int i = 0; i < this->roundCount; i++) {
		string keyStr = keyGen->Generate(this->round);
		bitset<16> key(keyStr);

		this->XOR(key);
		this->Substitution(false);

		if (i != 3) {
			this->Permutation(false);
		}
	}

	string keyStr = keyGen->Generate(this->round);
	bitset<16> key(keyStr);
	this->XOR(key);
}

void Section::XOR(bitset<16> key)
{
	this->word->operator^=(key);
}

void Section::YStep()
{
	this->y += 55;
}

void Section::DrowBitReg(Graphics^ g, vector<int> colors)
{
	if (colors.size() == 16) {
		this->Drawer->DrowReg16Color(g, 0, this->y, 30, 35, colors);
	}
	else {
		this->Drawer->DrowReg16(g, 0, this->y, 30, 35);
	}
	this->Drawer->DrowBits16(g, this->word->to_string(), 0, this->y);
	this->YStep();
}

void Section::Decrypt(KeyGen* keyGen, Graphics^ g)
{
	vector <int> NoColor;
	vector <int> orderColor{ 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };

	string keyStr = keyGen->Generate(this->round);
	bitset<16> key(keyStr);

	this->Drawer->DrowReg16(g, 550, this->y, 30, 35); // ����
	this->Drawer->DrowBits16(g, keyStr, 550, this->y); // ����

	this->DrowBitReg(g, NoColor);

	this->Drawer->DrowXOR(g, 240, this->y);
	this->XOR(key);
	this->DrowBitReg(g, NoColor);


	for (int i = 0; i < this->roundCount; i++) {
		string keyStr = keyGen->Generate(this->round);
		bitset<16> key(keyStr);

		if (i != 0) {
			this->DrowBitReg(g, orderColor);
			this->Permutation(true);
		}


		this->Drawer->DrowS_Block(g, 62, this->y);
		this->Drawer->DrowSubstitution(g, 550, this->y - 50, this->word->to_string());
		this->Substitution(true);
		this->DrowBitReg(g, NoColor);
		this->Drawer->DrowSubstitution(g, 550, this->y - 50, this->word->to_string());

		this->Drawer->DrowXOR(g, 240, this->y);
		this->XOR(key);

		if (i != 3) {
			this->DrowBitReg(g, this->P_Block->GetPermutation());
		}
		else {
			this->DrowBitReg(g, NoColor);
		}
	}

}
