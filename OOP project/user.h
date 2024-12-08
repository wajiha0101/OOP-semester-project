#pragma once
#include<iostream>
#include<string>
using namespace std;

class user {
public:
	string name, email, address,giftnote;
	int phone;
	void userinfo() {
		cout << "Enter your name: ";
		getline(cin, name);
		cout << "Enter your email: ";
		getline(cin, email);
		cout << "Enter your address: ";
		getline(cin, address);
		cout << "Enter your phone number: ";
		cin >> phone;
	}

	void displayuserinfo() {
		cout << "Name: " << name << endl;
		cout << "Email: " << email << endl;
		cout << "Address: " << address << endl;
		cout << "Phone: " << phone << endl;
		if (!giftnote.empty()){
			cout << "Gift Note: " << giftnote << endl;
	    }
	}
};