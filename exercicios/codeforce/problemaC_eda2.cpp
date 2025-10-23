#include <iostream>
#include <vector>
using namespace std;

vector<int> cartas[51];
vector<int> ordem;
int distintos;


void trocarCartas(const int& color)
{
    /*
    int i = cartas[color][0];
    int a = -1;
    ordem.insert(ordem.begin(), color);
    ordem.erase(cartas[color].begin()+ i);
    if (i <= 2)
    {
        for (int j = 0; j < 2; j++)
        {
            cartas[ordem[j]][0] ++;
        }
    }
    else if ( i > 2 )
    {
        for (auto& posicoes : cartas)
        {
            a++;
            for (auto& cor : posicoes)
            {
                cout << a << ' ' << cor << '\n';
            }
        }

    }*/
}

int imprimirCartas(const int& color)
{
    int a = cartas[color][0];
    trocarCartas(color);
    return a;

}


void adicionarCartas(const int& n, const int& carta)
{
    cartas[carta].push_back(n);
}



int main()
{
    int n, q, card, color;
    cin >> n >> q;
    for( int i = 1; i <= n; i++)
    {
        cin >> card;
        adicionarCartas(i, card);
        ordem.push_back(card);
    }
    for ( int i = 1; i <= q; i ++)
    {
        cin >> color;
        cout << imprimirCartas(color) << ' ';
    }
    int a = -1;
    for (auto& c : cartas)
        {
            a++;
            for (auto& q : c) cout << a << ' ' << q <<'\n' ;
        }
    cout << "Vetor ordem " << '\n';
    for (auto c : ordem) cout << c << '\n';

}