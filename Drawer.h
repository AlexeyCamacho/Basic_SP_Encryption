#pragma once
#include <bitset>
#include <string>

using namespace std;
using namespace System::Drawing;


class Drawer
{

public:
	void DrowReg16(Graphics^ g, int x, int y, int w, int h);
	void DrowBits16(Graphics^ g, string input, int x, int y);
	void DrowLines(Graphics^ g);
};

