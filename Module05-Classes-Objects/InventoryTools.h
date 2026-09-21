#ifndef INVENTORYTOOLS_H
#define INVENTORYTOOLS_H

#include <string>

// Represents one inventory record
struct InventoryRecord
{
    std::string itemName;
    int quantity;
    double price;
};

// Function declarations
void addRecord(InventoryRecord records[], int& recordCount, int maxRecords);

void displayRecords(
    const InventoryRecord records[],
    int recordCount
);

double calculateInventoryValue(
    const InventoryRecord records[],
    int recordCount
);

#endif
