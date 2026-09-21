#include <iostream>
#include <iomanip>
#include <limits>

#include "InventoryTools.h"

using namespace std;


int main()
{
    const int MAX_RECORDS = 10;

    InventoryRecord inventory[MAX_RECORDS];

    int recordCount = 0;
    int choice = 0;

    do
    {
        cout << "\n========================================" << endl;
        cout << "            INVENTORY MANAGER" << endl;
        cout << "========================================" << endl;
        cout << "1. Add Inventory Record" << endl;
        cout << "2. Display Inventory Records" << endl;
        cout << "3. Calculate Total Inventory Value" << endl;
        cout << "4. Exit" << endl;
        cout << "========================================" << endl;
        cout << "Select an option: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            cout << "\nInvalid input. Please enter a number "
                 << "from 1 to 4." << endl;

            continue;
        }

        switch (choice)
        {
            case 1:
                addRecord(
                    inventory,
                    recordCount,
                    MAX_RECORDS
                );
                break;

            case 2:
                displayRecords(
                    inventory,
                    recordCount
                );
                break;

            case 3:
            {
                double totalValue =
                    calculateInventoryValue(
                        inventory,
                        recordCount
                    );

                cout << fixed << setprecision(2);

                cout << "\nTotal Inventory Value: $"
                     << totalValue
                     << endl;

                break;
            }

            case 4:
                cout << "\nClosing Inventory Manager..."
                     << endl;

                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "\nInvalid option. Please select "
                     << "a number from 1 to 4." << endl;
                break;
        }

    } while (choice != 4);

    return 0;
}
