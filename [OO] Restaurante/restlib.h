#ifndef RESTAURANTE
#define RESTAURANTE

#include <string>
#include <vector>


class Pedido
{
    private:
        int numero;
        std::string descricao;
        float preco;
        int quantComprada;


    public:
        /******** CONSTRUTORES ********/
        Pedido();
        Pedido(int, std::string, float, int);


        /******** MÉTODOS ********/
        int getNumero();
        std::string getDescricao();
        float getPreco();
        int getQuantComprada();


        void setNumero(int);
        void setDescricao(std::string);
        void setPreco(float);
        void setQuantComprada(int);


        void aumentaQuantComprada(int);
        float getTotal();
};


class MesaDeRestaurante
{
    private:
        std::vector<Pedido> pedido;


    public:
        /******** MÉTODOS ********/
        void adicionarPedido(Pedido);
        void zeraPedidos();
        float calculaTotal();
        void exibeConta();
};


class Restaurante
{
    private:
        MesaDeRestaurante *mesa;
        int quantMesas;


    public:
        /******** CONSTRUTORES ********/
        Restaurante();
        Restaurante(int);


        /******** MÉTODOS ********/
        MesaDeRestaurante getMesa(int);
        int getQuantMesas();


        void adicionarPedido(Pedido, int);
        float calculaTotalRestaurante();
        void NovoArray(int);


        void limparArray();
};



#endif