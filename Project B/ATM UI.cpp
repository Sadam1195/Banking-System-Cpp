#ifndef GRAPHICS_CPP
#define GRAPHICS_CPP
#include "Graphics.cpp"
#endif

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <conio.h>
#include <iomanip>
#include <windows.h>

using namespace std;

class atmUI {
private:
	int getHiddenPIN() {
		char ch;
		string input;
		int count = 0;
		ch = _getch();
		while (ch != 13 && count < 4) {
			if (ch >= '0' && ch <= '9') {
				cout << "*";
				input += ch;
				count++;
			}
			ch = _getch();
		}
		return atoi(input.c_str());
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

		Graphics::goToXY(37, 8);
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

		Graphics::goToXY(40, 8);
		PIN = getHiddenPIN();
		return PIN;
	}


	int customAmount() {
		int amount;
		cout << endl << endl << endl;
		cout << setw(55) << " _________________________ " << endl;
		cout << setw(55) << "/                         \\" << endl;
		cout << setw(55) << "|  PROJECT B              |" << endl;
		cout << setw(55) << "|                         |" << endl;
		cout << setw(55) << "|   CUSTOM                |" << endl;
		cout << setw(55) << "|   AMOUNT:               |" << endl;
		cout << setw(55) << "|                         |" << endl;
		cout << setw(55) << "|                         |" << endl;
		cout << setw(55) << "|                         |" << endl;
		cout << setw(55) << "\\_________________________/" << endl;

		Graphics::goToXY(40, 8);
		cin >> amount;
		return amount;
	}


	void Choice()
	{
		int x, y;

		cout << endl << endl << endl;
		cout << "\t\t\t _________________________ " << endl
			<< "\t\t\t/                         \\" << endl
			<< "\t\t\t| Select Amount           |" << endl
			<< "\t\t\t|                         |" << endl
			<< "\t\t\t|    1000 Rs Only         |" << endl
			<< "\t\t\t|    2000 Rs Only         |" << endl
			<< "\t\t\t|    3000 Rs Only         |" << endl
			<< "\t\t\t|    5000 Rs Only         |" << endl
			<< "\t\t\t|    Custom  Only         |" << endl
			<< "\t\t\t\\_________________________/ " << endl;
		int money[] = { 1000, 2000, 3000, 5000, -1 };
		int indicator = 0;
		Graphics::goToXY(45, 7);
		cout << "X\b";

		while (true)
		{
			int ch = _getch();
			//cout << (int)ch;
			x = Graphics::whereX();
			y = Graphics::whereY();
			if (ch == 80 && indicator < 4) //DOWN
			{
				cout << " ";
				indicator++;
				Graphics::goToXY(x, y + 1);
				cout << "X\b";
			}
			if (ch == 72 && indicator != 0) //UP
			{
				cout << " ";
				indicator--;
				Graphics::goToXY(x, y - 1);
				cout << "X\b";
			}
			if (ch == 13)
			{
				int cash = money[indicator];
				if (cash == -1) {
					//cash = customMoney()
				}
				break;
			}
		}
	}


	bool transaction() {
		Graphics::cls();
		cout << endl << endl << endl;
		cout << setw(55) << " _________________________ " << endl;
		cout << setw(55) << "/                         \\" << endl;
		cout << setw(55) << "|  PROJECT B              |" << endl;
		cout << setw(55) << "|                         |" << endl;
		cout << setw(55) << "|                         |" << endl;
		Graphics::SetColor(Graphics::BLUE);
		cout << setw(55) << "|      Transaction        |" << endl;
		Graphics::SetColor(Graphics::WHITE);
		cout << setw(55) << "|                         |" << endl;
		cout << setw(55) << "|                         |" << endl;
		cout << setw(55) << "|                         |" << endl;
		cout << setw(55) << "\\________________________/" << endl;

		Graphics::goToXY(46, 8);
		cout << ".";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";

		Graphics::goToXY(35, 8);
		cout << "               ";
		Graphics::goToXY(30, 8);
		cout << "TRANSACTION COMPLETED!!!";

		Graphics::goToXY(31, 11);
		char choice;
		cout << "Want another (Y/N)? ";
		choice = getchar();
		Sleep(1000);
		return (choice == 'y' || choice == 'Y') ? true : false;

	}

	void accountBlocked() {
		cout << endl << endl << endl;
		cout << setw(55) << " _________________________ " << endl;
		cout << setw(55) << "/                         \\" << endl;
		cout << setw(55) << "|  PROJECT B              |" << endl;
		cout << setw(55) << "|                         |" << endl;
		cout << setw(55) << "|                         |" << endl;
		Graphics::SetColor(Graphics::RED);
		cout << setw(55) << "| ~~~ ACCOUNT BLOCKED ~~~ |" << endl;
		Graphics::SetColor(Graphics::WHITE);
		cout << setw(55) << "|                         |" << endl;
		cout << setw(55) << "|                         |" << endl;
		cout << setw(55) << "|                         |" << endl;
		cout << setw(55) << "\\_________________________/" << endl;
	}

public:
	void run(){
		string username = getUsername();
		Graphics::cls();
		string PIN = getPIN();
		Graphics::cls();
		Choice();
		Graphics::cls();
		Choice();
		transaction();
		_getch();
	}
};