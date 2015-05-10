#include <iostream>
#include <cstdlib>    // system()
#include <stdio.h>    
#include <string>     // to_string()

#include "Login_UI.cpp"
#include "ATM_UI.cpp"
#include "Graphics.cpp"

using namespace std;

int main()
{
	// Set Screen Size
	system("MODE CON COLS=80 LINES=33");

	Graphics::SetColor(YELLOW);
	cout
		<< endl << endl
		<< "\t  ____                     _                 _             ____  " << endl
		<< "\t |  _ \\   _ __    ___     (_)   ___    ___  | |_          | __ ) " << endl
		<< "\t | |_) | | '__|  / _ \\    | |  / _ \\  / __| | __|         |  _ \\ " << endl
		<< "\t |  __/  | |    | (_) |   | | |  __/ | (__  | |_          | |_) |" << endl
		<< "\t |_|     |_|     \\___/   _/ |  \\___|  \\___|  \\__|         |____/ " << endl
		<< "\t                        |__/                                     " << endl;
	
	Graphics::SetColor(GREEN);
	cout << "\t\t\t\t\t\t    By Owais (P14-6011) " << endl
		 << "\t\t\t\t\t\t       Zerk (P14-6012)" << endl;
	
	


	Graphics::SetColor(DARKTEAL);
	Graphics::goToXY(30,15);
	cout << "ATM";
	Graphics::goToXY(30, 16);
	cout << "e-Banking";
	Graphics::SetColor(WHITE);

	int x = 45,
		y = 15;
	Graphics::goToXY(x, y);
	cout << "X\b";

	char ch;
	int count = 0;

	while (ch = _getch()) {
		if (ch == 80 && count < 1) { // DOWN
			cout << " \b";
			Graphics::goToXY(x, y += 1);
			cout << "X\b";
			count++;
		}
		if (ch == 72 && count != 0) { // UP
			cout << " \b";
			Graphics::goToXY(x, y -= 1);
			cout << "X\b";
			count--;
		}
		if (ch == 13) {
			switch (count) {
			case 0:
				atmUI atm;
				atm.run();
				break;
			case 1:
				loginUI online;
				online.run();
				break;
			}
			break;
		}
	}

	/*
	Bank branch;
	userDetail user;

	user.name = "Syed Owais Ali Chishti";
	user.username = "owais";
	user.password = "pass";
	user.pin = Bank::randomPIN();
	user.role = 1;
	user.atmBlocked = 0;


	if (branch.addUser(user) == true)// if return false mean user already exist with that username
	{
		cout << "User Added";
	}
	
	user.name = "Zerk Shaban";
	user.username = "zerk";
	user.password = "pass";
	user.pin = Bank::randomPIN();
	user.role = 1;
	user.atmBlocked = 0;


	if (branch.addUser(user) == true)// if return false mean user already exist with that username
	{
		cout << "User Added";
	}
	*/
	
	//Registration
	
	/*
	Bank branch;
	userDetail user;

	user.name = "Syed Owais Ali Chishti";
	user.username = "owais";
	user.password = "pass";
	user.pin = Bank::randomPIN();
	user.role = 1;
	user.atmBlocked = 0;

	
	if(branch.addUser(user) == true)// if return false mean user already exist with that username
	{
	cout << "User Added";
	}
	*/

	// Registration
	//Bank branch;
	//userDetail user;

	//user.name = "Syed Owais Ali Chishti";
	//user.username = "owais";
	//user.password = "pass";
	//user.pin = Bank::randomPIN();
	//user.role = 1;
	//user.atmBlocked = 0;

	/*
	if(branch.addUser(user) == true)// if return false mean user already exist with that username
	{
	cout << "User Added";
	}
	else {
	cout << "Unable to add user.";
	}
	*/

	/*
	// Login
	if (branch.login("owais", "pass", 1)) {
	cout << "Logged in";
	}
	else {
	cout << "Sorry!!! unable to log in.";
	}
	*/


	//logout();
	//cout << branch.isLogged();
	//cout << branch.user.name;

	//cout << branch.creationData();

	//string username = "owais";
	//branch.addBalance(username, -500);
	//cout << branch.getBalance(username);
	//branch.deleteUser(username);


	system("pause");
	return 0;
}