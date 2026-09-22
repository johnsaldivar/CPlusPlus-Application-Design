#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    const int RECORD_COUNT = 7;

    // Arrays used to store selected fields
    // from the Kaggle dataset.
    string productLines[RECORD_COUNT];
    double unitPrices[RECORD_COUNT];
    int quantities[RECORD_COUNT];

    // Open the actual CSV downloaded from Kaggle.
    ifstream datasetFile("data/SuperMarket Analysis.csv");

    if (!datasetFile.is_open())
    {
        cerr << "Error: Unable to open the Kaggle dataset." << endl;
        cerr << "Make sure SuperMarket Analysis.csv is inside the data folder."
             << endl;

        return 1;
    }

    string line;

    // Skip the CSV header row.
    getline(datasetFile, line);

    int recordCount = 0;

    // Read the first 7 records from the dataset.
    while (recordCount < RECORD_COUNT &&
           getline(datasetFile, line))
    {
        stringstream row(line);
        string field;

        // Column 0 - Invoice ID
        getline(row, field, ',');

        // Column 1 - Branch
        getline(row, field, ',');

        // Column 2 - City
        getline(row, field, ',');

        // Column 3 - Customer type
        getline(row, field, ',');

        // Column 4 - Gender
        getline(row, field, ',');

        // Column 5 - Product line
        getline(row, productLines[recordCount], ',');

        // Column 6 - Unit price
        getline(row, field, ',');
        unitPrices[recordCount] = stod(field);

        // Column 7 - Quantity
        getline(row, field, ',');
        quantities[recordCount] = stoi(field);

        recordCount++;
    }

    datasetFile.close();

    if (recordCount == 0)
    {
        cerr << "No records were loaded from the dataset." << endl;
        return 1;
    }

    // Pointer to the first unit price in the array.
    double* pricePtr = &unitPrices[0];

    cout << "\n======================================================" << endl;
    cout << "          INVENTORY MANAGER - KAGGLE DATASET" << endl;
    cout << "======================================================" << endl;

    cout << "Source file: data/SuperMarket Analysis.csv" << endl;
    cout << "Records loaded: " << recordCount << endl;

    cout << "\n";

    cout << left
         << setw(8) << "Record"
         << setw(28) << "Product Line"
         << setw(14) << "Unit Price"
         << "Quantity"
         << endl;

    cout << "------------------------------------------------------"
         << endl;

    cout << fixed << setprecision(2);

    // Display all selected records.
    for (int i = 0; i < recordCount; i++)
    {
        cout << left
             << setw(8) << (i + 1)
             << setw(28) << productLines[i]
             << "$" << setw(13) << unitPrices[i]
             << quantities[i]
             << endl;
    }

    cout << "\n--- Pointer Demonstration ---" << endl;

    cout << "First unit price using array access: $"
         << unitPrices[0]
         << endl;

    cout << "First unit price using pointer access: $"
         << *pricePtr
         << endl;

    cout << "Pointer memory address: "
         << pricePtr
         << endl;

    cout << "\nDataset loaded and displayed successfully."
         << endl;

    return 0;
}
