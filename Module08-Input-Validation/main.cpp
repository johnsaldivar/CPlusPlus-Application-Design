#include <iostream>

#include "InventorySystem.h"
#include "InputValidator.h"
#include "User.h"

void showWelcome();

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

    InventorySystem inventory;
    inventory.seedData();

    Admin admin(
        "admin_user"
    );

    RegularUser regularUser(
        "regular_user"
    );

    User* currentUser =
        chooseRole(
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
        << "========================================\n";

    std::cout
        << "       INVENTORY MANAGER - MODULE 8\n";

    std::cout
        << "========================================\n";

    std::cout
        << "Input Validation & Protecting Data\n\n";
}

User* chooseRole(
    Admin& admin,
    RegularUser& regularUser
)
{
    while (true)
    {
        std::cout
            << "Choose a role:\n";

        std::cout
            << "1. Admin\n";

        std::cout
            << "2. Regular User\n";

        int choice =
            InputValidator::getIntInRange(
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
}

void runApplication(
    User& currentUser,
    InventorySystem& inventory
)
{
    int choice = 0;

    std::cout
        << "\nLogged in as: "
        << currentUser.getUsername()
        << " ("
        << currentUser.getRole()
        << ")\n";

    do
    {
        std::cout
            << "\n========================================\n";

        std::cout
            << "             INVENTORY MENU\n";

        std::cout
            << "========================================\n";

        std::cout
            << "1. View Records\n";

        std::cout
            << "2. Search Record by SKU\n";

        std::cout
            << "3. Add Record\n";

        std::cout
            << "4. Delete Record\n";

        std::cout
            << "5. Exit\n";

        choice =
            InputValidator::getIntInRange(
                "Select an option: ",
                1,
                5
            );

        switch (choice)
        {
            case 1:
            {
                if (currentUser.canView())
                {
                    inventory
                        .displayProducts();
                }
                else
                {
                    std::cout
                        << "\nAccess denied.\n";
                }

                break;
            }

            case 2:
            {
                if (!currentUser.canView())
                {
                    std::cout
                        << "\nAccess denied.\n";

                    break;
                }

                int sku =
                    InputValidator::getIntInRange(
                        "Enter SKU to search for "
                        "(1-999999): ",
                        1,
                        999999
                    );

                inventory
                    .searchAndDisplay(
                        sku
                    );

                break;
            }

            case 3:
            {
                if (!currentUser.canAdd())
                {
                    std::cout
                        << "\nAccess denied: "
                        << "Regular Users cannot "
                        << "add records.\n";

                    break;
                }

                int sku;

                while (true)
                {
                    sku =
                        InputValidator::getIntInRange(
                            "Enter SKU (1-999999): ",
                            1,
                            999999
                        );

                    if (
                        inventory.binarySearchBySku(
                            sku
                        ) == -1
                    )
                    {
                        break;
                    }

                    std::cout
                        << "Invalid SKU. That SKU "
                        << "already exists. Please "
                        << "try a different SKU.\n";
                }

                std::string name =
                    InputValidator::getRequiredString(
                        "Enter product name: ",
                        50
                    );

                int quantity =
                    InputValidator::getIntInRange(
                        "Enter quantity "
                        "(0-1000000): ",
                        0,
                        1000000
                    );

                double price =
                    InputValidator::getDoubleInRange(
                        "Enter price "
                        "(0.01-1000000.00): $",
                        0.01,
                        1000000.00
                    );

                std::string dateAdded =
                    InputValidator::getDateMMDDYYYY(
                        "Enter date added "
                        "(MM/DD/YYYY): "
                    );

                Product newProduct(
                    sku,
                    name,
                    quantity,
                    price,
                    dateAdded
                );

                if (
                    inventory.addProduct(
                        newProduct
                    )
                )
                {
                    std::cout
                        << "\nRecord added successfully "
                        << "in sorted SKU order.\n";
                }
                else
                {
                    std::cout
                        << "\nRecord could not be added. "
                        << "Inventory may be full.\n";
                }

                break;
            }

            case 4:
            {
                if (!currentUser.canDelete())
                {
                    std::cout
                        << "\nAccess denied: "
                        << "Regular Users cannot "
                        << "delete records.\n";

                    break;
                }

                int sku =
                    InputValidator::getIntInRange(
                        "Enter SKU to delete "
                        "(1-999999): ",
                        1,
                        999999
                    );

                if (
                    inventory
                        .deleteProductBySku(
                            sku
                        )
                )
                {
                    std::cout
                        << "\nRecord deleted successfully.\n";
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
                std::cout
                    << "\nClosing Inventory Manager...\n";

                break;
            }
        }

    } while (choice != 5);
}
