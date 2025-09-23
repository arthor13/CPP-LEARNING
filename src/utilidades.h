#include <iostream>

template<typename M>
void printMensagem(M msg);

template<typename T>
T soma(T t);

template<typename PrimeiroArgumento, typename... Outros>
PrimeiroArgumento soma (PrimeiroArgumento primeiroArgumento, Outros... outros);

std::string soma(std::string t);
template< typename... Outros>
std::string soma (std::string primeiroArgumento, Outros... outros);
