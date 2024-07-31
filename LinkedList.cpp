#include "LinkedList.h"
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

namespace MyLinkedList {
    struct Node {
        int data;
        Node* next;
    };
}
Node* head = nullptr;

void insert(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void printList() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    std::cout << "Linked List: ";
    printList();

    return 0;
}
#endif // LINKEDLIST_H
