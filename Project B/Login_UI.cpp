#ifndef LOGIN_UI_CPP
#define LOGIN_UI_CPP

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include "Graphics.cpp"
#include "Bank.cpp"

using namespace std;

class loginUI
{
private:
	bool logged = false;
	string username, password;
	int role;
	Bank LoggedUser;
	
	void setTitle(string title) {
		Graphics::coutV3(30, 1, title, DARKYELLOW);
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
		Graphics::cls();
		while (true) {
			Graphics::goToXY(20, 5);
			Graphics::coutV3(20, 5, "------------------------------------", TEAL);

			Graphics::coutV3(25, 7, "          *** LOGIN ***             ", GREEN);

			Graphics::coutV3(25, 10, "Username: ", YELLOW);
			Graphics::coutV3(25, 11, "Password: ", YELLOW);

			Graphics::coutV3(25, 13, "~ OPTIONS ~", PINK);
			Graphics::coutV3(25, 14, " 1) User" , GRAY);
			Graphics::coutV3(25, 15, " 2) Accountant", GRAY);
			Graphics::coutV3(25, 16, " 3) Manager", GRAY);
			Graphics::coutV3(25, 17, "Role: ", YELLOW);

			Graphics::coutV3(20, 19, "------------------------------------", TEAL);


			Graphics::coutV3(35, 10, "                  ");
			Graphics::coutV3(35, 11, "                  ");
			Graphics::coutV3(35, 17, "                  ");

			Graphics::goToXY(35, 10);
			username = userInput(1);

			Graphics::goToXY(35, 11);
			password = userInput(2);

			Graphics::goToXY(31, 17);
			role = atoi(userInput(3).c_str());

			Graphics::goToXY(35, 15);

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
			Graphics::goToXY(20, i);
			cout << empty;
		}

		Graphics::coutV3(45, 30, "Copyright (C) 2015 | Zerk & Owais" , DARKTEAL);
	}

	void getFunction(int funcID) {
		try {
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
		catch (int e) {
			throw e;
		}
	}

	string nonBlockingCIN(bool show = true, bool hide = false) {
		try {
			string text = "";
			char ch;
			Graphics::goToXY(Graphics::whereX(), Graphics::whereY());
			while (ch = _getch())
			{
	
				if (ch == 80)		throw 1;
				if (ch == 72)		throw 2;
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
		}
		catch (int e){
			throw e;
		}

		return ""; //removing warning
	}

	void menu() {
		int optionsCount = 0;
		if (LoggedUser.currentUser.role == 1) { //USER
			optionsCount = 4;

			Graphics::coutV2("-------------------\n\n", DARKGREEN);
			Graphics::coutV2(" Hello,           "); Graphics::coutV2("|\n", GREEN);
			Graphics::coutV2("-------------------\n\n", DARKGREEN);
			Graphics::coutV2(" Information      ", GRAY); Graphics::coutV2("| \n", GREEN);
			Graphics::coutV2("-------------------\n\n", DARKGREEN);
			Graphics::coutV2(" Transfer Money   ", GRAY); Graphics::coutV2("|\n", GREEN);
			Graphics::coutV2("-------------------\n\n", DARKGREEN);
			Graphics::coutV2(" Change Password  ", GRAY); Graphics::coutV2("|\n", GREEN);
			Graphics::coutV2("-------------------\n\n", DARKGREEN);
			Graphics::coutV2(" Change PIN       ", GRAY); Graphics::coutV2("|\n", GREEN);
			Graphics::coutV2("-------------------\n\n", DARKGREEN);
			Graphics::coutV2(" Logout           ", GRAY); Graphics::coutV2("|\n", GREEN);
			Graphics::coutV2("-------------------\n\n", DARKGREEN);
			Graphics::coutV2("                  |\n\n\n", GREEN);
			Graphics::coutV2("                  |\n\n\n", GREEN);
			Graphics::coutV2("                  |\n\n\n", GREEN);
			Graphics::coutV2("                  |\n\n\n", GREEN);
		}
			
		if (LoggedUser.currentUser.role == 2) { //ACCOUNTANT
			optionsCount = 4;

			Graphics::coutV2("-------------------\n\n", DARKGREEN);
			Graphics::coutV2(" Hello,           ", GRAY); cout << "|\n";
			Graphics::coutV2("-------------------\n\n", DARKGREEN);
			Graphics::coutV2(" Information      ", GRAY); cout << "|\n";
			Graphics::coutV2("-------------------\n\n", DARKGREEN);
			Graphics::coutV2(" Add Money        ", GRAY); Graphics::coutV2("|\n", GREEN);
			Graphics::coutV2("-------------------\n\n", DARKGREEN);
			Graphics::coutV2(" Add User         ", GRAY); Graphics::coutV2("|\n", GREEN);
			Graphics::coutV2("-------------------\n\n", DARKGREEN);
			Graphics::coutV2(" Change Password  ", GRAY); Graphics::coutV2("|\n", GREEN);
			Graphics::coutV2("-------------------\n\n", DARKGREEN);
			Graphics::coutV2(" Logout           ", GRAY); Graphics::coutV2("|\n", GREEN);
			Graphics::coutV2("-------------------\n\n", DARKGREEN);
			Graphics::coutV2("                  |\n\n\n", GREEN);
			Graphics::coutV2("                  |\n\n\n", GREEN);
			Graphics::coutV2("                  |\n\n\n", GREEN);
			Graphics::coutV2("                  |\n\n\n", GREEN);
		}
		if (LoggedUser.currentUser.role == 3) { //MANAGER
			optionsCount = 8;

			Graphics::coutV2("-------------------\n\n", DARKGREEN);
			Graphics::coutV2(" Hello,           ", GRAY); Graphics::coutV2("|\n", GREEN);
			Graphics::coutV2("-------------------\n\n", DARKGREEN);
			Graphics::coutV2(" Information      ", GRAY); Graphics::coutV2("|\n", GREEN);
			Graphics::coutV2("-------------------\n\n", DARKGREEN);
			Graphics::coutV2(" Add Money        ", GRAY); Graphics::coutV2("|\n", GREEN);
			Graphics::coutV2("-------------------\n\n", DARKGREEN);
			Graphics::coutV2(" Add User         ", GRAY); Graphics::coutV2("|\n", GREEN);
			Graphics::coutV2("-------------------\n\n", DARKGREEN);
			Graphics::coutV2(" Remove Account   ", GRAY); Graphics::coutV2("| \n", GREEN);
			Graphics::coutV2("-------------------\n\n", DARKGREEN);
			Graphics::coutV2(" Unblock ATM      ", GRAY); Graphics::coutV2("|\n", GREEN);
			Graphics::coutV2("-------------------\n\n", DARKGREEN);
			Graphics::coutV2(" Change User Pass ", GRAY); Graphics::coutV2("|\n", GREEN);
			Graphics::coutV2("-------------------\n\n", DARKGREEN);
			Graphics::coutV2(" Change User PIN  ", GRAY); Graphics::coutV2("|\n", GREEN);
			Graphics::coutV2("-------------------\n\n", DARKGREEN);
			Graphics::coutV2(" Change Password  ", GRAY); Graphics::coutV2("|\n", GREEN);
			Graphics::coutV2("-------------------\n\n", DARKGREEN);
			Graphics::coutV2(" Logout           ", GRAY); Graphics::coutV2("|\n", GREEN);
			Graphics::coutV2("-------------------\n\n", DARKGREEN);
		}

		Graphics::coutV3(8, 2, LoggedUser.currentUser.username, GREEN);

		int count = 0;

		int x = 18;
		int y = 5;

		Graphics::goToXY(18, y);
		Graphics::coutColored(GREEN,"X\b");

		getFunction(count);

		char ch;
		ch = getch();
		while (true) {
			try {
				if (ch == 80 && count < optionsCount) { // DOWN
					Graphics::goToXY(18, y);
					cout << "|";
					Graphics::goToXY(18, y += 3);
					Graphics::coutColored(GREEN, "X\b");
					count++;
					getFunction(count);

				}
				if (ch == 72 && count != 0) { // UP
					Graphics::goToXY(18, y);
					cout << "|";
					Graphics::goToXY(18, y -= 3);
					Graphics::coutColored(GREEN, "X\b");
					count--;
					getFunction(count);
				}

				ch = getch();
			}
			catch (int e) {
				if (e == 1) ch = 80;
				if (e == 2) ch = 72;
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

		Graphics::coutV3(x, y++, "Name: ", YELLOW);

		Graphics::coutV3(36, 8, LoggedUser.currentUser.name);

		Graphics::coutV3(x, y++, "Creation Date: ", YELLOW);

		Graphics::coutV3(45, 9, LoggedUser.creationData());

	
		if (LoggedUser.currentUser.role == 1)
		{
			Graphics::coutV3(x, y, "Balance: ", YELLOW);
			Graphics::coutV3(x+10, y++, to_string(LoggedUser.getBalance(username)));
			Graphics::coutV3(x, y++, "Status:", YELLOW);
			Graphics::coutV3(x + 9, 11, "User");

		}
		else if (LoggedUser.user.role == 2)
		{
			Graphics::coutV3(x, y, "Status: ", YELLOW);
			Graphics::coutV3(x + 9, 10, "Accountant");
		}
		else if (LoggedUser.user.role == 3)
		{
			Graphics::coutV3(x, y, "Status: ", YELLOW);
			Graphics::coutV3(x + 9, 10, "Manager");
		}
		_getch();
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

			Graphics::coutV3(x, y++, "Reciever Name: ", YELLOW);
			Graphics::coutV3(x, y++, "Amount: ", YELLOW);


			while (true)
			{
				Graphics::goToXY(45, 8);
				Reciver_Name = nonBlockingCIN();
				if (Reciver_Name == "") return;

				if (LoggedUser.usernameAlreadyExist(Reciver_Name))
				{
					break;
				}
				else {
					Graphics::coutV3(44, 9, "         ");
				}
			}

			string dummy;
			Graphics::goToXY(38, 10);
			dummy = nonBlockingCIN();
			if (dummy == "") return;
			Amount_Sended = atoi(dummy.c_str());

			double Sender_Bal = LoggedUser.getBalance(LoggedUser.currentUser.username);

			if (Amount_Sended <= Sender_Bal)
			{
				LoggedUser.addBalance(LoggedUser.currentUser.username, -1 * Amount_Sended);
				LoggedUser.addBalance(Reciver_Name, Amount_Sended);
				Graphics::coutV3(x, y += 4, "Money Successfully Transfered!!!", BLUE);
			}
			else
			{
				Graphics::coutV3(x, y += 4, "Money Over-flow!!!", RED);
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
			Graphics::coutV3(x, y, "Enter new password: ", YELLOW);

			Graphics::goToXY(x + 18,y);
			new_pass = nonBlockingCIN(true);
			LoggedUser.changePassword(LoggedUser.currentUser.username, new_pass);

			Graphics::coutV3(x, y += 4, "Password Changed.", BLUE);

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
			Graphics::coutV3(x, y, "Enter new pin: ", YELLOW);

			Graphics::goToXY(x + 15, y);
			new_pin = nonBlockingCIN(true);
			if (new_pin == "") return;

			LoggedUser.changePIN( LoggedUser.currentUser.username,atoi(new_pin.c_str()));

			Graphics::coutV3(x, y += 4, "PIN Changed!!!", BLUE);
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
			Graphics::coutV3(x, y, "Do you want to Log Out - Press Enter", YELLOW);

			dummy = nonBlockingCIN(true,true);
		
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
		try {
			setTitle("!!! UNLOCK ATM !!!");
			string new_pass;
			int x = 30;
			int y = 8;
			Graphics::coutV3(x, y, "Username: ", YELLOW);

			Graphics::goToXY(x + 10, y);
			username = nonBlockingCIN();

			LoggedUser.unlockATM(LoggedUser.currentUser.username, 0);

			Graphics::coutV3(x, y += 4, username + " atm unlocked.", BLUE);
		}
		catch (int e) {
			throw e;
		}
	}

	void Add_Money() {
		try {
			setTitle("!!! ADD MONEY !!!");
			int x = 30;
			int y = 8;

			Graphics::coutV3(x, y++, "Username: ", YELLOW);
			Graphics::coutV3(x, y++, "Amount: ", YELLOW);

			Graphics::goToXY(x + 10, y - 2); string username = nonBlockingCIN();
			Graphics::goToXY(x + 8, y - 1); double amount = atof(nonBlockingCIN().c_str());

			if (LoggedUser.addBalance(username, amount) == true) {
				Graphics::coutV3(x, y += 4, "Amount successfully added.", BLUE);
			}
			else {
				Graphics::coutV3(x, y += 4, "Failed to add money.", RED);
			}
		}
		catch (int e) {
			throw e;
		}
	}

	void Change_User_Password() {
		try{
			setTitle("!!! CHANGE USER PASSWORD !!!");
			int x = 30;
			int y = 8;

			Graphics::coutV3(x, y++, "Username: ", YELLOW);
			Graphics::coutV3(x, y++, "New Password: ", YELLOW);

			Graphics::goToXY(x + 10, y - 2); string username = nonBlockingCIN();
			Graphics::goToXY(x + 14, y - 1); string pass = nonBlockingCIN();

			if (LoggedUser.changePassword(username, pass) == true) {
				Graphics::coutV3(x, y += 4, "Password Changed", BLUE);
			}
			else {
				Graphics::coutV3(x, y += 4, "Failed to change password.", BLUE);
			}
		}
		catch (int e) {
			throw e;
		}
	}

	void Change_User_PIN() {
		try {
			setTitle("!!! CHANGE USER PIN !!!");
			int x = 30;
			int y = 8;

			Graphics::coutV3(x, y++, "Username: ", YELLOW);
			Graphics::coutV3(x, y++, "New PIN: ", YELLOW);


			Graphics::goToXY(x + 10, y - 2); string username = nonBlockingCIN();
			Graphics::goToXY(x + 9, y - 1); string PIN = nonBlockingCIN();

			if (LoggedUser.changePIN(username, atoi(PIN.c_str())) == true) {
				Graphics::coutV3(x, y += 4, "PIN Changed", BLUE);
			}
			else {
				Graphics::coutV3(x, y += 4, "Failed to change PIN.", RED);
			}
		}
		catch (int e) {
			throw e;
		}
	}

	void Delete_Account() {
		try {
			setTitle("!!! DELETE ACCOUNT !!!");
			int x = 30;
			int y = 8;
			Graphics::coutV3(x, y++, "Username: ", YELLOW);
			Graphics::coutV3(x, y++, "Are you sure (Y/N): ", YELLOW);

			Graphics::goToXY(x + 10, y - 2); string username = nonBlockingCIN();

			Graphics::goToXY(x + 20, y - 1); string confirm = nonBlockingCIN();


			if (confirm[0] == 'Y' || confirm[0] == 'y') {
				LoggedUser.deleteUser(username);
				Graphics::coutV3(x, y += 4, "User removed.", BLUE);
			}
			else {
				Graphics::coutV3(x, y += 4, "Fail to remove user.", RED);
			}
		}
		catch (int e) {
			throw e;
		}
	}

	void Unblock_ATM() {
		try {
			setTitle("!!! UNLOCK ATM !!!");
			int x = 30;
			int y = 8;
			Graphics::coutV3(x, y, "Username: ", YELLOW);

			Graphics::goToXY(x + 10, y); string username = nonBlockingCIN();

			if (LoggedUser.unlockATM(username, 0) == true) {
				Graphics::coutV3(x, y += 4, "User ATM unlocked.", BLUE);
			}
			else {
				Graphics::coutV3(x, y += 4, "User ATM unlocked.", RED);

			}
		}
		catch (int e) {
			throw e;
		}
	}

	void Add_User() {
		try {
			setTitle("!!! ADD USER !!!");
			userDetail newUser;

			int x = 30;
			int y = 8;

			Graphics::coutV3(x, y++, "Name: ", YELLOW);
			Graphics::coutV3(x, y++, "Username: ", YELLOW);
			Graphics::coutV3(x, y++, "Password: ", YELLOW);
			Graphics::coutV3(x, y++, "Role: ", YELLOW);

			Graphics::goToXY(x + 6, y - 4); newUser.name = nonBlockingCIN();
			Graphics::goToXY(x + 10, y - 3); newUser.username = nonBlockingCIN();
			Graphics::goToXY(x + 10, y - 2); newUser.password = nonBlockingCIN(true);
			Graphics::goToXY(x + 6, y - 1); newUser.role = atoi(nonBlockingCIN(true).c_str());

			if (newUser.role < 1 && newUser.role > 3) {
				newUser.role = 1;
			}

			newUser.pin = Bank::randomPIN();
			newUser.atmBlocked = 0;

			if (LoggedUser.addUser(newUser) == true)// if return false mean user already exist with that username
			{
				Graphics::coutV3(x, y + 4, "User Added", BLUE);
				Graphics::coutV3(x, y + 5, "User ATM PIN is " + newUser.pin, BLUE);
			}
			else {
				Graphics::coutV3(x, y + 4, "User Already Exist", RED);
			}
		}
		catch (int e) {
			throw e;
		}
	}

public:
	void run() {
		Graphics::cls();

		if (login()) {
			Graphics::cls();
			menu();
			//Information();
			//Transfer_Money();
		}
	}
};

#endif