#pragma once

#include <string>
#include <Windows.h>

using namespace std;

class CheckBox
{
private:
	COORD position;
	DWORD bg;
	DWORD fg;
	string name;
public:
	CheckBox(COORD pos,string name)
		: position(pos) {
		this->bg = 0;
		this->fg = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
		this->name = name;
	};

	COORD getPosition() {
		return position;
	}

	COORD getNextLinePosition(COORD position) {
		position.Y++;
		return position;
	}

	void setName(string name);
	void setBackground(DWORD bg);
	void setForeground(DWORD fg);
	void draw();
	~CheckBox() {};
};

