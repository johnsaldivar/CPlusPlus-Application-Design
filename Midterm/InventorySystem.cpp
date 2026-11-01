#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include "InventorySystem.h"

InventorySystem::InventorySystem(
    int capacity,
    const std::string& dataFileName
)
    : products(new Product[capacity]),
      productCount(0),
      capacity(capacity),
      dataFileName(dataFileName)
{
}

InventorySystem::~InventorySystem()
{
    delete[] products;
    products = nullptr;
}

bool InventorySystem::loadFromFile()
{
    std::ifstream inputFile(dataFileName);

    if (!inputFile.is_open())
    {
        return false;
    }

    productCount = 0;
    std::string line;

    while (productCount < capacity && std::getline(inputFile, line))
    {
        if (line.empty())
        {
            continue;
        }

        std::stringstream row(line);
        std::string skuText;
        std::string name;
        std::string quantityText;
        std::string priceText;
        std::string dateAdded;

        if (!std::getline(row, skuText, '|') ||
            !std::getline(row, name, '|') ||
            !std::getline(row, quantityText, '|') ||
            !std::getline(row, priceText, '|') ||
            !std::getline(row, dateAdded))
        {
            continue;
        }

        try
        {
            int sku = std::stoi(skuText);
            int quantity = std::stoi(quantityText);
            double price = std::stod(priceText);

            Product product(
                sku,
                name,
                quantity,
                price,
                dateAdded
            );

            addProduct(product);
        }
        catch (...)
        {
            // Skip malformed file records rather than terminating the program.
        }
    }

    return true;
}

bool InventorySystem::saveToFile() const
{
    std::ofstream outputFile(dataFileName);

    if (!outputFile.is_open())
    {
        return false;
    }

    outputFile << std::fixed << std::setprecision(2);

    for (int i = 0; i < productCount; i++)
    {
        outputFile
            << products[i].getSku() << '|'
            << products[i].getName() << '|'
            << products[i].getQuantity() << '|'
            << products[i].getPrice() << '|'
            << products[i].getDateAdded()
            << '\n';
    }

    return true;
}

void InventorySystem::seedDefaultData()
{
    productCount = 0;

    addProduct(Product(1001, "Brake Pads", 5, 39.99, "10/01/2026"));
    addProduct(Product(1002, "Oil Filter", 10, 8.99, "10/02/2026"));
    addProduct(Product(1005, "Air Filter", 7, 14.49, "10/03/2026"));
    addProduct(Product(1010, "Spark Plugs", 12, 6.25, "10/04/2026"));
}

void InventorySystem::displayProducts() const
{
    std::cout
        << "\n=====================================================================\n"
        << "                         INVENTORY RECORDS\n"
        << "=====================================================================\n";

    if (productCount == 0)
    {
        std::cout << "No inventory records are available.\n";
        return;
    }

    std::cout
        << std::left
        << std::setw(10) << "SKU"
        << std::setw(24) << "Product"
        << std::setw(12) << "Quantity"
        << std::setw(12) << "Price"
        << "Date Added\n"
        << "---------------------------------------------------------------------\n";

    for (int i = 0; i < productCount; i++)
    {
        products[i].display();
    }
}

bool InventorySystem::addProduct(const Product& product)
{
    if (productCount >= capacity)
    {
        return false;
    }

    if (binarySearchBySku(product.getSku()) != -1)
    {
        return false;
    }

    int insertIndex = 0;

    while (
        insertIndex < productCount &&
        products[insertIndex].getSku() < product.getSku()
    )
    {
        insertIndex++;
    }

    for (int i = productCount; i > insertIndex; i--)
    {
        products[i] = products[i - 1];
    }

    products[insertIndex] = product;
    productCount++;

    return true;
}

bool InventorySystem::deleteProductBySku(int sku)
{
    int index = binarySearchBySku(sku);

    if (index == -1)
    {
        return false;
    }

    for (int i = index; i < productCount - 1; i++)
    {
        products[i] = products[i + 1];
    }

    productCount--;
    return true;
}

int InventorySystem::binarySearchBySku(int targetSku) const
{
    int left = 0;
    int right = productCount - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int middleSku = products[mid].getSku();

        if (middleSku == targetSku)
        {
            return mid;
        }

        if (middleSku < targetSku)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

void InventorySystem::searchAndDisplay(int targetSku) const
{
    int index = binarySearchBySku(targetSku);

    if (index == -1)
    {
        std::cout
            << "\nNo product found with SKU "
            << targetSku << ".\n";
        return;
    }

    std::cout
        << "\nProduct found using binary search:\n"
        << std::left
        << std::setw(10) << "SKU"
        << std::setw(24) << "Product"
        << std::setw(12) << "Quantity"
        << std::setw(12) << "Price"
        << "Date Added\n"
        << "---------------------------------------------------------------------\n";

    products[index].display();
}

int InventorySystem::getProductCount() const
{
    return productCount;
}

int InventorySystem::getCapacity() const
{
    return capacity;
}

const Product* InventorySystem::getDataPointer() const
{
    return products;
}
