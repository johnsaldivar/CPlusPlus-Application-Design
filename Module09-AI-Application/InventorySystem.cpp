#include <iostream>
#include <iomanip>
#include "InventorySystem.h"

InventorySystem::InventorySystem()
{
    productCount = 0;
}

void InventorySystem::seedData()
{
    products[0] = Product(1001, "Brake Pads", 2, 39.99);
    products[1] = Product(1002, "Oil Filter", 10, 8.99);
    products[2] = Product(1005, "Air Filter", 4, 14.49);
    products[3] = Product(1010, "Spark Plugs", 15, 6.25);
    products[4] = Product(1015, "Engine Cleaner", 7, 12.50);

    productCount = 5;
}

void InventorySystem::displayInventory() const
{
    std::cout << "\n=============================================================\n";
    std::cout << "                    INVENTORY RECORDS\n";
    std::cout << "=============================================================\n";

    std::cout << std::left
              << std::setw(10) << "SKU"
              << std::setw(25) << "Product"
              << std::setw(12) << "Quantity"
              << "Price\n";

    std::cout << "-------------------------------------------------------------\n";

    for (int i = 0; i < productCount; i++)
    {
        std::cout << std::left
                  << std::setw(10) << products[i].getSku()
                  << std::setw(25) << products[i].getName()
                  << std::setw(12) << products[i].getQuantity()
                  << "$"
                  << std::fixed
                  << std::setprecision(2)
                  << products[i].getPrice()
                  << '\n';
    }
}

int InventorySystem::getProductCount() const
{
    return productCount;
}

const Product& InventorySystem::getProduct(int index) const
{
    return products[index];
}
