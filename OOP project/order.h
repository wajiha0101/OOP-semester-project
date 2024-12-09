#pragma once
#include"items.h"
#include"cart.h"
#include"user.h"
#include<iostream>
#include<vector>
using namespace std;

class Order {
	vector<Cart>orderitems;
	double totalprice;
	Cart c;
	user u;
	
public:
	Order() {
		totalprice = 0;
	}
	void order() {
		if (c.gettotalprice() == 0) {
			cout << "Your cart is empty\n";
			return;
		}
		saveorder("order.h");
		cout << "Order placed successfully!\n";
		displayOrderDetails();
	}
	void checkoutinfo() {
		cout << "Customers Details\n";
		u.displayuserinfo();
		c.displaycart();
		cout << "total price is: " << c.gettotalprice();
	}
	void displayOrderDetails() {
		cout << "Ordered Items:\n";
		for (const auto& item : orderitems) {
			item.displaycart();
		}
		cout << "Total price: " << totalprice << endl;
	}
	void saveorder(const string& orderpath) {
		ofstream orderfile(orderpath);
		if (!orderfile.is_open()) {
			cout << "File not found\n";
			return;
		}
		orderfile << "Customer Details:\n";     //userinfo saving
		orderfile << "Name: " << u.name << "\n";
		orderfile << "Email: " << u.email << "\n";
		orderfile << "Address: " << u.address << "\n";
		orderfile << "Phone: " << u.phone << "\n";
		//save cart items
		for (const auto& oderitem : c.getcartitems()) {
			orderfile << oderitem.id << oderitem.name<<oderitem.price<<"\n";
		}
		orderfile << "Total Price: $" << c.gettotalprice() << "\n";
		orderfile << "--------------------------\n";
		orderfile.close();
	}
	
	void displayAllOrders() {
		if (orderitems.empty()) {
			cout << "No orders found.\n";
			return;
		}

		cout << "Displaying all orders:\n";
		for (const auto& cart : orderitems) {
			cart.displaycart();
			cout << "Total Price: $" << cart.gettotalprice() << endl;
		}
	}

	void loadorder(const string& orderpath) {
		ifstream orderfile(orderpath);
		if (!orderfile.is_open()) {
			cout << "File not found\n";
			return;
		}
		string line;
		// for items
		while (getline(orderfile, line)) {
			string id, name, price;
			stringstream ss(line);
			ss >> id >> name >> price;
			ordrcart.additem(Item(id, name, price));
		}
		//for customer
		while (getline(orderfile, line)) {
			string name, email, address;
			int phone;
			getline(orderfile, name);
			getline(orderfile, email);
			getline(orderfile, address);
			orderfile >> phone;
			cin.ignore();
		}

		double total;
		file >> total;   // Read total from file
		totalprice = total;  // Assign total to the class variable to store it temporaily
		orderitems.push_back(orderCart);  // Save the cart in the list

	}
};


/*if (line.find("Total Price: $") != string::npos) {
				string totalprice = line.substr(14);
				ordrcart.settotalprice(stod(totalprice));
			}*/