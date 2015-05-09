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
		Graphics::goToXY(30,1); cout << title;
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
			cout << "------------------------------------";
			Graphics::goToXY(20, 7);
			cout << "          *** LOGIN ***             ";


			Graphics::goToXY(25, 10);
			cout << "USERNAME: ";
			Graphics::goToXY(25, 11);
			cout << "PASSWORD: ";

			Graphics::goToXY(25, 13);
			Graphics::SetColor(YELLOW);
			cout << "OPTIONS";
			Graphics::SetColor(GRAY);
			Graphics::goToXY(25, 14);
			cout << "1) USER";
			Graphics::goToXY(25, 15);
			cout << "2) ACCOUNTANT";
			Graphics::goToXY(25, 16);
			cout << "3) MANAGER";
			Graphics::SetColor(WHITE);

			Graphics::goToXY(25, 17);
			cout << "ROLE:";


			Graphics::goToXY(20, 19);
			cout << "------------------------------------";

			Graphics::goToXY(35, 10);
			cout << "                  ";
			Graphics::goToXY(35, 11);
			cout << "                  ";
			Graphics::goToXY(35, 12);
			cout << "                  ";

			Graphics::goToXY(35, 10);
			username = userInput(1);

			Graphics::goToXY(35, 11);
			password = userInput(2);

			Graphics::goToXY(31, 17);
			role = atoi(userInput(3).c_str());

			Graphics::goToXY(35, 15);

			//cout << username << " " << password << " " << role;
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
		Graphics::goToXY(45, 30); cout << "Copyright (C) 2015 | Zerk & Owais";
		//COLS = 80 LINES = 25
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
			cout << "-------------------" << "\n\n"
				<< " Hello,           |" << "\n"
				<< "-------------------" << "\n\n"
				<< " Information      |" << "\n"
				<< "-------------------" << "\n\n"
				<< " Transfer Money   |" << "\n"
				<< "-------------------" << "\n\n"
				<< " Change Password  |" << "\n"
				<< "-------------------" << "\n\n"
				<< " Change PIN       |" << "\n"
				<< "-------------------" << "\n\n"
				<< " Logout           |" << "\n"
				<< "-------------------";
		}
		if (LoggedUser.currentUser.role == 2) { //ACCOUNTANT
			optionsCount = 4;
			cout << "-------------------" << "\n\n"
				<< " Hello,           |" << "\n"
				<< "-------------------" << "\n\n"
				<< " Information      |" << "\n"
				<< "-------------------" << "\n\n"
				<< " Add Money        |" << "\n"
				<< "-------------------" << "\n\n"
				<< " Add User         |" << "\n"
				<< "-------------------" << "\n\n"
				<< " Change Password  |" << "\n"
				<< "-------------------" << "\n\n"
				<< " Logout           |" << "\n"
				<< "-------------------";
		}
		if (LoggedUser.currentUser.role == 3) { //MANAGER
			optionsCount = 8;
			cout << "-------------------" << "\n\n"
				<< " Hello,           |" << "\n"
				<< "-------------------" << "\n\n"
				<< " Information      |" << "\n"
				<< "-------------------" << "\n\n"
				<< " Add Money        |" << "\n"
				<< "-------------------" << "\n\n"
				<< " Add User         |" << "\n"
				<< "-------------------" << "\n\n"
				<< " Remove Account   |" << "\n"
				<< "-------------------" << "\n\n"
				<< " Unblock ATM      |" << "\n"
				<< "-------------------" << "\n\n"
				<< " Change User Pass |" << "\n"
				<< "-------------------" << "\n\n"
				<< " Change User PIN  |" << "\n"
				<< "-------------------" << "\n\n"
				<< " Change Password  |" << "\n"
				<< "-------------------" << "\n\n"
				<< " Logout           |" << "\n"
				<< "-------------------";
		}


		Graphics::goToXY(8,2);
		cout << LoggedUser.currentUser.username;

		int count = 0;

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
		Graphics::goToXY(x, y);
		cout << "Name: ";
		Graphics::goToXY(36, 8);
		cout << LoggedUser.currentUser.name;
		y++;
		Graphics::goToXY(x, y);
		cout << "Creation Date: ";
		Graphics::goToXY(45, 9);
		cout << LoggedUser.creationData();
		y++;
;
		
		if (LoggedUser.currentUser.role == 1)
		{
			Graphics::goToXY(x, y);
			cout << "Balance: ";
			Graphics::goToXY(40, 10);
			cout << LoggedUser.getBalance(username);
			y++;

			Graphics::goToXY(x, y);	cout << "Status: ";

			Graphics::goToXY(Graphics::whereX() , 11);
			Graphics::coutColored(PINK, "User");

		}
		else if (LoggedUser.user.role == 2)
		{
			Graphics::goToXY(x, y);	cout << "Status: ";
			Graphics::goToXY(Graphics::whereX(), 10);
			Graphics::coutColored(YELLOW, "Accountant");
		}
		else if (LoggedUser.user.role == 3)
		{
			Graphics::goToXY(x, y);	cout << "Status: ";
			Graphics::goToXY(Graphics::whereX(), 10);
			Graphics::coutColored(DARKBLUE, "Manager");
			
		}
		_getch();
	}

	void Transfer_Money()
	{
		try {
			setTitle("!!! TRANSFER MONEY !!!");
			int Amount_Sended = -1;
			string Reciver_Name;
			string Sender_Name;
			Bank LoggedUser;
			int x = 30;
			int y = 8;
			Graphics::goToXY(x, y);
			cout << "Sender Name: ";
			y++;
			Graphics::goToXY(x, y);
			cout << "Reciever Name: ";
			y++;
			Graphics::goToXY(x, y);
			cout << "Amount: ";

		
			while (true)
			{
				Graphics::goToXY(43, 8);

				Sender_Name = nonBlockingCIN();
				if (Sender_Name == "") return;
				if (LoggedUser.usernameAlreadyExist(Sender_Name))
				{
					break;
				}
				else {
					Graphics::goToXY(43, 8);
					cout << "         ";
				}
			}
			while (true)
			{
				Graphics::goToXY(45, 9);
				Reciver_Name = nonBlockingCIN();
				if (Reciver_Name == "") return;

				if (LoggedUser.usernameAlreadyExist(Reciver_Name))
				{
					break;
				}
				else {
					Graphics::goToXY(44, 9);
					cout << "         ";
				}
			}

			string dummy;
			Graphics::goToXY(38, 10);
			dummy = nonBlockingCIN();
			if (dummy == "") return;
			Amount_Sended = atoi(dummy.c_str());

			double Sender_Bal = LoggedUser.getBalance(Sender_Name);

			Graphics::goToXY(x, y += 4);
			if (Amount_Sended <= Sender_Bal)
			{
				LoggedUser.addBalance(Sender_Name, -1 * Amount_Sended);
				LoggedUser.addBalance(Reciver_Name, Amount_Sended);
				cout << "Money Successfully Transfered!!!!!" << endl;
			}
			else
			{
				cout << "Money Over-flow";
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
			Graphics::goToXY(x, y);		
			cout << "Enter new password: ";
			new_pass = nonBlockingCIN(true);
			if (new_pass == "") return;
			LoggedUser.changePassword(LoggedUser.currentUser.username, new_pass);

			Graphics::goToXY(x, y += 4);
			cout << "Password Changed!!!";
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
			Graphics::goToXY(x, y);
			cout << "Enter new pin: ";
			new_pin = nonBlockingCIN(true);
			if (new_pin == "") return;

			LoggedUser.changePIN( LoggedUser.currentUser.username,atoi(new_pin.c_str()));
			Graphics::goToXY(x, y += 4);
			cout << "PIN Changed!!!";
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
			Graphics::goToXY(x, y);
			cout << "Do you want to Log Out - Press Enter ";
			dummy = nonBlockingCIN(true,true);
			cout << "I am out";
		
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
			int x = 30;
			int y = 8;
			Graphics::goToXY(x, y);
			cout << "Do you want to Log Out: ";
			while (true)
			{
				if (_getch() == 13)
				{
					LoggedUser.logout();

					return;
				}

			}
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
			Graphics::goToXY(x, y);	  cout << "Username: ";
			Graphics::goToXY(x, ++y); cout << "Amount: ";
			Graphics::goToXY(x + 10, y - 2); string username = nonBlockingCIN();
			Graphics::goToXY(x + 8, y - 1); double amount = atof(nonBlockingCIN().c_str());
			if (LoggedUser.addBalance(username, amount) == true) {
				Graphics::goToXY(x, y += 4); cout << "Amount successfully added.";
			}
			else {
				Graphics::goToXY(x, y += 4); cout << "Failed to add money.";
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
			Graphics::goToXY(x, y);	  cout << "Username: ";
			Graphics::goToXY(x, ++y); cout << "Password: ";
			Graphics::goToXY(x + 10, y - 2); string username = nonBlockingCIN();
			Graphics::goToXY(x + 10, y - 1); string pass = nonBlockingCIN();
			if (LoggedUser.changePassword(username, pass) == true) {
				Graphics::goToXY(x, y += 4); cout << "Password Changed";
			}
			else {
				Graphics::goToXY(x, y += 4); cout << "Failed to change password.";
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
			Graphics::goToXY(x, y);	  cout << "Username: ";
			Graphics::goToXY(x, ++y); cout << "PIN: ";
			Graphics::goToXY(x + 10, y - 1); string username = nonBlockingCIN();
			Graphics::goToXY(x + 6, y); string PIN = nonBlockingCIN();
			if (LoggedUser.changePIN(username, atoi(PIN.c_str())) == true) {
				Graphics::goToXY(x, y += 4); cout << "PIN Changed";
			}
			else {
				Graphics::goToXY(x, y += 4); cout << "Failed to change PIN.";
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
			Graphics::goToXY(x, y);	  cout << "Username: ";
			Graphics::goToXY(x, ++y);	  cout << "Are you sure (Y/N): ";
			Graphics::goToXY(x + 10, y); string username = nonBlockingCIN();
			Graphics::goToXY(x + 20, y - 1); string confirm = nonBlockingCIN();


			if (confirm[0] == 'Y' || confirm[0] == 'y') {
				LoggedUser.deleteUser(username);
				Graphics::goToXY(x, y += 4); cout << "User Removed.";
			}
			else {
				Graphics::goToXY(x, y += 4); cout << "Fail to remove user.";
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
			Graphics::goToXY(x, y);	  cout << "Username: ";
			Graphics::goToXY(x + 10, y); string username = nonBlockingCIN();


			if (LoggedUser.unlockATM(username, 0) == true) {
				Graphics::goToXY(x, y += 4); cout << "User ATM unlocked.";
			}
			else {
				Graphics::goToXY(x, y += 4); cout << "Fail to unlock ATM.";
			}
		}
		catch (int e) {
			throw e;
		}
	}

	void Add_User() {
		try {
			setTitle("!!!ADD USER !!!");
			userDetail newUser;

			int x = 30;
			int y = 8;
			Graphics::goToXY(x, y);	  cout << "Name: ";
			Graphics::goToXY(x, ++y); cout << "Username: ";
			Graphics::goToXY(x, ++y); cout << "Password: ";
			Graphics::goToXY(x, ++y); cout << "Role: ";
			Graphics::goToXY(x + 7, y - 3); newUser.name = nonBlockingCIN();
			Graphics::goToXY(x + 11, y - 2); newUser.username = nonBlockingCIN();
			Graphics::goToXY(x + 11, y - 1); newUser.password = nonBlockingCIN(true);
			Graphics::goToXY(x + 7, y); newUser.role = atoi(nonBlockingCIN(true).c_str());

			if (newUser.role < 1 && newUser.role > 3) {
				newUser.role = 1;
			}

			newUser.pin = Bank::randomPIN();
			newUser.atmBlocked = 0;

			if (LoggedUser.addUser(newUser) == true)// if return false mean user already exist with that username
			{
				Graphics::goToXY(x, y + 4); cout << "User Added";
				Graphics::goToXY(x, y + 4); cout << "User ATM PIN is " << newUser.pin;
			}
			else {
				Graphics::goToXY(x, y + 4); cout << "User already exists.";
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