#include <iostream>
#include <fstream>
#include <cstdlib> // system()
#include <string> // to_string()
#include <ctime> // time()
#include <stdio.h>
#include <windows.h>

using namespace std;

struct userDetail {
	string name;
	string username;
	string password;
	int pin;
	short int role;
	bool atmBlocked;
};

class bank
{
public:
	string name;
	string username;
	string password;
	int pin;
	short int role;
	bool atmBlocked;
	char infoFile[10];
	char dataDir[10];
	bool loggedIn = false;
	fstream infoFileWriteStream;

	HANDLE hCon;
	userDetail currentUser;
	enum Color { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE };

	bank()
	{
		char infoFile[] = "info.txt";
		char dataDir[] = "data/";
		bool loggedIn = false;
		infoFileWriteStream.open("infoFile.txt");


	}

	/* http://www.infernodevelopment.com/set-console-text-color */
	void SetColor(Color c) {
		if (hCon == NULL) {
			hCon = GetStdHandle(STD_OUTPUT_HANDLE);
		}
		SetConsoleTextAttribute(hCon, c);

		//SetColor(YELLOW);
		//	cout << "X\b";
	}

	void goToXY(short int x, short int y) {
		COORD coord = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	int whereX() {
		CONSOLE_SCREEN_BUFFER_INFO consoleinfo;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleinfo);
		return consoleinfo.dwCursorPosition.X;
	}

	int whereY() {
		CONSOLE_SCREEN_BUFFER_INFO consoleinfo;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleinfo);
		return consoleinfo.dwCursorPosition.Y;
	}

	bank getRoleValue(string username) {
		fstream infoFileReadStream("infoFile.txt");
		bank user;
		int position = 0;
		while (infoFileReadStream
			>> user.username
			>> user.password
			>> user.pin
			>> user.role
			>> user.atmBlocked
			)
		{
			if (user.username == username) {
				return user;
			}
			position = infoFileReadStream.tellg();
		}
		return user;
	}

	bool putCurrentUserValue(string username, bank data) {

		fstream infoFileReadStream("infoFile.txt");
		userDetail user;
		int position = 0;
		while (infoFileReadStream
			>> user.username
			>> user.password
			>> user.pin
			>> user.role
			>> user.atmBlocked
			)
		{
			if (user.username == username) {
				infoFileReadStream.seekp(position);
				infoFileReadStream << data.username << " "
					<< data.password << " "
					<< data.pin << " "
					<< data.role << " "
					<< data.atmBlocked
					<< endl;
				break;
			}
			position = infoFileReadStream.tellg();
		}
		return 0;
	}

	void changePIN(string username, int pin){
		bank data = getRoleValue(username);
		data.pin = pin;
		putCurrentUserValue(username, data);
	}

	void changePassword(string username, string password){
		bank data = getRoleValue(username);
		data.password = password;
		putCurrentUserValue(username, data);
	}

	void unlockATM(string username, bool unlock){
		bank data = getRoleValue(username);
		data.atmBlocked = unlock;
		putCurrentUserValue(username, data);
	}

	void deleteUser(string username){
		bank data = getRoleValue(username);
		data.name = "DEL_N";
		data.username = "DEL_UN";
		data.password = "DEL_P";
		data.pin = -1;
		data.role = -1;
		data.atmBlocked = -1;
		putCurrentUserValue(username, data);

		string fileLoc = dataDir + username;
		remove(fileLoc.c_str());
	}

	/*////////////////////////////////////////////*/

	void init()
	{
		srand(time(NULL));
	}

	int randomPIN()
	{
		int min = 1111;
		int max = 9999;
		int randNo = ((rand() % (max - min)) + min);
		srand(randNo + (unsigned int)time(NULL));
		return randNo;
	}

	string repeatCh(char repeatedCh, int limit) {
		string data;
		for (int i = 0; i < limit; i++) {
			data += repeatedCh;
		}
		return data;
	}

	void modifyKeyValue(string username, string key, string value) {
		string userFileLoc = string(dataDir) + username + ".txt";
		fstream userFile(userFileLoc.c_str());
		string tag, info;
		int position = 0;
		while (userFile >> tag >> info) {
			//cout << tag << " " << info << " " << value << endl;

			if (tag == key) {
				cout << tag << " " << info << " " << value << endl;
				userFile.seekp(position);
				userFile << repeatCh(' ', info.size());
				userFile.seekp(position);
				userFile << endl << key << " " << value << endl;
				break;
			}
			position = userFile.tellg();

		}
		userFile.close();
	}

	string getValueByKey(string username, string key){
		string userFileLoc = string(dataDir) + username + ".txt";
		fstream userFile(userFileLoc.c_str());
		string tag, info;
		while (userFile >> tag >> info) {
			if (tag == key) {
				return info.c_str();
			}
		}
		userFile.close();
		return "NULL";
	}

	float getBalance(string username) {
		string key = "BAL";
		string value = getValueByKey(username, key);
		return atof(value.c_str());
	}

	bool addBalance(string username, int amount) {
		string balance = to_string(getBalance(username) + amount);
		modifyKeyValue(username, "BAL", balance);
		return true;
	}

	bool usernameAlreadyExist(string username) {
		string line;
		bool flag = false;
		bank user;
		ifstream infoFileReadStream("infoFile.exe");
		while (infoFileReadStream
			>> user.username
			>> user.password
			>> user.pin
			>> user.role
			)
		{
			if (user.username == username) {
				flag = true;
				break;
			}
		}
		infoFileReadStream.close();
		return flag;
	}

	string replaceWith(string str, char pin, char replace) {
		string newStr;
		int size = str.size();
		for (int i = 0; i < size; i++){
			if (str.c_str()[i] == pin) {
				newStr += replace;
			}
			else {
				newStr += str.c_str()[i];
			}
		}
		return newStr;
	}

	bool login(string username, string password, short int role) {
		string line;
		bool flag = false;
		bank user;
		ifstream infoFileReadStream("infoFile.txt");
		while (infoFileReadStream
			>> user.username
			>> user.password
			>> user.pin
			>> user.role
			>> user.atmBlocked
			)
		{
			if (user.username == username) {
				flag = true;
				currentUser = user; // Login user
				currentUser.name = replaceWith(getValueByKey(username, "NAME"), '_', ' ');
				break;
			}
		}
		infoFileReadStream.close();
		return flag;
	}

	int addUser(bank user) {
		// Checking whether person with same username exist or not
		// return false and cancel all operation
		if (usernameAlreadyExist(user.username))
		{
			return false;
		}

		// Adding data to file
		infoFileWriteStream << user.username << " "
			<< user.password << " "
			<< user.pin << " "
			<< user.role << " "
			<< user.atmBlocked
			<< endl;

		// Create file for user
		string userFileLoc = string(dataDir) + user.username + ".txt";
		ofstream userFile(userFileLoc.c_str());

		user.name = replaceWith(user.name, ' ', '_');

		time_t rawtime;
		time(&rawtime);
		string CDtime = replaceWith(ctime(&rawtime), ' ', '_');

		userFile << "NAME " << user.name << endl
			<< "CD " << CDtime << endl
			<< "BAL " << 0 << endl;
		userFile.close();

		return true;
	}

	bool isLogged() {
		if (currentUser.username.size() > 0)
			return true;
		else
			return false;

	}

	bool logout() {
		currentUser.name = "";
		currentUser.username = "";
		currentUser.password = "";
		currentUser.pin = -1;
		currentUser.role = -1;
		currentUser.atmBlocked = -1;
		return true;
	}

	string creationData() {
		string key = "CD";
		string value = getValueByKey(currentUser.username, key);
		return replaceWith(value, '_', ' ');
	}
	~bank()
	{
		infoFileWriteStream.close();

	}

};

int main()
{


	// Registration
	bank user, currentUser;
	user.init();
	user.name = "Syed Owais Ali Chishti";
	user.username = "owais";
	user.password = "pass";
	user.pin = user.randomPIN();
	user.role = 1;
	user.atmBlocked = 0;
	//if(addUser(user) == true)// if return false mean user already exist with that username
	//{
	//	cout << "User Added";
	//}
	//else {
	//	cout << "Unable to add user.";
	//}
	// Login    
	user.login("owais", "pass", 1);
	//logout();
	cout << user.isLogged();
	//cout << currentUser.name;

	cout << user.creationData();

	//string username = "owais";
	//addBalance(username, -500);
	//cout << getBalance(username);
	//deleteUser(username);

	system("pause");
	return 0;
}