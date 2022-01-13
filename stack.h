//
// Created by krasn on 05.01.2022.
//

#include <iostream>
#include <stdexcept>
#ifndef BLACKJACK_STACK_H
#define BLACKJACK_STACK_H


template <class T>
class Stack {
public:
    Stack() : root (nullptr) {} //По умолчанию стек пуст

    void push(const T& x) { //Передаем по константной ссылке
        Node* new_node = new Node;
        new_node->data = x;
        new_node->next = root;
        root = new_node;
    }

    bool empty() const {
        return root == nullptr;
    }

    const T& top() const {
        if (empty()) {
            throw length_error("stack is empty");
        }
        return  root->data;
    }

    T pop() { //void pop() ???
        if (empty()) {
            throw length_error("stack is empty");
        }
        Node * del_node = root;
        T return_data = del_node->data;
        root = del_node->next;
        delete del_node;
        return return_data;
    }

    void print() { //void pop() ???
        if (empty()) {
            throw length_error("stack is empty");
        }
        Node * del_node = root;
        while (del_node != nullptr) {
            T return_data = del_node->data;
            del_node = del_node->next;
            std::cout << return_data.first << " ";
        }
    }

    void clear() {
        while (root != nullptr) {
            pop();
        }
    }


    ~Stack() { //деструктор
        while (!empty()) {
            pop();
        }
    }

private:
    struct Node {
        T data; //Поле с данными
        Node *next; //Указатель на следующий
    };
    Node* root; //Вершина стека

}; //Stack


#endif //BLACKJACK_STACK_H
