#include <string>
#include "Funcionario02.h"


/*/////// CONSTRUTORES ///////*/
Funcionario::Funcionario(){
    nome = "\0";
    sobrenome = "\0";
    salarioMensal = 0;
}

Funcionario::Funcionario(std::string nome, std::string sobrenome, int salario){
    this->nome = nome;
    this->sobrenome = sobrenome;
    this->salarioMensal = salario; //Uso opcional do ponteiro "this"
}


/*/////// MÉTODOS ///////*/
std::string Funcionario::getNome(){
    return nome;
}

std::string Funcionario::getSobrenome(){
    return sobrenome;
}

int Funcionario::getSalarioMensal(){
    return salarioMensal;
}


void Funcionario::setNome(std::string nome){
    this->nome = nome;
}

void Funcionario::setSobrenome(std::string sobrenome){
    this->sobrenome = sobrenome;
}

void Funcionario::setSalarioMensal(int salario){
    salarioMensal = salario;
}


int Funcionario::getSalarioAnual(){
    return salarioMensal * 12;
}

void Funcionario::aumentaSalario(float percent){
    salarioMensal += salarioMensal * percent;
}