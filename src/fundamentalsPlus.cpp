#include <iostream>
#include <vector>
#include "utilidades.h"

    int main()
{
    //NÃO PRECISA COLOCAR O TIPO, MAS É BOM 
    printMensagem<int>(1);
    printMensagem<std::string>("Hello");
    printMensagem(3.14);
    printMensagem(true);

    std::cout << soma(1.5,2,435314,13213,1321,23,0.223) << std::endl;
    std::cout << soma(std::string {"Arthur"}, std::string{"de Lima"}, std::string{"Sobreira"}) << std::endl;
}