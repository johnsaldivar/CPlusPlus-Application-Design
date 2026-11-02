<div align="center">

# 💻 C++ Application Design

### 📦 Inventory Manager
### Course Projects & Application Development Portfolio

![C++](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Project](https://img.shields.io/badge/Project-Inventory%20Manager-2ea44f?style=for-the-badge)
![Module](https://img.shields.io/badge/Latest%20Module-08-blue?style=for-the-badge)
![Progress](https://img.shields.io/badge/Progress-Module%2008%20Complete-success?style=for-the-badge)
![Modules](https://img.shields.io/badge/Modules%20Completed-8%20of%2015-success?style=for-the-badge)
![Midway](https://img.shields.io/badge/Midway%20Project-Complete-success?style=for-the-badge)
![Revision](https://img.shields.io/badge/Module%2004-Awaiting%20Regrade-orange?style=for-the-badge)
![GitHub](https://img.shields.io/badge/GitHub-johnsaldivar-181717?style=for-the-badge&logo=github)

**Developed by [John Saldivar](https://github.com/johnsaldivar)**

**Build → Test → Improve → Connect**

</div>

---

## 📖 About This Repository

This repository contains my coursework, programming assignments, and
application development work for my **C++ Application Design** course.

Throughout the course, I am developing a C++ application while learning
new programming concepts and applying them to the project as it grows.

Rather than treating every assignment as an unrelated program, this
repository documents the development of one larger application and the
skills introduced throughout each module.

My semester project is an **Inventory Manager**.

---

## 👨‍💻 Developer

**John Saldivar**

- GitHub: [@johnsaldivar](https://github.com/johnsaldivar)
- Repository: [CPlusPlus-Application-Design](https://github.com/johnsaldivar/CPlusPlus-Application-Design)

---

# 📦 Inventory Manager

## 🚀 Project Overview

The **Inventory Manager** is a command-line C++ application designed to
manage inventory records.

The project begins with fundamental C++ concepts and continues to grow
into a more organized and functional application as new topics are
introduced throughout the course.

The application now demonstrates:

- Inventory records
- External dataset integration
- CSV processing
- Arrays and pointers
- Functions and headers
- Classes and objects
- Encapsulation
- Inheritance
- Role-based permissions
- Sorted records
- Binary search
- Input validation
- Required-field and range checking
- Date-format validation
- Duplicate-SKU protection
- File I/O and persistent text-file storage
- Dynamic memory and pointer-based storage in the Midway Project

Future modules will continue expanding the application with additional
data structures, database concepts, security concepts, and AI-related
functionality.

---

# 🎯 Project Goals

The Inventory Manager is being developed incrementally throughout the
semester.

The project is intended to demonstrate:

- C++ fundamentals
- Variables and data types
- Console input and output
- Menu-driven application flow
- Functions
- Arrays
- Pointers
- External datasets
- CSV file input
- Records
- Structures
- Header files
- Multi-file application design
- Classes
- Objects
- Constructors
- Encapsulation
- Getters and setters
- The `this` pointer
- Object life cycles
- Inheritance
- Polymorphic interfaces
- Access modifiers
- Role-based permissions
- Sorted records
- Binary search
- Data structures
- Searching and algorithms
- File and long-term data storage
- Input validation
- Memory management
- Security concepts
- Database concepts
- Artificial intelligence concepts
- Version control using Git and GitHub

---

# ✨ Planned & Implemented Features

The Inventory Manager currently includes or will eventually include:

- ➕ Add inventory items
- 📋 View inventory records
- 🔎 Search inventory records
- ✏️ Update existing items
- 🗑️ Remove inventory records
- 🔢 Track item quantities
- 🏷️ Organize products
- 💲 Store pricing information
- 🧮 Calculate inventory value
- 📊 Work with multiple records
- 🌐 Import external datasets
- 📄 Read data from CSV files
- 🧱 Represent inventory using classes
- 🔒 Protect object data through encapsulation
- 🔎 Access data through getters
- ✏️ Modify data through setters
- 👑 Support Admin permissions
- 👤 Support Regular User permissions
- 🔐 Restrict actions according to role
- 🔢 Maintain records in sorted order
- 🔍 Search efficiently using binary search
- ✅ Validate user input
- 🧾 Validate required fields, ranges, and dates
- 🚫 Reject duplicate SKUs
- 💾 Save inventory data to a text file
- 📂 Load previously stored inventory
- 🧠 Demonstrate dynamic memory and pointer-based storage
- 🗃️ Explore database-backed storage
- 🤖 Explore AI functionality where appropriate

---

# 🧠 Skills & Concepts

## Core C++

Concepts demonstrated include:

- `main()`
- Variables
- Data types
- Strings
- Integers
- Floating-point numbers
- Characters
- Booleans
- `cin`
- `cout`
- Conditional logic
- `switch/case`
- Loops
- Functions
- Arrays
- Pointers
- Structures
- Header files
- Classes
- Objects
- Dynamic memory
- `new[]` / `delete[]`
- `sizeof()`
- File streams

---

## Object-Oriented Programming

The Inventory Manager now demonstrates:

- Classes
- Objects
- Private data members
- Protected data members
- Public interfaces
- Constructors
- Getters
- Setters
- Encapsulation
- The `this` pointer
- Object life cycles
- Base classes
- Derived classes
- Inheritance
- Virtual functions
- Shared interfaces

Module 7 extends object-oriented design through:

```text
User
 ├── Admin
 └── RegularUser
```

---

## Algorithms & Searching

The project now includes:

- Sorted arrays
- Unique identifiers
- Sorted insertion
- Binary search
- Record lookup
- Not-found handling
- Record deletion

Products are maintained in ascending SKU order so that binary search can
be used correctly.

---

## Data & File Processing

The project includes experience with:

- Arrays
- Parallel arrays
- Pointers
- Memory addresses
- External datasets
- Kaggle datasets
- CSV files
- `ifstream`
- `ofstream`
- `getline()`
- String parsing
- `stoi()`
- `stod()`
- Text-file persistence
- `inventory.txt`
- Product records
- Product objects
- Dynamic Product arrays
- Pointer access to dynamically allocated storage

---

## Input Validation & Data Protection

Module 8 adds a reusable validation layer before data is accepted by the
Inventory Manager.

The application now validates:

- Role selections
- Menu selections
- Integer input
- Decimal input
- Numeric ranges
- Required Product names
- Product-name length
- SKU uniqueness
- `MM/DD/YYYY` date formatting
- Real calendar dates
- Leap years

Invalid values are rejected with a useful message and the user is allowed
to try again.

---

## Midway Project Concepts

The separate **Midway Project** builds on Modules 1–8 and demonstrates the
required course concepts in one integrated Inventory Management System.

It includes:

- Data types and data sizes
- Strings
- Arrays
- Pointers
- Dynamic memory
- Binary search
- Classes
- File I/O
- Persistent `inventory.txt` storage
- Input validation
- Admin and Regular User permissions

The Midway Project is stored separately in the repository under:

```text
Midterm/
```

---

## Security & Permissions

Module 7 introduces basic role-based authorization.

The application now has:

```text
Admin
 ├── View Records
 ├── Search Records
 ├── Add Records
 └── Delete Records

Regular User
 ├── View Records
 ├── Search Records
 ├── Add Records     ❌
 └── Delete Records  ❌
```

This demonstrates how applications can restrict functionality according
to a user's assigned role.

---

## Developer Workflow

This repository documents the software-development workflow used
throughout the course:

- Git
- GitHub
- Repositories
- Files and folders
- Commits
- Push
- Version control
- Compilation
- Testing
- Debugging
- Revision
- Documentation
- Project organization
- Public portfolio development

---

# 📁 Repository Structure

```text
CPlusPlus-Application-Design/
│
├── README.md
│
├── Module01-Setup/
│   ├── README.md
│   └── setup_check.cpp
│
├── Module02-Variables/
│   ├── README.md
│   └── inventory_manager.cpp
│
├── Module03-Datasets-Arrays-Pointers/
│   ├── README.md
│   └── inventory_welcome.cpp
│
├── Module04-Functions-Headers/
│   ├── README.md
│   ├── inventory_dataset.cpp
│   └── data/
│       └── SuperMarket Analysis.csv
│
├── Module05-Classes-Objects/
│   ├── README.md
│   ├── main.cpp
│   ├── InventoryTools.h
│   └── InventoryTools.cpp
│
├── Module06-Records-Storage/
│   ├── README.md
│   ├── main.cpp
│   ├── Product.h
│   └── Product.cpp
│
├── Module07-Security-Search/
│   ├── README.md
│   ├── main.cpp
│   ├── Product.h
│   ├── Product.cpp
│   ├── User.h
│   ├── User.cpp
│   ├── InventorySystem.h
│   └── InventorySystem.cpp
│
├── Module08-Input-Validation/
│   ├── README.md
│   ├── main.cpp
│   ├── Product.h
│   ├── Product.cpp
│   ├── User.h
│   ├── User.cpp
│   ├── InventorySystem.h
│   ├── InventorySystem.cpp
│   ├── InputValidator.h
│   └── InputValidator.cpp
│
├── Midterm/
│   ├── README.md
│   ├── main.cpp
│   ├── Product.h
│   ├── Product.cpp
│   ├── User.h
│   ├── User.cpp
│   ├── InventorySystem.h
│   ├── InventorySystem.cpp
│   ├── InputValidator.h
│   ├── InputValidator.cpp
│   ├── inventory.txt
│   └── output.pdf
│
├── Module09-AI-Application/
├── Module10-Future-of-AI/
├── Module11-Application-Showcase/
├── Module12-Cpp-and-AI/
├── Module13-Careers-Mini-Project/
├── Module14-AI-Agents/
└── Module15-Resources/
```

> **Note:** Module directory names were created during the original
> repository setup and are retained for organizational consistency.
> Each module README documents the actual assignment title and concepts
> covered.

---

# 📚 Module Progress

| Module | Actual Assignment Topic | Status |
|:---:|---|:---:|
| 01 | [Development Environment & GitHub](./Module01-Setup/) | ✅ Complete |
| 02 | [Menus, Switch Case & Application Flow](./Module02-Variables/) | ✅ Complete |
| 03 | [Variables, Cin & Cout](./Module03-Datasets-Arrays-Pointers/) | ✅ Complete |
| 04 | [Datasets, Arrays & Pointers](./Module04-Functions-Headers/) | 🔄 Revised / Resubmitted |
| 05 | [Records, Headers & Functions](./Module05-Classes-Objects/) | ✅ Complete |
| 06 | [Creating Classes & Objects](./Module06-Records-Storage/) | ✅ Complete |
| 07 | [Security, Roles & Binary Search](./Module07-Security-Search/) | ✅ Complete |
| 08 | [Input Validation & Protecting Data](./Module08-Input-Validation/) | ✅ Complete |
| 09 | AI Application | ⏳ Upcoming |
| 10 | Future of AI | ⏳ Upcoming |
| 11 | Application Showcase | ⏳ Upcoming |
| 12 | C++ and AI | ⏳ Upcoming |
| 13 | Careers & Mini Project | ⏳ Upcoming |
| 14 | AI Agents | ⏳ Upcoming |
| 15 | Resources | ⏳ Upcoming |

---

# ✅ Completed & Revised Modules

## Module 01 — Development Environment Setup

Module 1 established the development environment and GitHub workflow used
throughout the course.

### Completed

- [x] Public GitHub repository created
- [x] C++ development environment prepared
- [x] Repository organized
- [x] Original C++ test program created
- [x] Program compiled successfully
- [x] Program tested successfully
- [x] GitHub workflow practiced

➡️ **[View Module 01](./Module01-Setup/)**

---

## Module 02 — Menus, Switch Case & Application Flow

Module 2 established the Inventory Manager's menu and application flow.

```text
Menu
  │
  ▼
User Choice
  │
  ▼
Input Validation
  │
  ▼
switch/case
  │
  ▼
Function
  │
  ▼
Return to Menu
```

### Completed

- [x] Command-line menu created
- [x] Multiple menu options included
- [x] Loop implemented
- [x] `switch/case` implemented
- [x] Functions created
- [x] Invalid input handled
- [x] Program compiled successfully
- [x] Program tested successfully

➡️ **[View Module 02](./Module02-Variables/)**

---

## Module 03 — Variables, Cin & Cout

Module 3 introduced variables and fundamental C++ data types.

The completed program uses:

```text
7 Variables
5 Different Data Types
```

Including:

```text
string
int
double
char
bool
```

### Completed

- [x] Personalized welcome screen created
- [x] User input captured
- [x] Application information stored
- [x] Multiple C++ data types used
- [x] Every variable displayed
- [x] Program compiled successfully
- [x] Program tested successfully

➡️ **[View Module 03](./Module03-Datasets-Arrays-Pointers/)**

---

# 🔄 Module 04 — Datasets, Arrays & Pointers

Module 4 introduced working with external real-world data.

A public **Supermarket Sales Dataset** was downloaded from Kaggle.

The original CSV is included at:

```text
Module04-Functions-Headers/data/SuperMarket Analysis.csv
```

The revised program opens the downloaded CSV directly.

---

## Module 04 Data Flow

```text
Kaggle
   │
   ▼
Download CSV
   │
   ▼
C++ File Input
   │
   ▼
Read Records
   │
   ▼
Select Fields
   │
   ▼
Arrays
   │
   ▼
Pointer Access
```

Three fields are used:

```text
Product Line
Unit Price
Quantity
```

Seven records are selected.

### Revision Status

```text
Original Grade:  2 / 10
Revision:        Completed
CSV Included:    Yes
CSV Parsing:     Implemented
Arrays:          Implemented
Pointers:        Implemented
Status:          Awaiting Regrade
```

➡️ **[View Revised Module 04](./Module04-Functions-Headers/)**

---

## Module 05 — Records, Headers & Functions

Module 5 expanded the Inventory Manager into a multi-file application.

Inventory records are represented using:

```cpp
struct InventoryRecord
{
    std::string itemName;
    int quantity;
    double price;
};
```

The module introduced:

```text
main.cpp
InventoryTools.h
InventoryTools.cpp
```

Functions include:

```cpp
addRecord()
displayRecords()
calculateInventoryValue()
```

### Completed

- [x] Inventory record created
- [x] Add function created
- [x] Display function created
- [x] Calculation function created
- [x] Custom header created
- [x] Function declarations separated
- [x] Function implementations separated
- [x] Program compiled successfully
- [x] Program tested successfully

➡️ **[View Module 05](./Module05-Classes-Objects/)**

---

# ✅ Module 06 — Creating Classes & Objects

Module 6 introduced object-oriented programming.

The application now contains a `Product` class with:

```cpp
private:
    std::string name;
    int sku;
    int quantity;
    double price;
```

The class demonstrates:

- Private data members
- Constructor
- Member functions
- Getters
- Setters
- Encapsulation
- The `this` pointer
- Object life cycles

Two Product objects are created:

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

The application also reinforces `main()` as the application coordinator:

```cpp
int main()
{
    showWelcome();
    showMenu();
    demonstrateProducts();

    return 0;
}
```

### Completed

- [x] Product class created
- [x] Private members created
- [x] Constructor created
- [x] Member functions created
- [x] Getters created
- [x] Setters created
- [x] Encapsulation demonstrated
- [x] `this` pointer demonstrated
- [x] Two objects created
- [x] Three functions called from `main()`
- [x] Program compiled successfully
- [x] Program tested successfully

➡️ **[View Module 06](./Module06-Records-Storage/)**

---

# ✅ Module 07 — Security, Roles & Binary Search

Module 7 introduces application permissions and algorithm-based searching.

The Inventory Manager now supports two user roles:

```text
Admin
Regular User
```

The application uses inheritance, access modifiers, role-based
authorization, sorted product records, and binary search.

---

## 👤 User Hierarchy

The application uses a common `User` base class:

```text
              User
               │
       ┌───────┴───────┐
       │               │
       ▼               ▼
     Admin        RegularUser
```

The base class defines a common permission interface.

---

# 👑 Admin Role

The Admin role has permission to:

```text
View Records       ✅
Search Records     ✅
Add Records        ✅
Delete Records     ✅
```

The Admin class inherits from `User`:

```cpp
class Admin : public User
```

Admin permissions are implemented using:

```cpp
bool Admin::canView() const
{
    return true;
}

bool Admin::canAdd() const
{
    return true;
}

bool Admin::canDelete() const
{
    return true;
}
```

---

# 👤 Regular User Role

The Regular User has permission to:

```text
View Records       ✅
Search Records     ✅
Add Records        ❌
Delete Records     ❌
```

The class inherits from `User`:

```cpp
class RegularUser : public User
```

Its permissions are:

```cpp
bool RegularUser::canView() const
{
    return true;
}

bool RegularUser::canAdd() const
{
    return false;
}

bool RegularUser::canDelete() const
{
    return false;
}
```

---

# 🔐 Role-Based Authorization

Before protected actions are performed, the application checks the
current user's role permissions.

For example:

```cpp
if (!currentUser.canAdd())
{
    std::cout
        << "Access denied: Regular Users cannot add records.\n";

    break;
}
```

Delete permission is checked the same way.

This demonstrates basic application authorization.

---

# 🔒 Access Modifiers

Module 7 demonstrates:

### `private`

Used for Product and InventorySystem data.

```cpp
private:
    int sku;
    std::string name;
    int quantity;
    double price;
```

### `protected`

Used by the `User` base class:

```cpp
protected:
    std::string username;
```

### `public`

Used for constructors, getters, role functions, and application
operations.

---

# 📦 Sorted Product Records

Products are stored in ascending order according to SKU.

Initial records:

```text
1001 — Brake Pads
1002 — Oil Filter
1005 — Air Filter
1010 — Spark Plugs
```

If the Admin adds:

```text
1003 — Engine Cleaner
```

the Inventory Manager inserts it in the correct position:

```text
1001 — Brake Pads
1002 — Oil Filter
1003 — Engine Cleaner
1005 — Air Filter
1010 — Spark Plugs
```

This maintains the ordering required for binary search.

---

# ➕ Sorted Insertion

The Inventory Manager determines the correct insertion point:

```cpp
int insertIndex = 0;

while (
    insertIndex < productCount &&
    products[insertIndex].getSku()
        < product.getSku()
)
{
    insertIndex++;
}
```

Existing elements are shifted:

```cpp
for (
    int i = productCount;
    i > insertIndex;
    i--
)
{
    products[i] =
        products[i - 1];
}
```

The new record is inserted into its sorted position.

---

# 🔍 Binary Search

The application searches for products using:

```cpp
binarySearchBySku()
```

Implementation:

```cpp
int InventorySystem::binarySearchBySku(
    int targetSku
) const
{
    int left = 0;
    int right = productCount - 1;

    while (left <= right)
    {
        int mid =
            left +
            (right - left) / 2;

        int middleSku =
            products[mid].getSku();

        if (middleSku == targetSku)
        {
            return mid;
        }

        if (middleSku < targetSku)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}
```

The SKU serves as the product's unique searchable identifier.

---

# 🔎 Binary Search Example

Searching for:

```text
1005
```

returns:

```text
Product found using binary search:

SKU       Product                  Quantity    Price
----------------------------------------------------------
1005      Air Filter               7           $14.49
```

Searching for:

```text
9999
```

returns:

```text
No product found with SKU 9999.
```

---

# 🖥️ Module 07 Menu

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

The options are displayed to both roles, but permissions determine which
actions can actually be performed.

---

# 🧩 Module 07 Architecture

```text
                     INVENTORY MANAGER
                            │
             ┌──────────────┼──────────────┐
             │              │              │
             ▼              ▼              ▼
          Product          User       InventorySystem
             │              │              │
             │       ┌──────┴──────┐       │
             │       │             │       │
             ▼       ▼             ▼       ▼
          Records  Admin     RegularUser  Sorted Array
                                            │
                                            ▼
                                       Binary Search
```

---

# 🔀 Module 07 Application Flow

```text
                   Program Starts
                         │
                         ▼
                       main()
                         │
                         ▼
                  Create Inventory
                         │
                         ▼
                   Seed Products
                         │
                         ▼
                  Create User Roles
                         │
              ┌──────────┴──────────┐
              │                     │
              ▼                     ▼
            Admin              RegularUser
              │                     │
              └──────────┬──────────┘
                         │
                         ▼
                    Choose Role
                         │
                         ▼
                  Application Menu
                         │
        ┌────────────────┼────────────────┐
        │                │                │
        ▼                ▼                ▼
       View            Search           Modify
        │                │                │
        ▼                ▼                ▼
Permission Check   Binary Search   Permission Check
                                          │
                                   ┌──────┴──────┐
                                   │             │
                                   ▼             ▼
                                  Add          Delete
```

---

# 🧪 Module 07 Testing

The Admin role was tested to verify:

- Records can be viewed
- Existing SKUs can be searched
- Missing SKUs return not found
- New products can be added
- New products remain sorted by SKU
- Newly added products can be found using binary search
- Products can be deleted
- Deleted products are removed
- Application exits normally

The Regular User role was tested to verify:

- Records can be viewed
- Records can be searched
- Add attempts are denied
- Delete attempts are denied
- Application exits normally

---

# ✅ Module 07 Requirements

| Assignment Requirement | Implementation |
|---|---|
| Admin role | `Admin` |
| Regular User role | `RegularUser` |
| Admin can add | ✅ |
| Admin can view | ✅ |
| Admin can delete | ✅ |
| Regular User can view | ✅ |
| Regular User cannot add | ✅ |
| Regular User cannot delete | ✅ |
| Sorted records | SKU ascending |
| Binary search | `binarySearchBySku()` |
| Unique search field | SKU |
| Inheritance | `Admin` / `RegularUser` → `User` |
| Access modifiers | `private`, `protected`, `public` |

### Completed

- [x] User base class created
- [x] Admin role created
- [x] Regular User role created
- [x] Admin can view records
- [x] Admin can search records
- [x] Admin can add records
- [x] Admin can delete records
- [x] Regular User can view records
- [x] Regular User can search records
- [x] Regular User cannot add records
- [x] Regular User cannot delete records
- [x] Permission checks implemented
- [x] Inheritance demonstrated
- [x] Access modifiers demonstrated
- [x] SKU used as unique field
- [x] Records maintained in sorted order
- [x] Sorted insertion implemented
- [x] Binary search implemented
- [x] Missing records handled
- [x] Program compiled successfully
- [x] Admin role fully tested
- [x] Regular User role fully tested
- [x] Module 7 uploaded to GitHub
- [x] Module 7 completed

➡️ **[View Module 07](./Module07-Security-Search/)**

---

# ✅ Module 08 — Input Validation & Protecting Data

Module 8 adds a reusable validation layer to the Inventory Manager.

The application no longer assumes that user input is valid. Values are checked
before they are accepted or stored.

Validation now covers:

```text
Type
Range
Required Fields
Unique IDs
Date Format
Calendar Dates
Leap Years
```

The module introduces the `InputValidator` class:

```cpp
class InputValidator
{
public:
    static int getIntInRange(...);
    static double getDoubleInRange(...);
    static std::string getRequiredString(...);
    static std::string getDateMMDDYYYY(...);
    static bool isValidDate(...);
};
```

Product records also include a validated date:

```cpp
std::string dateAdded;
```

### Validation Examples

The application rejects:

```text
Negative SKU values
Negative quantities
Invalid prices
Empty Product names
Whitespace-only names
Duplicate SKUs
Incorrect date formats
Impossible calendar dates
Invalid leap-year dates
Nonnumeric menu input
Out-of-range menu choices
```

Each invalid entry produces a useful error message and allows the user to try
again.

### Existing Features Preserved

Module 8 keeps the functionality from Module 7:

- [x] Admin permissions
- [x] Regular User restrictions
- [x] Sorted Product records
- [x] Sorted insertion
- [x] Binary search
- [x] Record deletion
- [x] Multi-file application design

### Completed

- [x] InputValidator class created
- [x] Integer validation implemented
- [x] Decimal validation implemented
- [x] Range validation implemented
- [x] Required-field validation implemented
- [x] Empty names rejected
- [x] Negative values rejected where invalid
- [x] Duplicate SKU protection implemented
- [x] Date-format validation implemented
- [x] Calendar-date validation implemented
- [x] Leap-year validation implemented
- [x] Retry loops implemented
- [x] Helpful error messages implemented
- [x] Program compiled successfully
- [x] Admin workflow tested successfully
- [x] Regular User workflow tested successfully
- [x] Module 8 uploaded to GitHub
- [x] Module 8 completed

➡️ **[View Module 08](./Module08-Input-Validation/)**

---

# 🎓 Midway Project — Inventory Management System

The Midway Project is a separate project milestone that combines the C++
concepts introduced throughout the first half of the course into one complete
Inventory Management System.

It is stored in:

```text
Midterm/
```

The Midway version builds on the Inventory Manager developed in Modules 1–8
while adding persistent file storage and dynamic memory.

## Required Concepts Demonstrated

| Required Concept | Midway Implementation |
|---|---|
| Data types and data sizes | Multiple C++ types + `sizeof()` demonstration |
| File type | `inventory.txt` |
| Pointers | Pointer access to dynamically allocated Product storage |
| Arrays | Product collection |
| Search algorithm | Binary search by SKU |
| Strings | Product names, dates, usernames |
| File I/O | `ifstream` / `ofstream` |
| At least two classes | `Product`, `InventorySystem`, `User`, `InputValidator` |
| Dynamic memory | `new[]` / `delete[]` |

## Midway Features

The completed project includes:

- Admin and Regular User roles
- Role-based authorization
- Add Product
- View Products
- Search Products
- Delete Products
- Sorted insertion by SKU
- Binary search
- Duplicate SKU protection
- Input validation
- Date validation
- Dynamic Product storage
- Pointer demonstration
- Data-size demonstration
- Text-file loading
- Text-file saving
- Persistent inventory data

## Persistent Storage

The Midway Project uses:

```text
inventory.txt
```

Inventory records are loaded from the file and saved back to disk so the
application can preserve data between program runs.

## Dynamic Memory

The Product collection is dynamically allocated and accessed through a
pointer.

This demonstrates:

```text
Product*
new[]
delete[]
Pointer Access
Dynamic Array Storage
```

## Midway Report

The Midway folder also contains:

```text
output.pdf
```

The report documents:

- What the program does
- How the program works
- Required C++ concepts
- Program architecture
- Compilation/testing results
- Screenshots of the running application

### Completed

- [x] Midway Inventory Management System built
- [x] Required C++ concepts implemented
- [x] Dynamic memory implemented
- [x] Pointer demonstration implemented
- [x] Binary search implemented
- [x] File I/O implemented
- [x] Persistent text-file storage implemented
- [x] Multiple classes implemented
- [x] Input validation integrated
- [x] Role permissions integrated
- [x] Project compiled successfully
- [x] Admin workflow tested
- [x] Regular User workflow tested
- [x] File save/load tested
- [x] `output.pdf` created
- [x] Midway Project completed

➡️ **[View Midway Project](./Midterm/)**

---

# 🧩 Current Application Architecture

After eight modules and the Midway milestone, the Inventory Manager has
progressed from a basic console program into a modular application with
validation, role-based permissions, searching, and persistent storage.

```text
                         INVENTORY MANAGER
                                │
       ┌────────────────────────┼────────────────────────┐
       │                        │                        │
       ▼                        ▼                        ▼
      User                   Product              InputValidator
       │                        │                        │
 ┌─────┴─────┐                  │              ┌─────────┼─────────┐
 │           │                  │              │         │         │
 ▼           ▼                  ▼              ▼         ▼         ▼
Admin   RegularUser        Product Data       Type      Range     Format
 │           │                  │                        │
 └─────┬─────┘                  └──────────────┬─────────┘
       │                                      │
       ▼                                      ▼
 Authorization                         InventorySystem
                                              │
                       ┌──────────────────────┼──────────────────────┐
                       │                      │                      │
                       ▼                      ▼                      ▼
                 Sorted Records         Binary Search         File I/O
                       │                                         │
                       ▼                                         ▼
                Dynamic Storage                           inventory.txt
                       │
                       ▼
                    Product*
```

The standard Module 8 version focuses on validation. The separate Midway
Project extends the same architecture with dynamic memory and persistent
file storage.

---

# 📈 Application Evolution

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
Variables & Data Types
        │
        ▼
Module 04
External Dataset
CSV → Arrays → Pointers
        │
        ▼
Module 05
Records
Headers
Functions
        │
        ▼
Module 06
Classes
Objects
Encapsulation
        │
        ▼
Module 07
Roles
Permissions
Inheritance
Sorted Records
Binary Search
        │
        ▼
Module 08
Input Validation
Required Fields
Ranges
Dates
Duplicate Protection
        │
        ▼
Midway Project
Dynamic Memory
Pointers
File I/O
Persistent Storage
        │
        ▼
Future Modules
Databases
AI
Application Showcase
```

---

# 🔗 Data & Design Progression

```text
Variable
   │
   ▼
Array
   │
   ▼
Record
   │
   ▼
Functions
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
Sorted Records
   │
   ▼
Binary Search
   │
   ▼
Role-Based Access
   │
   ▼
Input Validation
   │
   ▼
Dynamic Memory
   │
   ▼
File I/O
   │
   ▼
Persistent Storage
   │
   ▼
Complete Inventory System
```

---

# 🔄 Development Workflow

```text
Plan
  │
  ▼
Write Code
  │
  ▼
Compile
  │
  ▼
Test
  │
  ▼
Review
  │
  ▼
Debug
  │
  ▼
Improve / Revise
  │
  ▼
Commit
  │
  ▼
Push
  │
  ▼
Verify on GitHub
  │
  ▼
Document
```

Typical Git workflow:

```bash
git add .
git commit -m "Complete Module 8 and Midway Project"
git push
```

---

# 🧪 Testing

Each module is tested before being considered complete.

The project has now been tested for:

```text
Compilation
User Input
Invalid Input
Application Flow
CSV Loading
Array Processing
Pointer Access
Record Creation
Calculations
Multi-File Compilation
Class Construction
Object Creation
Getters
Setters
Encapsulation
Inheritance
Permissions
Sorted Insertion
Binary Search
Record Deletion
Input Type Validation
Range Validation
Required Fields
Date Validation
Duplicate SKU Protection
Dynamic Memory
Pointer Access
File Loading
File Saving
Persistent Storage
Data Size Demonstration
Runtime Behavior
```

---

# ▶️ Building & Running

## Module 02

```bash
g++ inventory_manager.cpp -o inventory_manager
```

## Module 03

```bash
g++ inventory_welcome.cpp -o inventory_welcome
```

## Module 04

```bash
g++ inventory_dataset.cpp -o inventory_dataset
```

Required dataset:

```text
data/SuperMarket Analysis.csv
```

## Module 05

```bash
g++ main.cpp InventoryTools.cpp -o inventory_manager
```

## Module 06

```bash
g++ main.cpp Product.cpp -o inventory_manager
```

## Module 07

Compile all implementation files together:

```bash
g++ main.cpp Product.cpp User.cpp InventorySystem.cpp -o inventory_manager
```

## Module 08

```bash
g++ -std=c++17 main.cpp Product.cpp User.cpp InventorySystem.cpp InputValidator.cpp -o inventory_manager
```

## Midway Project

From inside the `Midterm/` folder:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic *.cpp -o inventory_manager
```

The Midway version reads and writes:

```text
inventory.txt
```

and includes:

```text
output.pdf
```

as the project report.

### Windows

```bash
inventory_manager.exe
```

### macOS / Linux

```bash
./inventory_manager
```

---

# 🔐 Repository Safety

This repository is public.

Sensitive or private information should never be committed.

Do not commit:

```text
Passwords
API Keys
Access Tokens
Private Credentials
Database Passwords
Authentication Secrets
Confidential Information
```

The Module 7 role system demonstrates authorization logic but is not
intended to be a production authentication system.

---

# 📈 Project Goal

The application currently demonstrates the following progression:

```text
Development Environment
        │
        ▼
Application Flow
        │
        ▼
Variables
        │
        ▼
External Dataset
        │
        ▼
CSV Input
        │
        ▼
Arrays & Pointers
        │
        ▼
Records
        │
        ▼
Headers & Functions
        │
        ▼
Classes & Objects
        │
        ▼
Encapsulation
        │
        ▼
Inheritance
        │
        ▼
Roles & Permissions
        │
        ▼
Sorted Records
        │
        ▼
Binary Search
        │
        ▼
Input Validation
        │
        ▼
Dynamic Memory
        │
        ▼
File I/O
        │
        ▼
Persistent Inventory Storage
```

The Midway Project demonstrates how the concepts introduced throughout the
first eight modules can work together inside one larger application.

Future modules will continue expanding the Inventory Manager with additional
application-design, database, and AI concepts.

---

# 📝 Current Status

```text
Project:       Inventory Manager
Language:      C++
Developer:     John Saldivar

Module 01:     Complete
Module 02:     Complete
Module 03:     Complete
Module 04:     Revised / Resubmitted
Module 05:     Complete
Module 06:     Complete
Module 07:     Complete
Module 08:     Complete

Modules Done:  8 / 15
Latest Module: Module 08

Module 04 Revision:
Kaggle CSV:    Included
CSV Parsing:   Implemented
Arrays:        Implemented
Pointers:      Implemented
Status:        Awaiting Regrade

Module 08:
Type Validation:      Implemented
Range Validation:     Implemented
Required Fields:      Implemented
Date Validation:      Implemented
Duplicate SKU Check:  Implemented
Retry Logic:          Implemented
Status:               Complete

Midway Project:
Inventory System:     Complete
Dynamic Memory:       Implemented
Pointers:             Implemented
Arrays:               Implemented
Binary Search:        Implemented
File I/O:             Implemented
Persistent Storage:   Implemented
Classes:              Implemented
Input Validation:     Implemented
output.pdf:            Complete
Status:                Complete

Repository:    Public
Development:   Active
```

---

# 🔗 Navigation

### Course Repository

[CPlusPlus-Application-Design](https://github.com/johnsaldivar/CPlusPlus-Application-Design)

### Developer

[John Saldivar](https://github.com/johnsaldivar)

### Modules

- ✅ [Module 01 — Development Environment Setup](./Module01-Setup/)
- ✅ [Module 02 — Menus, Switch Case & Application Flow](./Module02-Variables/)
- ✅ [Module 03 — Variables, Cin & Cout](./Module03-Datasets-Arrays-Pointers/)
- 🔄 [Module 04 — Datasets, Arrays & Pointers — Revised](./Module04-Functions-Headers/)
- ✅ [Module 05 — Records, Headers & Functions](./Module05-Classes-Objects/)
- ✅ [Module 06 — Creating Classes & Objects](./Module06-Records-Storage/)
- ✅ [Module 07 — Security, Roles & Binary Search](./Module07-Security-Search/)
- ✅ [Module 08 — Input Validation & Protecting Data](./Module08-Input-Validation/)
- 🎓 [Midway Project — Inventory Management System](./Midterm/)

---

<div align="center">

## 📦 Inventory Manager

### C++ Application Design

**John Saldivar**

![C++](https://img.shields.io/badge/C%2B%2B-Application%20Development-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Modules](https://img.shields.io/badge/Modules%20Completed-8%20of%2015-success?style=for-the-badge)
![Latest](https://img.shields.io/badge/Latest%20Module-08-blue?style=for-the-badge)
![Validation](https://img.shields.io/badge/Input-Validation-success?style=for-the-badge)
![Midway](https://img.shields.io/badge/Midway%20Project-Complete-success?style=for-the-badge)
![Search](https://img.shields.io/badge/Search-Binary%20Search-orange?style=for-the-badge)
![Revision](https://img.shields.io/badge/Module%2004-Awaiting%20Regrade-orange?style=for-the-badge)
![GitHub](https://img.shields.io/badge/Version%20Control-GitHub-181717?style=for-the-badge&logo=github)

**Build → Test → Improve → Connect**

</div>
