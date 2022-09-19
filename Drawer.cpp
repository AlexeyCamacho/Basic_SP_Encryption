#include "Drawer.h"

void Drawer::DrowReg16(Graphics^ g, int x, int y, int w, int h)
{

	Pen^ blackPen = gcnew Pen(Color::Black, 1.0f);

	int shift = 0;

	for (int i = 0; i < 16; i++) {
		g->DrawRectangle(blackPen, x + i * w + shift + i, y, w, h);
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
		switch (colors[i] / 4)
		{
		case 0: g->DrawRectangle(redPen, x + i * w + shift + i, y, w, h); break;
		case 1: g->DrawRectangle(bluePen, x + i * w + shift + i, y, w, h); break;
		case 2: g->DrawRectangle(greenPen, x + i * w + shift + i, y, w, h); break;
		case 3: g->DrawRectangle(yelloyPen, x + i * w + shift + i, y, w, h); break;
		default:
			break;
		}

		switch (colors[i] / 4)
		{
		case 0: this->DrowCustomReg(g, redPen, colors[i], x + i * w + shift + i, y); break;
		case 1: this->DrowCustomReg(g, bluePen, colors[i], x + i * w + shift + i, y); break;
		case 2: this->DrowCustomReg(g, greenPen, colors[i], x + i * w + shift + i, y); break;
		case 3: this->DrowCustomReg(g, yelloyPen, colors[i], x + i * w + shift + i, y); break;
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
		g->DrawString(test, printFont, drawBrush, x + 30 * i + shift + i, y + 10);

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

	g->DrawEllipse(redPen, x + 8, y - 17, 15, 15);
	g->DrawString("+", printFont, drawBrush, x + 7, y - 20);
}

void Drawer::DrowS_Block(Graphics^ g, int x, int y)
{
	Pen^ blackPen = gcnew Pen(Color::Black, 1.0f);
	blackPen->EndCap = System::Drawing::Drawing2D::LineCap::ArrowAnchor;

	for (int i = 0; i < 4; i++) {
		g->DrawLine(blackPen, Point(x + 129 * i, y - 18), Point(x + 129 * i, y - 2));
	}
}

void Drawer::DrowCustomReg(Graphics^ g, Pen^ pen, int i, int x, int y)
{

	switch (i % 4)
	{
	case 0: g->DrawRectangle(pen, x, y, 5, 5); break;
	case 1: g->DrawRectangle(pen, x, y + 30, 5, 5); break;
	case 2: g->DrawRectangle(pen, x + 25, y + 30, 5, 5); break;
	case 3: g->DrawRectangle(pen, x + 25, y, 5, 5); break;
	default:
		break;
	}
}

void Drawer::DrowSubstitution(Graphics^ g, int x, int y, string input)
{
	vector<int> words;

	Font^ printFont = gcnew System::Drawing::Font("Arial", 14);
	SolidBrush^ drawBrush = gcnew SolidBrush(Color::Red);

	for (int i = 0; i < 4; i++) {
		words.push_back(bitset<4>(input.substr(i * 4, 4)).to_ulong());
	}

	for (int i = 0; i < 4; i++) {
		System::String^ test = gcnew System::String(to_string(words[i]).c_str());
		g->DrawString(test, printFont, drawBrush, x + 35 * i, y);
	}
}
