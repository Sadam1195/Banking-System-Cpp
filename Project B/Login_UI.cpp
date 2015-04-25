#ifndef GRAPHICS_CPP
#define GRAPHICS_CPP
#include "Graphics.cpp"
#endif

#ifndef Bank_CPP
#define Bank_CPP
#include "Bank.cpp"
#endif

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>

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
		Information();
		//Transfer_Money();
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
		if (LoggedUser.currentUser.role == 1)
		{
			Graphics::goToXY(x, y);
			cout << "Status:";
			Graphics::goToXY(39, 11);
			Graphics::SetColor(Graphics::RED);
			cout << "User";
			Graphics::SetColor(Graphics::WHITE);

		}
		else if (LoggedUser.user.role == 2)
		{
			Graphics::goToXY(x, y);
			cout << "Status:";
			Graphics::goToXY(39, 12);
			Graphics::SetColor(Graphics::YELLOW);
			cout << "Accountant";
			Graphics::SetColor(Graphics::WHITE);
		}
		else if (LoggedUser.user.role == 3)
		{
			Graphics::goToXY(x, y);
			cout << "Status:";
			Graphics::goToXY(39, 13);
			Graphics::SetColor(Graphics::BLUE);
			cout << "Manager";
			Graphics::SetColor(Graphics::WHITE);
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
		cout << "Reciver Name: ";
		y++;
		Graphics::goToXY(x, y);
		cout << "Amount: ";
		
		while (true)
		{
			Graphics::goToXY(42, 8);
				cin >> Sender_Name;
			if (LoggedUser.usernameAlreadyExist(Sender_Name))
			{
				break;
			}
		}
		while (true)
		{
			Graphics::goToXY(42, 9);
			cin >> Reciver_Name;
			if (LoggedUser.usernameAlreadyExist(Reciver_Name))
			{
				break;
			}
		}

		float Sender_Bal = LoggedUser.getBalance(Sender_Name);
		
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

	Graphics::goToXY(38, 8);
	cin >> Sender_Name;

	}

	void Change_Password()
	{
		string new_pass;
		cout << "Enter new password:\n";
		cin >> new_pass;
		LoggedUser.changePassword(LoggedUser.currentUser.username,new_pass);

	}

	void Change_PIN()
	{
		int new_pin;
		cout << "Enter new pin:\n";
		cin >> new_pin;

		LoggedUser.changePIN( LoggedUser.currentUser.username,new_pin);

	}
	 
	void Log_Out()
	{
		
		cout << "Do you want to Log Out:\n";
		while (1)
		{
			if (_getch() == 13)
			{
				LoggedUser.logout();
				
				return;
			}

		}
		
	}

	void unlockATM()
	{
		cout << "Do you want to Log Out:\n";
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
		if (login()) {
			Graphics::cls();
			menu();
			Information();
			Transfer_Money();
		}
	}
};