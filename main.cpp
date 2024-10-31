#include <iostream>
#include "user.hpp"
#include "storage.hpp"

void print_menu() {
    std::cout << "\n1. Add User\n2. Delete User\n3. Search User\n4. Show All Users\n5. Save to File\n6. Load from File\n0. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    Storage storage;
    int choice;

    do {
        print_menu();
        std::cin >> choice;
        std::cin.ignore(); // 입력 버퍼 비우기

        if (choice == 1) {
            std::string name;
            int age;
            std::cout << "Enter name: ";
            std::getline(std::cin, name);
            std::cout << "Enter age: ";
            std::cin >> age;
            storage.add_user(User(name, age));
        }
        else if (choice == 2) {
            std::string name;
            std::cout << "Enter name to delete: ";
            std::getline(std::cin, name);
            storage.delete_user(name);
        }
        else if (choice == 3) {
            std::string name;
            std::cout << "Enter name to search: ";
            std::getline(std::cin, name);
            storage.search_user(name);
        }
        else if (choice == 4) {
            storage.show_all_users();
        }
        else if (choice == 5) {
            storage.save_to_file("user_data.txt");
        }
        else if (choice == 6) {
            storage.load_from_file("user_data.txt");
        }
    } while (choice != 0);

    return 0;
}
