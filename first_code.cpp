#include <iostream>
#include <iomanip>

int main()
{
    //Comentáario em C++
   //Tipos básicos de dados em C++
    int age = 2025;
    float temperature = 25.5232323;
    double numero = 25.2525;
    char characterA = 'A';
    bool isItHot = true;
    //STRING EM C++
    std::string msg = "Hello Arthur! ";
    //Print em C++
    std::cout << msg << age << " Temperatura: " << std::setprecision(7) << temperature <<std::endl;
    /*
    Tamanhos de dados em C++ (EM BYTES):
        INT: 4
        FLOAT:4
        DOUBLE: 8
        CHAR:1
        BOOL: 1
        STRING: 32
    */
   std::cout << "Size of int: " << sizeof(int) << "bytes" << std::endl;
   std::cout << "Size of float: " << sizeof(float) << "bytes" << std::endl;
   std::cout << "Size of char: " << sizeof(char) << "bytes" << std::endl;
   std::cout << "Size of bool: " << sizeof(bool) << "bytes" << std::endl;
   std::cout << "Size of string: " << sizeof(std::string) << "bytes" << std::endl;
    
}