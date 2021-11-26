#include <sstream>
#include "Estatisticas.h"


/*************************** template <class Type> class Estatisticas ***************************/

template <class Type>
int Estatisticas<Type>::indexOfMaior(std::vector<Type> vec){
    int maior = (vec.size() == 0 ? -1 : 0);

    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i].getTotal() > vec[maior].getTotal()){
            maior = i;
        }
    }

    return maior;
}

template <class Type>
int Estatisticas<Type>::indexOfMenor(std::vector<Type> vec){
    int menor = (vec.size() == 0 ? -1 : 0);

    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i].getTotal() < vec[menor].getTotal()){
            menor = i;
        }
    }

    return menor;
}

template <class Type>
float Estatisticas<Type>::media(std::vector<Type> vec){
    float media = 0;

    for (int i = 0; i < vec.size(); i++)
    {
        media += vec[i].getTotal();
    }
    if (vec.size() != 0) media /= vec.size();

    return media;
}

//////////////////////////////////////////////////////////////////////


/*************************** class Pedido ***************************/

/******** CONSTRUTORES / DESTRUTOR ********/
Pedido::Pedido(){
    valorUnitario = 0;
    quantidade = 0;
}

Pedido::Pedido(float valor, int quant){
    valorUnitario = valor;
    quantidade = quant;
}

Pedido::~Pedido() { }

/******** MÉTODOS ********/
float Pedido::getTotal(){
    return valorUnitario * quantidade;
}

std::string Pedido::toString(){
    std::stringstream sout;

    sout << "R$ " << valorUnitario << ", quant: " << quantidade
            << ", total: R$ " << getTotal();

    return sout.str();
}

//////////////////////////////////////////////////////////////////////


/*************************** class Livro ***************************/

/******** CONSTRUTORES / DESTRUTOR ********/
Livro::Livro(){
    titulo = "";
    totalPaginas = 0;
}

Livro::Livro(std::string titulo, int paginas){
    this->titulo = titulo;
    this->totalPaginas = paginas;
}

Livro::~Livro() { }

/******** MÉTODOS ********/
int Livro::getTotal(){
    return totalPaginas;
}

std::string Livro::toString(){
    std::stringstream sout;

    sout << titulo << ", páginas: " << totalPaginas;

    return sout.str();
}