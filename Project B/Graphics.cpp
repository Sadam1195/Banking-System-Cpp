#include <windows.h>

class Graphics {
public:
	/* http://www.infernodevelopment.com/set-console-text-color */
	HANDLE hCon;
	enum Color { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE };

	static void SetColor(Color c) {
		if (hCon == NULL) {
			hCon = GetStdHandle(STD_OUTPUT_HANDLE);
		}
		SetConsoleTextAttribute(hCon, c);

		//SetColor(YELLOW);
		//	cout << "X\b";
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
};
