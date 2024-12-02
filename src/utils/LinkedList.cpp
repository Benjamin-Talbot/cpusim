#include "LinkedList.h"

Node::Node(int data) {
    this->data = data;
    this->next = nullptr;
}

LinkedList::LinkedList(std::initializer_list<int> data) {
    const int* ptr = data.begin();
    this->head = new Node(ptr[0]);
    NODE current = this->head;
    for (int i = 1; i < data.size(); i++) {
        current->next = new Node(ptr[i]);
        current = current->next;
    }
}

void LinkedList::add(int data) {
    NODE node = new Node(data);
    node->next = this->head;
    this->head = node;
}

void LinkedList::printList() {
    NODE current = this->head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

LinkedList::Iterator::Iterator(NODE node) {
    this->current = node;
}

bool LinkedList::Iterator::operator!=(const Iterator& other) {
    return this->current != other.current;
}

int& LinkedList::Iterator::operator*() {
    return this->current->data;
}

LinkedList::Iterator& LinkedList::Iterator::operator++() {
    this->current = this->current->next;
    return *this;
}

int LinkedList::Iterator::next() {
    int data = this->current->data;
    this->current = this->current->next;
    return data;
}

LinkedList::Iterator LinkedList::begin() {
    return Iterator(this->head);
}

LinkedList::Iterator LinkedList::end() {
    return Iterator(nullptr);
}
