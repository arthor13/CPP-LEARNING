#include <iostream>
#include <memory>

    //SMARTPOINTERS, UTILIZE A LIBRARY <memory> PARA ACESSA AS FUNCIONALIDADES


int main()
{
    //O INTERESSANTE DOS SMARTPRTS É QUE VOCE NÃO PRECISA FAZER APAGAR O ESPACO DA MEMORIA MANUALMENTE
    //OS SMART PTRS APAGAM O ESPACO DA HEAP AUTOMATICAMENTE AO ACABAR O ESCOPO EM QUE AQUELE PONTEIRO PERTENCEEEEE
    //UNIQUE PTR
    //O USO É BEM PARECEIDO AO PONTEIRO NORMAL/PADRAO 
    std::unique_ptr<int> intPonteiroUnico = std::make_unique<int>(5);
    //É POSSIVEL MOVER OS PONTEIRO UNICO, TRANFERINDO O PONTEIRO INTERNAMENTE ENTRE AS DUAS VARIAVEIS E O PONTEIROR ANTERIOR VIRA nullptr
    std::unique_ptr<int> intPonteiroMovidoUnico = std::move(intPonteiroUnico);
    //BASICAMENTE ESTAMOS FAZENDO UM PONTEIRO PARA UM ENDERECO DA HEAP COM VALOR 5 E ARMAZENANDO NUM PONTEIRO UNICO
    //O INTERESSANTE DO UNIQUE PTR ESTÁ EXPLICADO NO NOME, ELE SEMPRE IRÁ APONTAR PARA UM ESPACO UNICO
    int* ponteiroX = new int {5};
    int* outroPonteiroX = ponteiroX;

    delete ponteiroX;
    ponteiroX = nullptr;
    std::cout << outroPonteiroX;//VALOR ERRADO/GARBAGE 
    //COM PONTEIROS NATIVOS VOCE VAI TER ERROS COMO ESSE DEMONSTRADO ACIMA


    //SHARED POINTER, NORMALMENTE SE COMPORTA COMO QUALQUER SMART POINTER, POREM TEM SUAS PECULIARIDADES
    std::shared_ptr<int> ponteiroCompartilhado = std::make_shared<int>(5);
    //O PONTEIRO CRU SÓ SERA DELETADO DA MEMORIA QUANDO O ULTIMO PONTEIRO COMPARTILHADO SEJA DELETADO -- POR ESCOPO OU RUNTIME
    std::shared_ptr<int> ponteiroCompartilhado2 = ponteiroCompartilhado2;
    
    
    intPonteiroMovidoUnico.reset();//LIMPANDO MANUALMENTE SMART POINTERS
    ponteiroCompartilhado.reset();//A MEMORIA NA HEAP QUE ELES REFERENCIAM CONTINUA VIVA, POIS EU TENHO OUTRO SHARED POINTER LA

    //WEAK PTR, NAO FAZ DELECAO FREEIND DA MEMORIA AUTOMATICAMENTE, É UTILIZADO EM CONJECTURA COM O SHARED PTR
    std::weak_ptr<int> ponteiroFaco;//PONTEIRO FRACO VAZIO
    std::weak_ptr<int> ponteiroFraco2 = ponteiroCompartilhado2;//PONTEIRO FRACO REFERENCIANDO PONTEIRO COMPARTILHADO

    //ponteirofraco.lock() GERA AUTOMATICAMENTE UM PONTEIRO COMPARTILAHDO
    std::shared_ptr<int> outroPonteiroCOmpartilhadoo = ponteiroFraco2.lock();

    ponteiroCompartilhado2.reset();
    if (ponteiroFraco2.expired())
    {
        std::cout  << "Ponteiro Fraco expirado, pois todos os shared foram resetados. REF COUNT = 0";
    }    
}
