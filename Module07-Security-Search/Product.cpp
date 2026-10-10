#include <iostream>
#include <iomanip>
#include "Product.h"

Product::Product()
{
    sku = 0;
    name = "";
    quantity = 0;
    price = 0.0;
}

Product::Product(
    int sku,
    const std::string& name,
    int quantity,
    double price
)
{
    this->sku = sku;
    this->name = name;
    this->quantity = quantity;
    this->price = price;
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

void Product::display() const
{
    std::cout << std::left
              << std::setw(10) << sku
              << std::setw(25) << name
              << std::setw(12) << quantity
              << "$"
              << std::fixed
              << std::setprecision(2)
              << price
              << '\n';
}
