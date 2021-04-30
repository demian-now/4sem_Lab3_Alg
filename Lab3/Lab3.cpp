#include <iostream>
#include "BellFord.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	Graph Test;
	Test.input();
	for (size_t i = 0; i < 4; i++)
		for (size_t j = 0; j < 4; j++)
			Test.BellFord(i,j);
	Test.clear();
}