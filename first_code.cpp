//Biblioteca padrão do C++, necessário para os comandos básicos
#include <iostream>
//Biblioteca utilizada para usar o setprecision, que basicamente determina o numero de algarismos em um número flutuante
#include <iomanip>
/* 
    Estou usando um curso da udemy e um curso do youtube ->https://www.youtube.com/watch?v=-TkoO8Z07hI 
*/

namespace first
{
    int x = 1;
}
namespace second
{
    int x = 2;
}


int main()
{
    //Estou compilando meu código utilizando G++ -> gpp(alias) name_of_file.cpp -o directory(optional)/name_of_the_output_file
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
    
   //Array em C++
   std::string lista[] = {"Lista", "em", "C++"};
    std::cout << lista[0] << std::endl;
    lista[0] = "Teste";

    //Constante em C++ (Standard da indústria é utilizar UPPERCASE para variáveis constantes)
    const double PI = 3.14159;
    double radius = 10;
    double circumferaence = 2 * PI * radius;


    /*
    
            Namespace -> Declarar fora da MAIN. É possivel ter variáveis de mesmo nome com diferentes valores.
            Caso eu tenho um namespace e uma variável local com o mesmo nome e printar, caso eu não especifique que estou referenciado a do namespace ele irá pegar a  variável local.
            É possível digitar *using namespace namespace_name* no ínicio da MAIN, dessa forma dentro daquele escopo eu não precisaria referenciar o nome daquele namespace toda vez que fosse digitar a variável. EX.: *first::x* -> *x*
            INTERESSANTE!!!
                É possível utilizar *using namespace std* retirando a necessidade de utilizar *std::* antes de funções como *cout* ou variáveis como *string*
                O problema é que *std* possui diversos nomes, e isso provavelmente geraria um possível conflito nas variáveis.
                    Solução -> *using std::cout* *using std::string*
                        Eu creio que seja melhor utilizar *std::* normalmente do que ficar utilizando esse namespace que pode gerar altas dores de cabeça.
     */
    int x = 5;
    std::cout << x << std::endl;
    std::cout << first::x << std::endl;

    /*
        TYPEDEf -> parece ser semelhante a C.
        Parece que é senso comum terminar o data type do typedef com _t. Ex: *typedef int inteiro_t* 
        Outra forma mais popular de utilizar typedef:
            *using inteiro_t = int;*
    
    */

    /*
        Conversão de tipos:
            Implicit0
                *int x = 3.14*
            Explicito
                *double = (int) 3.14*    
    */


    /*
        INPUT:
            *std::cin >> variable_name*
            *std::getline(std::cin >> std::ws, variable_name)* <- Para strings com possíveis whitespaces.
    */
    

    }