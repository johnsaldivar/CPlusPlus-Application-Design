#include <iostream>
#include "AIInventoryAssistant.h"

AIRecommendation AIInventoryAssistant::analyzeProduct(
    const Product& product
) const
{
    AIRecommendation result;

    if (product.getQuantity() <= 2)
    {
        result.classification = "CRITICAL";
        result.recommendation = "Restock immediately";
        result.explanation =
            "Inventory is extremely low and may run out soon.";
    }
    else if (product.getQuantity() <= 5)
    {
        result.classification = "RESTOCK SOON";
        result.recommendation = "Place a restock order soon";
        result.explanation =
            "Inventory is below the preferred stock level.";
    }
    else if (product.getQuantity() <= 10)
    {
        result.classification = "MONITOR";
        result.recommendation = "Monitor inventory level";
        result.explanation =
            "Inventory is acceptable but should be watched.";
    }
    else
    {
        result.classification = "HEALTHY";
        result.recommendation = "No restock needed";
        result.explanation =
            "Current inventory appears sufficient.";
    }

    return result;
}


bool AIInventoryAssistant::validateRecommendation(
    const AIRecommendation& result
) const
{
    bool knownClassification =
        result.classification == "CRITICAL" ||
        result.classification == "RESTOCK SOON" ||
        result.classification == "MONITOR" ||
        result.classification == "HEALTHY";

    return
        knownClassification &&
        !result.recommendation.empty() &&
        !result.explanation.empty();
}

void AIInventoryAssistant::generateRestockRecommendations(
    const InventorySystem& inventory
) const
{
    std::cout << "\n=============================================================\n";
    std::cout << "             AI RESTOCK RECOMMENDATION ASSISTANT\n";
    std::cout << "=============================================================\n";

    std::cout
        << "Mock AI prototype: product quantity is analyzed and classified\n"
        << "to demonstrate how an AI service could return recommendations.\n\n";

    for (int i = 0; i < inventory.getProductCount(); i++)
    {
        const Product& product = inventory.getProduct(i);
        AIRecommendation result = analyzeProduct(product);

        if (!validateRecommendation(result))
        {
            std::cout
                << "AI result could not be validated for SKU "
                << product.getSku()
                << ".\n";
            std::cout
                << "-------------------------------------------------------------\n";
            continue;
        }

        std::cout << "SKU: " << product.getSku() << '\n';
        std::cout << "Product: " << product.getName() << '\n';
        std::cout << "Quantity: " << product.getQuantity() << '\n';
        std::cout << "AI Classification: " << result.classification << '\n';
        std::cout << "Recommendation: " << result.recommendation << '\n';
        std::cout << "Explanation: " << result.explanation << '\n';
        std::cout << "-------------------------------------------------------------\n";
    }

    std::cout
        << "\nPrototype note: In a production version, this component could\n"
        << "send inventory data to a trained AI model or external AI service\n"
        << "and validate the returned result before displaying it.\n";
}

void AIInventoryAssistant::showArchitecture() const
{
    std::cout << "\n=============================================================\n";
    std::cout << "                    AI FEATURE ARCHITECTURE\n";
    std::cout << "=============================================================\n\n";

    std::cout << "C++ Inventory Manager\n";
    std::cout << "        |\n";
    std::cout << "        +--> User selects AI Restock Recommendations\n";
    std::cout << "        |\n";
    std::cout << "        +--> InventorySystem prepares Product data\n";
    std::cout << "        |\n";
    std::cout << "        +--> AIInventoryAssistant / Future AI Service\n";
    std::cout << "        |\n";
    std::cout << "        +--> Receive classification + recommendation\n";
    std::cout << "        |\n";
    std::cout << "        +--> Validate result\n";
    std::cout << "        |\n";
    std::cout << "        +--> Display recommendation to user\n\n";

    std::cout << "Data required by the AI feature:\n";
    std::cout << "- Product SKU\n";
    std::cout << "- Product name\n";
    std::cout << "- Current quantity\n";
    std::cout << "- Product price\n\n";

    std::cout << "A future version could also use:\n";
    std::cout << "- Historical sales\n";
    std::cout << "- Restock history\n";
    std::cout << "- Supplier lead time\n";
    std::cout << "- Seasonal demand\n";
    std::cout << "- Inventory trends\n";
}
