#include <iomanip>
#include <iostream>
#include <string>

#include "InputValidator.h"
#include "InventorySystem.h"
#include "User.h"

void showWelcome();
void showRequiredConcepts();
void showDataTypeSizes();
void showPointerDemo(const InventorySystem& inventory);

User* chooseRole(
    Admin& admin,
    RegularUser& regularUser
);

void runApplication(
    User& currentUser,
    InventorySystem& inventory
);

int main()
{
    showWelcome();

    InventorySystem inventory(
        50,
        "inventory.txt"
    );

    if (inventory.loadFromFile())
    {
        std::cout
            << "Inventory data loaded from inventory.txt.\n";
    }
    else
    {
        std::cout
            << "inventory.txt was not found. Loading default inventory.\n";

        inventory.seedDefaultData();

        if (inventory.saveToFile())
        {
            std::cout
                << "Default inventory saved to inventory.txt.\n";
        }
    }

    Admin admin("admin_user");
    RegularUser regularUser("regular_user");

    User* currentUser = chooseRole(
        admin,
        regularUser
    );

    runApplication(
        *currentUser,
        inventory
    );

    return 0;
}

void showWelcome()
{
    std::cout
        << "=====================================================\n"
        << "          C++ MIDWAY PROJECT\n"
        << "          INVENTORY MANAGEMENT SYSTEM\n"
        << "=====================================================\n"
        << "John Saldivar\n\n";
}

void showRequiredConcepts()
{
    std::cout
        << "\n========================================\n"
        << "       REQUIRED C++ CONCEPTS USED\n"
        << "========================================\n"
        << "Data types and data sizes      : Yes\n"
        << "Text file (.txt)               : Yes\n"
        << "Pointers                       : Yes\n"
        << "Dynamic memory                 : Yes\n"
        << "Arrays                         : Yes\n"
        << "Binary search                  : Yes\n"
        << "Strings                        : Yes\n"
        << "File input/output              : Yes\n"
        << "Two or more classes            : Yes\n"
        << "Input validation               : Yes\n"
        << "Role-based permissions         : Yes\n";
}

void showDataTypeSizes()
{
    std::cout
        << "\n========================================\n"
        << "             DATA TYPE SIZES\n"
        << "========================================\n"
        << "sizeof(char)      = " << sizeof(char) << " byte(s)\n"
        << "sizeof(bool)      = " << sizeof(bool) << " byte(s)\n"
        << "sizeof(int)       = " << sizeof(int) << " byte(s)\n"
        << "sizeof(double)    = " << sizeof(double) << " byte(s)\n"
        << "sizeof(Product*)  = " << sizeof(Product*) << " byte(s)\n";
}

void showPointerDemo(const InventorySystem& inventory)
{
    const Product* productPointer = inventory.getDataPointer();

    std::cout
        << "\n========================================\n"
        << "          POINTER / DYNAMIC ARRAY\n"
        << "========================================\n"
        << "The inventory is stored in a dynamically\n"
        << "allocated Product array.\n\n"
        << "Product array pointer address: "
        << static_cast<const void*>(productPointer)
        << '\n'
        << "Current records: " << inventory.getProductCount() << '\n'
        << "Dynamic array capacity: " << inventory.getCapacity() << '\n';

    if (inventory.getProductCount() > 0)
    {
        std::cout
            << "First SKU through pointer access: "
            << productPointer->getSku()
            << '\n';
    }
}

User* chooseRole(
    Admin& admin,
    RegularUser& regularUser
)
{
    std::cout
        << "\nChoose a role:\n"
        << "1. Admin\n"
        << "2. Regular User\n";

    int choice = InputValidator::getIntInRange(
        "Selection: ",
        1,
        2
    );

    if (choice == 1)
    {
        return &admin;
    }

    return &regularUser;
}

void runApplication(
    User& currentUser,
    InventorySystem& inventory
)
{
    std::cout
        << "\nLogged in as: "
        << currentUser.getUsername()
        << " (" << currentUser.getRole() << ")\n";

    int choice = 0;

    do
    {
        std::cout
            << "\n========================================\n"
            << "             INVENTORY MENU\n"
            << "========================================\n"
            << "1. View Records\n"
            << "2. Search Record by SKU\n"
            << "3. Add Record\n"
            << "4. Delete Record\n"
            << "5. Save Inventory to File\n"
            << "6. Show Data Type Sizes\n"
            << "7. Show Pointer / Dynamic Memory Demo\n"
            << "8. Show Required Concepts\n"
            << "9. Exit\n";

        choice = InputValidator::getIntInRange(
            "Select an option: ",
            1,
            9
        );

        switch (choice)
        {
            case 1:
            {
                if (currentUser.canView())
                {
                    inventory.displayProducts();
                }
                else
                {
                    std::cout << "\nAccess denied.\n";
                }
                break;
            }

            case 2:
            {
                if (!currentUser.canView())
                {
                    std::cout << "\nAccess denied.\n";
                    break;
                }

                int sku = InputValidator::getIntInRange(
                    "Enter SKU to search for (1-999999): ",
                    1,
                    999999
                );

                inventory.searchAndDisplay(sku);
                break;
            }

            case 3:
            {
                if (!currentUser.canAdd())
                {
                    std::cout
                        << "\nAccess denied: Regular Users cannot add records.\n";
                    break;
                }

                int sku;

                while (true)
                {
                    sku = InputValidator::getIntInRange(
                        "Enter SKU (1-999999): ",
                        1,
                        999999
                    );

                    if (inventory.binarySearchBySku(sku) == -1)
                    {
                        break;
                    }

                    std::cout
                        << "Invalid SKU. That SKU already exists. "
                        << "Please try a different SKU.\n";
                }

                std::string name = InputValidator::getRequiredString(
                    "Enter product name: ",
                    50
                );

                int quantity = InputValidator::getIntInRange(
                    "Enter quantity (0-1000000): ",
                    0,
                    1000000
                );

                double price = InputValidator::getDoubleInRange(
                    "Enter price (0.01-1000000.00): $",
                    0.01,
                    1000000.00
                );

                std::string dateAdded = InputValidator::getDateMMDDYYYY(
                    "Enter date added (MM/DD/YYYY): "
                );

                Product newProduct(
                    sku,
                    name,
                    quantity,
                    price,
                    dateAdded
                );

                if (inventory.addProduct(newProduct))
                {
                    std::cout
                        << "\nRecord added successfully in sorted SKU order.\n";

                    if (inventory.saveToFile())
                    {
                        std::cout
                            << "Inventory automatically saved to inventory.txt.\n";
                    }
                }
                else
                {
                    std::cout
                        << "\nRecord could not be added. Inventory may be full.\n";
                }

                break;
            }

            case 4:
            {
                if (!currentUser.canDelete())
                {
                    std::cout
                        << "\nAccess denied: Regular Users cannot delete records.\n";
                    break;
                }

                int sku = InputValidator::getIntInRange(
                    "Enter SKU to delete (1-999999): ",
                    1,
                    999999
                );

                if (inventory.deleteProductBySku(sku))
                {
                    std::cout << "\nRecord deleted successfully.\n";

                    if (inventory.saveToFile())
                    {
                        std::cout
                            << "Inventory automatically saved to inventory.txt.\n";
                    }
                }
                else
                {
                    std::cout
                        << "\nNo record found with that SKU.\n";
                }

                break;
            }

            case 5:
            {
                if (inventory.saveToFile())
                {
                    std::cout
                        << "\nInventory saved successfully to inventory.txt.\n";
                }
                else
                {
                    std::cout
                        << "\nError: inventory.txt could not be written.\n";
                }
                break;
            }

            case 6:
                showDataTypeSizes();
                break;

            case 7:
                showPointerDemo(inventory);
                break;

            case 8:
                showRequiredConcepts();
                break;

            case 9:
            {
                if (inventory.saveToFile())
                {
                    std::cout
                        << "\nInventory saved to inventory.txt.\n";
                }

                std::cout
                    << "Closing Inventory Management System...\n";
                break;
            }
        }

    } while (choice != 9);
}
