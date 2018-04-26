#include "TextBox.h"
#include "stdio.h"
#include <iostream>

using namespace std;

void TextBox::draw() {
	
		
	HANDLE hStdout;	
	COORD cursorPos;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	
	// Temp cursor position.
	cursorPos.X = position.X;
	cursorPos.Y = position.Y;
	
	// Set cursor position to specified location.
	SetConsoleCursorPosition(hStdout , cursorPos);
	
	// Writing the top frame (width)
	for(int x = 0 ; x < width ; x++){
		if(x == 0){
				cout<<'\xDA';
		}else{
			while(x < width-1){
				cout<<'\xC4';
				x++;
			}
			cout<<'\xBF';
		}
	}
	
	// Writing the middle frame (height)
	int y = 0;
	while(y < height){
		cursorPos.Y = cursorPos.Y+1;
		SetConsoleCursorPosition(hStdout , cursorPos);	
		for(int x = 0 ; x < width ; x++){
		if(x == 0 || x == width -2){
				cout<<'\xB3';
			}
			cout<<' ';
		}	
		y++;
	}
	
	// Writing the bottom frame (width)
	cursorPos.Y = cursorPos.Y+1;
	SetConsoleCursorPosition(hStdout , cursorPos);	
	for(int x = 0 ; x < width ; x++){
		if(x == 0){
			cout<<'\xC0';
		}else{
			while(x < width-1){
				cout<<'\xC4';
				x++;
			}
			cout<<'\xD9';
		}
	}
		
}

void TextBox::focus(){
	
	// STD INPUT OUTPUT HANDLE
	HANDLE hStdout;
	HANDLE hStdin; 
	
	// Temp cursor position	
	COORD cursorPos;
	
	DWORD cNumRead;
	DWORD fdwMode;
	DWORD i; 
    INPUT_RECORD irInBuf; 
	
	int maxBufferSize = width-2;
	int bufferSizeCounter = 0;
	// Get the standard input output handle. 
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	hStdin = GetStdHandle(STD_INPUT_HANDLE); 
	
	// Set cursor position inside the Textbox.
	cursorPos.X = position.X + 1;
	cursorPos.Y = position.Y + 1;
	SetConsoleCursorPosition(hStdout , cursorPos);
	
	// Enable the window and mouse input events. 
	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT; 
	SetConsoleMode(hStdin, fdwMode);
	
	while (1) 
    { 
	
	// Wait for the events. 
	 ReadConsoleInput(hStdin , &irInBuf , 1 , &cNumRead) ; 
          
		   // Dispatch the events to the appropriate handler. 
			switch(irInBuf.EventType) 
            { 
                case KEY_EVENT: // keyboard input 
                		if(!irInBuf.Event.KeyEvent.bKeyDown){
                			if(irInBuf.Event.KeyEvent.wVirtualKeyCode == VK_BACK){
                				if(cursorPos.X == position.X + 1){
                					continue;
                				}
                				cursorPos.X = cursorPos.X - 1;
                				SetConsoleCursorPosition(hStdout , cursorPos);
                				printf("%c",' ');
                				SetConsoleCursorPosition(hStdout , cursorPos);
								--bufferSizeCounter;	
                			}
                			else if(bufferSizeCounter < maxBufferSize){
                			++bufferSizeCounter;
                			cursorPos.X = cursorPos.X + 1;
                			printf("%c" , irInBuf.Event.KeyEvent.uChar.AsciiChar);
                			}	
                		}
                	
                    break; 

                case MOUSE_EVENT: // mouse input 
                  
                    break; 

                case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing 
                 
                    break; 

                case FOCUS_EVENT:  // disregard focus events 

                case MENU_EVENT:   // disregard menu events 
                    break; 

                default: 
                  
                    break; 
            } 
        
    } 

	
	
	
	
}

