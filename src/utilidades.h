template<typename M>
void printMensagem(M msg);

template<typename PrimeiroArgumento, typename... Outros>
PrimeiroArgumento soma (PrimeiroArgumento primeiroArgumento, Outros... outros);

template< typename... Outros>
std::string soma (std::string primeiroArgumento, Outros... outros);
