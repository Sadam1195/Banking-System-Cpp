#ifndef ATM_UI_CPP
#define ATM_UI_CPP

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <conio.h>
#include <iomanip>
#include <windows.h>

#include "Graphics.cpp"
#include "Bank.cpp"

using namespace std;

class atmUI : private Graphics {
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
		cls();
		string username;

		cout << "\n\n\n";
		cout << "\t\t\t"; coutV2(" _________________________\n");
		cout << "\t\t\t"; coutV2("/                         \\\n");
		cout << "\t\t\t"; coutV2("|   "); coutV2("PROJECT B", TEAL); coutV2("             |\n");
		cout << "\t\t\t"; coutV2("|                         |\n");
		cout << "\t\t\t"; coutV2("|   "); coutV2("1234 5672 1892 1728", GREEN); coutV2("   |\n");
		cout << "\t\t\t"; coutV2("|   "); coutV2("NAME:",YELLOW); coutV2("                 |\n");
		cout << "\t\t\t"; coutV2("|                   ----  |\n");
		cout << "\t\t\t"; coutV2("|   "); coutV2("Valid: ", RED); coutV2("1 / 15"); coutV2("   VISA ", PINK); coutV2(" |\n");
		cout << "\t\t\t"; coutV2("|                   ----  |\n");
		cout << "\t\t\t"; coutV2("\\_________________________/\n");

		goToXY(34, 8);
		cin >> username;
		return username;
	}

	string getPIN() {
		cls();
		string PIN;
		
		cout << "\n\n\n";
		cout << "\t\t\t"; coutV2(" _________________________\n");
		cout << "\t\t\t"; coutV2("/                         \\\n");
		cout << "\t\t\t"; coutV2("|   "); coutV2("PROJECT B", TEAL); coutV2("             |\n");
		cout << "\t\t\t"; coutV2("|                         |\n");
		cout << "\t\t\t"; coutV2("|                         |\n");
		cout << "\t\t\t"; coutV2("|       "); coutV2("PIN:", YELLOW); coutV2("              |\n");
		cout << "\t\t\t"; coutV2("|                         |\n");
		cout << "\t\t\t"; coutV2("|                         |\n");
		cout << "\t\t\t"; coutV2("|                         |\n");  
		cout << "\t\t\t"; coutV2("\\_________________________/\n");

		goToXY(37, 8);
		PIN = getHiddenPIN();
		return PIN;
	}

	float customAmount() {
		cls();
		float amount = -1;
		cout << "\n\n\n";
		cout << "\t\t\t"; coutV2(" _________________________\n");
		cout << "\t\t\t"; coutV2("/                         \\\n");
		cout << "\t\t\t"; coutV2("|   "); coutV2("PROJECT B", TEAL); coutV2("             |\n");
		cout << "\t\t\t"; coutV2("|                         |\n");
		cout << "\t\t\t"; coutV2("|                         |\n");
		cout << "\t\t\t"; coutV2("|       "); coutV2("CUSTOM", YELLOW); coutV2("            |\n");
		cout << "\t\t\t"; coutV2("|       "); coutV2("AMOUNT:", YELLOW); coutV2("           |\n");
		cout << "\t\t\t"; coutV2("|                         |\n");
		cout << "\t\t\t"; coutV2("|                         |\n");
		cout << "\t\t\t"; coutV2("\\_________________________/\n");
		goToXY(40, 9);
		while (amount < 0) {
			cin >> amount;
		}

		return amount;
	}

	float Choice() {
		cls();
		int x, y;

		cout << "\n\n\n";
		cout << "\t\t\t"; coutV2(" _________________________\n");
		cout << "\t\t\t"; coutV2("/                         \\\n");
		cout << "\t\t\t"; coutV2("| "); coutV2("PROJECT B", TEAL); cout << " - "; coutV2("Amount      |\n");
		cout << "\t\t\t"; coutV2("|                         |\n");
		cout << "\t\t\t"; coutV2("|    "); coutV2("1000 Rs Only", YELLOW); coutV2("         |\n");
		cout << "\t\t\t"; coutV2("|    "); coutV2("2000 Rs Only", YELLOW); coutV2("         |\n");
		cout << "\t\t\t"; coutV2("|    "); coutV2("3000 Rs Only", YELLOW); coutV2("         |\n");
		cout << "\t\t\t"; coutV2("|    "); coutV2("5000 Rs Only", YELLOW); coutV2("         |\n");
		cout << "\t\t\t"; coutV2("|    "); coutV2("Custom  Only", YELLOW); coutV2("         |\n");
		cout << "\t\t\t"; coutV2("\\_________________________/\n");


		float money[] = { 1000, 2000, 3000, 5000, -1 };
		int indicator = 0;
		goToXY(45, 7);
		cout << "X\b";

		while (true)
		{
			int ch = _getch();
			x = whereX();
			y = whereY();
			if (ch == 80 && indicator < 4) //DOWN
			{
				cout << " ";
				indicator++;
				goToXY(x, y + 1);
				cout << "X\b";
			}
			if (ch == 72 && indicator != 0) //UP
			{
				cout << " ";
				indicator--;
				goToXY(x, y - 1);
				cout << "X\b";
			}
			if (ch == 13)
			{
				float cash = money[indicator];
				if (cash == -1) {
					cash = customAmount();
				}
				return cash;
			}
		}
	}

	bool transaction(string username, float deductBalance) {
		Bank branch;

		cls();
		cout << "\n\n\n";
		cout << "\t\t\t"; coutV2(" _________________________\n");
		cout << "\t\t\t"; coutV2("/                         \\\n");
		cout << "\t\t\t"; coutV2("|   "); coutV2("PROJECT B", TEAL); coutV2("             |\n");
		cout << "\t\t\t"; coutV2("|                         |\n");
		cout << "\t\t\t"; coutV2("|                         |\n");
		cout << "\t\t\t"; coutV2("|      "); coutV2("TRANSACTION", TEAL); coutV2("        |\n");
		cout << "\t\t\t"; coutV2("|                         |\n");
		cout << "\t\t\t"; coutV2("|                         |\n");
		cout << "\t\t\t"; coutV2("|                         |\n");
		cout << "\t\t\t"; coutV2("\\_________________________/\n");

		goToXY(42, 8);
		cout << ".";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";

		coutV3(35, 8, "               ");
		goToXY(30, 8);

		double balance = branch.getBalance(username);
		if (deductBalance <= balance) {
			branch.addBalance(username, -1.0 * balance);
			coutV2("TRANS COMPLETED!!!", PINK);

		}
		else
		{
			coutV2("MONEY OVERFLOW!!!", RED);
		}

		goToXY(27, 11);
		char choice;
		coutV2("Want another (Y/N)? ", DARKYELLOW);
		cin.clear();
		cin >> choice;
		Sleep(500);
		return (choice == 'y' || choice == 'Y') ? true : false;
	}

	bool accountBlocked() {
		cls();
		cout << "\n\n\n";
		cout << "\t\t\t"; coutV2(" _________________________\n");
		cout << "\t\t\t"; coutV2("/                         \\\n");
		cout << "\t\t\t"; coutV2("|   "); coutV2("PROJECT B", TEAL); coutV2("             |\n");
		cout << "\t\t\t"; coutV2("|                         |\n");
		cout << "\t\t\t"; coutV2("|                         |\n");
		cout << "\t\t\t"; coutV2("|       "); coutV2("~~ ACCOUNT BLOCKED ~~", RED); coutV2("              |\n");
		cout << "\t\t\t"; coutV2("|                         |\n");
		cout << "\t\t\t"; coutV2("|                         |\n");
		cout << "\t\t\t"; coutV2("|                         |\n");
		cout << "\t\t\t"; coutV2("\\_________________________/\n");

		goToXY(31, 11);
		char choice;
		cout << "Want another (Y/N)? ";
		choice = getchar();
		Sleep(1000);
		return (choice == 'y' || choice == 'Y') ? true : false;
	}

public:
	void run() {
		cls();

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

			if (failAttempts >= 3) {
				branch.unlockATM(branch.currentUser.username, 1);
				if (accountBlocked() == false) {
					return;
				}
			}
		}
	}
};

#endif