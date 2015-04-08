#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <windows.h>
using namespace std;

HANDLE hCon;
	enum Color { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE };

	void SetColor(Color c) {
		if (hCon == NULL) {
			hCon = GetStdHandle(STD_OUTPUT_HANDLE);
		}
		SetConsoleTextAttribute(hCon, c);

		//SetColor(YELLOW);
		//	cout << "X\b";
	}


void goToXY(short int x, short int y) {
		COORD coord = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

string getUsername() {
	string username;
	
	cout << endl << endl << endl;
    cout << setw(55) << " _________________________ " << endl;
    cout << setw(55) << "/                         \\" << endl;
    cout << setw(55) << "|  PROJECT B              |" << endl;
    cout << setw(55) << "|                         |" << endl;
    cout << setw(55) << "|  1234 5672 1892 1728    |" << endl;
    cout << setw(55) << "|  NAME:                  |" << endl;
    cout << setw(55) << "|                    ---- |" << endl;
    cout << setw(55) << "|  Valid: 1/15       VISA |" << endl;
    cout << setw(55) << "|                    ---- |" << endl;
    cout << setw(55) << "\\_________________________/" << endl;

	goToXY(37,8);
	cin >> username;
	return username;
} 

string getPIN() {
	string PIN;
	cout << endl << endl << endl;
    cout << setw(55) << " _________________________ " << endl;
    cout << setw(55) << "/                         \\" << endl;
    cout << setw(55) << "|  PROJECT B              |" << endl;
    cout << setw(55) << "|                         |" << endl;
    cout << setw(55) << "|                         |" << endl;
    cout << setw(55) << "|      PIN:               |" << endl;
    cout << setw(55) << "|                         |" << endl;
    cout << setw(55) << "|                         |" << endl;
    cout << setw(55) << "|                         |" << endl;
    cout << setw(55) << "\\_________________________/" << endl;

	goToXY(40,8);
	cin >> PIN;
	return PIN;	
}


void accountBlocked() {
	cout << endl << endl << endl;
    cout << setw(55) << " _________________________ " << endl;
    cout << setw(55) << "/                         \\" << endl;
    cout << setw(55) << "|  PROJECT B              |" << endl;
    cout << setw(55) << "|                         |" << endl;
    cout << setw(55) << "|                         |" << endl;
	SetColor(RED);
	cout  << setw(55) << "| ~~~ ACCOUNT BLOCKED ~~~ |" << endl;
    SetColor(WHITE);
	cout << setw(55) << "|                         |" << endl;
    cout << setw(55) << "|                         |" << endl;
    cout << setw(55) << "|                         |" << endl;
    cout << setw(55) << "\\_________________________/" << endl;
}



int main1 () {
	string username = getUsername();
	system("cls");
	string PIN = getPIN();
	system("cls");
	accountBlocked();
	//cout << username;
    system("pause");
    return 0;
}
