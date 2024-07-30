#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>

template<class T>
class Node {
public:
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr) {}
};
template <typename T>
class LinkedList {
public:

    void DisplayList() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << std::endl;
            current = current->next;
        }
    }

private:
    struct Node {
        T data;
        Node* next;
    };

    Node* head;
};
// LinkedList is a template class representing the linked list
template<class T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* current; // SeeNext 
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

    T* GetItem(const T& item);      
    bool IsInlist(const T& item) const; 
    bool IsEmpty() const;         
    int Size() const;             
    T* SeeNext();               
    T* SeeAt(int location);             
    void Reset();                       
    ~LinkedList();        

    void displayList() const {
        Node<T>* temp = head;
        while (temp != nullptr) {
            temp->data.display(); // Call the display method of the item
            temp = temp->next;
        }
    }              

};

template<class T>
void LinkedList<T>::AddItem(const T& item) {
    Node<T>* newNode = new Node<T>(item);
    
    // Insert in sorted order
    if (head == nullptr || head->data > item) {
        newNode->next = head;
        head = newNode;
    } else {
        Node<T>* temp = head;
        while (temp->next != nullptr && temp->next->data < item) {
            temp = temp->next;
        }
        newNode->next = temp->next;
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
                head = current->next; // Item is in the head node
            } else {
                previous->next = current->next; // Item is in a non-head node
            }
            T* foundItem = new T(current->data);
            delete current;
            size--;
            return foundItem;
        }
        previous = current;
        current = current->next;
    }
    return nullptr; // Item not found
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
    } else {
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
    current = temp->next; // Set the current pointer to the next item

    return &(temp->data);
}

// Implementation of Reset method
template<class T>
void LinkedList<T>::Reset() {
    current = nullptr;
}

// Destructor implementation
template<class T>
LinkedList<T>::~LinkedList() { // Fixed destructor syntax
    Node<T>* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


#endif
