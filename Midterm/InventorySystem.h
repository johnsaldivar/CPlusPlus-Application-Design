#ifndef INVENTORYSYSTEM_H
#define INVENTORYSYSTEM_H

#include <string>
#include "Product.h"

class InventorySystem
{
private:
    Product* products;          // Pointer to a dynamically allocated array
    int productCount;
    int capacity;
    std::string dataFileName;

public:
    InventorySystem(
        int capacity,
        const std::string& dataFileName
    );

    ~InventorySystem();

    InventorySystem(const InventorySystem&) = delete;
    InventorySystem& operator=(const InventorySystem&) = delete;

    bool loadFromFile();
    bool saveToFile() const;

    void seedDefaultData();
    void displayProducts() const;

    bool addProduct(const Product& product);
    bool deleteProductBySku(int sku);

    int binarySearchBySku(int targetSku) const;
    void searchAndDisplay(int targetSku) const;

    int getProductCount() const;
    int getCapacity() const;

    const Product* getDataPointer() const;
};

#endif
