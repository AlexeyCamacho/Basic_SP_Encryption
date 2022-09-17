#pragma once
#include <bitset>
#include <vector>
#include <string>
#include "P_Block.h"
#include "S_Block.h"
#include "KeyGen.h"
#include "Drawer.h"

using namespace std;
using namespace System::Drawing;


class Section
{
private:
	bitset<16>* word;
	int round;
	int roundCount;
	S_Block* S_Block;
	P_Block* P_Block;
	Drawer* Drawer;
	int y;

	void Substitution();
	void Permutation();

public:
	Section();
	~Section();

	void SetInput(string input);
	void SetInput(unsigned short int input);
	bitset<16> GetOutput();
	void Encrypt(KeyGen* keyGen, Graphics^ g);
	void Decrypt(KeyGen* keyGen);
	void XOR(bitset<16> key);
	void YStep();


};

