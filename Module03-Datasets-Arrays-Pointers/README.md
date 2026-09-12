<div align="center">

# 📦 Module 03 — Variables, Cin & Cout

### Inventory Manager

[![Module](https://img.shields.io/badge/Module-03-4C8BF5?style=for-the-badge)](./)
[![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![Project](https://img.shields.io/badge/Project-Inventory%20Manager-success?style=for-the-badge)](#)
![Status](https://img.shields.io/badge/Status-Complete-success?style=for-the-badge)
[![GitHub](https://img.shields.io/badge/GitHub-johnsaldivar-181717?style=for-the-badge&logo=github)](https://github.com/johnsaldivar)

**Author:** [John Saldivar](https://github.com/johnsaldivar)

</div>

---

## 📖 Overview

Module 3 focuses on **variables, data types, `cin`, and `cout`**.

For this assignment, I expanded the **Inventory Manager** project by
creating a personalized welcome screen that stores and displays information
using several different C++ data types.

The program asks for the user's name and displays information about the
Inventory Manager, including its application name, version, current item
count, sample pricing information, status code, and application state.

---

## 🎯 Module Objectives

This module demonstrates:

- Creating and initializing variables
- Selecting appropriate C++ data types
- Working with `string`
- Working with `int`
- Working with `double`
- Working with `char`
- Working with `bool`
- Receiving console input using `cin`
- Displaying information using `cout`
- Connecting variables to a larger application
- Creating a personalized console interface

---

## 📦 Connection to the Inventory Manager

Variables represent information that the Inventory Manager needs to
remember.

For example:

```text
Variable
   ↓
Inventory Data
   ↓
Record / Object
   ↓
File or Database
   ↓
Application Feature
```

As the project develops, simple variables will eventually become parts of
inventory records, classes, data structures, files, and database records.

---

## 🧠 Variables Used

The Module 3 program currently uses the following variables:

| Variable | Data Type | Purpose |
|---|---|---|
| `userName` | `string` | Stores the current user's name |
| `applicationName` | `string` | Stores the application name |
| `versionNumber` | `double` | Stores the current application version |
| `currentItemCount` | `int` | Stores the current number of inventory items |
| `sampleItemPrice` | `double` | Demonstrates storing an item price |
| `inventoryStatus` | `char` | Stores a one-character status code |
| `applicationReady` | `bool` | Stores whether the application is ready |

The assignment requires at least six variables and four different C++
data types.

This implementation uses **seven variables** and **five different data
types**.

---

## ⌨️ User Input

The program asks the user to enter their name.

```cpp
cout << "Enter your name: ";
getline(cin, userName);
```

`getline()` allows the program to accept a full name containing spaces,
such as:

```text
John Saldivar
```

The entered name is stored in the `userName` variable.

---

## 🖥️ Console Output

`cout` is used to create a clean welcome screen and display every variable.

Example:

```text
========================================
       WELCOME TO INVENTORY MANAGER
========================================
User: John Saldivar
Application: Inventory Manager
Version: 0.3

--- Application Information ---
Current Item Count: 0
Sample Item Price: $19.99
Inventory Status Code: A
Application Ready: true
```

---

## 🧩 C++ Data Types Practiced

### `string`

Used for text.

```cpp
string applicationName = "Inventory Manager";
```

### `int`

Used for whole numbers.

```cpp
int currentItemCount = 0;
```

### `double`

Used for decimal values.

```cpp
double sampleItemPrice = 19.99;
```

### `char`

Used for a single character.

```cpp
char inventoryStatus = 'A';
```

### `bool`

Used for true/false values.

```cpp
bool applicationReady = true;
```

---

## 📁 Module Files

```text
Module03-Datasets-Arrays-Pointers/
├── README.md
└── inventory_welcome.cpp
```

> **Note:** The module directory names were created during the initial
> repository setup and are being retained for organizational consistency.
> The actual Module 3 assignment is **Variables, Cin, Cout**.

---

## 🧪 Testing

The program should be tested by entering a full name such as:

```text
John Saldivar
```

The program should then:

- Display the entered name correctly
- Display the application name
- Display the version number
- Display the current item count
- Display the sample item price
- Display the inventory status
- Display the application-ready value
- Display the Inventory Manager feature preview
- Exit normally without errors

---

## ✅ Module 3 Checklist

- [x] Personalized welcome screen created
- [x] User name stored in a variable
- [x] Application name stored in a variable
- [x] Version number stored in a variable
- [x] At least six application variables created
- [x] At least four different C++ data types used
- [x] Every variable displayed using `cout`
- [x] User input received using `cin`
- [x] Program compiled successfully
- [x] Program tested successfully
- [x] Module 3 files uploaded to GitHub
- [x] Module 3 completed

---

## 🔮 Future Development

The variables introduced in this module will eventually become part of
real inventory records.

Future versions may store information such as:

```text
Item ID
Item Name
Category
Quantity
Price
Availability
```

Those values can later be organized into arrays, objects, classes, files,
and databases as the Inventory Manager continues to grow.

---

## 🔗 Links

**Developer**  
[John Saldivar](https://github.com/johnsaldivar)

**Course Repository**  
[CPlusPlus-Application-Design](https://github.com/johnsaldivar/CPlusPlus-Application-Design)

**Previous Module**  
[Module 02 — Menus, Switch Case & Application Flow](../Module02-Variables/)

---

<div align="center">

## 📦 Inventory Manager

### Module 03 — Variables, Cin & Cout

**John Saldivar**

![C++](https://img.shields.io/badge/C%2B%2B-Variables%20%7C%20Cin%20%7C%20Cout-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)

**Build → Test → Improve → Connect**

</div>
