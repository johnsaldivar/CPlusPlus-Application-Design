#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product
{
private:
    int sku;
    std::string name;
    int quantity;
    double price;

public:
    Product();

    Product(
        int sku,
        const std::string& name,
        int quantity,
        double price
    );

    int getSku() const;
    std::string getName() const;
    int getQuantity() const;
    double getPrice() const;

    void display() const;
};

#endif
