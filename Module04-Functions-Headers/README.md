<div align="center">

# 📊 Module 04 — Datasets, Arrays & Pointers

### 📦 Inventory Manager

[![Module](https://img.shields.io/badge/Module-04-4C8BF5?style=for-the-badge)](./)
[![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![Project](https://img.shields.io/badge/Project-Inventory%20Manager-2ea44f?style=for-the-badge)](#)
[![Dataset](https://img.shields.io/badge/Dataset-Kaggle-20BEFF?style=for-the-badge&logo=kaggle&logoColor=white)](https://www.kaggle.com/datasets/faresashraf1001/supermarket-sales)
[![Status](https://img.shields.io/badge/Status-Complete-success?style=for-the-badge)](#)

**Author:** [John Saldivar](https://github.com/johnsaldivar)

</div>

---

## 📖 Overview

Module 4 introduces **datasets, arrays, loops, and pointers**.

For this assignment, I selected a public supermarket sales dataset from
Kaggle and brought a simplified portion of the dataset into the
**Inventory Manager** application.

Instead of working with one value at a time, the application now works
with collections of related values stored in C++ arrays.

The program also demonstrates how a pointer can be used to access a value
stored in memory.

---

## 🌐 Dataset Source

The dataset used for this module is:

### Supermarket Sales Dataset

**Source:** Kaggle

**Dataset Link:**  
https://www.kaggle.com/datasets/faresashraf1001/supermarket-sales

The original dataset contains supermarket transaction information.

For this assignment, I selected three fields:

- Product Line
- Unit Price
- Quantity

I selected seven records from the dataset for the C++ demonstration.

---

## 🎯 Module Objectives

This module demonstrates:

- Working with a real-world public dataset
- Inspecting fields within a dataset
- Selecting a simplified subset of data
- Creating C++ arrays
- Storing multiple values inside arrays
- Accessing array values by index
- Iterating through arrays using a loop
- Understanding basic pointer syntax
- Accessing an array value through a pointer
- Connecting external data to the Inventory Manager project

---

# 📊 Selected Dataset Fields

The simplified dataset uses three fields.

| Field | C++ Type | Purpose |
|---|---|---|
| Product Line | `string` | Category associated with the product |
| Unit Price | `double` | Price per unit |
| Quantity | `int` | Number of units purchased |

---

# 📋 Selected Records

Seven records were selected from the dataset.

| Record | Product Line | Unit Price | Quantity |
|:---:|---|---:|---:|
| 1 | Health and beauty | $74.69 | 7 |
| 2 | Electronic accessories | $15.28 | 5 |
| 3 | Home and lifestyle | $46.33 | 7 |
| 4 | Health and beauty | $58.22 | 8 |
| 5 | Sports and travel | $86.31 | 7 |
| 6 | Electronic accessories | $85.39 | 7 |
| 7 | Electronic accessories | $68.84 | 6 |

---

# 🧠 Arrays

An array allows several values of the same data type to be stored under
one variable name.

For example:

```cpp
double unitPrices[7] =
{
    74.69,
    15.28,
    46.33,
    58.22,
    86.31,
    85.39,
    68.84
};
```

Instead of creating seven separate price variables, one array stores all
seven prices.

Each value can be accessed using an index.

```cpp
unitPrices[0]
```

returns:

```text
74.69
```

C++ array indexes begin at `0`.

---

# 🔗 Parallel Arrays

This assignment uses three arrays:

```cpp
string productLines[RECORD_COUNT];
double unitPrices[RECORD_COUNT];
int quantities[RECORD_COUNT];
```

The arrays work together using the same index.

For example:

```text
Index 0
Product Line: Health and beauty
Unit Price:   74.69
Quantity:     7
```

The values at index `0` represent one simplified record.

---

# 🔁 Displaying the Dataset

A `for` loop displays each record.

```cpp
for (int i = 0; i < RECORD_COUNT; i++)
{
    cout << productLines[i] << endl;
    cout << unitPrices[i] << endl;
    cout << quantities[i] << endl;
}
```

The loop allows the program to process all records without writing a
separate `cout` statement for every item.

---

# 👉 Pointers

A pointer stores a memory address.

For this assignment, a pointer is connected to the first value in the
`unitPrices` array.

```cpp
double* pricePtr = &unitPrices[0];
```

The `&` operator retrieves the memory address of:

```cpp
unitPrices[0]
```

The pointer stores that address.

---

## Dereferencing the Pointer

The value stored at that memory address can be accessed using:

```cpp
*pricePtr
```

For this program:

```cpp
unitPrices[0]
```

and:

```cpp
*pricePtr
```

both return:

```text
74.69
```

This demonstrates how C++ can access data directly through a memory
address.

---

# 🖥️ Program Output

The application displays the selected dataset records in a formatted
table.

Example:

```text
===============================================
       INVENTORY MANAGER - DATASET VIEW
===============================================
Record  Product Line                Unit Price    Quantity
-----------------------------------------------
1       Health and beauty           $74.69        7
2       Electronic accessories      $15.28        5
3       Home and lifestyle          $46.33        7
4       Health and beauty           $58.22        8
5       Sports and travel           $86.31        7
6       Electronic accessories      $85.39        7
7       Electronic accessories      $68.84        6
```

The program then demonstrates pointer access.

```text
--- Pointer Demonstration ---
First unit price normally: $74.69
First unit price through pointer: $74.69
```

---

# 📦 Connection to the Inventory Manager

Previous modules introduced individual variables and application flow.

Module 4 begins working with **collections of data**.

The progression now looks like:

```text
Variable
    │
    ▼
Array
    │
    ▼
Multiple Records
    │
    ▼
Data Structure
    │
    ▼
Object / Class
    │
    ▼
File / Database
    │
    ▼
Inventory Manager
```

Arrays provide an early way for the Inventory Manager to work with
multiple records instead of only one item at a time.

---

# 🧩 Application Progress

```text
Module 01
Development Environment & GitHub
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
Future Modules
More Advanced Data Structures
```

---

# 📁 Module Files

```text
Module04-Functions-Headers/
├── README.md
└── inventory_dataset.cpp
```

> **Note:** The module directory names were created during the initial
> repository setup and are retained for organizational consistency.
> The actual Module 4 assignment is **Datasets, Arrays & Pointers**.

---

# 🧪 Testing

The application should be tested to verify that:

- All seven records appear
- Each product line matches the correct price
- Each product line matches the correct quantity
- Prices display with two decimal places
- The loop processes every array element
- The pointer correctly references the first price
- Dereferencing the pointer displays `74.69`
- The program exits normally
- No compilation errors occur
- No runtime errors occur

---

# ✅ Module 4 Checklist

- [x] Public Kaggle dataset selected
- [x] Dataset fields inspected
- [x] Seven dataset records selected
- [x] Three dataset fields selected
- [x] Product Line array created
- [x] Unit Price array created
- [x] Quantity array created
- [x] Loop used to display records
- [x] Pointer created
- [x] Pointer connected to an array value
- [x] Value accessed through pointer dereferencing
- [x] Dataset connected to Inventory Manager
- [ ] Program compiled successfully
- [ ] Program tested successfully
- [ ] Module 4 files uploaded to GitHub
- [ ] Module 4 completed

---

# 🔮 Future Development

The arrays used in this module provide a temporary way to organize
multiple records.

Future modules may replace or expand these arrays using:

- Functions
- Classes
- Objects
- Data structures
- Files
- Databases
- Long-term storage

Eventually, inventory data will be represented using more advanced
structures designed specifically for the Inventory Manager.

---

# 🔗 Links

**Developer**  
[John Saldivar](https://github.com/johnsaldivar)

**Course Repository**  
[CPlusPlus-Application-Design](https://github.com/johnsaldivar/CPlusPlus-Application-Design)

**Dataset**  
[Supermarket Sales Dataset — Kaggle](https://www.kaggle.com/datasets/faresashraf1001/supermarket-sales)

**Previous Module**  
[Module 03 — Variables, Cin & Cout](../Module03-Datasets-Arrays-Pointers/)

---

<div align="center">

## 📦 Inventory Manager

### Module 04 — Datasets, Arrays & Pointers

**John Saldivar**

![C++](https://img.shields.io/badge/C%2B%2B-Arrays%20%7C%20Pointers-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Dataset](https://img.shields.io/badge/Data-Kaggle-20BEFF?style=for-the-badge&logo=kaggle&logoColor=white)

**Build → Test → Improve → Connect**

</div>
