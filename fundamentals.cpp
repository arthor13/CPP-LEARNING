//Biblioteca padrão do C++, necessário para os comandos básicos
#include <iostream>
//Biblioteca utilizada para usar o setprecision, que basicamente determina o numero de algarismos em um número flutuante
#include <iomanip>
//Biblioteca pra utilizar vectors
#include <vector>
//Biblioteca pra utilizar maps
#include <map>
// Para utilizar getline()
#include <string>
//Para limpar literalmente todo o buffer de input é preciso importar essa library
#include <limits>
/* 
    Estou usando um curso da udemy chamado *Learn C++ and make a game from scratch* e um curso do youtube -> https://www.youtube.com/watch?v=-TkoO8Z07hI 
    Quando vc ver algo entre ** nos comentários é basicamente o código que voce digitaria, tem vezes que eu utilizo elas e tem vezes que não 
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
    //Estou compilando meu código utilizando G++ no Fedora 42 -> g++ name_of_file.cpp -o directory(optional)/name_of_the_output_file
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
    

    /*
        INPUT:
            *std::cin >> variable_name*
            *std::getline(std::cin, variable_name) -> para pegar uma string em C++, se não utilizar ela a sua string vai ser cortado no primeiro espaço que voce der

            INTERESSANTE ->
                ASSIM COMO VÁRIAS SITUAÇÕES EM C++ QUE NORMALMENTE ACUSARIAM ERRO EM OUTRA LINGUAGEM, PORÉM AQUI NÃO ACUSA É A QUESTÃO DO INPUT DE DADO ERRADO
                    O QUE EU QUERO DIZER É:
                        VAMOS SUPOR QUE VOCÊ INSIRA UM CARACTER "T" QUALQUER EM UMA VARIÁVEL QUE É DO TIPO INTEIRO,
                        AO INVÉS DO PROGRAMA DAR UM ERRO, O C++ IRÁ ADICIONAR POR DEFAULT O VALOR 0 À SUA VARIÁVEL INTEIRA
                        E O SEU CARACTER "T" QUE VOCE ADICIONOU IRÁ PARA O BUFFER DE INPUT, O QUE VAI FODER TODOS OS SEUS PRÓXIMOS INPUTS
                        VOCÊ PODE UTILIZAR ENTÃO UM std:cin.clear(); QUE IRÁ LIMPAR O BUFFER DE INPUT 
                        OU SEJA, VOCÊ VAI CONSEGUIR FAZER OUTRAS INPUTS DEPOIS DO INPUT ERRADO, 
                        PORÉM AQUELE VALOR ERRADO QUE VOCÊ ADICIONOU AINDA VAI ESTAR NO BUFFER E SERÁ ASSOCIADO AO PRÓXIMO INPUT QUE VOCÊ FIZER. 
                        OU SEJA, A FUNCÃO cin.clear() É COMO SE ESTIVESSE EMPURRANDO AQUILO QUE ESTÁ NO BUFFER DE INPUT PARA 
                        A PRÓXIMA VARIÁVEL QUE VC PUDESSE RECEBER 
                            EX: 
                              std::cin >> numeroInteiro;
                              std::cin.clear()
                              std::cin >> variavelString;

                            CASO O USUÁRIO INSIRA A LETRA "t" NO numeroInteiro, VOCÊ NÃO IRÁ CONSEGUIR INSERIR NADA NA variavelString 
                            E O VALOR DE "t" SERÁ AUTOMATICAMENTE ASSOCIADO À variavelString, PORÉM OS PRÓXIMOS INPUTS SERIAM NORMAIS
                                        -------------------------------------------------------------------------------
                            CASO VOCÊ NEM UTILIZASSE O std::cin.clear() VOCÊ NÃO CONSEGUIRIA INSERIR NADA NO variavelString E ELA AINDA IA FICAR COM VALOR NULO
                            E O "t" AINDA IA ESTAR NO BUFFER, FERRANDO COM TODOS SEUS INPUTS SEGUINTES

                        PARA RESOLVER TODOS ESSAS SITUAÇÕES PODE SE UTILIZAR O std::cin.clear() SEGUIDO DO std::cin.ignore(numero_de_inputs_a_ser_ignorados_no_buffer, '\n');
                        O ignore() BASICAMENTE VAI IGNORAR TODAS OS PRÓXIMO N INPUTS QUE VOCÊ DEFINIU NO PRIMEIRO PARAMETRO
                        E VAI PARAR DE IGNORAR DEPOIS DE UMA QUEBRA DE LINHA, QUE ADICIONAMOS NO SEGUNDO PARAMETRO.
                        É IMPORTANTE ADICIONAR A QUEBRA DE LINHAS, POIS CASO NÃO ADICIONEMOS TODOS OS PRÓXIMOS N INPUTS SERÃO IGNORADOS MESMO QUE O INPUT ERRADO
                        DO USUÁRIO JA TENHA SIDO DESCARTADO. 
                        DICA: É BOM COLOCAR UM NÚMERO BEM ALTO NO PRIMEIRO PARAMETRO, POIS NUNCA SE SABE QUAIS ATROCIDADES O USUÁRIO COLOCOU NO INPUT. 
                              OU SEJA, SE VOCÊ COLOCAR 5 NO PRIMEIRO PARAMETRO E O USUÁRIO DIGITOU 7 CARACTERES, VÃO FICAR 2 CARACTERES INDESEJADOS NO BUFFER
                                EXISTE UMA FUNÇÃO UTILIZANDO A BIBLIOTECA <limits> QUE É std::numeric_limits<std::streamsize>::max() 
                                E SE VOCÊ COLOCAR ELA NO PRIMEIRO PARAMETRO DA cin.ignore() TODO O BUFFER SERÁ IGNORADO, INDEPENDENTE DO TAMANHO DO INPUT DO USUÁRIO
                                !!!! LEMBRE SEMPRE DE COLOCAR O '\n' NO SEGUNDO PARAMETRO (QUE É O DE PARADA), PORQUE SE NÃO VOCÊ PODE IGNORA OS PRÓXIMOS INPUTS DO PROGRAMA 
    */
    
   /*
        Array em C++

        Para pegar o tamanho de uma array basta utilizar o sizeof da array e dividir o sizeof pelo tipo de dado dela
            sizeof(name_of_array)/sizeof(data_type_of_the_array)
        Arrays não mudam de tamanho

   */
   std::string lista[] = {"Lista", "em", "C++"};
    std::cout << lista[0] << std::endl;
    lista[0] = "Teste";


    /*
        Vector em C++
                FUN FACT -> VECTOR EM C++ FOI CRIAdO PRIMEIRO DO QUE A ARRAY

            Para buscar o primeiro valor de um vector basta utilizar -> 
                vector.name_front() 
            Para buscar o último valor de um vector basta utilizar -> vector_name.back()
            Para buscar o tamanho de um vector basta utilizar -> 
                vector_name.size()
            O verdadeiro valor de um vector sobre uma array é a habilidade de diminuir e aumentar o tamanho do vector, o que não é possivel na array.
            Para aumentar (tipo append em pytohn):
                vector_name.push_back(dado_a_ser_adicionado)
            Para inserir:
                vector_name.insert(vector_name[local_a_ser_inserido], valor_a_ser_inserido)
                    Pode-se utilizar, para inserir no ínicio, a função *vector_name.begin()* ao invés de *vector_name[local_a_ser_inserido]* -> válido *.begin()+1*
                    Existe também a *.end()* que retorna o depois do último
                        DE ACORDO COM MEU ENTEDIMENTO ESSAS FUNÇÕES RETORNAM O PONTEIRO DAS POSIÇÕES, DIFERENTE DO *FRONT()* E *BACK()* QUE RETORNAM O VALOR ARMAZENADO NAQUELA POSIÇÃO
            Para remover:
                vector_name.erase(vector_name[posição])

            EXISTEM DIVERSAS OUTRAS FUNÇÕES ASSOCIADAS AO VECTOR. PARA MAIS INFORMAÇÕES -> https://cplusplus.com/reference/vector/vector/
    */
    std::vector<int> vetor_int;


    /*
        MAP EM C++ -> Bem semelhante aos dictionaires em Python
            O primeiro paramêtro ao criar um map é a key(identificador) e a segunda é o valor 
                *std::map<std::string, int> name_of_the map { {"Nome_da_key", valor_da_key}, {"Nome_da_key", valor_da_key} }* 
            Para acessar o valor de um map basta utilizar a key
                *std::cout << idsFunc["Arthur"] << std::endl;* -> Irá me retornar o valor 123 contido no meu map
            Para alterar o valor de um map basta
                *map_name[key_do_valor_que_quero_trocar] = valor_a_ser_adicionado;*
            Para inserir basta utilizar
                *map_name.insert( {"Key", valor} );*
            Para apagar um campo
                *map_name.erase("Key");*
                IMPORTANTE!!!!!!!!!!!!
                    APÓS APAGAR COM O ERASE, SE VC TENTAR ACESSAR O MAP ATRAVÉS DA KEY JÁ APAGADA O PROGRAMA IRÁ CRIAR UMA NOVA KEY NO MAP COM O VALOR 0
                        EX(LEVE EM CONTRA QUE O VALOR QUE IREI IMPRIMIR AQUI TENHA SIDO APAGADO ANTERIORMENTE COM ERASE): 
                            std::cout << meuMapa["João"] << std::endl;
                                Irá imprimir 0, pois o programa buscou a key "João" no meuMapa 
                                e quando ele não achou ele basicmanete fez internamente um meuMapa.insert( {"João, 0"} )
            Para pegar o tamanho de um map
                *map_name.size()*
            Para apagar tudo
                *map_name.clear()*
            Para buscar se existe um valor dentro do map
                *map_name.find("Key")* 
                    Irá retornar o ponteiro do local do map onde o valor está CASO EXISTA
                    Ou seja, voce pode compara a função find com a função end, que irá dar um valor falso caso exista e verdadeiro caso não
                        *map_name.find("Key") == map_name.end()* -> 1 caso exista e 0 caso não

            OBVIAMENTE EXISTEM OUTRAS FUNÇÕES    
    */
    std::map<std::string, int> idsFunc { {"Arthur", 123}, {"João", 345} };
    idsFunc["Arthur"] = 678;


    /*
        Operadores Aritméticos em C++ (NÃO VOU EXPLICAR MUITO ESSA SEÇÃO PQ É UMA COISA BEM BÁSICA E PADRONIZADA EM TODAS AS LINGUAGENS "-")
            + - / * %    
                +
                    ADIÇÃO
                -
                    SUBTRAÇÃO
                /
                    DIVISÃO
                *
                    MULTIPLICAÇÃO
                %
                    MÓDULO
                        SÓ FUNCIONA COM INT
                    
                É POSSÍVEL UTILIZAR *OPERADOR*= (Algumas linguagens não suportam, eu acho) -> a += b;
                É POSSIVEL TAMBÉM -> a++ || ++a ; SIMILARMENTE À C (nem toda linguagem suporta) 

        Operadores Lógicos em C++
            ==
                IGUAL
            !=
                DIFERENTE
            >
                MAIOR
            <
                MENOR
            >=
                MAIOR OU IGUAL
            <=
                MENOR OU IGUAL
            &&
                E
            ||
                OU 
            
            OBS: Lembrando que esses operadores podem ser utilizados em uma variável também -> *bool variavel = a == b;*
    */

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
            Implicito
                *int x = 3.14*
            Explicito
                *double = (int) 3.14*    
    */



    }