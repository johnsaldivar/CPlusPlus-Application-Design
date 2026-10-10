<div align="center">

# 🔐 Module 07 — Security, Roles & Binary Search

### 📦 Inventory Manager

[![Module](https://img.shields.io/badge/Module-07-4C8BF5?style=for-the-badge)](./)
[![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![Project](https://img.shields.io/badge/Project-Inventory%20Manager-2ea44f?style=for-the-badge)](#)
[![Security](https://img.shields.io/badge/Security-Role%20Based-purple?style=for-the-badge)](#)
[![Search](https://img.shields.io/badge/Search-Binary%20Search-orange?style=for-the-badge)](#)
[![Status](https://img.shields.io/badge/Status-Complete-success?style=for-the-badge)](#)

**Author:** [John Saldivar](https://github.com/johnsaldivar)

</div>

---

# 📖 Overview

Module 7 introduces **role-based permissions, access control, inheritance,
sorted records, and binary search**.

The Inventory Manager now supports two user roles:

- Admin
- Regular User

The Admin role can:

- View records
- Search records
- Add records
- Delete records

The Regular User role can:

- View records
- Search records

Regular Users are denied permission to add or delete inventory records.

Inventory records are also maintained in sorted SKU order so the
application can efficiently locate a product using binary search.

---

# ✅ Assignment Requirements

The Module 7 assignment requires:

1. Create Admin and Regular User roles.
2. Restrict application actions based on the user's role.
3. Allow Admin users to add records.
4. Allow Admin users to view records.
5. Allow Admin users to delete records.
6. Allow Regular Users to view records.
7. Store records in sorted order.
8. Implement binary search.
9. Search for a record using an ID or another unique field.
10. Connect the new functionality to the larger application.

This Inventory Manager implementation satisfies each requirement.

| Assignment Requirement | Implementation |
|---|---|
| Admin role | `Admin` class |
| Regular User role | `RegularUser` class |
| Shared user class | `User` |
| Admin can view | `canView()` |
| Admin can add | `canAdd()` |
| Admin can delete | `canDelete()` |
| Regular User can view | `canView()` |
| Regular User cannot add | Access denied |
| Regular User cannot delete | Access denied |
| Sorted records | Sorted automatically by SKU |
| Binary search | `binarySearchBySku()` |
| Unique search field | SKU |
| Application integration | Inventory Manager |

---

# 👤 User Roles

The application uses a base `User` class.

```cpp
class User
{
protected:
    std::string username;

public:
    User(const std::string& username);

    virtual ~User() = default;

    std::string getUsername() const;

    virtual std::string getRole() const = 0;

    virtual bool canView() const = 0;
    virtual bool canAdd() const = 0;
    virtual bool canDelete() const = 0;
};
```

The `username` field uses:

```cpp
protected:
```

This allows derived role classes to inherit from `User`.

---

# 👑 Admin Role

The Admin class inherits from User:

```cpp
class Admin : public User
```

Admin permissions are:

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

Therefore an Admin can:

```text
View Records     ✅
Search Records   ✅
Add Records      ✅
Delete Records   ✅
```

---

# 👤 Regular User Role

The Regular User class also inherits from User:

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

Therefore a Regular User can:

```text
View Records     ✅
Search Records   ✅
Add Records      ❌
Delete Records   ❌
```

---

# 🔐 Role-Based Authorization

Before an application action is performed, the user's permission is
checked.

For example:

```cpp
if (!currentUser.canAdd())
{
    std::cout
        << "Access denied: Regular Users cannot add records.\n";

    break;
}
```

Delete permission is checked in the same way:

```cpp
if (!currentUser.canDelete())
{
    std::cout
        << "Access denied: Regular Users cannot delete records.\n";

    break;
}
```

This demonstrates basic **role-based authorization**.

> This assignment demonstrates permission logic for application design.
> It is not intended to represent a production authentication system.

---

# 🧱 Inheritance

Module 7 builds on the object-oriented programming introduced in Module 6.

```text
                User
                 │
          ┌──────┴──────┐
          │             │
          ▼             ▼
        Admin      RegularUser
```

Both `Admin` and `RegularUser` inherit common behavior from the `User`
class.

This reduces duplicated code and creates a shared interface for
permissions.

---

# 🔒 Access Modifiers

The project demonstrates all three common C++ access levels.

## Private

Product data and Inventory System data use:

```cpp
private:
```

Example:

```cpp
private:
    int sku;
    std::string name;
    int quantity;
    double price;
```

---

## Protected

The User class uses:

```cpp
protected:
```

for:

```cpp
std::string username;
```

This allows derived classes to inherit the value.

---

## Public

Constructors, getters, permission functions, and inventory operations use:

```cpp
public:
```

These functions form the public interface used by the application.

---

# 📦 Product Records

Inventory records are represented by Product objects.

Each Product contains:

```text
SKU
Product Name
Quantity
Price
```

The SKU acts as the unique record identifier.

Example:

```text
SKU:       1005
Product:   Air Filter
Quantity:  7
Price:     $14.49
```

---

# 📊 Sorted Records

Binary search requires the records to remain sorted.

The Inventory Manager stores products in ascending SKU order.

Initial records:

```text
1001 — Brake Pads
1002 — Oil Filter
1005 — Air Filter
1010 — Spark Plugs
```

If an Admin adds:

```text
1003 — Engine Cleaner
```

the application does not simply append it.

Instead, it inserts the record into the correct position:

```text
1001 — Brake Pads
1002 — Oil Filter
1003 — Engine Cleaner
1005 — Air Filter
1010 — Spark Plugs
```

This ensures the records remain sorted.

---

# ➕ Sorted Insertion

The application finds the correct insertion position:

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

Existing records are shifted:

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

The new record is then inserted:

```cpp
products[insertIndex] = product;
```

Because every new product is inserted this way, the data stays sorted.

---

# 🔍 Binary Search

The application searches products using:

```cpp
int binarySearchBySku(
    int targetSku
) const;
```

Binary search begins with the entire sorted collection:

```text
Left                           Right
 ↓                               ↓
1001   1002   1005   1010
```

It checks the middle value and repeatedly eliminates half of the
remaining search area.

---

## Binary Search Implementation

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

If a matching SKU is found, its array index is returned.

If no match exists:

```cpp
return -1;
```

---

# 🔎 Search Example

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

Both roles see the application menu, but actions are restricted according
to their permissions.

---

# 👑 Admin Example

```text
Choose a role:
1. Admin
2. Regular User

Selection: 1

Logged in as: admin_user (Admin)
```

The Admin can:

```text
View
Search
Add
Delete
```

---

# 👤 Regular User Example

```text
Choose a role:
1. Admin
2. Regular User

Selection: 2

Logged in as: regular_user (Regular User)
```

Attempting to add a record displays:

```text
Access denied: Regular Users cannot add records.
```

Attempting to delete a record displays:

```text
Access denied: Regular Users cannot delete records.
```

---

# 🔀 Application Flow

```text
                     Program Starts
                           │
                           ▼
                         main()
                           │
                           ▼
                      showWelcome()
                           │
                           ▼
                  Create InventorySystem
                           │
                           ▼
                     Seed Records
                           │
                           ▼
                  Create User Objects
                           │
                ┌──────────┴──────────┐
                │                     │
                ▼                     ▼
              Admin              RegularUser
                │                     │
                └──────────┬──────────┘
                           │
                           ▼
                       chooseRole()
                           │
                           ▼
                    runApplication()
                           │
                           ▼
                       Menu Choice
                           │
       ┌───────────────────┼────────────────────┐
       │                   │                    │
       ▼                   ▼                    ▼
      View               Search              Modify
       │                   │                    │
       ▼                   ▼                    ▼
Permission Check     Binary Search       Permission Check
                                             │
                                    ┌────────┴────────┐
                                    │                 │
                                    ▼                 ▼
                                   Add              Delete
```

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
```

Module 7 builds directly on the Product class and object-oriented concepts
introduced in Module 6.

---

# 🧩 Current Architecture

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

# 📁 Module Files

```text
Module07-Security-Search/
│
├── README.md
├── main.cpp
├── Product.h
├── Product.cpp
├── User.h
├── User.cpp
├── InventorySystem.h
└── InventorySystem.cpp
```

### `main.cpp`

Contains:

- Program entry point
- Role selection
- Application menu
- Permission checks
- Input handling

### `Product.h` / `Product.cpp`

Contain:

- Product class
- Product data
- Product display functionality

### `User.h` / `User.cpp`

Contain:

- User base class
- Admin class
- RegularUser class
- Role permissions

### `InventorySystem.h` / `InventorySystem.cpp`

Contain:

- Product record storage
- Sorted insertion
- Record deletion
- Record display
- Binary search
- Search result display

---

# 🧪 Testing

Module 7 was compiled and fully tested using both available user roles.

## Admin Tests

- [x] Log in as Admin
- [x] View records
- [x] Search existing SKU `1005`
- [x] Search missing SKU `9999`
- [x] Add SKU `1003`
- [x] Verify SKU `1003` is inserted between `1002` and `1005`
- [x] Search newly added SKU
- [x] Delete SKU `1003`
- [x] Verify the deleted record is removed
- [x] Exit normally

---

## Regular User Tests

- [x] Log in as Regular User
- [x] View records
- [x] Search existing SKU `1005`
- [x] Attempt to add a record
- [x] Verify Add is denied
- [x] Attempt to delete a record
- [x] Verify Delete is denied
- [x] Exit normally

---

# ✅ Module 7 Checklist

- [x] User base class created
- [x] Admin role created
- [x] Regular User role created
- [x] Admin can view records
- [x] Admin can search records
- [x] Admin can add records
- [x] Admin can delete records
- [x] Regular User can view records
- [x] Regular User can search records
- [x] Regular User is prevented from adding records
- [x] Regular User is prevented from deleting records
- [x] Role permission checks implemented
- [x] Inheritance demonstrated
- [x] `private` access demonstrated
- [x] `protected` access demonstrated
- [x] `public` access demonstrated
- [x] Product SKU used as unique identifier
- [x] Records stored in sorted SKU order
- [x] New records inserted in sorted order
- [x] Binary search implemented
- [x] Existing record can be found using binary search
- [x] Missing record returns not found
- [x] Module connected to Inventory Manager
- [x] Program compiled successfully
- [x] Admin role fully tested
- [x] Regular User role fully tested
- [x] Module 7 files uploaded to GitHub
- [x] Module 7 completed

---

# 🎉 Module 7 Status

```text
Module:          07
Topic:           Security, Roles & Binary Search

Build:           Successful
Admin Testing:   Passed
User Testing:    Passed

Admin Role:      Implemented
Regular User:    Implemented
Permissions:     Implemented
Inheritance:     Implemented

Sorted Records:  Implemented
Sorted Insert:   Passed
Binary Search:   Passed

GitHub Upload:   Complete
Status:          ✅ Complete
```

---

# ▶️ Building & Running

Compile all implementation files together:

```bash
g++ main.cpp Product.cpp User.cpp InventorySystem.cpp -o inventory_manager
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

Module 7 creates the foundation for more advanced application security and
data access.

Future versions can expand this system with:

```text
Username / Password Authentication
        │
        ▼
Role-Based Authorization
        │
        ▼
Product Collections
        │
        ▼
Binary Search
        │
        ▼
Persistent Files
        │
        ▼
Database
        │
        ▼
Full Inventory Application
```

Potential future improvements include:

- Persistent user accounts
- Password authentication
- Additional user roles
- More detailed permissions
- Record editing
- File-based inventory storage
- Database-backed product storage
- Larger product collections
- Additional search options

---

# 🔗 Links

**Developer**  
[John Saldivar](https://github.com/johnsaldivar)

**Course Repository**  
[CPlusPlus-Application-Design](https://github.com/johnsaldivar/CPlusPlus-Application-Design)

**Previous Module**  
[Module 06 — Creating Classes & Objects](../Module06-Records-Storage/)

**Next Module**  
[Module 08](../Module08-Input-Validation/)

---

<div align="center">

## 📦 Inventory Manager

### Module 07 — Security, Roles & Binary Search

**John Saldivar**

![C++](https://img.shields.io/badge/C%2B%2B-OOP%20%7C%20Algorithms-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Security](https://img.shields.io/badge/Security-Role%20Based-purple?style=for-the-badge)
![Search](https://img.shields.io/badge/Search-Binary%20Search-orange?style=for-the-badge)
![Architecture](https://img.shields.io/badge/Architecture-Inheritance-success?style=for-the-badge)
![Status](https://img.shields.io/badge/Module-Complete-success?style=for-the-badge)

**Build → Test → Improve → Connect**

</div>
