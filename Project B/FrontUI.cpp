#include <iostream>
#include <cstdlib>    // system()
#include <stdio.h>    
#include <string>     // to_string()

#include "Login_UI.cpp"
#include "ATM_UI.cpp"
#include "Graphics.cpp"
#include "FileLogger.cpp"

void frontUI() {
	// Set Screen Size
	system("MODE CON COLS=80 LINES=25");

	ige::FileLogger myLog("1.0.4.2", "testfile.txt");
	myLog << "Initiated";
	myLog << ige::FileLogger::e_logType::LOG_WARNING << "Hey! ... This is a warning message!";
	myLog << ige::FileLogger::e_logType::LOG_ERROR << "WOW! Something really wrong is happening here!";
	myLog << "This is just a simple text";

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
	Graphics::goToXY(30, 15);
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

}