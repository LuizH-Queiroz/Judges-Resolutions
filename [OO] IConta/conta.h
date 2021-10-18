#ifndef ICONTA
#define ICONTA

#include <string>


class IConta
{
    public:
        /******** DESTRUTOR ********/
        virtual ~IConta() { /* VAZIO */ }

        /******** MÉTODOS ********/
        virtual void sacar(float valor) = 0;
        virtual void depositar(float valor) = 0;
        virtual float saldoTotalDisponivel() = 0;
};


class Conta : public IConta
{
    protected:
        std::string nomeCliente;
        int numeroConta;
        float salarioMensal;
        float saldo;
        float limite;

        /******** MÉTODO PROTECTED ********/
        virtual void definirLimite() { limite = 2 * salarioMensal; }

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        Conta();
        Conta(std::string nome, int numero, float salario);
        virtual ~Conta() { /* VAZIO */ }

        /******** MÉTODOS ********/
        std::string getNome() const { return nomeCliente; }
        int getNumeroConta() const { return numeroConta; }
        float getSalarioMensal() const { return salarioMensal; }
        float getSaldo() const { return saldo; }
        float getLimite() const { return limite; }

        void setNomeCliente(std::string nome);
        void setNumeroConta(int numero);
        void setSalarioMensal(float salario);
        void setSaldo(float saldo);
        void setLimite(float limite);

        virtual void sacar(float valor) override;
        virtual void depositar(float valor) override;
        virtual float saldoTotalDisponivel() override;
};


class ContaEspecial : public Conta
{
    protected:
        /******** MÉTODO PROTECTED ********/
        virtual void definirLimite() override { limite = 3 * salarioMensal; }

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        ContaEspecial() { /* VAZIO */ }
        ContaEspecial(std::string nome, int numero, float salario);
        virtual ~ContaEspecial() { /* VAZIO */ }
};


#endif