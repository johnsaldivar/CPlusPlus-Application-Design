#ifndef USER_H
#define USER_H

#include <string>

class User
{
protected:
    std::string username;

public:
    explicit User(const std::string& username);
    virtual ~User() = default;

    std::string getUsername() const;

    virtual std::string getRole() const = 0;
    virtual bool canView() const = 0;
    virtual bool canAdd() const = 0;
    virtual bool canDelete() const = 0;
};

class Admin : public User
{
public:
    explicit Admin(const std::string& username);

    std::string getRole() const override;
    bool canView() const override;
    bool canAdd() const override;
    bool canDelete() const override;
};

class RegularUser : public User
{
public:
    explicit RegularUser(const std::string& username);

    std::string getRole() const override;
    bool canView() const override;
    bool canAdd() const override;
    bool canDelete() const override;
};

#endif
