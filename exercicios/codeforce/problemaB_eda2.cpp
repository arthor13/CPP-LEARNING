#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
const int MAX { 2010 };

vector<int> funcionarios[MAX];
int MINGROUP = 0, ATUAL = 0;


void addFunc(int& funcionario, int& supervisor)
    {
        funcionarios[supervisor].push_back(funcionario);
    }

int countGroup(int s)
    {
        if(funcionarios[s].size() == 0) return 1;
        int max = 0;
        for (auto f : funcionarios[s])
        { 
            if (max >=  1 + countGroup(f)) continue;
            else max = 1  + countGroup(f);
        }
        return max;
    }

int main() {
    int n,s;
    vector<int> p;
    
    cin >> n;
    for (int i = 1; i <= n ; i++)
        {
            cin >> s;
            if (s == -1 ) p.push_back(i);
            else addFunc(i,s);
        }
    for (auto f : p)
        {
            ATUAL = countGroup(f);
            if ( ATUAL  > MINGROUP) MINGROUP = ATUAL;
        }
        
    cout << MINGROUP << '\n';
    return 0;
}