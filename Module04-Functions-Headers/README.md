<div align="center">

# 📊 Module 04 — Datasets, Arrays & Pointers

### 📦 Inventory Manager

[![Module](https://img.shields.io/badge/Module-04-4C8BF5?style=for-the-badge)](./)
[![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![Project](https://img.shields.io/badge/Project-Inventory%20Manager-2ea44f?style=for-the-badge)](#)
[![Dataset](https://img.shields.io/badge/Dataset-Kaggle-20BEFF?style=for-the-badge&logo=kaggle&logoColor=white)](https://www.kaggle.com/datasets/faresashraf1001/supermarket-sales)
[![Status](https://img.shields.io/badge/Status-Revised%20%26%20Complete-success?style=for-the-badge)](#)

**Author:** [John Saldivar](https://github.com/johnsaldivar)

</div>

---

## 📖 Overview

Module 4 focuses on **datasets, arrays, loops, and pointers**.

For this assignment, I downloaded a public supermarket sales dataset from
**Kaggle** and included the original CSV file with this module.

The C++ program opens the downloaded dataset, reads a simplified selection
of records, stores selected fields in arrays, displays the records using a
loop, and demonstrates accessing one of the array values through a pointer.

This module connects real-world external data to the **Inventory Manager**
project.

---

# 🌐 Kaggle Dataset

The dataset used for this assignment was downloaded from Kaggle.

### Dataset

**Supermarket Sales Dataset**

### Source

[Kaggle — Supermarket Sales Dataset](https://www.kaggle.com/datasets/faresashraf1001/supermarket-sales)

### Downloaded File

```text
SuperMarket Analysis.csv
```

The original downloaded CSV is included in this module under:

```text
data/SuperMarket Analysis.csv
```

The downloaded dataset contains approximately **1,000 transaction records**
and multiple fields describing supermarket sales.

---

# 🎯 Assignment Requirements

The Module 4 assignment requires:

- Selecting a small public Kaggle dataset
- Choosing 5–10 records
- Choosing at least 2–3 fields
- Representing the selected data using C++ arrays
- Displaying the records
- Demonstrating access to one value through a pointer

This implementation uses:

```text
Dataset: Supermarket Sales Dataset
Records Selected: 7
Fields Selected: 3
```

---

# 📊 Fields Selected

The following three fields were selected from the downloaded dataset:

| Field | C++ Type | Purpose |
|---|---|---|
| Product line | `string` | Stores the product category |
| Unit price | `double` | Stores the price per unit |
| Quantity | `int` | Stores the number of units purchased |

---

# 📋 Records Used

The program loads the first seven records from the downloaded CSV.

| Record | Product Line | Unit Price | Quantity |
|:---:|---|---:|---:|
| 1 | Health and beauty | $74.69 | 7 |
| 2 | Electronic accessories | $15.28 | 5 |
| 3 | Home and lifestyle | $46.33 | 7 |
| 4 | Health and beauty | $58.22 | 8 |
| 5 | Sports and travel | $86.31 | 7 |
| 6 | Electronic accessories | $85.39 | 7 |
| 7 | Electronic accessories | $68.84 | 6 |

These values are read directly from:

```text
data/SuperMarket Analysis.csv
```

rather than being manually entered into the C++ source code.

---

# 📂 Reading the Kaggle Dataset

The C++ application opens the downloaded CSV using `ifstream`.

```cpp
ifstream datasetFile("data/SuperMarket Analysis.csv");
```

The program then skips the CSV header:

```cpp
getline(datasetFile, line);
```

and reads the selected records one line at a time.

```cpp
while (recordCount < RECORD_COUNT &&
       getline(datasetFile, line))
{
    // Parse CSV data
}
```

This demonstrates bringing external Kaggle data into a C++ application.

---

# 🧠 Arrays

Three arrays store the selected dataset fields.

```cpp
string productLines[RECORD_COUNT];
double unitPrices[RECORD_COUNT];
int quantities[RECORD_COUNT];
```

Each array uses the same index to represent one record.

For example:

```text
Index 0

Product line: Health and beauty
Unit price:   74.69
Quantity:     7
```

Together, the values at the same index represent one simplified
supermarket record.

---

# 🔄 Loading CSV Values into Arrays

The program reads values from the Kaggle CSV and places them into the
appropriate arrays.

### Product Line

```cpp
getline(row, productLines[recordCount], ',');
```

### Unit Price

```cpp
getline(row, field, ',');
unitPrices[recordCount] = stod(field);
```

### Quantity

```cpp
getline(row, field, ',');
quantities[recordCount] = stoi(field);
```

The string values read from the CSV are converted into the appropriate C++
data types where necessary.

---

# 🔁 Displaying the Records

A `for` loop processes and displays every selected record.

```cpp
for (int i = 0; i < recordCount; i++)
{
    cout << productLines[i] << endl;
    cout << unitPrices[i] << endl;
    cout << quantities[i] << endl;
}
```

Using a loop avoids writing separate output statements for every record.

---

# 👉 Pointer Demonstration

Module 4 also introduces pointers.

A pointer is created that stores the memory address of the first value in
the `unitPrices` array.

```cpp
double* pricePtr = &unitPrices[0];
```

The `&` operator retrieves the memory address of:

```cpp
unitPrices[0]
```

---

## Dereferencing the Pointer

The value stored at the pointer's memory address is accessed using:

```cpp
*pricePtr
```

Therefore:

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

This demonstrates accessing an array value through a pointer.

---

# 🖥️ Example Program Output

```text
======================================================
          INVENTORY MANAGER - KAGGLE DATASET
======================================================
Source file: data/SuperMarket Analysis.csv
Records loaded: 7

Record  Product Line                Unit Price    Quantity
------------------------------------------------------
1       Health and beauty           $74.69        7
2       Electronic accessories      $15.28        5
3       Home and lifestyle          $46.33        7
4       Health and beauty           $58.22        8
5       Sports and travel           $86.31        7
6       Electronic accessories      $85.39        7
7       Electronic accessories      $68.84        6

--- Pointer Demonstration ---
First unit price using array access: $74.69
First unit price using pointer access: $74.69
Pointer memory address: 0x...

Dataset loaded and displayed successfully.
```

> The exact pointer memory address will be different each time the program
> runs.

---

# 📦 Connection to the Inventory Manager

Previous modules worked primarily with individual values and program flow.

Module 4 introduces working with **collections of external data**.

```text
Kaggle Dataset
      │
      ▼
Downloaded CSV
      │
      ▼
C++ File Input
      │
      ▼
Selected Fields
      │
      ▼
Arrays
      │
      ▼
Multiple Records
      │
      ▼
Pointer Access
      │
      ▼
Inventory Manager
```

This is an important step toward building an application that can work
with larger collections of real-world information.

---

# 🔗 Data Progression

The Inventory Manager is gradually progressing toward more structured data.

```text
Variable
   │
   ▼
External Dataset
   │
   ▼
Array
   │
   ▼
Multiple Records
   │
   ▼
Record / Structure
   │
   ▼
Class / Object
   │
   ▼
File / Database
   │
   ▼
Complete Application
```

---

# 📁 Module Files

```text
Module04-Functions-Headers/
│
├── README.md
├── inventory_dataset.cpp
│
└── data/
    └── SuperMarket Analysis.csv
```

### `inventory_dataset.cpp`

Opens the Kaggle dataset, loads selected records into arrays, displays the
data, and demonstrates pointer access.

### `data/SuperMarket Analysis.csv`

The original dataset file downloaded from Kaggle.

### `README.md`

Documents the dataset source, assignment requirements, implementation,
testing, and connection to the Inventory Manager.

> **Note:** The module directory name was created during the initial
> repository setup and is retained for organizational consistency.
> The actual Module 4 assignment is **Datasets, Arrays & Pointers**.

---

# 🧪 Testing

The revised Module 4 program was tested to confirm that:

- The downloaded Kaggle CSV opens successfully
- The program reads records from the CSV
- Seven records are loaded
- Product Line values are read correctly
- Unit Price values are read correctly
- Quantity values are read correctly
- Dataset values are stored in arrays
- The loop displays all seven records
- Prices display with two decimal places
- The pointer references the first Unit Price
- Dereferencing the pointer returns `$74.69`
- The program exits normally
- No compilation errors occur
- No runtime errors occur

---

# ✅ Module 4 Checklist

- [x] Public Kaggle dataset selected
- [x] Dataset downloaded directly from Kaggle
- [x] Original Kaggle CSV included in repository
- [x] Dataset inspected
- [x] Seven dataset records selected
- [x] Three dataset fields selected
- [x] C++ program opens the downloaded CSV
- [x] Product Line values loaded into an array
- [x] Unit Price values loaded into an array
- [x] Quantity values loaded into an array
- [x] Loop used to display records
- [x] Pointer created
- [x] Pointer connected to an array value
- [x] Array value accessed through pointer dereferencing
- [x] Dataset connected to Inventory Manager
- [x] Program compiled successfully
- [x] Program tested successfully
- [x] Module 4 revised based on instructor feedback
- [x] Module 4 completed

---

# 🔧 Revision After Instructor Feedback

The original Module 4 submission demonstrated arrays and pointers using
values selected from the Kaggle dataset.

After instructor feedback, the assignment was revised to make the Kaggle
dataset integration explicit.

The revised version now:

1. Includes the original CSV downloaded from Kaggle.
2. Opens the downloaded CSV directly from C++.
3. Reads seven records from the dataset.
4. Extracts three fields from those records.
5. Stores the extracted values in C++ arrays.
6. Displays those values using a loop.
7. Demonstrates accessing one array value using a pointer.

This revision directly demonstrates the complete workflow required by the
assignment:

```text
Kaggle
   ↓
Download Dataset
   ↓
CSV File
   ↓
C++ Reads CSV
   ↓
Select Records
   ↓
Store in Arrays
   ↓
Display Records
   ↓
Pointer Demonstration
```

---

# 🔮 Future Development

The dataset and arrays introduced in this module provide a foundation for
more advanced forms of inventory storage.

Future modules can expand this work through:

- Structures
- Functions
- Classes
- Objects
- Searching
- Input validation
- File storage
- Databases
- More advanced data structures

The goal is to gradually move from simplified dataset records toward a
complete Inventory Manager.

---

# 🔗 Links

**Developer**  
[John Saldivar](https://github.com/johnsaldivar)

**Course Repository**  
[CPlusPlus-Application-Design](https://github.com/johnsaldivar/CPlusPlus-Application-Design)

**Kaggle Dataset**  
[Supermarket Sales Dataset](https://www.kaggle.com/datasets/faresashraf1001/supermarket-sales)

**Previous Module**  
[Module 03 — Variables, Cin & Cout](../Module03-Datasets-Arrays-Pointers/)

**Next Module**  
[Module 05 — Records, Headers & Functions](../Module05-Classes-Objects/)

---

<div align="center">

## 📦 Inventory Manager

### Module 04 — Datasets, Arrays & Pointers

**John Saldivar**

![C++](https://img.shields.io/badge/C%2B%2B-Arrays%20%7C%20Pointers-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Dataset](https://img.shields.io/badge/Data-Kaggle-20BEFF?style=for-the-badge&logo=kaggle&logoColor=white)
![Revision](https://img.shields.io/badge/Revision-Kaggle%20CSV%20Integrated-success?style=for-the-badge)

**Build → Test → Improve → Connect**

</div>
