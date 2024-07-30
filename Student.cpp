#include "Student.h"
#include <ctime>

// Constructor implementation
Student::Student(std::string fName, std::string lName, std::string mNo, std::tm birth, double g)
    : firstName(fName), lastName(lName), mNumber(mNo), birthday(birth), gpa(g) {}

// GetName method implementation
std::string Student::GetName() const {
    return firstName + " " + lastName;
}

// GetMNumber method implementation
std::string Student::GetMNumber() const {
    return mNumber;
}

// GetAge method implementation
int Student::GetAge() const {
    std::time_t t = std::time(0); // Get current time
    std::tm* now = std::localtime(&t);

    int currentYear = now->tm_year + 1900;
    int currentMonth = now->tm_mon + 1;
    int currentDay = now->tm_mday;

    int age = currentYear - (birthday.tm_year + 1900);

    // Adjust age if the birthday has not occurred yet for the current year 
    if (currentMonth < (birthday.tm_mon + 1) ||
        (currentMonth == (birthday.tm_mon + 1) && currentDay < birthday.tm_mday)) {
        age--;
    }

    return age;
}

// Operator > overload
bool Student::operator>(const Student& other) const {
    return mNumber > other.mNumber;
}

// Operator < overload
bool Student::operator<(const Student& other) const {
    return mNumber < other.mNumber;
}

// Operator == overload
bool Student::operator==(const Student& other) const {
    return mNumber == other.mNumber;
}

// Implementation of Display method (Task 4)
void Student::Display() const { // Task 4
    std::cout << "Name: " << GetName() << ", MNumber: " << mNumber << ", GPA: " << gpa << ", Age: " << GetAge() << std::endl;
}

// Implementation of << operator overload
std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "Name: " << student.GetName() << ", MNumber: " << student.GetMNumber()
       << ", GPA: " << student.gpa << ", Age: " << student.GetAge();
    return os;
}
