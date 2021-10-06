#ifndef IMOVEIS
#define IMOVEIS

#include <string>

class Imovel
{
    protected:
        std::string tipo; //Terreno, Casa ou Apartamento
        float valor;
        bool vender;
        bool alugar;

    public:
        /******** CONSTRUTORES ********/
        Imovel();
        Imovel(int, float, std::string); //int para tipo, string para venda ou aluguel

        /******** MÉTODOS ********/
        std::string getTipo() const { return tipo; }
        float getValor() const { return valor; }


        bool paraVender() const { return vender; }
        bool paraAlugar() const { return alugar; }


        void lerAtributos();
        void exibeAtributos() const;
};

class Casa : public Imovel
{
    private:
        int num_pavimentos;
        int num_quartos;
        float areaTerreno;
        float areaConstruida;

    public:
        /******** CONSTRUTORES ********/
        Casa();
        Casa(float, std::string, int, int, float, float);

        /******** MÉTODOS ********/
        void lerAtributos();
        void exibeAtributos() const;
};

class Apartamento : public Imovel
{
    private:
        float area;
        int num_quartos;
        int andar;
        float valor_condominio;
        int vagas_garagem;

    public:
        /******** CONSTRUTORES ********/
        Apartamento();
        Apartamento(float, std::string, float, int, int, float, int);

        /******** MÉTODOS ********/
        void lerAtributos();
        void exibeAtributos() const;
};

class Terreno : public Imovel
{
    private:
        float area;

    public:
        /******** CONSTRUTORES ********/
        Terreno();
        Terreno(float, std::string, float);

        /******** MÉTODOS ********/
        void lerAtributos();
        void exibeAtributos() const;
};

#endif