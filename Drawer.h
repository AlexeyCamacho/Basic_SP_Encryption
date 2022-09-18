#pragma once
#include <bitset>
#include <string>
#include <vector>

using namespace std;
using namespace System::Drawing;


class Drawer
{

public:
	void DrowReg16(Graphics^ g, int x, int y, int w, int h);
	void DrowReg16Color(Graphics^ g, int x, int y, int w, int h, vector<int> colors);
	void DrowBits16(Graphics^ g, string input, int x, int y);
	void DrowXOR(Graphics^ g, int x, int y);
	void DrowS_Block(Graphics^ g, int x, int y);
	void DrowCustomReg(Graphics^ g, Pen^ pen, int i, int x, int y);
};

