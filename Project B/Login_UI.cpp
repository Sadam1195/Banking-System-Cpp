#ifndef LOGIN_UI_CPP
#define LOGIN_UI_CPP

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include <string>
#include "Graphics.cpp"
#include "Bank.cpp"

using namespace std;

class loginUI : private Graphics
{
private:
	bool logged = false;
	string username, password;
	int role;
	Bank LoggedUser;

	void setTitle(string title) {
		coutV3(30, 1, title, DARKYELLOW);
	}

	string userInput(int type) {
		char ch;
		string input;
		ch = _getch();
		while (ch != 13) {
			if (type == 1 && ch >= 'a' && ch <= 'z') { //username
				cout << ch;
				input += ch;
			}
			else if (type == 2)  { //password
				cout << "*";
				input += ch;
			}
			else if (type == 3 && ch >= '0' && ch <= '9') { //Role
				if (ch == '1' || ch == '2' || ch == '3') {
					cout << ch;
					input += ch;
					break;
				}

			}
			ch = _getch();
		}
		return input;
	}

	bool login() {
		cls();
		while (true) {
			goToXY(20, 5);
			coutV3(20, 5, "------------------------------------", TEAL);

			coutV3(25, 7, "          *** LOGIN ***             ", GREEN);

			coutV3(25, 10, "Username: ", YELLOW);
			coutV3(25, 11, "Password: ", YELLOW);

			coutV3(25, 13, "~ OPTIONS ~", PINK);
			coutV3(25, 14, " 1) User", GRAY);
			coutV3(25, 15, " 2) Accountant", GRAY);
			coutV3(25, 16, " 3) Manager", GRAY);
			coutV3(25, 17, "Role: ", YELLOW);
			coutV3(25, 18, "                       --------    ", WHITE);
			coutV3(25, 19, "                        SUBMIT     ", WHITE);
			coutV3(25, 20, "                       --------    ", WHITE);
			coutV3(20, 21, "------------------------------------", TEAL);


			coutV3(35, 10, "                  ");
			coutV3(35, 11, "                  ");
			coutV3(31, 17, "                  ");

			goToXY(35, 10);
			username = userInput(1);

			goToXY(35, 11);
			password = userInput(2);

			goToXY(31, 17);
			role = atoi(userInput(3).c_str());

			goToXY(0, 0);

			POINT up = { 385, 258 },
				down = { 446, 286 };

			while (true) {
			//while (GetAsyncKeyState(VK_RETURN) != 0) {
				//if ((GetKeyState(VK_LBUTTON) & 0x80) != 0) {
					if (positionClicked(up, down)) break;
					Sleep(10);
				//}
			}

			if (LoggedUser.login(username, password, role))
			{
				return true;
			}
		}
	}

	void clearShowScreen() {
		string empty;
		for (int i = 0; i < (80 - 20); i++) {
			empty += " ";
		}

		for (int i = 0; i < 20; i++) {
			goToXY(20, i);
			cout << empty;
		}

		coutV3(45, 30, "Copyright (C) 2015 | Zerk & Owais", DARKTEAL);
	}

	void getFunction(int funcID) {
		clearShowScreen();
		if (LoggedUser.currentUser.role == 1) { // USER
			switch (funcID) {
			case 0:
				Information();
				break;
			case 1:
				Transfer_Money();
				break;
			case 2:
				Change_Password();
				break;
			case 3:
				Change_PIN();
				break;
			case 4:
				Log_Out();
				break;
			}
		}
		if (LoggedUser.currentUser.role == 2) { // ACCOUNTANT
			switch (funcID) {
			case 0:
				Information();
				break;
			case 1:
				Add_Money();
				break;
			case 2:
				Add_User();
				break;
			case 3:
				Change_Password();
				break;
			case 4:
				Log_Out();
				break;
			}
		}
		if (LoggedUser.currentUser.role == 3) { // MANAGER
			switch (funcID) {
			case 0:
				Information();
				break;
			case 1:
				Add_Money();
				break;
			case 2:
				Add_User();
				break;
			case 3:
				Delete_Account();
				break;
			case 4:
				Unblock_ATM();
				break;
			case 5:
				Change_User_Password();
				break;
			case 6:
				Change_User_PIN();
				break;
			case 7:
				Change_Password();
				break;
			case 8:
				Log_Out();
				break;
			}
		}
	}

	string nonBlockingCIN(bool show = true, bool hide = false) {
		string text = "";
		char ch;
		goToXY(whereX(), whereY());
		while (ch = _getch())
		{
			if (ch == 80)			throw 1; // UP
			else if (ch == 72)		throw 2; // DOWN
			else if (ch == 9)		throw 3; // TAB
			else if (ch == 13)  return text;
			else {
				if (ch != -32) {
					if (hide)
						cout << (char)ch;
					else if (show)
						cout << (char)ch;
					else
						cout << "*";
					text.push_back(ch);
				}
			}
		}

		return ""; //removing warning
	}

	void menu() {
		int optionsCount = 0;
		if (LoggedUser.currentUser.role == 1) { //USER
			optionsCount = 4;

			coutV2("-------------------\n\n", DARKGREEN);
			coutV2(" Hello,           "); coutV2("|\n", GREEN);
			coutV2("-------------------\n\n", DARKGREEN);
			coutV2(" Information      ", GRAY); coutV2("| \n", GREEN);
			coutV2("-------------------\n\n", DARKGREEN);
			coutV2(" Transfer Money   ", GRAY); coutV2("|\n", GREEN);
			coutV2("-------------------\n\n", DARKGREEN);
			coutV2(" Change Password  ", GRAY); coutV2("|\n", GREEN);
			coutV2("-------------------\n\n", DARKGREEN);
			coutV2(" Change PIN       ", GRAY); coutV2("|\n", GREEN);
			coutV2("-------------------\n\n", DARKGREEN);
			coutV2(" Logout           ", GRAY); coutV2("|\n", GREEN);
			coutV2("-------------------\n\n", DARKGREEN);
			coutV2("                  |\n\n\n", GREEN);
			coutV2("                  |\n\n\n", GREEN);
			coutV2("                  |\n\n\n", GREEN);
			coutV2("                  |\n\n\n", GREEN);
		}

		if (LoggedUser.currentUser.role == 2) { //ACCOUNTANT
			optionsCount = 4;

			coutV2("-------------------\n\n", DARKGREEN);
			coutV2(" Hello,           ", GRAY); cout << "|\n";
			coutV2("-------------------\n\n", DARKGREEN);
			coutV2(" Information      ", GRAY); cout << "|\n";
			coutV2("-------------------\n\n", DARKGREEN);
			coutV2(" Add Money        ", GRAY); coutV2("|\n", GREEN);
			coutV2("-------------------\n\n", DARKGREEN);
			coutV2(" Add User         ", GRAY); coutV2("|\n", GREEN);
			coutV2("-------------------\n\n", DARKGREEN);
			coutV2(" Change Password  ", GRAY); coutV2("|\n", GREEN);
			coutV2("-------------------\n\n", DARKGREEN);
			coutV2(" Logout           ", GRAY); coutV2("|\n", GREEN);
			coutV2("-------------------\n\n", DARKGREEN);
			coutV2("                  |\n\n\n", GREEN);
			coutV2("                  |\n\n\n", GREEN);
			coutV2("                  |\n\n\n", GREEN);
			coutV2("                  |\n\n\n", GREEN);
		}
		if (LoggedUser.currentUser.role == 3) { //MANAGER
			optionsCount = 8;

			coutV2("-------------------\n\n", DARKGREEN);
			coutV2(" Hello,           ", GRAY); coutV2("|\n", GREEN);
			coutV2("-------------------\n\n", DARKGREEN);
			coutV2(" Information      ", GRAY); coutV2("|\n", GREEN);
			coutV2("-------------------\n\n", DARKGREEN);
			coutV2(" Add Money        ", GRAY); coutV2("|\n", GREEN);
			coutV2("-------------------\n\n", DARKGREEN);
			coutV2(" Add User         ", GRAY); coutV2("|\n", GREEN);
			coutV2("-------------------\n\n", DARKGREEN);
			coutV2(" Remove Account   ", GRAY); coutV2("| \n", GREEN);
			coutV2("-------------------\n\n", DARKGREEN);
			coutV2(" Unblock ATM      ", GRAY); coutV2("|\n", GREEN);
			coutV2("-------------------\n\n", DARKGREEN);
			coutV2(" Change User Pass ", GRAY); coutV2("|\n", GREEN);
			coutV2("-------------------\n\n", DARKGREEN);
			coutV2(" Change User PIN  ", GRAY); coutV2("|\n", GREEN);
			coutV2("-------------------\n\n", DARKGREEN);
			coutV2(" Change Password  ", GRAY); coutV2("|\n", GREEN);
			coutV2("-------------------\n\n", DARKGREEN);
			coutV2(" Logout           ", GRAY); coutV2("|\n", GREEN);
			coutV2("-------------------\n\n", DARKGREEN);
		}

		coutV3(8, 2, LoggedUser.currentUser.username, GREEN);

		int count = 0;

		int x = 18;
		int y = 5;

		goToXY(18, y);
		coutColored(GREEN, "X\b");

		char ch = 0;
		while (true) {
			try {
				if (ch == 80 && count < optionsCount) { // DOWN
					goToXY(18, y);
					cout << "|";
					y += 3;
					count++;
				}
				if (ch == 72 && count != 0) { // UP
					goToXY(18, y);
					cout << "|";
					y -= 3;
					count--;
				}
				if (ch == 9){
					POINT c[100][2] = {
						{ { 0, 50 }, { 150, 90 } },
						{ { 0, 90 }, { 150, 130 } },
						{ { 0, 130 }, { 150, 170 } },
						{ { 0, 170 }, { 150, 210 } },
						{ { 0, 210 }, { 150, 250 } },
						{ { 0, 250 }, { 150, 290 } },
						{ { 0, 290 }, { 150, 330 } },
						{ { 0, 330 }, { 150, 370 } },
						{ { 0, 370 }, { 150, 410 } }
					};

					for (int i = 0; i <= optionsCount; i++) {
						if (positionClicked(c[i][0], c[i][1])) {
							count = i;
							goToXY(18, y);
							cout << "|";
							y = 5 + (i * 3);
							break;
						}
						Sleep(100);
						if (i == optionsCount) i = 0;
					}
				}

				goToXY(18, y);
				coutColored(GREEN, "X\b");

				getFunction(count);
				ch = getch();
			}
			catch (int e) {
				if (e == 1) ch = 80;
				else if (e == 2) ch = 72;
				else if (e == 3) ch = 9;
			}
		}
		_getch();
	}

	void Information()
	{
		setTitle("!!! INFORMATION !!!");
		userDetail user;
		int x = 30;
		int y = 8;

		coutV3(x, y++, "Name: ", YELLOW);

		coutV3(36, 8, LoggedUser.currentUser.name);

		coutV3(x, y++, "Creation Date: ", YELLOW);

		coutV3(45, 9, LoggedUser.creationData());


		if (LoggedUser.currentUser.role == 1)
		{
			coutV3(x, y, "Balance: ", YELLOW);
			coutV3(x + 10, y++, to_string_precision(LoggedUser.getBalance(username)));
			coutV3(x, y++, "Status:", YELLOW);
			coutV3(x + 9, 11, "User");

		}
		else if (LoggedUser.user.role == 2)
		{
			coutV3(x, y, "Status: ", YELLOW);
			coutV3(x + 9, 10, "Accountant");
		}
		else if (LoggedUser.user.role == 3)
		{
			coutV3(x, y, "Status: ", YELLOW);
			coutV3(x + 9, 10, "Manager");
		}
		nonBlockingCIN(true,true);
	}

	void Transfer_Money()
	{
		try {
			setTitle("!!! TRANSFER MONEY !!!");
			int Amount_Sended = -1;
			string Reciver_Name;
			Bank LoggedUser;
			int x = 30;
			int y = 8;

			coutV3(x, y++, "Reciever Name: ", YELLOW);
			coutV3(x, y++, "Amount: ", YELLOW);

			while (true)
			{
				goToXY(45, y - 2);
				Reciver_Name = nonBlockingCIN();
				if (Reciver_Name == "") return;

				if (LoggedUser.usernameAlreadyExist(Reciver_Name))
				{
					break;
				}
				else {
					coutV3(44, 9, "         ");
				}
			}

			string dummy;
			goToXY(38, y - 1);
			dummy = nonBlockingCIN();
			if (dummy == "") return;
			Amount_Sended = atoi(dummy.c_str());

			double Sender_Bal = LoggedUser.getBalance(username);

			if (Amount_Sended <= Sender_Bal)
			{
				LoggedUser.addBalance(username, -1 * Amount_Sended);
				LoggedUser.addBalance(Reciver_Name, Amount_Sended);
				coutV3(x, y += 4, "Money Successfully Transfered!!!", BLUE);
			}
			else
			{

				coutV3(x, y += 4, "Money Over-flow!!! ", RED);
			}
		}
		catch (int e) {
			throw e;
		}

	}

	void Change_Password()
	{
		try {
			setTitle("!!! CHANGE PASSWORD !!!");
			string new_pass;
			int x = 30;
			int y = 8;
			coutV3(x, y, "Enter new password: ", YELLOW);

			goToXY(x + 20, y);
			new_pass = nonBlockingCIN(true);
			LoggedUser.changePassword(LoggedUser.currentUser.username, new_pass);

			coutV3(x, y += 4, "Password Changed.", BLUE);

		}

		catch (int e) {
			throw e;
		}

	}

	void Change_PIN()
	{
		try {
			setTitle("!!! CHANGE PIN !!!");
			string new_pin;
			int x = 30;
			int y = 8;
			coutV3(x, y, "Enter new pin: ", YELLOW);

			goToXY(x + 15, y);
			new_pin = nonBlockingCIN(true);
			if (new_pin == "") return;

			LoggedUser.changePIN(LoggedUser.currentUser.username, atoi(new_pin.c_str()));

			coutV3(x, y += 4, "PIN Changed!!!", BLUE);
		}
		catch (int e) {
			throw e;
		}

	}

	void Log_Out()
	{
		try {
			setTitle("!!! LOGOUT !!!");
			string dummy;
			int x = 30;
			int y = 8;
			coutV3(x, y, "Do you want to Log Out - Press Enter", YELLOW);

			dummy = nonBlockingCIN(true, true);

			if (dummy == "")
			{
				LoggedUser.logout();
				run();
				return;
			}
		}
		catch (int e) {
			throw e;
		}
	}

	void unlockATM()
	{
			setTitle("!!! UNLOCK ATM !!!");
			string new_pass;
			int x = 30;
			int y = 8;
			coutV3(x, y, "Username: ", YELLOW);

			goToXY(x + 10, y);
			username = nonBlockingCIN();

			LoggedUser.unlockATM(LoggedUser.currentUser.username, 0);

			coutV3(x, y += 4, username + " atm unlocked.", BLUE);
	}

	void Add_Money() {
			setTitle("!!! ADD MONEY !!!");
			int x = 30;
			int y = 8;

			coutV3(x, y++, "Username: ", YELLOW);
			coutV3(x, y++, "Amount: ", YELLOW);

			goToXY(x + 10, y - 2); string username = nonBlockingCIN();
			goToXY(x + 8, y - 1); double amount = atof(nonBlockingCIN().c_str());

			if (LoggedUser.addBalance(username, amount) == true) {
				coutV3(x, y += 4, "Amount successfully added.", BLUE);
			}
			else {
				coutV3(x, y += 4, "Failed to add money.", RED);
			}
	}

	void Change_User_Password() {
			setTitle("!!! CHANGE USER PASSWORD !!!");
			int x = 30;
			int y = 8;

			coutV3(x, y++, "Username: ", YELLOW);
			coutV3(x, y++, "New Password: ", YELLOW);

			goToXY(x + 10, y - 2); string username = nonBlockingCIN();
			goToXY(x + 14, y - 1); string pass = nonBlockingCIN();

			if (LoggedUser.changePassword(username, pass) == true) {
				coutV3(x, y += 4, "Password Changed", BLUE);
			}
			else {
				coutV3(x, y += 4, "Failed to change password.", BLUE);
			}
	}

	void Change_User_PIN() {
			setTitle("!!! CHANGE USER PIN !!!");
			int x = 30;
			int y = 8;

			coutV3(x, y++, "Username: ", YELLOW);
			coutV3(x, y++, "New PIN: ", YELLOW);


			goToXY(x + 10, y - 2); string username = nonBlockingCIN();
			goToXY(x + 9, y - 1); string PIN = nonBlockingCIN();

			if (LoggedUser.changePIN(username, atoi(PIN.c_str())) == true) {
				coutV3(x, y += 4, "PIN Changed", BLUE);
			}
			else {
				coutV3(x, y += 4, "Failed to change PIN.", RED);
			}
	}

	void Delete_Account() {
			setTitle("!!! DELETE ACCOUNT !!!");
			int x = 30;
			int y = 8;
			coutV3(x, y++, "Username: ", YELLOW);
			coutV3(x, y++, "Are you sure (Y/N): ", YELLOW);

			goToXY(x + 10, y - 2); string username = nonBlockingCIN();

			goToXY(x + 20, y - 1); string confirm = nonBlockingCIN();


			if (confirm[0] == 'Y' || confirm[0] == 'y') {
				LoggedUser.deleteUser(username);
				coutV3(x, y += 4, "User removed.", BLUE);
			}
			else {
				coutV3(x, y += 4, "Fail to remove user.", RED);
			}
	}

	void Unblock_ATM() {
			setTitle("!!! UNLOCK ATM !!!");
			int x = 30;
			int y = 8;
			coutV3(x, y, "Username: ", YELLOW);

			goToXY(x + 10, y); string username = nonBlockingCIN();

			if (LoggedUser.unlockATM(username, 0) == true) {
				coutV3(x, y += 4, "User ATM unlocked.", BLUE);
			}
			else {
				coutV3(x, y += 4, "User ATM unlocked.", RED);

			}
	}

	void Add_User() {
			setTitle("!!! ADD USER !!!");
			userDetail newUser;

			int x = 30;
			int y = 8;

			coutV3(x, y++, "Name: ", YELLOW);
			coutV3(x, y++, "Username: ", YELLOW);
			coutV3(x, y++, "Password: ", YELLOW);
			coutV3(x, y++, "Role: ", YELLOW);

			goToXY(x + 6, y - 4); newUser.name = nonBlockingCIN();
			goToXY(x + 10, y - 3); newUser.username = nonBlockingCIN();
			goToXY(x + 10, y - 2); newUser.password = nonBlockingCIN(false);
			goToXY(x + 6, y - 1); newUser.role = atoi(nonBlockingCIN().c_str());

			if (newUser.role < 1 && newUser.role > 3) {
				newUser.role = 1;
			}

			newUser.pin = Bank::randomPIN();
			newUser.atmBlocked = 0;

			if (LoggedUser.addUser(newUser) == true)// if return false mean user already exist with that username
			{
				coutV3(x, y + 4, "User Added", BLUE);
				coutV3(x, y + 5, "ATM PIN is " + to_string(newUser.pin), BLUE);

			}
			else {
				coutV3(x, y + 4, "User Already Exist", RED);
			}
	}

public:
	void run() {
		cls();

		if (login()) {
			cls();
			menu();
		}
	}
};

#endif