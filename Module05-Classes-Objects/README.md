<div align="center">

# 🧩 Module 05 — Records, Headers & Functions

### 📦 Inventory Manager

[![Module](https://img.shields.io/badge/Module-05-4C8BF5?style=for-the-badge)](./)
[![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![Project](https://img.shields.io/badge/Project-Inventory%20Manager-2ea44f?style=for-the-badge)](#)
[![Status](https://img.shields.io/badge/Status-Complete-success?style=for-the-badge)](#)
[![GitHub](https://img.shields.io/badge/GitHub-johnsaldivar-181717?style=for-the-badge&logo=github)](https://github.com/johnsaldivar)

**Author:** [John Saldivar](https://github.com/johnsaldivar)

</div>

---

## 📖 Overview

Module 5 introduces **records, functions, header files, and multi-file
C++ application organization**.

For this assignment, the Inventory Manager was expanded from working
with simple arrays and variables into a system capable of creating and
displaying inventory records.

The application also separates reusable functionality into a custom
header file and source file.

---

# 🎯 Module Objectives

This module demonstrates:

- Creating inventory records
- Creating reusable functions
- Passing arrays to functions
- Passing values by reference
- Returning values from functions
- Separating declarations from implementations
- Creating a custom `.h` header file
- Creating a separate `.cpp` implementation file
- Including standard C++ headers
- Including user-defined headers
- Organizing a larger C++ application
- Calculating information from stored records

---

# 📦 Inventory Record

Each inventory item is represented using an `InventoryRecord`.

```cpp
struct InventoryRecord
{
    std::string itemName;
    int quantity;
    double price;
};
```

Each record contains three fields:

| Field | Type | Purpose |
|---|---|---|
| `itemName` | `string` | Stores the inventory item's name |
| `quantity` | `int` | Stores how many units are available |
| `price` | `double` | Stores the price per unit |

---

# 🧠 Functions

Module 5 divides the Inventory Manager into smaller functions.

## Add Record

```cpp
void addRecord(
    InventoryRecord records[],
    int& recordCount,
    int maxRecords
);
```

This function allows a user to enter a new inventory record.

---

## Display Records

```cpp
void displayRecords(
    const InventoryRecord records[],
    int recordCount
);
```

This function displays all currently stored inventory records.

---

## Calculate Inventory Value

```cpp
double calculateInventoryValue(
    const InventoryRecord records[],
    int recordCount
);
```

This function calculates the total value of the inventory.

The calculation for each item is:

```text
Quantity × Price
```

The values for all records are then added together.

---

# 🧮 Calculation Example

If the inventory contains:

| Item | Quantity | Price |
|---|---:|---:|
| Brake Pads | 5 | $39.99 |
| Oil Filter | 10 | $8.99 |

The calculation is:

```text
Brake Pads
5 × $39.99 = $199.95

Oil Filter
10 × $8.99 = $89.90

Total Inventory Value
$199.95 + $89.90 = $289.85
```

---

# 📁 Multi-File Program Structure

Module 5 separates the Inventory Manager into multiple files.

```text
Module05-Classes-Objects/
│
├── README.md
├── main.cpp
├── InventoryTools.h
└── InventoryTools.cpp
```

### `main.cpp`

Contains the application's entry point and menu.

### `InventoryTools.h`

Contains the inventory record definition and function declarations.

### `InventoryTools.cpp`

Contains the implementation of the inventory functions.

### `README.md`

Documents the assignment and concepts demonstrated.

> **Note:** The module directory name was created during the initial
> repository setup and is retained for organizational consistency.
> The actual Module 5 assignment is **Records, Headers & Functions**.

---

# 📄 Header Files

C++ applications commonly use header files to declare functionality
that may be shared across multiple source files.

The Inventory Manager includes:

```cpp
#include "InventoryTools.h"
```

This is a **user-defined header file**.

The header contains function declarations such as:

```cpp
void displayRecords(
    const InventoryRecord records[],
    int recordCount
);
```

The actual function implementation is located inside:

```text
InventoryTools.cpp
```

---

# 📚 Standard Headers vs User-Defined Headers

The project uses standard C++ headers such as:

```cpp
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
```

These are provided by the C++ standard library.

The project also uses:

```cpp
#include "InventoryTools.h"
```

This header was created specifically for the Inventory Manager.

---

# 🧱 Header Guards

The custom header uses a header guard:

```cpp
#ifndef INVENTORYTOOLS_H
#define INVENTORYTOOLS_H

// declarations

#endif
```

The header guard prevents the contents of the header from being included
multiple times during compilation.

---

# 🖥️ Application Menu

Module 5 uses the following menu:

```text
========================================
            INVENTORY MANAGER
========================================
1. Add Inventory Record
2. Display Inventory Records
3. Calculate Total Inventory Value
4. Exit
========================================
Select an option:
```

Each option calls a separate function.

---

# 🔀 Application Flow

```text
                     main()
                       │
                       ▼
                 Display Menu
                       │
                       ▼
                User Selection
                       │
        ┌──────────────┼──────────────┐
        │              │              │
        ▼              ▼              ▼
   Add Record      Display        Calculate
        │           Records        Total Value
        │              │              │
        └──────────────┼──────────────┘
                       │
                       ▼
                 Return to Menu
                       │
                       ▼
                     Exit
```

---

# 🔗 Connection to Previous Modules

The Inventory Manager continues to build upon previous work.

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
Variables, Cin & Cout
        │
        ▼
Module 04
Datasets, Arrays & Pointers
        │
        ▼
Module 05
Records, Headers & Functions
```

Module 5 combines several earlier concepts into a more organized
application.

---

# 🧩 Application Architecture

The application is beginning to separate different responsibilities.

```text
                 INVENTORY MANAGER
                        │
         ┌──────────────┴──────────────┐
         │                             │
         ▼                             ▼
      main.cpp                 InventoryTools.h
         │                             │
         │                      Record Definition
         │                    Function Declarations
         │                             │
         └──────────────┬──────────────┘
                        │
                        ▼
                InventoryTools.cpp
                        │
                 Function Logic
                        │
          ┌─────────────┼─────────────┐
          │             │             │
          ▼             ▼             ▼
        Add          Display       Calculate
       Record        Records         Value
```

This organization allows the program to remain manageable as additional
features are added.

---

# 🧪 Testing

The Module 5 application should be tested by:

- Starting with an empty inventory
- Displaying records while the inventory is empty
- Adding multiple inventory records
- Displaying the stored records
- Verifying item names
- Verifying quantities
- Verifying prices
- Calculating the total inventory value
- Confirming the calculated result
- Testing an invalid menu number
- Testing nonnumeric menu input
- Exiting normally
- Confirming there are no compilation errors
- Confirming there are no runtime errors

---

# ✅ Module 5 Checklist

- [x] Inventory record structure created
- [x] Record contains name, quantity, and price
- [x] Add-record function created
- [x] Display-records function created
- [x] Calculation function created
- [x] Custom header file created
- [x] Function declarations moved into header
- [x] Functions implemented in separate `.cpp` file
- [x] Standard C++ headers used
- [x] User-defined header used
- [x] Inventory array created
- [x] Records passed to functions
- [x] Calculation returns a result
- [x] Application connected to Inventory Manager
- [ ] Program compiled successfully
- [ ] Program tested successfully
- [ ] Module 5 files uploaded to GitHub
- [ ] Module 5 completed

---

# 🔮 Future Development

Module 5 creates a more maintainable project structure.

Future modules can continue expanding the Inventory Manager without
placing all application logic inside `main.cpp`.

The current progression is:

```text
Data
  │
  ▼
Record
  │
  ▼
Functions
  │
  ▼
Header / Source Separation
  │
  ▼
Reusable Components
  │
  ▼
Larger Application
```

Later modules may expand these records using:

- Classes
- Objects
- Files
- Databases
- Searching
- Validation
- More advanced data structures

---

# 🔗 Links

**Developer**  
[John Saldivar](https://github.com/johnsaldivar)

**Course Repository**  
[CPlusPlus-Application-Design](https://github.com/johnsaldivar/CPlusPlus-Application-Design)

**Previous Module**  
[Module 04 — Datasets, Arrays & Pointers](../Module04-Functions-Headers/)

---

<div align="center">

## 📦 Inventory Manager

### Module 05 — Records, Headers & Functions

**John Saldivar**

![C++](https://img.shields.io/badge/C%2B%2B-Headers%20%7C%20Functions-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Architecture](https://img.shields.io/badge/Architecture-Multi--File-success?style=for-the-badge)

**Build → Test → Improve → Connect**

</div>
