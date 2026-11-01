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
    std::string dateAdded;

public:
    Product();

    Product(
        int sku,
        const std::string& name,
        int quantity,
        double price,
        const std::string& dateAdded
    );

    int getSku() const;
    std::string getName() const;
    int getQuantity() const;
    double getPrice() const;
    std::string getDateAdded() const;

    void display() const;
};

#endif
