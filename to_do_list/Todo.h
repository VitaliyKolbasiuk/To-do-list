#pragma once

#include <iostream>
#include <vector>
#include <string>

class Todo {
    int m_todo_id = 1;
    std::string m_todo_name;
    std::string m_todo_description;

public:

    static void add_todo(std::vector<Todo>& todo_list, std::string name, std::string description) {
        Todo todo;
        if (!todo_list.empty()) {
            todo.m_todo_id = todo_list.back().m_todo_id + 1;
        }
        todo.m_todo_name = std::move(name);
        todo.m_todo_description = std::move(description);

        todo_list.emplace_back(todo);
    }

    static void edit_todo(std::vector<Todo>& todo_list, int todo_id, std::string name, std::string description) {
        todo_list[todo_id - 1].m_todo_name = std::move(name);
        todo_list[todo_id - 1].m_todo_description = std::move(description);
    }

    static void edit_todo_name(std::vector<Todo>& todo_list, int todo_id, std::string name) {
        todo_list[todo_id - 1].m_todo_name = std::move(name);
    }

    static void edit_todo_description(std::vector<Todo>& todo_list, int todo_id, std::string description) {
        todo_list[todo_id - 1].m_todo_description = std::move(description);
    }

    static void remove_todo(std::vector<Todo>& todo_list, int todo_id) {
        todo_list.erase(todo_list.cbegin() + todo_id - 1);
        for (int i = todo_id - 1; i < todo_list.size(); i++) {
            todo_list[i].m_todo_id--;
        }
    }

    static void show_todos(std::vector<Todo>& todo_list) {
        system("cls");
        if (todo_list.empty()) {
            std::cout << "There are no todos" << std::endl;
        }
        else {
            std::cout << "Todo id" << " | " << "Todo name" << " | " << "Todo description" << std::endl;
            for (const auto& todo : todo_list) {
                std::cout << todo.m_todo_id << " | " << todo.m_todo_name << " | " << todo.m_todo_description << std::endl;
            }
        }
    }
};