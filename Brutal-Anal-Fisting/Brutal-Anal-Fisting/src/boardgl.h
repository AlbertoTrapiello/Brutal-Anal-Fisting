#pragma once

#include "board.h"


//enums to eliminate dependency of glut
enum { MOUSE_LEFT_BUTTON, MOUSE_MIDDLE_BUTTON, MOUSE_RIGHT_BUTTON };
enum { KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT };


class boardgl
{
protected:
	Board* m_board;
	int N;

	//visualization	
	double center_x, center_y, center_z;
	double dist;

	//mouse	
	int xcell_sel, ycell_sel;			//cell selected with mouse

										//mouse+special-keys combination state events 
	bool controlKey;
	bool shiftKey;
	bool leftButton;
	bool rightButton;
	bool midButton;

public:
	boardgl(Board* pb):m_board(pb){}

	//Initizalization
	void init();						//enable lights

	//Event managers
	
	void Draw();
	void DrawGrid();
	void DrawCell(int i, int j);
	void KeyDown(unsigned char key);
	void SpecialKeyDown(unsigned char key);
	void MouseButton(int x, int y, int button, bool down, bool shiftKey, bool ctrlKey);
	
	//info

	void setSize(int s) { N = s; }
	int getSize() { return N; }
};

