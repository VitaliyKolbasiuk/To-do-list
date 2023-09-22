#include "Todo.h"

int getUserChoice() {
    int userAction = -1;
    std::cout << std::endl << "Choose action:" << std::endl;
    std::cout << "1. Show all todos" << std::endl;
    std::cout << "2. Add todo" << std::endl;
    std::cout << "3. Edit todo" << std::endl;
    std::cout << "4. Remove todo" << std::endl;
    std::cout << "5. Stop program" << std::endl;
    std::cin >> userAction;
    if (userAction < 1 || userAction > 5) {
        std::cout << "Wrong input" << std::endl;
        exit(-1);
    }
    return userAction;
}

int main() {
    std::vector<Todo> todoList;

    while (true) {
        int userActionTwo;

        std::string name;
        std::string description;
        int todoId;

        switch (getUserChoice()) {
            case 1: {
                Todo::show_todos(todoList);
                break;
            }
            case 2: {
                std::cout << "Write name of your todo:" << std::endl;
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Write description of your todo:" << std::endl;
                std::getline(std::cin, description);

                Todo::add_todo(todoList, std::move(name), std::move(description));
                break;
            }
            case 3: {
                std::cout << "1. Edit name" << std::endl;
                std::cout << "2. Edit description" << std::endl;
                std::cout << "3. Edit name and description" << std::endl;

                std::cin >> userActionTwo;

                std::cout << "Enter todo id" << std::endl;
                std::cin >> todoId;


                switch (userActionTwo) {
                    case 1:
                        std::cout << "Enter new todo name" << std::endl;
                        std::cin.ignore();
                        std::getline(std::cin, name);

                        Todo::edit_todo_name(todoList, todoId, name);
                        break;
                    case 2:
                        std::cout << "Enter new todo description" << std::endl;
                        std::cin.ignore();
                        std::getline(std::cin, description);

                        Todo::edit_todo_description(todoList, todoId, description);
                        break;
                    case 3:
                        std::cout << "Enter new todo name" << std::endl;
                        std::cin.ignore();
                        std::getline(std::cin, name);
                        std::cout << "Enter new todo description" << std::endl;
                        std::getline(std::cin, description);

                        Todo::edit_todo(todoList, todoId, name, description);
                        break;
                    default:
                        std::cout << "You entered wrong number" << std::endl;
                        break;
                }
                break;
            }
            case 4:
                std::cout << "Enter todo id" << std::endl;
                std::cin >> todoId;

                Todo::remove_todo(todoList, todoId);
                break;

            case 5:
                return 0;
            default:
                std::cout << "You entered wrong number" << std::endl;
                break;
        }
    }
}