#ifndef USER_HPP
#define USER_HPP

#include <string>

class User {
public:
    User(const std::string& name, int age);

    std::string get_name() const;
    int get_age() const;

private:
    std::string name;
    int age;
};

#endif // USER_HPP
