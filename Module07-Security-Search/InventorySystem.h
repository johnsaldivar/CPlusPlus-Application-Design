#ifndef INVENTORYSYSTEM_H
#define INVENTORYSYSTEM_H

#include "Product.h"

class InventorySystem
{
private:
    static const int MAX_RECORDS = 20;

    Product products[MAX_RECORDS];
    int productCount;

public:
    InventorySystem();

    void seedData();

    void displayProducts() const;

    bool addProduct(
        const Product& product
    );

    bool deleteProductBySku(
        int sku
    );

    int binarySearchBySku(
        int targetSku
    ) const;

    void searchAndDisplay(
        int targetSku
    ) const;

    int getProductCount() const;
};

#endif
