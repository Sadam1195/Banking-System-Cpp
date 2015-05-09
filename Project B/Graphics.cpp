#ifndef GRAPHICS_CPP
#define GRAPHICS_CPP

#include <windows.h>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;

enum Color { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE };

class Graphics {
public:
	/* http://www.infernodevelopment.com/set-console-text-color */
	static void SetColor(Color c) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
		//SetColor(YELLOW);
		//	cout << "X\b";
	}

	static void coutColored(Color c, string text) {
		SetColor(c);
		std::cout << text;
		SetColor(WHITE);
	}

	static void goToXY(short int x, short int y) {
		COORD coord = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	
	static int whereX() {
		CONSOLE_SCREEN_BUFFER_INFO consoleinfo;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleinfo);
		return consoleinfo.dwCursorPosition.X;
	}

	static int whereY() {
		CONSOLE_SCREEN_BUFFER_INFO consoleinfo;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleinfo);
		return consoleinfo.dwCursorPosition.Y;
	}

	static void cls() {
		system("cls");
	}

	static void coutV2(string str, Color c = WHITE) {
		SetColor(c);
		cout << str;
		SetColor(WHITE);
	}

	static void coutV3(int x, int y, string str, Color c = WHITE) {
		goToXY(x,y);
		SetColor(c);
		cout << str;
		SetColor(WHITE);
		goToXY(0, 0);
	}
};


#endif