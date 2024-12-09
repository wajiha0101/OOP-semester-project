#pragma once
#include<iostream>
#include<vector>
#include <fstream>
using namespace std;
class Items {
public:
	string name;
	int id, price;
	Items(string name, int id, int price) {
		this->name = name;
		this->id = id;
		this->price = price;
	}
	void displayItems()const {
		cout << id << ". " << name << " - $" << price << endl;
	}
	 void saveinfile(ofstream& itemsfile) const {
		itemsfile << id << " " << name << " " << price << endl;
	}
	static Items itemsfromfile(ifstream& itemsfile) {
		int id, price;
		string name;
		itemsfile >> id >> name >> price;
		return Items(name, id, price);
	}

	vector<Items> loadfromfile(const string& itemspath) {
		vector<Items> items;
		ifstream itemsfile(itemspath);
		if (!itemsfile.is_open()) {
			cout << "File not found\n";
			return items;
		}
		while (!itemsfile.eof()) {
			items.push_back(itemsfromfile(itemsfile));
		}
		itemsfile.close();
		return items; 
	}
	void saveitemsinfile(const vector<Items>& ite,const string& itempath) {
		ofstream itemsfile(itempath);
		if (!itemsfile.is_open()) {
			cout << "File not found\n";
			return;
		}
		for (const auto& item : ite) {
			item.saveinfile(itemsfile);
		}
		itemsfile.close();
		cout << "Saved successfully\n";
	}



	//BUGET SEARCH FUNCTIONS
	static void serach_by_budget(const vector<Items>&it) {
		int min, max;
		cout << "Enter the minimum budget: " << endl;
		cin >> min;
		cout << "Enter the maximum budget: " << endl;
		cin >> max;
		bool found =false;
		for (const auto& item : it) {
			if (item.price >= min && item.price <= max) {
				item.displayItems();
				found = true;
			}
		}
		if (!found) {
			cout << "No items found in this budget\n";
		}

	}
};

//class cart :public Items {
//public:
//	cart(string n,int Id,int pr):Items(n,Id,pr) {
//		totalprize = 0;
//	}
//	vector<Items> item;
//	double totalprize;
//
//	void additem(Items item) {
//		this->item.push_back(item);
//		totalprize += item.price;
//	}
//	void displaycart() {
//		cout << "Your Cart:\n";
//		for (int i = 0; i < item.size(); i++) {
//			item[i].displayItems();
//		}
//		cout << "Your total amount: " << totalprize << endl;
//	}
//};

