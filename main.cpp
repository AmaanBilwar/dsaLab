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

void PrintMenu() {
    std::cout << "Linked List Test Program" << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << "1. Add Item" << std::endl;
    std::cout << "2. Get Item" << std::endl;
    std::cout << "3. Is In List" << std::endl;
    std::cout << "4. Is Empty" << std::endl;
    std::cout << "5. Size" << std::endl;
    std::cout << "6. See Next" << std::endl;
    std::cout << "7. See At" << std::endl;
    std::cout << "8. Reset" << std::endl;
    std::cout << "9. Print List" << std::endl;
    std::cout << "10. Exit" << std::endl;
}

int main() {
    LinkedList<Student> studentList;

    while (true) {
        PrintMenu();
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string firstName, lastName, mNumber;
                int year, month, day;
                double gpa;

                std::cout << "Enter first name: ";
                std::cin >> firstName;
                std::cout << "Enter last name: ";
                std::cin >> lastName;
                std::cout << "Enter MNumber: ";
                std::cin >> mNumber;
                std::cout << "Enter birthday (year month day): ";
                std::cin >> year >> month >> day;
                std::cout << "Enter GPA (optional): ";
                std::cin >> gpa;

                std::tm birthday = CreateBirthday(year, month, day);
                Student student(firstName, lastName, mNumber, birthday, gpa);
                studentList.AddItem(student);
                break;
            }
            case 2: {
                std::string mNumber;
                std::cout << "Enter MNumber to get: ";
                std::cin >> mNumber;

                Student* student = studentList.GetItem(Student("", "", mNumber, CreateBirthday(0, 0, 0)));
                if (student != nullptr) {
                    std::cout << "Got student: " << *student << std::endl;
                    delete student;
                } else {
                    std::cout << "Student not found" << std::endl;
                }
                break;
            }
            case 3: {
                std::string mNumber;
                std::cout << "Enter MNumber to check: ";
                std::cin >> mNumber;

                if (studentList.IsInlist(Student("", "", mNumber, CreateBirthday(0, 0, 0)))) {
                    std::cout << "Student is in the list" << std::endl;
                } else {
                    std::cout << "Student is not in the list" << std::endl;
                }
                break;
            }
            case 4: {
                if (studentList.IsEmpty()) {
                    std::cout << "List is empty" << std::endl;
                } else {
                    std::cout << "List is not empty" << std::endl;
                }
                break;
            }
            case 5: {
                std::cout << "Size of list: " << studentList.Size() << std::endl;
                break;
            }
            case 6: {
                Student* student = studentList.SeeNext();
                if (student != nullptr) {
                    std::cout << "Next student: " << *student << std::endl;
                } else {
                    std::cout << "No more students" << std::endl;
                }
                break;
            }
            case 7: {
                int location;
                std::cout << "Enter location to see: ";
                std::cin >> location;

                try {
                    Student* student = studentList.SeeAt(location);
                    std::cout << "Student at location " << location << ": " << *student << std::endl;
                } catch (const std::out_of_range& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            case 8: {
                studentList.Reset();
                std::cout << "List reset" << std::endl;
                break;
            }
            case 9: {
                studentList.PrintList();
                break;
            }
            case 10: {
                return 0;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
                break;
            }
        }
    }

    return 0;
}
