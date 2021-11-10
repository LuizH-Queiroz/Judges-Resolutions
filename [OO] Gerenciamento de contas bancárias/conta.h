#ifndef CONTA_H
#define CONTA_H

#include <string>


class Conta
{
    protected:
        std::string nomeCliente;
        int numero;
        double saldo;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        Conta();
        Conta(std::string nome, int num, double saldo);
        virtual ~Conta();

        /******** MÉTODOS ********/
        std::string getNomeCliente();
        int getNumero();
        double getSaldo();

        void setNomeCliente(std::string nome);
        void setNumero(int numero);
        void setSaldo(double saldo);

        virtual void sacar(double valor);
        void depositar(double valor);
        virtual double saldoTotalDisponivel();
};


class ContaCorrente : public Conta
{
    protected:
        double salario;
        int limite;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        ContaCorrente();
        ContaCorrente(std::string nome, int num, double saldo, double salario);
        virtual ~ContaCorrente();

        /******** MÉTODOS ********/
        double getSalario();
        int getLimite();

        void setSalario(double salario);

        virtual double definirLimite();
        virtual void sacar(double valor) override;
        virtual double saldoTotalDisponivel() override;
};


class ContaEspecial : public ContaCorrente
{
    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        ContaEspecial();
        ContaEspecial(std::string nome, int num, double saldo, double salario);
        virtual ~ContaEspecial();

        /******** MÉTODOS ********/
        virtual double definirLimite() override;
};


class Poupanca : public Conta
{
    private:
        int variacao;
        double taxaRendimento;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        Poupanca();
        Poupanca(std::string nome, int num, double saldo, int variacao, double rendimento);
        virtual ~Poupanca();

        /******** MÉTODOS ********/
        int getVariacao();
        double getTaxaRendimento();

        void setVariacao(int variacao);
        void setTaxaRendimento(double rendimento);

        double render();
        virtual double saldoTotalDisponivel() override;
};



#endif