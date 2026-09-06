<div align="center">

# 📋 Module 02 — Menus, Switch Case & Application Flow

### Inventory Manager

[![Module](https://img.shields.io/badge/Module-02-4C8BF5?style=for-the-badge)](./)
[![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![Project](https://img.shields.io/badge/Project-Inventory%20Manager-success?style=for-the-badge)](#)
[![GitHub](https://img.shields.io/badge/GitHub-johnsaldivar-181717?style=for-the-badge&logo=github)](https://github.com/johnsaldivar)

**Author:** [John Saldivar](https://github.com/johnsaldivar)

</div>

---

## 📖 Overview

Module 2 introduces application flow using menus, loops, functions, and
`switch/case` statements.

For this course, I am developing an **Inventory Manager** application.

This module establishes the main navigation system that will eventually
connect users to the different features of the application.

---

## 🚀 Inventory Manager

The Inventory Manager will eventually allow users to manage a collection
of inventory records.

Planned functionality includes:

- Adding inventory items
- Viewing inventory
- Searching for items
- Updating existing items
- Removing items
- Persistent data storage in future modules

The functionality will continue to expand as additional C++ concepts are
introduced throughout the course.

---

## 🎯 Module Objectives

This module demonstrates:

- Creating a command-line menu
- Using a loop to keep an application running
- Using `switch/case` for menu navigation
- Separating program behavior into functions
- Validating user input
- Handling invalid menu selections
- Creating the foundation for a larger application

---

## 🖥️ Application Menu

The current application presents the following menu:

```text
========================================
         INVENTORY MANAGER
========================================
1. Add Item
2. View Inventory
3. Search Inventory
4. Update Item
5. Remove Item
6. Exit
========================================
Select an option:
```

The menu continues to display until the user chooses **Exit**.

---

## 🔀 Application Flow

```text
Start Application
       │
       ▼
 Display Main Menu
       │
       ▼
  Get User Choice
       │
       ▼
 Validate Input
       │
       ▼
   switch(choice)
       │
 ┌─────┼─────┬─────┬─────┬─────┐
 ▼     ▼     ▼     ▼     ▼     ▼
Add   View  Search Update Remove Exit
 │     │      │      │      │
 └─────┴──────┴──────┴──────┘
              │
              ▼
        Display Menu Again
```

---

## 🧠 Concepts Practiced

### `switch/case`

The `switch` statement determines which feature should run based on the
user's menu selection.

Example:

```cpp
switch (choice)
{
    case 1:
        addItem();
        break;

    case 2:
        viewInventory();
        break;
}
```

---

### Loops

A `do-while` loop keeps the application running until the user chooses
the Exit option.

```cpp
do
{
    // Application menu
}
while (choice != 6);
```

---

### Functions

Each feature of the application is represented by its own function.

```cpp
void addItem();
void viewInventory();
void searchInventory();
void updateItem();
void removeItem();
```

Separating features into functions makes the program easier to organize
and prepares the application for additional functionality in future
modules.

---

## 🛡️ Input Validation

The application checks whether the user entered valid numeric input.

For example, entering:

```text
hello
```

will not cause the application to stop working.

Instead, the program displays:

```text
Invalid input. Please enter a number from 1 to 6.
```

Numbers outside the available menu range are also rejected.

Example:

```text
Select an option: 20

Invalid option. Please choose a number from 1 to 6.
```

---

## 📁 Module Files

```text
Module02-Menus-Switch-Flow/
├── README.md
└── inventory_manager.cpp
```

### `inventory_manager.cpp`

Contains the current Inventory Manager application and demonstrates:

- Menu design
- Loops
- Switch statements
- Functions
- Input validation

### `README.md`

Documents the Module 2 assignment, application design, and concepts
practiced.

---

## 🧪 Testing

The program was tested with valid and invalid menu selections.

| Input | Expected Result |
|:---:|---|
| `1` | Add Item function |
| `2` | View Inventory function |
| `3` | Search Inventory function |
| `4` | Update Item function |
| `5` | Remove Item function |
| `20` | Invalid option message |
| `hello` | Invalid input message |
| `6` | Exit application |

---

## ✅ Module 2 Checklist

- [x] Main menu created
- [x] At least five menu options included
- [x] Exit option included
- [x] Menu repeats using a loop
- [x] Menu navigation uses `switch/case`
- [x] Each application feature uses a separate function
- [x] Invalid numeric selections are handled
- [x] Invalid non-numeric input is handled
- [x] Program compiled successfully
- [x] Program tested successfully
- [x] Module documentation created

---

## 🔮 Future Development

The current menu provides the structure for the Inventory Manager.

Future modules will gradually add actual inventory functionality behind
each menu option.

For example:

```text
Add Item
   ↓
Store item information
   ↓
View Inventory
   ↓
Search stored records
   ↓
Update / Remove records
   ↓
Save records permanently
```

As new concepts are introduced, the application will evolve from a menu
prototype into a functional inventory management system.

---

## 🔗 Links

**Developer**  
[John Saldivar](https://github.com/johnsaldivar)

**Course Repository**  
[CPlusPlus-Application-Design](https://github.com/johnsaldivar/CPlusPlus-Application-Design)

**Previous Module**  
[Module 01 — Development Environment Setup](../Module01-Setup/)

---

<div align="center">

### 📦 Inventory Manager

**John Saldivar**

*Build → Test → Improve → Connect*

</div>
