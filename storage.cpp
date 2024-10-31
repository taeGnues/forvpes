#include "storage.hpp"
#include <fstream>
#include <iostream>

void Storage::add_user(const User& user) {
    users.push_back(user);
    std::cout << "User added: " << user.get_name() << "\n";
}

void Storage::delete_user(const std::string& name) {
    auto it = std::remove_if(users.begin(), users.end(), [&name](const User& user) {
        return user.get_name() == name;
    });
    
    if (it != users.end()) {
        users.erase(it, users.end());
        std::cout << "User deleted: " << name << "\n";
    } else {
        std::cout << "User not found: " << name << "\n";
    }
}

void Storage::search_user(const std::string& name) const {
    for (const auto& user : users) {
        if (user.get_name() == name) {
            std::cout << "Found User - Name: " << user.get_name() << ", Age: " << user.get_age() << "\n";
            return;
        }
    }
    std::cout << "User not found: " << name << "\n";
}

void Storage::show_all_users() const {
    std::cout << "All Users:\n";
    for (const auto& user : users) {
        std::cout << "Name: " << user.get_name() << ", Age: " << user.get_age() << "\n";
    }
}

void Storage::save_to_file(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& user : users) {
            file << user.get_name() << "\n" << user.get_age() << "\n";
        }
        std::cout << "Users saved to " << filename << "\n";
    } else {
        std::cout << "Failed to open file " << filename << "\n";
    }
}

void Storage::load_from_file(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        users.clear();
        std::string name;
        int age;
        while (std::getline(file, name) && file >> age) {
            file.ignore(); // 나머지 줄을 비웁니다.
            users.emplace_back(name, age);
        }
        std::cout << "Users loaded from " << filename << "\n";
    } else {
        std::cout << "Failed to open file " << filename << "\n";
    }
}
