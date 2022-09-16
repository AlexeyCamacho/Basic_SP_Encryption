#pragma once
#include <bitset>
#include <vector>
#include <string>
#include "P_Block.h"
#include "S_Block.h"
#include "KeyGen.h"

using namespace std;


class Section
{
private:
	bitset<16>* word;
	int round;
	int roundCount;
	S_Block* S_Block;
	P_Block* P_Block;

	void Substitution();
	void Permutation();

public:
	Section();
	~Section();

	void SetInput(string input);
	void SetInput(unsigned short int input);
	bitset<16> GetOutput();
	void Encrypt(KeyGen* keyGen);
	void Decrypt(KeyGen* keyGen);
	void XOR(bitset<16> key);


};

