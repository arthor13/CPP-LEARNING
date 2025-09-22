#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    auto stopCondition = false;
    
    while(!stopCondition){
        int condicao;
        int numero;
        cout << "Deseja continuar realizando operações ? (DIGITE 1 PRA SIM E 0 PRA NÃO)\n";
        cin >> condicao;

        switch (condicao){
            case 1:
                cout << "Digite o número que deseja verificar" <<  endl;
                cin >> numero;
                if (numero % 2 == 0) cout << "Par\n";
                else cout << "Ímpar\n";
                break;
            case 0:
                stopCondition = true;
                break;            
        }


        
    }
    
}
