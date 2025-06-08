#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int getValidOption(int min, int max) {
    int choice;
    while (true) {
        cout << ">> Enter choice (" << min << "-" << max << "): ";
        cin >> choice;
        if (cin.fail() || choice < min || choice > max) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter valid input!.\n";
        } else {
            cin.ignore();
            return choice;
        }
    }
}
void printHeader(string title){
    cout << "\n============================================\n";
    cout << "     " << title << "\n";
    cout << "============================================\n";
}
int main() {
    const int MAX_ITEMS = 100;
    string outlet, collection[MAX_ITEMS], brand[MAX_ITEMS], season[MAX_ITEMS], style[MAX_ITEMS];
    string type[MAX_ITEMS], subType[MAX_ITEMS], size[MAX_ITEMS], color[MAX_ITEMS];
    float price[MAX_ITEMS];
    int totalItems = 0;
    float totalBill = 0;
    int option;
    string outlets[] = {"Lahore", "Islamabad", "Karachi", "Faisalabad"};
    string brands[] = {"J.", "Sapphire", "Nishat", "Breeze", "Gul Ahmad"};
    string colors[] = {"Red", "Blue", "Green", "Yellow", "Black", "White", "Brown", "Purple", "Pink", "Orange"};
    string sizes[] = {"S", "M", "L", "XL"};
    const float PANT_PRICE = 2500;
    const float SHIRT_PRICE = 2000;
    const float MEN_SUIT_PRICE = 4000;
    const float WOMEN_2PC_PRICE = 3000;
    const float WOMEN_3PC_PRICE = 4500;
    const float SHAWL_PRICE = 2000;
    const float HOODIE_PRICE = 4000;
    const float JACKET_PRICE = 6000;
    const float SWEATER_PRICE = 3000;
    printHeader("WELCOME TO TRENDY THREADS OUTLET");
    cout << ">>> Choose the nearest outlet:\n";
    for (int i = 0; i < 4; i++) {
        cout << " [" << i + 1 << "] " << outlets[i] << "\n";
    }
    option = getValidOption(1, 4);
    outlet = outlets[option - 1];
    system("CLS");
    while (true) {
        printHeader("COLLECTION SELECTION");
        cout << " [1] Men\n [2] Women\n";
        option = getValidOption(1, 2);
        collection[totalItems] = (option == 1) ? "Men" : "Women";
        system("CLS");
        printHeader("BRAND SELECTION");
        for (int i = 0; i < 5; i++) {
            cout << " [" << i + 1 << "] " << brands[i] << "\n";
        }
        option = getValidOption(1, 5);
        brand[totalItems] = brands[option - 1];
        system("CLS");
        printHeader("SEASON SELECTION");
        cout << " [1] Summer\n [2] Winter\n";
        option = getValidOption(1, 2);
        season[totalItems] = (option == 1) ? "Summer" : "Winter";
        system("CLS");
        printHeader("STYLE SELECTION");
        cout << " [1] Eastern\n [2] Western\n";
        option = getValidOption(1, 2);
        style[totalItems] = (option == 1) ? "Eastern" : "Western";
        system("CLS");
        if (style[totalItems] == "Eastern") {
            printHeader("EASTERN SUIT TYPE");
            if (collection[totalItems] == "Men") {
                if (season[totalItems] == "Summer") {
                    cout << " [1] Cotton (Rs. 4000)\n [2] Wash n Wear (Rs. 4000)\n [3] Texture Wash n Wear (Rs. 4000)\n";
                } else {
                    cout << " [1] Khaddar (Rs. 4000)\n [2] Marina (Rs. 4000)\n [3] Cotton Wool Blend (Rs. 4000)\n";
                }
                getValidOption(1, 3);
                type[totalItems] = "Suit";
                price[totalItems] = MEN_SUIT_PRICE;
            } else {
                if (season[totalItems] == "Summer") {
                    cout << " [1] Linen\n [2] Cotton\n [3] Cambric Cotton\n [4] Lawn\n [5] Arabic Lawn\n";
                    getValidOption(1, 5);
                } else {
                    cout << " [1] Velvet\n [2] Linen\n [3] Marina\n [4] Rashmi\n";
                    getValidOption(1, 4);
                }
                cout << "\n>>> Choose Suit Piece:\n";
                cout << " [1] 2PC (Rs. 3000)\n [2] 3PC (Rs. 4500)\n";
                option = getValidOption(1, 2);
                type[totalItems] = (option == 1) ? "2PC Suit" : "3PC Suit";
                price[totalItems] = (option == 1) ? WOMEN_2PC_PRICE : WOMEN_3PC_PRICE;
            }
        } else {
            printHeader("WESTERN CATEGORY");
            cout << " [1] Pant\n [2] Shirt\n [3] Outerwear\n";
            option = getValidOption(1, 3);
            system("CLS");

            if (option == 1) {
                printHeader("PANT TYPES");
                cout << " [1] Cotton Pant (Rs. 2500)\n [2] Jeans Pant (Rs. 2500)\n [3] Baggy Pant (Rs. 2500)\n [4] Skinny Pant (Rs. 2500)\n";
                option = getValidOption(1, 4);
                type[totalItems] = "Pant";
                string pantTypes[] = {"Cotton Pant", "Jeans Pant", "Baggy Pant", "Skinny Pant"};
                subType[totalItems] = pantTypes[option - 1];
                price[totalItems] = PANT_PRICE;
            } else if (option == 2) {
                printHeader("SHIRT TYPES");
                cout << " [1] T-Shirt (Rs. 2000)\n [2] Polo Shirt (Rs. 2000)\n";
                option = getValidOption(1, 2);
                type[totalItems] = "Shirt";
                subType[totalItems] = (option == 1) ? "T-Shirt" : "Polo Shirt";
                price[totalItems] = SHIRT_PRICE;
            } else {
                if (season[totalItems] == "Summer") {
                    cout << "\n!! No Outerwear products available in Summer !!\n";
                    continue;
                }
                printHeader("OUTERWEAR OPTIONS");
                cout << " [1] Hoodie (Rs. 4000)\n [2] Sweater (Rs. 3000)\n [3] Jacket (Rs. 6000)\n [4] Shawl (Rs. 2000)\n";
                option = getValidOption(1, 4);
                string outerwear[] = {"Hoodie", "Sweater", "Jacket", "Shawl"};
                type[totalItems] = outerwear[option - 1];
                float prices[] = {HOODIE_PRICE, SWEATER_PRICE, JACKET_PRICE, SHAWL_PRICE};
                price[totalItems] = prices[option - 1];
            }
        }
        system("CLS");
        printHeader("SIZE SELECTION");
        if (type[totalItems] == "Shawl") {
            cout << " [1] Large (Only Size Available)\n";
            size[totalItems] = "Large";
            getValidOption(1, 1);
        } else {
            for (int i = 0; i < 4; i++) {
                cout << " [" << i + 1 << "] " << sizes[i] << "\n";
            }
            option = getValidOption(1, 4);
            size[totalItems] = sizes[option - 1];
        }
        system("CLS");

        printHeader("COLOR SELECTION");
        for (int i = 0; i < 10; i++) {
            cout << " [" << i + 1 << "] " << colors[i] << "\n";
        }
        option = getValidOption(1, 10);
        color[totalItems] = colors[option - 1];
        system("CLS");
        totalBill += price[totalItems];
        totalItems++;
        cout << "Add another item?\n [1] Yes\n [2] No\n";
        option = getValidOption(1, 2);
        system("CLS");
        if (option == 2) break;
    }
    printHeader("ORDER SUMMARY");
    for (int i = 0; i < totalItems; i++) {
        cout << "Item #" << i + 1 << ": " << collection[i] << " | " << style[i] << " | ";
        cout << (subType[i] != "" ? subType[i] : type[i]) << " | Size: " << size[i]
             << " | Color: " << color[i] << " | Rs. " << price[i] << endl;
    }
    cout << "\n>>> Total Bill: Rs. " << totalBill << "\n";
    string name, address, contact, email;
    cout << "\nEnter your name: ";
    getline(cin, name);
    cout << "Enter delivery address: ";
    getline(cin, address);
    cout << "Enter contact number: ";
    getline(cin, contact);
    cout << "Enter email: ";
    getline(cin, email);
    cout << "\nConfirm Order?\n [1] Confirm\n [2] Cancel\n";
    option = getValidOption(1, 2);
    system("CLS");
    printHeader("ORDER STATUS");
    if (option == 1) {
        cout << " Order Confirmed!\n";
        cout << "Thanks, " << name << ". Your items will be delivered to: " << address <<"in 3-5 working days."<< "\n";
        cout << ".Thank you for shopping.We appreciate your trust.\n Stay stylish with Trendy Threads!\n";
    } else {
        cout << " Order Cancelled.\nHope to serve you next time!\n";
    }
    cout << "\n============================================\n";
        return 0;

}

