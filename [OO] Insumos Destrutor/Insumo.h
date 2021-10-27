#ifndef INSUMO_H
#define INSUMO_H

#include <string>
#include <vector>


class Insumo
{
    protected:
        std::string nome;
        int quantidade;
        int valorUnitario;
        std::string dtVencimento;
        std::string nomeFabricante;
        int tipoInsumo;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        Insumo();
        Insumo(std::string insumo_nome, int quant, int valor, std::string vencimento,
               std::string fabricante, int tipo);
        virtual ~Insumo();
};


class Vacina : public Insumo
{
    private:
        int tipo;
        int quantDoses;
        int intervalo;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        Vacina();
        Vacina(std::string insumo_nome, int quant, int valor, std::string vencimento,
               std::string fabricante, int tipo, int tipo_vac, int n_doses, int interval);
        virtual ~Vacina();
};


class Medicamento : public Insumo
{
    private:
        std::string dosagem;
        std::string administracao;
        std::string disponibilizacao;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        Medicamento();
        Medicamento(std::string insumo_nome, int quant, int valor, std::string vencimento,
                    std::string fabricante, int tipo, std::string dosagem, std::string administracao,
                    std::string disponibilizacao);
        virtual ~Medicamento();
};


class EPI : public Insumo
{
    private:
        int tipo;
        std::string descricao;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        EPI();
        EPI(std::string insumo_nome, int quant, int valor, std::string vencimento,
            std::string fabricante, int tipo, int tipo_EPI, std::string descricao);
        virtual ~EPI();
};



class Local
{
    private:
        std::string nome;
        int tipo;
        Insumo* insumosArr[3];
        std::vector<Insumo*> insumosVec;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        Local();
        Local(std::string nome, int tipo);
        virtual ~Local();

        /******** MÉTODOS ********/
        void addInsumoArr(Insumo *in, int index);
        void addInsumoVec(Insumo *in);
};



#endif