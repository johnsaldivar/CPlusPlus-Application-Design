#include <iostream>
#include <limits>
#include "InventorySystem.h"
#include "AIInventoryAssistant.h"

int readMenuChoice();
void showWelcome();
void showMenu();

int main()
{
    InventorySystem inventory;
    AIInventoryAssistant aiAssistant;

    inventory.seedData();

    showWelcome();

    int choice = 0;

    do
    {
        showMenu();
        choice = readMenuChoice();

        switch (choice)
        {
            case 1:
                inventory.displayInventory();
                break;

            case 2:
                aiAssistant.generateRestockRecommendations(inventory);
                break;

            case 3:
                aiAssistant.showArchitecture();
                break;

            case 4:
                std::cout << "\nClosing Inventory Manager...\n";
                break;
        }

    } while (choice != 4);

    return 0;
}

void showWelcome()
{
    std::cout << "=============================================\n";
    std::cout << "       INVENTORY MANAGER - MODULE 9\n";
    std::cout << "=============================================\n";
    std::cout << "Using AI to Expand Your Application\n";
}

void showMenu()
{
    std::cout << "\n=============================================\n";
    std::cout << "                 MAIN MENU\n";
    std::cout << "=============================================\n";
    std::cout << "1. View Inventory\n";
    std::cout << "2. AI Restock Recommendations\n";
    std::cout << "3. View AI Architecture\n";
    std::cout << "4. Exit\n";
}

int readMenuChoice()
{
    int choice;

    while (true)
    {
        std::cout << "Select an option: ";

        if (std::cin >> choice && choice >= 1 && choice <= 4)
        {
            return choice;
        }

        std::cout << "Invalid input. Please enter a number from 1 to 4.\n";

        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );
    }
}
