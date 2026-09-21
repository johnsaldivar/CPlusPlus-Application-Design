#include <iostream>
#include <iomanip>
#include <limits>

#include "InventoryTools.h"

using namespace std;


void addRecord(
    InventoryRecord records[],
    int& recordCount,
    int maxRecords
)
{
    if (recordCount >= maxRecords)
    {
        cout << "\nInventory is full. No more records can be added."
             << endl;
        return;
    }

    cout << "\n========================================" << endl;
    cout << "             ADD INVENTORY ITEM" << endl;
    cout << "========================================" << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Item name: ";
    getline(cin, records[recordCount].itemName);

    cout << "Quantity: ";
    cin >> records[recordCount].quantity;

    cout << "Price: $";
    cin >> records[recordCount].price;

    recordCount++;

    cout << "\nInventory record added successfully!" << endl;
}


void displayRecords(
    const InventoryRecord records[],
    int recordCount
)
{
    cout << "\n========================================" << endl;
    cout << "             INVENTORY RECORDS" << endl;
    cout << "========================================" << endl;

    if (recordCount == 0)
    {
        cout << "No inventory records are available." << endl;
        return;
    }

    cout << left
         << setw(8) << "Record"
         << setw(25) << "Item"
         << setw(12) << "Quantity"
         << "Price" << endl;

    cout << "--------------------------------------------------"
         << endl;

    cout << fixed << setprecision(2);

    for (int i = 0; i < recordCount; i++)
    {
        cout << left
             << setw(8) << (i + 1)
             << setw(25) << records[i].itemName
             << setw(12) << records[i].quantity
             << "$" << records[i].price
             << endl;
    }
}


double calculateInventoryValue(
    const InventoryRecord records[],
    int recordCount
)
{
    double totalValue = 0.0;

    for (int i = 0; i < recordCount; i++)
    {
        totalValue +=
            records[i].quantity * records[i].price;
    }

    return totalValue;
}
