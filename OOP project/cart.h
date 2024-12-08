#pragma once
#include"items.h"

class Cart {
	vector<Items>cartitems;
	double totalprice;
public:
	Cart() {
		totalprice = 0;
	}
	void additem(Items item) {
		cartitems.push_back(item);
		totalprice += item.price;
	}
	void displaycart()const {
		cout << "Your Cart:\n";
		if (cartitems.empty()) {
			cout << "Your cart is empty\n";
			return;
		}
		for (int i = 0; i < cartitems.size(); i++) {
			cartitems[i].displayItems();
		}
		cout << "Your total amount: " << totalprice << endl;
	}

		double gettotalprice()const {
			return totalprice;
		}
	};