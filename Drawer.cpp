#include "Drawer.h"

void Drawer::DrowReg16(Graphics^ g, int x, int y, int w, int h)
{
	Pen^ redPen = gcnew Pen(Color::Red, 1.0f);
	Pen^ bluePen = gcnew Pen(Color::Blue, 1.0f);
	Pen^ greenPen = gcnew Pen(Color::Green, 1.0f);
	Pen^ yelloyPen = gcnew Pen(Color::Yellow, 1.0f);

	int shift = 0;

	for (int i = 0; i < 16; i++) {
		g->DrawRectangle(redPen, x * i + shift, y, w, h);
		if (i % 4 == 3) {
			shift += 5;
		}
	}
}

void Drawer::DrowBits16(Graphics^ g, string input, int x, int y)
{
	Font^ printFont = gcnew System::Drawing::Font("Arial", 12);
	SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);

	int shift = 8;

	for (int i = 0; i < 16; i++) {
		std::string charStr{ input[i] };
		System::String^ test = gcnew System::String(charStr.c_str());
		g->DrawString(test, printFont, drawBrush, x * i + shift, y + 10);

		if (i % 4 == 3) {
			shift += 5;
		}
	}
}
