#ifndef INVENTORYSYSTEM_H
#define INVENTORYSYSTEM_H

#include "Product.h"

class InventorySystem
{
private:
    static const int MAX_PRODUCTS = 10;
    Product products[MAX_PRODUCTS];
    int productCount;

public:
    InventorySystem();

    void seedData();
    void displayInventory() const;

    int getProductCount() const;
    const Product& getProduct(int index) const;
};

#endif
