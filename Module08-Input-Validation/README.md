<div align="center">

# 🛡️ Module 08 — Input Validation & Protecting Data

### 📦 Inventory Manager

[![Module](https://img.shields.io/badge/Module-08-4C8BF5?style=for-the-badge)](./)
[![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![Project](https://img.shields.io/badge/Project-Inventory%20Manager-2ea44f?style=for-the-badge)](#)
[![Validation](https://img.shields.io/badge/Input-Validated-success?style=for-the-badge)](#)
[![Security](https://img.shields.io/badge/Data-Protected-purple?style=for-the-badge)](#)
[![Status](https://img.shields.io/badge/Status-Complete-success?style=for-the-badge)](#)

**Author:** [John Saldivar](https://github.com/johnsaldivar)

</div>

---

# 📖 Overview

Module 8 introduces **input validation and protecting application data**.

A reliable application should not assume that users will always enter valid
information. Before accepting data, the Inventory Manager now checks user input
for:

- Correct data type
- Valid numeric range
- Required fields
- Duplicate identifiers
- Proper date format
- Valid calendar dates

When invalid information is entered, the application displays a useful error
message and allows the user to try again instead of accepting bad data or
terminating unexpectedly.

Module 8 builds directly on the role-based permissions, sorted inventory
records, and binary search introduced in Module 7.

---

# ✅ Assignment Requirements

The Module 8 assignment requires validation to be added to the application.

The program must prevent invalid entries such as:

- Negative values
- Empty names
- Incorrectly formatted dates

The application must also display useful error messages and allow the user to
correct the invalid information.

| Assignment Requirement | Inventory Manager Implementation |
|---|---|
| Validate user input | `InputValidator` class |
| Check numeric types | `getIntInRange()` / `getDoubleInRange()` |
| Reject negative SKU values | SKU range begins at `1` |
| Reject negative quantities | Quantity range begins at `0` |
| Reject invalid prices | Price must be at least `0.01` |
| Reject empty names | `getRequiredString()` |
| Reject whitespace-only names | Input is trimmed before validation |
| Limit product name length | Maximum 50 characters |
| Validate date format | `MM/DD/YYYY` |
| Validate calendar dates | `isValidDate()` |
| Validate leap years | `isLeapYear()` |
| Validate menu choices | Menu range restricted to `1–5` |
| Validate role selection | Role restricted to `1–2` |
| Prevent duplicate SKUs | Binary-search uniqueness check |
| Display useful errors | Specific validation messages |
| Allow the user to retry | Validation loops continue until valid |
| Protect existing role permissions | Admin / Regular User preserved |
| Preserve binary search | `binarySearchBySku()` retained |
| Preserve sorted records | Products remain sorted by SKU |

---

# 🛡️ InputValidator Class

Module 8 introduces a reusable `InputValidator` class.

```cpp
class InputValidator
{
public:
    static int getIntInRange(
        const std::string& prompt,
        int minimum,
        int maximum
    );

    static double getDoubleInRange(
        const std::string& prompt,
        double minimum,
        double maximum
    );

    static std::string getRequiredString(
        const std::string& prompt,
        std::size_t maximumLength
    );

    static std::string getDateMMDDYYYY(
        const std::string& prompt
    );

    static bool isValidDate(
        const std::string& date
    );
};
```

Instead of repeating validation logic throughout `main.cpp`, validation rules
are organized into one reusable component.

This improves:

```text
Reliability
Maintainability
Code Reuse
Data Protection
User Experience
```

---

# 🔢 Integer Validation

Integer input is read as a complete line and then parsed.

```cpp
std::string line;
std::getline(std::cin, line);

std::stringstream parser(line);

int value;
char extra;

if (!(parser >> value) ||
    (parser >> extra))
{
    // Invalid input
}
```

This prevents values such as:

```text
hello
12abc
5.5
```

from being accepted as valid integers.

For example:

```text
Select an option: hello
Invalid input. Please enter a whole number.
```

The application then prompts the user again.

---

# 💲 Decimal Validation

Prices are validated separately as decimal values.

Examples of invalid price input include:

```text
abc
-5
0
12.50abc
```

A valid price must be numeric and fall within the allowed range.

```text
Minimum Price: 0.01
Maximum Price: 1000000.00
```

---

# 📏 Range Validation

After confirming the correct data type, the application checks whether the
value falls within the permitted range.

```cpp
if (value < minimum ||
    value > maximum)
{
    // Reject value
}
```

Examples include:

| Input | Valid Range |
|---|---:|
| Role | `1–2` |
| Menu option | `1–5` |
| SKU | `1–999999` |
| Quantity | `0–1000000` |
| Price | `0.01–1000000.00` |

This prevents values such as negative SKUs, negative quantities, invalid menu
choices, and invalid prices from being accepted.

---

# 📝 Required String Validation

Product names are required.

The application rejects an empty value:

```text
Enter product name:
Invalid input. This field is required and cannot be empty.
```

Input containing only spaces is also rejected because the string is trimmed
before validation.

For example:

```text
"       "
```

is treated as an empty value.

Product names are also limited to a maximum of 50 characters.

---

# 📅 Date Validation

Module 8 adds a `dateAdded` field to each Product.

```cpp
std::string dateAdded;
```

The required date format is:

```text
MM/DD/YYYY
```

Example:

```text
11/01/2026
```

The validation checks more than the appearance of the string.

It verifies:

- Exact length
- Slash positions
- Numeric month
- Numeric day
- Numeric year
- Month range
- Day range
- Year range
- Number of days in each month
- Leap years

---

# ✅ Valid Date Examples

```text
11/01/2026
01/15/2026
12/31/2026
02/29/2024
```

---

# ❌ Invalid Date Examples

```text
13/01/2026
02/30/2026
02/29/2025
11-01-2026
1/1/2026
hello
```

Invalid dates display an error message and the user is allowed to enter a new
value.

Example:

```text
Enter date added (MM/DD/YYYY): 02/29/2025
Invalid date. Use MM/DD/YYYY and enter a real date between 2000 and 2100.

Enter date added (MM/DD/YYYY): 11/01/2026
```

---

# 🗓️ Leap-Year Validation

The validator checks whether February can contain 29 days.

```cpp
bool InputValidator::isLeapYear(int year)
{
    return
        (year % 400 == 0) ||
        (year % 4 == 0 &&
         year % 100 != 0);
}
```

Therefore:

```text
02/29/2024   ✅ Valid
02/29/2025   ❌ Invalid
```

---

# 🔑 Duplicate SKU Protection

SKU is the unique identifier used by the Inventory Manager.

Before accepting a new Product, the application checks whether the requested
SKU already exists.

```cpp
if (inventory.binarySearchBySku(sku) == -1)
{
    // SKU is available
}
```

If a duplicate is entered:

```text
Enter SKU (1-999999): 1001
Invalid SKU. That SKU already exists.
Please try a different SKU.
```

The user must enter another SKU before the Product can be created.

This prevents duplicate identifiers from entering the inventory.

---

# 🔍 Binary Search Preserved

Module 8 continues using the binary-search algorithm introduced in Module 7.

```cpp
int InventorySystem::binarySearchBySku(
    int targetSku
) const
```

Product records continue to remain sorted in ascending SKU order.

Example:

```text
1001
1002
1003
1005
1010
```

Because the records remain sorted, binary search continues to work correctly.

---

# 📊 Sorted Insertion Preserved

New Products are not simply appended to the end of the array.

The Inventory Manager determines where the new SKU belongs and inserts the
Product into the correct location.

Example:

```text
Before:

1001
1002
1005
1010
```

Admin adds:

```text
1003
```

Result:

```text
1001
1002
1003
1005
1010
```

This preserves the sorted ordering required by binary search.

---

# 🔐 Role Permissions Preserved

Module 8 keeps the role-based authorization introduced in Module 7.

```text
Admin
├── View Records      ✅
├── Search Records    ✅
├── Add Records       ✅
└── Delete Records    ✅

Regular User
├── View Records      ✅
├── Search Records    ✅
├── Add Records       ❌
└── Delete Records    ❌
```

Input validation and role authorization perform two different jobs.

```text
Permission Check
      │
      ▼
Can the user perform this action?
      │
      ▼
Input Validation
      │
      ▼
Is the submitted data acceptable?
      │
      ▼
Store / Process Data
```

A user must have permission to perform an action, and the information entered
must also pass validation.

---

# 🔄 Input Validation Flow

```text
                   User Enters Data
                          │
                          ▼
                     Read Full Line
                          │
                          ▼
                    Check Data Type
                          │
                ┌─────────┴─────────┐
                │                   │
             Invalid              Valid
                │                   │
                ▼                   ▼
          Show Error          Check Range
                │                   │
                │          ┌────────┴────────┐
                │          │                 │
                │       Invalid            Valid
                │          │                 │
                ▼          ▼                 ▼
             Retry     Show Error       Check Format
                           │                 │
                           ▼                 ▼
                         Retry        Accept / Store
```

Invalid input never reaches the stored Product record.

---

# 🧱 Product Class Update

The Product class now contains:

```cpp
private:
    int sku;
    std::string name;
    int quantity;
    double price;
    std::string dateAdded;
```

The new `dateAdded` field allows the application to demonstrate date-format
validation while remaining relevant to the Inventory Management System.

---

# 🖥️ Application Menu

```text
========================================
             INVENTORY MENU
========================================
1. View Records
2. Search Record by SKU
3. Add Record
4. Delete Record
5. Exit
```

Menu input is validated.

Example:

```text
Select an option: hello
Invalid input. Please enter a whole number.

Select an option: 9
Invalid range. Enter a value from 1 to 5.

Select an option: 3
```

The program remains running and prompts the user again instead of accepting
invalid information.

---

# 🧪 Add-Record Validation Example

```text
Enter SKU (1-999999): -5
Invalid range. Enter a value from 1 to 999999.

Enter SKU (1-999999): abc
Invalid input. Please enter a whole number.

Enter SKU (1-999999): 1001
Invalid SKU. That SKU already exists. Please try a different SKU.

Enter SKU (1-999999): 1003

Enter product name:
Invalid input. This field is required and cannot be empty.

Enter product name: Engine Cleaner

Enter quantity (0-1000000): -1
Invalid range. Enter a value from 0 to 1000000.

Enter quantity (0-1000000): 4

Enter price (0.01-1000000.00): $-2
Invalid range. Enter a value from 0.01 to 1000000.

Enter price (0.01-1000000.00): $12.50

Enter date added (MM/DD/YYYY): 02/29/2025
Invalid date. Use MM/DD/YYYY and enter a real date between 2000 and 2100.

Enter date added (MM/DD/YYYY): 11/01/2026

Record added successfully in sorted SKU order.
```

---

# 📁 Module Files

```text
Module08-Input-Validation/
│
├── README.md
├── main.cpp
├── Product.h
├── Product.cpp
├── User.h
├── User.cpp
├── InventorySystem.h
├── InventorySystem.cpp
├── InputValidator.h
└── InputValidator.cpp
```

## `main.cpp`

Contains:

- Program entry point
- Role selection
- Application menu
- Permission checks
- Validated Product creation
- Validated search and delete input

## `InputValidator.h` / `InputValidator.cpp`

Contain reusable validation functions for:

- Integer input
- Decimal input
- Numeric ranges
- Required strings
- String length
- Date format
- Calendar dates
- Leap years

## `Product.h` / `Product.cpp`

Contain:

- Product class
- SKU
- Name
- Quantity
- Price
- Date Added
- Product display functionality

## `User.h` / `User.cpp`

Contain:

- User base class
- Admin class
- RegularUser class
- Role-based permissions

## `InventorySystem.h` / `InventorySystem.cpp`

Contain:

- Product storage
- Sorted insertion
- Duplicate SKU protection
- Record deletion
- Record display
- Binary search
- Search result display

---

# 🔗 Connection to Previous Modules

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
```

Module 8 does not replace the previous application features.

It adds a validation layer that protects the information being entered into
those features.

---

# 🧩 Current Architecture

```text
                       INVENTORY MANAGER
                              │
          ┌───────────────────┼───────────────────┐
          │                   │                   │
          ▼                   ▼                   ▼
        User               Product         InputValidator
          │                   │                   │
   ┌──────┴──────┐            │          ┌────────┼────────┐
   │             │            │          │        │        │
   ▼             ▼            ▼          ▼        ▼        ▼
 Admin      RegularUser   Product Data   Type    Range    Format
                               │           │        │        │
                               └───────────┼────────┼────────┘
                                           │
                                           ▼
                                  InventorySystem
                                           │
                                   ┌───────┴───────┐
                                   │               │
                                   ▼               ▼
                             Sorted Records   Binary Search
```

---

# 🧪 Testing

Module 8 was compiled and tested using both valid and intentionally invalid
input.

## Input Validation Tests

- [x] Reject nonnumeric role input
- [x] Reject invalid role numbers
- [x] Reject nonnumeric menu input
- [x] Reject out-of-range menu choices
- [x] Reject negative SKU values
- [x] Reject nonnumeric SKU values
- [x] Reject duplicate SKUs
- [x] Accept a valid unique SKU
- [x] Reject empty Product names
- [x] Reject whitespace-only Product names
- [x] Accept a valid Product name
- [x] Reject negative quantities
- [x] Reject nonnumeric quantities
- [x] Accept a valid quantity
- [x] Reject negative prices
- [x] Reject nonnumeric prices
- [x] Accept a valid price
- [x] Reject incorrect date formats
- [x] Reject impossible calendar dates
- [x] Reject invalid leap-year dates
- [x] Accept valid leap-year dates
- [x] Accept a valid `MM/DD/YYYY` date
- [x] Allow the user to retry after invalid input

---

## Existing Feature Regression Tests

- [x] Admin can view records
- [x] Admin can search records
- [x] Admin can add a validated record
- [x] Admin can delete a record
- [x] Added records remain in sorted SKU order
- [x] Binary search finds newly added records
- [x] Missing SKU returns not found
- [x] Regular User can view records
- [x] Regular User can search records
- [x] Regular User cannot add records
- [x] Regular User cannot delete records
- [x] Application exits normally

---

# ✅ Module 8 Checklist

- [x] Input-validation component created
- [x] Integer type validation implemented
- [x] Decimal type validation implemented
- [x] Range validation implemented
- [x] Required-field validation implemented
- [x] Empty names rejected
- [x] Whitespace-only names rejected
- [x] Negative SKU values rejected
- [x] Negative quantities rejected
- [x] Invalid prices rejected
- [x] Date field added to Product
- [x] Date-format validation implemented
- [x] Calendar-date validation implemented
- [x] Leap-year validation implemented
- [x] Duplicate SKU validation implemented
- [x] Helpful error messages implemented
- [x] Retry loops implemented
- [x] Role permissions preserved
- [x] Sorted records preserved
- [x] Binary search preserved
- [x] Module connected to Inventory Manager
- [x] Program compiled successfully
- [x] Program fully tested
- [x] Module 8 files uploaded to GitHub
- [x] Module 8 completed

---

# 🎉 Module 8 Status

```text
Module:              08
Topic:               Input Validation & Protecting Data

Build:               Successful
Validation Testing:  Passed
Admin Testing:       Passed
User Testing:        Passed

Type Validation:     Implemented
Range Validation:    Implemented
Required Fields:     Implemented
Date Validation:     Implemented
Leap Years:          Implemented
Duplicate SKU Check: Implemented
Retry Logic:         Implemented

Role Permissions:    Preserved
Sorted Records:      Preserved
Binary Search:       Preserved

GitHub Upload:       Complete
Status:              ✅ Complete
```

---

# ▶️ Building & Running

Compile all implementation files together:

```bash
g++ -std=c++17 main.cpp Product.cpp User.cpp InventorySystem.cpp InputValidator.cpp -o inventory_manager
```

For additional compiler warnings:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Product.cpp User.cpp InventorySystem.cpp InputValidator.cpp -o inventory_manager
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

# 🔮 Future Development

Module 8 adds a protection layer before information reaches the main
application.

The Inventory Manager can continue evolving through:

```text
User Input
    │
    ▼
Validation
    │
    ▼
Authorization
    │
    ▼
Classes / Objects
    │
    ▼
Sorted Records
    │
    ▼
Search
    │
    ▼
Persistent File Storage
    │
    ▼
Database
    │
    ▼
Complete Inventory System
```

Future improvements may include:

- Persistent inventory files
- Loading records when the program starts
- Saving records when the program exits
- Database-backed storage
- Additional Product fields
- Record editing
- More advanced user accounts
- Additional permission levels

---

# 🔗 Links

**Developer**  
[John Saldivar](https://github.com/johnsaldivar)

**Course Repository**  
[CPlusPlus-Application-Design](https://github.com/johnsaldivar/CPlusPlus-Application-Design)

**Previous Module**  
[Module 07 — Security, Roles & Binary Search](../Module07-Security-Search/)

**Next Module**  
[Module 09](../Module09-AI-Application/)

---

<div align="center">

## 📦 Inventory Manager

### Module 08 — Input Validation & Protecting Data

**John Saldivar**

![C++](https://img.shields.io/badge/C%2B%2B-Validation%20%7C%20Security-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Validation](https://img.shields.io/badge/Input-Type%20%7C%20Range%20%7C%20Format-success?style=for-the-badge)
![Security](https://img.shields.io/badge/Data-Protected-purple?style=for-the-badge)
![Status](https://img.shields.io/badge/Module-Complete-success?style=for-the-badge)

**Build → Test → Improve → Connect**

</div>
