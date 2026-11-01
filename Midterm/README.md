<div align="center">

# C++ Midway Project

## Inventory Management System

**John Saldivar**

![C++](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Project](https://img.shields.io/badge/Project-Inventory%20Management%20System-2ea44f?style=for-the-badge)
![Search](https://img.shields.io/badge/Search-Binary%20Search-orange?style=for-the-badge)
![Storage](https://img.shields.io/badge/Storage-File%20I%2FO-purple?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-success?style=for-the-badge)

</div>

---

# Project Overview

This Midway Project is a command-line **Inventory Management System** written in C++.
It builds on the concepts developed throughout the first half of the course and combines
them into one larger application.

The program can:

- Load inventory records from `inventory.txt`
- Display inventory records
- Search for a product by SKU using binary search
- Add records while preserving sorted SKU order
- Delete records
- Save inventory records to a text file
- Validate user input
- Restrict actions using Admin and Regular User roles
- Demonstrate C++ data type sizes
- Demonstrate pointers and dynamic memory

---

# Assignment Requirement Mapping

| Required Concept | Project Implementation |
|---|---|
| Data types and data sizes | `int`, `double`, `bool`, `char`, strings, and `sizeof()` display |
| File types | `inventory.txt` |
| Pointers | `Product* products`, `User* currentUser` |
| Dynamic memory | `new Product[capacity]` and `delete[] products` |
| Arrays | Dynamically allocated Product array and fixed validation arrays |
| Binary search | `binarySearchBySku()` |
| Strings | Product names, usernames, dates, file parsing |
| File I/O | `ifstream` and `ofstream` |
| At least two classes | `Product`, `InventorySystem`, `User`, `Admin`, `RegularUser`, `InputValidator` |

---

# Project Structure

```text
Midterm/
├── README.md
├── main.cpp
├── Product.h
├── Product.cpp
├── User.h
├── User.cpp
├── InventorySystem.h
├── InventorySystem.cpp
├── InputValidator.h
├── InputValidator.cpp
├── inventory.txt
└── output.pdf
```

---

# Dynamic Memory and Pointers

The Inventory System stores Products in a dynamically allocated array:

```cpp
Product* products;
```

Memory is allocated in the constructor:

```cpp
products = new Product[capacity];
```

and released in the destructor:

```cpp
delete[] products;
```

The program includes a menu option that displays the Product array's pointer address,
capacity, record count, and first SKU accessed through the pointer.

---

# File I/O

Inventory records are stored in:

```text
inventory.txt
```

Each record uses this format:

```text
SKU|Product Name|Quantity|Price|Date Added
```

Example:

```text
1001|Brake Pads|5|39.99|10/01/2026
```

The project uses:

```cpp
std::ifstream
std::ofstream
```

Records are loaded when the program starts and saved when records change or the
application exits.

---

# Binary Search

Records remain sorted by SKU so the application can use binary search.

```cpp
int InventorySystem::binarySearchBySku(int targetSku) const
```

Binary search repeatedly eliminates half of the remaining search area until the SKU is
found or the search range is empty.

---

# Classes

The project uses several classes.

## Product

Represents one inventory record.

## InventorySystem

Manages the dynamically allocated Product array, file I/O, sorted insertion, deletion,
and binary search.

## User

Abstract base class for application roles.

## Admin / RegularUser

Derived classes implementing role-based permissions.

## InputValidator

Provides reusable validation for integers, decimal values, required strings, ranges, and
dates.

---

# Input Validation

The program rejects invalid information and allows the user to try again.

Examples include:

- Nonnumeric menu selections
- Out-of-range menu selections
- Negative SKUs
- Duplicate SKUs
- Empty Product names
- Negative quantities
- Invalid prices
- Incorrect date formats
- Impossible calendar dates

---

# Role-Based Permissions

```text
Admin
├── View Records      Yes
├── Search Records    Yes
├── Add Records       Yes
└── Delete Records    Yes

Regular User
├── View Records      Yes
├── Search Records    Yes
├── Add Records       No
└── Delete Records    No
```

---

# Building

Compile all implementation files together:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Product.cpp User.cpp InventorySystem.cpp InputValidator.cpp -o inventory_manager
```

Run on macOS/Linux:

```bash
./inventory_manager
```

Run on Windows:

```bash
inventory_manager.exe
```

---

# Testing Status

- [x] Compiles successfully with C++17
- [x] Loads inventory from text file
- [x] Saves inventory to text file
- [x] Displays sorted records
- [x] Binary search finds existing SKU
- [x] Missing SKU handled correctly
- [x] Admin can add records
- [x] Added records remain sorted
- [x] Admin can delete records
- [x] Regular User cannot add records
- [x] Regular User cannot delete records
- [x] Invalid numeric input is rejected
- [x] Data type sizes are displayed
- [x] Pointer address is displayed
- [x] Dynamic array allocation demonstrated
- [x] Program exits normally

---

# Status

```text
Project:         C++ Midway Project
Application:     Inventory Management System
Developer:       John Saldivar
Build:           Successful
Testing:         Passed
File I/O:        Implemented
Dynamic Memory:  Implemented
Pointers:        Implemented
Arrays:          Implemented
Binary Search:   Implemented
Classes:         Implemented
Status:          Complete
```
