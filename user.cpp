#include "user.hpp"

User::User(const std::string& name, int age) : name(name), age(age) {}

std::string User::get_name() const {
    return name;
}

int User::get_age() const {
    return age;
}
