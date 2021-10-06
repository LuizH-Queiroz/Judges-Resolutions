#include "trabalhador.h"

/********************* Class Trabalhador *********************/

/******** CONSTRUTORES ********/
Trabalhador::Trabalhador(){
    nome = "";
    salario = 0;
}

/******** MÉTODOS ********/
void Trabalhador::setNome(std::string nome){
    this->nome = nome;
}

void Trabalhador::setSalario(float sal){

    if (sal >= 0){
        salario = sal;
    }
}



/********************* Class TrabalhadorAssalariado *********************/

/******** CONSTRUTORES ********/
TrabalhadorAssalariado::TrabalhadorAssalariado() // Chamada implicita ao contrutor padrao
{                                                // Trabalhador::Trabalhador()
    //Nada para adicionar
}

TrabalhadorAssalariado::TrabalhadorAssalariado(float sal)
{
    nome = "";
    
    if (sal >= 0){
        salario = sal;
    }
    else {
        salario = 0;
    }
}

/******** MÉTODOS ********/
float TrabalhadorAssalariado::calcularPagamentoSemanal() const {
    return salario / 4;
}



/********************* Class TrabalhadorPorHora *********************/

const int TrabalhadorPorHora::maxHorasSemanais = 40;

/******** CONSTRUTORES ********/
TrabalhadorPorHora::TrabalhadorPorHora()
                  : Trabalhador()
{
    valorDaHora = 0;
}

TrabalhadorPorHora::TrabalhadorPorHora(float valor)
{ //Chamada implicita ao construtor Trabalhador::Trabalhador()
    if (valor >= 0){
        valorDaHora = valor;
    }
    else {
        valor = 0;
    }
}

/******** MÉTODOS ********/
void TrabalhadorPorHora::setValorDaHora(float valor){

    if (valor >= 0){
        valorDaHora = valor;
    }
}

float TrabalhadorPorHora::calcularPagamentoSemanal(int horasSemanais){

    if (horasSemanais < 0){
        return -1;
    }

    if (horasSemanais <= maxHorasSemanais){
        salario = (valorDaHora * horasSemanais) * 4; //O salario eh mensal
        return valorDaHora * horasSemanais;
    }
    else {
        int horasExcedentes = horasSemanais - maxHorasSemanais;
        salario = ((maxHorasSemanais * valorDaHora) + (horasExcedentes * valorDaHora * 1.5)) * 4;
        return salario / 4;
    }

}