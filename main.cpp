#include "LinkedList.h"
#include "Student.h"
#include <iostream>
#include <ctime> 

using namespace std; 


tm CreateBirthday(int year, int month, int day) {
    tm birthday = {};
    birthday.tm_year = year - 1900; 
    birthday.tm_mon = month - 1;  
    birthday.tm_mday = day;
    return birthday;
}

// Function to display the menu
void DisplayMenu() { 
    cout << "Select an option:\n";
    cout << "1. Add Student\n";
    cout << "2. Get Student by MNumber\n";
    cout << "3. Check if Student is in the list\n";
    cout << "4. Display all Students\n"; 
    cout << "5. Check if the list is empty\n"; 
    cout << "6. Get size of the list\n"; 
    cout << "7. Exit\n";
}

int main() {
    LinkedList<Student> studentList; 
    int choice;

    while (true) {
        DisplayMenu(); 
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { 
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
                cout << "Enter GPA (or 0 for no GPA): ";
                cin >> gpa;

                std::tm birth = CreateBirthday(year, month, day);
                Student newStudent(firstName, lastName, mNumber, birth, gpa);
                studentList.AddItem(newStudent); 
                break;
            }
            case 2: {
                string mNumber;
                cout << "Enter MNumber: ";
                cin >> mNumber;
                Student* foundStudent = studentList.GetItem(Student("", "", mNumber, {}, 0.0)); 
                if (foundStudent) {
                    cout << "Found Student: " << *foundStudent << endl;
                    delete foundStudent;
                } else {
                    cout << "Student not found.\n";
                }
                break;
            }
            case 3: {  
                string mNumber;
                cout << "Enter MNumber: ";
                cin >> mNumber;
                if (studentList.IsInlist(Student("", "", mNumber, {}, 0.0))) { 
                    cout << "Student is in the list.\n";
                } else {
                    cout << "Student is not in the list.\n";
                }
                break;
            }
            case 4: { 
                studentList.PrintList(); 
                break;
            }
            case 5: { 
                if (studentList.IsEmpty()) {
                    cout << "The list is empty.\n";
                } else {
                    cout << "The list is not empty.\n";
                }
                break;
            }
            case 6: { 
                cout << "Size of the list: " << studentList.Size() << endl;
                break;
            }
            case 7: 
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
