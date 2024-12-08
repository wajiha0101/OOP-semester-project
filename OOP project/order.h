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


};
