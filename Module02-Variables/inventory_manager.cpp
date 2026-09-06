#include <iostream>
#include <limits>

using namespace std;

// Function prototypes
void displayMenu();
void addItem();
void viewInventory();
void searchInventory();
void updateItem();
void removeItem();

int main()
{
    int choice = 0;

    do
    {
        displayMenu();

        cout << "Select an option: ";

        // Check that the user entered a number
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\nInvalid input. Please enter a number from 1 to 6.\n";
            continue;
        }

        switch (choice)
        {
            case 1:
                addItem();
                break;

            case 2:
                viewInventory();
                break;

            case 3:
                searchInventory();
                break;

            case 4:
                updateItem();
                break;

            case 5:
                removeItem();
                break;

            case 6:
                cout << "\nClosing Inventory Manager..." << endl;
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "\nInvalid option. Please choose a number from 1 to 6.\n";
                break;
        }

    } while (choice != 6);

    return 0;
}


void displayMenu()
{
    cout << "\n========================================" << endl;
    cout << "         INVENTORY MANAGER" << endl;
    cout << "========================================" << endl;
    cout << "1. Add Item" << endl;
    cout << "2. View Inventory" << endl;
    cout << "3. Search Inventory" << endl;
    cout << "4. Update Item" << endl;
    cout << "5. Remove Item" << endl;
    cout << "6. Exit" << endl;
    cout << "========================================" << endl;
}


void addItem()
{
    cout << "\n--- Add Item ---" << endl;
    cout << "This feature will allow new inventory items to be added." << endl;
}


void viewInventory()
{
    cout << "\n--- View Inventory ---" << endl;
    cout << "This feature will display all inventory items." << endl;
}


void searchInventory()
{
    cout << "\n--- Search Inventory ---" << endl;
    cout << "This feature will allow inventory items to be searched." << endl;
}


void updateItem()
{
    cout << "\n--- Update Item ---" << endl;
    cout << "This feature will allow existing inventory items to be updated." << endl;
}


void removeItem()
{
    cout << "\n--- Remove Item ---" << endl;
    cout << "This feature will allow inventory items to be removed." << endl;
}
