#ifndef LINKEDTLIST_H
#define LINKEDTLIST_H

#include <iostream>
#include <initializer_list>

class Node {
public:
    int data;
    Node* next;
    Node(int data);
};
typedef Node* NODE;

class LinkedList {
public:
    NODE head;
    NODE current;
    LinkedList(std::initializer_list<int> data);
    void add(int data);
    void printList();
    class Iterator {
        public:
            NODE current;
            Iterator(NODE node);
            bool operator!=(const Iterator& other);
            int& operator*();
            Iterator& operator++();
            int next();
    };
    
    Iterator begin();
    Iterator end();
};
typedef LinkedList* LINKEDLIST;


#endif