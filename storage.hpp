#ifndef STORAGE_HPP
#define STORAGE_HPP

#include "user.hpp"
#include <vector>
#include <algorithm>

class Storage {
public:
    void add_user(const User& user);
    void delete_user(const std::string& name);
    void search_user(const std::string& name) const;
    void show_all_users() const;
    void save_to_file(const std::string& filename) const;
    void load_from_file(const std::string& filename);

private:
    std::vector<User> users;
};

#endif // STORAGE_HPP
