#include "GerenciarEmpresa.h"

/********************* Class Funcionario *********************/

/******** MÉTODOS ********/
void Funcionario::setMatricula(int mat){
    
    if (mat > 0){
        matricula = mat;
    }
}

void Funcionario::setNome(std::string n){
    nome = n;
}

void Funcionario::setSalario(float sal){
    
    if (sal >= 0){
        salario = sal;
    }
}



/********************* Class Funcionario *********************/

/******** MÉTODOS ********/
float Consultor::getSalario(float percent) const{
    return salario * (1 + percent);
}