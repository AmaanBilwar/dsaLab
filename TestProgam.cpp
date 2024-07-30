#include <iostream>
#include <string>
#include "Student.h"
#include "LinkedList.h"

using namespace std;

void AddStudent(LinkedList<Student>& studentList) {
    string firstName, lastName, mNumber;
    int year, month, day;
    double gpa;

    cout << "Enter First Name: ";
    cin >> firstName;
    cout << "Enter Last Name: ";
    cin >> lastName;
    cout << "Enter MNumber: ";
    cin >> mNumber;
    cout << "Enter Birth Year: ";
    cin >> year;
    cout << "Enter Birth Month: ";
    cin >> month;
    cout << "Enter Birth Day: ";
    cin >> day;
    cout << "Enter GPA: ";
    cin >> gpa;

    tm birthday = {};
    birthday.tm_year = year - 1900; // tm_year is year since 1900
    birthday.tm_mon = month - 1;    // tm_mon is months since January (0-11)
    birthday.tm_mday = day;

    Student student(firstName, lastName, mNumber, birthday, gpa);
    studentList.AddItem(student);
    cout << "Student added successfully.\n";
}

void GetStudent(LinkedList<Student>& studentList) {
    string mNumber;
    cout << "Enter MNumber: ";
    cin >> mNumber;

    Student temp("", "", mNumber, {}, 0.0); // Create a temporary student object with the MNumber
    Student foundStudent;
    if (studentList.GetItem(temp, foundStudent)) {
        cout << "Student found: " << foundStudent << endl;
    } else {
        cout << "Student with MNumber " << mNumber << " not found.\n";
    }
}

int main() {
    LinkedList<Student> studentList;

    while (true) {
        std::cout << "Options:" << std::endl;
        std::cout << "1. Add student" << std::endl;
        std::cout << "2. Display list" << std::endl;
        std::cout << "3. Exit" << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                // ... existing code to add student ...
                break;
            case 2:
                list.displayList();
                break;
            case 3:
                return 0;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
    }

    return 0;
}
