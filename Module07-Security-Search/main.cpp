#include <iostream>
#include <limits>
#include <string>

#include "InventorySystem.h"
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

int readInteger(
    const std::string& prompt
);

double readDouble(
    const std::string& prompt
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
        << "       INVENTORY MANAGER - MODULE 7\n";

    std::cout
        << "========================================\n";

    std::cout
        << "Security, Roles & Binary Search\n\n";
}


User* chooseRole(
    Admin& admin,
    RegularUser& regularUser
)
{
    int choice;

    do
    {
        std::cout
            << "Choose a role:\n";

        std::cout
            << "1. Admin\n";

        std::cout
            << "2. Regular User\n";

        choice =
            readInteger(
                "Selection: "
            );

        if (choice == 1)
        {
            return &admin;
        }

        if (choice == 2)
        {
            return &regularUser;
        }

        std::cout
            << "Invalid role selection. "
            << "Please choose 1 or 2.\n\n";

    } while (true);
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
            readInteger(
                "Select an option: "
            );

        switch (choice)
        {
            case 1:
            {
                if (
                    currentUser.canView()
                )
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
                if (
                    !currentUser.canView()
                )
                {
                    std::cout
                        << "\nAccess denied.\n";

                    break;
                }

                int sku =
                    readInteger(
                        "Enter SKU to search for: "
                    );

                inventory
                    .searchAndDisplay(
                        sku
                    );

                break;
            }


            case 3:
            {
                if (
                    !currentUser.canAdd()
                )
                {
                    std::cout
                        << "\nAccess denied: "
                        << "Regular Users cannot "
                        << "add records.\n";

                    break;
                }

                int sku =
                    readInteger(
                        "Enter SKU: "
                    );

                std::cin.ignore(
                    std::numeric_limits<
                        std::streamsize
                    >::max(),
                    '\n'
                );

                std::string name;

                std::cout
                    << "Enter product name: ";

                std::getline(
                    std::cin,
                    name
                );

                int quantity =
                    readInteger(
                        "Enter quantity: "
                    );

                double price =
                    readDouble(
                        "Enter price: $"
                    );

                Product newProduct(
                    sku,
                    name,
                    quantity,
                    price
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
                        << "The SKU may already exist "
                        << "or inventory may be full.\n";
                }

                break;
            }


            case 4:
            {
                if (
                    !currentUser.canDelete()
                )
                {
                    std::cout
                        << "\nAccess denied: "
                        << "Regular Users cannot "
                        << "delete records.\n";

                    break;
                }

                int sku =
                    readInteger(
                        "Enter SKU to delete: "
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


            default:
            {
                std::cout
                    << "\nInvalid option. "
                    << "Please select 1 through 5.\n";

                break;
            }
        }

    } while (choice != 5);
}


int readInteger(
    const std::string& prompt
)
{
    int value;

    while (true)
    {
        std::cout << prompt;

        if (std::cin >> value)
        {
            return value;
        }

        std::cin.clear();

        std::cin.ignore(
            std::numeric_limits<
                std::streamsize
            >::max(),
            '\n'
        );

        std::cout
            << "Invalid input. "
            << "Please enter a whole number.\n";
    }
}


double readDouble(
    const std::string& prompt
)
{
    double value;

    while (true)
    {
        std::cout << prompt;

        if (std::cin >> value)
        {
            return value;
        }

        std::cin.clear();

        std::cin.ignore(
            std::numeric_limits<
                std::streamsize
            >::max(),
            '\n'
        );

        std::cout
            << "Invalid input. "
            << "Please enter a number.\n";
    }
}
