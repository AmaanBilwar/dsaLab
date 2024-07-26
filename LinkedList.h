#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept> // For exceptions

// Node is a template class representing each element in the linked list
template<class T>
class Node {
public:
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr) {}
};

// LinkedList is a template class representing the linked list
template<class T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* current; // For SeeNext method
    int size;

public:
    // Constructor to initialize an empty list
    LinkedList() : head(nullptr), current(nullptr), size(0) {}

    // Method to add an item to the list
    void AddItem(const T& item);

    // Operator overloads
    bool operator>(const LinkedList<T>& other) const;
    bool operator<(const LinkedList<T>& other) const;
    bool operator==(const LinkedList<T>& other) const;

    // Debug method to print the list
    void PrintList() const;

    // New methods to be added
    T* GetItem(const T& item);          // Get and remove an item if it exists
    bool IsInlist(const T& item) const; // Check if an item is in the list
    bool IsEmpty() const;               // Check if the list is empty
    int Size() const;                   // Get number of items in the list
    T* SeeNext();                       // See the next item in the list
    T* SeeAt(int location);             // See an item at a specific location
    void Reset();                       // Reset the location for SeeNext
    ~LinkedList();                      // Destructor
};

template<class T>
void LinkedList<T>::AddItem(const T& item) {
    Node<T>* newNode = new Node<T>(item);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    size++;
}

// Operator > overload
template<class T>
bool LinkedList<T>::operator>(const LinkedList<T>& other) const {
    Node<T>* thisCurr = head;
    Node<T>* otherCurr = other.head;

    while (thisCurr != nullptr && otherCurr != nullptr) {
        if (thisCurr->data > otherCurr->data) {
            return true;
        } else if (thisCurr->data < otherCurr->data) {
            return false;
        }
        thisCurr = thisCurr->next;
        otherCurr = otherCurr->next;
    }

    // If this list is longer than the other list
    return (thisCurr != nullptr && otherCurr == nullptr);
}

// Operator < overload
template<class T>
bool LinkedList<T>::operator<(const LinkedList<T>& other) const {
    Node<T>* thisCurr = head;
    Node<T>* otherCurr = other.head;

    while (thisCurr != nullptr && otherCurr != nullptr) {
        if (thisCurr->data < otherCurr->data) {
            return true;
        } else if (thisCurr->data > otherCurr->data) {
            return false;
        }
        thisCurr = thisCurr->next;
        otherCurr = otherCurr->next;
    }

    // If this list is shorter than the other list
    return (thisCurr == nullptr && otherCurr != nullptr);
}

// Operator == overload
template<class T>
bool LinkedList<T>::operator==(const LinkedList<T>& other) const {
    Node<T>* thisCurr = head;
    Node<T>* otherCurr = other.head;

    while (thisCurr != nullptr && otherCurr != nullptr) {
        if (thisCurr->data != otherCurr->data) {
            return false;
        }
        thisCurr = thisCurr->next;
        otherCurr = otherCurr->next;
    }

    // Both lists should reach their end at the same time
    return (thisCurr == nullptr && otherCurr == nullptr);
}

// Method to print the linked list (for debugging purposes)
template<class T>
void LinkedList<T>::PrintList() const {
    Node<T>* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Implementation of GetItem method
template<class T>
T* LinkedList<T>::GetItem(const T& item) {
    Node<T>* current = head;
    Node<T>* previous = nullptr;

    while (current != nullptr) {
        if (current->data == item) {
            if (previous == nullptr) {
                // Item is in the head node
                head = current->next;
            } else {
                // Item is in a non-head node
                previous->next = current->next;
            }
            T* foundItem = new T(current->data);
            delete current;
            size--;
            return foundItem;
        }
        previous = current;
        current = current->next;
    }

    // Item not found
    return nullptr;
}

// Implementation of IsInlist method
template<class T>
bool LinkedList<T>::IsInlist(const T& item) const {
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->data == item) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Implementation of IsEmpty method
template<class T>
bool LinkedList<T>::IsEmpty() const {
    return head == nullptr;
}

// Implementation of Size method
template<class T>
int LinkedList<T>::Size() const {
    return size;
}

// Implementation of SeeNext method
template<class T>
T* LinkedList<T>::SeeNext() {
    if (head == nullptr) {
        throw std::runtime_error("List is empty");
    }

    if (current == nullptr) {
        current = head;
    } 
    else {
        current = current->next;
    }

    if (current != nullptr) {
        return &(current->data);
    } else {
        return nullptr;
    }
}

// Implementation of SeeAt method
template<class T>
T* LinkedList<T>::SeeAt(int location) {
    if (location >= size) {
        throw std::out_of_range("Location is out of range");
    }

    Node<T>* temp = head;
    for (int i = 0; i < location; ++i) {
        temp = temp->next;
    }
    current = temp->next;

    return &(temp->data);
}

// Implementation of Reset method
template<class T>
void LinkedList<T>::Reset() {
    current = nullptr;
}

//Destructor
template<class T>
LinkedList<T>::~
LinkedList() {
    Node<T>* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}
#endif