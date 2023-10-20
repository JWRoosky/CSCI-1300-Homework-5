#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void displayMenu(){
    cout << "Please input 1-4 followed by enter to navigate the menu:" << endl;
    cout << "1) Add Product" << endl;
    cout << "2) Remove Product" << endl;
    cout << "3) Checkout " << endl;
    cout << "4) Exit" << endl;
    return;
}

void displayProducts(){
    cout << "Add Product:" << endl;
    cout << "A) Cheetos" << endl;
    cout << "B) Oreos" << endl;
    cout << "C) Coffee" << endl;
    cout << "D) Slurpee" << endl;
    return;
}

double calculatePriceWithString(string product, double budget){
    double tax = 0.09;
    if (product == "Cheetos"){
        return 2.99 + (2.99 * tax);
    }
    else if (product == "Oreos"){
        return 3.39 + (3.39 * tax);
    }
    else if (product == "Coffee"){
        return 3.79 + (3.79 * tax);
    }
    else if (product == "Slurpee"){
        return 4.29 + (4.29 * tax);
    }
    else{
        return 0;
    }
}

double calculatePriceWithChar(char product, double budget){
    double tax = 0.09;
    if (product == 'A'){
        return 2.99 + (2.99 * tax);
    }
    else if (product == 'B'){
        return 3.39 + (3.39 * tax);
    }
    else if (product == 'C'){
        return 3.79 + (3.79 * tax);
    }
    else if (product == 'D'){
        return 4.29 + (4.29 * tax);
    }
    else{
        return 0;
    }
}

vector<string> addProduct(char product, vector<string> cart){
    if (product == 'A'){
        cart.push_back("Cheetos");
        cout << "Cheetos added to cart." << endl;
    }
    else if (product == 'B'){
        cart.push_back("Oreos");
        cout << "Oreos added to cart." << endl;
    }
    else if (product == 'C'){
        cart.push_back("Coffee");
        cout << "Coffee added to cart." << endl;
    }
    else if (product == 'D'){
        cart.push_back("Slurpee");
        cout << "Slurpee added to cart." << endl;
    }
    else{
        cout << "Invalid input." << endl;
    }
    
    return cart;
}

vector<string> removeProduct(string product, vector<string> cart){
    bool flag = true;
    vector<string> new_cart;
    if (cart.size() == 0){
        cout << "Cart is empty." << endl;
        return cart;
    }
    else{
        for (int i = 0; i < cart.size(); i++){
            if (cart[i] == product && (flag)){
                flag = false;
                cout << cart[i] << " removed from cart." << endl;
            }
            else{
                new_cart.push_back(cart[i]);
            }
        }
        if (new_cart.size() == cart.size()){
            cout << "Product Name not found." << endl;
            return cart;
        }
        return new_cart;
    }
}

void checkout(vector<string> cart){
    double total = 0;
    if (cart.size() == 0){
        cout << "Cart is empty." << endl;
    }
    else{
        cout << "Your cart has the following products: " << endl;
        for (int i = 0; i < cart.size(); i++){
            cout << cart[i] << endl;
            total += calculatePriceWithString(cart[i], 0); 
        }
        cout << "Total amount: $" << fixed << setprecision(3) << total << endl;
        cout << "Thank you! Please visit again." << endl;
    }
}

int main(){
    cout << "Welcome to Kroga Gas Station!" << endl;
    vector<string> cart;
    double budget = 0;

    cout << "Enter your budget:" << endl;
    cin >> budget;
    if(cin.fail() || budget < 0.1){
        cout << "Invalid input. Balance must be a non-negative value. " << endl;
        return 1;
    }

    bool program_running = true;

    while (program_running){
        int menu_choice;
        displayMenu();
        cin >> menu_choice;

        if (menu_choice == 1){
            if (budget < calculatePriceWithString("Slurpee", budget)){
                cout << "Your budget is insufficient to add more products." << endl;
            }
            else{
                displayProducts();
                char choice;
                cin >> choice;
                cart = addProduct(choice, cart);
                budget = budget - calculatePriceWithChar(choice, budget);
            }
        }

        else if (menu_choice == 2){
            cout << "Enter the product name to be removed from the cart: " << endl;
            string product;
            cin >> product;
            cart = removeProduct(product, cart);
            budget = budget + calculatePriceWithString(product, budget);
        }

        else if (menu_choice == 3){
            checkout(cart);
            if (cart.size() != 0){
                program_running = false;
            }
        }
        else if (menu_choice == 4){
            cout << "Thank you! Please visit again." << endl;
            program_running = false;
        }
        else{
            cout << "Invalid input." << endl;
        }
    }
}
