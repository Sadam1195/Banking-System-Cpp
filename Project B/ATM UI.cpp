#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include "Graphics.cpp"

using namespace std;

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
	cin >> PIN;
	return PIN;
}
void Choice()
{
	int x = 19;
	int y = 2;
	cout << "\t\t\t\t\t\tWelcome Owais Chisti" << endl;
	cout << "\t\t\tPlease,Enter the Amount" << endl;
	cout << "\t\t\t-------------------" << "\n\n"
		<< "\t\t\t| 1000 Rs Only     |" << "\n"
		<< "\t\t\t-------------------" << "\n\n"
		<< "\t\t\t| 2000 Rs Only     |" << "\n"
		<< "\t\t\t-------------------" << "\n\n"
		<< "\t\t\t| 3000 Rs Only     |" << "\n"
		<< "\t\t\t-------------------" << "\n\n"
		<< "\t\t\t| 5000 Rs Only     |" << "\n"
		<< "\t\t\t-------------------" << "\n\n"
		<< "\t\t\t| Custom  Only     |" << "\n"
		<< "\t\t\t-------------------";
	int money[] = { 1000, 2000, 3000, 5000, -1 };
	int indicator = 0;
	Graphics::goToXY(41, 4);
	getchar();
	while (true)
	{
		int ch = _getch();
		//cout << (int)ch;
		x = Graphics::whereX();
		y = Graphics::whereY();
		if (ch == 80 && indicator < 4) //DOWN
		{
			indicator++;
			Graphics::goToXY(x, y + 3);
		}
		if (ch == 72 && indicator != 0) //UP
		{
			indicator--;
			Graphics::goToXY(x, y - 3);
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

	system("cls");
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

	Graphics::goToXY(46, 5);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";

	Graphics::goToXY(35, 5);
	cout << "               ";
	Graphics::goToXY(30, 5);
	cout << "TRANSACTION COMPLETED!!!";

	_getch();
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



int main() {
	string username = getUsername();
	system("cls");
	string PIN = getPIN();
	system("cls");
	Choice();
	system("cls");
	//accountBlocked();
	//cout << username;
	system("pause");
	return 0;
}
