#pragma once
#include <string>

using namespace std;

class Separator
{
private:
	string input;

public:
	Separator();
	~Separator();

	void SetInput(string input);
	string GetNextWord();
	int GetCountWords();
};

