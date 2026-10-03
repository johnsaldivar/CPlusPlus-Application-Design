#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product
{
private:
    std::string name;
    int sku;
    int quantity;
    double price;

public:
    // Constructor
    Product(
        const std::string& name,
        int sku,
        int quantity,
        double price
    );

    // Member functions
    void displayProduct() const;
    double calculateInventoryValue() const;

    // Getters
    std::string getName() const;
    int getQuantity() const;
    double getPrice() const;

    // Setters
    void setQuantity(int quantity);
    void setPrice(double price);
};

#endif
