#include "Todo.h"

int getUserChoice() {
    int user_action;
    std::cout << std::endl << "Choose action:" << std::endl;
    std::cout << "1. Show all todos" << std::endl;
    std::cout << "2. Add todo" << std::endl;
    std::cout << "3. Edit todo" << std::endl;
    std::cout << "4. Remove todo" << std::endl;
    std::cout << "5. Stop program" << std::endl;
    std::cin >> user_action;
    return user_action;
}

int main() {
    std::vector<Todo> todo_list;

    while (true) {
        int user_action_two;

        std::string name;
        std::string description;
        int todo_id;

        switch (getUserChoice()) {
        case 1:
            Todo::show_todos(todo_list);
            break;
        case 2:
            std::cout << "Write name of your todo:" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Write description of your todo:" << std::endl;
            std::getline(std::cin, description);

            Todo::add_todo(todo_list, name, description);
            break;
        case 3:
            std::cout << "1. Edit name" << std::endl;
            std::cout << "2. Edit description" << std::endl;
            std::cout << "3. Edit name and description" << std::endl;

            std::cin >> user_action_two;

            std::cout << "Enter todo id" << std::endl;
            std::cin >> todo_id;


            switch (user_action_two) {
            case 1:
                std::cout << "Enter new todo name" << std::endl;
                std::cin.ignore();
                std::getline(std::cin, name);

                Todo::edit_todo_name(todo_list, todo_id, name);
                break;
            case 2:
                std::cout << "Enter new todo description" << std::endl;
                std::cin.ignore();
                std::getline(std::cin, description);

                Todo::edit_todo_description(todo_list, todo_id, description);
                break;
            case 3:
                std::cout << "Enter new todo name" << std::endl;
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter new todo description" << std::endl;
                std::getline(std::cin, description);

                Todo::edit_todo(todo_list, todo_id, name, description);
                break;
            default:
                std::cout << "You entered wrong number" << std::endl;
                break;
            }
            break;

        case 4:
            std::cout << "Enter todo id" << std::endl;
            std::cin >> todo_id;

            Todo::remove_todo(todo_list, todo_id);
            break;

        case 5:
            return 0;
        default:
            std::cout << "You entered wrong number" << std::endl;
            break;
        }
    }
}