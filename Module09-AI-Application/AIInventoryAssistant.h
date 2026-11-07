#ifndef AIINVENTORYASSISTANT_H
#define AIINVENTORYASSISTANT_H

#include <string>
#include "InventorySystem.h"
#include "Product.h"

struct AIRecommendation
{
    std::string classification;
    std::string recommendation;
    std::string explanation;
};

class AIInventoryAssistant
{
private:
    bool validateRecommendation(const AIRecommendation& result) const;

public:
    AIRecommendation analyzeProduct(const Product& product) const;
    void generateRestockRecommendations(const InventorySystem& inventory) const;
    void showArchitecture() const;
};

#endif
