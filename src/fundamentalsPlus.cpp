#include <iostream>
#include <vector>
//COMO O ARQUIVO .h ESTÁ NO MESMO DIRETORIO QUE MEU ARQUIVO EM QUE VOU IMPORTÁ-LO UTILIZAMOS "", SE FOSSE EM OUTRO DIRETÓRIO USARIAMOS O <>
//BASICAMENTE ESTAMOS MANTENDO O "GROSSO" DO CODIGO E FUNÇÕES NUM ARQUIVO .h E IMPORTAMOS ELE PRO CODIGO PRINCIPAL ONDE USAREMOS AS FUNCOES E DEFINICOES IMPLEMENTADAS NELE
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