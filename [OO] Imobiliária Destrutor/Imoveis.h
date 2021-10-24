#ifndef IMOVEIS_H
#define IMOVEIS_H

#include <string>
#include <vector>


enum TipoImovel
{
    INDEFINIDO = 0,
    CASA = 1,
    APARTAMENTO = 2,
    TERRENO = 3
};


class Imovel
{
    protected:
        std::string nome;
        float valor;
        TipoImovel tipo;
        std::string forma_negocio;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        Imovel();
        Imovel(float valor, TipoImovel tipo, std::string forma_negocio);
        virtual ~Imovel();


        /******** MÉTODOS ********/
        std::string getNome() const;
        float getValor() const;
        TipoImovel getTipoImovel() const;
        std::string getFormaNegocio() const;

        void setNome(std::string nome);
        void setValor(float valor);
        void setTipoImovel(TipoImovel tipo);
        void setFormaNegocio(std::string forma);

        virtual void lerAtributos();
        virtual void exibeAtributos() const;
};


class Casa : public Imovel
{
    private:
        int num_pavimentos;
        int num_quartos;
        float area_terreno;
        float area_construida;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        Casa();
        Casa(float valor, std::string forma_negocio,
             int num_pavimentos, int num_quartos, float area_terreno, float area_construida);
        virtual ~Casa();


        /******** MÉTODOS ********/
        int getNumPavimentos() const;
        int getNumQuartos() const;
        float getAreaTerreno() const;
        float getAreaConstruida() const;

        void setNumPavimentos(int num);
        void setNumQuartos(int num);
        void setAreaTerreno(float area);
        void setAreaConstruida(float area);

        virtual void lerAtributos() override;
        virtual void exibeAtributos() const override;
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
        /******** CONSTRUTORES / DESTRUTOR ********/
        Apartamento();
        Apartamento(float valor, std::string forma_negocio,
                    float area, int num_quartos, int andar, float valor_condominio, int vagas_garagem);
        virtual ~Apartamento();


        /******** MÉTODOS ********/
        float getArea() const;
        int getNumQuartos() const;
        int getAndar() const;
        float getValorCondominio() const;
        int getVagasGaragem() const;

        void setArea(float area);
        void setNumQuartos(int num);
        void setAndar(int andar);
        void setValorCondominio(float valor);
        void setVagasGaragem(int quant);

        virtual void lerAtributos() override;
        virtual void exibeAtributos() const override;
};


class Terreno : public Imovel
{
    private:
        float area;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        Terreno();
        Terreno(float valor, std::string forma_negocio, float area);
        virtual ~Terreno();


        /******** MÉTODOS ********/
        float getArea() const;

        void setArea(float area);

        virtual void lerAtributos() override;
        virtual void exibeAtributos() const override;
};

///////////////////////////////////////////////////////////////////////////////////////

/******************************** Class Imobiliaria ********************************/
class Imobiliaria
{
    private:
        std::vector<Imovel*> imoveis;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        Imobiliaria();
        virtual ~Imobiliaria();


        /******** OPERADORES ********/
        Imovel* &operator[] (int indice);


        /******** MÉTODOS ********/
        size_t size() const;

        void addImovel(Imovel *imovel);
        void buscaImovel(std::string busca);
};



#endif