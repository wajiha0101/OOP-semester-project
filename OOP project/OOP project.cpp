//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//
//class Items {
//	string name;
//	int id, price;
//public:
//    void displayItems() {
//        ifstream file("items.txt");
//        int id, price;
//        string name;
//        cout << "Available Items:\n";
//        while (file >> id >> name >> price) {
//            cout << id << ". " << name << " - $" << price << endl;
//        }
//        file.close();
//    }
//
//};
//
//class cart:public Items {
//	string itemname[100];
//    int itemprize[100];
//    int itemcount;
//	int totalprize;
//public:
//
//};
//
//int main() {
//	Items item;
//	item.displayItems();
//	return 0;
//}


#include <iostream>
#include "items.h"
#include "user.h"
#include "cart.h"
#include "order.h"
using namespace std;

int main() {
    vector<Items> availableItems = {
        Items("Phone", 101, 500),
        Items("Laptop", 102, 1000),
        Items("Headphones", 103, 150),
        Items("Tablet", 104, 300),
        Items("Smartwatch", 105, 200)
    };

    Cart cart;
    user user;
    Order order;

    int choice;
    while (true) {
        cout << "\n====== Online Shopping System ======\n";
        cout << "1. View Items\n";
        cout << "2. Search Items by Budget\n";
        cout << "3. Add Items to Cart\n";
        cout << "4. View Cart\n";
        cout << "5. Checkout\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nAvailable Items:\n";
            for (const auto& item : availableItems) {
                item.displayItems();
            }
            break;

        case 2:
            Items::serach_by_budget(availableItems);
            break;

        case 3: {
            int itemID;
			char ch;
            cout << "\nEnter Item ID to add to cart (0 to finish): ";
            while (true) {
                cin >> itemID;
                if (itemID == 0) break;

                bool found = false;
                for (const auto& item : availableItems) {
                        if (item.id == itemID) {
                            cart.additem(item);
                            cout << item.name << " added to cart.\n";
                            found = true;
                            break;
                        }
                }
                if (!found) {
                    cout << "Invalid Item ID. Try again: ";   
                }
                cout << "Do you want to add more items to cart? (y/n): ";
                cin >> ch;
                if (ch != 'y' && ch != 'Y') break;
            }
            break;
        }

        case 4:
            cart.displaycart();
            break;

        case 5:
            if (cart.gettotalprice() == 0) {
                cout << "Your cart is empty. Add items to checkout.\n";
            }
            else {
                cout << "\nProceeding to Checkout...\n";
                cin.ignore(); // Clear input buffer
                user.userinfo();
                order.order();
            }
            break;

        case 6:
            cout << "Thank you for using the system. Goodbye!\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
