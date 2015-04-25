#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include "Graphics.cpp"

using namespace std;

bool logged = false;

string userInput (int type) {
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

void loginUI () {
	string username, password;
	int role;

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
	username = userInput(1);
	Graphics::goToXY(35, 11);
	password = userInput(2);
	Graphics::goToXY(31, 12);
	role = atoi(userInput(3).c_str());
	Graphics::goToXY(35, 15);
	
	//cout << username << " " << password << " " << role;
	logged = true;

}

void menu () {
	cout << "-------------------" << "\n\n" 
		 << " Hello, " << "Owais     |" << "\n" 
		 << "-------------------" << "\n\n" 
		 << " Information      -" << "\n" 
		 << "-------------------" << "\n\n" 
		 << " Transfer Money   |" <<  "\n"
		 << "-------------------" << "\n\n" 
		 << " Change Password  |" << "\n" 
		 << "-------------------" << "\n\n" 
		 << " Change PIN       |" << "\n" 
		 << "-------------------" << "\n\n" 
		 << " Logout           |" << "\n" 
		 << "-------------------";


}

int main() {
	loginUI ();
	if (true) {
		Graphics::cls();
		menu();
	}
	return 0;
}
