#include "Drawer.h"

void Drawer::DrowReg16(Graphics^ g, int x, int y, int w, int h)
{

	Pen^ blackPen = gcnew Pen(Color::Black, 1.0f);

	int shift = 0;

	for (int i = 0; i < 16; i++) {
		g->DrawRectangle(blackPen, x * i + shift, y, w, h);
		if (i % 4 == 3) {
			shift += 5;
		}
	}
}

void Drawer::DrowReg16Color(Graphics^ g, int x, int y, int w, int h, vector<int> colors)
{
	Pen^ redPen = gcnew Pen(Color::Red, 1.0f);
	Pen^ bluePen = gcnew Pen(Color::Blue, 1.0f);
	Pen^ greenPen = gcnew Pen(Color::Green, 1.0f);
	Pen^ yelloyPen = gcnew Pen(Color::Yellow, 1.0f);

	int shift = 0;

	for (int i = 0; i < 16; i++) {
		switch (i % 4)
		{
		case 0: g->DrawRectangle(redPen, x * i + shift + i, y, w, h); break;
		case 1: g->DrawRectangle(bluePen, x * i + shift + i, y, w, h); break;
		case 2: g->DrawRectangle(greenPen, x * i + shift + i, y, w, h); break;
		case 3: g->DrawRectangle(yelloyPen, x * i + shift + i, y, w, h); break;
		default:
			break;
		}

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

void Drawer::DrowXOR(Graphics^ g, int x, int y)
{
	Pen^ redPen = gcnew Pen(Color::Red, 1.0f);
	Font^ printFont = gcnew System::Drawing::Font("Arial", 14);
	SolidBrush^ drawBrush = gcnew SolidBrush(Color::Red);

	g->DrawEllipse(redPen, x, y - 17, 15, 15);
	g->DrawString("+", printFont, drawBrush, x - 1, y - 20);
}

void Drawer::DrowS_Block(Graphics^ g, int x, int y)
{
	Pen^ blackPen = gcnew Pen(Color::Black, 1.0f);
	blackPen->EndCap = System::Drawing::Drawing2D::LineCap::ArrowAnchor;

	for (int i = 0; i < 4; i++) {
		g->DrawLine(blackPen, Point(x + 125 * i, y - 18), Point(x + 125 * i, y - 2));
	}
}
