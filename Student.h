#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <ctime>

class Student {
public:
class Student {
    public:
        std::string name;
        int age;
        double gpa;

        // Constructor
        Student(std::string name, int age, double gpa) : name(name), age(age), gpa(gpa) {}

        // Display method
        void display() const {
            std::cout << "Name: " << name << std::endl;
            std::cout << "Age: " << age << std::endl;
            std::cout << "GPA: " << gpa << std::endl;
            std::cout << std::endl; // Empty line for better readability
        }
        
    // Public methods
    std::string GetName() const;
    std::string GetMNumber() const;
    int GetAge() const;

    // Operator overloads
    bool operator>(const Student& other) const;
    bool operator<(const Student& other) const;
    bool operator==(const Student& other) const;

    // Friend function for output
    friend std::ostream& operator<<(std::ostream& os, const Student& student); // Declaration only

private:
    std::string firstName;
    std::string lastName;
    std::string mNumber;
    std::tm birthday;
    double gpa;
};

#endif
