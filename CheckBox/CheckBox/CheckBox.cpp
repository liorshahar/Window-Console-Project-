#include "CheckBox.h"
#include <iostream>

void CheckBox::setForeground(DWORD fg) {
	this->fg = fg;
}

void CheckBox::setBackground(DWORD bg) {
	this->bg = bg;
}


void CheckBox::draw() {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(out, &info);
	SetConsoleCursorPosition(out, this->position);
	SetConsoleTextAttribute(out, this->fg | this->bg);
	std::cout << "\xDA""\xC4""\xC4""\xC4""\xBF";
	SetConsoleCursorPosition(out, this->getNextLinePosition(this->position));
	std::cout << "\xB3""   ""\xB3" + name;
	SetConsoleCursorPosition(out, this->getNextLinePosition(this->getNextLinePosition(this->position)));
	std::cout << "\xC0""\xC4""\xC4""\xC4""\xD9";
	SetConsoleCursorPosition(out, this->getNextLinePosition(this->position));
}