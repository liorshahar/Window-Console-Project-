#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <Tchar.h>
#include "TextBox.h"
#include <iostream>
using namespace std;
HANDLE wHnd;    // Handle to write to the console.
HANDLE rHnd;    // Handle to read from the console.

int _tmain(int argc, _TCHAR* argv[]) {
	
	
	INPUT_RECORD irInBuf[128];
	DWORD cNumRead, fdwMode, i; 
  
    int counter=0;
    
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	
	// Enable the window and mouse input events. 
	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS; 
	SetConsoleMode(hStdin, fdwMode);
	
	COORD tBoxPos = {0,0};	
	COORD tBoxPo1 = {3,3};
		
  	TextBox tBox(tBoxPos);
  	tBox.draw();
  	SetConsoleCursorPosition(hStdout , tBoxPo1);
  	tBox.focus();
  	while(1){
  		
        }
  		
}

