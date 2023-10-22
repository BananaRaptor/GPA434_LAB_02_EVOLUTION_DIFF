#include "Console.h"


#include <conio.h>
#include <iostream>
#include <algorithm>


void Console::clearScreen()
{
	system("cls");
}

bool Console::wantToQuit()
{
	std::cout << "\nAppuyer sur ESC pour quitter ou toute autre touche pour poursuivre...";
	return _getch() == 27;
}

void Console::pressAnyKeyToContinue()
{
	std::cout << "\nAppuyer sur une touche pour poursuivre...";
#pragma warning(disable:4101)
	int tempToIgnore{ _getch() };
#pragma warning(default:4101)
}

int Console::getUInt09(uint8_t min, uint8_t max)
{
	min = std::clamp<uint8_t>(min, 0, 9);
	max = std::clamp<uint8_t>(max, 0, 9);
	min = std::min(min, max);
	max = std::max(min, max);

	int value{};
	do {
		value = _getch() - '0';
	} while (value < min || value > max);

	return value;
}

bool Console::getBoolean(char trueChar, char falseChar)
{
	trueChar = toupper(trueChar);
	falseChar = toupper(falseChar);

	char value{};
	do {
		value = static_cast<char>(toupper(_getch()));
	} while (value != trueChar && value != falseChar);

	return value == trueChar;
}