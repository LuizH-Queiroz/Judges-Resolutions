#ifndef SISTEMAGERENCIAFOLHA_H
#define SISTEMAGERENCIAFOLHA_H

#include <string>
#include <vector>
#include "FuncionarioExceptions.h"


class Funcionario
{
    private:
        std::string nome;
        int matricula;

    public:
        /******** CONSTRUTORES E DESTRUTOR ********/
        Funcionario();
        Funcionario(std::string nome, int matricula);
        virtual ~Funcionario();

        /******** MÉTODOS ********/
        std::string getNome();
        int getMatricula();

        void setNome(std::string nome);
        void setMatricula(int matricula);

        virtual double calcularSalario() = 0;
};


class Assalariado : Funcionario
{
    private:
        double salario;

    public:
        /******** CONSTRUTORES E DESTRUTOR ********/
        Assalariado();
        Assalariado(std::string nome, int matricula, double salario);
        virtual ~Assalariado();

        /******** MÉTODOS ********/
        //double getSalario(); //Usar calcularSalario() no lugar

        void setSalario(double sal);

        virtual double calcularSalario() override;
};


class Horista : Funcionario
{
    private:
        double salarioPorHora;
        double horasTrabalhadas; //Horas semanais trabalhadas

    public:
        /******** CONSTRUTORES E DESTRUTOR ********/
        Horista();
        Horista(std::string nome, int matricula, double salarioHora, double horasTrabalhadas);
        virtual ~Horista();

        /******** MÉTODOS ********/
        double getSalarioPorHora();
        double getHorasTrabalhadas();

        void setSalarioPorHora(double sal);
        void setHorasTrabalhadas(double horas);

        virtual double calcularSalario() override;
};


class Comissionado : Funcionario
{
    private:
        double vendasMensais;
        double percentualComissao;

    public:
        /******** CONSTRUTORES E DESTRUTOR ********/
        Comissionado();
        Comissionado(std::string nome, int matricula, double vendas, double percentual);
        virtual ~Comissionado();

        /******** MÉTODOS ********/
        double getVendasMensais();
        double getPercentualComissao();

        void setVendasMensais(double vendas);
        void setPercentualComissao(double percentual);

        virtual double calcularSalario() override;
};


class SistemaGerenciaFolha
{
    private:
        std::vector<Funcionario*> funcionarios;
        double orcamento_maximo;

    public:
        /******** CONSTRUTORES E DESTRUTOR ********/
        SistemaGerenciaFolha(double maximo);
        virtual ~SistemaGerenciaFolha();

        /******** MÉTODOS ********/
        void setFuncionarios(Funcionario * func);

        double calculaValorTotalFolha();
        double consultaSalarioFuncionario(std::string nome);
};


#endif