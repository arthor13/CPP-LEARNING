#include <iostream>
#include <string>
#include <sstream>
#include <map>
int main()
{
    std::string teste = R"""(Lorem ipsum dolor sit amet,consectetur adipiscing elit.Aenean semper leo vel augue fermentum, in blandit sapien mollis. Fusce sed tortor nec magna ullamcorper dapibus. Aliquam quis libero aliquet arcu luctus sagittis in vitae risus. Aliquam in nibh vehicula, vehicula est eget, sollicitudin tellus. Cras aliquet id elit id pharetra. Curabitur vel tortor nulla. Nunc sit amet sem arcu.

Duis sollicitudin aliquam mi nec mattis. Nullam at fermentum magna. Etiam in facilisis massa. Sed semper nec tellus ut iaculis. Curabitur finibus velit ut quam gravida, ut vulputate libero ullamcorper. Proin vitae lacus lobortis, pellentesque erat vitae, tincidunt metus. Sed eget vestibulum ipsum. Suspendisse sagittis non mauris quis pretium. Fusce in laoreet nulla, at aliquet est.

Curabitur sit amet egestas dolor. Nulla scelerisque luctus tellus mattis efficitur. Morbi ac enim quis purus consectetur ullamcorper. Etiam vestibulum lorem et eros sagittis, vitae pellentesque est ullamcorper. Cras vehicula enim in iaculis auctor. Quisque lobortis ipsum non gravida ultrices. Curabitur ultricies faucibus hendrerit. Donec sagittis mattis neque. Duis fermentum dapibus est, sit amet ultricies nibh rutrum luctus. Integer ullamcorper quam nec eros aliquet, eu viverra ex faucibus. Nunc tincidunt tortor in quam pretium, at tempus ex feugiat. Donec suscipit lectus congue dui varius, a vulputate mi facilisis. Praesent dictum velit a tellus malesuada, eu tincidunt nisi convallis.

Nullam auctor ante a pellentesque viverra. Aliquam a tempor lectus, ac laoreet erat. Phasellus condimentum magna ac enim dignissim, non fringilla erat viverra. Pellentesque porta lectus vel feugiat semper. Aenean malesuada ipsum odio, et ornare quam suscipit id. Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec condimentum nulla nec libero posuere ultricies. Proin id efficitur sem, sit amet luctus urna.

Duis vestibulum turpis sed magna ultricies interdum.Ut consequat elit ut fringilla bibendum.Cras a metus non ligula convallis luctus sit amet tincidunt lectus.Maecenas auctor augue sed leo tincidunt, a commodo dui mollis. Proin ac dui suscipit, dapibus dui quis, aliquam massa. Morbi mollis iaculis diam, id molestie tellus suscipit at. Vivamus non lorem imperdiet, pharetra augue eget, dignissim leo. Nullam ipsum justo, suscipit id erat vel, consectetur placerat ex.Nam sed urna eu turpis rhoncus dictum in tincidunt leo.Sed in interdum ligula,sed lacinia elit.Fusce tristique neque ut nibh placerat varius. )""";

    std::stringstream ss;
    ss << teste;
    
    std::string proxStr = "";

    ss >> proxStr;
    ss >> proxStr;
    
    /*BASICAMENTE O QUE ESSE CÓDIGO ESTÁ FAZENDO É ATRIBUINDO O INPUT DE MULTIPLAS LINHAS PARA A VARIAVEL ss DO TIPO SS(STRING STREAM) NA LINHA 18,
    APÓS ISSO EU CRIO UMA STRING VAZIA E COMEÇO A ATRIBUIR A SS PARA A NOVA STRING VAZIA, O QUE ISSO IRÁ FAZER, EM CADA ITERAÇÃO, É ATRIBUIR UMA PALAVRA POR VEZ PARA MINHA STRING proxStr
    A CADA ITERAÇÃO SERÁ ATRIBUIDO A Nésima PALAVRA DA STRING
    NO CASO DO LOREM IPSUM
        NA PRIMEIRA ss >> proxStr A VARIAVEL VAI RECEBER "Lorem"
        NA SEGUNDA ss >> proxStr A VARIAVEL VAI RECEBER "ipsum"

    O COMPORTAMENTO É BASICAMENTE O MESMO DE UM cout << E DE UM cin >>
        */

    //BASICAMENTE ENQUANTO TIVER PALAVRAS PRA PASSA O LOOP SERÁ FEITO, QUANDO NÃO TIVER IRÁ RETORNAR EOF QUE DARÁ FALSO E O LOOP VAI PARAR
    //ELE CONTABILIZA WHITESPACES, OU SEJA PONTUAÇÃO COLADA NAS PALAVRAS SERÁ CONTABILIZADO COMO UMA PALAVRA
    //MAPA PARA A CONTAGEM DE PALAVRAS
    std::map<std::string, int> contagemPalavras;

    while(ss >> proxStr)
        {
            //TRANSFORMAR EM LOWER CASE
            std::string formatada = "";
            int id = 0;
            //PARA TODO CARACTER NA STRING 
            for (char c : proxStr)
            {
                ++id;
                //std::isaplha() VERIFICA SE FAZ PARTE DO ALFABETO, SE SIM COLOCAMOS O CARACTER NO FINAL DA MINHA STRING formatada
                if (std::isalpha(c))
                {
                    //std::tolower() POE EM LETRA MINUSCULA
                    formatada.push_back(std::tolower(c));
                }//CASO NÃO SEJA ALFABETICA DA BREAK, ISSO É IMPORTANTE POIS, COMO PODEMOS OBSERVAR NO TEXTO INPUTADO HÁ CASOS EM QUE EXISTE PONTUAÇÃO SEPARANDO DUAS PALAVRAS
                //SEM WHITESPACE O QUE IŔA FAZER COM QUE A PALAVRA FICA CONJUNTA TIPO Lorem,Ipsum
                else break;
            }
            //PARA RESOLVER A SITUAÇÃO ACIMA VERIFICAMOS SE O ID, QUE É ADICIONADO PREVIAMENTE EM TODA ITERAÇÃO DO CARACTER DA NOSSA STRING, É DIFERENTE DO ÚLTIMO ID DA NOSSA STRING
            //SE FOR DIFERENTE QUER DIZER QUE HOUVE O BREAK DO ELSE ANTERIOR, OU SEJA, HÁ UMA STRING DO TIPO Lorem.Ipsum 
            //ENTÃO CRIAMOS UMA NOVA STRING E ATRIBUIMOS A ELA O RESTO DA STRING À PARTIR DO ID ATRAVÉS DA FUNÇÃO .substr()
            //COM ISSO ADICIONAMOS AO FINAL DA NOSSA SS A PALAVR SEPARADA COM WS PRA NAO DAR ERRO NOVAMENTE
            if (id != proxStr.size() - 1)
            {
                std::string sobra = proxStr.substr(id);
                ss << ' ' << sobra;
            }
            //ELE VAI BUSCAR O INDEX DO MAPA ONDE EXISTE A PALAVRA,
            //SE NÃO EXISTE AUTOMATICAMENTE É CRIADO E ATRIBUIDO + 1 PRA ELE
            contagemPalavras[formatada] += 1;

            std::cout << formatada << std::endl;
            std::cout << "Aparições até agora " << contagemPalavras[formatada] << std::endl;
        }

}