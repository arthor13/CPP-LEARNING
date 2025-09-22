#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    auto stopCondition = false;
    
    while(!stopCondition){
        int operacao;
        float numero;
        cout << "Olá para converter de\n" << "milhas para KM digite 1\n" << "km para milhas digite 2\n" << "para parar o programa digite 3\n" << endl;
        cin >> operacao;

        switch (operacao){   
        case 1:
            cout << "Digite o numero que deseja converter:" << endl;
            cin >> numero;
            cout << numero << " convertido para km é igual à: " << std::setprecision(4) << (numero * 1.60934 ) << endl;
            break;
        case 2:
            cout << "Digite o numero que deseja converter:" << endl;
            cin >> numero;
            cout << numero << " convertido para milha é igual à: " <<  std::setprecision(4) << (numero * 0.621371  ) << endl;
            break;
        default:
            stopCondition = true;
            break;

        }
    }
    
}
