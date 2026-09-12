#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Variables used by the Inventory Manager
    string userName;
    string applicationName = "Inventory Manager";
    double versionNumber = 0.3;
    int currentItemCount = 0;
    double sampleItemPrice = 19.99;
    char inventoryStatus = 'A';
    bool applicationReady = true;

    // Get the user's name
    cout << "Enter your name: ";
    getline(cin, userName);

    // Display bool values as true/false instead of 1/0
    cout << boolalpha;

    // Welcome screen
    cout << "\n========================================" << endl;
    cout << "       WELCOME TO INVENTORY MANAGER" << endl;
    cout << "========================================" << endl;

    cout << "User: " << userName << endl;
    cout << "Application: " << applicationName << endl;
    cout << "Version: " << versionNumber << endl;

    cout << "\n--- Application Information ---" << endl;
    cout << "Current Item Count: " << currentItemCount << endl;
    cout << "Sample Item Price: $" << sampleItemPrice << endl;
    cout << "Inventory Status Code: " << inventoryStatus << endl;
    cout << "Application Ready: " << applicationReady << endl;

    cout << "\n--- Inventory Manager Features ---" << endl;
    cout << "1. Add Item" << endl;
    cout << "2. View Inventory" << endl;
    cout << "3. Search Inventory" << endl;
    cout << "4. Update Item" << endl;
    cout << "5. Remove Item" << endl;
    cout << "6. Exit" << endl;

    cout << "\nWelcome, " << userName << "!" << endl;
    cout << applicationName << " is ready for development." << endl;

    return 0;
}
