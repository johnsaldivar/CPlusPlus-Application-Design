#include "User.h"


User::User(const std::string& username)
{
    this->username = username;
}

std::string User::getUsername() const
{
    return username;
}


// ==========================
// Admin
// ==========================

Admin::Admin(const std::string& username)
    : User(username)
{
}

std::string Admin::getRole() const
{
    return "Admin";
}

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


// ==========================
// Regular User
// ==========================

RegularUser::RegularUser(const std::string& username)
    : User(username)
{
}

std::string RegularUser::getRole() const
{
    return "Regular User";
}

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
