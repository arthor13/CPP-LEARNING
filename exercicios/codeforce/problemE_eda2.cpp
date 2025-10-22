#include <iostream>
#include <map>
using namespace std;

//ERRADO POR ENQUANTO

void primeiro(string& phrase, const int& indice, char& key) {
    phrase[indice] = key;
}

int segundo(const string& phrase, int& begin, int& end) {
    map<char, int> contagem;
    for (int i = --begin; i < end; i++)
        {
          if (contagem.find(phrase[i]) != contagem.end()) continue;
          contagem[phrase[i]] ++;
        }
    return contagem.size();
}



int main ()
{
    string phrase;
    int n, type, indice, valueInt;
    char value;
    cin >> phrase;
    cin >> n;

    for (n; n > 0; n--)
    {
      cin >> type;
      if (type == 1)
        {
            cin >> indice >> value;
            primeiro(phrase,--indice, value);
        }
      else if (type == 2)
      {
        cin >> indice >> valueInt;
        cout << segundo(phrase,indice, valueInt) << '\n';
      }
    }
}
