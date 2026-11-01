#include <iostream>
#include <iomanip>
#include "Product.h"

Product::Product()
{
    sku = 0;
    name = "";
    quantity = 0;
    price = 0.0;
    dateAdded = "";
}

Product::Product(
    int sku,
    const std::string& name,
    int quantity,
    double price,
    const std::string& dateAdded
)
{
    this->sku = sku;
    this->name = name;
    this->quantity = quantity;
    this->price = price;
    this->dateAdded = dateAdded;
}

int Product::getSku() const
{
    return sku;
}

std::string Product::getName() const
{
    return name;
}

int Product::getQuantity() const
{
    return quantity;
}

double Product::getPrice() const
{
    return price;
}

std::string Product::getDateAdded() const
{
    return dateAdded;
}

void Product::display() const
{
    std::cout
        << std::left
        << std::setw(10) << sku
        << std::setw(24) << name
        << std::setw(12) << quantity
        << "$"
        << std::setw(11)
        << std::fixed
        << std::setprecision(2)
        << price
        << dateAdded
        << '\n';
}
