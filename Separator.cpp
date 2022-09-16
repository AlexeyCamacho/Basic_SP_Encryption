#include "Separator.h"

Separator::Separator()
{
}

Separator::~Separator()
{
}

void Separator::SetInput(string input)
{	
	this->input = input;
}


string Separator::GetNextWord()
{
	return this->input;
}

int Separator::GetCountWords()
{
	return 1;
}
