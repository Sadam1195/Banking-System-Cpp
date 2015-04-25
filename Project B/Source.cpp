#include <iostream>
#include <cstdlib>    // system()
#include <stdio.h>    
#include <string>     // to_string()

#include "Login_UI.cpp"
#include "ATM_UI.cpp"

using namespace std;

int main()
{
	//atmUI atm;
	//atm.run();

	loginUI online;
	online.run();


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