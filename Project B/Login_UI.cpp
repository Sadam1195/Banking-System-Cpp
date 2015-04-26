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
			Graphics::goToXY(25, 12);
			cout << "ROLE:";

			Graphics::goToXY(20, 16);
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

			Graphics::goToXY(33, 12);
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
	}

	void getFunction(int funcID) {
		
		clearShowScreen();
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

	string nonBlockingCIN(bool show = true) {
		string text;
		char ch;
		Graphics::goToXY(Graphics::whereX(),Graphics::whereY());
		while (ch = _getch())
		{
			if (ch == 80 || ch == 72)
			{
				return "";
			}
			else if (ch == 13) {
				return text;
			}
			else {
				if (ch != -32) {
					if (show) cout << (char)ch;
					else cout << "*";
					text.push_back(ch);
				}
			}
		}
	}

	void menu() {
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
		
		Graphics::goToXY(7,2);
		cout << LoggedUser.currentUser.username;

		int count = 0;

		int y = 5;
		Graphics::goToXY(18, y);

		Graphics::coutColored(GREEN,"X\b");
		getFunction(count);
		
		char ch;
		ch = getch();
		while (true) {
			if (ch == 80 && count < 4) { // DOWN
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
		_getch();
	}

	void Information()
	{
		userDetail user;
		int x = 30;
		int y = 8;
		Graphics::goToXY(x, y);
		cout << "Name: ";
		Graphics::goToXY(35, 8);
		cout << LoggedUser.currentUser.name;
		y++;
		Graphics::goToXY(x, y);
		cout << "Creation Date: ";
		Graphics::goToXY(45, 9);
		cout << LoggedUser.creationData();
		y++;
		Graphics::goToXY(x, y);
		cout << "Balance: ";
		Graphics::goToXY(40, 10);
		cout << LoggedUser.getBalance(username) ;

		y++;
		Graphics::goToXY(x, y);
		cout << "Status: ";
		if (LoggedUser.currentUser.role == 1)
		{
			Graphics::goToXY(Graphics::whereX() , 11);
			Graphics::coutColored(PINK, "User");

		}
		else if (LoggedUser.user.role == 2)
		{
			Graphics::goToXY(Graphics::whereX(), 12);
			Graphics::coutColored(YELLOW, "Accountant");
		}
		else if (LoggedUser.user.role == 3)
		{

			Graphics::goToXY(Graphics::whereX(), 13);
			Graphics::coutColored(DARKBLUE, "Manager");
			
		}
		_getch();
	}

	void Transfer_Money()
	{
		int Amount_Sended=-1;
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

		float Sender_Bal = LoggedUser.getBalance(Sender_Name);
		
		Graphics::goToXY(x, y += 4);
		if (Amount_Sended <= Sender_Bal)
		{
			LoggedUser.addBalance(Sender_Name, -1 * Amount_Sended);
			LoggedUser.addBalance(Reciver_Name,Amount_Sended);
			cout << "Money Successfully Transfered!!!!!" << endl;
		}
		else
		{
			 cout << "Money Over-flow";
 		}
	}

	void Change_Password()
	{
		string new_pass;
		int x = 30;
		int y = 8;
		Graphics::goToXY(x, y);

		cout << "Enter new password: ";
		new_pass = nonBlockingCIN(true);
		if (new_pass == "") return;
		LoggedUser.changePassword(LoggedUser.currentUser.username,new_pass);

		Graphics::goToXY(x, y += 4);
		cout << "Password Changed!!!";
	}

	void Change_PIN()
	{
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
	 
	void Log_Out()
	{
		string dummy;
		int x = 30;
		int y = 8;
		Graphics::goToXY(x, y);
		cout << "Do you want to Log Out: ";
		dummy = nonBlockingCIN(false);
		if (dummy == "") return;

		if ((int)dummy[dummy.size() - 1] == 13)
		{
			LoggedUser.logout();
			return;
		}
		
	}

	void unlockATM()
	{
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

public:
	void run() {
		Graphics::cls();

		if (login()) {
			Graphics::cls();
			menu();
			Information();
			Transfer_Money();
		}
	}
};