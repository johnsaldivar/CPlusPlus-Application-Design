<div align="center">

# 🧱 Module 06 — Creating Classes & Objects

### 📦 Inventory Manager

[![Module](https://img.shields.io/badge/Module-06-4C8BF5?style=for-the-badge)](./)
[![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![Project](https://img.shields.io/badge/Project-Inventory%20Manager-2ea44f?style=for-the-badge)](#)
[![Topic](https://img.shields.io/badge/Topic-Classes%20%26%20Objects-purple?style=for-the-badge)](#)
[![Status](https://img.shields.io/badge/Status-Complete-success?style=for-the-badge)](#)

**Author:** [John Saldivar](https://github.com/johnsaldivar)

</div>

---

## 📖 Overview

Module 6 introduces one of the most important concepts in C++:
**classes and objects**.

For this assignment, the Inventory Manager now uses a custom `Product`
class to represent an inventory item.

The class combines related data and behavior into one reusable component.

Instead of storing product information in unrelated variables, each
`Product` object now manages its own:

- Name
- SKU
- Quantity
- Price

The class also provides functions for displaying product information,
calculating inventory value, retrieving information, and updating values.

---

# ✅ Assignment Requirements

The Module 6 assignment requires:

1. Create a class that represents something in the application.
2. Include private data members.
3. Create a constructor.
4. Create at least two member functions.
5. Include at least one getter or setter.
6. Create at least two objects from the class.
7. Display information from both objects.
8. Create a `main()` function that coordinates the application.
9. Call at least three functions from `main()`.
10. Explain or diagram the application's flow.

This project satisfies every requirement.

| Assignment Requirement | Inventory Manager Implementation |
|---|---|
| Application class | `Product` |
| Private data members | `name`, `sku`, `quantity`, `price` |
| Constructor | `Product(...)` |
| Member function #1 | `displayProduct()` |
| Member function #2 | `calculateInventoryValue()` |
| Getter | `getName()`, `getQuantity()`, `getPrice()` |
| Setter | `setQuantity()`, `setPrice()` |
| Object #1 | `product1` |
| Object #2 | `product2` |
| Display objects | `displayProduct()` |
| `this` pointer | Used in constructor and setters |
| Function #1 from `main()` | `showWelcome()` |
| Function #2 from `main()` | `showMenu()` |
| Function #3 from `main()` | `demonstrateProducts()` |

---

# 📦 Product Class

The Inventory Manager uses a `Product` class.

```cpp
class Product
{
private:
    std::string name;
    int sku;
    int quantity;
    double price;

public:
    Product(
        const std::string& name,
        int sku,
        int quantity,
        double price
    );

    void displayProduct() const;
    double calculateInventoryValue() const;

    std::string getName() const;
    int getQuantity() const;
    double getPrice() const;

    void setQuantity(int quantity);
    void setPrice(double price);
};
```

A class acts as a blueprint.

Each `Product` object created from this class contains its own copy of the
product data.

---

# 🔒 Encapsulation

The Product class uses private data members:

```cpp
private:
    std::string name;
    int sku;
    int quantity;
    double price;
```

These values cannot be directly modified from outside the class.

Instead, controlled access is provided through getters and setters.

For example:

```cpp
product1.setQuantity(8);
```

and:

```cpp
product1.getQuantity();
```

This demonstrates **encapsulation**.

---

# 🏗️ Constructor

The constructor initializes each Product object when it is created.

```cpp
Product::Product(
    const std::string& name,
    int sku,
    int quantity,
    double price
)
{
    this->name = name;
    this->sku = sku;
    this->quantity = quantity;
    this->price = price;
}
```

The constructor automatically runs whenever a new Product object is
created.

---

# 👉 The `this` Pointer

Module 6 introduces the `this` pointer.

Inside a member function, `this` refers to the current object.

For example:

```cpp
this->name = name;
```

The left side:

```cpp
this->name
```

refers to the private data member belonging to the current Product object.

The right side:

```cpp
name
```

refers to the constructor parameter.

The `this` pointer is also used in the setters:

```cpp
this->quantity = quantity;
this->price = price;
```

---

# 🧠 Member Functions

The Product class contains several member functions.

## Display Product

```cpp
void displayProduct() const;
```

Displays the information stored inside a Product object.

---

## Calculate Inventory Value

```cpp
double calculateInventoryValue() const;
```

Calculates:

```text
Quantity × Price
```

For example:

```text
5 × $39.99 = $199.95
```

---

# 🔎 Getters

Getters provide controlled read access to private data.

```cpp
std::string getName() const;
int getQuantity() const;
double getPrice() const;
```

Example:

```cpp
product1.getName();
```

---

# ✏️ Setters

Setters provide controlled modification of private data.

```cpp
void setQuantity(int quantity);
void setPrice(double price);
```

For example:

```cpp
product1.setQuantity(8);
```

The setter checks that the quantity is not negative before changing the
private value.

---

# 🧱 Objects

Two Product objects are created in this assignment.

```cpp
Product product1(
    "Brake Pads",
    1001,
    5,
    39.99
);

Product product2(
    "Oil Filter",
    1002,
    10,
    8.99
);
```

Both objects are created from the same `Product` class but contain
different values.

---

# 🔄 Object Life Cycle

A Product object follows a basic life cycle:

```text
Class Definition
      │
      ▼
Constructor Called
      │
      ▼
Object Created
      │
      ▼
Object Used
      │
      ▼
Getters / Setters / Member Functions
      │
      ▼
Object Goes Out of Scope
      │
      ▼
Object Destroyed
```

In this program, `product1` and `product2` are created inside
`demonstrateProducts()`.

When that function finishes, the objects go out of scope and are
automatically destroyed.

A custom destructor is not required for this assignment because the class
does not manually manage dynamic resources.

---

# ▶️ Understanding `main()`

The `main()` function is the entry point of the application.

```cpp
int main()
{
    showWelcome();
    showMenu();
    demonstrateProducts();

    return 0;
}
```

Execution begins in `main()`.

Rather than putting the entire program inside `main()`, it coordinates
other functions.

---

# 3️⃣ Functions Called From `main()`

The assignment specifically asks for at least three functions to be called
from `main()`.

This application calls exactly three:

```cpp
showWelcome();
showMenu();
demonstrateProducts();
```

### `showWelcome()`

Displays the application heading.

### `showMenu()`

Displays the current application features.

### `demonstrateProducts()`

Creates Product objects and demonstrates their functionality.

---

# 🔀 Application Flow

The application follows this flow:

```text
                    Program Starts
                          │
                          ▼
                       main()
                          │
            ┌─────────────┼─────────────┐
            │             │             │
            ▼             ▼             ▼
      showWelcome()   showMenu()   demonstrateProducts()
                                          │
                                          ▼
                                   Create Product Objects
                                          │
                              ┌───────────┴───────────┐
                              │                       │
                              ▼                       ▼
                          product1                product2
                              │                       │
                              └───────────┬───────────┘
                                          │
                                          ▼
                                  displayProduct()
                                          │
                                          ▼
                                  Getter Functions
                                          │
                                          ▼
                                  Setter Functions
                                          │
                                          ▼
                            calculateInventoryValue()
                                          │
                                          ▼
                                      Program Ends
```

This matches the course's larger application model:

```text
main()
   │
   ▼
Functions
   │
   ▼
Classes / Objects
   │
   ▼
Data
   │
   ▼
Future File / Database Storage
```

---

# 🖥️ Example Output

```text
========================================
         INVENTORY MANAGER - MODULE 6
========================================
Classes and Objects Demonstration

Application Features
1. Create Product Objects
2. Display Product Information
3. Update Product Data

--- Product 1 ---
Product: Brake Pads
SKU: 1001
Quantity: 5
Price: $39.99
Inventory Value: $199.95

--- Product 2 ---
Product: Oil Filter
SKU: 1002
Quantity: 10
Price: $8.99
Inventory Value: $89.90

--- Getter Demonstration ---
Product 1 name: Brake Pads
Product 2 quantity: 10

--- Setter Demonstration ---
Updating Brake Pads quantity from 5 to 8.
New quantity: 8
New inventory value: $319.92
```

---

# 📁 Module Files

```text
Module06-Records-Storage/
│
├── README.md
├── main.cpp
├── Product.h
└── Product.cpp
```

### `main.cpp`

Contains:

- Program entry point
- `showWelcome()`
- `showMenu()`
- `demonstrateProducts()`

### `Product.h`

Contains:

- Product class declaration
- Private data members
- Constructor declaration
- Member function declarations
- Getter declarations
- Setter declarations

### `Product.cpp`

Contains the implementations of the Product class member functions.

### `README.md`

Documents the Module 6 assignment and how each requirement was satisfied.

> **Note:** The folder name was created during the original repository
> setup and is retained for organizational consistency. The actual Module 6
> assignment is **Creating Classes & Objects**.

---

# 🧩 Connection to Previous Modules

The Inventory Manager continues building upon previous work.

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
        │
        ▼
Module 06
Classes & Objects
```

Module 6 replaces the idea of loosely related record data with a reusable
class.

---

# 📈 Data Progression

```text
Individual Variable
        │
        ▼
Array
        │
        ▼
Record / struct
        │
        ▼
Class
        │
        ▼
Object
        │
        ▼
Collection of Objects
        │
        ▼
File / Database
        │
        ▼
Complete Inventory Manager
```

---

# 🧪 Testing

The Module 6 application should be tested to verify that:

- The project compiles successfully
- `main()` starts the program
- `showWelcome()` executes
- `showMenu()` executes
- `demonstrateProducts()` executes
- Two Product objects are created
- Both Product objects display correctly
- Constructor values are stored correctly
- Getters return correct values
- Setter changes the quantity
- Negative values are rejected by setters
- Inventory value is calculated correctly
- The application exits normally
- No runtime errors occur

---

# ✅ Module 6 Checklist

- [x] `Product` class created
- [x] Private data members created
- [x] Constructor created
- [x] At least two member functions created
- [x] Getter functions created
- [x] Setter functions created
- [x] `this` pointer demonstrated
- [x] Encapsulation demonstrated
- [x] Two Product objects created
- [x] Both objects displayed
- [x] `main()` used as application entry point
- [x] Three functions called from `main()`
- [x] Application flow documented
- [x] Object life cycle explained
- [x] Inventory Manager connection documented
- [x] Program compiled successfully
- [x] Program tested successfully
- [x] Module 6 files uploaded to GitHub
- [x] Module 6 completed

---

# 🔮 Future Development

The Product class provides a foundation for later modules.

Instead of storing individual values, future versions of the Inventory
Manager can store collections of Product objects.

For example:

```text
Product Object
      │
      ▼
Array / Collection of Products
      │
      ▼
Search / Update / Delete
      │
      ▼
Save to File
      │
      ▼
Database
      │
      ▼
Complete Inventory System
```

---

# 🔗 Links

**Developer**  
[John Saldivar](https://github.com/johnsaldivar)

**Course Repository**  
[CPlusPlus-Application-Design](https://github.com/johnsaldivar/CPlusPlus-Application-Design)

**Previous Module**  
[Module 05 — Records, Headers & Functions](../Module05-Classes-Objects/)

---

<div align="center">

## 📦 Inventory Manager

### Module 06 — Creating Classes & Objects

**John Saldivar**

![C++](https://img.shields.io/badge/C%2B%2B-Classes%20%7C%20Objects-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![OOP](https://img.shields.io/badge/OOP-Encapsulation-purple?style=for-the-badge)
![Architecture](https://img.shields.io/badge/Architecture-Product%20Class-success?style=for-the-badge)

**Build → Test → Improve → Connect**

</div>
