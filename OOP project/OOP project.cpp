
#include<iostream>
#include <iostream>
#include "items.h"
#include "user.h"
#include "cart.h"
#include "order.h"
using namespace std;

void displaymenu() {
    cout << "\n==== Online Shopping System ====" << endl;
    cout << "1. Add Item to Cart" << endl;
    cout << "2. Display Cart" << endl;
    cout << "3. Place Order" << endl;
    cout << "4. Load Cart from File" << endl;
    cout << "5. Save Cart to File" << endl;
    cout << "6. Load Orders from File" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Cart cart;
    user user;
    Order order;

    cout << "Enter Your Name: ";
    getline(cin, user.name);
    cout << "Enter Your Email: ";
    getline(cin, user.email);
    cout << "Enter Your Address: ";
    getline(cin, user.address);
    cout << "Enter Your Phone Number: ";
    cin >> user.phone;
    cin.ignore(); 

    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            int id, price;
            string name;
            cout << "Enter Item ID: ";
            cin >> id;
            cout << "Enter Item Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Item Price: ";
            cin >> price;
            cart.additem(Items(name, id, price));
            cout << "Item added to cart.\n";
            break;

        case 2:
            cart.displaycart();
            break;

        case 3: {
            if (cart.gettotalprice() > 0) {
                order.placeOrder(currentUser, cart);
                cart = Cart(); // Reset cart after order
            }
            else {
                cout << "Cart is empty. Cannot place order.\n";
            }
            break;
        }

        case 4:
            cart.loadCartFromFile("cart.txt");
            break;

        case 5:
            cart.saveCartToFile("cart.txt");
            break;

        case 6:
            order.loadOrderFromFile("orders.txt");
            break;
		case 7:
            cout << "Thank you for using the system!\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
    return 0;
}
