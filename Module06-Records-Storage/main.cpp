#include <iostream>
#include <iomanip>
#include "Product.h"

// Function declarations
void showWelcome();
void showMenu();
void demonstrateProducts();

int main()
{
    // main() is the starting point of the application.
    // It coordinates the functions used by the program.

    showWelcome();
    showMenu();
    demonstrateProducts();

    return 0;
}

void showWelcome()
{
    std::cout << "========================================\n";
    std::cout << "         INVENTORY MANAGER - MODULE 6\n";
    std::cout << "========================================\n";
    std::cout << "Classes and Objects Demonstration\n\n";
}

void showMenu()
{
    std::cout << "Application Features\n";
    std::cout << "1. Create Product Objects\n";
    std::cout << "2. Display Product Information\n";
    std::cout << "3. Update Product Data\n\n";
}

void demonstrateProducts()
{
    // Create at least two objects from the Product class.
    Product product1("Brake Pads", 1001, 5, 39.99);
    Product product2("Oil Filter", 1002, 10, 8.99);

    std::cout << "--- Product 1 ---\n";
    product1.displayProduct();

    std::cout << "\n--- Product 2 ---\n";
    product2.displayProduct();

    // Getter demonstration
    std::cout << "\n--- Getter Demonstration ---\n";
    std::cout << "Product 1 name: "
              << product1.getName()
              << '\n';

    std::cout << "Product 2 quantity: "
              << product2.getQuantity()
              << '\n';

    // Setter demonstration
    std::cout << "\n--- Setter Demonstration ---\n";

    std::cout << "Updating "
              << product1.getName()
              << " quantity from "
              << product1.getQuantity()
              << " to 8.\n";

    product1.setQuantity(8);

    std::cout << "New quantity: "
              << product1.getQuantity()
              << '\n';

    std::cout << "New inventory value: $"
              << std::fixed
              << std::setprecision(2)
              << product1.calculateInventoryValue()
              << '\n';
}
