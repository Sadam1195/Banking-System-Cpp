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

		cout << "\n\n\n";
		cout << "\t\t\t"; Graphics::coutV2(" _________________________\n");
		cout << "\t\t\t"; Graphics::coutV2("/                         \\\n");
		cout << "\t\t\t"; Graphics::coutV2("|   "); Graphics::coutV2("PROJECT B", TEAL); Graphics::coutV2("             |\n");
		cout << "\t\t\t"; Graphics::coutV2("|                         |\n");
		cout << "\t\t\t"; Graphics::coutV2("|   "); Graphics::coutV2("1234 5672 1892 1728", GREEN); Graphics::coutV2("   |\n");
		cout << "\t\t\t"; Graphics::coutV2("|   "); Graphics::coutV2("NAME:",YELLOW); Graphics::coutV2("                 |\n");
		cout << "\t\t\t"; Graphics::coutV2("|                   ----  |\n");
		cout << "\t\t\t"; Graphics::coutV2("|   "); Graphics::coutV2("Valid: ", RED); Graphics::coutV2("1 / 15"); Graphics::coutV2("   VISA ", PINK); Graphics::coutV2(" |\n");
		cout << "\t\t\t"; Graphics::coutV2("|                   ----  |\n");
		cout << "\t\t\t"; Graphics::coutV2("\\_________________________/\n");

		Graphics::goToXY(34, 8);
		cin >> username;
		return username;
	}

	string getPIN() {
		Graphics::cls();
		string PIN;
		
		cout << "\n\n\n";
		cout << "\t\t\t"; Graphics::coutV2(" _________________________\n");
		cout << "\t\t\t"; Graphics::coutV2("/                         \\\n");
		cout << "\t\t\t"; Graphics::coutV2("|   "); Graphics::coutV2("PROJECT B", TEAL); Graphics::coutV2("             |\n");
		cout << "\t\t\t"; Graphics::coutV2("|                         |\n");
		cout << "\t\t\t"; Graphics::coutV2("|                         |\n");
		cout << "\t\t\t"; Graphics::coutV2("|       "); Graphics::coutV2("PIN:", YELLOW); Graphics::coutV2("              |\n");
		cout << "\t\t\t"; Graphics::coutV2("|                         |\n");
		cout << "\t\t\t"; Graphics::coutV2("|                         |\n");
		cout << "\t\t\t"; Graphics::coutV2("|                         |\n");  
		cout << "\t\t\t"; Graphics::coutV2("\\_________________________/\n");

		Graphics::goToXY(37, 8);
		PIN = getHiddenPIN();
		return PIN;
	}

	float customAmount() {
		Graphics::cls();
		float amount = -1;
		cout << "\n\n\n";
		cout << "\t\t\t"; Graphics::coutV2(" _________________________\n");
		cout << "\t\t\t"; Graphics::coutV2("/                         \\\n");
		cout << "\t\t\t"; Graphics::coutV2("|   "); Graphics::coutV2("PROJECT B", TEAL); Graphics::coutV2("             |\n");
		cout << "\t\t\t"; Graphics::coutV2("|                         |\n");
		cout << "\t\t\t"; Graphics::coutV2("|                         |\n");
		cout << "\t\t\t"; Graphics::coutV2("|       "); Graphics::coutV2("CUSTOM", YELLOW); Graphics::coutV2("            |\n");
		cout << "\t\t\t"; Graphics::coutV2("|       "); Graphics::coutV2("AMOUNT:", YELLOW); Graphics::coutV2("           |\n");
		cout << "\t\t\t"; Graphics::coutV2("|                         |\n");
		cout << "\t\t\t"; Graphics::coutV2("|                         |\n");
		cout << "\t\t\t"; Graphics::coutV2("\\_________________________/\n");
		Graphics::goToXY(40, 9);
		while (amount < 0) {
			cin >> amount;
		}

		return amount;
	}

	float Choice() {
		Graphics::cls();
		int x, y;

		cout << "\n\n\n";
		cout << "\t\t\t"; Graphics::coutV2(" _________________________\n");
		cout << "\t\t\t"; Graphics::coutV2("/                         \\\n");
		cout << "\t\t\t"; Graphics::coutV2("| "); Graphics::coutV2("PROJECT B", TEAL); cout << " - "; Graphics::coutV2("Amount      |\n");
		cout << "\t\t\t"; Graphics::coutV2("|                         |\n");
		cout << "\t\t\t"; Graphics::coutV2("|    "); Graphics::coutV2("1000 Rs Only", YELLOW); Graphics::coutV2("         |\n");
		cout << "\t\t\t"; Graphics::coutV2("|    "); Graphics::coutV2("2000 Rs Only", YELLOW); Graphics::coutV2("         |\n");
		cout << "\t\t\t"; Graphics::coutV2("|    "); Graphics::coutV2("3000 Rs Only", YELLOW); Graphics::coutV2("         |\n");
		cout << "\t\t\t"; Graphics::coutV2("|    "); Graphics::coutV2("5000 Rs Only", YELLOW); Graphics::coutV2("         |\n");
		cout << "\t\t\t"; Graphics::coutV2("|    "); Graphics::coutV2("Custom  Only", YELLOW); Graphics::coutV2("         |\n");
		cout << "\t\t\t"; Graphics::coutV2("\\_________________________/\n");


		float money[] = { 1000, 2000, 3000, 5000, -1 };
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

		Graphics::cls();
		cout << "\n\n\n";
		cout << "\t\t\t"; Graphics::coutV2(" _________________________\n");
		cout << "\t\t\t"; Graphics::coutV2("/                         \\\n");
		cout << "\t\t\t"; Graphics::coutV2("|   "); Graphics::coutV2("PROJECT B", TEAL); Graphics::coutV2("             |\n");
		cout << "\t\t\t"; Graphics::coutV2("|                         |\n");
		cout << "\t\t\t"; Graphics::coutV2("|                         |\n");
		cout << "\t\t\t"; Graphics::coutV2("|      "); Graphics::coutV2("TRANSACTION", TEAL); Graphics::coutV2("        |\n");
		cout << "\t\t\t"; Graphics::coutV2("|                         |\n");
		cout << "\t\t\t"; Graphics::coutV2("|                         |\n");
		cout << "\t\t\t"; Graphics::coutV2("|                         |\n");
		cout << "\t\t\t"; Graphics::coutV2("\\_________________________/\n");

		Graphics::goToXY(42, 8);
		cout << ".";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";

		Graphics::coutV3(35, 8, "               ");
		Graphics::goToXY(30, 8);

		double balance = branch.getBalance(username);
		if (deductBalance <= balance) {
			branch.addBalance(username, -1.0 * balance);
			Graphics::coutV2("TRANSACTION COMPLETED!!!", PINK);

		}
		else
		{
			Graphics::coutV2("MONEY OVERFLOW!!!", RED);
		}

		Graphics::goToXY(27, 11);
		char choice;
		Graphics::coutV2("Want another (Y/N)? ", DARKYELLOW);
		cin.clear();
		cin >> choice;
		Sleep(500);
		return (choice == 'y' || choice == 'Y') ? true : false;
	}

	bool accountBlocked() {
		Graphics::cls();
		cout << "\n\n\n";
		cout << "\t\t\t"; Graphics::coutV2(" _________________________\n");
		cout << "\t\t\t"; Graphics::coutV2("/                         \\\n");
		cout << "\t\t\t"; Graphics::coutV2("|   "); Graphics::coutV2("PROJECT B", TEAL); Graphics::coutV2("             |\n");
		cout << "\t\t\t"; Graphics::coutV2("|                         |\n");
		cout << "\t\t\t"; Graphics::coutV2("|                         |\n");
		cout << "\t\t\t"; Graphics::coutV2("|       "); Graphics::coutV2("~~ ACCOUNT BLOCKED ~~", RED); Graphics::coutV2("              |\n");
		cout << "\t\t\t"; Graphics::coutV2("|                         |\n");
		cout << "\t\t\t"; Graphics::coutV2("|                         |\n");
		cout << "\t\t\t"; Graphics::coutV2("|                         |\n");
		cout << "\t\t\t"; Graphics::coutV2("\\_________________________/\n");

		Graphics::goToXY(31, 11);
		char choice;
		cout << "Want another (Y/N)? ";
		choice = getchar();
		Sleep(1000);
		return (choice == 'y' || choice == 'Y') ? true : false;
	}

public:
	void run() {
		Graphics::cls();

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
					branch.unlockATM(branch.currentUser.username, 1);
					return;
				}
			}
		}
	}
};