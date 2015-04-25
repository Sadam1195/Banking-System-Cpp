#ifndef GRAPHICS_CPP
#define GRAPHICS_CPP
#include "Graphics.cpp"
#endif

#ifndef Bank_CPP
#define Bank_CPP
#include "Bank.cpp"
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
	string getHiddenPIN() {
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
		return input;
	}

	string getUsername() {
		Graphics::cls();
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
		Graphics::cls();
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

	float customAmount() {
		Graphics::cls();
		float amount = -1;
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
		while (amount < 0) {
			cin >> amount;
		}
		
		return amount;
	}

	float Choice() {
		Graphics::cls();
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
					cash = customAmount();
				}
				return cash;
				break;
			}
		}
	}

	bool transaction(string username, float deductBalance) {
		Bank branch;

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

		float balance = branch.getBalance(username);
		if (deductBalance <= balance) {
			branch.addBalance(username, -1 * balance);
			cout << "TRANSACTION COMPLETED!!!";
		}
		else
		{
			cout << "MONEY OVERFLOW!!!";
		}	

		Graphics::goToXY(31, 11);
		char choice;
		cout << "Want another (Y/N)? ";
		cin.clear();
		cin >> choice;
		Sleep(500);
		return (choice == 'y' || choice == 'Y') ? true : false;
	}

	bool accountBlocked() {
		Graphics::cls();
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

		Graphics::goToXY(31, 11);
		char choice;
		cout << "Want another (Y/N)? ";
		choice = getchar();
		Sleep(1000);
		return (choice == 'y' || choice == 'Y') ? true : false;
	}

public:
	void run() {
		Bank branch;
		string username;
		while (true) {
			while (true) {
				username = getUsername();
				if (branch.usernameAlreadyExist(username) == true) {
					break;
				}
				if (accountBlocked()) {
					continue;
				}
				else {
					return;
				}
			}

			int failAttempts = 0;
			while (failAttempts < 3)
			{
				string pin = getPIN();
				if (branch.loginWithPIN(username, pin, 1)) {
					while (true) {
						float balance = Choice();
						if (transaction(username, balance)) {
							continue;
						}
						else {
							return;
						}

					}
					
				}
				else {
					failAttempts++;
				}
			}

			if (failAttempts == 3) {
				if (accountBlocked() == false) {
					return;
				}
			}
		}
	}
};