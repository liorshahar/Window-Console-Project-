#pragma once

#include <string>
#include <windows.h>

using namespace std;

class TextBox{
	
private:
	COORD position;
	int height;
	int width;
		
public:
	TextBox(COORD pos , int _height = 1, int _width = 10)
		: position(pos) , height(_height) , width(_width){
			
	}
	
	COORD getPosition() {
	return position;
	}
	
	int getHeight(){
		return height;
	}
	
	int getWidth(){
		return width;
	}
	
	void draw();
	void focus();

	~TextBox() {};
		
};
