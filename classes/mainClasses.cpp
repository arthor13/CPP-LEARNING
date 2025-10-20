#include <iostream>
#include <vector>

class Student
{
public:
    std::string name;
    int id;
    int year;
};

int main()
    {
    Student studentOne, studentTwo;
    studentOne.name = "Sam";
    studentOne.id = 0001;
    studentOne.year = 1;

    studentTwo.name = "Jão";
    studentTwo.id = 0002;
    studentTwo.year = 2;

    std::vector<Student> students = {studentOne, studentTwo};

    for (Student& student : students) {
        std::cout << student.name << std::endl;
        std::cout << student.id << std::endl;
        std::cout << student.year << std::endl;
    }
    }