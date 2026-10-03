#include <iostream>
#include <iomanip>
#include "Product.h"

Product::Product(
    const std::string& name,
    int sku,
    int quantity,
    double price
)
{
    this->name = name;
    this->sku = sku;
    this->quantity = quantity;
    this->price = price;
}

void Product::displayProduct() const
{
    std::cout << "Product: " << name << '\n';
    std::cout << "SKU: " << sku << '\n';
    std::cout << "Quantity: " << quantity << '\n';

    std::cout << "Price: $"
              << std::fixed
              << std::setprecision(2)
              << price
              << '\n';

    std::cout << "Inventory Value: $"
              << calculateInventoryValue()
              << '\n';
}

double Product::calculateInventoryValue() const
{
    return quantity * price;
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

void Product::setQuantity(int quantity)
{
    if (quantity >= 0)
    {
        this->quantity = quantity;
    }
}

void Product::setPrice(double price)
{
    if (price >= 0.0)
    {
        this->price = price;
    }
}
