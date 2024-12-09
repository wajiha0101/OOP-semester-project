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

};
