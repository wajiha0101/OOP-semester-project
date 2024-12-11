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
		// Load cart from file
		void loadCartFromFile(const string& cartPath) {
			ifstream file(cartPath);
			if (!file.is_open()) {
				cout << "Error: Cannot open file for loading.\n";
				return;
			}

			cartitems.clear();  // Clear old data
			totalprice = 0;

			file >> totalprice;  // Load total price

			while (!file.eof()) {
				int id, price;
				string name;
				file >> id >> name >> price;

				if (file.fail()) break;  // Stop if file is incomplete or corrupt

				cartitems.push_back(Items(name, id, price));
			}

			file.close();
			cout << "Cart loaded successfully.\n";
		}
	};