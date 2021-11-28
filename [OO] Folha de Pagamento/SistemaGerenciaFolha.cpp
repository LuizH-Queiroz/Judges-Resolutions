#include "SistemaGerenciaFolha.h"


/************************** Class Funcionario **************************/

/******** CONSTRUTORES E DESTRUTOR ********/
Funcionario::Funcionario(){
    nome = "";
    matricula = 0;
}

Funcionario::Funcionario(std::string nome, int matricula){
    this->nome = nome;
    this->matricula = matricula;
}

Funcionario::~Funcionario(){ }

/******** MÉTODOS ********/
std::string Funcionario::getNome() { return nome; }
int Funcionario::getMatricula() { return matricula; }

void Funcionario::setNome(std::string nome){
    this->nome = nome;
}

void Funcionario::setMatricula(int matricula){
    this->matricula = matricula;
}

///////////////////////////////////////////////////////////////////////////////////////


/************************** Class Assalariado : Funcionario **************************/

/******** CONSTRUTORES E DESTRUTOR ********/
Assalariado::Assalariado()
           : Funcionario()
{
    salario = 0;
}

Assalariado::Assalariado(std::string nome, int matricula, double salario)
           : Funcionario(nome, matricula)
{
    this->salario = salario;
}

Assalariado::~Assalariado(){ }

/******** MÉTODOS ********/
void Assalariado::setSalario(double sal){
    salario = sal;
}

double Assalariado::calcularSalario() { return salario; }

///////////////////////////////////////////////////////////////////////////////////


/************************** Class Horista : Funcionario **************************/

/******** CONSTRUTORES E DESTRUTOR ********/
Horista::Horista()
       : Funcionario()
{
    salarioPorHora = 0;
    horasTrabalhadas = 0;
}

Horista::Horista(std::string nome, int matricula, double salarioHora, double horasTrabalhadas)
       : Funcionario(nome, matricula)
{
    this->salarioPorHora = salarioHora;
    this->horasTrabalhadas = horasTrabalhadas;
}

Horista::~Horista(){ }

/******** MÉTODOS ********/
double Horista::getSalarioPorHora() { return salarioPorHora; }
double Horista::getHorasTrabalhadas() { return horasTrabalhadas; }

void Horista::setSalarioPorHora(double sal){
    salarioPorHora = sal;
}

void Horista::setHorasTrabalhadas(double horas){
    horasTrabalhadas = horas;
}

double Horista::calcularSalario(){
    double salario = 0;

    if (horasTrabalhadas <= 40){
        salario = horasTrabalhadas * salarioPorHora * 4;
    }
    else {
        salario += 40 * salarioPorHora * 4;
        salario += (horasTrabalhadas - 40) * (salarioPorHora * 1.5) * 4;
    }

    return salario;
}

////////////////////////////////////////////////////////////////////////////////////////


/************************** Class Comissionado : Funcionario **************************/

/******** CONSTRUTORES E DESTRUTOR ********/
Comissionado::Comissionado()
            : Funcionario()
{
    vendasMensais = 0;
    percentualComissao = 0;
}

Comissionado::Comissionado(std::string nome, int matricula, double vendas, double percentual)
            : Funcionario(nome, matricula)
{
    this->vendasMensais = vendas;
    this->percentualComissao = percentual;
}

Comissionado::~Comissionado() { }

/******** MÉTODOS ********/
double Comissionado::getVendasMensais() { return vendasMensais; }
double Comissionado::getPercentualComissao() { return percentualComissao; }

void Comissionado::setVendasMensais(double vendas){
    vendasMensais = vendas;
}

void Comissionado::setPercentualComissao(double percentual){
    percentualComissao = percentual;
}

double Comissionado::calcularSalario(){
    return percentualComissao * vendasMensais;
}

//////////////////////////////////////////////////////////////////////////////////


/************************** Class SistemaGerenciaFolha **************************/

/******** CONSTRUTORES E DESTRUTOR ********/
SistemaGerenciaFolha::SistemaGerenciaFolha(double maximo) {
    orcamento_maximo = maximo;
}

SistemaGerenciaFolha::~SistemaGerenciaFolha(){
    for (auto&& it : funcionarios) delete it;
    funcionarios.clear();
}

/******** MÉTODOS ********/
void SistemaGerenciaFolha::setFuncionarios(Funcionario * func){
    funcionarios.push_back(func);
}

double SistemaGerenciaFolha::calculaValorTotalFolha(){
    double total = 0;

    for (auto&& it : funcionarios) total += it->calcularSalario();

    if (total > orcamento_maximo) throw OrcamentoEstouradoException().what() + std::to_string((int) total);

    return total;
}

double SistemaGerenciaFolha::consultaSalarioFuncionario(std::string nome){

    for (auto&& it : funcionarios) if (it->getNome() == nome) return it->calcularSalario();

    throw new FuncionarioNaoExisteException();
}