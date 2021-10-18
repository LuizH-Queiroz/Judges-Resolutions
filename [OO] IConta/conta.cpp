#include <iostream>
#include "conta.h"

/******************************* Class Conta *******************************/

/******** CONSTRUTORES / DESTRUTOR ********/
Conta::Conta(){
    nomeCliente = "";
    numeroConta = 0;
    salarioMensal = saldo = limite = 0;    
}

Conta::Conta(std::string nome, int numero, float salario){
    nomeCliente = nome;

    if (numero > 0) numeroConta = numero;
    else numeroConta = 0;

    if (salario >= 0) salarioMensal = salario;
    else salarioMensal = 0;

    definirLimite();
}

/******** MÉTODOS ********/
void Conta::setNomeCliente(std::string nome){
    nomeCliente = nome;
}

void Conta::setNumeroConta(int numero){
    if (numero > 0) numeroConta = numero;
}

void Conta::setSalarioMensal(float salario){
    if (salario >= 0) salarioMensal = salario;
    definirLimite();
}

void Conta::setSaldo(float saldo){
    if (saldo >= 0) this->saldo = saldo;
}

void Conta::setLimite(float limite){
    if (limite >= 0) this->limite = limite;
}

void Conta::sacar(float valor){
    saldo -= valor;
}

void Conta::depositar(float valor){
    saldo += valor;
}

float Conta::saldoTotalDisponivel(){
    return saldo + limite;
}

/////////////////////////////////////////////////////////////////////////////

/******************************* Class Conta *******************************/

/******** CONSTRUTORES ********/
ContaEspecial::ContaEspecial(std::string nome, int numero, float salario)
             : Conta(nome, numero, salario)
{
    definirLimite();
}