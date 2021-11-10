#include <iostream>
#include "conta.h"


/****************************** Class Conta ******************************/
/******** CONSTRUTORES / DESTRUTOR ********/
Conta::Conta(){
    nomeCliente = "";
    numero = 0;
    saldo = 0;
}

Conta::Conta(std::string nome, int num, double saldo){
    this->nomeCliente = nome;
    this->numero = num;
    this->saldo = saldo;
}

Conta::~Conta(){

}

/******** MÉTODOS ********/
std::string Conta::getNomeCliente() { return nomeCliente; }

int Conta::getNumero() { return numero; }

double Conta::getSaldo() { return saldo; }

inline void Conta::setNomeCliente(std::string nome) { this->nomeCliente = nome; }

inline void Conta::setNumero(int numero) { this->numero = numero; }

inline void Conta::setSaldo(double saldo) { this->saldo = saldo; }

void Conta::sacar(double valor){

    if (valor <= saldo) saldo -= valor;
    else std::cout << "saldo insuficiente" << std::endl;
}

void Conta::depositar(double valor){
    saldo += valor;
}

double Conta::saldoTotalDisponivel(){
    return saldo;
}


//////////////////////////////////////////////////////////////////////////////////////////////////

/****************************** Class ContaCorrente : public Conta ******************************/
/******** CONSTRUTORES / DESTRUTOR ********/
ContaCorrente::ContaCorrente()
             : Conta()
{
    salario = 0;
    limite = 0;
}

ContaCorrente::ContaCorrente(std::string nome, int num, double saldo, double salario)
             : Conta(nome, num, saldo)
{
    this->salario = salario;
    definirLimite();
}

ContaCorrente::~ContaCorrente(){

}
/********* MÉTODOS *********/
double ContaCorrente::getSalario() { return salario; }

int ContaCorrente::getLimite() { return limite; }

inline void ContaCorrente::setSalario(double salario) { this->salario = salario; }

void ContaCorrente::sacar(double valor){

    if (valor <= (saldo + limite)){
        if (valor <= saldo){
            saldo -= valor;
        }
        else {
            saldo = 0;
            limite = limite - (valor - saldo);
        }
    }
    else std::cout << "\nsaldo insuficiente" << std::endl;
}

double ContaCorrente::definirLimite(){
    limite = 2*salario;
    return limite;
}

double ContaCorrente::saldoTotalDisponivel(){
    return saldo + limite;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

/****************************** Class ContaEspecial : public ContaCorrente ******************************/
/******** CONSTRUTORES / DESTRUTOR ********/
ContaEspecial::ContaEspecial()
             : ContaCorrente()
{
}

ContaEspecial::ContaEspecial(std::string nome, int num, double saldo, double salario)
             : ContaCorrente(nome, num, saldo, salario)
{
    definirLimite();
}

ContaEspecial::~ContaEspecial(){

}

/******** MÉTODOS ********/
double ContaEspecial::definirLimite(){
    limite = 4*salario;
    return limite;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

/****************************** Class Poupanca : public Conta ******************************/
/******** CONSTRUTORES / DESTRUTOR ********/
Poupanca::Poupanca()
        : Conta()
{
    variacao = 0;
    taxaRendimento = 0.006;
}

Poupanca::Poupanca(std::string nome, int num, double saldo, int variacao, double rendimento)
        : Conta(nome, num, saldo)
{
    this->variacao = variacao;
    this->taxaRendimento = rendimento;
}

Poupanca::~Poupanca(){

}

/******** MÉTODOS ********/
inline int Poupanca::getVariacao() { return variacao; }

inline double Poupanca::getTaxaRendimento() { return taxaRendimento; }

inline void Poupanca::setVariacao(int variacao) { this->variacao = variacao; }

inline void Poupanca::setTaxaRendimento(double rendimento) { this->taxaRendimento = rendimento; }

double Poupanca::render(){
    return saldo * taxaRendimento;
}

double Poupanca::saldoTotalDisponivel(){
    return saldo + render();
}