<div align="center">

# 🤖 Module 09 — Using AI to Expand Your Application

### 📦 Inventory Manager — AI Restock Recommendation Assistant

[![Module](https://img.shields.io/badge/Module-09-4C8BF5?style=for-the-badge)](./)
[![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![Project](https://img.shields.io/badge/Project-Inventory%20Manager-2ea44f?style=for-the-badge)](#)
[![Feature](https://img.shields.io/badge/AI-Restock%20Recommendations-purple?style=for-the-badge)](#)
[![Prototype](https://img.shields.io/badge/AI-Mock%20Prototype-orange?style=for-the-badge)](#)
[![Status](https://img.shields.io/badge/Status-Ready%20for%20Upload-blue?style=for-the-badge)](#)

**Author:** [John Saldivar](https://github.com/johnsaldivar)

**Build → Test → Improve → Connect**

</div>

---

# 📖 Overview

Module 9 explores how artificial intelligence can become a feature inside an
existing C++ application rather than only being used as a tool to write code.

For this assignment, the Inventory Manager adds one AI-focused feature:

> **AI Restock Recommendation Assistant**

The feature analyzes inventory information and provides a classification,
recommendation, and explanation for each Product.

Example classifications include:

```text
CRITICAL
RESTOCK SOON
MONITOR
HEALTHY
```

Because a live AI service is not required for the assignment, this module uses
a **mock AI prototype**. The prototype uses deterministic recommendation rules
to simulate the type of structured result a future AI model or external AI
service could return.

The program clearly identifies this as a prototype rather than a trained
machine-learning model.

---

# ✅ Assignment Requirements

The Module 9 assignment asks the student to:

1. Choose one AI-powered feature for the existing application.
2. Describe what the feature does.
3. Describe what data the feature would need.
4. Describe what the user would see.
5. Explain where AI fits into the current application architecture.
6. Build a mock version or prototype if a live AI service is not available.

This project directly addresses every requirement.

| Assignment Requirement | Inventory Manager Implementation |
|---|---|
| Choose one AI feature | AI Restock Recommendation Assistant |
| Explain what it does | Classifies inventory and recommends restocking actions |
| Identify required data | SKU, product name, quantity, price |
| Explain user output | Classification, recommendation, explanation |
| Show architecture placement | `AIInventoryAssistant` between inventory data and displayed result |
| Prepare data | `InventorySystem` supplies `Product` objects |
| AI/model step | `AIInventoryAssistant::analyzeProduct()` |
| Receive result | `AIRecommendation` structure |
| Validate result | `validateRecommendation()` |
| Display result | `generateRestockRecommendations()` |
| Build prototype | Working C++ mock AI prototype |

---

# 🤖 Selected AI Feature

## AI Restock Recommendation Assistant

The selected feature helps an inventory user decide which Products may need to
be reordered.

For each Product, the assistant returns:

```text
Classification
Recommendation
Explanation
```

Example:

```text
SKU: 1001
Product: Brake Pads
Quantity: 2
AI Classification: CRITICAL
Recommendation: Restock immediately
Explanation: Inventory is extremely low and may run out soon.
```

The prototype demonstrates the same data flow that could later be connected to
a real AI service.

---

# 🎯 What the Feature Does

The AI Restock Recommendation Assistant answers the question:

> Which inventory Products should receive attention or be restocked?

The prototype currently classifies Products into four categories.

| Quantity | Classification | Recommendation |
|---:|---|---|
| `0–2` | `CRITICAL` | Restock immediately |
| `3–5` | `RESTOCK SOON` | Place a restock order soon |
| `6–10` | `MONITOR` | Monitor inventory level |
| `11+` | `HEALTHY` | No restock needed |

These rules are used only to demonstrate the mock AI feature.

A future real AI implementation could replace the rules with predictions based
on historical inventory and sales information.

---

# 📊 Data the AI Feature Needs

The current prototype receives information already stored by the Inventory
Manager.

The following Product fields are used:

```text
Product SKU
Product Name
Current Quantity
Product Price
```

Example:

```text
SKU:       1005
Product:   Air Filter
Quantity:  4
Price:     $14.49
```

---

# 🔮 Data a Future AI Version Could Use

A production AI feature could use additional information such as:

- Historical sales
- Daily or weekly demand
- Previous restock dates
- Supplier lead times
- Seasonal demand
- Product popularity
- Inventory trends
- Sales velocity
- Purchase-order history

With this information, a model could potentially predict future demand instead
of relying only on current quantity.

---

# 👀 What the User Sees

The AI feature is available directly from the Inventory Manager menu.

```text
=============================================
                 MAIN MENU
=============================================
1. View Inventory
2. AI Restock Recommendations
3. View AI Architecture
4. Exit
```

Selecting:

```text
2. AI Restock Recommendations
```

displays a recommendation for every Product.

Example:

```text
=============================================================
             AI RESTOCK RECOMMENDATION ASSISTANT
=============================================================

SKU: 1005
Product: Air Filter
Quantity: 4
AI Classification: RESTOCK SOON
Recommendation: Place a restock order soon
Explanation: Inventory is below the preferred stock level.
```

---

# 🧠 AIRecommendation Result

The prototype stores the AI-style result in a structure.

```cpp
struct AIRecommendation
{
    std::string classification;
    std::string recommendation;
    std::string explanation;
};
```

This creates a clear interface between the AI component and the rest of the
application.

A future live AI service could return similar fields.

---

# 🏗️ AIInventoryAssistant Class

The AI feature is isolated inside its own class.

```cpp
class AIInventoryAssistant
{
private:
    bool validateRecommendation(
        const AIRecommendation& result
    ) const;

public:
    AIRecommendation analyzeProduct(
        const Product& product
    ) const;

    void generateRestockRecommendations(
        const InventorySystem& inventory
    ) const;

    void showArchitecture() const;
};
```

This keeps AI-related logic separate from Product storage and the main
application flow.

---

# 🔬 Mock AI Analysis

The mock prototype uses Product quantity to generate a recommendation.

```cpp
if (product.getQuantity() <= 2)
{
    result.classification = "CRITICAL";
    result.recommendation = "Restock immediately";
}
else if (product.getQuantity() <= 5)
{
    result.classification = "RESTOCK SOON";
    result.recommendation = "Place a restock order soon";
}
else if (product.getQuantity() <= 10)
{
    result.classification = "MONITOR";
    result.recommendation = "Monitor inventory level";
}
else
{
    result.classification = "HEALTHY";
    result.recommendation = "No restock needed";
}
```

This is a deterministic prototype rather than a trained AI model.

Its purpose is to demonstrate:

```text
Application Data
      │
      ▼
AI Component
      │
      ▼
Structured Result
      │
      ▼
Result Validation
      │
      ▼
User Recommendation
```

---

# ✅ AI Result Validation

The conceptual architecture for Module 9 includes validating the result before
presenting it to the user.

The prototype implements this with:

```cpp
bool AIInventoryAssistant::validateRecommendation(
    const AIRecommendation& result
) const
```

The function verifies that:

- The classification is an expected category.
- The recommendation is not empty.
- The explanation is not empty.

Expected classifications are:

```text
CRITICAL
RESTOCK SOON
MONITOR
HEALTHY
```

If a result does not pass validation, it is not displayed as a valid
recommendation.

This demonstrates an important future AI integration rule:

> AI output should be checked before the application trusts or displays it.

---

# 🧩 AI Architecture

The prototype follows the Module 9 conceptual flow.

```text
C++ Inventory Manager
        │
        ▼
User Request
        │
        ▼
Prepare Inventory Data
        │
        ▼
AIInventoryAssistant
Mock AI / Future AI Service
        │
        ▼
Receive AIRecommendation
        │
        ▼
Validate Result
        │
        ▼
Display Recommendation
```

---

# 🔌 Where AI Fits in the Application

The existing application already contains Product data and an InventorySystem.

Module 9 adds an AI layer:

```text
                     INVENTORY MANAGER
                            │
             ┌──────────────┴──────────────┐
             │                             │
             ▼                             ▼
       InventorySystem              User Interface
             │
             ▼
        Product Data
             │
             ▼
     AIInventoryAssistant
             │
             ▼
       AIRecommendation
             │
             ▼
      Validate AI Result
             │
             ▼
        Display Result
```

The AI component does not replace the inventory application. It uses the data
already stored by the Inventory Manager to provide an additional feature.

---

# 🔄 Future Live AI Architecture

A future production version could replace the mock analysis with an external
AI service or trained model.

```text
C++ Inventory Manager
        │
        ▼
Prepare Product Data
        │
        ▼
Create AI Request
        │
        ▼
AI Service / Model
        │
        ▼
Receive Response
        │
        ▼
Parse Response
        │
        ▼
Validate Response
        │
        ▼
Display Recommendation
```

The rest of the Inventory Manager could remain largely unchanged.

---

# ⚠️ Prototype vs. Live AI

This project intentionally uses a mock prototype.

## Current Module 9 Prototype

```text
C++ Rules
    │
    ▼
Classification
    │
    ▼
Recommendation
```

## Possible Future Version

```text
Inventory History
        │
        ▼
AI Model / Service
        │
        ▼
Demand Prediction
        │
        ▼
Restock Recommendation
```

The prototype requires no:

- API key
- Internet connection
- Paid AI service
- Hosted machine-learning model

This keeps the assignment reproducible and self-contained.

---

# 📦 Product Class

Inventory information is represented using the `Product` class.

```cpp
class Product
{
private:
    int sku;
    std::string name;
    int quantity;
    double price;

public:
    Product();
    Product(
        int sku,
        const std::string& name,
        int quantity,
        double price
    );

    int getSku() const;
    std::string getName() const;
    int getQuantity() const;
    double getPrice() const;
};
```

The Product class supplies the information analyzed by the AI prototype.

---

# 🗃️ InventorySystem

`InventorySystem` stores the Product objects used in the prototype.

Sample inventory:

```text
1001 — Brake Pads       — Quantity 2
1002 — Oil Filter       — Quantity 10
1005 — Air Filter       — Quantity 4
1010 — Spark Plugs      — Quantity 15
1015 — Engine Cleaner   — Quantity 7
```

The sample quantities intentionally represent several inventory conditions so
all recommendation classifications can be demonstrated.

---

# 🧪 Example AI Results

## Critical

```text
SKU: 1001
Product: Brake Pads
Quantity: 2
AI Classification: CRITICAL
Recommendation: Restock immediately
Explanation: Inventory is extremely low and may run out soon.
```

## Restock Soon

```text
SKU: 1005
Product: Air Filter
Quantity: 4
AI Classification: RESTOCK SOON
Recommendation: Place a restock order soon
Explanation: Inventory is below the preferred stock level.
```

## Monitor

```text
SKU: 1015
Product: Engine Cleaner
Quantity: 7
AI Classification: MONITOR
Recommendation: Monitor inventory level
Explanation: Inventory is acceptable but should be watched.
```

## Healthy

```text
SKU: 1010
Product: Spark Plugs
Quantity: 15
AI Classification: HEALTHY
Recommendation: No restock needed
Explanation: Current inventory appears sufficient.
```

---

# 🖥️ Application Menu

```text
=============================================
                 MAIN MENU
=============================================
1. View Inventory
2. AI Restock Recommendations
3. View AI Architecture
4. Exit
```

### Option 1 — View Inventory

Displays the Product records.

### Option 2 — AI Restock Recommendations

Runs the mock AI analysis and displays recommendations.

### Option 3 — View AI Architecture

Displays the data requirements and explains where the AI component fits in the
application.

### Option 4 — Exit

Closes the application.

---

# 🔄 Application Flow

```text
                    Program Starts
                          │
                          ▼
                        main()
                          │
                          ▼
                 Create InventorySystem
                          │
                          ▼
                    Seed Product Data
                          │
                          ▼
              Create AIInventoryAssistant
                          │
                          ▼
                       Main Menu
                          │
          ┌───────────────┼──────────────────┐
          │               │                  │
          ▼               ▼                  ▼
     View Inventory   AI Recommendations   Architecture
                          │
                          ▼
                  Prepare Product Data
                          │
                          ▼
                     Analyze Product
                          │
                          ▼
                 AIRecommendation Result
                          │
                          ▼
                    Validate Result
                          │
                          ▼
                   Display to User
```

---

# 🔗 Connection to Previous Modules

Module 9 continues the progression of the Inventory Manager.

```text
Module 01
Development Environment
        │
        ▼
Module 02
Menus & Application Flow
        │
        ▼
Module 03
Variables & Input/Output
        │
        ▼
Module 04
Datasets, Arrays & Pointers
        │
        ▼
Module 05
Records, Headers & Functions
        │
        ▼
Module 06
Classes & Objects
        │
        ▼
Module 07
Security, Roles & Binary Search
        │
        ▼
Module 08
Input Validation & Protecting Data
        │
        ▼
Module 09
AI Application Feature
```

The project has progressed from storing and protecting inventory data to using
that data as input for an AI-oriented feature.

---

# 📁 Module Files

```text
Module09-AI-Application/
│
├── README.md
├── main.cpp
├── Product.h
├── Product.cpp
├── InventorySystem.h
├── InventorySystem.cpp
├── AIInventoryAssistant.h
└── AIInventoryAssistant.cpp
```

### `main.cpp`

Contains:

- Program entry point
- Main menu
- Menu validation
- Inventory display option
- AI recommendation option
- AI architecture option

### `Product.h` / `Product.cpp`

Contain:

- Product class
- SKU
- Product name
- Quantity
- Price
- Getters

### `InventorySystem.h` / `InventorySystem.cpp`

Contain:

- Product array
- Sample data
- Inventory display
- Product access for AI analysis

### `AIInventoryAssistant.h` / `AIInventoryAssistant.cpp`

Contain:

- AI mock prototype
- Recommendation classifications
- `AIRecommendation`
- Result validation
- Recommendation display
- Architecture explanation

---

# 🧪 Testing

The exact Module 9 source was compiled with warnings enabled and tested.

## Build Tests

- [x] `main.cpp` compiles
- [x] `Product.cpp` compiles
- [x] `InventorySystem.cpp` compiles
- [x] `AIInventoryAssistant.cpp` compiles
- [x] Multi-file application links successfully
- [x] No runtime errors during test flow

## Menu Tests

- [x] Inventory option displays Product records
- [x] AI Recommendation option runs successfully
- [x] Architecture option displays successfully
- [x] Exit option closes normally
- [x] Nonnumeric menu input is rejected
- [x] Out-of-range menu input is rejected
- [x] User can retry invalid menu input

## AI Prototype Tests

- [x] Quantity `2` returns `CRITICAL`
- [x] Quantity `4` returns `RESTOCK SOON`
- [x] Quantity `7` returns `MONITOR`
- [x] Quantity `10` returns `MONITOR`
- [x] Quantity `15` returns `HEALTHY`
- [x] Recommendation text displays
- [x] Explanation text displays
- [x] Results are validated before display

---

# ✅ Module 9 Checklist

- [x] One AI-powered feature selected
- [x] AI feature connected to Inventory Manager
- [x] Feature purpose documented
- [x] Required data documented
- [x] User-visible output documented
- [x] AI location in application architecture documented
- [x] Mock AI prototype created
- [x] `AIInventoryAssistant` class created
- [x] `AIRecommendation` structure created
- [x] Product data prepared for analysis
- [x] Mock recommendation logic implemented
- [x] AI result validation implemented
- [x] Results displayed to user
- [x] Future live-AI architecture documented
- [x] Prototype limitations clearly identified
- [x] Multi-file program compiled successfully
- [x] Invalid menu input tested
- [x] Recommendation categories tested
- [ ] Module 9 files uploaded to GitHub
- [ ] Module 9 completed in repository

---

# ▶️ Building & Running

Compile all implementation files:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic \
main.cpp Product.cpp InventorySystem.cpp AIInventoryAssistant.cpp \
-o inventory_manager
```

### Windows

```bash
inventory_manager.exe
```

### macOS / Linux

```bash
./inventory_manager
```

---

# 🚀 Future Improvements

A future version could replace the mock prototype with a live AI service or
trained model.

Possible improvements include:

- Predict demand from historical sales
- Recommend reorder quantities
- Detect unusual inventory changes
- Identify slow-moving inventory
- Generate natural-language inventory summaries
- Allow natural-language inventory search
- Analyze seasonal trends
- Compare supplier lead times
- Explain why a restock is recommended

---

# 🧠 Responsible AI Design

A future AI-powered Inventory Manager should not blindly trust model output.

```text
Prepare Data
    │
    ▼
Send Request
    │
    ▼
Receive AI Result
    │
    ▼
Validate Result
    │
    ▼
Apply Business Rules
    │
    ▼
Display Recommendation
    │
    ▼
Human Makes Final Decision
```

AI recommendations should assist the user rather than silently modify critical
inventory data without review.

---

# 🔗 Links

**Developer**  
[John Saldivar](https://github.com/johnsaldivar)

**Course Repository**  
[CPlusPlus-Application-Design](https://github.com/johnsaldivar/CPlusPlus-Application-Design)

**Previous Module**  
[Module 08 — Input Validation & Protecting Data](../Module08-Input-Validation/)

**Next Module**  
[Module 10](../Module10-Future-of-AI/)

---

<div align="center">

## 📦 Inventory Manager

### Module 09 — Using AI to Expand Your Application

**AI Restock Recommendation Assistant**

**John Saldivar**

![C++](https://img.shields.io/badge/C%2B%2B-AI%20Application-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![AI](https://img.shields.io/badge/AI-Restock%20Recommendations-purple?style=for-the-badge)
![Prototype](https://img.shields.io/badge/Prototype-Mock%20AI-orange?style=for-the-badge)
![Architecture](https://img.shields.io/badge/Architecture-Validated%20Results-success?style=for-the-badge)

**Build → Test → Improve → Connect**

</div>
