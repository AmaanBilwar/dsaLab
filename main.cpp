#include "LinkedList.h"
#include "Student.h"
#include <iostream>
#include <ctime> 


// Helper function to create a std::tm struct for birthdays
std::tm CreateBirthday(int year, int month, int day) {
    std::tm birthday = {};
    birthday.tm_year = year - 1900; // Years since 1900
    birthday.tm_mon = month - 1;    // Months since January (0-11)
    birthday.tm_mday = day;
    return birthday;
}

int main() {


    // Create some Student objects
    std::tm birth1 = CreateBirthday(2000, 5, 15);
    Student student1("John", "Doe", "M00012345", birth1, 3.5);

    std::tm birth2 = CreateBirthday(1999, 8, 20);
    Student student2("Jane", "Smith", "M00012346", birth2, 3.8);
    std::tm birth3 = CreateBirthday(2001, 12, 30);
    Student student3("Alice", "Brown", "M00012347", birth3);

    
    //Print student details
    std::cout << "Student 1: " << student1.GetName() << ", MNumber: " << student1.GetMNumber() << ", Age: " 
              << student1.GetAge() << std::endl;
    std::cout << "Student 2: " << student2.GetName() << ", MNumber: " << student2.GetMNumber() << ", Age: " 
              << student2.GetAge() << std::endl;
    std::cout << "Student 3: " << student3.GetName() << ", MNumber: " << student3.GetMNumber() << ", Age: " 
              << student3.GetAge() << std::endl;

    // Create a LinkedList of Students
    LinkedList<Student> studentList;
    studentList.AddItem(student1);
    studentList.AddItem(student2);
    studentList.AddItem(student3);

    // Print the list
    studentList.PrintList(); // Should print the details of the students

    // Test operator overloads
    if (student1 > student2) {
        std::cout << "Student 1 has a greater MNumber than Student 2" << std::endl;
    } else if (student1 < student2) {
        std::cout << "Student 1 has a lesser MNumber than Student 2" << std::endl; // Should print this
    } else if (student1 == student2) {
        std::cout << "Student 1 and Student 2 have the same MNumber" << std::endl;
    }

    // Test LinkedList methods
    Student* pStudent = studentList.GetItem(student2);
    if (pStudent != nullptr) {
        std::cout << "Got student: " << *pStudent << std::endl;
        delete pStudent;
    }

    studentList.PrintList(); // Should print the details of the remaining students




    LinkedList<int> list1;
    list1.AddItem(1);
    list1.AddItem(3);
    list1.AddItem(5);

    list1.PrintList(); // Should print: 1 -> 3 -> 5 -> nullptr

    LinkedList<int> list2;
    list2.AddItem(2);
    list2.AddItem(4);

    list2.PrintList(); // Should print: 2 -> 4 -> nullptr

    // Testing operator overloads
    if (list1 > list2) {
        std::cout << "list1 is greater than list2" << std::endl;
    } else if (list1 < list2) {
        std::cout << "list1 is less than list2" << std::endl; // Should print this
    } else if (list1 == list2) {
        std::cout << "list1 is equal to list2" << std::endl;
    }


// Create another list with the same values as list1
    LinkedList<int> list3;
    list3.AddItem(1);
    list3.AddItem(3);
    list3.AddItem(5);

    if (list1 == list3) {
        std::cout << "list1 is equal to list3" << std::endl; // Should print this
    }

// Test GetItem
    int* item = list1.GetItem(3);
    if (item != nullptr) {
        std::cout << "Got item: " << *item << std::endl; // Should print: Got item: 3
        delete item;
    } else {
        std::cout << "Item not found" << std::endl;
    }
    list1.PrintList(); // Should print: 1 -> 5 -> nullptr
     
     
     
     // Test IsInlist
    if (list1.IsInlist(5)) {
        std::cout << "5 is in the list" << std::endl;
    } else {
        std::cout << "5 is not in the list" << std::endl;
    }

    // Test IsEmpty
    if (list1.IsEmpty()) {
        std::cout << "list1 is empty" << std::endl;
    } else {
        std::cout << "list1 is not empty" << std::endl; // Should print this
    }

    // Test Size
    std::cout << "Size of list1: " << list1.Size() << std::endl; // Should print: Size of list1: 2

     // Test SeeNext
    list1.Reset(); // Reset position to head
    int* nextItem = list1.SeeNext();
    if (nextItem != nullptr) {
        std::cout << "Next item: " << *nextItem << std::endl; // Should print: Next item: 1
    }
    nextItem = list1.SeeNext();
    if (nextItem != nullptr) {
        std::cout << "Next item: " << *nextItem << std::endl; // Should print: Next item: 5
    }
    nextItem = list1.SeeNext();
    if (nextItem == nullptr) {
        std::cout << "No more items" << std::endl; // Should print: No more items
    }
    // Test SeeAt
    list1.AddItem(7);
    try {
        int* seeAtItem = list1.SeeAt(1);
        std::cout << "Item at position 1: " << *seeAtItem << std::endl; // Should print: Item at position 1: 5
    } catch (const std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        int* seeAtItem = list1.SeeAt(3); // Attempt to access out-of-range index
        std::cout << "Item at position 3: " << *seeAtItem << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << e.what() << std::endl; // Should print: Location is out of range
    }
        // Remove all elements to test IsEmpty
    list1.GetItem(1);
    list1.GetItem(5);
    list1.GetItem(7);

    if (list1.IsEmpty()) {
        std::cout << "list1 is empty" << std::endl; // Should print this now
    } else {
        std::cout << "list1 is not empty" << std::endl;
    }

    return 0;
}