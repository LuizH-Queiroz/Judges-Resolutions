#include <string>
#include "Funcionario02.h"


/*/////// CONSTRUTOR ///////*/



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