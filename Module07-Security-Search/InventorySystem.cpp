#include <iostream>
#include <iomanip>
#include "InventorySystem.h"


InventorySystem::InventorySystem()
{
    productCount = 0;
}


void InventorySystem::seedData()
{
    addProduct(
        Product(
            1001,
            "Brake Pads",
            5,
            39.99
        )
    );

    addProduct(
        Product(
            1002,
            "Oil Filter",
            10,
            8.99
        )
    );

    addProduct(
        Product(
            1005,
            "Air Filter",
            7,
            14.49
        )
    );

    addProduct(
        Product(
            1010,
            "Spark Plugs",
            12,
            6.25
        )
    );
}


void InventorySystem::displayProducts() const
{
    std::cout
        << "\n==============================================\n";

    std::cout
        << "              INVENTORY RECORDS\n";

    std::cout
        << "==============================================\n";

    if (productCount == 0)
    {
        std::cout
            << "No inventory records are available.\n";

        return;
    }

    std::cout
        << std::left
        << std::setw(10) << "SKU"
        << std::setw(25) << "Product"
        << std::setw(12) << "Quantity"
        << "Price\n";

    std::cout
        << "----------------------------------------------------------\n";

    for (int i = 0; i < productCount; i++)
    {
        products[i].display();
    }
}


// Adds a product while keeping the array
// sorted by SKU.
bool InventorySystem::addProduct(
    const Product& product
)
{
    if (productCount >= MAX_RECORDS)
    {
        return false;
    }

    // Prevent duplicate SKU values.
    if (binarySearchBySku(
            product.getSku()
        ) != -1)
    {
        return false;
    }

    int insertIndex = 0;

    while (
        insertIndex < productCount &&
        products[insertIndex].getSku()
            < product.getSku()
    )
    {
        insertIndex++;
    }

    // Shift records to the right.
    for (
        int i = productCount;
        i > insertIndex;
        i--
    )
    {
        products[i] =
            products[i - 1];
    }

    products[insertIndex] = product;

    productCount++;

    return true;
}


bool InventorySystem::deleteProductBySku(
    int sku
)
{
    int index =
        binarySearchBySku(sku);

    if (index == -1)
    {
        return false;
    }

    for (
        int i = index;
        i < productCount - 1;
        i++
    )
    {
        products[i] =
            products[i + 1];
    }

    productCount--;

    return true;
}


// Binary search requires the product
// records to remain sorted by SKU.
int InventorySystem::binarySearchBySku(
    int targetSku
) const
{
    int left = 0;

    int right =
        productCount - 1;

    while (left <= right)
    {
        int mid =
            left +
            (right - left) / 2;

        int middleSku =
            products[mid].getSku();

        if (middleSku == targetSku)
        {
            return mid;
        }

        if (middleSku < targetSku)
        {
            left =
                mid + 1;
        }
        else
        {
            right =
                mid - 1;
        }
    }

    return -1;
}


void InventorySystem::searchAndDisplay(
    int targetSku
) const
{
    int index =
        binarySearchBySku(
            targetSku
        );

    if (index == -1)
    {
        std::cout
            << "\nNo product found with SKU "
            << targetSku
            << ".\n";

        return;
    }

    std::cout
        << "\nProduct found using binary search:\n";

    std::cout
        << std::left
        << std::setw(10) << "SKU"
        << std::setw(25) << "Product"
        << std::setw(12) << "Quantity"
        << "Price\n";

    std::cout
        << "----------------------------------------------------------\n";

    products[index].display();
}


int InventorySystem::getProductCount() const
{
    return productCount;
}
