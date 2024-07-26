#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <ctime>

class Student {
private:
    std::string firstName;
    std::string lastName;
    std::string mNumber; // MNumber should store the M and the 8 digits
    double gpa;
    std::tm birthday;

public:
    // Constructor
    Student(std::string fName, std::string lName, std::string mNo, std::tm birth, double g = 0.0);

    // Methods
    std::string GetName() const;
    std::string GetMNumber() const;
    int GetAge() const;

    // Operator overloads
    bool operator>(const Student& other) const;
    bool operator<(const Student& other) const;
    bool operator==(const Student& other) const;

    // Friend function to overload << operator
    friend std::ostream& operator<<(std::ostream& os, const Student& student);
};

#endif