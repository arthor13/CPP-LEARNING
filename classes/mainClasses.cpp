#include <iostream>
#include <vector>

class Student
{
public:
    Student(const std::string& studentName, int studentID, int  sudentYear)
        //AQUI INICIALIZA DA FORMA PADRÃO NO C++
        : name{studentName}, id{studentID}, year{sudentYear}
    {
       ///Forma arcaica de se fazer ->
       ///name = studentName; ... e por ai vai
    }
    /// É possivel criar mais de um constructor desde que a assinatura/parametro seja diferente das outras
    ///É POSSIVEL CHAMAR UM CONSTRUTOR DENTRO DE OUTRO CONSTRUTOR
    Student (const char* nameArray, int StudentID, int studentYear)
        :Student{std::string{nameArray}, StudentID, studentYear}
        {

        }


    std::string name;
    int id;
    int year;
};

int main()
    {
    Student studentOne{"Jão", 1234, 1};
    Student studentTwo{"John", 1235, 1};

    std::vector<Student> students = {studentOne, studentTwo};

    for (Student& student : students) {
        std::cout << student.name << std::endl;
        std::cout << student.id << std::endl;
        std::cout << student.year << std::endl;
    }
    }