#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    const int RECORD_COUNT = 7;

    // Selected fields from the Kaggle Supermarket Sales dataset.
    // Fields used: Product Line, Unit Price, and Quantity.

    string productLines[RECORD_COUNT] =
    {
        "Health and beauty",
        "Electronic accessories",
        "Home and lifestyle",
        "Health and beauty",
        "Sports and travel",
        "Electronic accessories",
        "Electronic accessories"
    };

    double unitPrices[RECORD_COUNT] =
    {
        74.69,
        15.28,
        46.33,
        58.22,
        86.31,
        85.39,
        68.84
    };

    int quantities[RECORD_COUNT] =
    {
        7,
        5,
        7,
        8,
        7,
        7,
        6
    };

    // Pointer to the first value in the unitPrices array.
    double* pricePtr = &unitPrices[0];

    cout << "===============================================" << endl;
    cout << "       INVENTORY MANAGER - DATASET VIEW" << endl;
    cout << "===============================================" << endl;

    cout << left
         << setw(8) << "Record"
         << setw(28) << "Product Line"
         << setw(14) << "Unit Price"
         << "Quantity" << endl;

    cout << "-----------------------------------------------" << endl;

    cout << fixed << setprecision(2);

    // Display all records stored in the arrays.
    for (int i = 0; i < RECORD_COUNT; i++)
    {
        cout << left
             << setw(8) << (i + 1)
             << setw(28) << productLines[i]
             << "$" << setw(13) << unitPrices[i]
             << quantities[i] << endl;
    }

    cout << "\n--- Pointer Demonstration ---" << endl;

    cout << "First unit price normally: $"
         << unitPrices[0] << endl;

    cout << "First unit price through pointer: $"
         << *pricePtr << endl;

    cout << "Memory address stored in pointer: "
         << pricePtr << endl;

    cout << "\nDataset records displayed successfully." << endl;

    return 0;
}
