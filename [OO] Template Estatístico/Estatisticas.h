#ifndef ESTATISTICAS_H
#define ESTATISTICAS_H

#include <string>
#include <vector>

template <class Type>
class Estatisticas {
    public:
        static int indexOfMaior(std::vector<Type> vec);
        static int indexOfMenor(std::vector<Type> vec);
        static float media(std::vector<Type> vec);
};


class Pedido {
    private:
        float valorUnitario;
        int quantidade;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        Pedido();
        Pedido(float valor, int quant);
        virtual ~Pedido();

        /******** MÉTODOS ********/
        float getTotal();
        std::string toString();
};


class Livro {
    private:
        std::string titulo;
        int totalPaginas;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        Livro();
        Livro(std::string titulo, int paginas);
        virtual ~Livro();

        /******** MÉTODOS ********/
        int getTotal();
        std::string toString();
};


#endif