#include <iostream>
#include <vector>
using namespace std;
int cartas[51];

void adicionarCartas(const int& n, const int& carta)
{
    if ( cartas[carta] > n )
    { 
        cartas[carta] = n;

    }
}

void trocarCartas(int posicao, int& cor)
{
    for(int& posicoes : cartas)
    {
        if(posicoes < posicao) posicoes++;
        else if(posicoes == posicao) posicoes = 1;
    }
}

void imprimirCartas(int& cor)
{
    cout << cartas[cor]<< '\n';
    trocarCartas(cartas[cor], cor);
}

int main()
{
    for(int& i : cartas) i = 300000;
    int n, q, card, color;
    cin >> n >> q;
    for( int i = 1; i <= n; i++)
    {
        cin >> card;
        adicionarCartas(i, card);
    }
    for ( int i = 0; i < q; i ++)
    {
        cin >> color;
        imprimirCartas(color);
    }
}
