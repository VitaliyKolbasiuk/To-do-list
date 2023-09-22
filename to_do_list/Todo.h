#pragma once

#include <iostream>
#include <vector>
#include <string>

class Todo {
    int m_todoId = 1;
    std::string m_todoName;
    std::string m_todoDescription;

public:

    static void add_todo(std::vector<Todo>& todoList, std::string name, std::string description) {
        Todo todo;
        if (!todoList.empty()) {
            todo.m_todoId = todoList.back().m_todoId + 1;
        }
        todo.m_todoName = name;
        todo.m_todoDescription = description;

        todoList.emplace_back(todo);
    }

    static void edit_todo(std::vector<Todo>& todoList, const int& todoId, std::string name, std::string description) {
        todoList[todoId - 1].m_todoName = name;
        todoList[todoId - 1].m_todoDescription = description;
    }

    static void edit_todo_name(std::vector<Todo>& todoList, const int& todoId, std::string name) {
        todoList[todoId - 1].m_todoName = name;
    }

    static void edit_todo_description(std::vector<Todo>& todoList, const int& todoId, std::string description) {
        todoList[todoId - 1].m_todoDescription = description;
    }

    static void remove_todo(std::vector<Todo>& todoList, const int& todoId) {
        todoList.erase(todoList.cbegin() + todoId - 1);
        for (int i = todoId - 1; i < todoList.size(); i++) {
            todoList[i].m_todoId--;
        }
    }

    static void show_todos(std::vector<Todo>& todoList) {
        system("cls");
        if (todoList.empty()) {
            std::cout << "There are no todos" << std::endl;
        }
        else {
            std::cout << "Todo id" << " | " << "Todo name" << " | " << "Todo description" << std::endl;
            for (const auto& todo : todoList) {
                std::cout << todo.m_todoId << " | " << todo.m_todoName << " | " << todo.m_todoDescription << std::endl;
            }
        }
    }
};