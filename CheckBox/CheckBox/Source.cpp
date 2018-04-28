#include <stdio.h>
#include <Windows.h>
#include "checkBox.h"
#include <string>
#include <iostream>     

using namespace std;
#define numberOfboxes 3

int main(int argc, char** argv) {

	COORD coordArray[numberOfboxes] = {{ 5,5 },{ 5,9 },{ 5,13 }};
	
	CheckBox checkBox1(coordArray[0],"option 1"), checkBox2(coordArray[1], "option 2"), checkBox3(coordArray[2], "option 3" );

	//checkBox1.setBackground(BACKGROUND_RED);
	checkBox1.draw();
	//checkBox2.setBackground(BACKGROUND_RED);
	checkBox2.draw();
	//checkBox3.setBackground(BACKGROUND_RED);
	checkBox3.draw();

	HANDLE in = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	WORD mode;
	mode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	SetConsoleMode(in, mode);
	DWORD charnum1;
	DWORD charnum2;

	CHAR* buf1 = new CHAR[2];
	CHAR* buf2 = new CHAR[2];

	SetConsoleCursorPosition(out, { 0,0 });
	int a = 1;
	SetConsoleCursorPosition(out, { coordArray[0].X + 2,coordArray[0].Y + 1 });
	while (1) {
		INPUT_RECORD ir;
		DWORD count;
		ReadConsoleInput(in, &ir, 1, &count);
		switch (ir.EventType)
		{
		case MOUSE_EVENT:
		{
			if (ir.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
				for (size_t i = 0; i < numberOfboxes; i++)
				{
					if (ir.Event.MouseEvent.dwMousePosition.X == coordArray[i].X + 2 && ir.Event.MouseEvent.dwMousePosition.Y == coordArray[i].Y + 1)
					{
						COORD pos = { (coordArray[i].X) + 2,(coordArray[i].Y) + 1 };
						SetConsoleCursorPosition(out, { pos.X,pos.Y });
						ReadConsoleOutputCharacter(out, buf2, 2, pos, &charnum2);
						if (buf2[0] != 'X') {
							cout << "X";
						}
						else if (buf2[0] == 'X') {
							cout << "  ";
						}
						SetConsoleCursorPosition(out, { pos.X,pos.Y });
					}
				}
			}
		}
		case KEY_EVENT:
		{
			
			if (ir.Event.KeyEvent.bKeyDown)
			{
				if (ir.Event.KeyEvent.wVirtualKeyCode == VK_DOWN)
				{
					SetConsoleCursorPosition(out, { coordArray[a % numberOfboxes].X + 2, coordArray[a % numberOfboxes].Y + 1 });
					a++;
				}
				else if (ir.Event.KeyEvent.wVirtualKeyCode == VK_SPACE)
				{
					a--;
					ReadConsoleOutputCharacter(out, buf1, 2, { coordArray[a % numberOfboxes].X + 2, coordArray[a % numberOfboxes].Y + 1 }, &charnum1);
					if (buf1[0] != 'X')
					{
						cout << "X";
						SetConsoleCursorPosition(out, { coordArray[a % numberOfboxes].X + 2, coordArray[a % numberOfboxes].Y + 1 });
					}
					else if (buf1[0] == 'X') {
						cout << "  ";
						SetConsoleCursorPosition(out, { coordArray[a % numberOfboxes].X + 2, coordArray[a % numberOfboxes].Y + 1 });
					}
					SetConsoleCursorPosition(out, { coordArray[a % numberOfboxes].X + 2, coordArray[a % numberOfboxes].Y + 1 });
					a++;
				}
			}
		}
		}
	}
	cin.get();
}
