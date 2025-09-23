#include <iostream>
#include <random>
#include <vector>
#include <iomanip> //É PRECISO DESSA BIBLIOTECA PARA UTILIZAR A .time()

void sortVetor(int n, std::vector<int>& vetor, int& iteracoes)
    {
        if (n >= vetor.size() -1 )
        {
            return;
        }
        int i = n;
        for (int j = n  ; j < vetor.size(); j++)
            {
                iteracoes ++;
                if (vetor[j] < vetor[i])
                    {
                       i = j;
                    }
            }
        int temp = vetor[n];
        vetor[n] = vetor[i];
        vetor[i] = temp;
        sortVetor(n + 1, vetor, iteracoes);
    }



int main()
{
    std::vector<int> randomNumber;
    
    /*PARA RESOLVER A QUESTÃO DOS NUMERO PSEUDO ALEATÓRIOS,
    BASTA UTILIZAR A FUNÇÃO .srand(seed) QUE BASICAMENTE DETERMINA UM SET DE ALEATORIOS DIFERENTES
    PRA CADA SEED DIGITADA, OU SEJA OS NUMEROS ALEATORIOS DA SEED 1 E DA SEED 2 SÃO DIFERENTES
    MAS AÍ SURGE UM PROBLEMA -> FICAR DIGITANDO MANUALMENTE UMA SEED DIFERENTE NÃO DA
    PARA ISSO PODEMOS UTILIZAR A FUNÇÃO std::time(nullptr) QUE BASICAMENTE VAI RETORNAR A HORA ATUAL
    OU SEJA AS SEEDS SERÃO DIFERENTES QUASE TODA HORA, POIS A TIME RETORNA ATÉ OS SEGUNDOS
        O nullptr É BASICAMENTE UMA EXPRESSÃO QUE INDICA "ALGO QUE NÃO EXISTE"
    */

    std::srand(std::time(nullptr));

    for (int i = 0; i < 13; ++i)
        {
            //A FUNÇÃO rand() GERA NUMERO ALEATORIOS DE 0 AO MAXIMO QUE O TIPO PERMITE -> PARA LIMITAR BASTA UTILIZAR O % 
            //OS NUMEROS ALEATORIOS SERÃO SEMPRE IGUAIS, NÃO IMPORTA QUANTAS VEZES VC COMPILAR OU RODAR O PROGRAMA
            int number = std::rand() % 100; 
            randomNumber.push_back(number);
            std::cout << number << " ";
        }


    int menor = std::numeric_limits<int>::max(); // BASICAMENTE A numeric_limits<tipo_de_numero>::max() VAI RETORNAR O MAIOR INTEIRO POSSÍVEL, EXISTE A .min() TAMBÉM

    for (int num : randomNumber)
        {
            if(num  < menor)
                {
                    menor = num;
                }
        }
        
    std::cout << "O menor número é: " << menor << std::endl;
    int n = 0;
    sortVetor(0, randomNumber, n);
    for (int num : randomNumber)
        {
            std::cout << num << std::endl;
        }
}